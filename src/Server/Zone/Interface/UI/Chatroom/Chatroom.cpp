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

#include "Chatroom.hpp"

Horizon::Zone::UI::Chatroom::Chatroom(std::shared_ptr <Horizon::Zone::ZoneSession> session)
    : _session(session)
{

}

Horizon::Zone::UI::Chatroom::~Chatroom()
{

}

void Horizon::Zone::UI::Chatroom::create_chatroom(int limit, int _public, std::string password, std::string title)
{

}

void Horizon::Zone::UI::Chatroom::role_change(int role, std::string name)
{

}

void Horizon::Zone::UI::Chatroom::add_member(int chat_id, std::string password)
{

}

void Horizon::Zone::UI::Chatroom::expel_member(std::string name)
{

}

void Horizon::Zone::UI::Chatroom::leave()
{

}

void Horizon::Zone::UI::Chatroom::change_properties(int limit, int type, std::string password, std::string title)
{

}