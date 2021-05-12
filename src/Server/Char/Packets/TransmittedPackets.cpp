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


#include "TransmittedPackets.hpp"
#include "Server/Char/Session/CharSession.hpp"
#include "Server/Char/Interface/CharClientInterface.hpp"
#include "Server/Common/Configuration/Horizon.hpp"
#include "Server/Common/SQL/Character/Character.hpp"
#include "Server/Common/SQL/Character/Status.hpp"
#include "Server/Char/Char.hpp"

#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/functions.h>

using namespace Horizon::Char;

/**
 * HC_ACCOUNT_ID
 */
void HC_ACCOUNT_ID::deliver(int32_t account_id)
{
	_account_id = account_id;
	serialize();
	transmit();
}

ByteBuffer &HC_ACCOUNT_ID::serialize()
{
	buf() << _account_id;
	return buf();
}

/**
 * HC_ACCEPT_MAKECHAR
 */
void HC_ACCEPT_MAKECHAR::deliver(uint32_t char_id, uint32_t start_zeny, std::string map_name, std::string name, uint8_t slot, uint32_t hair_color, uint32_t hair_style, uint32_t job_class, uint8_t gender)
{
	_c._character_id = char_id;
	_c._zeny = start_zeny;
	_c._status_points = 48;
	_c._hp = 40;
	_c._maximum_hp = 40;
	_c._sp = 40;
	_c._maximum_sp = 40;
	_c._walk_speed = DEFAULT_MOVEMENT_SPEED;
	_c._job_id = job_class;
	_c._hair_view_id = hair_style;
	strncpy(_c._name, name.c_str(), MAX_UNIT_NAME_LENGTH);
	_c._char_slot = slot;
#if (PACKET_VERSION >= 20100720 && PACKET_VERSION <= 20100727) || PACKET_VERSION >= 20100803
	strncpy(_c._map_name, map_name.c_str(), MAP_NAME_LENGTH_EXT);///< len: 16
#endif
#if PACKET_VERSION >= 20141016
	_c._gender = gender;                   ///< 146 0: Female, 1: Male, 99: Account-based.
#endif

	serialize();
	transmit();
}

ByteBuffer &HC_ACCEPT_MAKECHAR::serialize()
{
	buf() << _packet_id;
	buf().append((uint8_t *) &_c, sizeof(s_hc_character_list_data));
	return buf();
}

/**
 * HC_SECOND_PASSWD_LOGIN
 */
void HC_SECOND_PASSWD_LOGIN::deliver(hc_pincode_state_type state)
{
	_pincode_seed = rand() % 0xFFFF;
	get_session()->get_session_data()._pincode_seed = _pincode_seed;
	
	_account_id = get_session()->get_session_data()._account_id;
	_state = state;
	
	serialize();
	transmit();
}

#if CLIENT_TYPE == 'M' && PACKET_VERSION >= 20180124 \
|| CLIENT_TYPE == 'R' && PACKET_VERSION >= 20180124 \
|| CLIENT_TYPE == 'Z' && PACKET_VERSION >= 20180131
void HC_SECOND_PASSWD_LOGIN::deliver(hc_pincode_state_type state, hc_pincode_login_response2 state2)
{
	_state2 = state2;
	deliver(state);
}
#endif

ByteBuffer &HC_SECOND_PASSWD_LOGIN::serialize()
{
	buf() << _packet_id;
	buf() << _pincode_seed;
	buf() << _account_id;
	buf() << ((short) _state);
#if CLIENT_TYPE == 'M' && PACKET_VERSION >= 20180124 \
|| CLIENT_TYPE == 'R' && PACKET_VERSION >= 20180124 \
|| CLIENT_TYPE == 'Z' && PACKET_VERSION >= 20180131
	buf() << (uint8_t) _state2;
#endif
	
	return buf();
}


/**
 * HC_DELETE_CHAR3_RESERVED
 */
void HC_DELETE_CHAR3_RESERVED::deliver(uint32_t char_id, character_delete_result res, uint32_t date)
{
	_character_id = char_id;
	_result = res;
	_deletion_date = date;
	
	serialize();
	transmit();
}

ByteBuffer &HC_DELETE_CHAR3_RESERVED::serialize()
{
	buf() << _packet_id;
	buf() << _character_id;
	buf() << _result;
	buf() << _deletion_date;
	
	return buf();
}

/**
 * HC_REQUEST_CHARACTER_PASSWORD
 */
void HC_REQUEST_CHARACTER_PASSWORD::deliver() { }

ByteBuffer &HC_REQUEST_CHARACTER_PASSWORD::serialize()
{
	return buf();
}

/**
 * HC_MAKE_SECOND_PASSWD
 */
void HC_MAKE_SECOND_PASSWD::deliver(pincode_make_response state)
{
	_state = state;
	_seed = get_session()->get_session_data()._pincode_seed;
	
	serialize();
	transmit();
}

ByteBuffer &HC_MAKE_SECOND_PASSWD::serialize()
{
	buf() << _packet_id;
	buf() << (short) _state;
	buf() << _seed;
	
	return buf();
}

/**
 * HC_CHARLIST_NOTIFY
 */
void HC_CHARLIST_NOTIFY::deliver() { }

ByteBuffer &HC_CHARLIST_NOTIFY::serialize()
{
	return buf();
}

/**
 * HC_BLOCK_CHARACTER
 */
void HC_BLOCK_CHARACTER::deliver() { }

ByteBuffer &HC_BLOCK_CHARACTER::serialize()
{
	return buf();
}

/**
 * HC_NOTIFY_ACCESSIBLE_MAPNAME
 */
void HC_NOTIFY_ACCESSIBLE_MAPNAME::deliver() { }

ByteBuffer &HC_NOTIFY_ACCESSIBLE_MAPNAME::serialize()
{
	return buf();
}

/**
 * HC_REFUSE_MAKECHAR
 */
void HC_REFUSE_MAKECHAR::deliver(hc_char_create_error_type error)
{
	_error = error;
	
	serialize();
	transmit();
}

ByteBuffer &HC_REFUSE_MAKECHAR::serialize()
{
	buf() << _packet_id;
	buf() << (uint8_t) _error;
	return buf();
}

/**
 * HC_ACK_IS_VALID_CHARNAME
 */
void HC_ACK_IS_VALID_CHARNAME::deliver() { }

ByteBuffer &HC_ACK_IS_VALID_CHARNAME::serialize()
{
	return buf();
}

/**
 * HC_DELETE_SECOND_PASSWD
 */
void HC_DELETE_SECOND_PASSWD::deliver() { }

ByteBuffer &HC_DELETE_SECOND_PASSWD::serialize()
{
	return buf();
}

/**
 * HC_REFUSE_SELECTCHAR
 */
void HC_REFUSE_SELECTCHAR::deliver() { }

ByteBuffer &HC_REFUSE_SELECTCHAR::serialize()
{
	return buf();
}

/**
 * HC_UPDATE_CHARINFO
 */
void HC_UPDATE_CHARINFO::deliver() { }

ByteBuffer &HC_UPDATE_CHARINFO::serialize()
{
	return buf();
}

/**
 * HC_ACCEPT_ENTER2
 */
void HC_ACCEPT_ENTER2::deliver(uint8_t total_slots, uint8_t premium_slots)
{
	serialize(total_slots, premium_slots);
	transmit();
}

ByteBuffer &HC_ACCEPT_ENTER2::serialize(uint8_t total_slots, uint8_t premium_slots)
{
	_total_slots = total_slots;
	_premium_slots = premium_slots;
	
	buf() << _packet_id;
	buf() << _packet_length;
	buf() << _total_slots;
	buf() << _premium_slots;
	buf() << _unknown_byte;
	buf() << _char_slots_1;
	buf() << _char_slots_2;
	buf().append(_unknown_bytes, sizeof(_unknown_bytes));
	
	return buf();
}

/**
 * HC_SECRETSCAN_DATA
 */
void HC_SECRETSCAN_DATA::deliver() { }

ByteBuffer &HC_SECRETSCAN_DATA::serialize()
{
	return buf();
}

/**
 * HC_CHARNOTBEENSELECTED
 */
void HC_CHARNOTBEENSELECTED::deliver() { }

ByteBuffer &HC_CHARNOTBEENSELECTED::serialize()
{
	return buf();
}

/**
 * HC_ACK_CHANGE_CHARNAME
 */
void HC_ACK_CHANGE_CHARNAME::deliver() { }

ByteBuffer &HC_ACK_CHANGE_CHARNAME::serialize()
{
	return buf();
}

/**
 * HC_ACCEPT_ENTER
 */

bool HC_ACCEPT_ENTER::prepare_and_deliver(uint32_t account_id, uint8_t max_char_slots, uint8_t permitted_slots, uint8_t total_premium_slots)
{
	SQL::TableCharacters tch;
	SQL::TableCharacterStatus tcs;

	std::shared_ptr<sqlpp::mysql::connection> conn = sChar->get_db_connection();

	auto cres = (*conn)(select(all_of(tch).as(sqlpp::alias::left), all_of(tcs).as(sqlpp::alias::right)).from(tch.join(tcs).on(tch.id == tcs.id)).where(tch.account_id == account_id));

#if PACKET_VERSION >= 20100413
	_max_char_slots = max_char_slots;
	_permitted_slots = permitted_slots;
	_total_premium_slots = total_premium_slots;
#endif

	_packet_length = 0;
	std::vector<s_hc_character_list_data> vc;
	for (auto i = cres.begin(); i != cres.end(); i++)
	{
		s_hc_character_list_data c;
		
		c._character_id = i->right.id;          ///< 0
		c._base_experience = i->right.base_experience;
		c._zeny = i->right.zeny;                    ///< 8
		c._job_experience = i->right.job_experience;
		c._job_level = i->right.job_level;               ///< 16
		c._sc_opt1 = 0;                 ///< 20 Probably OPT1 / 2
		c._sc_opt2 = 0;                 ///< 24
		c._body_state = i->right.body_state;              ///< 28
		c._virtue = i->right.virtue;                  ///< 32
		c._honor = i->right.honor;                   ///< 36
		c._status_points = i->right.status_points;           ///< 40
		c._hp = i->right.hp;                      ///< 42
		c._maximum_hp = i->right.maximum_hp;              ///< 46
		c._sp = i->right.sp;                      ///< 50
		c._maximum_sp = i->right.maximum_sp;              ///< 52
		c._walk_speed = DEFAULT_MOVEMENT_SPEED;              ///< 54
		c._job_id = i->right.job_id;                  ///< 56
		c._hair_view_id = i->right.hair_style_id;            ///< 58
#if PACKET_VERSION >= 20141022
		c._body_view_id = i->right.body_id;            ///< 60 p->body in hercules.
#endif
		c._weapon_view_id = i->right.weapon_id;          ///< 62 OPTION_* in hercules.
		c._base_level = i->right.base_level;              ///< 64
		c._skill_point = i->right.skill_points;             ///< 66
		c._head_bottom_view_id = i->right.head_bottom_view_id;     ///< 68
		c._shield_id = i->right.shield_id;               ///< 70
		c._head_top_view_id = i->right.head_top_view_id;        ///< 72
		c._head_mid_view_id = i->right.head_mid_view_id;        ///< 74
		c._hair_color_id = i->right.hair_color_id;           ///< 76
		c._clothes_color_id = i->right.cloth_color_id;        ///< 78
		
		std::string lname =i->left.name;
		strncpy(c._name,  lname.c_str(), MAX_UNIT_NAME_LENGTH);  ///< 80
		
		c._strength = i->right.strength;                 ///< 104
		c._agility = i->right.agility;
		c._vitality = i->right.vitality;
		c._intelligence = i->right.intelligence;
		c._dexterity = i->right.dexterity;
		c._luck = i->right.luck;
		c._char_slot = i->left.slot;               ///< 110
#if PACKET_VERSION >= 20061023
		c._rename_count = i->left.rename_count ? 0 : 1;            ///< 112
#endif
#if (PACKET_VERSION >= 20100720 && PACKET_VERSION <= 20100727) || PACKET_VERSION >= 20100803
		std::string current_map = i->left.current_map;
		strncpy(c._map_name,  current_map.c_str(), MAP_NAME_LENGTH_EXT);///< 114
#endif
#if PACKET_VERSION >= 20100803
		std::chrono::system_clock::time_point tp{ i->left.deleted_at.value() };             ///< 130
		std::chrono::system_clock::duration dn = tp.time_since_epoch();
		c._deleted_at = dn.count() * std::chrono::system_clock::period::num / std::chrono::system_clock::period::den;
#endif
#if PACKET_VERSION >= 20110111
		c._robe_view_id = i->right.robe_view_id;            ///< 134
#endif
#if PACKET_VERSION != 20111116 //2011-11-16 wants 136, ask gravity.
#if PACKET_VERSION >= 20110928
		c._change_slot_count = i->left.change_slot_count ? 1 : 0;       ///< 138
#endif
#if PACKET_VERSION >= 20111025
		c._addon_option = i->left.rename_count ? 1 : 0;            ///< 142 1: Displays "Addon" on side-bar.
#endif
#if PACKET_VERSION >= 20141016
		c._gender = i->left.gender == "M" ? 1 : i->left.gender == "F" ? 0 : 99;                   ///< 146 0: Female, 1: Male, 99: Account-based.
#endif
#endif
		_packet_length += sizeof(c);
		vc.push_back(c);
	}

#if PACKET_VERSION >= 20100413
	_packet_length += 27;
#else
	_packet_length += 24;
#endif

	buf() << _packet_id;
	buf() << _packet_length;

#if PACKET_VERSION >= 20100413
	buf() << _max_char_slots;
	buf() << _permitted_slots;
	buf() << _total_premium_slots;
#endif

	buf().append(_unknown_bytes, sizeof(_unknown_bytes));

	for (s_hc_character_list_data c : vc)
		buf().append((uint8_t *) &c, sizeof(s_hc_character_list_data));
	
	HLog(debug) << "Sending character list data size: " << sizeof(s_hc_character_list_data);
	
	deliver();

	return true;
}

void HC_ACCEPT_ENTER::deliver()
{
	transmit();
}

ByteBuffer &HC_ACCEPT_ENTER::serialize()
{
	return buf();
}

/**
 * HC_WAITING_LOGIN
 */
void HC_WAITING_LOGIN::deliver() { }

ByteBuffer &HC_WAITING_LOGIN::serialize()
{
	return buf();
}

/**
 * HC_SECOND_PASSWD_REQ
 */
void HC_SECOND_PASSWD_REQ::deliver() { }

ByteBuffer &HC_SECOND_PASSWD_REQ::serialize()
{
	return buf();
}

/**
 * HC_DELETE_CHAR3_CANCEL
 */
void HC_DELETE_CHAR3_CANCEL::deliver(uint32_t char_id, hc_delete_cancel_result result)
{
	_character_id = char_id;
	_result = result;

	serialize();
	transmit();
}

ByteBuffer &HC_DELETE_CHAR3_CANCEL::serialize()
{
	buf() << _packet_id;
	buf() << _character_id;
	buf() << (int) _result;
	return buf();
}

/**
 * HC_CHARACTER_LIST
 */
void HC_CHARACTER_LIST::deliver() { }

ByteBuffer &HC_CHARACTER_LIST::serialize()
{
	return buf();
}

/**
 * HC_ACCEPT_DELETECHAR
 */
void HC_ACCEPT_DELETECHAR::deliver()
{
	transmit();
}

ByteBuffer &HC_ACCEPT_DELETECHAR::serialize()
{
	buf() << _packet_id;
	return _buffer;
}

/**
 * HC_ACK_CHARINFO_PER_PAGE
 */

void HC_ACK_CHARINFO_PER_PAGE::prepare_and_deliver()
{
	SQL::TableCharacters tch;
	SQL::TableCharacterStatus tcs;
	
	std::shared_ptr<sqlpp::mysql::connection> conn = sChar->get_db_connection();
	
	auto cres = (*conn)(select(all_of(tch).as(sqlpp::alias::left), all_of(tcs).as(sqlpp::alias::right)).from(tch.join(tcs).on(tch.id == tcs.id)).where(tch.account_id == get_session()->get_session_data()._account_id));
	
	_packet_length = 4;
	std::vector<s_hc_character_list_data> vc;
	for (auto i = cres.begin(); i != cres.end(); i++)
	{
		s_hc_character_list_data c;
		
		c._character_id = i->right.id;          ///< 0
		c._base_experience = i->right.base_experience;
		c._zeny = i->right.zeny;                    ///< 8
		c._job_experience = i->right.job_experience;
		c._job_level = i->right.job_level;               ///< 16
		c._sc_opt1 = 0;                 ///< 20 Probably OPT1 / 2
		c._sc_opt2 = 0;                 ///< 24
		c._body_state = i->right.body_state;              ///< 28
		c._virtue = i->right.virtue;                  ///< 32
		c._honor = i->right.honor;                   ///< 36
		c._status_points = i->right.status_points;           ///< 40
		c._hp = i->right.hp;                      ///< 42
		c._maximum_hp = i->right.maximum_hp;              ///< 46
		c._sp = i->right.sp;                      ///< 50
		c._maximum_sp = i->right.maximum_sp;              ///< 52
		c._walk_speed = DEFAULT_MOVEMENT_SPEED;              ///< 54
		c._job_id = i->right.job_id;                  ///< 56
		c._hair_view_id = i->right.hair_style_id;            ///< 58
#if PACKET_VERSION >= 20141022
		c._body_view_id = i->right.body_id;            ///< 60 p->body in hercules.
#endif
		c._weapon_view_id = i->right.weapon_id;          ///< 62 OPTION_* in hercules.
		c._base_level = i->right.base_level;              ///< 64
		c._skill_point = i->right.skill_points;             ///< 66
		c._head_bottom_view_id = i->right.head_bottom_view_id;     ///< 68
		c._shield_id = i->right.shield_id;               ///< 70
		c._head_top_view_id = i->right.head_top_view_id;        ///< 72
		c._head_mid_view_id = i->right.head_mid_view_id;        ///< 74
		c._hair_color_id = i->right.hair_color_id;           ///< 76
		c._clothes_color_id = i->right.cloth_color_id;        ///< 78
		
		std::string lname =i->left.name;
		strncpy(c._name,  lname.c_str(), MAX_UNIT_NAME_LENGTH);  ///< 80
		
		c._strength = i->right.strength;                 ///< 104
		c._agility = i->right.agility;
		c._vitality = i->right.vitality;
		c._intelligence = i->right.intelligence;
		c._dexterity = i->right.dexterity;
		c._luck = i->right.luck;
		c._char_slot = i->left.slot;               ///< 110
#if PACKET_VERSION >= 20061023
		c._rename_count = i->left.rename_count ? 0 : 1;            ///< 112
#endif
#if (PACKET_VERSION >= 20100720 && PACKET_VERSION <= 20100727) || PACKET_VERSION >= 20100803
		std::string current_map = i->left.current_map;
		strncpy(c._map_name,  current_map.c_str(), MAP_NAME_LENGTH_EXT);///< 114
#endif
#if PACKET_VERSION >= 20100803
		std::chrono::system_clock::time_point tp{ i->left.deleted_at.value() };             ///< 130
		std::chrono::system_clock::duration dn = tp.time_since_epoch();
		c._deleted_at = dn.count() * std::chrono::system_clock::period::num / std::chrono::system_clock::period::den;
#endif
#if PACKET_VERSION >= 20110111
		c._robe_view_id = i->right.robe_view_id;            ///< 134
#endif
#if PACKET_VERSION != 20111116 //2011-11-16 wants 136, ask gravity.
#if PACKET_VERSION >= 20110928
		c._change_slot_count = i->left.change_slot_count ? 1 : 0;       ///< 138
#endif
#if PACKET_VERSION >= 20111025
		c._addon_option = i->left.rename_count ? 1 : 0;            ///< 142 1: Displays "Addon" on side-bar.
#endif
#if PACKET_VERSION >= 20141016
		c._gender = i->left.gender == "M" ? 1 : i->left.gender == "F" ? 0 : 99;                   ///< 146 0: Female, 1: Male, 99: Account-based.
#endif
#endif
		_packet_length += sizeof(c);
		vc.push_back(c);
	}
	
	buf() << _packet_id;
	buf() << _packet_length;
	
	for (s_hc_character_list_data c : vc)
		buf().append((uint8_t *) &c, sizeof(s_hc_character_list_data));
	
	HLog(debug) << "Sending character list data size: " << sizeof(s_hc_character_list_data);
	
	deliver();
}

void HC_ACK_CHARINFO_PER_PAGE::deliver() { transmit(); }

ByteBuffer &HC_ACK_CHARINFO_PER_PAGE::serialize()
{
	return buf();
}

/**
 * HC_QUEUE_ORDER
 */
void HC_QUEUE_ORDER::deliver() { }

ByteBuffer &HC_QUEUE_ORDER::serialize()
{
	return buf();
}

/**
 * HC_CHECKBOT_RESULT
 */
void HC_CHECKBOT_RESULT::deliver() { }

ByteBuffer &HC_CHECKBOT_RESULT::serialize()
{
	return buf();
}

/**
 * HC_REFUSE_ENTER
 */
void HC_REFUSE_ENTER::deliver(hc_char_connect_error_type error)
{
	_error = error;
	
	serialize();
	transmit();
}

ByteBuffer &HC_REFUSE_ENTER::serialize()
{
	buf() << _packet_id;
	buf() << ((uint8_t) _error);
	return buf();
}

/**
 * HC_EDIT_SECOND_PASSWD
 */
void HC_EDIT_SECOND_PASSWD::deliver(pincode_edit_response state)
{
	_seed = rand() % 0xFFFF;
	
	_state = state;
	
	get_session()->get_session_data()._pincode_seed = _seed;
	
	serialize();
	transmit();
}

ByteBuffer &HC_EDIT_SECOND_PASSWD::serialize()
{
	buf() << _packet_id;
	buf() << (short) _state;
	buf() << _seed;
	return buf();
}

/**
 * HC_NOTIFY_ZONESVR
 */
void HC_NOTIFY_ZONESVR::deliver(uint32_t char_id, std::string map_name, uint32_t ip_address, uint16_t port)
{
	_char_id = char_id;
	strncpy(_map_name, map_name.c_str(), MAP_NAME_LENGTH_EXT);
	_ip_address = ip_address;
	_port = port;
	
	serialize();
	transmit();
}

ByteBuffer &HC_NOTIFY_ZONESVR::serialize()
{
	buf() << _packet_id;
	buf() << _char_id;
	buf().append(_map_name, sizeof(_map_name));
	buf() << _ip_address;
	buf() << _port;
	return buf();
}

/**
 * HC_REFUSE_DELETECHAR
 */
void HC_REFUSE_DELETECHAR::deliver() 
{
	serialize();
	transmit();
}

ByteBuffer &HC_REFUSE_DELETECHAR::serialize()
{
	buf() << _packet_id;
	buf() << _error;
	return buf(); 
}

/**
 * HC_ACK_CHANGE_CHARACTER_SLOT
 */
void HC_ACK_CHANGE_CHARACTER_SLOT::deliver() { }

ByteBuffer &HC_ACK_CHANGE_CHARACTER_SLOT::serialize()
{
	return buf();
}

/**
 * HC_CHECKBOT
 */
void HC_CHECKBOT::deliver() { }

ByteBuffer &HC_CHECKBOT::serialize()
{
	return buf();
}

/**
 * HC_AVAILABLE_SECOND_PASSWD
 */
void HC_AVAILABLE_SECOND_PASSWD::deliver() { }

ByteBuffer &HC_AVAILABLE_SECOND_PASSWD::serialize()
{
	return buf();
}

/**
 * HC_DELETE_CHAR3
 */
void HC_DELETE_CHAR3::deliver(uint32_t char_id, character_delete_accept_result result)
{	
	_character_id = char_id;
	_result = result;
	
	serialize();
	transmit();
}

ByteBuffer &HC_DELETE_CHAR3::serialize()
{
	buf() << _packet_id;
	buf() << _character_id;
	buf() << _result;
	return buf();
}

/**
 * HC_NOT_AVAILABLE_SECOND_PASSWD
 */
void HC_NOT_AVAILABLE_SECOND_PASSWD::deliver() { }

ByteBuffer &HC_NOT_AVAILABLE_SECOND_PASSWD::serialize()
{
	return buf();
}

