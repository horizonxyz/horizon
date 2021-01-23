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

#ifndef HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20090318
#define HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20090318

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
		ADD_HPKT(0x0208, 31, CZ_ACK_REQ_ADD_FRIENDS);
		ADD_HPKT(0x00c5, -1, CZ_ACK_SELECT_DEALTYPE);
		ADD_HPKT(0x0218, 28, CZ_ALCHEMIST_RANK);
		ADD_HPKT(0x0172, 10, CZ_ALLY_GUILD);
		ADD_HPKT(0x0099, -1, CZ_BROADCAST);
		ADD_HPKT(0x0118, -1, CZ_CANCEL_LOCKON);
		ADD_HPKT(0x019d, 13, CZ_CHANGE_EFFECTSTATE);
		ADD_HPKT(0x0102, 10, CZ_CHANGE_GROUPEXPOPTION);
		ADD_HPKT(0x022d, 10, CZ_COMMAND_MER);
		ADD_HPKT(0x01a1, 30, CZ_COMMAND_PET);
		ADD_HPKT(0x00eb, 15, CZ_CONCLUDE_EXCHANGE_ITEM);
		ADD_HPKT(0x0090, -1, CZ_CONTACTNPC);
		ADD_HPKT(0x00d5, 26, CZ_CREATE_CHATROOM);
		ADD_HPKT(0x0203, -1, CZ_DELETE_FRIENDS);
		ADD_HPKT(0x00ce, -1, CZ_DISCONNECT_ALL_CHARACTER);
		ADD_HPKT(0x00cc, 9, CZ_DISCONNECT_CHARACTER);
		ADD_HPKT(0x01e7, 86, CZ_DORIDORI);
		ADD_HPKT(0x0436, 8, CZ_ENTER2);
		ADD_HPKT(0x00e3, 55, CZ_EXIT_ROOM);
		ADD_HPKT(0x017e, 26, CZ_GUILD_CHAT);
		ADD_HPKT(0x01d5, 2, CZ_INPUT_EDITDLGSTR);
		ADD_HPKT(0x02f6, -1, CZ_IRMAIL_LIST);
		ADD_HPKT(0x02f3, -1, CZ_IRMAIL_SEND);
		ADD_HPKT(0x013f, -1, CZ_ITEM_CREATE);
		ADD_HPKT(0x0362, -1, CZ_ITEM_PICKUP2);
		ADD_HPKT(0x00ff, 4, CZ_JOIN_GROUP);
		ADD_HPKT(0x016b, -1, CZ_JOIN_GUILD);
		ADD_HPKT(0x019c, 8, CZ_LOCALBROADCAST);
		ADD_HPKT(0x00f9, 11, CZ_MAKE_GROUP);
		ADD_HPKT(0x0140, -1, CZ_MOVETO_MAP);
		ADD_HPKT(0x0126, 8, CZ_MOVE_ITEM_FROM_BODY_TO_CART);
		ADD_HPKT(0x0364, 30, CZ_MOVE_ITEM_FROM_BODY_TO_STORE2);
		ADD_HPKT(0x0127, -1, CZ_MOVE_ITEM_FROM_CART_TO_BODY);
		ADD_HPKT(0x0365, -1, CZ_MOVE_ITEM_FROM_STORE_TO_BODY2);
		ADD_HPKT(0x0128, 12, CZ_MOVE_ITEM_FROM_STORE_TO_CART);
		ADD_HPKT(0x00c8, -1, CZ_PC_PURCHASE_ITEMLIST);
		ADD_HPKT(0x0134, -1, CZ_PC_PURCHASE_ITEMLIST_FROMMC);
		ADD_HPKT(0x00c9, 8, CZ_PC_SELL_ITEMLIST);
		ADD_HPKT(0x01bc, 6, CZ_RECALL);
		ADD_HPKT(0x01bd, -1, CZ_RECALL_GID);
		ADD_HPKT(0x0161, 7, CZ_REG_CHANGE_GUILD_POSITIONINFO);
		ADD_HPKT(0x011d, -1, CZ_REMEMBER_WARPPOINT);
		ADD_HPKT(0x01ba, 6, CZ_REMOVE_AID);
		ADD_HPKT(0x018e, -1, CZ_REQMAKINGITEM);
		ADD_HPKT(0x0369, -1, CZ_REQNAME_BYGID2);
		ADD_HPKT(0x0437, -1, CZ_REQUEST_ACT2);
		ADD_HPKT(0x0108, 4, CZ_REQUEST_CHAT_PARTY);
		ADD_HPKT(0x035f, 67, CZ_REQUEST_MOVE2);
		ADD_HPKT(0x0232, 6, CZ_REQUEST_MOVENPC);
		ADD_HPKT(0x0234, 6, CZ_REQUEST_MOVETOOWNER);
		ADD_HPKT(0x0360, 4, CZ_REQUEST_TIME2);
		ADD_HPKT(0x0170, -1, CZ_REQ_ALLY_GUILD);
		ADD_HPKT(0x0130, 7, CZ_REQ_BUY_FROMMC);
		ADD_HPKT(0x012a, 13, CZ_REQ_CARTOFF);
		ADD_HPKT(0x0155, -1, CZ_REQ_CHANGE_MEMBERPOS);
		ADD_HPKT(0x00bf, 18, CZ_REQ_EMOTION);
		ADD_HPKT(0x00d9, 4, CZ_REQ_ENTER_ROOM);
		ADD_HPKT(0x0103, -1, CZ_REQ_EXPEL_GROUP_MEMBER);
		ADD_HPKT(0x0149, 22, CZ_REQ_GIVE_MANNER_POINT);
		ADD_HPKT(0x014f, 58, CZ_REQ_GUILD_MENU);
		ADD_HPKT(0x014d, 39, CZ_REQ_GUILD_MENUINTERFACE);
		ADD_HPKT(0x017c, 282, CZ_REQ_ITEMCOMPOSITION);
		ADD_HPKT(0x017a, 10, CZ_REQ_ITEMCOMPOSITION_LIST);
		ADD_HPKT(0x0178, -1, CZ_REQ_ITEMIDENTIFY);
		ADD_HPKT(0x01fd, -1, CZ_REQ_ITEMREPAIR);
		ADD_HPKT(0x0159, 8, CZ_REQ_LEAVE_GUILD);
		ADD_HPKT(0x01b2, 6, CZ_REQ_OPENSTORE2);
		ADD_HPKT(0x00ab, 14, CZ_REQ_TAKEOFF_EQUIP);
		ADD_HPKT(0x00c1, -1, CZ_REQ_USER_COUNT);
		ADD_HPKT(0x00a9, -1, CZ_REQ_WEAR_EQUIP);
		ADD_HPKT(0x00d3, -1, CZ_REQ_WHISPER_LIST);
		ADD_HPKT(0x00b2, -1, CZ_RESTART);
		ADD_HPKT(0x01a7, 60, CZ_SELECT_PETEGG);
		ADD_HPKT(0x011b, 24, CZ_SELECT_WARPPOINT);
		ADD_HPKT(0x00cf, 44, CZ_SETTING_WHISPER_PC);
		ADD_HPKT(0x00d0, 30, CZ_SETTING_WHISPER_STATE);
		ADD_HPKT(0x01bb, 6, CZ_SHIFT);
		ADD_HPKT(0x00bb, 7, CZ_STATUS_CHANGE);
		ADD_HPKT(0x0225, 2, CZ_TAEKWON_RANK);
		ADD_HPKT(0x019f, 53, CZ_TRYCAPTURE_MONSTER);
		ADD_HPKT(0x0112, -1, CZ_UPGRADE_SKILLLEVEL);
		ADD_HPKT(0x0438, -1, CZ_USE_SKILL2);
		ADD_HPKT(0x0366, -1, CZ_USE_SKILL_TOGROUND2);
		ADD_HPKT(0x0367, 30, CZ_USE_SKILL_TOGROUND_WITHTALKBOX2);
		ADD_HPKT(0x0096, 11, CZ_WHISPER);
		ADD_TPKT(0x0083, 65, ZC_ACCEPT_QUIT);
		ADD_TPKT(0x00ea, 6, ZC_ACK_ADD_EXCHANGE_ITEM);
		ADD_TPKT(0x00d6, -1, ZC_ACK_CREATE_CHATROOM);
		ADD_TPKT(0x017d, 28, ZC_ACK_ITEMCOMPOSITION);
		ADD_TPKT(0x0179, 3, ZC_ACK_ITEMIDENTIFY);
		ADD_TPKT(0x015a, 2, ZC_ACK_LEAVE_GUILD);
		ADD_TPKT(0x00fa, 20, ZC_ACK_MAKE_GROUP);
		ADD_TPKT(0x011e, -1, ZC_ACK_REMEMBER_WARPPOINT);
		ADD_TPKT(0x018f, -1, ZC_ACK_REQMAKINGITEM);
		ADD_TPKT(0x0195, 4, ZC_ACK_REQNAMEALL);
		ADD_TPKT(0x0194, 6, ZC_ACK_REQNAME_BYGID);
		ADD_TPKT(0x0169, 29, ZC_ACK_REQ_JOIN_GUILD);
		ADD_TPKT(0x0110, -1, ZC_ACK_TOUSESKILL);
		ADD_TPKT(0x0098, 10, ZC_ACK_WHISPER);
		ADD_TPKT(0x013b, 4, ZC_ACTION_FAILURE);
		ADD_TPKT(0x00e9, 2, ZC_ADD_EXCHANGE_ITEM);
		ADD_TPKT(0x0209, 6, ZC_ADD_FRIENDS_LIST);
		ADD_TPKT(0x0124, 8, ZC_ADD_ITEM_TO_CART);
		ADD_TPKT(0x01c5, 10, ZC_ADD_ITEM_TO_CART2);
		ADD_TPKT(0x01c4, 16, ZC_ADD_ITEM_TO_STORE2);
		ADD_TPKT(0x0104, 8, ZC_ADD_MEMBER_TO_GROUP);
		ADD_TPKT(0x01e9, 28, ZC_ADD_MEMBER_TO_GROUP2);
		ADD_TPKT(0x0111, 20, ZC_ADD_SKILL);
		ADD_TPKT(0x021a, 23, ZC_ALCHEMIST_RANK);
		ADD_TPKT(0x013a, 10, ZC_ATTACK_RANGE);
		ADD_TPKT(0x01cd, -1, ZC_AUTOSPELLLIST);
		ADD_TPKT(0x0163, 3, ZC_BAN_LIST);
		ADD_TPKT(0x01c3, -1, ZC_BROADCAST2);
		ADD_TPKT(0x00ee, 282, ZC_CANCEL_EXCHANGE_ITEM);
		ADD_TPKT(0x0123, 6, ZC_CART_NORMAL_ITEMLIST);
		ADD_TPKT(0x01ef, 9, ZC_CART_NORMAL_ITEMLIST2);
		ADD_TPKT(0x009c, -1, ZC_CHANGE_DIRECTION);
		ADD_TPKT(0x00f8, -1, ZC_CLOSE_STORE);
		ADD_TPKT(0x01d2, -1, ZC_COMBODELAY);
		ADD_TPKT(0x00ec, 27, ZC_CONCLUDE_EXCHANGE_ITEM);
		ADD_TPKT(0x01ea, 2, ZC_CONGRATULATION);
		ADD_TPKT(0x0141, 11, ZC_COUPLESTATUS);
		ADD_TPKT(0x0137, 16, ZC_DELETEITEM_FROM_MCSTORE);
		ADD_TPKT(0x0125, -1, ZC_DELETE_ITEM_FROM_CART);
		ADD_TPKT(0x00f6, -1, ZC_DELETE_ITEM_FROM_STORE);
		ADD_TPKT(0x0132, -1, ZC_DISAPPEAR_ENTRY);
		ADD_TPKT(0x00c0, 4, ZC_EMOTION);
		ADD_TPKT(0x00a4, -1, ZC_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x0295, -1, ZC_EQUIPMENT_ITEMLIST2);
		ADD_TPKT(0x013c, 30, ZC_EQUIP_ARROW);
		ADD_TPKT(0x00f0, -1, ZC_EXEC_EXCHANGE_ITEM);
		ADD_TPKT(0x022f, -1, ZC_FEED_MER);
		ADD_TPKT(0x0206, 71, ZC_FRIENDS_STATE);
		ADD_TPKT(0x00fb, -1, ZC_GROUP_LIST);
		ADD_TPKT(0x01b6, 33, ZC_GUILD_INFO2);
		ADD_TPKT(0x016f, -1, ZC_GUILD_NOTICE);
		ADD_TPKT(0x0239, 97, ZC_HOSKILLINFO_UPDATE);
		ADD_TPKT(0x02f5, 10, ZC_IRMAIL_NOTIFY);
		ADD_TPKT(0x02f4, 2, ZC_IRMAIL_SEND_RES);
		ADD_TPKT(0x0177, 5, ZC_ITEMIDENTIFY_LIST);
		ADD_TPKT(0x00a1, 4, ZC_ITEM_DISAPPEAR);
		ADD_TPKT(0x009d, -1, ZC_ITEM_ENTRY);
		ADD_TPKT(0x009e, -1, ZC_ITEM_FALL_ENTRY);
		ADD_TPKT(0x00a0, 10, ZC_ITEM_PICKUP_ACK);
		ADD_TPKT(0x029a, 15, ZC_ITEM_PICKUP_ACK2);
		ADD_TPKT(0x00af, 6, ZC_ITEM_THROW_ACK);
		ADD_TPKT(0x0238, 3, ZC_KILLER_RANK);
		ADD_TPKT(0x018d, 14, ZC_MAKABLEITEMLIST);
		ADD_TPKT(0x0154, -1, ZC_MEMBERMGR_INFO);
		ADD_TPKT(0x00dc, 3, ZC_MEMBER_NEWENTRY);
		ADD_TPKT(0x00b7, 29, ZC_MENU_LIST);
		ADD_TPKT(0x018c, -1, ZC_MONSTER_INFO);
		ADD_TPKT(0x014c, -1, ZC_MYGUILD_BASIC_INFO);
		ADD_TPKT(0x01ee, 7, ZC_NORMAL_ITEMLIST2);
		ADD_TPKT(0x008a, 7, ZC_NOTIFY_ACT);
		ADD_TPKT(0x02e1, 114, ZC_NOTIFY_ACT2);
		ADD_TPKT(0x007a, 3, ZC_NOTIFY_ACTENTRY);
		ADD_TPKT(0x0121, -1, ZC_NOTIFY_CARTITEM_COUNTINFO);
		ADD_TPKT(0x0109, 81, ZC_NOTIFY_CHAT_PARTY);
		ADD_TPKT(0x0117, 2, ZC_NOTIFY_GROUNDSKILL);
		ADD_TPKT(0x0106, 2, ZC_NOTIFY_HP_TO_GROUPM);
		ADD_TPKT(0x0189, 90, ZC_NOTIFY_MAPINFO);
		ADD_TPKT(0x0199, 67, ZC_NOTIFY_MAPPROPERTY);
		ADD_TPKT(0x01d6, 8, ZC_NOTIFY_MAPPROPERTY2);
		ADD_TPKT(0x0086, 4, ZC_NOTIFY_MOVE);
		ADD_TPKT(0x022c, -1, ZC_NOTIFY_MOVEENTRY3);
		ADD_TPKT(0x02ec, -1, ZC_NOTIFY_MOVEENTRY4);
		ADD_TPKT(0x0079, -1, ZC_NOTIFY_NEWENTRY);
		ADD_TPKT(0x01d9, 3, ZC_NOTIFY_NEWENTRY2);
		ADD_TPKT(0x02ed, 2, ZC_NOTIFY_NEWENTRY4);
		ADD_TPKT(0x0087, 3, ZC_NOTIFY_PLAYERMOVE);
		ADD_TPKT(0x019a, 14, ZC_NOTIFY_RANKING);
		ADD_TPKT(0x0114, 2, ZC_NOTIFY_SKILL);
		ADD_TPKT(0x01de, -1, ZC_NOTIFY_SKILL2);
		ADD_TPKT(0x0078, -1, ZC_NOTIFY_STANDENTRY);
		ADD_TPKT(0x01d8, 57, ZC_NOTIFY_STANDENTRY2);
		ADD_TPKT(0x022a, 26, ZC_NOTIFY_STANDENTRY3);
		ADD_TPKT(0x02ee, 5, ZC_NOTIFY_STANDENTRY4);
		ADD_TPKT(0x00f2, 8, ZC_NOTIFY_STOREITEM_COUNTINFO);
		ADD_TPKT(0x007f, 10, ZC_NOTIFY_TIME);
		ADD_TPKT(0x0080, -1, ZC_NOTIFY_VANISH);
		ADD_TPKT(0x0092, 30, ZC_NPCACK_SERVERMOVE);
		ADD_TPKT(0x01b0, 7, ZC_NPCSPRITE_CHANGE);
		ADD_TPKT(0x01d4, 6, ZC_OPEN_EDITDLGSTR);
		ADD_TPKT(0x00b0, -1, ZC_PAR_CHANGE);
		ADD_TPKT(0x01ab, 23, ZC_PAR_CHANGE_USER);
		ADD_TPKT(0x00c6, 6, ZC_PC_PURCHASE_ITEMLIST);
		ADD_TPKT(0x0133, 4, ZC_PC_PURCHASE_ITEMLIST_FROMMC);
		ADD_TPKT(0x0136, -1, ZC_PC_PURCHASE_MYITEMLIST);
		ADD_TPKT(0x00ca, 4, ZC_PC_PURCHASE_RESULT);
		ADD_TPKT(0x00c7, 54, ZC_PC_SELL_ITEMLIST);
		ADD_TPKT(0x01a6, 6, ZC_PETEGG_LIST);
		ADD_TPKT(0x0166, -1, ZC_POSITION_ID_NAME_INFO);
		ADD_TPKT(0x01fc, 8, ZC_REPAIRITEMLIST);
		ADD_TPKT(0x0207, 9, ZC_REQ_ADD_FRIENDS);
		ADD_TPKT(0x0171, -1, ZC_REQ_ALLY_GUILD);
		ADD_TPKT(0x00e5, 68, ZC_REQ_EXCHANGE_ITEM);
		ADD_TPKT(0x01f4, -1, ZC_REQ_EXCHANGE_ITEM2);
		ADD_TPKT(0x023a, -1, ZC_REQ_STORE_PASSWORD);
		ADD_TPKT(0x00aa, 8, ZC_REQ_WEAR_EQUIP_ACK);
		ADD_TPKT(0x00b3, -1, ZC_RESTART_ACK);
		ADD_TPKT(0x023c, -1, ZC_RESULT_STORE_PASSWORD);
		ADD_TPKT(0x00e1, -1, ZC_ROLE_CHANGE);
		ADD_TPKT(0x00d7, 11, ZC_ROOM_NEWENTRY);
		ADD_TPKT(0x00b4, 6, ZC_SAY_DIALOG);
		ADD_TPKT(0x00d1, 2, ZC_SETTING_WHISPER_PC);
		ADD_TPKT(0x01b3, 6, ZC_SHOW_IMAGE2);
		ADD_TPKT(0x010f, 26, ZC_SKILLINFO_LIST);
		ADD_TPKT(0x010e, 6, ZC_SKILLINFO_UPDATE);
		ADD_TPKT(0x01c9, 54, ZC_SKILL_ENTRY2);
		ADD_TPKT(0x01ac, -1, ZC_SKILL_UPDATE);
		ADD_TPKT(0x01d0, 26, ZC_SPIRITS);
		ADD_TPKT(0x00c3, 6, ZC_SPRITE_CHANGE);
		ADD_TPKT(0x020e, -1, ZC_STARSKILL);
		ADD_TPKT(0x0119, 6, ZC_STATE_CHANGE);
		ADD_TPKT(0x0229, 27, ZC_STATE_CHANGE3);
		ADD_TPKT(0x00be, 10, ZC_STATUS_CHANGE);
		ADD_TPKT(0x00bc, 2, ZC_STATUS_CHANGE_ACK);
		ADD_TPKT(0x0088, -1, ZC_STOPMOVE);
		ADD_TPKT(0x0131, 6, ZC_STORE_ENTRY);
		ADD_TPKT(0x01f0, 6, ZC_STORE_NORMAL_ITEMLIST2);
		ADD_TPKT(0x0224, 6, ZC_TAEKWON_POINT);
		ADD_TPKT(0x0226, 53, ZC_TAEKWON_RANK);
		ADD_TPKT(0x01a0, 79, ZC_TRYCAPTURE_MONSTER);
		ADD_TPKT(0x016d, 11, ZC_UPDATE_CHARSTAT);
		ADD_TPKT(0x01f2, 11, ZC_UPDATE_CHARSTAT2);
		ADD_TPKT(0x00c2, -1, ZC_USER_COUNT);
		ADD_TPKT(0x013e, -1, ZC_USESKILL_ACK);
		ADD_TPKT(0x00a8, -1, ZC_USE_ITEM_ACK);
		ADD_TPKT(0x01c8, 43, ZC_USE_ITEM_ACK2);
		ADD_TPKT(0x011a, 8, ZC_USE_SKILL);
		ADD_TPKT(0x00b5, -1, ZC_WAIT_DIALOG);
		ADD_TPKT(0x011c, 282, ZC_WARPLIST);
		ADD_TPKT(0x0097, 6, ZC_WHISPER);
#undef ADD_TPKT
#undef ADD_HPKT
	}

	~ClientPacketLengthTable() { }

};
}
}
#endif /* HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20090318 */