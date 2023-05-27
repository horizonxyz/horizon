/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
	   \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 *
 * Copyright (c) 2019 Sagun K. (sagunxp@gmail.com).
 * Copyright (c) 2019 Horizon Dev Team.
 *
 * Base Author - Sagun K. (sagunxp@gmail.com)
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

#ifndef HORIZON_ZONE_UI_CHATROOM_HPP
#define HORIZON_ZONE_UI_CHATROOM_HPP

#include "Server/Zone/Definitions/ClientDefinitions.hpp"

namespace Horizon
{
namespace Zone
{
class ZoneSession;
namespace UI
{
class Chatroom
{
public:
	Chatroom(std::shared_ptr<ZoneSession> session);
	~Chatroom();

	std::shared_ptr<ZoneSession> session() { return _session.lock(); }

	void create_chatroom(int limit, int _public, std::string password, std::string title);
	void role_change(int role, std::string name);
	void add_member(int chat_id, std::string password);
	void expel_member(std::string name);
	void leave();
	void change_properties(int limit, int type, std::string password, std::string title);

private:
	std::weak_ptr<ZoneSession> _session;
};
}
}
}

#endif /* HORIZON_ZONE_UI_CHATROOM_HPP */