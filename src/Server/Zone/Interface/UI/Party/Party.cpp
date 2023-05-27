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

#include "Party.hpp"
#include "Server/Zone/Session/ZoneSession.hpp"

Horizon::Zone::UI::Party::Party(std::shared_ptr<Horizon::Zone::ZoneSession> session)
{

}

Horizon::Zone::UI::Party::~Party()
{

}

void Horizon::Zone::UI::Party::create(std::string name, int item_share_rule, int item_pickup_rule)
{

}

void Horizon::Zone::UI::Party::invite(int account_id)
{

}

void Horizon::Zone::UI::Party::invite(std::string name)
{

}

void Horizon::Zone::UI::Party::invite_response(int party_id, enum party_invite_response_type response)
{

}

void Horizon::Zone::UI::Party::leave()
{

}

void Horizon::Zone::UI::Party::expel_member(int account_id, std::string name)
{

}

void Horizon::Zone::UI::Party::change_properties(int exp_share_rule, int item_pickup_rule, int item_share_rule)
{

}

void Horizon::Zone::UI::Party::send_message(int packet_length, std::string message)
{

}

void Horizon::Zone::UI::Party::change_leader(int account_id)
{

}

/* Notify */
void Horizon::Zone::UI::Party::notify_created(zcack_makegroup_result_type result)
{

}