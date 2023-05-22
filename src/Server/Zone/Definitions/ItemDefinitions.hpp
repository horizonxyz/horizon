/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
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

#ifndef HORIZON_ZONE_ITEM_DEFINITIONS
#define HORIZON_ZONE_ITEM_DEFINITIONS

#include "Server/Zone/Definitions/EntityDefinitions.hpp"

#define ITEM_NAME_LENGTH 50
#define UNKNOWN_ITEM_ID 512 // Apple

#define MAX_ITEM_OPTIONS 5
#define MAX_ITEM_SLOTS 4
#define MAX_REFINE_LEVEL 20

static_assert(MAX_ITEM_OPTIONS >= 0, "MAX_ITEM_OPTIONS cannot be less than 0.");
static_assert(MAX_ITEM_OPTIONS <= 5,
			  "MAX_ITEM_OPTIONS is limited by the client and database layout "
			  "and should not be changed unless supported by the client.");
static_assert(MAX_ITEM_SLOTS > 0 && MAX_ITEM_SLOTS <= 4,
			  "MAX_ITEM_SLOTS is limited by the client and database layout "
			  "and should not be changed unless supported by the client.");

#define MIN_INVENTORY_SIZE 100
#define MAX_INVENTORY_SIZE 300

static_assert(MIN_INVENTORY_SIZE > 0 && MAX_INVENTORY_SIZE > MIN_INVENTORY_SIZE,
              "Max Inventory should be greater than minimum storage size of 1.");

#define MIN_STORAGE_SIZE 600
#define MAX_STORAGE_SIZE 600

static_assert(MIN_STORAGE_SIZE > 0 && MAX_STORAGE_SIZE >= MIN_STORAGE_SIZE,
              "Max storage should be greater than minimum storage size of 1.");

#define MAX_INVENTORY_STACK_LIMIT 30000
#define MAX_CART_STACK_LIMIT 30000
#define MAX_STORAGE_STACK_LIMIT 30000
#define MAX_GSTORAGE_STACK_LIMIT 30000

static_assert(MAX_INVENTORY_STACK_LIMIT > 0,
              "MAX_INVENTORY_STACK_LIMIT should be greater than 0.");
static_assert(MAX_CART_STACK_LIMIT > 0,
              "MAX_CART_STACK_LIMIT should be greater than 0.");
static_assert(MAX_STORAGE_STACK_LIMIT > 0,
              "MAX_STORAGE_STACK_LIMIT should be greater than 0.");
static_assert(MAX_GSTORAGE_STACK_LIMIT > 0,
              "MAX_GSTORAGE_STACK_LIMIT should be greater than 0.");

enum refine_type
{
	REFINE_TYPE_ARMOR   = 0,
	REFINE_TYPE_WEAPON1 = 1,
	REFINE_TYPE_WEAPON2 = 2,
	REFINE_TYPE_WEAPON3 = 3,
	REFINE_TYPE_WEAPON4 = 4,
	REFINE_TYPE_MAX     = 5
};

enum refine_chance_type
{
	REFINE_CHANCE_TYPE_NORMAL     = 0, // Normal Chance
	REFINE_CHANCE_TYPE_ENRICHED   = 1, // Enriched Ore Chance
	REFINE_CHANCE_TYPE_E_NORMAL   = 2, // Event Normal Ore Chance
	REFINE_CHANCE_TYPE_E_ENRICHED = 3, // Event Enriched Ore Chance
	REFINE_CHANCE_TYPE_MAX
};

enum item_weapon_type
{
	IT_WT_FIST      = 0,      ///< Bare hands
	IT_WT_DAGGER    = 1,
	IT_WT_1HSWORD   = 2,
	IT_WT_2HSWORD   = 3,
	IT_WT_1HSPEAR   = 4,
	IT_WT_2HSPEAR   = 5,
	IT_WT_1HAXE     = 6,
	IT_WT_2HAXE     = 7,
	IT_WT_1HMACE    = 8,
	IT_WT_2HMACE    = 9,
	IT_WT_STAFF     = 10,
	IT_WT_BOW       = 11,
	IT_WT_KNUCKLE   = 12,
	IT_WT_MUSICAL   = 13,
	IT_WT_WHIP      = 14,
	IT_WT_BOOK      = 15,
	IT_WT_KATAR     = 16,
	IT_WT_REVOLVER  = 17,
	IT_WT_RIFLE     = 18,
	IT_WT_GATLING   = 19,
	IT_WT_SHOTGUN   = 20,
	IT_WT_GRENADE   = 21,
	IT_WT_HUUMA     = 22,
	IT_WT_2HSTAFF   = 23,
	IT_WT_SINGLE_MAX,
	// dual-wield constants
	IT_WT_DOUBLE_DAGGERS, ///< 2 daggers
	IT_WT_DOUBLE_SWORDS, ///< 2 swords
	IT_WT_DOUBLE_AXES, ///< 2 axes
	IT_WT_DOUBLE_DAGGER_SWORD, ///< dagger + sword
	IT_WT_DOUBLE_DAGGER_AXE, ///< dagger + axe
	IT_WT_DOUBLE_SWORD_AXE, ///< sword + axe
#ifndef MAX_WEAPON_TYPE
	IT_WT_MAX_WEAPON_TYPE,
#endif
};

enum item_weapon_type_mask
{
	IT_WTM_RANGED = (1ULL << IT_WT_BOW) | (1ULL << IT_WT_WHIP) | (1ULL << IT_WT_MUSICAL)
					| (1ULL << IT_WT_RIFLE) | (1ULL < IT_WT_GATLING) | (1ULL << IT_WT_SHOTGUN)
					| (1ULL << IT_WT_REVOLVER) | (1ULL << IT_WT_GRENADE),
	IT_WTM_MELEE  = (1ULL << IT_WT_DAGGER)| (1ULL << IT_WT_1HSWORD) | (1ULL << IT_WT_2HSWORD)
					| (1ULL << IT_WT_1HSPEAR) | (1ULL << IT_WT_1HAXE) | (1ULL << IT_WT_2HAXE) | (1ULL << IT_WT_1HMACE)
					| (1ULL << IT_WT_2HMACE) | (1ULL << IT_WT_KNUCKLE) | (1ULL << IT_WT_KATAR)
					| (1ULL << IT_WT_HUUMA)
};

enum item_level_type
{
	IT_LVL_ARMOR       = 0,
	IT_LVL_WEAPON1     = 1,
	IT_LVL_WEAPON2     = 2,
	IT_LVL_WEAPON3     = 3,
	IT_LVL_WEAPON4     = 4,
	IT_LVL_MAX
};

enum item_gender_type
{
	IT_GENDER_FEMALE = 0,
	IT_GENDER_MALE   = 1,
	IT_GENDER_ANY    = 2
};

//Equip position constants
enum item_equip_location_mask
{
	IT_EQPM_NONE               = 0x000000,
	IT_EQPM_HEAD_LOW           = 0x000001,
	IT_EQPM_HAND_R             = 0x000002, //2
	IT_EQPM_GARMENT            = 0x000004, //4
	IT_EQPM_ACC_L              = 0x000008, //8
	IT_EQPM_ARMOR              = 0x000010, //16
	IT_EQPM_HAND_L             = 0x000020, //32
	IT_EQPM_SHOES              = 0x000040, //64
	IT_EQPM_ACC_R              = 0x000080, //128
	IT_EQPM_HEAD_TOP           = 0x000100, //256
	IT_EQPM_HEAD_MID           = 0x000200, //512
	IT_EQPM_COSTUME_HEAD_TOP   = 0x000400, //1024
	IT_EQPM_COSTUME_HEAD_MID   = 0x000800, //2048
	IT_EQPM_COSTUME_HEAD_LOW   = 0x001000, //4096
	IT_EQPM_COSTUME_GARMENT    = 0x002000, //8192
	//UNUSED_COSTUME_FLOOR = 0x004000, //16384
	IT_EQPM_AMMO               = 0x008000, //32768
	IT_EQPM_SHADOW_ARMOR       = 0x010000, //65536
	IT_EQPM_SHADOW_WEAPON      = 0x020000, //131072
	IT_EQPM_SHADOW_SHIELD      = 0x040000, //262144
	IT_EQPM_SHADOW_SHOES       = 0x080000, //524288
	IT_EQPM_SHADOW_ACC_R       = 0x100000, //1048576
	IT_EQPM_SHADOW_ACC_L       = 0x200000, //2097152

	// Composites
	IT_EQPM_WEAPON             = IT_EQPM_HAND_R,
	IT_EQPM_SHIELD             = IT_EQPM_HAND_L,
	IT_EQPM_ARMS               = IT_EQPM_HAND_R | IT_EQPM_HAND_L,
	IT_EQPM_HELM               = IT_EQPM_HEAD_LOW | IT_EQPM_HEAD_MID | IT_EQPM_HEAD_TOP,
	IT_EQPM_ACC                = IT_EQPM_ACC_L | IT_EQPM_ACC_R,
	IT_EQPM_COSTUME            = IT_EQPM_COSTUME_HEAD_TOP | IT_EQPM_COSTUME_HEAD_MID | IT_EQPM_COSTUME_HEAD_LOW | IT_EQPM_COSTUME_GARMENT,
	IT_EQPM_SHADOW_ACC         = IT_EQPM_SHADOW_ACC_R | IT_EQPM_SHADOW_ACC_L,
	IT_EQPM_SHADOW_ARMS        = IT_EQPM_SHADOW_WEAPON | IT_EQPM_SHADOW_SHIELD
};

enum item_equip_location_index
{
	IT_EQPI_ACC_L            = 0,
	IT_EQPI_ACC_R            = 1,
	IT_EQPI_SHOES            = 2,
	IT_EQPI_GARMENT          = 3,
	IT_EQPI_HEAD_LOW         = 4,
	IT_EQPI_HEAD_MID         = 5,
	IT_EQPI_HEAD_TOP         = 6,
	IT_EQPI_ARMOR            = 7,
	IT_EQPI_HAND_L           = 8,
	IT_EQPI_HAND_R           = 9,
	IT_EQPI_COSTUME_TOP      = 10,
	IT_EQPI_COSTUME_MID      = 11,
	IT_EQPI_COSTUME_LOW      = 12,
	IT_EQPI_COSTUME_GARMENT  = 13,
	IT_EQPI_AMMO             = 14,
	IT_EQPI_SHADOW_ARMOR     = 15,
	IT_EQPI_SHADOW_WEAPON    = 16,
	IT_EQPI_SHADOW_SHIELD    = 17,
	IT_EQPI_SHADOW_SHOES     = 18,
	IT_EQPI_SHADOW_ACC_R     = 19,
	IT_EQPI_SHADOW_ACC_L     = 20,
	IT_EQPI_MAX
};

enum item_transaction_mask
{
	ITRMASK_NONE               = 0x0000, ///< No restrictions
	ITRMASK_DROP               = 0x0001, ///< Item can be dropped
	ITRMASK_TRADE              = 0x0002, ///< Item can be traded (nor vended)
	ITRMASK_TRADEWPARTNER      = 0x0004, ///< Wedded partner can override ITR_NOTRADE restriction
	ITRMASK_SELL_TO_NPC        = 0x0008, ///< Item can be sold to NPCs
	ITRMASK_CART               = 0x0010, ///< Item can be placed in the cart
	ITRMASK_STORAGE            = 0x0020, ///< Item can be placed in the storage
	ITRMASK_GSTORAGE           = 0x0040, ///< Item can be placed in the guild storage
	ITRMASK_MAIL               = 0x0080, ///< Item can be attached to mail messages
	ITRMASK_AUCTION            = 0x0100, ///< Item can be auctioned
	ITRMASK_BUYING_STORE       = 0x0200, ///< Item can be listed in the buying store.
	ITRMASK_ALL                = 0x03ff  ///< Sum of all the above values
};

enum item_usage_restriction_mask
{
	IURMASK_NONE    = 0x0, ///< No restrictions
	IURMASK_SITTING = 0x1, ///< Item can't be used while sitting
	IURMASK_ALL     = 0x1  ///< Sum of all the above values
};

enum item_type : uint8_t
{
	IT_TYPE_HEALING              = 0,
	IT_TYPE_UNKNOWN              = 1,
	IT_TYPE_USABLE               = 2,
	IT_TYPE_ETC                  = 3,
	IT_TYPE_WEAPON               = 4,
	IT_TYPE_ARMOR                = 5,
	IT_TYPE_CARD                 = 6,
	IT_TYPE_PET_EGG              = 7,
	IT_TYPE_PET_ARMOR            = 8,
	IT_TYPE_UNKNOWN2             = 9,
	IT_TYPE_AMMO                 = 10,
	IT_TYPE_CONSUMPTION_DELAY    = 11,
	IT_TYPE_CASH                 = 18,
	IT_TYPE_MAX
};

enum item_ammunition_type
{
	IT_AT_NONE               = 0,
	IT_AT_ARROW              = 1,
	IT_AT_DAGGER             = 2,
	IT_AT_BULLET             = 3,
	IT_AT_SHELL              = 4,
	IT_AT_GRENADE            = 5,
	IT_AT_SHURIKEN           = 6,
	IT_AT_KUNAI              = 7,
	IT_AT_CANNONBALL         = 8,
	IT_AT_THROWABLE_ITEM     = 9,
	IT_AT_MAX
};

enum item_bind_type : uint16_t
{
	IT_BIND_NONE      = 0x0,
	IT_BIND_MIN       = 0x1,
	IT_BIND_ACCOUNT   = 0x1,
	IT_BIND_GUILD     = 0x2,
	IT_BIND_PARTY     = 0x3,
	IT_BIND_CHARACTER = 0x4,
	IT_BIND_MAX       = 0x4,
};

enum item_inventory_addition_notif_type : uint8_t
{
	ITEM_INV_ADD_SUCCESS, // * 0 = success
	ITEM_INV_ADD_INVALID, // * 1 = invalid itemid not found or negative amount
	ITEM_INV_ADD_OVER_WEIGHT, // * 2 = overweight
	ITEM_INV_ADD_UNKNOWN, // * 3 = ?
	ITEM_INV_ADD_NO_INV_SPACE, // * 4 = no free place found
	ITEM_INV_ADD_OVER_QUANTITY, // * 5 = max amount reached
	ITEM_INV_ADD_UNKNOWN2, // * 6 = ?
	ITEM_INV_ADD_OVER_STACK_LIMIT, // * 7 = stack limitation
};

enum item_deletion_reason_type : uint16_t
{
	ITEM_DEL_NORMAL         = 0, /// Normal
	ITEM_DEL_SKILLUSE       = 1, /// Item used for a skill
	ITEM_DEL_FAILREFINE     = 2, /// Refine failed
	ITEM_DEL_MATERIALCHANGE = 3, /// Material changed
	ITEM_DEL_TOSTORAGE      = 4, /// Moved to storage
	ITEM_DEL_TOCART         = 5, /// Moved to cart
	ITEM_DEL_SOLD           = 6, /// Item sold
	ITEM_DEL_ANALYSIS       = 7, /// Consumed by Four Spirit Analysis (SO_EL_ANALYSIS) skill
};

enum item_equip_result_type
{
	IT_EQUIP_SUCCESS = 0x0,
	IT_EQUIP_FAIL_LV = 0x1,
	IT_EQUIP_FAIL    = 0x2,
};

enum item_unequip_result_type
{
	IT_UNEQUIP_SUCCESS = 0x0,
	IT_UNEQUIP_FAIL    = 0x1,
};

struct item_config_data
{
	uint32_t item_id;
	std::string name{""}, key_name{""};

	int32_t value_buy{0};
	int32_t value_sell{0};

	item_type type{IT_TYPE_ETC};

	union {
		item_weapon_type weapon_t;
		item_ammunition_type ammo_t;
	} sub_type{IT_WT_FIST};

	uint64_t equip_location_mask{0};      ///< @see equip_location_mask type.
	uint32_t weight{0};
	int32_t attack{0};
	int32_t defense{0};
	int8_t attack_range{0};
	int8_t card_slot_count{0};
	uint32_t sprite_id{0};

	union {
		int8_t armor;
		int8_t weapon;
	} level{0};

	int32_t magic_atk{0};
	struct {
		int32_t max_lv{0};
		int32_t min_lv{0};
		std::vector<uint32_t> job_ids;
		item_gender_type gender{IT_GENDER_ANY};
	} requirements;

	int drop_effect_mode{0};

	int delay{0};

	std::string default_script{""}; ///< Default script for everything.
	std::string equip_script{""};   ///< Script executed once when equipping.
	std::string unequip_script{""}; ///< Script executed once when unequipping.

	struct {
		unsigned available : 1;
		unsigned refineable : 1;
		unsigned consumption_delay : 1;         ///< Signifies items that are not consumed immediately upon double-click
		unsigned bind_on_equip : 1;
		unsigned force_serial : 1;
		unsigned keep_after_use : 1;
		unsigned allow_item_options: 1;            ///< disallows use of item options on the item. (non-equippable items are automatically flagged)
		unsigned drop_announce : 1;             ///< Official Drop Announce
		unsigned show_drop_effect : 1;          ///< Shows Drop Effect.
		unsigned trade_restriction_mask : 8;         ///< Item trade restrictions mask (@see enum item_trade_restriction_mask)
	} config;
	
	struct {
		unsigned int inventory{0};
		unsigned int cart{0};
		unsigned int storage{0};
		unsigned int guild_storage{0};
	} stack;

	int usage_restriction_mask{0}, usage_restriction_group_override_id{0};

	int trade_restriction_mask{0}, trade_restriction_group_override_id{0};
	bool trade_restriction_partner_override{0};
};

/**
 * Structure used to store and convey item data in the state machine
 * and in communication with the client.
 */
struct item_entry_data
{
	bool is_equipment() { return type == IT_TYPE_WEAPON || type == IT_TYPE_ARMOR; }

	bool is_stackable()
	{
		if (type == IT_TYPE_WEAPON || type == IT_TYPE_ARMOR
			|| type == IT_TYPE_PET_EGG || type == IT_TYPE_PET_ARMOR
			|| hire_expire_date > 0
			)
			return false;
		return true;
	}

	bool operator == (item_entry_data const &right)
	{
		if (item_id != right.item_id
			|| bind_type != right.bind_type
			|| hire_expire_date != right.hire_expire_date
			|| unique_id != right.unique_id
			|| type != right.type
			|| info.is_favorite != right.info.is_favorite
			)
			return false;

		return true;
	}

	uint8_t get_refine_level() { return refine_level; }
	void set_refine_level(int lvl) { refine_level = lvl; }

	uint32_t get_hire_expire_date() { return hire_expire_date; }
	void set_hire_expire_date(int date) { hire_expire_date = date; }

	item_bind_type get_bind_type() { return bind_type; }
	void set_bind_type(item_bind_type val) { bind_type = val; }

	uint8_t get_option_count() { return option_count; }
	void set_option_count(uint8_t count) { option_count = count; }

	uint16_t get_sprite_id() { return sprite_id; }

	uint16_t inventory_index{0};
	uint32_t item_id{0};
	item_type type{IT_TYPE_ETC};
	uint16_t amount{0};
	uint32_t current_equip_location_mask{0};
	uint32_t actual_equip_location_mask{0};
	uint8_t refine_level{0};
	uint32_t slot_item_id[MAX_ITEM_SLOTS]{0};
	uint32_t hire_expire_date{0};
	uint16_t sprite_id{0};

	element_type ele_type{ELE_NEUTRAL};
	uint8_t option_count{0};
	struct options {
		int16_t get_index() const { return index; }
		void set_index(int idx) { index = idx; }

		int16_t get_value() const { return value; }
		void set_value(int val) { value = val; }

		int16_t index{0};
		int16_t value{0};
		uint8_t param{0};
	} option_data[MAX_ITEM_OPTIONS];
	struct item_entry_info {
		item_entry_info () { memset(this, 0, sizeof(*this)); }
		unsigned is_identified : 1;
		unsigned is_broken : 1;
		unsigned is_favorite : 1;
		unsigned spare_bits : 5;
	} info;
	item_bind_type bind_type{IT_BIND_NONE}; // int16_t
	uint64_t unique_id{0};
	// Item configuration data.
	std::shared_ptr<const item_config_data> config;
};

typedef std::array<std::pair<item_equip_location_mask, std::weak_ptr<item_entry_data>>, IT_EQPI_MAX> EquipmentListType;

struct item_slot {
#if ((CLIENT_TYPE == 'M' && PACKET_VERSION >= 20181121) || \
	(CLIENT_TYPE == 'R' && PACKET_VERSION >= 20180704) || \
	(CLIENT_TYPE == 'Z' && PACKET_VERSION >= 20181114))
	uint32 item_id[4];
#else
	uint16 item_id[4];
#endif
};
#endif /* HORIZON_ZONE_ITEM_DEFINITIONS */
