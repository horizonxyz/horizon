/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 * Copyright (c) 2020- Horizon Dev Team.
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

#include "Trade.hpp"

using namespace Horizon::Zone::UI;

Trade::Trade(std::shared_ptr<ZoneSession> s)
	: _session(s)
{

}

Trade::~Trade()
{

}

void Trade::request(int account_id)
{

}

void Trade::response(int result)
{
	switch (result)
	{
	case 3: // accepted
	case 4: // rejected
	default:
		break;
	}
}

void Trade::add_zeny(int zeny)
{

}

void Trade::add_item(int inventory_index, int amount)
{

}

void Trade::lock()
{

}

void Trade::cancel()
{

}

void Trade::commit()
{

}