/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 * Copyright (c) 2019 Horizon Dev Team.
 *
 * Base Author - Sxyz (sagunxp@gmail.com)
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

#include "PacketHandlerRE20130605.hpp"

using namespace Horizon::Common;
using namespace Horizon::Common::RE20130605;

PacketHandlerRE20130605::PacketHandlerRE20130605(std::shared_ptr<CommonSocket> socket)
: PacketHandler(socket)
{
	initialize_handlers();
}

PacketHandlerRE20130605::~PacketHandlerRE20130605()
{
	//
}

void PacketHandlerRE20130605::initialize_handlers()
{
	PacketHandler::initialize_handlers();

#define HANDLER_FUNC(packet) add_packet_handler(RE20130605::packets::packet, boost::bind(&PacketHandlerRE20130605::Handle_ ## packet, this, boost::placeholders::_1));
#undef HANDLER_FUNC
}