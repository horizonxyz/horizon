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

#ifndef HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080820
#define HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080820

#include "Core/Multithreading/LockedLookupTable.hpp"

#include "Default.hpp"

#include <utility>

namespace Horizon
{
namespace Zone
{
/**
 * @brief Client Packet Length Table object that stores
 * the packet length of each packet of this client version.
 * Packets with IDs already existent in the database are over-written.
 * The data is stored in a thread-safe lookup table.
 * RAII techinque ensures that the table is populated on instantiation.
 */
class ClientPacketLengthTable : public PacketLengthTable
{
public:
	ClientPacketLengthTable(std::shared_ptr<ZoneSession> s)
	: PacketLengthTable(s)
	{
#define ADD_HPKT(i, j, k) _hpacket_length_table.insert(i, std::make_pair(j, std::make_shared<k>(s)))
#define ADD_TPKT(i, j, k) _tpacket_length_table.insert(i, std::make_pair(j, std::make_shared<k>(s)))
		ADD_HPKT(0x0208, -1, CZ_ACK_REQ_ADD_FRIENDS);
		ADD_HPKT(0x00c5, 2, CZ_ACK_SELECT_DEALTYPE);
		ADD_HPKT(0x00e8, -1, CZ_ADD_EXCHANGE_ITEM);
		ADD_HPKT(0x0202, -1, CZ_ADD_FRIENDS);
		ADD_HPKT(0x0218, -1, CZ_ALCHEMIST_RANK);
		ADD_HPKT(0x0217, 55, CZ_BLACKSMITH_RANK);
		ADD_HPKT(0x00ed, 53, CZ_CANCEL_EXCHANGE_ITEM);
		ADD_HPKT(0x00de, -1, CZ_CHANGE_CHATROOM);
		ADD_HPKT(0x019d, -1, CZ_CHANGE_EFFECTSTATE);
		ADD_HPKT(0x0102, -1, CZ_CHANGE_GROUPEXPOPTION);
		ADD_HPKT(0x00b8, -1, CZ_CHOOSE_MENU);
		ADD_HPKT(0x01ed, 31, CZ_CHOPOKGI);
		ADD_HPKT(0x0146, 3, CZ_CLOSE_DIALOG);
		ADD_HPKT(0x0090, -1, CZ_CONTACTNPC);
		ADD_HPKT(0x00d5, -1, CZ_CREATE_CHATROOM);
		ADD_HPKT(0x00ce, -1, CZ_DISCONNECT_ALL_CHARACTER);
		ADD_HPKT(0x01e7, 4, CZ_DORIDORI);
		ADD_HPKT(0x00ef, -1, CZ_EXEC_EXCHANGE_ITEM);
		ADD_HPKT(0x017e, 4, CZ_GUILD_CHAT);
		ADD_HPKT(0x016e, 12, CZ_GUILD_NOTICE);
		ADD_HPKT(0x0143, -1, CZ_INPUT_EDITDLG);
		ADD_HPKT(0x02f6, 22, CZ_IRMAIL_LIST);
		ADD_HPKT(0x02f3, 2, CZ_IRMAIL_SEND);
		ADD_HPKT(0x013f, -1, CZ_ITEM_CREATE);
		ADD_HPKT(0x0362, 34, CZ_ITEM_PICKUP2);
		ADD_HPKT(0x0237, -1, CZ_KILLER_RANK);
		ADD_HPKT(0x00f9, 3, CZ_MAKE_GROUP);
		ADD_HPKT(0x0140, -1, CZ_MOVETO_MAP);
		ADD_HPKT(0x0127, -1, CZ_MOVE_ITEM_FROM_CART_TO_BODY);
		ADD_HPKT(0x0365, -1, CZ_MOVE_ITEM_FROM_STORE_TO_BODY2);
		ADD_HPKT(0x0128, 30, CZ_MOVE_ITEM_FROM_STORE_TO_CART);
		ADD_HPKT(0x007d, -1, CZ_NOTIFY_ACTORINIT);
		ADD_HPKT(0x0134, 39, CZ_PC_PURCHASE_ITEMLIST_FROMMC);
		ADD_HPKT(0x00c9, 2, CZ_PC_SELL_ITEMLIST);
		ADD_HPKT(0x01bc, -1, CZ_RECALL);
		ADD_HPKT(0x01bd, -1, CZ_RECALL_GID);
		ADD_HPKT(0x011d, 24, CZ_REMEMBER_WARPPOINT);
		ADD_HPKT(0x018e, 6, CZ_REQMAKINGITEM);
		ADD_HPKT(0x0368, 4, CZ_REQNAME2);
		ADD_HPKT(0x0108, 8, CZ_REQUEST_CHAT_PARTY);
		ADD_HPKT(0x0360, 12, CZ_REQUEST_TIME2);
		ADD_HPKT(0x0130, 6, CZ_REQ_BUY_FROMMC);
		ADD_HPKT(0x012e, 3, CZ_REQ_CLOSESTORE);
		ADD_HPKT(0x00bf, 6, CZ_REQ_EMOTION);
		ADD_HPKT(0x00d9, 10, CZ_REQ_ENTER_ROOM);
		ADD_HPKT(0x00e4, 31, CZ_REQ_EXCHANGE_ITEM);
		ADD_HPKT(0x00e2, 6, CZ_REQ_EXPEL_MEMBER);
		ADD_HPKT(0x014d, 27, CZ_REQ_GUILD_MENUINTERFACE);
		ADD_HPKT(0x017a, -1, CZ_REQ_ITEMCOMPOSITION_LIST);
		ADD_HPKT(0x0178, 90, CZ_REQ_ITEMIDENTIFY);
		ADD_HPKT(0x00fc, -1, CZ_REQ_JOIN_GROUP);
		ADD_HPKT(0x0100, -1, CZ_REQ_LEAVE_GROUP);
		ADD_HPKT(0x0159, 26, CZ_REQ_LEAVE_GUILD);
		ADD_HPKT(0x0165, 6, CZ_REQ_MAKE_GUILD);
		ADD_HPKT(0x01ae, 27, CZ_REQ_MAKINGARROW);
		ADD_HPKT(0x00e0, -1, CZ_REQ_ROLE_CHANGE);
		ADD_HPKT(0x00c1, -1, CZ_REQ_USER_COUNT);
		ADD_HPKT(0x00a9, 11, CZ_REQ_WEAR_EQUIP);
		ADD_HPKT(0x00b2, 14, CZ_RESTART);
		ADD_HPKT(0x01ce, -1, CZ_SELECTAUTOSPELL);
		ADD_HPKT(0x01a7, 10, CZ_SELECT_PETEGG);
		ADD_HPKT(0x011b, 23, CZ_SELECT_WARPPOINT);
		ADD_HPKT(0x00cf, 2, CZ_SETTING_WHISPER_PC);
		ADD_HPKT(0x00d0, -1, CZ_SETTING_WHISPER_STATE);
		ADD_HPKT(0x01bb, 2, CZ_SHIFT);
		ADD_HPKT(0x0112, 9, CZ_UPGRADE_SKILLLEVEL);
		ADD_HPKT(0x0366, 6, CZ_USE_SKILL_TOGROUND2);
		ADD_HPKT(0x0367, 282, CZ_USE_SKILL_TOGROUND_WITHTALKBOX2);
		ADD_HPKT(0x0096, -1, CZ_WHISPER);
		ADD_TPKT(0x0073, 15, ZC_ACCEPT_ENTER);
		ADD_TPKT(0x0083, -1, ZC_ACCEPT_QUIT);
		ADD_TPKT(0x00ea, 2, ZC_ACK_ADD_EXCHANGE_ITEM);
		ADD_TPKT(0x00d6, -1, ZC_ACK_CREATE_CHATROOM);
		ADD_TPKT(0x015e, 30, ZC_ACK_DISORGANIZE_GUILD_RESULT);
		ADD_TPKT(0x00e7, 44, ZC_ACK_EXCHANGE_ITEM);
		ADD_TPKT(0x01f5, -1, ZC_ACK_EXCHANGE_ITEM2);
		ADD_TPKT(0x0179, -1, ZC_ACK_ITEMIDENTIFY);
		ADD_TPKT(0x0188, 8, ZC_ACK_ITEMREFINING);
		ADD_TPKT(0x01fe, 30, ZC_ACK_ITEMREPAIR);
		ADD_TPKT(0x015a, 28, ZC_ACK_LEAVE_GUILD);
		ADD_TPKT(0x00fa, -1, ZC_ACK_MAKE_GROUP);
		ADD_TPKT(0x018f, 18, ZC_ACK_REQMAKINGITEM);
		ADD_TPKT(0x0095, 58, ZC_ACK_REQNAME);
		ADD_TPKT(0x0194, -1, ZC_ACK_REQNAME_BYGID);
		ADD_TPKT(0x018b, 3, ZC_ACK_REQ_DISCONNECT);
		ADD_TPKT(0x0169, 5, ZC_ACK_REQ_JOIN_GUILD);
		ADD_TPKT(0x0110, 3, ZC_ACK_TOUSESKILL);
		ADD_TPKT(0x0098, -1, ZC_ACK_WHISPER);
		ADD_TPKT(0x013b, 11, ZC_ACTION_FAILURE);
		ADD_TPKT(0x0209, 20, ZC_ADD_FRIENDS_LIST);
		ADD_TPKT(0x0124, 282, ZC_ADD_ITEM_TO_CART);
		ADD_TPKT(0x01c5, 6, ZC_ADD_ITEM_TO_CART2);
		ADD_TPKT(0x00f4, -1, ZC_ADD_ITEM_TO_STORE);
		ADD_TPKT(0x01c4, -1, ZC_ADD_ITEM_TO_STORE2);
		ADD_TPKT(0x0104, 17, ZC_ADD_MEMBER_TO_GROUP);
		ADD_TPKT(0x01e9, -1, ZC_ADD_MEMBER_TO_GROUP2);
		ADD_TPKT(0x0111, 66, ZC_ADD_SKILL);
		ADD_TPKT(0x021c, 26, ZC_ALCHEMIST_POINT);
		ADD_TPKT(0x0139, 2, ZC_ATTACK_FAILURE_FOR_DISTANCE);
		ADD_TPKT(0x013a, 10, ZC_ATTACK_RANGE);
		ADD_TPKT(0x0163, 3, ZC_BAN_LIST);
		ADD_TPKT(0x021b, 7, ZC_BLACKSMITH_POINT);
		ADD_TPKT(0x0219, 5, ZC_BLACKSMITH_RANK);
		ADD_TPKT(0x009a, 11, ZC_BROADCAST);
		ADD_TPKT(0x01c3, 43, ZC_BROADCAST2);
		ADD_TPKT(0x0297, -1, ZC_CART_EQUIPMENT_ITEMLIST2);
		ADD_TPKT(0x0123, -1, ZC_CART_NORMAL_ITEMLIST);
		ADD_TPKT(0x01a4, -1, ZC_CHANGESTATE_PET);
		ADD_TPKT(0x00f8, 2, ZC_CLOSE_STORE);
		ADD_TPKT(0x01d2, 7, ZC_COMBODELAY);
		ADD_TPKT(0x0144, 10, ZC_COMPASS);
		ADD_TPKT(0x00ec, -1, ZC_CONCLUDE_EXCHANGE_ITEM);
		ADD_TPKT(0x0141, 2, ZC_COUPLESTATUS);
		ADD_TPKT(0x020a, 29, ZC_DELETE_FRIENDS);
		ADD_TPKT(0x0125, -1, ZC_DELETE_ITEM_FROM_CART);
		ADD_TPKT(0x00f6, -1, ZC_DELETE_ITEM_FROM_STORE);
		ADD_TPKT(0x0105, 3, ZC_DELETE_MEMBER_FROM_GROUP);
		ADD_TPKT(0x0132, -1, ZC_DISAPPEAR_ENTRY);
		ADD_TPKT(0x00c0, 79, ZC_EMOTION);
		ADD_TPKT(0x00db, 6, ZC_ENTER_ROOM);
		ADD_TPKT(0x00a4, 58, ZC_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x013c, -1, ZC_EQUIP_ARROW);
		ADD_TPKT(0x00f0, 2, ZC_EXEC_EXCHANGE_ITEM);
		ADD_TPKT(0x01a3, 8, ZC_FEED_PET);
		ADD_TPKT(0x0227, 36, ZC_GAME_GUARD);
		ADD_TPKT(0x0101, 2, ZC_GROUPINFO_CHANGE);
		ADD_TPKT(0x00fb, 6, ZC_GROUP_LIST);
		ADD_TPKT(0x01b6, 4, ZC_GUILD_INFO2);
		ADD_TPKT(0x016f, 9, ZC_GUILD_NOTICE);
		ADD_TPKT(0x0239, -1, ZC_HOSKILLINFO_UPDATE);
		ADD_TPKT(0x017b, 10, ZC_ITEMCOMPOSITION_LIST);
		ADD_TPKT(0x0177, 6, ZC_ITEMIDENTIFY_LIST);
		ADD_TPKT(0x00a1, -1, ZC_ITEM_DISAPPEAR);
		ADD_TPKT(0x009e, 6, ZC_ITEM_FALL_ENTRY);
		ADD_TPKT(0x00a0, 3, ZC_ITEM_PICKUP_ACK);
		ADD_TPKT(0x00af, -1, ZC_ITEM_THROW_ACK);
		ADD_TPKT(0x00b1, 7, ZC_LONGPAR_CHANGE);
		ADD_TPKT(0x018d, -1, ZC_MAKABLEITEMLIST);
		ADD_TPKT(0x01ad, 2, ZC_MAKINGARROW_LIST);
		ADD_TPKT(0x0154, 5, ZC_MEMBERMGR_INFO);
		ADD_TPKT(0x00dd, 2, ZC_MEMBER_EXIT);
		ADD_TPKT(0x00dc, 2, ZC_MEMBER_NEWENTRY);
		ADD_TPKT(0x00b7, -1, ZC_MENU_LIST);
		ADD_TPKT(0x018c, 7, ZC_MONSTER_INFO);
		ADD_TPKT(0x0196, 4, ZC_MSG_STATE_CHANGE);
		ADD_TPKT(0x010c, 6, ZC_MVP);
		ADD_TPKT(0x010a, -1, ZC_MVP_GETTING_ITEM);
		ADD_TPKT(0x010b, -1, ZC_MVP_GETTING_SPECIAL_EXP);
		ADD_TPKT(0x01ee, 10, ZC_NORMAL_ITEMLIST2);
		ADD_TPKT(0x008a, 7, ZC_NOTIFY_ACT);
		ADD_TPKT(0x02e1, 13, ZC_NOTIFY_ACT2);
		ADD_TPKT(0x007a, -1, ZC_NOTIFY_ACTENTRY);
		ADD_TPKT(0x0117, -1, ZC_NOTIFY_GROUNDSKILL);
		ADD_TPKT(0x0075, 2, ZC_NOTIFY_INITCHAR);
		ADD_TPKT(0x0189, -1, ZC_NOTIFY_MAPINFO);
		ADD_TPKT(0x01d6, 10, ZC_NOTIFY_MAPPROPERTY2);
		ADD_TPKT(0x0086, -1, ZC_NOTIFY_MOVE);
		ADD_TPKT(0x01da, 14, ZC_NOTIFY_MOVEENTRY2);
		ADD_TPKT(0x02ec, -1, ZC_NOTIFY_MOVEENTRY4);
		ADD_TPKT(0x0079, 5, ZC_NOTIFY_NEWENTRY);
		ADD_TPKT(0x01d9, -1, ZC_NOTIFY_NEWENTRY2);
		ADD_TPKT(0x008e, 8, ZC_NOTIFY_PLAYERCHAT);
		ADD_TPKT(0x0087, 10, ZC_NOTIFY_PLAYERMOVE);
		ADD_TPKT(0x0107, 16, ZC_NOTIFY_POSITION_TO_GROUPM);
		ADD_TPKT(0x01eb, -1, ZC_NOTIFY_POSITION_TO_GUILDM);
		ADD_TPKT(0x019a, 3, ZC_NOTIFY_RANKING);
		ADD_TPKT(0x01de, 60, ZC_NOTIFY_SKILL2);
		ADD_TPKT(0x01d8, -1, ZC_NOTIFY_STANDENTRY2);
		ADD_TPKT(0x02ee, 8, ZC_NOTIFY_STANDENTRY4);
		ADD_TPKT(0x007c, 6, ZC_NOTIFY_STANDENTRY_NPC);
		ADD_TPKT(0x007f, 53, ZC_NOTIFY_TIME);
		ADD_TPKT(0x0077, 7, ZC_NOTIFY_UPDATEPLAYER);
		ADD_TPKT(0x0093, -1, ZC_NPCACK_ENABLE);
		ADD_TPKT(0x0092, 7, ZC_NPCACK_SERVERMOVE);
		ADD_TPKT(0x01b0, 3, ZC_NPCSPRITE_CHANGE);
		ADD_TPKT(0x0142, 10, ZC_OPEN_EDITDLG);
		ADD_TPKT(0x01d4, 22, ZC_OPEN_EDITDLGSTR);
		ADD_TPKT(0x0287, -1, ZC_PC_CASH_POINT_ITEMLIST);
		ADD_TPKT(0x0133, 59, ZC_PC_PURCHASE_ITEMLIST_FROMMC);
		ADD_TPKT(0x0136, 19, ZC_PC_PURCHASE_MYITEMLIST);
		ADD_TPKT(0x00ca, 86, ZC_PC_PURCHASE_RESULT);
		ADD_TPKT(0x0135, 71, ZC_PC_PURCHASE_RESULT_FROMMC);
		ADD_TPKT(0x00c7, 6, ZC_PC_SELL_ITEMLIST);
		ADD_TPKT(0x01a6, 6, ZC_PETEGG_LIST);
		ADD_TPKT(0x01aa, 30, ZC_PET_ACT);
		ADD_TPKT(0x0166, -1, ZC_POSITION_ID_NAME_INFO);
		ADD_TPKT(0x022e, -1, ZC_PROPERTY_HOMUN);
		ADD_TPKT(0x01a2, -1, ZC_PROPERTY_PET);
		ADD_TPKT(0x00da, -1, ZC_REFUSE_ENTER_ROOM);
		ADD_TPKT(0x01fc, -1, ZC_REPAIRITEMLIST);
		ADD_TPKT(0x0207, -1, ZC_REQ_ADD_FRIENDS);
		ADD_TPKT(0x0171, 282, ZC_REQ_ALLY_GUILD);
		ADD_TPKT(0x00e5, -1, ZC_REQ_EXCHANGE_ITEM);
		ADD_TPKT(0x01f4, -1, ZC_REQ_EXCHANGE_ITEM2);
		ADD_TPKT(0x00fe, 26, ZC_REQ_JOIN_GROUP);
		ADD_TPKT(0x016a, -1, ZC_REQ_JOIN_GUILD);
		ADD_TPKT(0x023a, 26, ZC_REQ_STORE_PASSWORD);
		ADD_TPKT(0x00ac, -1, ZC_REQ_TAKEOFF_EQUIP_ACK);
		ADD_TPKT(0x00aa, 11, ZC_REQ_WEAR_EQUIP_ACK);
		ADD_TPKT(0x00b3, -1, ZC_RESTART_ACK);
		ADD_TPKT(0x023c, 4, ZC_RESULT_STORE_PASSWORD);
		ADD_TPKT(0x0148, -1, ZC_RESURRECTION);
		ADD_TPKT(0x00d7, -1, ZC_ROOM_NEWENTRY);
		ADD_TPKT(0x00b4, -1, ZC_SAY_DIALOG);
		ADD_TPKT(0x00d1, -1, ZC_SETTING_WHISPER_PC);
		ADD_TPKT(0x00d2, 9, ZC_SETTING_WHISPER_STATE);
		ADD_TPKT(0x01b3, -1, ZC_SHOW_IMAGE2);
		ADD_TPKT(0x010f, 67, ZC_SKILLINFO_LIST);
		ADD_TPKT(0x0120, -1, ZC_SKILL_DISAPPEAR);
		ADD_TPKT(0x011f, 5, ZC_SKILL_ENTRY);
		ADD_TPKT(0x01d0, -1, ZC_SPIRITS);
		ADD_TPKT(0x01e1, -1, ZC_SPIRITS2);
		ADD_TPKT(0x01d7, 8, ZC_SPRITE_CHANGE2);
		ADD_TPKT(0x020e, 4, ZC_STARSKILL);
		ADD_TPKT(0x0119, 3, ZC_STATE_CHANGE);
		ADD_TPKT(0x0229, -1, ZC_STATE_CHANGE3);
		ADD_TPKT(0x00bd, -1, ZC_STATUS);
		ADD_TPKT(0x00be, 10, ZC_STATUS_CHANGE);
		ADD_TPKT(0x00bc, 114, ZC_STATUS_CHANGE_ACK);
		ADD_TPKT(0x00a5, 3, ZC_STORE_NORMAL_ITEMLIST);
		ADD_TPKT(0x01f0, 4, ZC_STORE_NORMAL_ITEMLIST2);
		ADD_TPKT(0x0224, 4, ZC_TAEKWON_POINT);
		ADD_TPKT(0x0226, -1, ZC_TAEKWON_RANK);
		ADD_TPKT(0x016d, 67, ZC_UPDATE_CHARSTAT);
		ADD_TPKT(0x016c, -1, ZC_UPDATE_GDID);
		ADD_TPKT(0x00c2, -1, ZC_USER_COUNT);
		ADD_TPKT(0x00a8, 15, ZC_USE_ITEM_ACK);
		ADD_TPKT(0x00b5, -1, ZC_WAIT_DIALOG);
#undef ADD_TPKT
#undef ADD_HPKT
	}

	~ClientPacketLengthTable() { }

};
}
}
#endif /* HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080820 */