/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 * Copyright (c) 2020- Horizon Dev Team.
 *
 * Base Author - Sagun Khosla. (sagunxp@gmail.com)
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

#include "CharClientInterface.hpp"

#include "Server/Common/Definitions/EntityDefinitions.hpp"
#include "Server/Common/Definitions/ItemDefinitions.hpp"
#include "Server/Common/SQL/GameAccount.hpp"
#include "Server/Common/SQL/SessionData.hpp"
#include "Server/Common/SQL/Character/Character.hpp"
#include "Server/Common/SQL/Character/Status.hpp"
#include "Server/Common/SQL/GameAccount.hpp"

#include "Server/Zone/Game/Entities/Player/Assets/Inventory.hpp"
#include "Server/Zone/Game/Entities/Player/Player.hpp"
#include "Server/Zone/Game/Entities/Traits/Status.hpp"
#include "Server/Zone/Game/Map/Map.hpp"
#include "Server/Zone/Game/Map/MapManager.hpp"
#include "Server/Zone/Game/Map/MapContainerThread.hpp"
#include "Server/Zone/Game/StaticDB/SkillDB.hpp"
#include "Server/Zone/Session/ZoneSession.hpp"
#include "Server/Zone/SocketMgr/ClientSocketMgr.hpp"
#include "Server/Zone/Zone.hpp"

#include <date/date.h>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/mysql/connection.h>


#include <memory>

using namespace Horizon::Zone;
using namespace Horizon::Zone::Entities;

ZoneClientInterface::ZoneClientInterface(std::shared_ptr<ZoneSession> s)
: ClientInterface(s)
{
	
}

ZoneClientInterface::~ZoneClientInterface()
{
}

bool ZoneClientInterface::login(uint32_t account_id, uint32_t char_id, uint32_t auth_code, uint32_t client_time, uint8_t gender)
{
	SQL::TableGameAccounts tga;
	SQL::TableSessionData tsd;
	SQL::TableCharacters tch;
	std::shared_ptr<sqlpp::mysql::connection> conn = sZone->get_db_connection();
	
	auto res = (*conn)(select(all_of(tsd)).from(tsd).where(tsd.game_account_id == account_id and tsd.auth_code == auth_code));
	
	if (res.empty()) {
		HLog(error) << "Login error! Session data for game account " << account_id << " and authentication code " << auth_code << " does not exist.";
		return false;
	}

	std::string current_server = res.front().current_server;
	if (current_server.compare("Z") == 0) {
		ZC_REFUSE_ENTER pkt(get_session());
		pkt.deliver(ZONE_SERV_ERROR_REJECT);
		return false;
	}
	
	auto res2 = (*conn)(select(all_of(tga)).from(tga).where(tga.id == account_id));
	
	if (res2.empty()) {
		HLog(error) << "Login error! Game account with id " << account_id << " does not exist.";
		return false;
	}
	
	(*conn)(update(tsd).set(tsd.current_server = "Z").where(tsd.game_account_id == account_id and tsd.auth_code == auth_code));
	
	auto res3 = (*conn)(select(all_of(tch)).from(tch).where(tch.id == char_id));
	
	if (res3.empty()) {
		HLog(error) << "Login error! Character with ID " << char_id << " does not exist.";
		return false;
	}
	
	MapCoords mcoords(res3.front().current_x, res3.front().current_y);
	std::shared_ptr<Map> map = MapMgr->get_map(res3.front().current_map);
	std::shared_ptr<Player> pl = std::make_shared<Player>(get_session(), account_id, map, mcoords);
	
	/* Initialize Player Model */
	pl->character()._character_id = res3.front().id;
	pl->character()._account_id = res3.front().account_id;
	pl->character()._slot = res3.front().slot;
	pl->set_name(res3.front().name);
	pl->set_posture(POSTURE_STANDING);
	pl->set_group_id(res2.front().group_id);
	
	std::string acc_gender = res2.front().gender;
	std::string char_gender = res3.front().gender;
	pl->character()._gender = strcmp(char_gender.c_str(), "U") == 0
		? (strcmp(acc_gender.c_str(), "M") == 0 ? ENTITY_GENDER_MALE : ENTITY_GENDER_FEMALE)
		: strcmp(char_gender.c_str(), "M") == 0 ? ENTITY_GENDER_MALE : ENTITY_GENDER_FEMALE;
	
	pl->character()._online = true;
	pl->set_last_unique_id((uint64_t) res3.front().last_unique_id);
	
	
	ZC_AID zc_aid(get_session());
	ZC_ACCEPT_ENTER2 zc_ae2(get_session());
	
	zc_aid.deliver(account_id);
	zc_ae2.deliver(uint16_t(res3.front().current_x), uint16_t(res3.front().current_y), DIR_SOUTH, uint16_t(res3.front().font));
	
	get_session()->set_player(pl);
	map->container()->add_player(std::move(pl));
	
	ClientSocktMgr->set_socket_for_removal(get_session()->get_socket());
	
	return true;
}

/**
 * All cleanups are managed in ZoneSocket::perform_cleanup
 */
bool ZoneClientInterface::restart(uint8_t type)
{
	ZC_RESTART_ACK rpkt(get_session());
	
	switch (type) {
		case 0:
			HLog(info) << "Character is being respawned.";
			break;
		default:
			SQL::TableSessionData tsd;
			std::shared_ptr<sqlpp::mysql::connection> conn = sZone->get_db_connection();
			(*conn)(update(tsd).where(tsd.game_account_id == get_session()->player()->character()._account_id).set(tsd.current_server = "C", tsd.last_update = std::time(nullptr)));
			rpkt.deliver(type);
			HLog(info) << "Character has moved to the character server.";
			break;
	}
	
	return true;
}

bool ZoneClientInterface::disconnect(int8_t type)
{
	ZC_ACK_REQ_DISCONNECT pkt(get_session());
	
	HLog(debug) << "ZoneClientInterface::disconnect: Type :" << type;

	pkt.deliver(type); // 0 => Quit, 1 => Wait for 10 seconds
	
	std::shared_ptr<Player> pl = get_session()->player();
	pl->map_container()->remove_player(pl);

	return true;
}

bool ZoneClientInterface::update_session(int32_t account_id)
{
	SQL::TableSessionData tsd;
	std::shared_ptr<sqlpp::mysql::connection> conn = sZone->get_db_connection();

	HLog(debug) << "Updating session from I.P. address " << get_session()->get_socket()->remote_ip_address();
	
	auto sres = (*conn)(select(all_of(tsd)).from(tsd).where(tsd.game_account_id == account_id));

	if (sres.empty()) {
		ZC_ACK_REQ_DISCONNECT pkt(get_session());
		HLog(warning) << "Invalid connection for account with ID " << account_id << ", session wasn't found.";
		pkt.deliver(0);
		return false;
	}

	std::string current_server = sres.front().current_server;

	if (current_server.compare("C") != 0) {
		ZC_ACK_REQ_DISCONNECT pkt(get_session());
		HLog(warning) << "Invalid connection for account with ID " << account_id << ", session wasn't found.";
		pkt.deliver(0);
		return false;
	}

	(*conn)(update(tsd).where(tsd.game_account_id == account_id).set(tsd.last_update = std::time(nullptr)));
	return true;
}

bool ZoneClientInterface::walk_to_coordinates(uint16_t x, uint16_t y, uint8_t dir)
{
	get_session()->player()->move_to_coordinates(x, y);
	return true;
}

bool ZoneClientInterface::notify_time()
{
	ZC_NOTIFY_TIME pkt(get_session());
	pkt.deliver();
	return true;
}


bool ZoneClientInterface::notify_entity_name(uint32_t guid)
{
	std::shared_ptr<Entity> entity = get_session()->player()->get_nearby_entity(guid);
	
	if (entity == nullptr)
		return false;

#if (CLIENT_TYPE == 'M' && PACKET_VERSION >= 20150225) \
	|| (CLIENT_TYPE == 'R' && PACKET_VERSION >= 20141126) \
	|| (CLIENT_TYPE == 'Z')
	ZC_ACK_REQNAMEALL2 req(get_session());
	req.deliver(guid, entity->name(), "", "", "", 0);
#else
	ZC_ACK_REQNAMEALL req(get_session());
	req.deliver(guid, entity->name(), "", "", "");
#endif
	
	return true;
}

entity_viewport_entry ZoneClientInterface::create_viewport_entry(std::shared_ptr<Entity> entity)
{
	entity_viewport_entry entry;

	if (entity == nullptr)
		return entry;
	
	std::shared_ptr<Traits::Status> status = entity->status();

	entry.guid = entity->guid();
	entry.unit_type = entity->type();
	entry.speed = status->movement_speed()->total();
	entry.body_state = 0;
	entry.health_state = 0;
	entry.effect_state = 0;
	entry.job_id = entity->job_id();
	entry.hair_style_id = status->hair_style()->get();
	entry.hair_color_id = status->hair_color()->get();
	entry.robe_id = status->robe_sprite()->get();
	entry.guild_id = 0;
	entry.guild_emblem_version = 0;
	entry.honor = 0;
	entry.virtue = 0;
	entry.in_pk_mode = 0;
	entry.current_x = entity->map_coords().x();
	entry.current_y = entity->map_coords().y();
	entry.current_dir = entity->direction();
	
	if (entity->is_walking()) {
		entry.to_x = entity->dest_coords().x();
		entry.to_y = entity->dest_coords().y();
	}
	
	entry.posture = entity->posture();
	entry.base_level = status->base_level()->total();
	entry.font = 1;

	// @TODO Add config opting to show hp bars.
	entry.max_hp = -1;
	entry.hp = -1;
	
	entry.is_boss = 0;
	entry.body_style_id = 0;
	std::strncpy(entry.name, entity->name().c_str(), entity->name().size());
	
	switch (entry.unit_type)
	{
		case ENTITY_PLAYER:
			entry.character_id = entity->downcast<Player>()->character()._character_id;
			entry.x_size = entry.y_size = 0;
			entry.gender = entity->downcast<Player>()->character()._gender;
			break;
		case ENTITY_NPC:
		default:
			entry.x_size = entry.y_size = 0;
			break;
	}
	
	return entry;
}

bool ZoneClientInterface::notify_player_movement(MapCoords from, MapCoords to)
{
	ZC_NOTIFY_PLAYERMOVE pkt(get_session());
	pkt.deliver(from.x(), from.y(), to.x(), to.y());
	return true;
}

bool ZoneClientInterface::notify_movement_stop(int32_t guid, int16_t x, int16_t y)
{
	ZC_STOPMOVE pkt(get_session());
	pkt.deliver(guid, x, y);
	return true;
}

bool ZoneClientInterface::notify_viewport_add_entity(entity_viewport_entry entry)
{
#if PACKET_VERSION >= 20150513
	ZC_NOTIFY_STANDENTRY11 pkt(get_session());
	pkt.deliver(entry);
#endif
	return true;
}

bool ZoneClientInterface::notify_viewport_spawn_entity(entity_viewport_entry entry)
{
	ZC_NOTIFY_NEWENTRY11 pkt(get_session());
	pkt.deliver(entry);
	return true;
}

bool ZoneClientInterface::notify_viewport_moving_entity(entity_viewport_entry entry)
{
#if PACKET_VERSION >= 20150513
	ZC_NOTIFY_MOVEENTRY11 pkt(get_session());
	pkt.deliver(entry);
#endif
	return true;
}

bool ZoneClientInterface::notify_viewport_remove_entity(std::shared_ptr<Entity> entity, entity_viewport_notification_type type)
{
	if (entity == nullptr)
		 return false;

	ZC_NOTIFY_VANISH pkt(get_session());
	pkt.deliver(entity->guid(), type);
	return true;
}

void ZoneClientInterface::notify_initial_status(std::shared_ptr<Traits::Status> status)
{
	if (status == nullptr)
		return;

	ZC_STATUS zcs(get_session());
	zc_status_data data;
	
	data.status_points = status->status_point()->get_base();
	data.strength = status->strength()->get_base();
	data.strength_req_stats = status->strength_cost()->get_base();
	data.agility = status->agility()->get_base();
	data.agility_req_stats = status->agility_cost()->get_base();
	data.vitality = status->vitality()->get_base();
	data.vitality_req_stats = status->vitality_cost()->get_base();
	data.intelligence = status->intelligence()->get_base();
	data.intelligence_req_stats = status->intelligence_cost()->get_base();
	data.dexterity = status->dexterity()->get_base();
	data.dexterity_req_stats = status->dexterity_cost()->get_base();
	data.luck = status->luck()->get_base();
	data.luck_req_stats = status->luck_cost()->get_base();
	data.status_atk = status->status_atk()->total();
	data.equip_atk = status->equip_atk()->total();
	data.status_matk = status->status_matk()->total();
	data.equip_matk = 0;
	data.soft_def = status->soft_def()->total();
	data.hard_def = 0;
	data.soft_mdef = status->soft_mdef()->total();
	data.hard_mdef = 0;
	data.hit = status->hit()->total();
	data.flee = status->flee()->total();
	data.perfect_dodge = 0;
	data.critical = status->crit()->total() / 10;
	data.attack_speed = status->aspd()->total();
	data.plus_aspd = 0;
	
	zcs.deliver(data);
}

bool ZoneClientInterface::notify_appearance_update(entity_appearance_type type, int32_t value, int32_t value2)
{
	ZC_SPRITE_CHANGE2 pkt(get_session());
	pkt.deliver(get_session()->player()->guid(), type, value, value2);
	return true;
}

// 0x00b0
bool ZoneClientInterface::notify_compound_attribute_update(status_point_type type, int32_t value)
{
	ZC_PAR_CHANGE pkt(get_session());
	pkt.deliver(type, value);
	return true;
}

// 0x00bc
bool ZoneClientInterface::notify_status_attribute_update(status_point_type type, int32_t value, bool success)
{
	ZC_STATUS_CHANGE_ACK pkt(get_session());
	pkt.deliver(type, value, success);
	return true;
}

// 0x00be
bool ZoneClientInterface::notify_required_attribute_update(status_point_type type, int32_t value)
{
	ZC_STATUS_CHANGE pkt(get_session());
	pkt.deliver(type, value);
	return true;
}

// 0x0121
bool ZoneClientInterface::notify_cart_weight_update()
{
	return true;
}

// 0x013a
bool ZoneClientInterface::notify_attack_range_update(int32_t value)
{
	ZC_ATTACK_RANGE pkt(get_session());
	pkt.deliver(value);
	return true;

}

// 0x0acb
bool ZoneClientInterface::notify_experience_update(status_point_type type, int32_t value)
{
	notify_compound_attribute_update(type, value);
	return true;
}

// 0x00b1
bool ZoneClientInterface::notify_zeny_update()
{
	return true;
}

bool ZoneClientInterface::increase_status_point(status_point_type type, uint8_t amount)
{
	std::shared_ptr<Player> pl = get_session()->player();

	if (pl == nullptr)
		return false;

	pl->status()->increase_status_point(type, amount);
	return true;
}

void ZoneClientInterface::npc_contact(int32_t guid)
{

}

void ZoneClientInterface::notify_npc_dialog(uint32_t npc_guid, std::string dialog)
{
	uint32_t current_npc_guid = get_session()->player()->npc_contact_guid();
	
}

void ZoneClientInterface::notify_npc_next_dialog(uint32_t npc_guid)
{
	ZC_WAIT_DIALOG pkt(get_session());
	pkt.deliver(npc_guid);
}

void ZoneClientInterface::notify_npc_close_dialog(uint32_t npc_guid)
{
	ZC_CLOSE_DIALOG pkt(get_session());
	pkt.deliver(npc_guid);
}

void ZoneClientInterface::notify_npc_menu_list(uint32_t npc_guid, std::string const &menu)
{
	ZC_MENU_LIST pkt(get_session());
	pkt.deliver(npc_guid, menu);
}

bool ZoneClientInterface::notify_move_to_map(std::string map_name, int16_t x, int16_t y)
{
	ZC_NPCACK_MAPMOVE pkt(get_session());
	pkt.deliver(map_name, x, y);
	return true;
}

bool ZoneClientInterface::notify_chat(std::string message)
{
	ZC_NOTIFY_PLAYERCHAT pkt(get_session());
	pkt.deliver(message);
	return true;
}

void ZoneClientInterface::parse_chat_message(std::string message)
{
	ZC_NOTIFY_PLAYERCHAT notify_player_chat(get_session());
	ZC_NOTIFY_CHAT notify_chat(get_session());

	HLog(debug) << get_session()->player()->name() << ": " << message;

	int guid = get_session()->player()->guid();
	int msg_first_char = get_session()->player()->name().size() + 3;

	if (message[msg_first_char] == '@') {
		get_session()->player()->script_manager()->perform_command_from_player(get_session()->player(), &message[msg_first_char + 1]);
		return;
	}

	ByteBuffer buf;

	notify_chat._packet_length = 8 + message.size();
	notify_chat._guid = guid;
	notify_chat._message = message;
	buf = notify_chat.serialize();
	get_session()->player()->notify_in_area(buf, GRID_NOTIFY_AREA_WOS);
	notify_player_chat.deliver(message);
}

void ZoneClientInterface::map_enter()
{
	get_session()->player()->on_map_enter();
}

bool ZoneClientInterface::notify_map_properties(zc_map_properties p)
{
	ZC_MAPPROPERTY_R2 pkt(get_session());
	pkt.deliver(p);
	return true;
}

void ZoneClientInterface::whisper_message(const char *name, int32_t name_length, const char *message, int32_t message_length)
{
	// validate name
	// only restriction is that the name must be zero-terminated
	if (name[name_length] != '\0') {
		HLog(warning) << "ZoneClientInterface::whisper_message: Player '" << get_session()->player()->name() << "' sent an unterminated name!\n";
		return;
	}
	// validate name
	// only restriction is that the name must be zero-terminated
	if (message[message_length] != '\0') {
		HLog(warning) << "ZoneClientInterface::whisper_message: Player '" << get_session()->player()->name() << "' sent an unterminated message!\n";
		return;
	}

	HLog(debug) << name << " : " << message;

	std::shared_ptr<Player> player = MapMgr->find_player(name);

	ZC_ACK_WHISPER02 pkt(get_session());
	if (player != nullptr)
		pkt.deliver(WRT_SUCCESS, player->character()._character_id);
	else
		pkt.deliver(WRT_RECIPIENT_OFFLINE, 0);

	ZC_WHISPER pkt2(player->get_session());
	pkt2.deliver(get_session()->player()->name(), message, player->group_id() >= 99 ? true : false);
}

void ZoneClientInterface::use_item(int16_t inventory_index, int32_t guid)
{
	get_session()->player()->inventory()->use_item(inventory_index, guid);
}

void ZoneClientInterface::equip_item(int16_t inventory_index, int16_t equip_location_mask)
{
	get_session()->player()->inventory()->equip_item(inventory_index, equip_location_mask);
}

void ZoneClientInterface::unequip_item(int16_t inventory_index)
{
	get_session()->player()->inventory()->unequip_item(inventory_index);
}

bool ZoneClientInterface::notify_pickup_item(item_entry_data id, int16_t amount, item_inventory_addition_notif_type result)
{
	ZC_ITEM_PICKUP_ACK_V7 pkt(get_session());
	pkt.deliver(id, amount, result);
	return true;
}

bool ZoneClientInterface::notify_normal_item_list(std::vector<std::shared_ptr<const item_entry_data>> const &items)
{
	ZC_INVENTORY_ITEMLIST_NORMAL_V5 pkt(get_session());
	pkt.deliver(items);
	return true;
}

bool ZoneClientInterface::notify_equipment_item_list(std::vector<std::shared_ptr<const item_entry_data>> const &items)
{
	ZC_INVENTORY_ITEMLIST_EQUIP_V6 pkt(get_session());
	pkt.deliver(items);
	return true;
}

bool ZoneClientInterface::notify_throw_item(int16_t inventory_index, int16_t amount)
{
	ZC_ITEM_THROW_ACK pkt(get_session());
	pkt.deliver(inventory_index, amount);
	return true;
}

bool ZoneClientInterface::notify_inventory_move_failed(int16_t inventory_index, bool silent)
{
	ZC_INVENTORY_MOVE_FAILED pkt(get_session());
	pkt.deliver(inventory_index, silent);
	return true;
}

bool ZoneClientInterface::notify_delete_item(int16_t inventory_index, int16_t amount, item_deletion_reason_type reason)
{
	ZC_DELETE_ITEM_FROM_BODY pkt(get_session());
	pkt.deliver(inventory_index, amount, reason);
	return true;
}

bool ZoneClientInterface::notify_bind_on_equip(int16_t inventory_index)
{
	ZC_NOTIFY_BIND_ON_EQUIP pkt(get_session());
	pkt.deliver(inventory_index);
	return true;
}

bool ZoneClientInterface::notify_use_item(std::shared_ptr<item_entry_data> inv_item, bool success)
{
	ZC_USE_ITEM_ACK pkt(get_session());
	pkt.deliver(inv_item->inventory_index, inv_item->amount, success);
	return true;
}

bool ZoneClientInterface::notify_equip_item(std::shared_ptr<const item_entry_data> item, item_equip_result_type result)
{
	ZC_ACK_WEAR_EQUIP_V5 pkt(get_session());
	pkt.deliver(item->inventory_index, item->current_equip_location_mask, item->sprite_id, result);
	return true;
}

bool ZoneClientInterface::notify_unequip_item(std::shared_ptr<const item_entry_data> item, item_unequip_result_type result)
{
	ZC_ACK_TAKEOFF_EQUIP_V5 pkt(get_session());
	pkt.deliver(item->inventory_index, item->current_equip_location_mask, result);
	return true;
}

bool ZoneClientInterface::notify_equip_arrow(std::shared_ptr<const item_entry_data> item)
{
	ZC_EQUIP_ARROW pkt(get_session());
	pkt.deliver(item->inventory_index);
	return true;
}

bool ZoneClientInterface::notify_action_failure(int16_t message_type)
{
	ZC_ACTION_FAILURE pkt(get_session());
	pkt.deliver(message_type);
	return true;
}

void ZoneClientInterface::upgrade_skill_level(int16_t skill_id)
{
	ZC_SKILLINFO_UPDATE pkt(get_session());
	
	std::shared_ptr<skill_learnt_info> ls = get_session()->player()->get_learnt_skill(skill_id);

	if (ls == nullptr) {
		skill_learnt_info s;
		s.skill_id = skill_id;
		s.level = 1;
		s.learn_type = SKILL_LEARN_PERMANENT;
		ls = std::make_shared<skill_learnt_info>(s);
		get_session()->player()->add_learnt_skill(ls);
	} else {
		ls->level += 1;
	}

	std::shared_ptr<const skill_config_data> skd = SkillDB->get_skill_by_id(ls->skill_id);

	bool upgradeable = false;

	job_class_type job_id = (job_class_type) get_session()->player()->job_id();
	std::shared_ptr<const skill_tree_config> stc = SkillDB->get_skill_tree_skill_id_by_job_id(job_id, ls->skill_id);

	if (stc == nullptr) {
		HLog(error) << "Skill ID " << ls->skill_id << " not found for Job ID " << (int32_t) job_id << ".";
		return;
	}

	upgradeable = (ls->level < stc->max_level) ? true : false;

	get_session()->player()->status()->skill_point()->sub_base(1);

	pkt.deliver(skill_id, ls->level, skd->sp_cost[ls->level], skd->use_range[ls->level], upgradeable);
}

bool ZoneClientInterface::notify_learnt_skill_list()
{
	const std::map<uint16_t, std::shared_ptr<skill_learnt_info>> &learnt_skills = get_session()->player()->get_learnt_skills();
	std::vector<zc_skill_info_data> sidv;

	for (auto sp : learnt_skills) {
		const std::shared_ptr<skill_learnt_info> ls = sp.second;

		if (ls == nullptr) {
			HLog(error) << "Learnt skill was a nullptr.";
			continue;
		}

		zc_skill_info_data si;

		std::shared_ptr<const skill_config_data> skd = SkillDB->get_skill_by_id(ls->skill_id);
		
		if (skd == nullptr) {
			HLog(error) << "Tried to send data for unknown skill with ID " << ls->skill_id;
			continue;
		}

		si.skill_id = ls->skill_id;
		si.skill_type = skd->primary_type;
		si.level = ls->level;

		si.sp_cost = ls->level ? skd->sp_cost[ls->level] : 0;
		si.range = ls->level ? skd->use_range[ls->level] : 0;
		
#if (CLIENT_VERSION == 'R' && PACKET_VERSION >= 20190807) || \
	(CLIENT_VERSION == 'Z' && PACKET_VERSION >= 20190918)
		si.level2 = ls->level;
#else
		strncpy(si.name, skd->name.c_str(), MAX_SKILL_NAME_LENGTH);
#endif

		if (ls->learn_type == SKILL_LEARN_PERMANENT) {
			job_class_type job_id = (job_class_type) get_session()->player()->job_id();
			std::shared_ptr<const skill_tree_config> stc = SkillDB->get_skill_tree_skill_id_by_job_id(job_id, ls->skill_id);

			if (stc == nullptr) {
				HLog(error) << "Skill ID " << ls->skill_id << " not found for Job ID " << (int32_t) job_id << ".";
				continue;
			}

			si.upgradeable = (ls->level < stc->max_level) ? 1 : 0;
		}

		sidv.push_back(si);
	}

	ZC_SKILLINFO_LIST pkt(get_session());
	pkt.deliver(sidv);

	return true;
}
