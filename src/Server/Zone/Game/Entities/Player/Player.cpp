/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 *
 * Copyright (c) 2019 Sagun K. (sagunxp@gmail.com).
 * Copyright (c) 2019 Horizon Dev Team.
 *
 * Base Author - Sagun K. (sagunxp@gmail.com)
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************/

#include "Player.hpp"

#include "Server/Common/Definitions/EntityDefinitions.hpp"
#include "Server/Common/SQL/Character/Character.hpp"
#include "Server/Zone/Game/Entities/Player/Assets/Inventory.hpp"
#include "Server/Zone/Game/Map/Grid/Notifiers/GridNotifiers.hpp"
#include "Server/Zone/Game/Map/Grid/Container/GridReferenceContainer.hpp"
#include "Server/Zone/Game/Map/Grid/Container/GridReferenceContainerVisitor.hpp"
#include "Server/Zone/Game/StaticDB/ItemDB.hpp"
#include "Server/Zone/Game/StaticDB/JobDB.hpp"
#include "Server/Zone/Game/StaticDB/SkillDB.hpp"
#include "Server/Zone/Game/Entities/Creature/Hostile/Monster.hpp"
#include "Server/Zone/Game/Entities/Entity.hpp"
#include "Server/Zone/Game/Entities/Traits/AttributesImpl.hpp"
#include "Server/Zone/Game/Entities/Traits/Status.hpp"
#include "Server/Zone/Session/ZoneSession.hpp"
#include "Server/Zone/Socket/ZoneSocket.hpp"
#include "Server/Zone/Zone.hpp"

#include "version.hpp"
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/mysql/connection.h>

using namespace Horizon::Zone;
using namespace Horizon::Zone::Entities;

Player::Player(std::shared_ptr<ZoneSession> session, uint32_t guid, std::shared_ptr<Map> map, const MapCoords& mcoords)
: Entity(guid, ENTITY_PLAYER, map, mcoords), _session(session)
{
}

Player::~Player()
{
	if (has_valid_grid_reference())
		remove_grid_reference();
}

uint64_t Player::new_unique_id()
{
	int64_t char_id = (int64_t) character()._character_id;
	
	if (character()._last_unique_id > 0)
		return ++character()._last_unique_id;

	return (character()._last_unique_id = (char_id << 32));
}

void Player::initialize()
{
	Entity::initialize();

	// Initialize Status.
	status()->initialize(shared_from_this());

	// Inventory.
	_inventory = std::make_shared<Assets::Inventory>(downcast<Player>(), get_max_inventory_size());
	_inventory->load();

	status()->aspd()->compute(true);
	status()->equip_atk()->compute(true);

	// Ensure grid for entity.
	map()->ensure_grid_for_entity(this, map_coords());
	
	// Populate skill tree.
	std::vector<std::shared_ptr<const skill_tree_config>> sktree = SkillDB->get_skill_tree_by_job_id((job_class_type) job_id());

	for (auto s : sktree) {
		skill_learnt_info info;
		info.skill_id = s->skill_id;
		info.level = 0;
		info.learn_type = SKILL_LEARN_PERMANENT;
		add_learnt_skill(std::make_shared<skill_learnt_info>(info));
	}

	// On map entry processing.
	on_map_enter();

	// Initialize Script States.
	script_manager()->initialize_state(get_lua_state());

	try {
		sol::state &pl_lua = get_lua_state();
		sol::load_result fx = pl_lua.load_file("scripts/internal/on_login_event.lua");
		sol::protected_function_result result = fx(shared_from_this()->downcast<Player>(), VER_PRODUCTVERSION_STR);
		if (!result.valid()) {
			sol::error err = result;
			HLog(error) << "Player::initialize: " << err.what();
		}
	} catch (sol::error &e) {
		HLog(error) << "Player::initialize: " << e.what();
	}

    map()->container()->getScheduler().Schedule(
    	Milliseconds(60000),
    	get_scheduler_task_id(ENTITY_SCHEDULE_SAVE),
    	[this] (TaskContext context)
    {
    	save();
    	context.Repeat(Milliseconds(60000));
    });

}

void Player::stop_movement()
{
	MapCoords const &coords = map_coords();
	get_session()->clif()->notify_movement_stop(guid(), coords.x(), coords.y());
}

void Player::save()
{
	SQL::TableCharacters tch;
	std::shared_ptr<sqlpp::mysql::connection> conn = sZone->get_db_connection();
	
	(*conn)(update(tch).set(tch.slot = character()._slot, tch.name = name(), tch.online = character()._online ? 1 : 0, 
		tch.last_unique_id = character()._last_unique_id, tch.hotkey_row_index = 0, tch.change_slot_count = 0, tch.font = 0,
		tch.show_equip = 0, tch.allow_party = 0, tch.partner_aid = 0, tch.father_aid = 0, tch.mother_aid = 0, tch.child_aid = 0, tch.party_id = 0,
		tch.guild_id = 0, tch.pet_id = 0, tch.homun_id = 0, tch.elemental_id = 0, tch.current_map = map()->get_name(), tch.current_x = map_coords().x(), tch.current_y = map_coords().y(),
		tch.saved_map = character()._saved_map, tch.saved_x = character()._saved_x, tch.saved_y = character()._saved_y)
		.where(tch.account_id == character()._account_id and tch.id == character()._character_id));

	HLog(info) << "Player " << name() << " has been saved at (" << map()->get_name() << " " << map_coords().x() << "," << map_coords().y() << ").";

	_inventory->save();
}

void Player::on_pathfinding_failure()
{
	HLog(debug) << "Player " << name() << " has failed to find path from (" << map_coords().x() << "," << map_coords().y() << ") to (" << dest_coords().x() << ", " << dest_coords().y() << ").";
}

void Player::on_movement_begin()
{
	get_session()->clif()->notify_player_movement(map_coords(), dest_coords());
}

void Player::on_movement_end()
{
}

void Player::on_movement_step()
{
	GridNPCTrigger npc_trigger(shared_from_this());
	GridReferenceContainerVisitor<GridNPCTrigger, GridReferenceContainer<AllEntityTypes>> npc_trigger_performer(npc_trigger);

	map()->ensure_grid_for_entity(this, map_coords());

	update_viewport();

	map()->visit_in_range(map_coords(), npc_trigger_performer, MAX_NPC_TRIGGER_RANGE);
}

void Player::update_viewport()
{
	GridViewPortUpdater updater(shared_from_this());
	GridReferenceContainerVisitor<GridViewPortUpdater, GridReferenceContainer<AllEntityTypes>> update_caller(updater);

	map()->visit_in_range(map_coords(), update_caller);
}

void Player::add_entity_to_viewport(std::shared_ptr<Entity> entity)
{
	if (entity == nullptr)
		return;

	if (entity_is_in_viewport(entity))
		return;

	if (entity->is_walking()) {
		realize_entity_movement(entity);
	} else {
		entity_viewport_entry entry = get_session()->clif()->create_viewport_entry(entity);
		get_session()->clif()->notify_viewport_add_entity(entry);
	}
	
	_viewport_entities.push_back(entity);

	if (entity->type() == ENTITY_MONSTER) {
	    entity->downcast<Monster>()->set_spotted(true);
	}

	HLog(debug) << "------- VIEWPORT ENTITIES ----------";
	for (auto it = _viewport_entities.begin(); it != _viewport_entities.end(); it++)
		HLog(debug) << "Entity:" << it->lock()->name() << " " << it->lock()->guid();
	HLog(debug) << "--------------------";
}

void Player::remove_entity_from_viewport(std::shared_ptr<Entity> entity, entity_viewport_notification_type type)
{
	if (!entity_is_in_viewport(entity))
		return;

	_viewport_entities.erase(std::remove_if(_viewport_entities.begin(), _viewport_entities.end(),
		[entity] (std::weak_ptr<Entity> wp_e) {
			return wp_e.lock()->guid() == entity->guid();
		}
	), _viewport_entities.end());

	get_session()->clif()->notify_viewport_remove_entity(entity, type);

	HLog(debug) << "------- VIEWPORT ENTITIES ----------";
	for (auto it = _viewport_entities.begin(); it != _viewport_entities.end(); it++)
		HLog(debug) << "Entity:" << it->lock()->name() << " " << it->lock()->guid();
	HLog(debug) << "--------------------";
}

bool Player::entity_is_in_viewport(std::shared_ptr<Entity> entity)
{
	if (entity == nullptr)
		return false;

	std::vector<std::weak_ptr<Entity>>::iterator it = std::find_if (_viewport_entities.begin(), _viewport_entities.end(), 
		[entity] (const std::weak_ptr<Entity> &vp_ew) { 
			std::shared_ptr<Entity> vp_es = vp_ew.lock();

			if (vp_es == nullptr || entity == nullptr)
				return false;

			return (vp_es->guid() == entity->guid());
		}
	);
	
	return (it != _viewport_entities.end());
}

void Player::realize_entity_movement(std::shared_ptr<Entity> entity)
{
	if (entity == nullptr)
		return;

	entity_viewport_entry entry = get_session()->clif()->create_viewport_entry(entity);
	get_session()->clif()->notify_viewport_moving_entity(entry);
}

void Player::spawn_entity_in_viewport(std::shared_ptr<Entity> entity)
{
	if (entity == nullptr)
		return;

	entity_viewport_entry entry = get_session()->clif()->create_viewport_entry(entity);
	get_session()->clif()->notify_viewport_spawn_entity(entry);
}

bool Player::move_to_map(std::shared_ptr<Map> dest_map, MapCoords coords)
{
	if (dest_map == nullptr)
		return false;

	force_movement_stop_internal(true);
	map()->container()->getScheduler().Count(get_scheduler_task_id(ENTITY_SCHEDULE_WALK));

	std::shared_ptr<Player> myself = downcast<Player>();

	notify_nearby_players_of_existence(EVP_NOTIFY_TELEPORT);

	{
		if (!dest_map->container()->get_map(map()->get_name())) {
			map()->container()->remove_player(myself);
			dest_map->container()->add_player(myself);
		}

		if (coords == MapCoords(0, 0))
			coords = dest_map->get_random_accessible_coordinates();

		dest_map->ensure_grid_for_entity(this, coords);
		set_map(dest_map);
		set_map_coords(coords);
	}

	get_session()->clif()->notify_move_to_map(dest_map->get_name(), coords.x(), coords.y());
	return true;
}

void Player::send_npc_dialog(uint32_t npc_guid, std::string dialog)
{
	get_session()->clif()->notify_npc_dialog(npc_guid, dialog);
}

void Player::send_npc_next_dialog(uint32_t npc_guid)
{
	get_session()->clif()->notify_npc_next_dialog(npc_guid);
}

void Player::send_npc_close_dialog(uint32_t npc_guid)
{
	get_session()->clif()->notify_npc_close_dialog(npc_guid);
}

void Player::send_npc_menu_list(uint32_t npc_guid, std::string const &menu)
{
	get_session()->clif()->notify_npc_menu_list(npc_guid, menu);
}

void Player::on_item_equip(std::shared_ptr<const item_entry_data> item)
{
	std::shared_ptr<const item_config_data> itemd = ItemDB->get_item_by_id(item->item_id);
	std::shared_ptr<Traits::Status> s = status();

	if (item->type == IT_TYPE_WEAPON) {
		s->status_atk()->set_weapon_type(itemd->sub_type.weapon_t);
		s->equip_atk()->on_weapon_changed();
		s->aspd()->on_weapon_changed();
	}
}

void Player::on_item_unequip(std::shared_ptr<const item_entry_data> item)
{
	std::shared_ptr<const item_config_data> itemd = ItemDB->get_item_by_id(item->item_id);
	std::shared_ptr<Traits::Status> s = status();

	if (item->type == IT_TYPE_WEAPON) {
		s->status_atk()->set_weapon_type(IT_WT_FIST);
		s->equip_atk()->on_weapon_changed();
		s->aspd()->on_weapon_changed();
	}
}

void Player::on_map_enter()
{
	force_movement_stop_internal(false);
//	get_packet_handler()->Send_ZC_MAPPROPERTY_R2(get_map());

	inventory()->notify_all();
	// Status Notifications.

	// clear viewport
	get_viewport_entities().clear();

	update_viewport();

	notify_nearby_players_of_spawn();

	// Notify learnt skill list.
	get_session()->clif()->notify_learnt_skill_list();
}

void Player::notify_in_area(ByteBuffer &buf, player_notifier_type type, uint16_t range)
{
	GridPlayerNotifier notifier(buf, static_cast<Entity *>(this)->shared_from_this(), type);
	GridReferenceContainerVisitor<GridPlayerNotifier, GridReferenceContainer<AllEntityTypes>> container(notifier);

	map()->visit_in_range(map_coords(), container, range);
}


bool Player::job_change(int32_t job_id)
{
	std::shared_ptr<const job_config_data> job = JobDB->get_job_by_id(job_id);

	if (job == nullptr) {
		HLog(error) << "Player::job_change: Invalid job_id " << job_id << " provided, job was not found or not supported.";
		return false;
	}

	set_job_id(job_id);
	status()->base_appearance()->set(job_id);

	return true;
}

