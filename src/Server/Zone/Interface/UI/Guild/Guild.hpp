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

#ifndef HORIZON_ZONE_UI_GUILD_HPP
#define HORIZON_ZONE_UI_GUILD_HPP

#include "Server/Zone/Definitions/ClientDefinitions.hpp"

namespace Horizon
{
namespace Zone
{
class ZoneSession;
namespace UI
{
class Guild
{
public:
	Guild(std::shared_ptr<ZoneSession> session);
	~Guild();
	
	void create(int master_id, std::string name);
	std::shared_ptr<ZoneSession> session() { return _session.lock(); }
	void request_guild_information(int type);
	void notify_menu_interface();
	void change_position_info(std::vector<s_cz_reg_change_guild_positioninfo> info);
	void change_member_positions(std::vector<s_cz_req_change_memberpos> members);
	void change_emblem(std::string emblem);
	void change_notice(int guild_id, std::string subject, std::string notice);
	void invite(int account_id, int inviter_account_id, int inviter_char_id);
	void invite(std::string name);
	void invite_response(int guild_id, cz_join_guild_response_type response);
	void leave(int guild_id, int account_id, int char_id, std::string reason);
	void expel(int guild_id, int account_id, int char_id, std::string reason);
	void send_message(std::string message);
	void invite_ally(int account_id, int inviter_account_id, int inviter_char_id);
	void invite_ally_response(int inviter_account_id, cz_ally_guild_response_type response);
	void remove_related_guild(int guild_id, cz_req_delete_related_guild_relation_type relation);
	void add_opposition(int account_id);
	void disband(std::string key);

private:
	std::weak_ptr<ZoneSession> _session;
};
}
}
}

#endif /* HORIZON_ZONE_UI_GUILD_HPP */