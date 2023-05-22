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
#ifndef HORIZON_ZONE_UI_DEFINITIONS
#define HORIZON_ZONE_UI_DEFINITIONS

#define CHATROOM_TITLE_SIZE 36 + 1
#define CHATROOM_PASS_SIZE 8 + 1

enum party_invite_response_type
{
	PARTY_INVITE_RESPONSE_REJECT = 0,
	PARTY_INVITE_REPSONSE_ACCEPT = 1
};

enum zcparty_joinreqack_result_type
{
	ZCPARTY_JOINREQACK_CHAR_IN_PARTY = 0,
	ZCPARTY_JOINREQACK_INVITE_REJECTED = 1,
	ZCPARTY_JOINREQACK_INVITE_ACCEPTED = 2,
	ZCPARTY_JOINREQACK_PARTY_FULL = 3,
	ZCPARTY_JOINREQACK_ALREADY_IN_SAME_PARTY = 4,
	ZCPARTY_JOINREQACK_BLOCKED_PARTY_INVITE = 5,
	ZCPARTY_JOINREQACK_NOT_ONLINE_DOESNT_EXIST = 7,
	ZCPARTY_JOINREQACK_MAP_RESTRICTS_PARTY_INVITE = 8,
	ZCPARTY_JOINREQACK_MAP_RESTRICTS_PARTY_INVITE2 = 9,
	ZCPARTY_JOINREQACK_RESTRICTED_INSIDE_MEMORIAL_DUNGEON = 10,
	ZCPARTY_JOINREQACK_LEVEL_RESTRICTED = 11
};

#endif /* HORIZON_ZONE_UI_DEFINTIONS */