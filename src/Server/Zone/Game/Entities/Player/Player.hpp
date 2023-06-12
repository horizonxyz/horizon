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

#ifndef HORIZON_ZONE_GAME_ENTITIES_PLAYER_HPP
#define HORIZON_ZONE_GAME_ENTITIES_PLAYER_HPP

#include "Server/Common/Configuration/Horizon.hpp" // MAX_INVENTORY_SIZE
#include "Server/Zone/Definitions/PlayerDefinitions.hpp"
#include "Server/Zone/Definitions/ClientDefinitions.hpp"
#include "Server/Zone/Game/Entities/Entity.hpp"
#include "Server/Zone/Game/Entities/GridObject.hpp"
#include "Server/Zone/Game/StaticDB/JobDB.hpp"
#include "Server/Zone/Definitions/EntityDefinitions.hpp" // entity_gender_types
#include "Server/Zone/Definitions/ItemDefinitions.hpp"
#include "Server/Zone/Definitions/NPCDefinitions.hpp"
#include "Server/Zone/Definitions/SkillDefinitions.hpp"



class ByteBuffer;

namespace Horizon
{
namespace Zone
{
class ZoneSession;
namespace Assets
{
	class Inventory;
}
namespace Entities
{
class Player : public Entity, public GridObject<Player>
{
	struct s_char_data {
		int32_t _character_id{0};
		int16_t _slot{0};
		int8_t _online{0};
		entity_gender_types _gender{ENTITY_GENDER_FEMALE};
		int32_t _max_inventory_size{MAX_INVENTORY_SIZE};
		int64_t _last_unique_id{0};
		int8_t _font{0};
		int32_t _unban_time{0};
		int32_t _rename_count{0};
		int16_t _hotkey_row_index{0};
		int32_t _change_slot_count{0};
		int8_t _show_equip{0}; 
		int8_t _allow_party{0};
		int32_t _partner_aid{0};
		int32_t _father_aid{0}, _mother_aid{0}, _child_aid{0};
		int32_t _party_id{0}, _guild_id{0};
		int32_t _homun_id{0}, _pet_id{0}, _elemental_id{0};
		std::string _saved_map{""};
		int32_t _saved_x{0}, _saved_y{0};
	};

	struct s_account_data {
		int32_t _account_id{0};
		std::string _account_gender{""};
		int16_t _group_id{0};
	};
	
public:
	Player(std::shared_ptr<ZoneSession> session, uint32_t guid);
	~Player();

	std::shared_ptr<ZoneSession> get_session() { return _session; }

	void create(int char_id, std::string account_gender, int group_id);

	bool initialize();

	/**
	 * Grid applications
	 */
	void update_viewport();

	/**
	 * Movement
	 */
	void realize_entity_movement(std::shared_ptr<Entity> entity);
	void realize_entity_movement_entry(std::shared_ptr<Entity> entity);

	void add_entity_to_viewport(std::shared_ptr<Entity> entity);
	void remove_entity_from_viewport(std::shared_ptr<Entity> entity, entity_viewport_notification_type type);
	void spawn_entity_in_viewport(std::shared_ptr<Entity> entity);
	bool entity_is_in_viewport(std::shared_ptr<Entity> entity);

	void notify_in_area(ByteBuffer &buf, grid_notifier_type type, uint16_t range = MAX_VIEW_RANGE);
	bool move_to_map(std::shared_ptr<Map> map, MapCoords coords = { 0, 0 });
	void notify_map_properties();
	void on_map_enter();

	void stop_movement() override;
	void on_pathfinding_failure() override;
	void on_movement_begin() override;
	void on_movement_step() override;
	void on_movement_end() override;

	bool is_overweight_50();
	bool is_overweight_90();
	/**
	 * DB Synchronizations.
	 */
	bool save();
	bool load();

	uint64_t new_unique_id();

	bool is_logged_in() { return _is_logged_in; }
	bool set_logged_in(bool logged_in) { return _is_logged_in.exchange(logged_in); }

	s_char_data &character() { return _char; }
	s_account_data &account() { return _account; }

	bool job_change(int32_t job_id);
	
	/**
	 * Item Stores
	 */
	void set_last_unique_id(uint64_t last_unique_id) { character()._last_unique_id = last_unique_id; }
	uint64_t last_unique_id() { return character()._last_unique_id; }
	uint32_t get_max_inventory_size() { return character()._max_inventory_size; }
	void set_max_inventory_size(uint32_t size) { character()._max_inventory_size = size; }
	void on_item_equip(std::shared_ptr<const item_entry_data> item);
	void on_item_unequip(std::shared_ptr<const item_entry_data> item);
	std::shared_ptr<Assets::Inventory> inventory() { return _inventory; }

	/**
	 * NPC / Script applications
	 */
	std::shared_ptr<sol::state> lua_state() { return _lua_state; }
	void send_npc_dialog(uint32_t npc_guid, std::string dialog);
	void send_npc_next_dialog(uint32_t npc_guid);
	void send_npc_close_dialog(uint32_t npc_guid);
	void send_npc_menu_list(uint32_t npc_guid, std::string const &menu);
	int32_t npc_contact_guid() { return _npc_contact_guid; }
	void set_npc_contact_guid(int32_t guid) { _npc_contact_guid = guid; }

	std::vector<std::weak_ptr<Entity>> &get_viewport_entities() { return _viewport_entities; }

	std::map<uint16_t, std::shared_ptr<skill_learnt_info>> &get_learnt_skills() { return _learnt_skills; }
	std::shared_ptr<skill_learnt_info> get_learnt_skill(uint16_t skill_id) 
	{ 
		try { 
			return _learnt_skills.at(skill_id); 
		} catch (std::exception e) { 
			return nullptr; 
		} 
	}

	void add_learnt_skill(std::shared_ptr<skill_learnt_info> i) { _learnt_skills.insert({ i->skill_id, i }); }
	
	std::shared_ptr<const job_config_data> job() { return _job; }
	void set_job(std::shared_ptr<const job_config_data> j) { _job = j; }
	
	/**
	 * Skills
	 */
	bool on_action_request(player_action_type action);
	bool perform_action(player_action_type action);
	bool perform_skill(int16_t skill_id, int16_t skill_lv);
	bool on_skill_failure(int16_t skill_id, int message_type, int item_id, skill_use_fail_cause_type cause);
	/**
	 * Status Effects
	 */
    void on_status_effect_start(std::shared_ptr<status_change_entry> sce) override;
    void on_status_effect_end(std::shared_ptr<status_change_entry> sce) override;
    void on_status_effect_change(std::shared_ptr<status_change_entry> sce) override;

    bool attack(std::shared_ptr<Entity> e, bool continuous = false) override;
    bool stop_attack();
private:
	std::shared_ptr<ZoneSession> _session;
	std::shared_ptr<sol::state> _lua_state;
	std::shared_ptr<Assets::Inventory> _inventory;
	std::atomic<bool> _is_logged_in{false};
	int32_t _npc_contact_guid{0};

	std::vector<std::weak_ptr<Entity>> _viewport_entities;
	
	std::map<uint16_t, std::shared_ptr<skill_learnt_info>> _learnt_skills;

	s_char_data _char;
	s_account_data _account;

	std::shared_ptr<const job_config_data> _job;
};
}
}
}

#endif /* HORIZON_ZONE_GAME_ENTITIES_PLAYER_HPP */
