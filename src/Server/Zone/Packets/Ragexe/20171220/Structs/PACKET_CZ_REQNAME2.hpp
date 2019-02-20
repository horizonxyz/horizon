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

#ifndef HORIZON_ZONE_RAGEXE_20171220_PACKET_CZ_REQNAME2_HPP
#define HORIZON_ZONE_RAGEXE_20171220_PACKET_CZ_REQNAME2_HPP

#include "Server/Zone/Packets/Ragexe/20171220/PacketsRagexe20171220.hpp"
#include "Server/Zone/Packets/Ragexe/Structs/PACKET_CZ_REQNAME2.hpp"

#include "Server/Common/PacketBuffer.hpp"


namespace Horizon
{
namespace Zone
{
namespace Ragexe20171220
{
struct PACKET_CZ_REQNAME2 : public Horizon::Zone::Ragexe::PACKET_CZ_REQNAME2
{
	PACKET_CZ_REQNAME2(uint16_t packet_id = CZ_REQNAME2) : Horizon::Zone::Ragexe::PACKET_CZ_REQNAME2(packet_id) { }

	virtual PacketBuffer serialize() override
	{
		return Ragexe::PACKET_CZ_REQNAME2::serialize();
	}

	virtual void deserialize(PacketBuffer &buf) override
	{
		Ragexe::PACKET_CZ_REQNAME2::deserialize(buf);
	}

	virtual Ragexe::PACKET_CZ_REQNAME2 & operator << (PacketBuffer &right) override
	{
		deserialize(right);
		return *this;
	}

	virtual PacketBuffer operator >> (PacketBuffer &right) override
	{
		return right = serialize();
	}

	/* Size: 2 bytes */
	/* Changed from 6 in version 0 to 2 */
};
}
}
}

#endif /* HORIZON_ZONE_RAGEXE_20171220_PACKET_CZ_REQNAME2_HPP */
