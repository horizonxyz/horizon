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

#ifndef HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20100309
#define HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20100309

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
		ADD_HPKT(0x0815, 6, CZ_REQ_CLOSE_BUYING_STORE);
		ADD_HPKT(0x0819, 10, CZ_REQ_TRADE_BUYING_STORE);
		ADD_TPKT(0x0818, -1, ZC_ACK_ITEMLIST_BUYING_STORE);
		ADD_TPKT(0x0814, 2, ZC_BUYING_STORE_ENTRY);
		ADD_TPKT(0x0816, 6, ZC_DISAPPEAR_BUYING_STORE_ENTRY);
		ADD_TPKT(0x081d, 22, ZC_EL_INIT);
		ADD_TPKT(0x081e, 8, ZC_EL_PAR_CHANGE);
		ADD_TPKT(0x081a, 4, ZC_FAILED_TRADE_BUYING_STORE_TO_BUYER);
		ADD_TPKT(0x081c, 6, ZC_ITEM_DELETE_BUYING_STORE);
		ADD_TPKT(0x0813, -1, ZC_MYITEMLIST_BUYING_STORE);
		ADD_TPKT(0x081b, 4, ZC_UPDATE_ITEM_FROM_BUYING_STORE);
#undef ADD_TPKT
#undef ADD_HPKT
	}

	~ClientPacketLengthTable() { }

};
}
}
#endif /* HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20100309 */