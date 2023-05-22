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


#include "HandledPackets.hpp"
#include "Server/Zone/Session/ZoneSession.hpp"

using namespace Horizon::Zone;

/**
 * CZ_AUCTION_ADD_ITEM
 */
void CZ_AUCTION_ADD_ITEM::handle(ByteBuffer &&buf) { }

void CZ_AUCTION_ADD_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CLOSE_WINDOW
 */
void CZ_CLOSE_WINDOW::handle(ByteBuffer &&buf) { }

void CZ_CLOSE_WINDOW::deserialize(ByteBuffer &buf) { }

/**
 * CZ_RESTART
 */
void CZ_RESTART::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->restart(_type);
}

void CZ_RESTART::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _type;
}

/**
 * CZ_REQUEST_MOVETOOWNER
 */
void CZ_REQUEST_MOVETOOWNER::handle(ByteBuffer &&buf) { }

void CZ_REQUEST_MOVETOOWNER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ACCOUNTNAME
 */
void CZ_REQ_ACCOUNTNAME::handle(ByteBuffer &&buf) { }

void CZ_REQ_ACCOUNTNAME::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQUEST_ACT
 */
void CZ_REQUEST_ACT::handle(ByteBuffer &&buf)
{
	deserialize(buf);
    get_session()->clif()->action_request(_target_guid, (player_action_type) _action);
}

void CZ_REQUEST_ACT::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _target_guid;
	buf >> _action;
}

/**
 * CZ_GM_FULLSTRIP
 */
void CZ_GM_FULLSTRIP::handle(ByteBuffer &&buf) { }

void CZ_GM_FULLSTRIP::deserialize(ByteBuffer &buf) { }

/**
 * CZ_COMMAND_PET
 */
void CZ_COMMAND_PET::handle(ByteBuffer &&buf) { }

void CZ_COMMAND_PET::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MAIL_ADD_ITEM
 */
void CZ_MAIL_ADD_ITEM::handle(ByteBuffer &&buf) { }

void CZ_MAIL_ADD_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_CART_TO_STORE
 */
void CZ_MOVE_ITEM_FROM_CART_TO_STORE::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_CART_TO_STORE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ENTER
 */
void CZ_ENTER::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->login(_account_id, _char_id, _auth_code, _client_time, _gender);
}

void CZ_ENTER::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _account_id;
	buf >> _char_id;
	buf >> _auth_code;
	buf >> _client_time;
	buf >> _gender;
}

/**
 * CZ_REQUEST_TIME2
 */
void CZ_REQUEST_TIME2::handle(ByteBuffer &&buf) { }

void CZ_REQUEST_TIME2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_JOIN_BATTLE_FIELD
 */
void CZ_JOIN_BATTLE_FIELD::handle(ByteBuffer &&buf) { }

void CZ_JOIN_BATTLE_FIELD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_LOCALBROADCAST
 */
void CZ_LOCALBROADCAST::handle(ByteBuffer &&buf) { }

void CZ_LOCALBROADCAST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REMOVE_AID
 */
void CZ_REMOVE_AID::handle(ByteBuffer &&buf) { }

void CZ_REMOVE_AID::deserialize(ByteBuffer &buf) { }

/**
 * CZ_KSY_EVENT
 */
void CZ_KSY_EVENT::handle(ByteBuffer &&buf) { }

void CZ_KSY_EVENT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ITEM_PICKUP
 */
void CZ_ITEM_PICKUP::handle(ByteBuffer &&buf) { }

void CZ_ITEM_PICKUP::deserialize(ByteBuffer &buf) { }

/**
 * CZ_AUCTION_CREATE
 */
void CZ_AUCTION_CREATE::handle(ByteBuffer &&buf) { }

void CZ_AUCTION_CREATE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_BANKING_DEPOSIT
 */
void CZ_REQ_BANKING_DEPOSIT::handle(ByteBuffer &&buf) { }

void CZ_REQ_BANKING_DEPOSIT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MAIL_GET_LIST
 */
void CZ_MAIL_GET_LIST::handle(ByteBuffer &&buf) { }

void CZ_MAIL_GET_LIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_BROADCAST
 */
void CZ_BROADCAST::handle(ByteBuffer &&buf) { }

void CZ_BROADCAST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ENTRY_QUEUE_CANCEL
 */
void CZ_REQ_ENTRY_QUEUE_CANCEL::handle(ByteBuffer &&buf) { }

void CZ_REQ_ENTRY_QUEUE_CANCEL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_UNKNOWN_BOOKING_SOMMON_MEMBER_08f5
 */
void CZ_UNKNOWN_BOOKING_SOMMON_MEMBER_08f5::handle(ByteBuffer &&buf) { }

void CZ_UNKNOWN_BOOKING_SOMMON_MEMBER_08f5::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ES_GET_LIST
 */
void CZ_ES_GET_LIST::handle(ByteBuffer &&buf) { }

void CZ_ES_GET_LIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_OPEN_GUILD_STORAGE
 */
void CZ_REQ_OPEN_GUILD_STORAGE::handle(ByteBuffer &&buf) { }

void CZ_REQ_OPEN_GUILD_STORAGE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SETTING_WHISPER_STATE
 */
void CZ_SETTING_WHISPER_STATE::handle(ByteBuffer &&buf) { }

void CZ_SETTING_WHISPER_STATE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_RENAME_MER
 */
void CZ_RENAME_MER::handle(ByteBuffer &&buf) { }

void CZ_RENAME_MER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_JOIN_REQ_ACK
 */
void CZ_PARTY_JOIN_REQ_ACK::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().invite_response(_party_id, ((int)_response) ? PARTY_INVITE_RESPONSE_ACCEPT : PARTY_INVITE_RESPONSE_REJECT);
}

void CZ_PARTY_JOIN_REQ_ACK::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _party_id;
	buf >> _response;
}

/**
 * CZ_REQ_TRADE_BUYING_STORE
 */
void CZ_REQ_TRADE_BUYING_STORE::handle(ByteBuffer &&buf) { }

void CZ_REQ_TRADE_BUYING_STORE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_CONFIG
 */
void CZ_PARTY_CONFIG::handle(ByteBuffer &&buf) { }

void CZ_PARTY_CONFIG::deserialize(ByteBuffer &buf) { }

/**
 * CZ_NPC_TRADE_QUIT
 */
void CZ_NPC_TRADE_QUIT::handle(ByteBuffer &&buf) { }

void CZ_NPC_TRADE_QUIT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_OPENSTORE
 */
void CZ_REQ_OPENSTORE::handle(ByteBuffer &&buf) { }

void CZ_REQ_OPENSTORE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SELECT_PETEGG
 */
void CZ_SELECT_PETEGG::handle(ByteBuffer &&buf) { }

void CZ_SELECT_PETEGG::deserialize(ByteBuffer &buf) { }

/**
 * CZ_STANDING_RESURRECTION
 */
void CZ_STANDING_RESURRECTION::handle(ByteBuffer &&buf) { }

void CZ_STANDING_RESURRECTION::deserialize(ByteBuffer &buf) { }

/**
 * CZ_NPROTECTGAMEGUARDCSAUTH
 */
void CZ_NPROTECTGAMEGUARDCSAUTH::handle(ByteBuffer &&buf) { }

void CZ_NPROTECTGAMEGUARDCSAUTH::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_STORE_TO_BODY2
 */
void CZ_MOVE_ITEM_FROM_STORE_TO_BODY2::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_STORE_TO_BODY2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_JOIN_COUPLE
 */
void CZ_JOIN_COUPLE::handle(ByteBuffer &&buf) { }

void CZ_JOIN_COUPLE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PC_SELL_ITEMLIST
 */
void CZ_PC_SELL_ITEMLIST::handle(ByteBuffer &&buf) { }

void CZ_PC_SELL_ITEMLIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_NEXT_SCRIPT
 */
void CZ_REQ_NEXT_SCRIPT::handle(ByteBuffer &&buf) { }

void CZ_REQ_NEXT_SCRIPT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_BODY_TO_STORE2
 */
void CZ_MOVE_ITEM_FROM_BODY_TO_STORE2::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_BODY_TO_STORE2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PROGRESS
 */
void CZ_PROGRESS::handle(ByteBuffer &&buf) { }

void CZ_PROGRESS::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_GUILD_EMBLEM_IMG
 */
void CZ_REQ_GUILD_EMBLEM_IMG::handle(ByteBuffer &&buf) { }

void CZ_REQ_GUILD_EMBLEM_IMG::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_REMOVE_BARGAIN_SALE_ITEM
 */
void CZ_REQ_REMOVE_BARGAIN_SALE_ITEM::handle(ByteBuffer &&buf) { }

void CZ_REQ_REMOVE_BARGAIN_SALE_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_BOOKING_REQ_REGISTER
 */
void CZ_PARTY_BOOKING_REQ_REGISTER::handle(ByteBuffer &&buf) { }

void CZ_PARTY_BOOKING_REQ_REGISTER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ENTRY_QUEUE_RANKING
 */
void CZ_REQ_ENTRY_QUEUE_RANKING::handle(ByteBuffer &&buf) { }

void CZ_REQ_ENTRY_QUEUE_RANKING::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_RECRUIT_REQ_REGISTER
 */
void CZ_PARTY_RECRUIT_REQ_REGISTER::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_REQ_REGISTER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_OPENSTORE2
 */
void CZ_REQ_OPENSTORE2::handle(ByteBuffer &&buf) { }

void CZ_REQ_OPENSTORE2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MACRO_USE_SKILL_TOGROUND
 */
void CZ_MACRO_USE_SKILL_TOGROUND::handle(ByteBuffer &&buf) { }

void CZ_MACRO_USE_SKILL_TOGROUND::deserialize(ByteBuffer &buf) { }

/**
 * CZ_DISCONNECT_CHARACTER
 */
void CZ_DISCONNECT_CHARACTER::handle(ByteBuffer &&buf) { }

void CZ_DISCONNECT_CHARACTER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CANCEL_BATTLE_FIELD
 */
void CZ_CANCEL_BATTLE_FIELD::handle(ByteBuffer &&buf) { }

void CZ_CANCEL_BATTLE_FIELD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_RENAME_PET
 */
void CZ_RENAME_PET::handle(ByteBuffer &&buf) { }

void CZ_RENAME_PET::deserialize(ByteBuffer &buf) { }

/**
 * CZ_BATTLE_FIELD_LIST
 */
void CZ_BATTLE_FIELD_LIST::handle(ByteBuffer &&buf) { }

void CZ_BATTLE_FIELD_LIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_USE_SKILL
 */
void CZ_USE_SKILL::handle(ByteBuffer &&buf) { }

void CZ_USE_SKILL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ENTRY_QUEUE_APPLY
 */
void CZ_REQ_ENTRY_QUEUE_APPLY::handle(ByteBuffer &&buf) { }

void CZ_REQ_ENTRY_QUEUE_APPLY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SETTING_WHISPER_PC
 */
void CZ_SETTING_WHISPER_PC::handle(ByteBuffer &&buf) { }

void CZ_SETTING_WHISPER_PC::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SEARCH_STORE_INFO
 */
void CZ_SEARCH_STORE_INFO::handle(ByteBuffer &&buf) { }

void CZ_SEARCH_STORE_INFO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ITEM_PICKUP2
 */
void CZ_ITEM_PICKUP2::handle(ByteBuffer &&buf) { }

void CZ_ITEM_PICKUP2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_RECRUIT_CANCEL_VOLUNTEER
 */
void CZ_PARTY_RECRUIT_CANCEL_VOLUNTEER::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_CANCEL_VOLUNTEER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_NEXT_RODEX
 */
void CZ_REQ_NEXT_RODEX::handle(ByteBuffer &&buf) { }

void CZ_REQ_NEXT_RODEX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ES_CANCEL
 */
void CZ_ES_CANCEL::handle(ByteBuffer &&buf) { }

void CZ_ES_CANCEL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_TAKEOFF_EQUIP
 */
void CZ_REQ_TAKEOFF_EQUIP::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->unequip_item(_inventory_index);
}

void CZ_REQ_TAKEOFF_EQUIP::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _inventory_index;
}

/**
 * CZ_IRMAIL_LIST
 */
void CZ_IRMAIL_LIST::handle(ByteBuffer &&buf) { }

void CZ_IRMAIL_LIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_INPUT_EDITDLG
 */
void CZ_INPUT_EDITDLG::handle(ByteBuffer &&buf) { }

void CZ_INPUT_EDITDLG::deserialize(ByteBuffer &buf) { }

/**
 * CZ_JOIN_BABY
 */
void CZ_JOIN_BABY::handle(ByteBuffer &&buf) { }

void CZ_JOIN_BABY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_AUCTION_ITEM_SEARCH
 */
void CZ_AUCTION_ITEM_SEARCH::handle(ByteBuffer &&buf) { }

void CZ_AUCTION_ITEM_SEARCH::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ZENY_FROM_RODEX
 */
void CZ_REQ_ZENY_FROM_RODEX::handle(ByteBuffer &&buf) { }

void CZ_REQ_ZENY_FROM_RODEX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ACK_GAME_GUARD
 */
void CZ_ACK_GAME_GUARD::handle(ByteBuffer &&buf) { }

void CZ_ACK_GAME_GUARD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_SEND_RODEX
 */
void CZ_REQ_SEND_RODEX::handle(ByteBuffer &&buf) { }

void CZ_REQ_SEND_RODEX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_RECRUIT_REQ_UPDATE
 */
void CZ_PARTY_RECRUIT_REQ_UPDATE::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_REQ_UPDATE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_WEAR_EQUIP
 */
void CZ_REQ_WEAR_EQUIP::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->equip_item(_inventory_index, _equip_location_mask);
}

void CZ_REQ_WEAR_EQUIP::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _inventory_index;
	buf >> _equip_location_mask;
}

/**
 * CZ_PARTY_RECRUIT_REQ_VOLUNTEER
 */
void CZ_PARTY_RECRUIT_REQ_VOLUNTEER::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_REQ_VOLUNTEER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_BOOKING_REQ_UPDATE
 */
void CZ_PARTY_BOOKING_REQ_UPDATE::handle(ByteBuffer &&buf) { }

void CZ_PARTY_BOOKING_REQ_UPDATE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REFINE_WINDOW_CLOSE
 */
void CZ_REFINE_WINDOW_CLOSE::handle(ByteBuffer &&buf) { }

void CZ_REFINE_WINDOW_CLOSE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_INVENTORY_EXPAND_REJECTED
 */
void CZ_INVENTORY_EXPAND_REJECTED::handle(ByteBuffer &&buf) { }

void CZ_INVENTORY_EXPAND_REJECTED::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_GUILDSTORAGE_LOG
 */
void CZ_REQ_GUILDSTORAGE_LOG::handle(ByteBuffer &&buf) { }

void CZ_REQ_GUILDSTORAGE_LOG::deserialize(ByteBuffer &buf) { }

/**
 * CZ_DELETE_FRIENDS
 */
void CZ_DELETE_FRIENDS::handle(ByteBuffer &&buf) { }

void CZ_DELETE_FRIENDS::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_RECRUIT_ACK_RECALL
 */
void CZ_PARTY_RECRUIT_ACK_RECALL::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_ACK_RECALL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_REFRESH_RODEX
 */
void CZ_REQ_REFRESH_RODEX::handle(ByteBuffer &&buf) { }

void CZ_REQ_REFRESH_RODEX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_AUCTION_REQ_MY_SELL_STOP
 */
void CZ_AUCTION_REQ_MY_SELL_STOP::handle(ByteBuffer &&buf) { }

void CZ_AUCTION_REQ_MY_SELL_STOP::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_STORE_TO_CART
 */
void CZ_MOVE_ITEM_FROM_STORE_TO_CART::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_STORE_TO_CART::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_USER_COUNT
 */
void CZ_REQ_USER_COUNT::handle(ByteBuffer &&buf) { }

void CZ_REQ_USER_COUNT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ITEM_CREATE_EX
 */
void CZ_ITEM_CREATE_EX::handle(ByteBuffer &&buf) { }

void CZ_ITEM_CREATE_EX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_GUILDSTORAGE_TO_CART
 */
void CZ_MOVE_ITEM_FROM_GUILDSTORAGE_TO_CART::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_GUILDSTORAGE_TO_CART::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_DELETE_RODEX
 */
void CZ_REQ_DELETE_RODEX::handle(ByteBuffer &&buf) { }

void CZ_REQ_DELETE_RODEX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SE_PC_BUY_CASHITEM_LIST
 */
void CZ_SE_PC_BUY_CASHITEM_LIST::handle(ByteBuffer &&buf) { }

void CZ_SE_PC_BUY_CASHITEM_LIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SEARCH_STORE_INFO_NEXT_PAGE
 */
void CZ_SEARCH_STORE_INFO_NEXT_PAGE::handle(ByteBuffer &&buf) { }

void CZ_SEARCH_STORE_INFO_NEXT_PAGE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ADD_FRIENDS
 */
void CZ_ADD_FRIENDS::handle(ByteBuffer &&buf) { }

void CZ_ADD_FRIENDS::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_GUILD_MENUINTERFACE
 */
void CZ_REQ_GUILD_MENUINTERFACE::handle(ByteBuffer &&buf) { }

void CZ_REQ_GUILD_MENUINTERFACE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PKMODE_CHANGE
 */
void CZ_PKMODE_CHANGE::handle(ByteBuffer &&buf) { }

void CZ_PKMODE_CHANGE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CHANGE_GROUP_MASTER
 */
void CZ_CHANGE_GROUP_MASTER::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().change_leader(_account_id);
}

void CZ_CHANGE_GROUP_MASTER::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _account_id;
}

/**
 * CZ_GPK_DYNCODE_RELOAD
 */
void CZ_GPK_DYNCODE_RELOAD::handle(ByteBuffer &&buf) { }

void CZ_GPK_DYNCODE_RELOAD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_LEAVE_GROUP
 */
void CZ_REQ_LEAVE_GROUP::handle(ByteBuffer &&buf) { }

void CZ_REQ_LEAVE_GROUP::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_MAIL_RETURN
 */
void CZ_REQ_MAIL_RETURN::handle(ByteBuffer &&buf) { }

void CZ_REQ_MAIL_RETURN::deserialize(ByteBuffer &buf) { }

/**
 * CZ_EQUIPWIN_MICROSCOPE
 */
void CZ_EQUIPWIN_MICROSCOPE::handle(ByteBuffer &&buf) { }

void CZ_EQUIPWIN_MICROSCOPE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MAIL_OPEN
 */
void CZ_MAIL_OPEN::handle(ByteBuffer &&buf) { }

void CZ_MAIL_OPEN::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SIMPLE_CASH_BTNSHOW
 */
void CZ_SIMPLE_CASH_BTNSHOW::handle(ByteBuffer &&buf) { }

void CZ_SIMPLE_CASH_BTNSHOW::deserialize(ByteBuffer &buf) { }

/**
 * CZ_COMMAND_MER
 */
void CZ_COMMAND_MER::handle(ByteBuffer &&buf) { }

void CZ_COMMAND_MER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_BEFORE_WORLD_INFO
 */
void CZ_REQ_BEFORE_WORLD_INFO::handle(ByteBuffer &&buf) { }

void CZ_REQ_BEFORE_WORLD_INFO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CARTOFF
 */
void CZ_REQ_CARTOFF::handle(ByteBuffer &&buf) { }

void CZ_REQ_CARTOFF::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CLOSE_BANKING
 */
void CZ_REQ_CLOSE_BANKING::handle(ByteBuffer &&buf) { }

void CZ_REQ_CLOSE_BANKING::deserialize(ByteBuffer &buf) { }

/**
 * CZ_START_USE_SKILL
 */
void CZ_START_USE_SKILL::handle(ByteBuffer &&buf) { }

void CZ_START_USE_SKILL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ATTENDANCE_REWARD_REQUEST
 */
void CZ_ATTENDANCE_REWARD_REQUEST::handle(ByteBuffer &&buf) { }

void CZ_ATTENDANCE_REWARD_REQUEST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_RECALL
 */
void CZ_RECALL::handle(ByteBuffer &&buf) { }

void CZ_RECALL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CLIENT_VERSION
 */
void CZ_CLIENT_VERSION::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->update_session(_account_id);
}

void CZ_CLIENT_VERSION::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _account_id;
}

/**
 * CZ_CHECK_RECEIVE_CHARACTER_NAME
 */
void CZ_CHECK_RECEIVE_CHARACTER_NAME::handle(ByteBuffer &&buf) { }

void CZ_CHECK_RECEIVE_CHARACTER_NAME::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ENTER2
 */
void CZ_ENTER2::handle(ByteBuffer &&buf) { }

void CZ_ENTER2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_DEATH_QUESTION
 */
void CZ_DEATH_QUESTION::handle(ByteBuffer &&buf) { }

void CZ_DEATH_QUESTION::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SHORTCUT_KEY_CHANGE
 */
void CZ_SHORTCUT_KEY_CHANGE::handle(ByteBuffer &&buf) { }

void CZ_SHORTCUT_KEY_CHANGE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_GUILD_ZENY
 */
void CZ_GUILD_ZENY::handle(ByteBuffer &&buf) { }

void CZ_GUILD_ZENY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_OPEN_BUYING_STORE
 */
void CZ_REQ_OPEN_BUYING_STORE::handle(ByteBuffer &&buf) { }

void CZ_REQ_OPEN_BUYING_STORE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_PARTY_NAME
 */
void CZ_REQ_PARTY_NAME::handle(ByteBuffer &&buf) { }

void CZ_REQ_PARTY_NAME::deserialize(ByteBuffer &buf) { }

/**
 * CZ_AGREE_STARPLACE
 */
void CZ_AGREE_STARPLACE::handle(ByteBuffer &&buf) { }

void CZ_AGREE_STARPLACE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_USE_ITEM2
 */
void CZ_USE_ITEM2::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->use_item(_inventory_index, _guid);
}

void CZ_USE_ITEM2::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _inventory_index;
	buf >> _guid;
}

/**
 * CZ_REQ_ADD_ITEM_RODEX
 */
void CZ_REQ_ADD_ITEM_RODEX::handle(ByteBuffer &&buf) { }

void CZ_REQ_ADD_ITEM_RODEX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_GUILD_NAME
 */
void CZ_REQ_GUILD_NAME::handle(ByteBuffer &&buf) { }

void CZ_REQ_GUILD_NAME::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MONSTER_TALK
 */
void CZ_MONSTER_TALK::handle(ByteBuffer &&buf) { }

void CZ_MONSTER_TALK::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_DISCONNECT
 * Type = 0 => Quit
 */
void CZ_REQ_DISCONNECT::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->disconnect(_type);
}

void CZ_REQ_DISCONNECT::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _type;
}

/**
 * CZ_STATUS_CHANGE
 */
void CZ_STATUS_CHANGE::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->increase_status_point((status_point_type) _type, _amount);
}

void CZ_STATUS_CHANGE::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _type;
	buf >> _amount;
}

/**
 * CZ_CHANGE_GROUPEXPOPTION
 */
void CZ_CHANGE_GROUPEXPOPTION::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().change_properties(_exp_share_rule, 0, 0);
}

void CZ_CHANGE_GROUPEXPOPTION::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _exp_share_rule;
}

/**
 * CZ_NOTIFY_ACTORINIT
 */
void CZ_NOTIFY_ACTORINIT::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->map_enter();
}

void CZ_NOTIFY_ACTORINIT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SE_CASHSHOP_CLOSE
 */
void CZ_SE_CASHSHOP_CLOSE::handle(ByteBuffer &&buf) { }

void CZ_SE_CASHSHOP_CLOSE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_JOIN_REQ
 */
void CZ_PARTY_JOIN_REQ::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().invite(_name);
}

void CZ_PARTY_JOIN_REQ::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf.read(_name, MAX_UNIT_NAME_LENGTH);
}

/**
 * CZ_SHIFT
 */
void CZ_SHIFT::handle(ByteBuffer &&buf) { }

void CZ_SHIFT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_COUNT_BARGAIN_SALE_ITEM
 */
void CZ_REQ_COUNT_BARGAIN_SALE_ITEM::handle(ByteBuffer &&buf) { }

void CZ_REQ_COUNT_BARGAIN_SALE_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVETO_MAP
 */
void CZ_MOVETO_MAP::handle(ByteBuffer &&buf) { }

void CZ_MOVETO_MAP::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_JOIN_BABY
 */
void CZ_REQ_JOIN_BABY::handle(ByteBuffer &&buf) { }

void CZ_REQ_JOIN_BABY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ITEMREPAIR
 */
void CZ_REQ_ITEMREPAIR::handle(ByteBuffer &&buf) { }

void CZ_REQ_ITEMREPAIR::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQUEST_MOVE2
 */
void CZ_REQUEST_MOVE2::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->walk_to_coordinates(_x, _y, _dir);
}

void CZ_REQUEST_MOVE2::deserialize(ByteBuffer &buf)
{
	char packed_pos[3];
	buf >> _packet_id;
	buf.read(packed_pos, sizeof(packed_pos));
	UnpackPosition((uint8_t *) packed_pos, &_x, &_y, &_dir);
}

/**
 * CZ_REQ_LEAVE_GUILD
 */
void CZ_REQ_LEAVE_GUILD::handle(ByteBuffer &&buf) { }

void CZ_REQ_LEAVE_GUILD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PC_PURCHASE_ITEMLIST_FROMMC
 */
void CZ_PC_PURCHASE_ITEMLIST_FROMMC::handle(ByteBuffer &&buf) { }

void CZ_PC_PURCHASE_ITEMLIST_FROMMC::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REPLY_ENTRY_QUEUE_ADMISSION
 */
void CZ_REPLY_ENTRY_QUEUE_ADMISSION::handle(ByteBuffer &&buf) { }

void CZ_REPLY_ENTRY_QUEUE_ADMISSION::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MACRO_STOP
 */
void CZ_MACRO_STOP::handle(ByteBuffer &&buf) { }

void CZ_MACRO_STOP::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CANCEL_EXCHANGE_ITEM
 */
void CZ_CANCEL_EXCHANGE_ITEM::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->trade().cancel();
}

void CZ_CANCEL_EXCHANGE_ITEM::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
}

/**
 * CZ_PARTY_RECRUIT_REQ_SEARCH
 */
void CZ_PARTY_RECRUIT_REQ_SEARCH::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_REQ_SEARCH::deserialize(ByteBuffer &buf) { }

/**
 * CZ_HACKSHIELD_CRC_MSG
 */
void CZ_HACKSHIELD_CRC_MSG::handle(ByteBuffer &&buf) { }

void CZ_HACKSHIELD_CRC_MSG::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQUEST_MOVE
 */
void CZ_REQUEST_MOVE::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->walk_to_coordinates(_x, _y, _dir);
}

void CZ_REQUEST_MOVE::deserialize(ByteBuffer &buf)
{
	char packed_pos[3];
	buf >> _packet_id;
	buf.read(packed_pos, sizeof(packed_pos));
	UnpackPosition((uint8_t *) packed_pos, &_x, &_y, &_dir);
}

/**
 * CZ_NPC_MARKET_PURCHASE
 */
void CZ_NPC_MARKET_PURCHASE::handle(ByteBuffer &&buf) { }

void CZ_NPC_MARKET_PURCHASE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQNAME_BYGID
 */
void CZ_REQNAME_BYGID::handle(ByteBuffer &&buf) { }

void CZ_REQNAME_BYGID::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_JOIN_GROUP
 */
void CZ_REQ_JOIN_GROUP::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().invite(_account_id);
}

void CZ_REQ_JOIN_GROUP::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _account_id;
}

/**
 * CZ_REQ_ROULETTE_INFO
 */
void CZ_REQ_ROULETTE_INFO::handle(ByteBuffer &&buf) { }

void CZ_REQ_ROULETTE_INFO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ALT_EQUIPMENT_EQUIP
 */
void CZ_ALT_EQUIPMENT_EQUIP::handle(ByteBuffer &&buf) { }

void CZ_ALT_EQUIPMENT_EQUIP::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ONECLICK_ITEMIDENTIFY
 */
void CZ_REQ_ONECLICK_ITEMIDENTIFY::handle(ByteBuffer &&buf) { }

void CZ_REQ_ONECLICK_ITEMIDENTIFY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PET_EVOLUTION
 */
void CZ_PET_EVOLUTION::handle(ByteBuffer &&buf) { }

void CZ_PET_EVOLUTION::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_RECRUIT_SUB_FILTERLINGLIST
 */
void CZ_PARTY_RECRUIT_SUB_FILTERLINGLIST::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_SUB_FILTERLINGLIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ACK_AU_BOT
 */
void CZ_ACK_AU_BOT::handle(ByteBuffer &&buf) { }

void CZ_ACK_AU_BOT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_REMAINTIME
 */
void CZ_REQ_REMAINTIME::handle(ByteBuffer &&buf) { }

void CZ_REQ_REMAINTIME::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PRIVATE_AIRSHIP_REQUEST
 */
void CZ_PRIVATE_AIRSHIP_REQUEST::handle(ByteBuffer &&buf) { }

void CZ_PRIVATE_AIRSHIP_REQUEST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REMOVE_AID_SSO
 */
void CZ_REMOVE_AID_SSO::handle(ByteBuffer &&buf) { }

void CZ_REMOVE_AID_SSO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_EMOTION
 */
void CZ_REQ_EMOTION::handle(ByteBuffer &&buf) { }

void CZ_REQ_EMOTION::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ACK_CASH_PASSWORD
 */
void CZ_ACK_CASH_PASSWORD::handle(ByteBuffer &&buf) { }

void CZ_ACK_CASH_PASSWORD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CASH_BARGAIN_SALE_ITEM_INFO
 */
void CZ_REQ_CASH_BARGAIN_SALE_ITEM_INFO::handle(ByteBuffer &&buf) { }

void CZ_REQ_CASH_BARGAIN_SALE_ITEM_INFO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_RESET
 */
void CZ_RESET::handle(ByteBuffer &&buf) { }

void CZ_RESET::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_JOIN_GUILD
 */
void CZ_REQ_JOIN_GUILD::handle(ByteBuffer &&buf) { }

void CZ_REQ_JOIN_GUILD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_HOSTILE_GUILD
 */
void CZ_REQ_HOSTILE_GUILD::handle(ByteBuffer &&buf) { }

void CZ_REQ_HOSTILE_GUILD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_GUILD_MENU
 */
void CZ_REQ_GUILD_MENU::handle(ByteBuffer &&buf) { }

void CZ_REQ_GUILD_MENU::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_GIVE_MANNER_BYNAME
 */
void CZ_REQ_GIVE_MANNER_BYNAME::handle(ByteBuffer &&buf) { }

void CZ_REQ_GIVE_MANNER_BYNAME::deserialize(ByteBuffer &buf) { }

/**
 * CZ_AUCTION_ADD
 */
void CZ_AUCTION_ADD::handle(ByteBuffer &&buf) { }

void CZ_AUCTION_ADD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REG_CHANGE_GUILD_POSITIONINFO
 */
void CZ_REG_CHANGE_GUILD_POSITIONINFO::handle(ByteBuffer &&buf) { }

void CZ_REG_CHANGE_GUILD_POSITIONINFO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REGISTER_GUILD_EMBLEM_IMG
 */
void CZ_REGISTER_GUILD_EMBLEM_IMG::handle(ByteBuffer &&buf) { }

void CZ_REGISTER_GUILD_EMBLEM_IMG::deserialize(ByteBuffer &buf) { }

/**
 * CZ_UNUSED_MER_USE_SKILL
 */
void CZ_UNUSED_MER_USE_SKILL::handle(ByteBuffer &&buf) { }

void CZ_UNUSED_MER_USE_SKILL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_OPEN_RODEXBOX
 */
void CZ_OPEN_RODEXBOX::handle(ByteBuffer &&buf) { }

void CZ_OPEN_RODEXBOX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_CART_TO_GUILDSTORAGE
 */
void CZ_MOVE_ITEM_FROM_CART_TO_GUILDSTORAGE::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_CART_TO_GUILDSTORAGE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MEMORIALDUNGEON_COMMAND
 */
void CZ_MEMORIALDUNGEON_COMMAND::handle(ByteBuffer &&buf) { }

void CZ_MEMORIALDUNGEON_COMMAND::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_BODY_TO_STORE
 */
void CZ_MOVE_ITEM_FROM_BODY_TO_STORE::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_BODY_TO_STORE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_OPEN_BANKING
 */
void CZ_REQ_OPEN_BANKING::handle(ByteBuffer &&buf) { }

void CZ_REQ_OPEN_BANKING::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REFINE_ITEM_REQUEST
 */
void CZ_REFINE_ITEM_REQUEST::handle(ByteBuffer &&buf) { }

void CZ_REFINE_ITEM_REQUEST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ITEMCOMPOSITION_LIST
 */
void CZ_REQ_ITEMCOMPOSITION_LIST::handle(ByteBuffer &&buf) { }

void CZ_REQ_ITEMCOMPOSITION_LIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MACRO_START
 */
void CZ_MACRO_START::handle(ByteBuffer &&buf) { }

void CZ_MACRO_START::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CLOSE_BUYING_STORE
 */
void CZ_REQ_CLOSE_BUYING_STORE::handle(ByteBuffer &&buf) { }

void CZ_REQ_CLOSE_BUYING_STORE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SHORTCUTKEYBAR_ROTATE
 */
void CZ_SHORTCUTKEYBAR_ROTATE::handle(ByteBuffer &&buf) { }

void CZ_SHORTCUTKEYBAR_ROTATE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_BANKING_WITHDRAW
 */
void CZ_REQ_BANKING_WITHDRAW::handle(ByteBuffer &&buf) { }

void CZ_REQ_BANKING_WITHDRAW::deserialize(ByteBuffer &buf) { }

/**
 * CZ_USE_SKILL_TOGROUND2
 */
void CZ_USE_SKILL_TOGROUND2::handle(ByteBuffer &&buf) { }

void CZ_USE_SKILL_TOGROUND2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_BOOKING_REQ_SEARCH
 */
void CZ_PARTY_BOOKING_REQ_SEARCH::handle(ByteBuffer &&buf) { }

void CZ_PARTY_BOOKING_REQ_SEARCH::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ADD_EXCHANGE_ITEM
 */
void CZ_ADD_EXCHANGE_ITEM::handle(ByteBuffer &&buf) 
{
	deserialize(buf);

	switch (_inventory_index) {
	case 0:
		get_session()->clif()->trade().add_zeny(_amount);
		break;
	default:
		get_session()->clif()->trade().add_item(_inventory_index, _amount);
		break;
	}
}

void CZ_ADD_EXCHANGE_ITEM::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _inventory_index;
	buf >> _amount;
}

/**
 * CZ_UNUSED_MER_UPGRADE_SKILLLEVEL
 */
void CZ_UNUSED_MER_UPGRADE_SKILLLEVEL::handle(ByteBuffer &&buf) { }

void CZ_UNUSED_MER_UPGRADE_SKILLLEVEL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_GUILD_NOTICE
 */
void CZ_GUILD_NOTICE::handle(ByteBuffer &&buf) { }

void CZ_GUILD_NOTICE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_AUCTION_ADD_CANCEL
 */
void CZ_AUCTION_ADD_CANCEL::handle(ByteBuffer &&buf) { }

void CZ_AUCTION_ADD_CANCEL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MACRO_USE_SKILL
 */
void CZ_MACRO_USE_SKILL::handle(ByteBuffer &&buf) { }

void CZ_MACRO_USE_SKILL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CANCEL_WRITE_RODEX
 */
void CZ_REQ_CANCEL_WRITE_RODEX::handle(ByteBuffer &&buf) { }

void CZ_REQ_CANCEL_WRITE_RODEX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_TRYCAPTURE_MONSTER
 */
void CZ_TRYCAPTURE_MONSTER::handle(ByteBuffer &&buf) { }

void CZ_TRYCAPTURE_MONSTER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ITEM_PICKUP_NEW_JAPEN
 */
void CZ_ITEM_PICKUP_NEW_JAPEN::handle(ByteBuffer &&buf) { }

void CZ_ITEM_PICKUP_NEW_JAPEN::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_JOIN_GUILD2
 */
void CZ_REQ_JOIN_GUILD2::handle(ByteBuffer &&buf) { }

void CZ_REQ_JOIN_GUILD2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PET_ACT
 */
void CZ_PET_ACT::handle(ByteBuffer &&buf) { }

void CZ_PET_ACT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CLOSE_DIALOG
 */
void CZ_CLOSE_DIALOG::handle(ByteBuffer &&buf) { }

void CZ_CLOSE_DIALOG::deserialize(ByteBuffer &buf) { }

/**
 * CZ_DORIDORI
 */
void CZ_DORIDORI::handle(ByteBuffer &&buf) { }

void CZ_DORIDORI::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SIMPLE_BUY_CASH_POINT_ITEM
 */
void CZ_SIMPLE_BUY_CASH_POINT_ITEM::handle(ByteBuffer &&buf) { }

void CZ_SIMPLE_BUY_CASH_POINT_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PC_BUY_CASH_POINT_ITEM
 */
void CZ_PC_BUY_CASH_POINT_ITEM::handle(ByteBuffer &&buf) { }

void CZ_PC_BUY_CASH_POINT_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_GUILDSTORAGE_TO_BODY
 */
void CZ_MOVE_ITEM_FROM_GUILDSTORAGE_TO_BODY::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_GUILDSTORAGE_TO_BODY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SRPACKET_START
 */
void CZ_SRPACKET_START::handle(ByteBuffer &&buf) { }

void CZ_SRPACKET_START::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SELECTAUTOSPELL
 */
void CZ_SELECTAUTOSPELL::handle(ByteBuffer &&buf) { }

void CZ_SELECTAUTOSPELL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SSILIST_ITEM_CLICK
 */
void CZ_SSILIST_ITEM_CLICK::handle(ByteBuffer &&buf) { }

void CZ_SSILIST_ITEM_CLICK::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ITEMIDENTIFY
 */
void CZ_REQ_ITEMIDENTIFY::handle(ByteBuffer &&buf) { }

void CZ_REQ_ITEMIDENTIFY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CHANGE_MEMBERPOS
 */
void CZ_REQ_CHANGE_MEMBERPOS::handle(ByteBuffer &&buf) { }

void CZ_REQ_CHANGE_MEMBERPOS::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ALLY_GUILD
 */
void CZ_REQ_ALLY_GUILD::handle(ByteBuffer &&buf) { }

void CZ_REQ_ALLY_GUILD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_OPEN_WRITE_RODEX
 */
void CZ_REQ_OPEN_WRITE_RODEX::handle(ByteBuffer &&buf) { }

void CZ_REQ_OPEN_WRITE_RODEX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CONCLUDE_EXCHANGE_ITEM
 */
void CZ_CONCLUDE_EXCHANGE_ITEM::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->trade().lock();
}

void CZ_CONCLUDE_EXCHANGE_ITEM::deserialize(ByteBuffer &buf) 
{ 
	buf >> _packet_id;
}

/**CZ_CANCEL_EXCHANGE_ITEM
 * CZ_REQUEST_QUIT
 */
void CZ_REQUEST_QUIT::handle(ByteBuffer &&buf) { }

void CZ_REQUEST_QUIT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ACH_REWARD
 */
void CZ_REQ_ACH_REWARD::handle(ByteBuffer &&buf) { }

void CZ_REQ_ACH_REWARD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQUEST_TIME
 */
void CZ_REQUEST_TIME::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->notify_time();
}

void CZ_REQUEST_TIME::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _timestamp;
}

/**
 * CZ_CHANGE_MAPTYPE
 */
void CZ_CHANGE_MAPTYPE::handle(ByteBuffer &&buf) { }

void CZ_CHANGE_MAPTYPE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_BLACKSMITH_RANK
 */
void CZ_BLACKSMITH_RANK::handle(ByteBuffer &&buf) { }

void CZ_BLACKSMITH_RANK::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MAIL_RESET_ITEM
 */
void CZ_MAIL_RESET_ITEM::handle(ByteBuffer &&buf) { }

void CZ_MAIL_RESET_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CLOSE_RODEXBOX
 */
void CZ_CLOSE_RODEXBOX::handle(ByteBuffer &&buf) { }

void CZ_CLOSE_RODEXBOX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_EXEC_EXCHANGE_ITEM
 */
void CZ_EXEC_EXCHANGE_ITEM::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->trade().commit();
}

void CZ_EXEC_EXCHANGE_ITEM::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
}

/**
 * CZ_WHISPER
 */
void CZ_WHISPER::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->whisper_message(
		_name,
		strnlen(_name, MAX_UNIT_NAME_LENGTH - 1),
		_message,
		strnlen(_message, _packet_length - 4 - MAX_UNIT_NAME_LENGTH)
	);
	delete[] _message;
}

void CZ_WHISPER::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _packet_length;
	buf.read(_name, MAX_UNIT_NAME_LENGTH);
	_message = new char[_packet_length - 4 - MAX_UNIT_NAME_LENGTH];
	buf.read(_message, _packet_length - 4 - MAX_UNIT_NAME_LENGTH);
}

/**
 * CZ_REQ_RANKING
 */
void CZ_REQ_RANKING::handle(ByteBuffer &&buf) { }

void CZ_REQ_RANKING::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_MAKE_GUILD
 */
void CZ_REQ_MAKE_GUILD::handle(ByteBuffer &&buf) { }

void CZ_REQ_MAKE_GUILD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MAKE_GROUP2
 */
void CZ_MAKE_GROUP2::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().create(_party_name, _item_pickup_rule, _item_share_rule);
}

void CZ_MAKE_GROUP2::deserialize(ByteBuffer &buf) 
{ 
	buf >> _packet_id;
	buf.read(_party_name, MAX_PARTY_NAME_LENGTH);
	buf >> _item_pickup_rule;
	buf >> _item_share_rule;
}

/**
 * CZ_ALLY_GUILD
 */
void CZ_ALLY_GUILD::handle(ByteBuffer &&buf) { }

void CZ_ALLY_GUILD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_USE_SKILL2
 */
void CZ_USE_SKILL2::handle(ByteBuffer &&buf) { }

void CZ_USE_SKILL2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ROLE_CHANGE
 */
void CZ_REQ_ROLE_CHANGE::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->chatroom().role_change(_role, _name);
}

void CZ_REQ_ROLE_CHANGE::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _role;
	buf.read(_name, MAX_UNIT_NAME_LENGTH);
}

/**
 * CZ_REPLY_LOBBY_ADMISSION
 */
void CZ_REPLY_LOBBY_ADMISSION::handle(ByteBuffer &&buf) { }

void CZ_REPLY_LOBBY_ADMISSION::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_GENERATE_ROULETTE
 */
void CZ_REQ_GENERATE_ROULETTE::handle(ByteBuffer &&buf) { }

void CZ_REQ_GENERATE_ROULETTE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CHANGE_CHATROOM
 */
void CZ_CHANGE_CHATROOM::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
}

void CZ_CHANGE_CHATROOM::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _packet_length;
	buf >> _limit;
	buf >> _type;
	buf.read(_password, CHATROOM_PASS_SIZE);
	buf.read(_title, CHATROOM_TITLE_SIZE);
}

/**
 * CZ_USE_SKILL_NEW_JAPEN
 */
void CZ_USE_SKILL_NEW_JAPEN::handle(ByteBuffer &&buf) { }

void CZ_USE_SKILL_NEW_JAPEN::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ITEM_THROW2
 */
void CZ_ITEM_THROW2::handle(ByteBuffer &&buf) { }

void CZ_ITEM_THROW2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_BOT_CHECK
 */
void CZ_BOT_CHECK::handle(ByteBuffer &&buf) { }

void CZ_BOT_CHECK::deserialize(ByteBuffer &buf) { }

/**
 * CZ_NPC_BARTER_PURCHASE
 */
void CZ_NPC_BARTER_PURCHASE::handle(ByteBuffer &&buf) { }

void CZ_NPC_BARTER_PURCHASE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CLOSE_SEARCH_STORE_INFO
 */
void CZ_CLOSE_SEARCH_STORE_INFO::handle(ByteBuffer &&buf) { }

void CZ_CLOSE_SEARCH_STORE_INFO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQUEST_ACT2
 */
void CZ_REQUEST_ACT2::handle(ByteBuffer &&buf) 
{
    deserialize(buf);
    get_session()->clif()->action_request(_target_guid, (player_action_type) _action);
}

void CZ_REQUEST_ACT2::deserialize(ByteBuffer &buf) 
{
    buf >> _packet_id;
    buf >> _target_guid;
    buf >> _action;
}

/**
 * CZ_INVENTORY_EXPAND
 */
void CZ_INVENTORY_EXPAND::handle(ByteBuffer &&buf) { }

void CZ_INVENTORY_EXPAND::deserialize(ByteBuffer &buf) { }

/**
 * CZ_LESSEFFECT
 */
void CZ_LESSEFFECT::handle(ByteBuffer &&buf) { }

void CZ_LESSEFFECT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SEEK_PARTY_MEMBER
 */
void CZ_SEEK_PARTY_MEMBER::handle(ByteBuffer &&buf) { }

void CZ_SEEK_PARTY_MEMBER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ENTER_ROOM
 */
void CZ_REQ_ENTER_ROOM::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->chatroom().add_member(_chat_id, _password);
}

void CZ_REQ_ENTER_ROOM::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _chat_id;
	buf.read(_password, CHATROOM_PASS_SIZE);
}

/**
 * CZ_CANCEL_LOCKON
 */
void CZ_CANCEL_LOCKON::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->stop_attack();
}

void CZ_CANCEL_LOCKON::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
}

/**
 * CZ_REQUEST_CHAT
 */
void CZ_REQUEST_CHAT::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->parse_chat_message(_message);
}

void CZ_REQUEST_CHAT::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _packet_length;

	int str_len = _packet_length - 4;
	_message = new char[str_len + 1];
	_message[str_len] = '\0';
	buf.read(_message, str_len);
}

/**
 * CZ_REQNAME_BYGID2
 */
void CZ_REQNAME_BYGID2::handle(ByteBuffer &&buf) { }

void CZ_REQNAME_BYGID2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MAIL_GET_ITEM
 */
void CZ_MAIL_GET_ITEM::handle(ByteBuffer &&buf) { }

void CZ_MAIL_GET_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQMAKINGHOMUN
 */
void CZ_REQMAKINGHOMUN::handle(ByteBuffer &&buf) { }

void CZ_REQMAKINGHOMUN::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_BANKING_CHECK
 */
void CZ_REQ_BANKING_CHECK::handle(ByteBuffer &&buf) { }

void CZ_REQ_BANKING_CHECK::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_STATUS
 */
void CZ_REQ_STATUS::handle(ByteBuffer &&buf) { }

void CZ_REQ_STATUS::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CANCEL_MERGE_ITEM
 */
void CZ_CANCEL_MERGE_ITEM::handle(ByteBuffer &&buf) { }

void CZ_CANCEL_MERGE_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_BODY_TO_CART
 */
void CZ_MOVE_ITEM_FROM_BODY_TO_CART::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_BODY_TO_CART::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MAKE_GROUP
 */
void CZ_MAKE_GROUP::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().create(_party_name, 0, 0);
}

void CZ_MAKE_GROUP::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf.read(_party_name, MAX_PARTY_NAME_LENGTH);
}

/**
 * CZ_GANGSI_RANK
 */
void CZ_GANGSI_RANK::handle(ByteBuffer &&buf) { }

void CZ_GANGSI_RANK::deserialize(ByteBuffer &buf) { }

/**
 * CZ_NPC_BARTER_CLOSE
 */
void CZ_NPC_BARTER_CLOSE::handle(ByteBuffer &&buf) { }

void CZ_NPC_BARTER_CLOSE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MER_COMMAND
 */
void CZ_MER_COMMAND::handle(ByteBuffer &&buf) { }

void CZ_MER_COMMAND::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CLOSE_ROULETTE
 */
void CZ_REQ_CLOSE_ROULETTE::handle(ByteBuffer &&buf) { }

void CZ_REQ_CLOSE_ROULETTE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CHANGE_EFFECTSTATE
 */
void CZ_CHANGE_EFFECTSTATE::handle(ByteBuffer &&buf) { }

void CZ_CHANGE_EFFECTSTATE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_AUCTION_REQ_MY_INFO
 */
void CZ_AUCTION_REQ_MY_INFO::handle(ByteBuffer &&buf) { }

void CZ_AUCTION_REQ_MY_INFO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_STOP_USE_SKILL
 */
void CZ_STOP_USE_SKILL::handle(ByteBuffer &&buf) { }

void CZ_STOP_USE_SKILL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQUEST_MOVENPC
 */
void CZ_REQUEST_MOVENPC::handle(ByteBuffer &&buf) { }

void CZ_REQUEST_MOVENPC::deserialize(ByteBuffer &buf) { }

/**
 * CZ_JOIN_GUILD
 */
void CZ_JOIN_GUILD::handle(ByteBuffer &&buf) { }

void CZ_JOIN_GUILD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_WHISPER_LIST
 */
void CZ_REQ_WHISPER_LIST::handle(ByteBuffer &&buf) { }

void CZ_REQ_WHISPER_LIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_BLOCKING_PLAY_CANCEL
 */
void CZ_BLOCKING_PLAY_CANCEL::handle(ByteBuffer &&buf) { }

void CZ_BLOCKING_PLAY_CANCEL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_INPUT_EDITDLGSTR
 */
void CZ_INPUT_EDITDLGSTR::handle(ByteBuffer &&buf) { }

void CZ_INPUT_EDITDLGSTR::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CREATE_CHATROOM
 */
void CZ_CREATE_CHATROOM::handle(ByteBuffer &&buf) 
{
	deserialize(buf);

	if (_packet_length - 15 < 1) // If title is less than size of 1.
		return;
	
	get_session()->clif()->chatroom().create_chatroom(_limit, _public, _password, _title);
}

void CZ_CREATE_CHATROOM::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _packet_length;
	buf >> _limit;
	buf >> _public;
	buf.read(_password, CHATROOM_PASS_SIZE);
	buf.read(_title, std::min((_packet_length - 16), CHATROOM_TITLE_SIZE));
}

/**
 * CZ_REQ_GIVE_MANNER_POINT
 */
void CZ_REQ_GIVE_MANNER_POINT::handle(ByteBuffer &&buf) { }

void CZ_REQ_GIVE_MANNER_POINT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CHANGE_DIRECTION2
 */
void CZ_CHANGE_DIRECTION2::handle(ByteBuffer &&buf) { }

void CZ_CHANGE_DIRECTION2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_GUILD_CHAT
 */
void CZ_GUILD_CHAT::handle(ByteBuffer &&buf) { }

void CZ_GUILD_CHAT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CHANGE_TITLE
 */
void CZ_REQ_CHANGE_TITLE::handle(ByteBuffer &&buf) { }

void CZ_REQ_CHANGE_TITLE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_DELETE_RELATED_GUILD
 */
void CZ_REQ_DELETE_RELATED_GUILD::handle(ByteBuffer &&buf) { }

void CZ_REQ_DELETE_RELATED_GUILD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_EXCHANGE_ITEM
 */
void CZ_REQ_EXCHANGE_ITEM::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->trade().request(_account_id);
}

void CZ_REQ_EXCHANGE_ITEM::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _account_id;
}

/**
 * CZ_PC_PURCHASE_ITEMLIST
 */
void CZ_PC_PURCHASE_ITEMLIST::handle(ByteBuffer &&buf) { }

void CZ_PC_PURCHASE_ITEMLIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MACRO_REQUEST_MOVE
 */
void CZ_MACRO_REQUEST_MOVE::handle(ByteBuffer &&buf) { }

void CZ_MACRO_REQUEST_MOVE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CHANGECART
 */
void CZ_REQ_CHANGECART::handle(ByteBuffer &&buf) { }

void CZ_REQ_CHANGECART::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_BUY_FROMMC
 */
void CZ_REQ_BUY_FROMMC::handle(ByteBuffer &&buf) { }

void CZ_REQ_BUY_FROMMC::deserialize(ByteBuffer &buf) { }

/**
 * CZ_INVENTORY_EXPAND_CONFIRMED
 */
void CZ_INVENTORY_EXPAND_CONFIRMED::handle(ByteBuffer &&buf) { }

void CZ_INVENTORY_EXPAND_CONFIRMED::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PETEGG_INFO
 */
void CZ_PETEGG_INFO::handle(ByteBuffer &&buf) { }

void CZ_PETEGG_INFO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CLOSE_BARGAIN_SALE_TOOL
 */
void CZ_CLOSE_BARGAIN_SALE_TOOL::handle(ByteBuffer &&buf) { }

void CZ_CLOSE_BARGAIN_SALE_TOOL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_JOIN_GROUP
 */
void CZ_JOIN_GROUP::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().invite_response(_party_id, (_response ? PARTY_INVITE_RESPONSE_ACCEPT : PARTY_INVITE_RESPONSE_REJECT));
}

void CZ_JOIN_GROUP::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _party_id;
	buf >> _response;
}

/**
 * CZ_REQ_EXPEL_GROUP_MEMBER
 */
void CZ_REQ_EXPEL_GROUP_MEMBER::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().expel_member(_account_id, _name);
}

void CZ_REQ_EXPEL_GROUP_MEMBER::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _account_id;
	buf.read(_name, MAX_UNIT_NAME_LENGTH);
}

/**
 * CZ_ACK_REQ_ADD_FRIENDS
 */
void CZ_ACK_REQ_ADD_FRIENDS::handle(ByteBuffer &&buf) { }

void CZ_ACK_REQ_ADD_FRIENDS::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_SCHEDULER_CASHITEM
 */
void CZ_REQ_SCHEDULER_CASHITEM::handle(ByteBuffer &&buf) { }

void CZ_REQ_SCHEDULER_CASHITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SRPACKETR2_START
 */
void CZ_SRPACKETR2_START::handle(ByteBuffer &&buf) { }

void CZ_SRPACKETR2_START::deserialize(ByteBuffer &buf) { }

/**
 * CZ_USE_SKILL_TOGROUND
 */
void CZ_USE_SKILL_TOGROUND::handle(ByteBuffer &&buf) { }

void CZ_USE_SKILL_TOGROUND::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CLICK_TO_BUYING_STORE
 */
void CZ_REQ_CLICK_TO_BUYING_STORE::handle(ByteBuffer &&buf) { }

void CZ_REQ_CLICK_TO_BUYING_STORE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_USE_ITEM_NEW_JAPEN
 */
void CZ_USE_ITEM_NEW_JAPEN::handle(ByteBuffer &&buf) { }

void CZ_USE_ITEM_NEW_JAPEN::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_RECRUIT_SHOW_EQUIPMENT
 */
void CZ_PARTY_RECRUIT_SHOW_EQUIPMENT::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_SHOW_EQUIPMENT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CONTACTNPC
 */
void CZ_CONTACTNPC::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->npc_contact(_guid);
}

void CZ_CONTACTNPC::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _guid;
	buf >> _type;
}

/**
 * CZ_OPEN_SIMPLE_CASHSHOP_ITEMLIST
 */
void CZ_OPEN_SIMPLE_CASHSHOP_ITEMLIST::handle(ByteBuffer &&buf) { }

void CZ_OPEN_SIMPLE_CASHSHOP_ITEMLIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_WEAR_EQUIP_V5
 */
void CZ_REQ_WEAR_EQUIP_V5::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->equip_item(_inventory_index, _equip_location_mask);
}

void CZ_REQ_WEAR_EQUIP_V5::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _inventory_index;
	buf >> _equip_location_mask;
}

/**
 * CZ_REFINE_ADD_ITEM
 */
void CZ_REFINE_ADD_ITEM::handle(ByteBuffer &&buf) { }

void CZ_REFINE_ADD_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_OPEN_UI
 */
void CZ_REQ_OPEN_UI::handle(ByteBuffer &&buf) { }

void CZ_REQ_OPEN_UI::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQUEST_CHAT_PARTY
 */
void CZ_REQUEST_CHAT_PARTY::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().send_message(_packet_length, _message);
}

void CZ_REQUEST_CHAT_PARTY::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _packet_length;
	buf.read(_message, MAX_CHAT_STR_LENGTH + MAX_UNIT_NAME_LENGTH + 3 + 1);
}

/**
 * CZ_MOVE_ITEM_FROM_STORE_TO_BODY
 */
void CZ_MOVE_ITEM_FROM_STORE_TO_BODY::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_STORE_TO_BODY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_GUILD_MEMBER_INFO
 */
void CZ_REQ_GUILD_MEMBER_INFO::handle(ByteBuffer &&buf) { }

void CZ_REQ_GUILD_MEMBER_INFO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQUEST_MOVE_NEW_JAPEN
 */
void CZ_REQUEST_MOVE_NEW_JAPEN::handle(ByteBuffer &&buf) { }

void CZ_REQUEST_MOVE_NEW_JAPEN::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_RECRUIT_ADD_FILTERLINGLIST
 */
void CZ_PARTY_RECRUIT_ADD_FILTERLINGLIST::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_ADD_FILTERLINGLIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_BAN_GUILD
 */
void CZ_REQ_BAN_GUILD::handle(ByteBuffer &&buf) { }

void CZ_REQ_BAN_GUILD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CHANGE_DIRECTION
 */
void CZ_CHANGE_DIRECTION::handle(ByteBuffer &&buf) { }

void CZ_CHANGE_DIRECTION::deserialize(ByteBuffer &buf) { }

/**
 * CZ_AUCTION_BUY
 */
void CZ_AUCTION_BUY::handle(ByteBuffer &&buf) { }

void CZ_AUCTION_BUY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_RECALL_GID
 */
void CZ_RECALL_GID::handle(ByteBuffer &&buf) { }

void CZ_RECALL_GID::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ITEM_FROM_RODEX
 */
void CZ_REQ_ITEM_FROM_RODEX::handle(ByteBuffer &&buf) { }

void CZ_REQ_ITEM_FROM_RODEX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_STATUS_GM
 */
void CZ_REQ_STATUS_GM::handle(ByteBuffer &&buf) { }

void CZ_REQ_STATUS_GM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CLOSE_SIMPLECASH_SHOP
 */
void CZ_CLOSE_SIMPLECASH_SHOP::handle(ByteBuffer &&buf) { }

void CZ_CLOSE_SIMPLECASH_SHOP::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MAIL_SEND
 */
void CZ_MAIL_SEND::handle(ByteBuffer &&buf) { }

void CZ_MAIL_SEND::deserialize(ByteBuffer &buf) { }

/**
 * CZ_RECV_ROULETTE_ITEM
 */
void CZ_RECV_ROULETTE_ITEM::handle(ByteBuffer &&buf) { }

void CZ_RECV_ROULETTE_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_WEAPONREFINE
 */
void CZ_REQ_WEAPONREFINE::handle(ByteBuffer &&buf) { }

void CZ_REQ_WEAPONREFINE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ACK_EXCHANGE_ITEM
 */
void CZ_ACK_EXCHANGE_ITEM::handle(ByteBuffer &&buf)\
{
	deserialize(buf);
	get_session()->clif()->trade().response(_result);
}

void CZ_ACK_EXCHANGE_ITEM::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _result;
}

/**
 * CZ_ITEMLISTWIN_RES
 */
void CZ_ITEMLISTWIN_RES::handle(ByteBuffer &&buf) { }

void CZ_ITEMLISTWIN_RES::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CLOSE_GUILD_STORAGE
 */
void CZ_REQ_CLOSE_GUILD_STORAGE::handle(ByteBuffer &&buf) { }

void CZ_REQ_CLOSE_GUILD_STORAGE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_TRYCOLLECTION
 */
void CZ_TRYCOLLECTION::handle(ByteBuffer &&buf) { }

void CZ_TRYCOLLECTION::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_OPEN_MEMBER_INFO
 */
void CZ_REQ_OPEN_MEMBER_INFO::handle(ByteBuffer &&buf) { }

void CZ_REQ_OPEN_MEMBER_INFO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_REMOVE_RODEX_ITEM
 */
void CZ_REQ_REMOVE_RODEX_ITEM::handle(ByteBuffer &&buf) { }

void CZ_REQ_REMOVE_RODEX_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_INVENTORY_TAB
 */
void CZ_INVENTORY_TAB::handle(ByteBuffer &&buf) { }

void CZ_INVENTORY_TAB::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MACRO_ITEM_PICKUP
 */
void CZ_MACRO_ITEM_PICKUP::handle(ByteBuffer &&buf) { }

void CZ_MACRO_ITEM_PICKUP::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQNAME2
 */
void CZ_REQNAME2::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->notify_entity_name(_guid);
}

void CZ_REQNAME2::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _guid;
}

/**
 * CZ_CLOSE_STORE
 */
void CZ_CLOSE_STORE::handle(ByteBuffer &&buf) { }

void CZ_CLOSE_STORE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_CLOSESTORE
 */
void CZ_REQ_CLOSESTORE::handle(ByteBuffer &&buf) { }

void CZ_REQ_CLOSESTORE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_SE_CASH_TAB_CODE
 */
void CZ_REQ_SE_CASH_TAB_CODE::handle(ByteBuffer &&buf) { }

void CZ_REQ_SE_CASH_TAB_CODE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ITEM_CREATE
 */
void CZ_ITEM_CREATE::handle(ByteBuffer &&buf) { }

void CZ_ITEM_CREATE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_OFFLINE_STORE_CREATE
 */
void CZ_OFFLINE_STORE_CREATE::handle(ByteBuffer &&buf) { }

void CZ_OFFLINE_STORE_CREATE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SEEK_PARTY
 */
void CZ_SEEK_PARTY::handle(ByteBuffer &&buf) { }

void CZ_SEEK_PARTY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CONFIG
 */
void CZ_CONFIG::handle(ByteBuffer &&buf) { }

void CZ_CONFIG::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ITEM_THROW
 */
void CZ_ITEM_THROW::handle(ByteBuffer &&buf) { }

void CZ_ITEM_THROW::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_CART_TO_BODY
 */
void CZ_MOVE_ITEM_FROM_CART_TO_BODY::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_CART_TO_BODY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PC_PURCHASE_ITEMLIST_FROMMC2
 */
void CZ_PC_PURCHASE_ITEMLIST_FROMMC2::handle(ByteBuffer &&buf) { }

void CZ_PC_PURCHASE_ITEMLIST_FROMMC2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_ITEMCOMPOSITION
 */
void CZ_REQ_ITEMCOMPOSITION::handle(ByteBuffer &&buf) { }

void CZ_REQ_ITEMCOMPOSITION::deserialize(ByteBuffer &buf) { }

/**
 * CZ_DISCONNECT_ALL_CHARACTER
 */
void CZ_DISCONNECT_ALL_CHARACTER::handle(ByteBuffer &&buf) { }

void CZ_DISCONNECT_ALL_CHARACTER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SELECTCART
 */
void CZ_SELECTCART::handle(ByteBuffer &&buf) { }

void CZ_SELECTCART::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQMAKINGITEM
 */
void CZ_REQMAKINGITEM::handle(ByteBuffer &&buf) { }

void CZ_REQMAKINGITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_EXPEL_MEMBER
 */
void CZ_REQ_EXPEL_MEMBER::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->chatroom().expel_member(_name);
}

void CZ_REQ_EXPEL_MEMBER::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf.read(_name, MAX_UNIT_NAME_LENGTH);
}

/**
 * CZ_USE_SKILL_TOGROUND_WITHTALKBOX
 */
void CZ_USE_SKILL_TOGROUND_WITHTALKBOX::handle(ByteBuffer &&buf) { }

void CZ_USE_SKILL_TOGROUND_WITHTALKBOX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_HUNTINGLIST
 */
void CZ_HUNTINGLIST::handle(ByteBuffer &&buf) { }

void CZ_HUNTINGLIST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_MERGE_ITEM
 */
void CZ_REQ_MERGE_ITEM::handle(ByteBuffer &&buf) { }

void CZ_REQ_MERGE_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_PVPPOINT
 */
void CZ_REQ_PVPPOINT::handle(ByteBuffer &&buf) { }

void CZ_REQ_PVPPOINT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_HACKSH_CPX_MSG
 */
void CZ_HACKSH_CPX_MSG::handle(ByteBuffer &&buf) { }

void CZ_HACKSH_CPX_MSG::deserialize(ByteBuffer &buf) { }

/**
 * CZ_USE_ITEM
 */
void CZ_USE_ITEM::handle(ByteBuffer &&buf)
{
	deserialize(buf);
	get_session()->clif()->use_item(_inventory_index, _guid);
}

void CZ_USE_ITEM::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _inventory_index;
	buf >> _guid;
}

/**
 * CZ_BATTLEFIELD_CHAT
 */
void CZ_BATTLEFIELD_CHAT::handle(ByteBuffer &&buf) { }

void CZ_BATTLEFIELD_CHAT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CHOOSE_MENU
 */
void CZ_CHOOSE_MENU::handle(ByteBuffer &&buf) { }

void CZ_CHOOSE_MENU::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_READ_RODEX
 */
void CZ_REQ_READ_RODEX::handle(ByteBuffer &&buf) { }

void CZ_REQ_READ_RODEX::deserialize(ByteBuffer &buf) { }

/**
 * CZ_GPK_AUTH
 */
void CZ_GPK_AUTH::handle(ByteBuffer &&buf) { }

void CZ_GPK_AUTH::deserialize(ByteBuffer &buf) { }

/**
 * CZ_KILLER_RANK
 */
void CZ_KILLER_RANK::handle(ByteBuffer &&buf) { }

void CZ_KILLER_RANK::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_MAKINGARROW
 */
void CZ_REQ_MAKINGARROW::handle(ByteBuffer &&buf) { }

void CZ_REQ_MAKINGARROW::deserialize(ByteBuffer &buf) { }

/**
 * CZ_CHOPOKGI
 */
void CZ_CHOPOKGI::handle(ByteBuffer &&buf) { }

void CZ_CHOPOKGI::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_BOOKING_REQ_DELETE
 */
void CZ_PARTY_BOOKING_REQ_DELETE::handle(ByteBuffer &&buf) { }

void CZ_PARTY_BOOKING_REQ_DELETE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_DYNAMICNPC_CREATE_REQUEST
 */
void CZ_DYNAMICNPC_CREATE_REQUEST::handle(ByteBuffer &&buf) { }

void CZ_DYNAMICNPC_CREATE_REQUEST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_RECRUIT_REQ_DELETE
 */
void CZ_PARTY_RECRUIT_REQ_DELETE::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_REQ_DELETE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MAIL_DELETE
 */
void CZ_MAIL_DELETE::handle(ByteBuffer &&buf) { }

void CZ_MAIL_DELETE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_RECALL_SSO
 */
void CZ_RECALL_SSO::handle(ByteBuffer &&buf) { }

void CZ_RECALL_SSO::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ALCHEMIST_RANK
 */
void CZ_ALCHEMIST_RANK::handle(ByteBuffer &&buf) { }

void CZ_ALCHEMIST_RANK::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQUEST_ACTNPC
 */
void CZ_REQUEST_ACTNPC::handle(ByteBuffer &&buf) { }

void CZ_REQUEST_ACTNPC::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQNAME
 */
void CZ_REQNAME::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->notify_entity_name(_guid);
}

void CZ_REQNAME::deserialize(ByteBuffer &buf)
{
	buf >> _packet_id;
	buf >> _guid;
}

/**
 * CZ_CLAN_CHAT
 */
void CZ_CLAN_CHAT::handle(ByteBuffer &&buf) { }

void CZ_CLAN_CHAT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_EXIT_ROOM
 */
void CZ_EXIT_ROOM::handle(ByteBuffer &&buf) 
{ 
	deserialize(buf);
	get_session()->clif()->chatroom().leave();
}

void CZ_EXIT_ROOM::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
}

/**
 * CZ_UPGRADE_SKILLLEVEL
 */
void CZ_UPGRADE_SKILLLEVEL::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->upgrade_skill_level(_skill_id);
}

void CZ_UPGRADE_SKILLLEVEL::deserialize(ByteBuffer &buf) 
{
	buf >> _packet_id;
	buf >> _skill_id;
}

/**
 * CZ_REQ_OPEN_ROULETTE
 */
void CZ_REQ_OPEN_ROULETTE::handle(ByteBuffer &&buf) { }

void CZ_REQ_OPEN_ROULETTE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_MAKINGITEM
 */
void CZ_REQ_MAKINGITEM::handle(ByteBuffer &&buf) { }

void CZ_REQ_MAKINGITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_NPC_MARKET_CLOSE
 */
void CZ_NPC_MARKET_CLOSE::handle(ByteBuffer &&buf) { }

void CZ_NPC_MARKET_CLOSE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_USE_SKILL_TOGROUND_WITHTALKBOX2
 */
void CZ_USE_SKILL_TOGROUND_WITHTALKBOX2::handle(ByteBuffer &&buf) { }

void CZ_USE_SKILL_TOGROUND_WITHTALKBOX2::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SKILL_SELECT_RESPONSE
 */
void CZ_SKILL_SELECT_RESPONSE::handle(ByteBuffer &&buf) { }

void CZ_SKILL_SELECT_RESPONSE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MACRO_REQUEST_ACT
 */
void CZ_MACRO_REQUEST_ACT::handle(ByteBuffer &&buf) { }

void CZ_MACRO_REQUEST_ACT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_IRMAIL_SEND
 */
void CZ_IRMAIL_SEND::handle(ByteBuffer &&buf) { }

void CZ_IRMAIL_SEND::deserialize(ByteBuffer &buf) { }

/**
 * CZ_MOVE_ITEM_FROM_BODY_TO_GUILDSTORAGE
 */
void CZ_MOVE_ITEM_FROM_BODY_TO_GUILDSTORAGE::handle(ByteBuffer &&buf) { }

void CZ_MOVE_ITEM_FROM_BODY_TO_GUILDSTORAGE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_APPLY_BARGAIN_SALE_ITEM
 */
void CZ_REQ_APPLY_BARGAIN_SALE_ITEM::handle(ByteBuffer &&buf) { }

void CZ_REQ_APPLY_BARGAIN_SALE_ITEM::deserialize(ByteBuffer &buf) { }

/**
 * CZ_OPEN_BARGAIN_SALE_TOOL
 */
void CZ_OPEN_BARGAIN_SALE_TOOL::handle(ByteBuffer &&buf) { }

void CZ_OPEN_BARGAIN_SALE_TOOL::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SE_CASHSHOP_OPEN
 */
void CZ_SE_CASHSHOP_OPEN::handle(ByteBuffer &&buf) { }

void CZ_SE_CASHSHOP_OPEN::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REMEMBER_WARPPOINT
 */
void CZ_REMEMBER_WARPPOINT::handle(ByteBuffer &&buf) { }

void CZ_REMEMBER_WARPPOINT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_GAMEGUARD_LINGO_READY
 */
void CZ_GAMEGUARD_LINGO_READY::handle(ByteBuffer &&buf) { }

void CZ_GAMEGUARD_LINGO_READY::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_JOIN_COUPLE
 */
void CZ_REQ_JOIN_COUPLE::handle(ByteBuffer &&buf) { }

void CZ_REQ_JOIN_COUPLE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ACK_STORE_PASSWORD
 */
void CZ_ACK_STORE_PASSWORD::handle(ByteBuffer &&buf) { }

void CZ_ACK_STORE_PASSWORD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ES_CHOOSE
 */
void CZ_ES_CHOOSE::handle(ByteBuffer &&buf) { }

void CZ_ES_CHOOSE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_SELECT_WARPPOINT
 */
void CZ_SELECT_WARPPOINT::handle(ByteBuffer &&buf) { }

void CZ_SELECT_WARPPOINT::deserialize(ByteBuffer &buf) { }

/**
 * CZ_PARTY_RECRUIT_REFUSE_VOLUNTEER
 */
void CZ_PARTY_RECRUIT_REFUSE_VOLUNTEER::handle(ByteBuffer &&buf) { }

void CZ_PARTY_RECRUIT_REFUSE_VOLUNTEER::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_DISORGANIZE_GUILD
 */
void CZ_REQ_DISORGANIZE_GUILD::handle(ByteBuffer &&buf) { }

void CZ_REQ_DISORGANIZE_GUILD::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ACTIVE_QUEST
 */
void CZ_ACTIVE_QUEST::handle(ByteBuffer &&buf) { }

void CZ_ACTIVE_QUEST::deserialize(ByteBuffer &buf) { }

/**
 * CZ_ACK_SELECT_DEALTYPE
 */
void CZ_ACK_SELECT_DEALTYPE::handle(ByteBuffer &&buf) { }

void CZ_ACK_SELECT_DEALTYPE::deserialize(ByteBuffer &buf) { }

/**
 * CZ_REQ_BATTLE_STATE_MONITOR
 */
void CZ_REQ_BATTLE_STATE_MONITOR::handle(ByteBuffer &&buf) { }

void CZ_REQ_BATTLE_STATE_MONITOR::deserialize(ByteBuffer &buf) { }

/**
 * CZ_GROUPINFO_CHANGE_V2
 */
void CZ_GROUPINFO_CHANGE_V2::handle(ByteBuffer &&buf) 
{
	deserialize(buf);
	get_session()->clif()->party().change_properties(_exp_share_rule, _item_pickup_rule, _item_share_rule);
}

void CZ_GROUPINFO_CHANGE_V2::deserialize(ByteBuffer& buf)
{
	buf >> _packet_id;
	buf >> _exp_share_rule;
	buf >> _item_pickup_rule;
	buf >> _item_share_rule;
}

/**
 * CZ_TAEKWON_RANK
 */
void CZ_TAEKWON_RANK::handle(ByteBuffer &&buf) { }

void CZ_TAEKWON_RANK::deserialize(ByteBuffer &buf) { }

