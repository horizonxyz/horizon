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

#ifndef HORIZON_ZONE_RAGEXE_20180307_PACKET_CZ_USE_SKILL_TOGROUND2_HPP
#define HORIZON_ZONE_RAGEXE_20180307_PACKET_CZ_USE_SKILL_TOGROUND2_HPP

#include "Server/Zone/Packets/Ragexe/20180307/PacketsRagexe20180307.hpp"
#include "Server/Zone/Packets/Ragexe/20180213/Structs/PACKET_CZ_USE_SKILL_TOGROUND2.hpp"

#include "Server/Common/PacketBuffer.hpp"


namespace Horizon
{
namespace Zone
{
namespace Ragexe20180307
{
struct PACKET_CZ_USE_SKILL_TOGROUND2 : public Horizon::Zone::Ragexe20180213::PACKET_CZ_USE_SKILL_TOGROUND2
{
	PACKET_CZ_USE_SKILL_TOGROUND2(uint16_t packet_id = CZ_USE_SKILL_TOGROUND2) : Horizon::Zone::Ragexe20180213::PACKET_CZ_USE_SKILL_TOGROUND2(packet_id) { }

	/* Size: 2 bytes */
};
}
}
}

#endif /* HORIZON_ZONE_RAGEXE_20180307_PACKET_CZ_USE_SKILL_TOGROUND2_HPP */
