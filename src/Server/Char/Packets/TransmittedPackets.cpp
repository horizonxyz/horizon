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
#include "Server/Char/Char.hpp"

#include <mysqlx/xdevapi.h>

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
bool HC_ACCEPT_ENTER::prepare(uint32_t account_id, uint8_t max_char_slots, uint8_t permitted_slots, uint8_t total_premium_slots)
{
	mysqlx::RowResult rr;
	
	try {
		rr = sChar->get_db_connection()->sql("SELECT "
			"a.`id`, a.`account_id`, a.`slot`, a.`name`, a.`online`, a.`gender`, a.`delete_reserved_at`, a.`deleted_at`, a.`unban_time`, " // 0 - 8
			"a.`rename_count`, a.`last_unique_id`, a.`hotkey_row_index`, a.`change_slot_count`, a.`font`, a.`show_equip`, a.`allow_party`, " // 9 - 15
			"a.`partner_aid`, a.`father_aid`, a.`mother_aid`, a.`child_aid`, a.`party_id`, a.`guild_id`, a.`pet_id`, a.`homun_id`, " // 16 - 23
			"a.`elemental_id`, a.`current_map`, a.`current_x`, a.`current_y`, a.`saved_map`, a.`saved_x`, a.`saved_y`, " // 24 - 30
			"b.`job_id`, b.`base_level`, b.`job_level`, b.`base_experience`, b.`job_experience`, b.`zeny`, b.`strength`, " // 31 - 37
			"b.`agility`, b.`vitality`, b.`intelligence`, b.`dexterity`, b.`luck`, b.`maximum_hp`, b.`hp`, b.`maximum_sp`, " // 38 - 45
			"b.`sp`, b.`status_points`, b.`skill_points`, b.`body_state`, b.`virtue`, b.`honor`, b.`manner`, b.`hair_style_id`, " // 46 - 53
			"b.`hair_color_id`, b.`cloth_color_id`, b.`body_id`, b.`weapon_view_id`, b.`shield_view_id`, b.`head_top_view_id`, b.`head_mid_view_id`, " // 54 - 60
			"b.`head_bottom_view_id`, b.`robe_view_id` " // 61 - 62
			"FROM `characters` as a LEFT JOIN `character_status` as b ON a.id = b.id WHERE a.account_id = ? AND a.deleted_at = ?")
			.bind(account_id, 0)
			.execute();

	std::list<mysqlx::Row> rs = rr.fetchAll();

#if PACKET_VERSION >= 20100413
	_max_char_slots = max_char_slots;
	_permitted_slots = permitted_slots;
	_total_premium_slots = total_premium_slots;
#endif

	std::cout << rs.size() << std::endl;

	_packet_length = 0;
	for (auto r : rs) {
		s_hc_character_list_data c;
		c._character_id = r[0].get<int>();;          ///< 0
		c._base_experience = r[34].get<int64_t>();
		c._zeny = r[36].get<int64_t>();                    ///< 8
		c._job_experience = r[35].get<int64_t>();
		c._job_level = r[33].get<int>();               ///< 16
		c._sc_opt1 = 0;                 ///< 20 Probably OPT1 / 2
		c._sc_opt2 = 0;                 ///< 24
		c._body_state = r[49].get<int64_t>();              ///< 28
		c._virtue = r[50].get<int>();                  ///< 32
		c._honor = r[51].get<int>();                   ///< 36
		c._status_points = r[47].get<int>();           ///< 40
		c._hp = r[44].get<int>();                      ///< 42
		c._maximum_hp = r[43].get<int>();              ///< 46
		c._sp = r[45].get<int>();                      ///< 50
		c._maximum_sp = r[46].get<int>();              ///< 52
		c._walk_speed = int16_t(DEFAULT_MOVEMENT_SPEED);              ///< 54
		c._job_id = r[31].get<int>();                  ///< 56
		c._hair_view_id = r[53].get<int>();            ///< 58
#if PACKET_VERSION >= 20141022
		c._body_view_id = r[56].get<int>();            ///< 60 p->body in hercules.
#endif
		c._weapon_view_id = r[57].get<int>();          ///< 62 OPTION_* in hercules.
		c._base_level = r[32].get<int>();              ///< 64
		c._skill_point = r[48].get<int>();             ///< 66
		c._head_bottom_view_id = r[61].get<int>();     ///< 68
		c._shield_id = r[58].get<int>();               ///< 70
		c._head_top_view_id = r[59].get<int>();        ///< 72
		c._head_mid_view_id = r[60].get<int>();        ///< 74
		c._hair_color_id = r[61].get<int>();           ///< 76
		c._clothes_color_id = r[55].get<int>();        ///< 78
		
		std::string lname = r[3].get<std::string>();
		strncpy(c._name,  lname.c_str(), MAX_UNIT_NAME_LENGTH);  ///< 80
		
		c._strength = r[37].get<int>();                 ///< 104
		c._agility = r[38].get<int>();
		c._vitality = r[39].get<int>();
		c._intelligence = r[40].get<int>();
		c._dexterity = r[41].get<int>();
		c._luck = r[42].get<int>();
		c._char_slot = r[2].get<int>();               ///< 110
#if PACKET_VERSION >= 20061023
		c._rename_count = r[9].get<int>() ? 0 : 1;            ///< 112
#endif
#if (PACKET_VERSION >= 20100720 && PACKET_VERSION <= 20100727) || PACKET_VERSION >= 20100803
		std::string current_map = r[25].get<std::string>();
		strncpy(c._map_name,  current_map.c_str(), MAP_NAME_LENGTH_EXT);///< 114
#endif
#if PACKET_VERSION >= 20100803
		if (r[6].get<int>() != 0) {             ///< 130
			std::chrono::system_clock::duration dn = std::chrono::system_clock::duration(r[6].get<int>());
			c._deleted_at = dn.count() * std::chrono::system_clock::period::num / std::chrono::system_clock::period::den;
		}
		else {
			c._deleted_at = 0;
		}
#endif
#if PACKET_VERSION >= 20110111
		c._robe_view_id = r[62].get<int>();            ///< 134
#endif
#if PACKET_VERSION != 20111116 //2011-11-16 wants 136, ask gravity.
#if PACKET_VERSION >= 20110928
		c._change_slot_count = r[12].get<int>() ? 1 : 0;       ///< 138
#endif
#if PACKET_VERSION >= 20111025
		c._addon_option = r[9].get<int>() ? 1 : 0;            ///< 142 1: Displays "Addon" on side-bar.
#endif
#if PACKET_VERSION >= 20141016
		c._gender = r[5].get<std::string>() == "M" ? 1 : r[5].get<std::string>() == "F" ? 0 : 99;                   ///< 146 0: Female, 1: Male, 99: Account-based.
#endif
#endif
		_packet_length += sizeof(c);
		_characters.push_back(c);
	} // end for
	}
	catch (mysqlx::Error& error) {
		HLog(error) << "HC_ACCEPT_ENTER::prepare: " << error.what();
		return false;
	}
	catch (std::exception& error) {
		HLog(error) << "HC_ACCEPT_ENTER::prepare: " << error.what();
		return false;
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

	for (s_hc_character_list_data c : _characters)
		buf().append((uint8_t *) &c, sizeof(s_hc_character_list_data));
	
	HLog(debug) << "Sending character list data size: " << (sizeof(s_hc_character_list_data) * _characters.size());
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

int32_t HC_ACK_CHARINFO_PER_PAGE::prepare(bool empty)
{
	_packet_length = 4;
	
	if (!empty) {

		mysqlx::RowResult rr;

		try {
			rr = sChar->get_db_connection()->sql("SELECT "
				"a.`id`, a.`account_id`, a.`slot`, a.`name`, a.`online`, a.`gender`, a.`delete_reserved_at`, a.`deleted_at`, a.`unban_time`, "
				"a.`rename_count`, a.`last_unique_id`, a.`hotkey_row_index`, a.`change_slot_count`, a.`font`, a.`show_equip`, a.`allow_party`, "
				"a.`partner_aid`, a.`father_aid`, a.`mother_aid`, a.`child_aid`, a.`party_id`, a.`guild_id`, a.`pet_id`, a.`homun_id`, "
				"a.`elemental_id`, a.`current_map`, a.`current_x`, a.`current_y`, a.`saved_map`, a.`saved_x`, a.`saved_y`, "
				"b.`job_id`, b.`base_level`, b.`job_level`, b.`base_experience`, b.`job_experience`, b.`zeny`, b.`strength`, "
				"b.`agility`, b.`vitality`, b.`intelligence`, b.`dexterity`, b.`luck`, b.`maximum_hp`, b.`hp`, b.`maximum_sp`, "
				"b.`sp`, b.`status_points`, b.`skill_points`, b.`body_state`, b.`virtue`, b.`honor`, b.`manner`, b.`hair_style_id`, "
				"b.`hair_color_id`, b.`cloth_color_id`, b.`body_id`, b.`weapon_view_id`, b.`shield_view_id`, b.`head_top_view_id`, b.`head_mid_view_id`, "
				"b.`head_bottom_view_id`, b.`robe_view_id` "
				"FROM `characters` as a LEFT JOIN `character_status` as b ON a.id = b.id WHERE a.account_id = ? AND a.deleted_at = ?")
				.bind(get_session()->get_session_data()._account_id, 0)
				.execute();
		}
		catch (mysqlx::Error& error) {
			HLog(error) << "HC_ACK_CHARINFO_PER_PAGE::prepare:" << error.what();
			return false;
		}

		std::list<mysqlx::Row> rs = rr.fetchAll();

		for (auto r : rs)
		{
			s_hc_character_list_data c;
			
			c._character_id = r[0].get<int>();          ///< 0
			c._base_experience = r[34].get<int64_t>();
			c._zeny = r[36].get<int64_t>();                    ///< 8
			c._job_experience = r[35].get<int64_t>();
			c._job_level = r[33].get<int>();               ///< 16
			c._sc_opt1 = 0;                 ///< 20 Probably OPT1 / 2
			c._sc_opt2 = 0;                 ///< 24
			c._body_state = r[49].get<int>();              ///< 28
			c._virtue = r[50].get<int>();                  ///< 32
			c._honor = r[51].get<int>();                   ///< 36
			c._status_points = r[47].get<int>();           ///< 40
			c._hp = r[44].get<int>();                      ///< 42
			c._maximum_hp = r[43].get<int>();              ///< 46
			c._sp = r[46].get<int>();                      ///< 50
			c._maximum_sp = r[45].get<int>();              ///< 52
			c._walk_speed = int16_t(DEFAULT_MOVEMENT_SPEED);              ///< 54
			c._job_id = r[31].get<int>();                  ///< 56
			c._hair_view_id = r[53].get<int>();            ///< 58
	#if PACKET_VERSION >= 20141022
			c._body_view_id = r[56].get<int>();            ///< 60 p->body in hercules.
	#endif
			c._weapon_view_id = r[57].get<int>();          ///< 62 OPTION_* in hercules.
			c._base_level = r[32].get<int>();              ///< 64
			c._skill_point = r[48].get<int>();             ///< 66
			c._head_bottom_view_id = r[61].get<int>();     ///< 68
			c._shield_id = r[58].get<int>();               ///< 70
			c._head_top_view_id = r[59].get<int>();        ///< 72
			c._head_mid_view_id = r[60].get<int>();        ///< 74
			c._hair_color_id = r[54].get<int>();           ///< 76
			c._clothes_color_id = r[55].get<int>();        ///< 78
			
			std::string lname = r[3].get<std::string>();
			strncpy(c._name,  lname.c_str(), MAX_UNIT_NAME_LENGTH);  ///< 80
			
			c._strength = r[37].get<int>();                 ///< 104
			c._agility = r[38].get<int>();
			c._vitality = r[39].get<int>();
			c._intelligence = r[40].get<int>();
			c._dexterity = r[41].get<int>();
			c._luck = r[42].get<int>();
			c._char_slot = r[2].get<int>();               ///< 110
#if PACKET_VERSION >= 20061023
			c._rename_count = r[9].get<int>() ? 0 : 1;            ///< 112
#endif
#if (PACKET_VERSION >= 20100720 && PACKET_VERSION <= 20100727) || PACKET_VERSION >= 20100803
			std::string current_map = r[25].get<std::string>();
			strncpy(c._map_name,  current_map.c_str(), MAP_NAME_LENGTH_EXT);///< 114
#endif
#if PACKET_VERSION >= 20100803
		if (r[6].get<int>() != 0) {
			std::chrono::system_clock::duration dn = std::chrono::system_clock::duration(r[6].get<int>());
			c._deleted_at = dn.count() * std::chrono::system_clock::period::num / std::chrono::system_clock::period::den;
		}
		else {
			c._deleted_at = 0;
		}
#endif
#if PACKET_VERSION >= 20110111
			c._robe_view_id = r[62].get<int>();            ///< 134
#endif
#if PACKET_VERSION != 20111116 //2011-11-16 wants 136, ask gravity.
	#if PACKET_VERSION >= 20110928
			c._change_slot_count = r[12].get<int>() ? 1 : 0;       ///< 138
	#endif
	#if PACKET_VERSION >= 20111025
			c._addon_option = r[9].get<int>() ? 1 : 0;            ///< 142 1: Displays "Addon" on side-bar.
	#endif
	#if PACKET_VERSION >= 20141016
			c._gender = r[5].get<std::string>() == "M" ? 1 : r[5].get<std::string>() == "F" ? 0 : 99;                   ///< 146 0: Female, 1: Male, 99: Account-based.
	#endif
#endif
			_packet_length += sizeof(c);
			_characters.push_back(c);
		}	
	}
	
	buf() << _packet_id;
	buf() << _packet_length;
	
	if (!empty)
		for (s_hc_character_list_data c : _characters)
			buf().append((int8_t *) &c, sizeof(s_hc_character_list_data));
	
	HLog(debug) << "Sending character list data size: " << (sizeof(s_hc_character_list_data) * _characters.size());

	return _characters.size();
}

void HC_ACK_CHARINFO_PER_PAGE::deliver() 
{
	transmit();
}

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

