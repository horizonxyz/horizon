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

#ifndef HORIZON_ZONE_GAME_ASSETS_INVENTORY_HPP
#define HORIZON_ZONE_GAME_ASSETS_INVENTORY_HPP

#include "Common/Definitions/ItemDefinitions.hpp"

#include <unordered_map>
#include <array>

namespace Horizon
{
namespace Zone
{
namespace Entities
{
	class Player;
}
namespace Assets
{
enum inventory_addition_result_type
{
	INVENTORY_ADD_SUCCESS          = 0, /// Success
	INVENTORY_ADD_INVALID          = 1, /// Invalid itemid not found or negative amount
	INVENTORY_ADD_OVER_WEIGHT      = 2, /// Overweight
	INVENTORY_ADD_NO_INV_SPACE     = 3, /// No free place found
	INVENTORY_ADD_OVER_QUANTITY    = 4, /// Max amount reached
	INVENTORY_ADD_OVER_STACK_LIMIT = 5, /// Stack limitation
};
enum inventory_deletion_reason_type
{
	INVENTORY_DEL_NORMAL         = 0, /// Normal
	INVENTORY_DEL_SKILLUSE       = 1, /// Item used for a skill
	INVENTORY_DEL_FAILREFINE     = 2, /// Refine failed
	INVENTORY_DEL_MATERIALCHANGE = 3, /// Material changed
	INVENTORY_DEL_TOSTORAGE      = 4, /// Moved to storage
	INVENTORY_DEL_TOCART         = 5, /// Moved to cart
	INVENTORY_DEL_SOLD           = 6, /// Item sold
	INVENTORY_DEL_ANALYSIS       = 7, /// Consumed by Four Spirit Analysis (SO_EL_ANALYSIS) skill
};
class Inventory
{
	typedef std::vector<std::shared_ptr<item_entry_data>> inventory_storage_type;
public:
	Inventory(std::shared_ptr<Entities::Player> player, uint32_t max_storage);
	virtual ~Inventory();

//	std::shared_ptr<PacketHandler> get_packet_handler() { return _packet_handler.lock(); }

	std::shared_ptr<Entities::Player> player() { return _player.lock(); }
	inventory_addition_result_type add_item(uint32_t item_id, uint16_t amount, bool is_identified = false);

	bool use_item(uint32_t inventory_index, uint32_t guid);
	bool can_equip(uint32_t inventory_index);
	item_equip_result_type equip_item(uint32_t inventory_index, uint16_t equip_location_mask);
	item_unequip_result_type unequip_item(uint32_t inventory_index);
	EquipmentListType &equipments() { return _equipments; }
	void add_to_equipment_list(std::shared_ptr<item_entry_data> item);
	void remove_from_equipment_list(std::shared_ptr<item_entry_data> item);

	void notify_all();
	void notify_without_equipments();
	void notify_only_equipments();
	void notify_add(item_entry_data const &data, uint16_t amount, inventory_addition_result_type fail);
	void notify_deletion(uint16_t idx, uint16_t amount, inventory_deletion_reason_type reason);
	void notify_drop(uint16_t idx, uint16_t amount);
	void notify_move_fail(uint16_t idx, bool silent);
	void save();
	uint32_t load();

	void set_max_storage(uint32_t max_storage) { _max_storage = max_storage; }
	uint32_t max_storage() { return _max_storage; }

	void print_inventory();

protected:
	uint32_t calculate_current_equip_location_mask(std::shared_ptr<const item_config_data> item);
private:
	int32_t _max_storage;
	std::weak_ptr<Entities::Player> _player;
	EquipmentListType _equipments;
	inventory_storage_type _inventory_items;
	inventory_storage_type _saved_inventory_items;
};
}
}
}
#endif /* HORIZON_ZONE_GAME_ASSETS_INVENTORY_HPP */
