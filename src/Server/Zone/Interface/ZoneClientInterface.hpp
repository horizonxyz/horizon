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

#ifndef HORIZON_ZONECLIENTINTERFACE_HPP
#define HORIZON_ZONECLIENTINTERFACE_HPP

#include "Server/Common/Base/NetworkPacket.hpp"
#include "Server/Zone/Definitions/EntityDefinitions.hpp"
#include "Server/Zone/Definitions/SkillDefinitions.hpp"
#include "Server/Zone/Definitions/PlayerDefinitions.hpp"
#include "Server/Common/Interfaces/ClientInterface.hpp"
#include "Server/Zone/Game/Map/Grid/GridDefinitions.hpp"
#include "Server/Zone/Packets/TransmittedPackets.hpp"
#include "Server/Zone/Interface/UI/Chatroom/Chatroom.hpp"
#include "Server/Zone/Interface/UI/Trade/Trade.hpp"
#include "Server/Zone/Interface/UI/Party/Party.hpp"
#include "Server/Zone/Interface/UI/Guild/Guild.hpp"

namespace Horizon
{
namespace Zone
{
namespace Entities
{
namespace Traits
{
	class Status;
}
}
class Entity;
class ZoneSession;
class ZoneClientInterface : public ClientInterface<ZoneSession>
{
public:
	ZoneClientInterface(std::shared_ptr<ZoneSession> s);
	~ZoneClientInterface();
	
	UI::Chatroom &chatroom() { return _chat_room; }
	UI::Trade &trade() { return _trade; }
	UI::Party &party() { return _party; }
	UI::Guild& guild() { return _guild; }

	bool login(uint32_t account_id, uint32_t char_id, uint32_t auth_code, uint32_t client_time, uint8_t gender);
	bool restart(uint8_t type);
	bool disconnect(int8_t type);
	bool update_session(int32_t account_id);
	
	bool walk_to_coordinates(uint16_t x, uint16_t y, uint8_t dir);
	
	bool notify_time();
	bool notify_entity_name(uint32_t guid);
	bool stop_attack();
	
	/* Movement & Viewport*/
	bool notify_player_movement(MapCoords from, MapCoords to);
	bool notify_movement_stop(int32_t guid, int16_t x, int16_t y);
	bool notify_entity_move(int32_t guid, MapCoords from, MapCoords to);

	entity_viewport_entry create_viewport_entry(std::shared_ptr<Entity> entity);
	bool notify_viewport_add_entity(entity_viewport_entry entry);
	bool notify_viewport_remove_entity(std::shared_ptr<Entity> entity, entity_viewport_notification_type type);
	bool notify_viewport_moving_entity(entity_viewport_entry entry);
	bool notify_viewport_spawn_entity(entity_viewport_entry entry);
	
	/**
	 * NPC
	 */
	void npc_contact(int32_t guid);
	void notify_npc_dialog(uint32_t npc_guid, std::string dialog);
	void notify_npc_next_dialog(uint32_t npc_guid);
	void notify_npc_close_dialog(uint32_t npc_guid);
	void notify_npc_menu_list(uint32_t npc_guid, std::string const &menu);
	uint32_t get_npc_contact_guid() { return _npc_contact_guid; }
	void set_npc_contact_guid(uint32_t guid) { _npc_contact_guid = guid; }
	
	/**
	 * Status
	 */
	bool notify_initial_status();
	bool notify_appearance_update(entity_appearance_type type, int32_t value, int32_t value2);
	bool notify_compound_attribute_update(status_point_type type, int32_t value);
	bool notify_status_attribute_update(status_point_type type, int32_t value, bool success);
	bool notify_required_attribute_update(status_point_type type, int32_t value);
	bool notify_cart_weight_update();
	bool notify_attack_range_update(int32_t value);
	bool notify_experience_update(status_point_type type, int32_t value);
	bool notify_zeny_update();
	bool increase_status_point(status_point_type type, uint8_t amount);
	/**
	 * Map
	 */
	bool notify_move_to_map(std::string map_name, int16_t x, int16_t y);
	void map_enter();
	bool notify_map_properties(zc_map_properties properties);

	/**
	 * Chat
	 */
	bool notify_chat(std::string message);
	void parse_chat_message(std::string message);
	void whisper_message(const char *name, int32_t name_length, const char *message, int32_t message_length);

	/**
	 * Items
	 */
	void use_item(int16_t inventory_index, int32_t guid);
	void equip_item(int16_t inventory_index, int16_t equip_location_mask);
	void unequip_item(int16_t inventory_index);
	bool notify_pickup_item(item_entry_data id, int16_t amount, item_inventory_addition_notif_type result);
	bool notify_normal_item_list(std::vector<std::shared_ptr<const item_entry_data>> const &items);
	bool notify_equipment_item_list(std::vector<std::shared_ptr<const item_entry_data>> const &items);
	bool notify_throw_item(int16_t inventory_index, int16_t amount);
	bool notify_inventory_move_failed(int16_t inventory_index, bool silent);
	bool notify_delete_item(int16_t inventory_index, int16_t amount, item_deletion_reason_type reason);
	bool notify_bind_on_equip(int16_t inventory_index);
	bool notify_use_item(std::shared_ptr<item_entry_data> inv_item, bool success);
	bool notify_equip_item(std::shared_ptr<const item_entry_data> item, item_equip_result_type result);
	bool notify_unequip_item(std::shared_ptr<const item_entry_data> item, item_unequip_result_type result);
	bool notify_equip_arrow(std::shared_ptr<const item_entry_data> item);
	bool notify_action_failure(int16_t message_type);

	/**
	 * Skills
	 */
	void upgrade_skill_level(int16_t skill_id);
	bool notify_learnt_skill_list();
	bool notify_skill_fail(int16_t skill_id, int32_t message_type, int32_t item_id, skill_use_fail_cause_type cause);

	/* UI Requests */
	void action_request(int32_t target_guid, player_action_type action);
	bool notify_action(player_action_type action);

	/**
	 * Status
	 */
	bool notify_status_change(int16_t si_type, int32_t guid, int8_t state, int32_t time_remaining, int32_t val1, int32_t val2, int32_t val3);
	bool notify_status_change_end(int16_t status_index, int32_t guid, int8_t state);

	/**
	 * Combat
	 */
	bool notify_damage(int guid, int target_guid, int start_time, int delay_skill, int delay_damage, int damage, bool is_sp_damaged, int number_of_hits, int8_t action_type, int left_damage);

protected:
	uint32_t _npc_contact_guid{0};
	UI::Chatroom _chat_room;
	UI::Trade _trade;
	UI::Party _party;
	UI::Guild _guild;
};
}
}

#endif /* HORIZON_ZONECLIENTINTERFACE_HPP */
