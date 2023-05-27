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

#ifndef HORIZON_ZONE_UI_PARTY_HPP
#define HORIZON_ZONE_UI_PARTY_HPP

#include "Server/Zone/Definitions/ClientDefinitions.hpp"

namespace Horizon
{
namespace Zone
{
class ZoneSession;
namespace UI
{
class Party
{
public:
	Party(std::shared_ptr<ZoneSession> session);
	~Party();

	std::shared_ptr<ZoneSession> session() { return _session.lock(); }

	void create(std::string name, int item_pickup_rule, int item_share_rule);
	void invite(int account_id);
	void invite(std::string name);
	void invite_response(int party_id, enum party_invite_response_type response);
	void leave();
	void expel_member(int account_id, std::string name);
	void change_properties(int exp_share_rule, int item_pickup_rule, int item_share_rule);
	void send_message(int packet_length, std::string message);
	void change_leader(int account_id);

	/* Nofity */
	void notify_created(zcack_makegroup_result_type result);

private:
	std::weak_ptr<ZoneSession> _session;
};
}
}
}

#endif /* HORIZON_ZONE_UI_PARTY_HPP */