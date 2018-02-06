/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 * Copyright (c) 2018 Horizon Dev Team.
 *
 * Base Author - Sagun Khosla. (sagunxp@gmail.com)
 *
 * Under a proprietary license this file is not for use
 * or viewing without permission.
 **************************************************/

#ifndef HORIZON_AUTH_PACKETHANDLERFACTORY_HPP
#define HORIZON_AUTH_PACKETHANDLERFACTORY_HPP

#include "Server/Auth/PacketHandler/PacketHandler.hpp"
#include "Server/Auth/PacketHandler/InterPacketHandler.hpp"
#include "Server/Auth/PacketHandler/Versions/PacketHandler20170315.hpp"
#include "Server/Auth/PacketHandler/Versions/PacketHandler20171113.hpp"

namespace Horizon
{
namespace Auth
{
class PacketHandlerFactory
{
public:
	PacketHandlerFactory() { };
	~PacketHandlerFactory() { };

	/**
	 * @brief Creates a packet handler object for a client connected to the auth-server,
	 *        based on the connected client's packet version.
	 * @param[in] session    constant reference to the session in question.
	 * @param[in] packet_ver version of the client of the connected session.
	 * @return shared pointer to a new packet handler object for the client version or default.
	 */
	static std::shared_ptr<PacketHandler> CreateAuthPacketHandler(std::shared_ptr<Session> const &session, int packet_ver)
	{
		switch (packet_ver)
		{
		case 20170315:
			return std::make_shared<PacketHandler20170315>(session);
		case 20171113:
			return std::make_shared<PacketHandler20171113>(session);
		default: // return common type.
			return std::make_shared<PacketHandler>(session);
		}
	}

	/**
	 * @brief Creates a packet handler object for a server connected to the auth-server.
	 * @param[in] session    constant reference to the session in question.
	 * @return shared pointer to a new packet handler object.
	 */
	static std::shared_ptr<InterPacketHandler> CreateInterPacketHandler(std::shared_ptr<InterSession> session)
	{
		return std::make_shared<InterPacketHandler>(session);
	}
};
}
}

#endif //HORIZON_AUTH_PACKETHANDLERFACTORY_HPP
