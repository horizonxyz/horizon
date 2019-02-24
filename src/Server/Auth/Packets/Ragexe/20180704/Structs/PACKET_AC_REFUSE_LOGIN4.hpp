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

#ifndef HORIZON_AUTH_RAGEXE_20180704_PACKET_AC_REFUSE_LOGIN4_HPP
#define HORIZON_AUTH_RAGEXE_20180704_PACKET_AC_REFUSE_LOGIN4_HPP

#include "Server/Auth/Packets/Ragexe/20180704/PacketsRagexe20180704.hpp"
#include "Server/Auth/Packets/Ragexe/Structs/PACKET_AC_REFUSE_LOGIN4.hpp"

#include "Server/Common/PacketBuffer.hpp"


namespace Horizon
{
namespace Auth
{
namespace Ragexe20180704
{
struct PACKET_AC_REFUSE_LOGIN4 : public Horizon::Auth::Ragexe::PACKET_AC_REFUSE_LOGIN4
{
	PACKET_AC_REFUSE_LOGIN4(uint16_t packet_id = AC_REFUSE_LOGIN4) : Horizon::Auth::Ragexe::PACKET_AC_REFUSE_LOGIN4(packet_id) { }

	/* Size: 26 bytes */
};
}
}
}

#endif /* HORIZON_AUTH_RAGEXE_20180704_PACKET_AC_REFUSE_LOGIN4_HPP */