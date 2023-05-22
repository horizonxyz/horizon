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

#ifndef HORIZON_ZONE_UI_TRADE_HPP
#define HORIZON_ZONE_UI_TRADE_HPP

namespace Horizon
{
namespace Zone
{
class ZoneSession;
namespace UI
{
class Trade
{
public:
	Trade(std::shared_ptr<ZoneSession> session);
	~Trade();

	std::shared_ptr<ZoneSession> session() { return _session.lock(); }

	void request(int account_id);
	void response(int result);
	void add_zeny(int zeny);
	void add_item(int inventory_index, int amount);
	void lock();
	void cancel();
	void commit();

private:
	std::weak_ptr<ZoneSession> _session;
};
}
}
}

#endif /* HORIZON_ZONE_UI_TRADE_HPP */