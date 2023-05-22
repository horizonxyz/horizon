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

#ifndef HORIZON_ZONE_TRANSMITTER_PACKETS_HPP
#define HORIZON_ZONE_TRANSMITTER_PACKETS_HPP

#include "Server/Common/Base/NetworkPacket.hpp"
#include "Server/Common/Configuration/Horizon.hpp"
#include "Server/Zone/Definitions/EntityDefinitions.hpp"
#include "Server/Zone/Definitions/ItemDefinitions.hpp"
#include "Server/Zone/Definitions/SkillDefinitions.hpp"
#include "Server/Zone/Definitions/CombatDefinitions.hpp"
#include "Server/Zone/Definitions/UIDefinitions.hpp"

namespace Horizon
{
namespace Zone
{
class ZoneSession;
enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REQMAKINGITEM = 0x018f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQMAKINGITEM
 *
 */ 
class ZC_ACK_REQMAKINGITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQMAKINGITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQMAKINGITEM, s)
	{}
	virtual ~ZC_ACK_REQMAKINGITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACK_DISCONNECT_CHARACTER = 0x00cd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_DISCONNECT_CHARACTER
 *
 */ 
class ZC_ACK_DISCONNECT_CHARACTER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_DISCONNECT_CHARACTER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_DISCONNECT_CHARACTER, s)
	{}
	virtual ~ZC_ACK_DISCONNECT_CHARACTER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_DISAPPEAR_ENTRY = 0x0132
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DISAPPEAR_ENTRY
 *
 */ 
class ZC_DISAPPEAR_ENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DISAPPEAR_ENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DISAPPEAR_ENTRY, s)
	{}
	virtual ~ZC_DISAPPEAR_ENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20161005 || \
	PACKET_VERSION >= 0
	ID_ZC_REFINE_ADD_ITEM = 0x0aa2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REFINE_ADD_ITEM
 *
 */ 
class ZC_REFINE_ADD_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REFINE_ADD_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REFINE_ADD_ITEM, s)
	{}
	virtual ~ZC_REFINE_ADD_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20180328 || \
	PACKET_VERSION >= 20180307 || \
	PACKET_VERSION >= 20180221 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20040705 || \
	PACKET_VERSION >= 20040628 || \
	PACKET_VERSION >= 0
	ID_ZC_FRIENDS_STATE = 0x0206
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FRIENDS_STATE
 *
 */ 
class ZC_FRIENDS_STATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FRIENDS_STATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FRIENDS_STATE, s)
	{}
	virtual ~ZC_FRIENDS_STATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181031 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_INVENTORY_EXPAND_RESULT = 0x0b17
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_INVENTORY_EXPAND_RESULT
 *
 */ 
class ZC_ACK_INVENTORY_EXPAND_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_INVENTORY_EXPAND_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_INVENTORY_EXPAND_RESULT, s)
	{}
	virtual ~ZC_ACK_INVENTORY_EXPAND_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20060607 || \
	PACKET_VERSION >= 0
	ID_ZC_HUNTINGLIST = 0x027a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HUNTINGLIST
 *
 */ 
class ZC_HUNTINGLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HUNTINGLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HUNTINGLIST, s)
	{}
	virtual ~ZC_HUNTINGLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_UPDATE = 0x01ac
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_UPDATE
 *
 */ 
class ZC_SKILL_UPDATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_UPDATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_UPDATE, s)
	{}
	virtual ~ZC_SKILL_UPDATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110104 || \
	PACKET_VERSION >= 20091201 || \
	PACKET_VERSION >= 0
	ID_ZC_DEFINE_CHECK = 0x07ff
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DEFINE_CHECK
 *
 */ 
class ZC_DEFINE_CHECK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DEFINE_CHECK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DEFINE_CHECK, s)
	{}
	virtual ~ZC_DEFINE_CHECK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111101 || \
	PACKET_VERSION >= 20111025 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_VOLUNTEER_INFO = 0x08f2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_VOLUNTEER_INFO
 *
 */ 
class ZC_PARTY_RECRUIT_VOLUNTEER_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_VOLUNTEER_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_VOLUNTEER_INFO, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_VOLUNTEER_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100622
	ID_ZC_SEARCH_STORE_OPEN_INFO = 0x083f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SEARCH_STORE_OPEN_INFO
 *
 */ 
class ZC_SEARCH_STORE_OPEN_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SEARCH_STORE_OPEN_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SEARCH_STORE_OPEN_INFO, s)
	{}
	virtual ~ZC_SEARCH_STORE_OPEN_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050718 || \
	PACKET_VERSION >= 0
	ID_ZC_AUCTION_RESULT = 0x0250
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_AUCTION_RESULT
 *
 */ 
class ZC_AUCTION_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_AUCTION_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_AUCTION_RESULT, s)
	{}
	virtual ~ZC_AUCTION_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ITEMIDENTIFY = 0x0179
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ITEMIDENTIFY
 *
 */ 
class ZC_ACK_ITEMIDENTIFY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ITEMIDENTIFY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ITEMIDENTIFY, s)
	{}
	virtual ~ZC_ACK_ITEMIDENTIFY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 0
	ID_ZC_QUEST_NOTIFY_EFFECT = 0x0446
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_QUEST_NOTIFY_EFFECT
 *
 */ 
class ZC_QUEST_NOTIFY_EFFECT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_QUEST_NOTIFY_EFFECT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_QUEST_NOTIFY_EFFECT, s)
	{}
	virtual ~ZC_QUEST_NOTIFY_EFFECT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130424 || \
	PACKET_VERSION >= 0
	ID_ZC_CLOSE_BARGAIN_SALE_TOOL = 0x09bd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CLOSE_BARGAIN_SALE_TOOL
 *
 */ 
class ZC_CLOSE_BARGAIN_SALE_TOOL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CLOSE_BARGAIN_SALE_TOOL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CLOSE_BARGAIN_SALE_TOOL, s)
	{}
	virtual ~ZC_CLOSE_BARGAIN_SALE_TOOL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090805 || \
	PACKET_VERSION >= 0
	ID_ZC_MSG_VALUE = 0x07e2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MSG_VALUE
 *
 */ 
class ZC_MSG_VALUE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MSG_VALUE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MSG_VALUE, s)
	{}
	virtual ~ZC_MSG_VALUE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180829 || \
	PACKET_VERSION >= 20180822 || \
	PACKET_VERSION >= 0
	ID_ZC_OFFLINE_STORE_VISIBLE = 0x0b05
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OFFLINE_STORE_VISIBLE
 *
 */ 
class ZC_OFFLINE_STORE_VISIBLE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OFFLINE_STORE_VISIBLE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OFFLINE_STORE_VISIBLE, s)
	{}
	virtual ~ZC_OFFLINE_STORE_VISIBLE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_INFO_REMAINTIME = 0x01c2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INFO_REMAINTIME
 *
 */ 
class ZC_INFO_REMAINTIME : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INFO_REMAINTIME(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INFO_REMAINTIME, s)
	{}
	virtual ~ZC_INFO_REMAINTIME() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090113 || \
	PACKET_VERSION >= 0
	ID_ZC_SIMPLE_CASH_POINT_ITEMLIST = 0x0444
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SIMPLE_CASH_POINT_ITEMLIST
 *
 */ 
class ZC_SIMPLE_CASH_POINT_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SIMPLE_CASH_POINT_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SIMPLE_CASH_POINT_ITEMLIST, s)
	{}
	virtual ~ZC_SIMPLE_CASH_POINT_ITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_NEWENTRY = 0x0079
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_NEWENTRY
 *
 */ 
class ZC_NOTIFY_NEWENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_NEWENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_NEWENTRY, s)
	{}
	virtual ~ZC_NOTIFY_NEWENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20040308 || \
	PACKET_VERSION >= 0
	ID_ZC_START_BABY = 0x01f8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_START_BABY
 *
 */ 
class ZC_START_BABY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_START_BABY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_START_BABY, s)
	{}
	virtual ~ZC_START_BABY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20061211 || \
	PACKET_VERSION >= 0
	ID_ZC_CASH_ITEM_DELETE = 0x0299
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CASH_ITEM_DELETE
 *
 */ 
class ZC_CASH_ITEM_DELETE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CASH_ITEM_DELETE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CASH_ITEM_DELETE, s)
	{}
	virtual ~ZC_CASH_ITEM_DELETE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111108 || \
	PACKET_VERSION >= 20111025 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_RECALL_COST = 0x08f6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_RECALL_COST
 *
 */ 
class ZC_PARTY_RECRUIT_RECALL_COST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_RECALL_COST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_RECALL_COST, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_RECALL_COST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MANNER_POINT_GIVEN = 0x014b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MANNER_POINT_GIVEN
 *
 */ 
class ZC_NOTIFY_MANNER_POINT_GIVEN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MANNER_POINT_GIVEN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MANNER_POINT_GIVEN, s)
	{}
	virtual ~ZC_NOTIFY_MANNER_POINT_GIVEN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140702 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_AU_BOT = 0x0a29
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_AU_BOT
 *
 */ 
class ZC_REQ_AU_BOT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_AU_BOT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_AU_BOT, s)
	{}
	virtual ~ZC_REQ_AU_BOT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_DELETE_ITEM_FROM_CART = 0x0125
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DELETE_ITEM_FROM_CART
 *
 */ 
class ZC_DELETE_ITEM_FROM_CART : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DELETE_ITEM_FROM_CART(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DELETE_ITEM_FROM_CART, s)
	{}
	virtual ~ZC_DELETE_ITEM_FROM_CART() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MVP_GETTING_ITEM = 0x010a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MVP_GETTING_ITEM
 *
 */ 
class ZC_MVP_GETTING_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MVP_GETTING_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MVP_GETTING_ITEM, s)
	{}
	virtual ~ZC_MVP_GETTING_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20101123 || \
	PACKET_VERSION >= 20100629 || \
	PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_WEAR_EQUIP_ACK = 0x00aa
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_WEAR_EQUIP_ACK
 *
 */ 
class ZC_REQ_WEAR_EQUIP_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_WEAR_EQUIP_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_WEAR_EQUIP_ACK, s)
	{}
	virtual ~ZC_REQ_WEAR_EQUIP_ACK() {}

	void deliver(int16_t index, int16_t equip_location_mask, item_equip_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int16_t _index{0};
	int16_t _equip_location_mask{0};
	int8_t _result{0};
};

enum {
#if PACKET_VERSION >= 20140917 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REQNAMEALL2 = 0x0a30
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQNAMEALL2
 *
 */ 
class ZC_ACK_REQNAMEALL2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQNAMEALL2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQNAMEALL2, s)
	{}
	virtual ~ZC_ACK_REQNAMEALL2() {}

	void deliver(int32_t guid, std::string name, std::string party_name, std::string guild_name, std::string position_name, int32_t title_id);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid;
	char _name[MAX_UNIT_NAME_LENGTH];
	char _party_name[MAX_UNIT_NAME_LENGTH];
	char _guild_name[MAX_UNIT_NAME_LENGTH];
	char _position_name[MAX_UNIT_NAME_LENGTH];
	int32_t _title_id;
};

enum {
#if PACKET_VERSION >= 20040216 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_EFFECT2 = 0x01f3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_EFFECT2
 *
 */ 
class ZC_NOTIFY_EFFECT2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_EFFECT2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_EFFECT2, s)
	{}
	virtual ~ZC_NOTIFY_EFFECT2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20060911 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_EFFECT3 = 0x0284
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_EFFECT3
 *
 */ 
class ZC_NOTIFY_EFFECT3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_EFFECT3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_EFFECT3, s)
	{}
	virtual ~ZC_NOTIFY_EFFECT3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20041213 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_CRAZYKILLER = 0x0220
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_CRAZYKILLER
 *
 */ 
class ZC_NOTIFY_CRAZYKILLER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_CRAZYKILLER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_CRAZYKILLER, s)
	{}
	virtual ~ZC_NOTIFY_CRAZYKILLER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_CARTOFF = 0x012b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CARTOFF
 *
 */ 
class ZC_CARTOFF : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CARTOFF(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CARTOFF, s)
	{}
	virtual ~ZC_CARTOFF() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120925 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_WEAR_EQUIP_V5 = 0x0999
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_WEAR_EQUIP_V5
 *
 */ 
class ZC_ACK_WEAR_EQUIP_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_WEAR_EQUIP_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_WEAR_EQUIP_V5, s)
	{}
	virtual ~ZC_ACK_WEAR_EQUIP_V5() {}

	void deliver(int16_t inventory_index, int32_t location, int16_t look, int8_t result);
	ByteBuffer &serialize();

/* Structure */
	int16_t _inventory_index{0};
	int32_t _equip_location{0};
	int16_t _look{0};
///     0 = failure
///     1 = success
///     2 = failure due to low level
	int8_t _result{0};
};

enum {
#if PACKET_VERSION >= 20061226 || \
	PACKET_VERSION >= 0
	ID_ZC_MER_PAR_CHANGE = 0x02a2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MER_PAR_CHANGE
 *
 */ 
class ZC_MER_PAR_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MER_PAR_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MER_PAR_CHANGE, s)
	{}
	virtual ~ZC_MER_PAR_CHANGE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_EXEC_EXCHANGE_ITEM = 0x00f0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EXEC_EXCHANGE_ITEM
 *
 */ 
class ZC_EXEC_EXCHANGE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
	enum zc_exec_exchange_item_result_type
	{
		ZCEXEC_EXCHANGEITEM_RESULT_SUCCESS = 0,
		ZCEXEC_EXCHANGEITEM_RESULT_FAILURE = 1,
	};
public:
	ZC_EXEC_EXCHANGE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EXEC_EXCHANGE_ITEM, s)
	{}
	virtual ~ZC_EXEC_EXCHANGE_ITEM() {}

	void deliver(zc_exec_exchange_item_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int8_t _result{ 0 };
};

enum {
#if PACKET_VERSION >= 20130327 || \
	PACKET_VERSION >= 20130313 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_APPLY_BARGAIN_SALE_ITEM = 0x09af
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_APPLY_BARGAIN_SALE_ITEM
 *
 */ 
class ZC_ACK_APPLY_BARGAIN_SALE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_APPLY_BARGAIN_SALE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_APPLY_BARGAIN_SALE_ITEM, s)
	{}
	virtual ~ZC_ACK_APPLY_BARGAIN_SALE_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ENTER_ROOM = 0x00db
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ENTER_ROOM
 *
 */ 
class ZC_ENTER_ROOM : public Base::NetworkPacketTransmitter<ZoneSession>
{
	struct chatroom_user { int8_t _type; char name[MAX_UNIT_NAME_LENGTH]; };
public:
	ZC_ENTER_ROOM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ENTER_ROOM, s)
	{}
	virtual ~ZC_ENTER_ROOM() {}

	void deliver(int chat_id, std::vector<chatroom_user> users);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{ 0 };
	int _chat_id{ 0 };
	std::vector<chatroom_user> _users;
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_REPLY_REMAINTIME = 0x01c1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REPLY_REMAINTIME
 *
 */ 
class ZC_REPLY_REMAINTIME : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REPLY_REMAINTIME(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REPLY_REMAINTIME, s)
	{}
	virtual ~ZC_REPLY_REMAINTIME() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_AID = 0x0283
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_AID
 *
 */ 
class ZC_AID : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_AID(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_AID, s)
	{}
	virtual ~ZC_AID() {}

	void deliver(int32_t aid);
	ByteBuffer &serialize();

/* Structure */
	int32_t _account_id{0};
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_THROW_MVPITEM = 0x010d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_THROW_MVPITEM
 *
 */ 
class ZC_THROW_MVPITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_THROW_MVPITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_THROW_MVPITEM, s)
	{}
	virtual ~ZC_THROW_MVPITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIP_ARROW = 0x013c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIP_ARROW
 *
 */ 
class ZC_EQUIP_ARROW : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIP_ARROW(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIP_ARROW, s)
	{}
	virtual ~ZC_EQUIP_ARROW() {}

	void deliver(int16_t inventory_index);
	ByteBuffer &serialize();

/* Structure */
	int16_t _index;
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140226 || \
	PACKET_VERSION >= 20140219 || \
	PACKET_VERSION >= 20140129 || \
	PACKET_VERSION >= 20140108 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_ITEM_TO_CART2 = 0x01c5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_ITEM_TO_CART2
 *
 */ 
class ZC_ADD_ITEM_TO_CART2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_ITEM_TO_CART2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_ITEM_TO_CART2, s)
	{}
	virtual ~ZC_ADD_ITEM_TO_CART2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_EXCHANGEITEM_UNDO = 0x00f1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EXCHANGEITEM_UNDO
 *
 */ 
class ZC_EXCHANGEITEM_UNDO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EXCHANGEITEM_UNDO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EXCHANGEITEM_UNDO, s)
	{}
	virtual ~ZC_EXCHANGEITEM_UNDO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110111 || \
	PACKET_VERSION >= 0
	ID_ZC_SHOWSCRIPT = 0x08b3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SHOWSCRIPT
 *
 */ 
class ZC_SHOWSCRIPT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SHOWSCRIPT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SHOWSCRIPT, s)
	{}
	virtual ~ZC_SHOWSCRIPT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050530 || \
	PACKET_VERSION >= 0
	ID_ZC_HOSKILLINFO_LIST = 0x0235
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HOSKILLINFO_LIST
 *
 */ 
class ZC_HOSKILLINFO_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HOSKILLINFO_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HOSKILLINFO_LIST, s)
	{}
	virtual ~ZC_HOSKILLINFO_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SETTING_WHISPER_STATE = 0x00d2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SETTING_WHISPER_STATE
 *
 */ 
class ZC_SETTING_WHISPER_STATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SETTING_WHISPER_STATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SETTING_WHISPER_STATE, s)
	{}
	virtual ~ZC_SETTING_WHISPER_STATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SETTING_WHISPER_PC = 0x00d1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SETTING_WHISPER_PC
 *
 */ 
class ZC_SETTING_WHISPER_PC : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SETTING_WHISPER_PC(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SETTING_WHISPER_PC, s)
	{}
	virtual ~ZC_SETTING_WHISPER_PC() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111122 || \
	PACKET_VERSION >= 0
	ID_ZC_INVENTORY_ITEMLIST_EQUIP = 0x0901
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INVENTORY_ITEMLIST_EQUIP
 *
 */ 
class ZC_INVENTORY_ITEMLIST_EQUIP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INVENTORY_ITEMLIST_EQUIP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INVENTORY_ITEMLIST_EQUIP, s)
	{}
	virtual ~ZC_INVENTORY_ITEMLIST_EQUIP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20060918 || \
	PACKET_VERSION >= 20060904 || \
	PACKET_VERSION >= 0
	ID_ZC_GANGSI_RANK = 0x0282
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GANGSI_RANK
 *
 */ 
class ZC_GANGSI_RANK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GANGSI_RANK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GANGSI_RANK, s)
	{}
	virtual ~ZC_GANGSI_RANK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111207 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_SUB_FILTERLINGLIST = 0x090c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_SUB_FILTERLINGLIST
 *
 */ 
class ZC_PARTY_RECRUIT_SUB_FILTERLINGLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_SUB_FILTERLINGLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_SUB_FILTERLINGLIST, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_SUB_FILTERLINGLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_ITEM_TO_STORE = 0x00f4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_ITEM_TO_STORE
 *
 */ 
class ZC_ADD_ITEM_TO_STORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_ITEM_TO_STORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_ITEM_TO_STORE, s)
	{}
	virtual ~ZC_ADD_ITEM_TO_STORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_AUTORUN_SKILL = 0x0147
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_AUTORUN_SKILL
 *
 */ 
class ZC_AUTORUN_SKILL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_AUTORUN_SKILL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_AUTORUN_SKILL, s)
	{}
	virtual ~ZC_AUTORUN_SKILL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140611 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_ACH_REWARD_ACK = 0x0a26
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_ACH_REWARD_ACK
 *
 */ 
class ZC_REQ_ACH_REWARD_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_ACH_REWARD_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_ACH_REWARD_ACK, s)
	{}
	virtual ~ZC_REQ_ACH_REWARD_ACK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20060927 || \
	PACKET_VERSION >= 0
	ID_ZC_NPC_SHOWEFST_UPDATE = 0x028a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NPC_SHOWEFST_UPDATE
 *
 */ 
class ZC_NPC_SHOWEFST_UPDATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NPC_SHOWEFST_UPDATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NPC_SHOWEFST_UPDATE, s)
	{}
	virtual ~ZC_NPC_SHOWEFST_UPDATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091201 || \
	PACKET_VERSION >= 0
	ID_ZC_CHANGE_GROUP_MASTER = 0x07fc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CHANGE_GROUP_MASTER
 *
 */ 
class ZC_CHANGE_GROUP_MASTER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CHANGE_GROUP_MASTER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CHANGE_GROUP_MASTER, s)
	{}
	virtual ~ZC_CHANGE_GROUP_MASTER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_TRYCAPTURE_MONSTER = 0x01a0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_TRYCAPTURE_MONSTER
 *
 */ 
class ZC_TRYCAPTURE_MONSTER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_TRYCAPTURE_MONSTER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_TRYCAPTURE_MONSTER, s)
	{}
	virtual ~ZC_TRYCAPTURE_MONSTER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_PICKUP_ACK = 0x00a0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_PICKUP_ACK
 *
 */ 
class ZC_ITEM_PICKUP_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_PICKUP_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_PICKUP_ACK, s)
	{}
	virtual ~ZC_ITEM_PICKUP_ACK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20180228 || \
	PACKET_VERSION >= 20180221 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20171227 || \
	PACKET_VERSION >= 20171220 || \
	PACKET_VERSION >= 20171206 || \
	PACKET_VERSION >= 20171204 || \
	PACKET_VERSION >= 20171108 || \
	PACKET_VERSION >= 20171101 || \
	PACKET_VERSION >= 20171018 || \
	PACKET_VERSION >= 20170920 || \
	PACKET_VERSION >= 20170913 || \
	PACKET_VERSION >= 20170726 || \
	PACKET_VERSION >= 20170719 || \
	PACKET_VERSION >= 20170621 || \
	PACKET_VERSION >= 20170614 || \
	PACKET_VERSION >= 20170524 || \
	PACKET_VERSION >= 20170517 || \
	PACKET_VERSION >= 20170426 || \
	PACKET_VERSION >= 20170419 || \
	PACKET_VERSION >= 20170322 || \
	PACKET_VERSION >= 20170315 || \
	PACKET_VERSION >= 20170201 || \
	PACKET_VERSION >= 20170125 || \
	PACKET_VERSION >= 20170118 || \
	PACKET_VERSION >= 20170111 || \
	PACKET_VERSION >= 20170104 || \
	PACKET_VERSION >= 20161109 || \
	PACKET_VERSION >= 20161102 || \
	PACKET_VERSION >= 20161026 || \
	PACKET_VERSION >= 20160907 || \
	PACKET_VERSION >= 20160831 || \
	PACKET_VERSION >= 20160817 || \
	PACKET_VERSION >= 20160803 || \
	PACKET_VERSION >= 20160713 || \
	PACKET_VERSION >= 20160706 || \
	PACKET_VERSION >= 20160330 || \
	PACKET_VERSION >= 20160323 || \
	PACKET_VERSION >= 20160120 || \
	PACKET_VERSION >= 20160113 || \
	PACKET_VERSION >= 20160106 || \
	PACKET_VERSION >= 20151230 || \
	PACKET_VERSION >= 20151223 || \
	PACKET_VERSION >= 20150610 || \
	PACKET_VERSION >= 20150603 || \
	PACKET_VERSION >= 20150415 || \
	PACKET_VERSION >= 20150408 || \
	PACKET_VERSION >= 20150401 || \
	PACKET_VERSION >= 20150107 || \
	PACKET_VERSION >= 20140219 || \
	PACKET_VERSION >= 20140212 || \
	PACKET_VERSION >= 20140108 || \
	PACKET_VERSION >= 20130306 || \
	PACKET_VERSION >= 20130227 || \
	PACKET_VERSION >= 20130115 || \
	PACKET_VERSION >= 20130109 || \
	PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20121205 || \
	PACKET_VERSION >= 20121128 || \
	PACKET_VERSION >= 20120503 || \
	PACKET_VERSION >= 20120502 || \
	PACKET_VERSION >= 20120424 || \
	PACKET_VERSION >= 20120328
	ID_ZC_PRNPC_STATE = 0x091b
#elif PACKET_VERSION >= 20120404 || \
	PACKET_VERSION >= 20120207 || \
	PACKET_VERSION >= 0
	ID_ZC_PRNPC_STATE = 0x096b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PRNPC_STATE
 *
 */ 
class ZC_PRNPC_STATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PRNPC_STATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PRNPC_STATE, s)
	{}
	virtual ~ZC_PRNPC_STATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091215 || \
	PACKET_VERSION >= 0
	ID_ZC_PC_PURCHASE_ITEMLIST_FROMMC2 = 0x0800
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PC_PURCHASE_ITEMLIST_FROMMC2
 *
 */ 
class ZC_PC_PURCHASE_ITEMLIST_FROMMC2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PC_PURCHASE_ITEMLIST_FROMMC2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PC_PURCHASE_ITEMLIST_FROMMC2, s)
	{}
	virtual ~ZC_PC_PURCHASE_ITEMLIST_FROMMC2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20160921 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_EXCHANGE_ITEM4 = 0x0a96
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_EXCHANGE_ITEM4
 *
 */ 
class ZC_ADD_EXCHANGE_ITEM4 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_EXCHANGE_ITEM4(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_EXCHANGE_ITEM4, s)
	{}
	virtual ~ZC_ADD_EXCHANGE_ITEM4() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070813 || \
	PACKET_VERSION >= 0
	ID_ZC_NPC_CHAT = 0x02c1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NPC_CHAT
 *
 */ 
class ZC_NPC_CHAT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NPC_CHAT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NPC_CHAT, s)
	{}
	virtual ~ZC_NPC_CHAT() {}

	void deliver(int32_t guid, std::string const &message, int32_t color);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{0};
	int32_t _guid{0};
	int32_t _color{0xFFFFFF};
	std::string _message{""};
};

enum {
#if PACKET_VERSION >= 20140115 || \
	PACKET_VERSION >= 0
	ID_ZC_ALL_QUEST_LIST3 = 0x09f8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALL_QUEST_LIST3
 *
 */ 
class ZC_ALL_QUEST_LIST3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALL_QUEST_LIST3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALL_QUEST_LIST3, s)
	{}
	virtual ~ZC_ALL_QUEST_LIST3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120410 || \
	PACKET_VERSION >= 0
	ID_ZC_ALL_QUEST_LIST2 = 0x097a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALL_QUEST_LIST2
 *
 */ 
class ZC_ALL_QUEST_LIST2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALL_QUEST_LIST2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALL_QUEST_LIST2, s)
	{}
	virtual ~ZC_ALL_QUEST_LIST2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20180605 || \
	PACKET_VERSION >= 0
	ID_ZC_ALL_QUEST_LIST4 = 0x0aff
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALL_QUEST_LIST4
 *
 */ 
class ZC_ALL_QUEST_LIST4 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALL_QUEST_LIST4(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALL_QUEST_LIST4, s)
	{}
	virtual ~ZC_ALL_QUEST_LIST4() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140226 || \
	PACKET_VERSION >= 20140219 || \
	PACKET_VERSION >= 20140129 || \
	PACKET_VERSION >= 20140108 || \
	PACKET_VERSION >= 20100223 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_EXCHANGE_ITEM2 = 0x080f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_EXCHANGE_ITEM2
 *
 */ 
class ZC_ADD_EXCHANGE_ITEM2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_EXCHANGE_ITEM2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_EXCHANGE_ITEM2, s)
	{}
	virtual ~ZC_ADD_EXCHANGE_ITEM2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140312 || \
	PACKET_VERSION >= 20140305 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_EXCHANGE_ITEM3 = 0x0a09
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_EXCHANGE_ITEM3
 *
 */ 
class ZC_ADD_EXCHANGE_ITEM3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_EXCHANGE_ITEM3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_EXCHANGE_ITEM3, s)
	{}
	virtual ~ZC_ADD_EXCHANGE_ITEM3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120214 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER_TO_PM = 0x0971
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER_TO_PM
 *
 */ 
class ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER_TO_PM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER_TO_PM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER_TO_PM, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER_TO_PM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120120 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_GUILD_NAME = 0x0913
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_GUILD_NAME
 *
 */ 
class ZC_ACK_GUILD_NAME : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_GUILD_NAME(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_GUILD_NAME, s)
	{}
	virtual ~ZC_ACK_GUILD_NAME() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20160629 || \
	PACKET_VERSION >= 0
	ID_ZC_OFFLINE_STORE_VANISH = 0x0a8a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OFFLINE_STORE_VANISH
 *
 */ 
class ZC_OFFLINE_STORE_VANISH : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OFFLINE_STORE_VANISH(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OFFLINE_STORE_VANISH, s)
	{}
	virtual ~ZC_OFFLINE_STORE_VANISH() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050411 || \
	PACKET_VERSION >= 0
	ID_ZC_STATE_CHANGE3 = 0x0229
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STATE_CHANGE3
 *
 */ 
class ZC_STATE_CHANGE3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STATE_CHANGE3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STATE_CHANGE3, s)
	{}
	virtual ~ZC_STATE_CHANGE3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140129 || \
	PACKET_VERSION >= 0
	ID_ZC_SHORTCUT_KEY_LIST_V3 = 0x0a00
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SHORTCUT_KEY_LIST_V3
 *
 */ 
class ZC_SHORTCUT_KEY_LIST_V3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SHORTCUT_KEY_LIST_V3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SHORTCUT_KEY_LIST_V3, s)
	{}
	virtual ~ZC_SHORTCUT_KEY_LIST_V3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090617 || \
	PACKET_VERSION >= 20090603 || \
	PACKET_VERSION >= 0
	ID_ZC_SHORTCUT_KEY_LIST_V2 = 0x07d9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SHORTCUT_KEY_LIST_V2
 *
 */ 
class ZC_SHORTCUT_KEY_LIST_V2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SHORTCUT_KEY_LIST_V2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SHORTCUT_KEY_LIST_V2, s)
	{}
	virtual ~ZC_SHORTCUT_KEY_LIST_V2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_SKILL2 = 0x01de
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_SKILL2
 *
 */ 
class ZC_NOTIFY_SKILL2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_SKILL2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_SKILL2, s)
	{}
	virtual ~ZC_NOTIFY_SKILL2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_CHANGE_CHATROOM = 0x00df
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CHANGE_CHATROOM
 *
 */ 
class ZC_CHANGE_CHATROOM : public Base::NetworkPacketTransmitter<ZoneSession>
{
	enum zc_change_chatroom_type
	{
		ZC_CHANGECHATROOM_PRIVATE = 0, // password protected
		ZC_CHANGECHATROOM_PUBLIC = 1,
		ZC_CHANGECHATROOM_ARENA = 2, // npc waiting room
		ZC_CHANGECHATROOM_PKZONE = 3 // non-clickable
	};
public:
	ZC_CHANGE_CHATROOM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CHANGE_CHATROOM, s)
	{}
	virtual ~ZC_CHANGE_CHATROOM() {}

	void deliver(int owner_id, int chat_id, int limit, int users, zc_change_chatroom_type type, std::string title);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{ 0 };
	int _owner_id; 
	int _chat_id; 
	int16_t _limit;
	int16_t _users;
	int8_t _type;
	char _title[CHATROOM_TITLE_SIZE];
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_ENTRY = 0x0131
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_ENTRY
 *
 */ 
class ZC_STORE_ENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_ENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_ENTRY, s)
	{}
	virtual ~ZC_STORE_ENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120925 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_ITEMLIST_NORMAL_V5 = 0x0995
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_ITEMLIST_NORMAL_V5
 *
 */ 
class ZC_STORE_ITEMLIST_NORMAL_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_ITEMLIST_NORMAL_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_ITEMLIST_NORMAL_V5, s)
	{}
	virtual ~ZC_STORE_ITEMLIST_NORMAL_V5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20040816 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_STATUS_GM = 0x0214
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_STATUS_GM
 *
 */ 
class ZC_ACK_STATUS_GM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_STATUS_GM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_STATUS_GM, s)
	{}
	virtual ~ZC_ACK_STATUS_GM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20071113 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_ACT2 = 0x02e1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_ACT2
 *
 */ 
class ZC_NOTIFY_ACT2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_ACT2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_ACT2, s)
	{}
	virtual ~ZC_NOTIFY_ACT2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MEMBER_EXIT = 0x00dd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MEMBER_EXIT
 *
 */ 
class ZC_MEMBER_EXIT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MEMBER_EXIT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MEMBER_EXIT, s)
	{}
	virtual ~ZC_MEMBER_EXIT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_THROW_ACK = 0x00af
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_THROW_ACK
 *
 */ 
class ZC_ITEM_THROW_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_THROW_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_THROW_ACK, s)
	{}
	virtual ~ZC_ITEM_THROW_ACK() {}

	void deliver(int16_t inventory_index, int16_t amount);
	ByteBuffer &serialize();

/* Structure */
	int16_t _inventory_index;
	int16_t _amount;
};

enum {
#if PACKET_VERSION >= 20110125 || \
	PACKET_VERSION >= 0
	ID_ZC_START_COLLECTION = 0x08b4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_START_COLLECTION
 *
 */ 
class ZC_START_COLLECTION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_START_COLLECTION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_START_COLLECTION, s)
	{}
	virtual ~ZC_START_COLLECTION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_OPEN_EDITDLGSTR = 0x01d4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OPEN_EDITDLGSTR
 *
 */ 
class ZC_OPEN_EDITDLGSTR : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OPEN_EDITDLGSTR(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OPEN_EDITDLGSTR, s)
	{}
	virtual ~ZC_OPEN_EDITDLGSTR() {}

	void deliver(int32_t guid);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid{0};
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SPIRITS2 = 0x01e1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SPIRITS2
 *
 */ 
class ZC_SPIRITS2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SPIRITS2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SPIRITS2, s)
	{}
	virtual ~ZC_SPIRITS2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_PROPERTY_PET = 0x01a2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PROPERTY_PET
 *
 */ 
class ZC_PROPERTY_PET : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PROPERTY_PET(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PROPERTY_PET, s)
	{}
	virtual ~ZC_PROPERTY_PET() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIPMENT_ITEMLIST = 0x00a4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIPMENT_ITEMLIST
 *
 */ 
class ZC_EQUIPMENT_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIPMENT_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIPMENT_ITEMLIST, s)
	{}
	virtual ~ZC_EQUIPMENT_ITEMLIST() {}

	void deliver(std::vector<item_entry_data> &items);
	ByteBuffer &serialize();

/* Structure */
	std::vector<item_entry_data> _items;
};

enum {
#if PACKET_VERSION >= 20140625 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_OPENSTORE2 = 0x0a28
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_OPENSTORE2
 *
 */ 
class ZC_ACK_OPENSTORE2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_OPENSTORE2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_OPENSTORE2, s)
	{}
	virtual ~ZC_ACK_OPENSTORE2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100309 || \
	PACKET_VERSION >= 0
	ID_ZC_DISAPPEAR_BUYING_STORE_ENTRY = 0x0816
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DISAPPEAR_BUYING_STORE_ENTRY
 *
 */ 
class ZC_DISAPPEAR_BUYING_STORE_ENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DISAPPEAR_BUYING_STORE_ENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DISAPPEAR_BUYING_STORE_ENTRY, s)
	{}
	virtual ~ZC_DISAPPEAR_BUYING_STORE_ENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20170228 || \
	PACKET_VERSION >= 20170222 || \
	PACKET_VERSION >= 0
	ID_ZC_WARPLIST = 0x0abe
#elif PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_WARPLIST = 0x011c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_WARPLIST
 *
 */ 
class ZC_WARPLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_WARPLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_WARPLIST, s)
	{}
	virtual ~ZC_WARPLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120214 || \
	PACKET_VERSION >= 0
	ID_ZC_WAIT_DIALOG2 = 0x0973
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_WAIT_DIALOG2
 *
 */ 
class ZC_WAIT_DIALOG2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_WAIT_DIALOG2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_WAIT_DIALOG2, s)
	{}
	virtual ~ZC_WAIT_DIALOG2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_BLADESTOP = 0x01d1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BLADESTOP
 *
 */ 
class ZC_BLADESTOP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BLADESTOP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BLADESTOP, s)
	{}
	virtual ~ZC_BLADESTOP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MSG_STATE_CHANGE = 0x0196
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MSG_STATE_CHANGE
 *
 */ 
class ZC_MSG_STATE_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MSG_STATE_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MSG_STATE_CHANGE, s)
	{}
	virtual ~ZC_MSG_STATE_CHANGE() {}

	void deliver(int16_t status_index, int32_t guid, int8_t state);
	ByteBuffer &serialize();

/* Structure */
	int16_t _status_index{0};
	int32_t _guid{0};
	int8_t _state{0};
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_SOUND = 0x01d3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SOUND
 *
 */ 
class ZC_SOUND : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SOUND(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SOUND, s)
	{}
	virtual ~ZC_SOUND() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NPCSPRITE_CHANGE = 0x01b0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NPCSPRITE_CHANGE
 *
 */ 
class ZC_NPCSPRITE_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NPCSPRITE_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NPCSPRITE_CHANGE, s)
	{}
	virtual ~ZC_NPCSPRITE_CHANGE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110810 || \
	PACKET_VERSION >= 20110809 || \
	PACKET_VERSION >= 0
	ID_ZC_SPIRITS_ATTRIBUTE = 0x08cf
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SPIRITS_ATTRIBUTE
 *
 */ 
class ZC_SPIRITS_ATTRIBUTE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SPIRITS_ATTRIBUTE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SPIRITS_ATTRIBUTE, s)
	{}
	virtual ~ZC_SPIRITS_ATTRIBUTE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20170426 || \
	PACKET_VERSION >= 20170104 || \
	PACKET_VERSION >= 20160928 || \
	PACKET_VERSION >= 0
	ID_ZC_ALT_EQUIPMENT_EQUIP = 0x0a98
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALT_EQUIPMENT_EQUIP
 *
 */ 
class ZC_ALT_EQUIPMENT_EQUIP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALT_EQUIPMENT_EQUIP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALT_EQUIPMENT_EQUIP, s)
	{}
	virtual ~ZC_ALT_EQUIPMENT_EQUIP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070821 || \
	PACKET_VERSION >= 0
	ID_ZC_FORMATSTRING_MSG = 0x02c2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FORMATSTRING_MSG
 *
 */ 
class ZC_FORMATSTRING_MSG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FORMATSTRING_MSG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FORMATSTRING_MSG, s)
	{}
	virtual ~ZC_FORMATSTRING_MSG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181031 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_INVENTORY_EXPAND = 0x0b15
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_INVENTORY_EXPAND
 *
 */ 
class ZC_ACK_INVENTORY_EXPAND : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_INVENTORY_EXPAND(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_INVENTORY_EXPAND, s)
	{}
	virtual ~ZC_ACK_INVENTORY_EXPAND() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20161005 || \
	PACKET_VERSION >= 0
	ID_ZC_REFINE_OPEN_WINDOW = 0x0aa0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REFINE_OPEN_WINDOW
 *
 */ 
class ZC_REFINE_OPEN_WINDOW : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REFINE_OPEN_WINDOW(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REFINE_OPEN_WINDOW, s)
	{}
	virtual ~ZC_REFINE_OPEN_WINDOW() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181002 || \
	PACKET_VERSION >= 20180919 || \
	PACKET_VERSION >= 20180912 || \
	PACKET_VERSION >= 20180905 || \
	PACKET_VERSION >= 20180829 || \
	PACKET_VERSION >= 20180822 || \
	PACKET_VERSION >= 0
	ID_ZC_INVENTORY_START = 0x0b08
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INVENTORY_START
 *
 */ 
class ZC_INVENTORY_START : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INVENTORY_START(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INVENTORY_START, s)
	{}
	virtual ~ZC_INVENTORY_START() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_CLOSE_DIALOG = 0x00b6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CLOSE_DIALOG
 *
 */ 
class ZC_CLOSE_DIALOG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CLOSE_DIALOG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CLOSE_DIALOG, s)
	{}
	virtual ~ZC_CLOSE_DIALOG() {}

	void deliver(int32_t guid);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid{0};
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_DELETE_RELATED_GUILD = 0x0184
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DELETE_RELATED_GUILD
 *
 */ 
class ZC_DELETE_RELATED_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DELETE_RELATED_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DELETE_RELATED_GUILD, s)
	{}
	virtual ~ZC_DELETE_RELATED_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100914 || \
	PACKET_VERSION >= 20100824 || \
	PACKET_VERSION >= 0
	ID_ZC_SE_PC_BUY_CASHITEM_RESULT = 0x0849
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SE_PC_BUY_CASHITEM_RESULT
 *
 */ 
class ZC_SE_PC_BUY_CASHITEM_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SE_PC_BUY_CASHITEM_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SE_PC_BUY_CASHITEM_RESULT, s)
	{}
	virtual ~ZC_SE_PC_BUY_CASHITEM_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20131127 || \
	PACKET_VERSION >= 20131120 || \
	PACKET_VERSION >= 0
	ID_ZC_UPDATE_ITEM_FROM_BUYING_STORE2 = 0x09e6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_ITEM_FROM_BUYING_STORE2
 *
 */ 
class ZC_UPDATE_ITEM_FROM_BUYING_STORE2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_ITEM_FROM_BUYING_STORE2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_ITEM_FROM_BUYING_STORE2, s)
	{}
	virtual ~ZC_UPDATE_ITEM_FROM_BUYING_STORE2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20060626 || \
	PACKET_VERSION >= 0
	ID_ZC_PCBANG_EFFECT = 0x027b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PCBANG_EFFECT
 *
 */ 
class ZC_PCBANG_EFFECT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PCBANG_EFFECT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PCBANG_EFFECT, s)
	{}
	virtual ~ZC_PCBANG_EFFECT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111108 || \
	PACKET_VERSION >= 20111025 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_FAILED_RECALL = 0x08f8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_FAILED_RECALL
 *
 */ 
class ZC_PARTY_RECRUIT_FAILED_RECALL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_FAILED_RECALL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_FAILED_RECALL, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_FAILED_RECALL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090617 || \
	PACKET_VERSION >= 0
	ID_ZC_SEEK_PARTY_MEMBER = 0x07df
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SEEK_PARTY_MEMBER
 *
 */ 
class ZC_SEEK_PARTY_MEMBER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SEEK_PARTY_MEMBER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SEEK_PARTY_MEMBER, s)
	{}
	virtual ~ZC_SEEK_PARTY_MEMBER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20170308 || \
	PACKET_VERSION >= 0
	ID_ZC_UNKNOWN_CLEAN_ITEMS_LISTS = 0x0ac8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UNKNOWN_CLEAN_ITEMS_LISTS
 *
 */ 
class ZC_UNKNOWN_CLEAN_ITEMS_LISTS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UNKNOWN_CLEAN_ITEMS_LISTS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UNKNOWN_CLEAN_ITEMS_LISTS, s)
	{}
	virtual ~ZC_UNKNOWN_CLEAN_ITEMS_LISTS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130515 || \
	PACKET_VERSION >= 20130320 || \
	PACKET_VERSION >= 20130306 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_BANKING_WITHDRAW = 0x09aa
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_BANKING_WITHDRAW
 *
 */ 
class ZC_ACK_BANKING_WITHDRAW : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_BANKING_WITHDRAW(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_BANKING_WITHDRAW, s)
	{}
	virtual ~ZC_ACK_BANKING_WITHDRAW() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140521 || \
	PACKET_VERSION >= 20140416 || \
	PACKET_VERSION >= 20140326 || \
	PACKET_VERSION >= 20140305 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REMOVE_RODEX_ITEM = 0x0a07
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REMOVE_RODEX_ITEM
 *
 */ 
class ZC_ACK_REMOVE_RODEX_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REMOVE_RODEX_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REMOVE_RODEX_ITEM, s)
	{}
	virtual ~ZC_ACK_REMOVE_RODEX_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20101102 || \
	PACKET_VERSION >= 0
	ID_ZC_MACRO_ITEMPICKUP_FAIL = 0x0855
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MACRO_ITEMPICKUP_FAIL
 *
 */ 
class ZC_MACRO_ITEMPICKUP_FAIL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MACRO_ITEMPICKUP_FAIL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MACRO_ITEMPICKUP_FAIL, s)
	{}
	virtual ~ZC_MACRO_ITEMPICKUP_FAIL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050718 || \
	PACKET_VERSION >= 0
	ID_ZC_AUCTION_ITEM_REQ_SEARCH = 0x0252
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_AUCTION_ITEM_REQ_SEARCH
 *
 */ 
class ZC_AUCTION_ITEM_REQ_SEARCH : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_AUCTION_ITEM_REQ_SEARCH(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_AUCTION_ITEM_REQ_SEARCH, s)
	{}
	virtual ~ZC_AUCTION_ITEM_REQ_SEARCH() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum zc_server_reject_type : int8_t
{
	ZONE_SERV_ERROR_REJECT = 3,
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_REFUSE_ENTER = 0x0074
#endif
};

/**
 * @brief Main object for the aegis packet: ZC_REFUSE_ENTER
 *
 */ 
class ZC_REFUSE_ENTER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REFUSE_ENTER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REFUSE_ENTER, s)
	{}
	virtual ~ZC_REFUSE_ENTER() {}

	void deliver(zc_server_reject_type error);
	ByteBuffer &serialize();

/* Structure */
	zc_server_reject_type _error;
};

enum {
#if PACKET_VERSION >= 20080527 || \
	PACKET_VERSION >= 20080521 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 0
	ID_ZC_SIMPLE_CASHSHOP_POINT_ITEMLIST = 0x035d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SIMPLE_CASHSHOP_POINT_ITEMLIST
 *
 */ 
class ZC_SIMPLE_CASHSHOP_POINT_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SIMPLE_CASHSHOP_POINT_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SIMPLE_CASHSHOP_POINT_ITEMLIST, s)
	{}
	virtual ~ZC_SIMPLE_CASHSHOP_POINT_ITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120925 || \
	PACKET_VERSION >= 0
	ID_ZC_INVENTORY_ITEMLIST_NORMAL_V5 = 0x0991
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INVENTORY_ITEMLIST_NORMAL_V5
 *
 */ 
class ZC_INVENTORY_ITEMLIST_NORMAL_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INVENTORY_ITEMLIST_NORMAL_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INVENTORY_ITEMLIST_NORMAL_V5, s)
	{}
	virtual ~ZC_INVENTORY_ITEMLIST_NORMAL_V5() {}

	void deliver(std::vector<std::shared_ptr<const item_entry_data>> const &items);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{0};
	std::vector<std::shared_ptr<const item_entry_data>> _items;
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_USESKILL_ACK = 0x013e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_USESKILL_ACK
 *
 */ 
class ZC_USESKILL_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_USESKILL_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_USESKILL_ACK, s)
	{}
	virtual ~ZC_USESKILL_ACK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140827 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_CHANGE_TITLE = 0x0a2f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_CHANGE_TITLE
 *
 */ 
class ZC_ACK_CHANGE_TITLE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_CHANGE_TITLE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_CHANGE_TITLE, s)
	{}
	virtual ~ZC_ACK_CHANGE_TITLE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20071023 || \
	PACKET_VERSION >= 20070828 || \
	PACKET_VERSION >= 0
	ID_ZC_MEMORIALDUNGEON_SUBSCRIPTION_INFO = 0x02cb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MEMORIALDUNGEON_SUBSCRIPTION_INFO
 *
 */ 
class ZC_MEMORIALDUNGEON_SUBSCRIPTION_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MEMORIALDUNGEON_SUBSCRIPTION_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MEMORIALDUNGEON_SUBSCRIPTION_INFO, s)
	{}
	virtual ~ZC_MEMORIALDUNGEON_SUBSCRIPTION_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110810 || \
	PACKET_VERSION >= 20110809 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_WEAR_EQUIP_ACK2 = 0x08d0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_WEAR_EQUIP_ACK2
 *
 */ 
class ZC_REQ_WEAR_EQUIP_ACK2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_WEAR_EQUIP_ACK2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_WEAR_EQUIP_ACK2, s)
	{}
	virtual ~ZC_REQ_WEAR_EQUIP_ACK2() {}

	void deliver(int16_t inventory_index, int32_t equip_location_mask, int16_t sprite_id, item_equip_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int16_t _inventory_index{0};
	int32_t _equip_location_mask{0};
	int16_t _sprite_id{0};
	int8_t _result{0};
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_RESTART_ACK = 0x00b3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_RESTART_ACK
 *
 */
class ZC_RESTART_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_RESTART_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_RESTART_ACK, s)
	{}
	virtual ~ZC_RESTART_ACK() {}

	void deliver(int8_t type);
	ByteBuffer &serialize();

/* Structure */
	int8_t _type{0};
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_UPDATE_GDID = 0x016c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_GDID
 *
 */ 
class ZC_UPDATE_GDID : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_GDID(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_GDID, s)
	{}
	virtual ~ZC_UPDATE_GDID() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_SHOW_IMAGE2 = 0x01b3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SHOW_IMAGE2
 *
 */ 
class ZC_SHOW_IMAGE2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SHOW_IMAGE2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SHOW_IMAGE2, s)
	{}
	virtual ~ZC_SHOW_IMAGE2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_FRIENDS_LIST = 0x0201
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FRIENDS_LIST
 *
 */ 
class ZC_FRIENDS_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FRIENDS_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FRIENDS_LIST, s)
	{}
	virtual ~ZC_FRIENDS_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_INITCHAR = 0x0075
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_INITCHAR
 *
 */ 
class ZC_NOTIFY_INITCHAR : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_INITCHAR(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_INITCHAR, s)
	{}
	virtual ~ZC_NOTIFY_INITCHAR() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_START_CAPTURE = 0x019e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_START_CAPTURE
 *
 */ 
class ZC_START_CAPTURE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_START_CAPTURE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_START_CAPTURE, s)
	{}
	virtual ~ZC_START_CAPTURE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140212 || \
	PACKET_VERSION >= 0
	ID_ZC_DRESSROOM_OPEN = 0x0a02
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DRESSROOM_OPEN
 *
 */ 
class ZC_DRESSROOM_OPEN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DRESSROOM_OPEN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DRESSROOM_OPEN, s)
	{}
	virtual ~ZC_DRESSROOM_OPEN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130515
	ID_ZC_ACTION_MOVE = 0x09c0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACTION_MOVE
 *
 */ 
class ZC_ACTION_MOVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACTION_MOVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACTION_MOVE, s)
	{}
	virtual ~ZC_ACTION_MOVE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111122 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_ITEMLIST_EQUIP = 0x0905
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_ITEMLIST_EQUIP
 *
 */ 
class ZC_STORE_ITEMLIST_EQUIP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_ITEMLIST_EQUIP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_ITEMLIST_EQUIP, s)
	{}
	virtual ~ZC_STORE_ITEMLIST_EQUIP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140611 || \
	PACKET_VERSION >= 20140605 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_OPEN_ROULETTE = 0x0a1a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_OPEN_ROULETTE
 *
 */ 
class ZC_ACK_OPEN_ROULETTE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_OPEN_ROULETTE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_OPEN_ROULETTE, s)
	{}
	virtual ~ZC_ACK_OPEN_ROULETTE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_NORMAL_ITEMLIST = 0x00a5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_NORMAL_ITEMLIST
 *
 */ 
class ZC_STORE_NORMAL_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_NORMAL_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_NORMAL_ITEMLIST, s)
	{}
	virtual ~ZC_STORE_NORMAL_ITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20151118 || \
	PACKET_VERSION >= 0
	ID_ZC_AIRSHIP_SERVERMOVE = 0x0a4c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_AIRSHIP_SERVERMOVE
 *
 */ 
class ZC_AIRSHIP_SERVERMOVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_AIRSHIP_SERVERMOVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_AIRSHIP_SERVERMOVE, s)
	{}
	virtual ~ZC_AIRSHIP_SERVERMOVE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_PC_SELL_RESULT = 0x00cb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PC_SELL_RESULT
 *
 */ 
class ZC_PC_SELL_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PC_SELL_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PC_SELL_RESULT, s)
	{}
	virtual ~ZC_PC_SELL_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MOVEENTRY = 0x007b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MOVEENTRY
 *
 */ 
class ZC_NOTIFY_MOVEENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MOVEENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MOVEENTRY, s)
	{}
	virtual ~ZC_NOTIFY_MOVEENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130417 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_CLOSE_BANKING = 0x09b9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_CLOSE_BANKING
 *
 */ 
class ZC_ACK_CLOSE_BANKING : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_CLOSE_BANKING(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_CLOSE_BANKING, s)
	{}
	virtual ~ZC_ACK_CLOSE_BANKING() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_BROADCAST = 0x009a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BROADCAST
 *
 */ 
class ZC_BROADCAST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BROADCAST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BROADCAST, s)
	{}
	virtual ~ZC_BROADCAST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090708 || \
	PACKET_VERSION >= 0
	ID_ZC_ES_NOTI_MYINFO = 0x07e0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ES_NOTI_MYINFO
 *
 */ 
class ZC_ES_NOTI_MYINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ES_NOTI_MYINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ES_NOTI_MYINFO, s)
	{}
	virtual ~ZC_ES_NOTI_MYINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120228 || \
	PACKET_VERSION >= 20120214 || \
	PACKET_VERSION >= 0
	ID_ZC_MERGE_ITEM_OPEN = 0x096d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MERGE_ITEM_OPEN
 *
 */ 
class ZC_MERGE_ITEM_OPEN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MERGE_ITEM_OPEN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MERGE_ITEM_OPEN, s)
	{}
	virtual ~ZC_MERGE_ITEM_OPEN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20031218 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_NORMAL_ITEMLIST2 = 0x01f0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_NORMAL_ITEMLIST2
 *
 */ 
class ZC_STORE_NORMAL_ITEMLIST2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_NORMAL_ITEMLIST2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_NORMAL_ITEMLIST2, s)
	{}
	virtual ~ZC_STORE_NORMAL_ITEMLIST2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120503 || \
	PACKET_VERSION >= 20120502 || \
	PACKET_VERSION >= 0
	ID_ZC_SELECTCART = 0x097f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SELECTCART
 *
 */ 
class ZC_SELECTCART : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SELECTCART(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SELECTCART, s)
	{}
	virtual ~ZC_SELECTCART() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050624 || \
	PACKET_VERSION >= 20050622 || \
	PACKET_VERSION >= 20050530 || \
	PACKET_VERSION >= 20050523 || \
	PACKET_VERSION >= 0
	ID_ZC_PROPERTY_HOMUN = 0x022e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PROPERTY_HOMUN
 *
 */ 
class ZC_PROPERTY_HOMUN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PROPERTY_HOMUN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PROPERTY_HOMUN, s)
	{}
	virtual ~ZC_PROPERTY_HOMUN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111004 || \
	PACKET_VERSION >= 0
	ID_ZC_REPLY_ACK_ENTRY_QUEUE_ADMISSION = 0x08de
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REPLY_ACK_ENTRY_QUEUE_ADMISSION
 *
 */ 
class ZC_REPLY_ACK_ENTRY_QUEUE_ADMISSION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REPLY_ACK_ENTRY_QUEUE_ADMISSION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REPLY_ACK_ENTRY_QUEUE_ADMISSION, s)
	{}
	virtual ~ZC_REPLY_ACK_ENTRY_QUEUE_ADMISSION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110131 || \
	PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 0
	ID_ZC_IRMAIL_SEND_RES = 0x02f4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_IRMAIL_SEND_RES
 *
 */ 
class ZC_IRMAIL_SEND_RES : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_IRMAIL_SEND_RES(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_IRMAIL_SEND_RES, s)
	{}
	virtual ~ZC_IRMAIL_SEND_RES() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130515 || \
	PACKET_VERSION >= 20130320 || \
	PACKET_VERSION >= 20130306 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_BANKING_DEPOSIT = 0x09a8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_BANKING_DEPOSIT
 *
 */ 
class ZC_ACK_BANKING_DEPOSIT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_BANKING_DEPOSIT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_BANKING_DEPOSIT, s)
	{}
	virtual ~ZC_ACK_BANKING_DEPOSIT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20101221 || \
	PACKET_VERSION >= 0
	ID_ZC_MCSTORE_NOTMOVEITEM_LIST = 0x08b1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MCSTORE_NOTMOVEITEM_LIST
 *
 */ 
class ZC_MCSTORE_NOTMOVEITEM_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MCSTORE_NOTMOVEITEM_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MCSTORE_NOTMOVEITEM_LIST, s)
	{}
	virtual ~ZC_MCSTORE_NOTMOVEITEM_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20070611
	ID_ZC_HACKSHIELD_CRC_MSG = 0x02a8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HACKSHIELD_CRC_MSG
 *
 */ 
class ZC_HACKSHIELD_CRC_MSG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HACKSHIELD_CRC_MSG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HACKSHIELD_CRC_MSG, s)
	{}
	virtual ~ZC_HACKSHIELD_CRC_MSG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120523 || \
	PACKET_VERSION >= 20120522 || \
	PACKET_VERSION >= 20120515 || \
	PACKET_VERSION >= 0
	ID_ZC_FATIGUE_CHN = 0x0982
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FATIGUE_CHN
 *
 */ 
class ZC_FATIGUE_CHN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FATIGUE_CHN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FATIGUE_CHN, s)
	{}
	virtual ~ZC_FATIGUE_CHN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NPCACK_MAPMOVE = 0x0091
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NPCACK_MAPMOVE
 *
 */ 
class ZC_NPCACK_MAPMOVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NPCACK_MAPMOVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NPCACK_MAPMOVE, s)
	{}
	virtual ~ZC_NPCACK_MAPMOVE() {}

	void deliver(std::string map_name, int16_t x, int16_t y);
	ByteBuffer &serialize();

/* Structure */
	char _map_name[MAP_NAME_LENGTH_EXT]{0};
	int16_t _x{0};
	int16_t _y{0};
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_ENTRY = 0x009d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_ENTRY
 *
 */ 
class ZC_ITEM_ENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_ENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_ENTRY, s)
	{}
	virtual ~ZC_ITEM_ENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100817 || \
	PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081210 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_SELECT_REQUEST = 0x0442
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_SELECT_REQUEST
 *
 */ 
class ZC_SKILL_SELECT_REQUEST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_SELECT_REQUEST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_SELECT_REQUEST, s)
	{}
	virtual ~ZC_SKILL_SELECT_REQUEST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111025 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_ACK_DELETE = 0x08ea
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_ACK_DELETE
 *
 */ 
class ZC_PARTY_RECRUIT_ACK_DELETE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_ACK_DELETE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_ACK_DELETE, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_ACK_DELETE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070918 || \
	PACKET_VERSION >= 0
	ID_ZC_CONFIG = 0x02d9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CONFIG
 *
 */ 
class ZC_CONFIG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CONFIG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CONFIG, s)
	{}
	virtual ~ZC_CONFIG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_ENTRY = 0x011f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_ENTRY
 *
 */ 
class ZC_SKILL_ENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_ENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_ENTRY, s)
	{}
	virtual ~ZC_SKILL_ENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_EXCHANGE_ITEM = 0x00e7
#endif
};

enum zc_ack_exchange_item_result_type
{
	ZCACK_EXCHANGEITEM_CHAR_TOO_FAR = 0,
	ZCACK_EXCHANGEITEM_CHAR_DOES_NOT_EXIST = 1,
	ZCACK_EXCHANGEITEM_TRADE_FAILED = 2,
	ZCACK_EXCHANGEITEM_ACCEPT = 3,
	ZCACK_EXCHANGEITEM_CANCEL = 4,
	ZCACK_EXCHANGEITEM_BUSY = 5
};

/**
 * @brief Main object for the aegis packet: ZC_ACK_EXCHANGE_ITEM
 *
 */ 
class ZC_ACK_EXCHANGE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_EXCHANGE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_EXCHANGE_ITEM, s)
	{}
	virtual ~ZC_ACK_EXCHANGE_ITEM() {}

	void deliver(zc_ack_exchange_item_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int8_t _result{ 0 };
};

enum {
#if PACKET_VERSION >= 20060918 || \
	PACKET_VERSION >= 0
	ID_ZC_DEATH_QUESTION = 0x0285
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DEATH_QUESTION
 *
 */ 
class ZC_DEATH_QUESTION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DEATH_QUESTION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DEATH_QUESTION, s)
	{}
	virtual ~ZC_DEATH_QUESTION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20041108 || \
	PACKET_VERSION >= 0
	ID_ZC_BLACKSMITH_POINT = 0x021b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BLACKSMITH_POINT
 *
 */ 
class ZC_BLACKSMITH_POINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BLACKSMITH_POINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BLACKSMITH_POINT, s)
	{}
	virtual ~ZC_BLACKSMITH_POINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_DISAPPEAR = 0x00a1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_DISAPPEAR
 *
 */ 
class ZC_ITEM_DISAPPEAR : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_DISAPPEAR(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_DISAPPEAR, s)
	{}
	virtual ~ZC_ITEM_DISAPPEAR() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_OPEN_MEMBER_INFO = 0x0158
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_OPEN_MEMBER_INFO
 *
 */ 
class ZC_ACK_OPEN_MEMBER_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_OPEN_MEMBER_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_OPEN_MEMBER_INFO, s)
	{}
	virtual ~ZC_ACK_OPEN_MEMBER_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20180912 || \
	PACKET_VERSION >= 20180905 || \
	PACKET_VERSION >= 20180829 || \
	PACKET_VERSION >= 20180822 || \
	PACKET_VERSION >= 0
	ID_ZC_INVENTORY_END = 0x0b0b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INVENTORY_END
 *
 */ 
class ZC_INVENTORY_END : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INVENTORY_END(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INVENTORY_END, s)
	{}
	virtual ~ZC_INVENTORY_END() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140409 || \
	PACKET_VERSION >= 20140326 || \
	PACKET_VERSION >= 20140115 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ZENY_FROM_RODEX = 0x09f2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ZENY_FROM_RODEX
 *
 */ 
class ZC_ACK_ZENY_FROM_RODEX : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ZENY_FROM_RODEX(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ZENY_FROM_RODEX, s)
	{}
	virtual ~ZC_ACK_ZENY_FROM_RODEX() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_GUILD_SKILLINFO = 0x0162
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILD_SKILLINFO
 *
 */ 
class ZC_GUILD_SKILLINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILD_SKILLINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILD_SKILLINFO, s)
	{}
	virtual ~ZC_GUILD_SKILLINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111101 || \
	PACKET_VERSION >= 0
	ID_ZC_EFST_SET_ENTER = 0x08ff
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EFST_SET_ENTER
 *
 */ 
class ZC_EFST_SET_ENTER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EFST_SET_ENTER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EFST_SET_ENTER, s)
	{}
	virtual ~ZC_EFST_SET_ENTER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20071002 || \
	PACKET_VERSION >= 0
	ID_ZC_BATTLEFIELD_CHAT = 0x02dc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BATTLEFIELD_CHAT
 *
 */ 
class ZC_BATTLEFIELD_CHAT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BATTLEFIELD_CHAT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BATTLEFIELD_CHAT, s)
	{}
	virtual ~ZC_BATTLEFIELD_CHAT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_RANKING = 0x019a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_RANKING
 *
 */ 
class ZC_NOTIFY_RANKING : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_RANKING(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_RANKING, s)
	{}
	virtual ~ZC_NOTIFY_RANKING() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110419 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_ENTRY3 = 0x08c7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_ENTRY3
 *
 */ 
class ZC_SKILL_ENTRY3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_ENTRY3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_ENTRY3, s)
	{}
	virtual ~ZC_SKILL_ENTRY3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_ENTRY2 = 0x01c9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_ENTRY2
 *
 */ 
class ZC_SKILL_ENTRY2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_ENTRY2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_ENTRY2, s)
	{}
	virtual ~ZC_SKILL_ENTRY2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130828 || \
	PACKET_VERSION >= 20130618 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_ENTRY5 = 0x09ca
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_ENTRY5
 *
 */ 
class ZC_SKILL_ENTRY5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_ENTRY5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_ENTRY5, s)
	{}
	virtual ~ZC_SKILL_ENTRY5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20121212 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_ENTRY4 = 0x099f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_ENTRY4
 *
 */ 
class ZC_SKILL_ENTRY4 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_ENTRY4(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_ENTRY4, s)
	{}
	virtual ~ZC_SKILL_ENTRY4() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130814 || \
	PACKET_VERSION >= 0
	ID_ZC_NPROTECTGAMEGUARDCSAUTH = 0x09cf
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NPROTECTGAMEGUARDCSAUTH
 *
 */ 
class ZC_NPROTECTGAMEGUARDCSAUTH : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NPROTECTGAMEGUARDCSAUTH(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NPROTECTGAMEGUARDCSAUTH, s)
	{}
	virtual ~ZC_NPROTECTGAMEGUARDCSAUTH() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REQNAME_BYGID = 0x0194
#elif PACKET_VERSION >= 20180207 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REQNAME_BYGID = 0x0af7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQNAME_BYGID
 *
 */ 
class ZC_ACK_REQNAME_BYGID : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQNAME_BYGID(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQNAME_BYGID, s)
	{}
	virtual ~ZC_ACK_REQNAME_BYGID() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20071023 || \
	PACKET_VERSION >= 20070828 || \
	PACKET_VERSION >= 0
	ID_ZC_MEMORIALDUNGEON_INFO = 0x02cd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MEMORIALDUNGEON_INFO
 *
 */ 
class ZC_MEMORIALDUNGEON_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MEMORIALDUNGEON_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MEMORIALDUNGEON_INFO, s)
	{}
	virtual ~ZC_MEMORIALDUNGEON_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_USE_SKILL = 0x011a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_USE_SKILL
 *
 */ 
class ZC_USE_SKILL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_USE_SKILL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_USE_SKILL, s)
	{}
	virtual ~ZC_USE_SKILL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_SHOW_IMAGE = 0x0145
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SHOW_IMAGE
 *
 */ 
class ZC_SHOW_IMAGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SHOW_IMAGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SHOW_IMAGE, s)
	{}
	virtual ~ZC_SHOW_IMAGE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140409 || \
	PACKET_VERSION >= 20140326 || \
	PACKET_VERSION >= 20140305 || \
	PACKET_VERSION >= 20140115 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ITEM_FROM_RODEX = 0x09f4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ITEM_FROM_RODEX
 *
 */ 
class ZC_ACK_ITEM_FROM_RODEX : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ITEM_FROM_RODEX(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ITEM_FROM_RODEX, s)
	{}
	virtual ~ZC_ACK_ITEM_FROM_RODEX() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140430 || \
	PACKET_VERSION >= 0
	ID_ZC_DYNAMICNPC_CREATE_RESULT = 0x0a17
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DYNAMICNPC_CREATE_RESULT
 *
 */ 
class ZC_DYNAMICNPC_CREATE_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DYNAMICNPC_CREATE_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DYNAMICNPC_CREATE_RESULT, s)
	{}
	virtual ~ZC_DYNAMICNPC_CREATE_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_USE_ITEM_ACK2 = 0x01c8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_USE_ITEM_ACK2
 *
 */ 
class ZC_USE_ITEM_ACK2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_USE_ITEM_ACK2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_USE_ITEM_ACK2, s)
	{}
	virtual ~ZC_USE_ITEM_ACK2() {}

	void deliver(int16_t index, int16_t item_id, int32_t target_guid, int16_t amount, bool success);
	ByteBuffer &serialize();

/* Structure */
	int16_t _index;
	int16_t _item_id;
	int32_t _target_guid;
	int16_t _amount;
	int8_t _success;
};

enum {
#if PACKET_VERSION >= 20091124 || \
	PACKET_VERSION >= 0
	ID_ZC_USESKILL_ACK2 = 0x07fb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_USESKILL_ACK2
 *
 */ 
class ZC_USESKILL_ACK2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_USESKILL_ACK2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_USESKILL_ACK2, s)
	{}
	virtual ~ZC_USESKILL_ACK2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100608 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_BAN_GUILD_SSO = 0x0839
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_BAN_GUILD_SSO
 *
 */ 
class ZC_ACK_BAN_GUILD_SSO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_BAN_GUILD_SSO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_BAN_GUILD_SSO, s)
	{}
	virtual ~ZC_ACK_BAN_GUILD_SSO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20041129 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_WEAPONITEMLIST = 0x0221
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_WEAPONITEMLIST
 *
 */ 
class ZC_NOTIFY_WEAPONITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_WEAPONITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_WEAPONITEMLIST, s)
	{}
	virtual ~ZC_NOTIFY_WEAPONITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_PC_PURCHASE_ITEMLIST = 0x00c6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PC_PURCHASE_ITEMLIST
 *
 */ 
class ZC_PC_PURCHASE_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PC_PURCHASE_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PC_PURCHASE_ITEMLIST, s)
	{}
	virtual ~ZC_PC_PURCHASE_ITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090818 || \
	PACKET_VERSION >= 0
	ID_ZC_MSG_SKILL = 0x07e6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MSG_SKILL
 *
 */ 
class ZC_MSG_SKILL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MSG_SKILL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MSG_SKILL, s)
	{}
	virtual ~ZC_MSG_SKILL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20061211 || \
	PACKET_VERSION >= 0
	ID_ZC_CASH_TIME_COUNTER = 0x0298
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CASH_TIME_COUNTER
 *
 */ 
class ZC_CASH_TIME_COUNTER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CASH_TIME_COUNTER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CASH_TIME_COUNTER, s)
	{}
	virtual ~ZC_CASH_TIME_COUNTER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_WHISPER_LIST = 0x00d4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_WHISPER_LIST
 *
 */ 
class ZC_WHISPER_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_WHISPER_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_WHISPER_LIST, s)
	{}
	virtual ~ZC_WHISPER_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20170726 || \
	PACKET_VERSION >= 0
	ID_ZC_REFINE_STATUS = 0x0ada
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REFINE_STATUS
 *
 */ 
class ZC_REFINE_STATUS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REFINE_STATUS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REFINE_STATUS, s)
	{}
	virtual ~ZC_REFINE_STATUS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_EFFECT = 0x019b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_EFFECT
 *
 */ 
class ZC_NOTIFY_EFFECT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_EFFECT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_EFFECT, s)
	{}
	virtual ~ZC_NOTIFY_EFFECT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091222 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_BOOKING_ACK_REGISTER = 0x0803
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_BOOKING_ACK_REGISTER
 *
 */ 
class ZC_PARTY_BOOKING_ACK_REGISTER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_BOOKING_ACK_REGISTER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_BOOKING_ACK_REGISTER, s)
	{}
	virtual ~ZC_PARTY_BOOKING_ACK_REGISTER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20101102 || \
	PACKET_VERSION >= 0
	ID_ZC_GPK_DYNCODE = 0x0851
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GPK_DYNCODE
 *
 */ 
class ZC_GPK_DYNCODE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GPK_DYNCODE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GPK_DYNCODE, s)
	{}
	virtual ~ZC_GPK_DYNCODE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140924 || \
	PACKET_VERSION >= 0
	ID_ZC_UPDATE_TAIWANCASH = 0x0a34
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_TAIWANCASH
 *
 */ 
class ZC_UPDATE_TAIWANCASH : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_TAIWANCASH(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_TAIWANCASH, s)
	{}
	virtual ~ZC_UPDATE_TAIWANCASH() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20041108 || \
	PACKET_VERSION >= 0
	ID_ZC_ALCHEMIST_POINT = 0x021c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALCHEMIST_POINT
 *
 */ 
class ZC_ALCHEMIST_POINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALCHEMIST_POINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALCHEMIST_POINT, s)
	{}
	virtual ~ZC_ALCHEMIST_POINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050103 || \
	PACKET_VERSION >= 20041220 || \
	PACKET_VERSION >= 20040817 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_PVPPOINT = 0x0210
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_PVPPOINT
 *
 */ 
class ZC_ACK_PVPPOINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_PVPPOINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_PVPPOINT, s)
	{}
	virtual ~ZC_ACK_PVPPOINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140312 || \
	PACKET_VERSION >= 20140305 || \
	PACKET_VERSION >= 0
	ID_ZC_INVENTORY_ITEMLIST_EQUIP_V6 = 0x0a0d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INVENTORY_ITEMLIST_EQUIP_V6
 *
 */ 
class ZC_INVENTORY_ITEMLIST_EQUIP_V6 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INVENTORY_ITEMLIST_EQUIP_V6(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INVENTORY_ITEMLIST_EQUIP_V6, s)
	{}
	virtual ~ZC_INVENTORY_ITEMLIST_EQUIP_V6() {}

	void deliver(std::vector<std::shared_ptr<const item_entry_data>> const &items);
	ByteBuffer &serialize();

/* Structure */
	std::vector<std::shared_ptr<const item_entry_data>> _items;
};

enum {
#if PACKET_VERSION >= 20071002 || \
	PACKET_VERSION >= 0
	ID_ZC_BATTLEFIELD_NOTIFY_POSITION = 0x02df
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BATTLEFIELD_NOTIFY_POSITION
 *
 */ 
class ZC_BATTLEFIELD_NOTIFY_POSITION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BATTLEFIELD_NOTIFY_POSITION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BATTLEFIELD_NOTIFY_POSITION, s)
	{}
	virtual ~ZC_BATTLEFIELD_NOTIFY_POSITION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130502 || \
	PACKET_VERSION >= 20130424 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_OPEN_GUILD_STORAGE = 0x09bb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_OPEN_GUILD_STORAGE
 *
 */ 
class ZC_ACK_OPEN_GUILD_STORAGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_OPEN_GUILD_STORAGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_OPEN_GUILD_STORAGE, s)
	{}
	virtual ~ZC_ACK_OPEN_GUILD_STORAGE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20040426 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ITEMREPAIR = 0x01fe
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ITEMREPAIR
 *
 */ 
class ZC_ACK_ITEMREPAIR : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ITEMREPAIR(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ITEMREPAIR, s)
	{}
	virtual ~ZC_ACK_ITEMREPAIR() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120925 || \
	PACKET_VERSION >= 0
	ID_ZC_INVENTORY_ITEMLIST_EQUIP_V5 = 0x0992
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INVENTORY_ITEMLIST_EQUIP_V5
 *
 */ 
class ZC_INVENTORY_ITEMLIST_EQUIP_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INVENTORY_ITEMLIST_EQUIP_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INVENTORY_ITEMLIST_EQUIP_V5, s)
	{}
	virtual ~ZC_INVENTORY_ITEMLIST_EQUIP_V5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100420 || \
	PACKET_VERSION >= 20100309 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_DELETE_BUYING_STORE = 0x081c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_DELETE_BUYING_STORE
 *
 */ 
class ZC_ITEM_DELETE_BUYING_STORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_DELETE_BUYING_STORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_DELETE_BUYING_STORE, s)
	{}
	virtual ~ZC_ITEM_DELETE_BUYING_STORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070918 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIPWIN_MICROSCOPE = 0x02d7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIPWIN_MICROSCOPE
 *
 */ 
class ZC_EQUIPWIN_MICROSCOPE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIPWIN_MICROSCOPE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIPWIN_MICROSCOPE, s)
	{}
	virtual ~ZC_EQUIPWIN_MICROSCOPE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SPRITE_CHANGE = 0x00c3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SPRITE_CHANGE
 *
 */ 
class ZC_SPRITE_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SPRITE_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SPRITE_CHANGE, s)
	{}
	virtual ~ZC_SPRITE_CHANGE() {}

	void deliver(int32_t guid, entity_appearance_type look_type, int32_t look_id, int32_t look_shield = 0);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid;
	int8_t _look_type;
	int32_t _look_id;
	int32_t _shield_id;
};

enum {
#if PACKET_VERSION >= 20070904 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_BIND_ON_EQUIP = 0x02d3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_BIND_ON_EQUIP
 *
 */ 
class ZC_NOTIFY_BIND_ON_EQUIP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_BIND_ON_EQUIP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_BIND_ON_EQUIP, s)
	{}
	virtual ~ZC_NOTIFY_BIND_ON_EQUIP() {}

	void deliver(int16_t index);
	ByteBuffer &serialize();

/* Structure */
	int16_t _index;
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_PC_PURCHASE_RESULT = 0x00ca
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PC_PURCHASE_RESULT
 *
 */ 
class ZC_PC_PURCHASE_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PC_PURCHASE_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PC_PURCHASE_RESULT, s)
	{}
	virtual ~ZC_PC_PURCHASE_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070622 || \
	PACKET_VERSION >= 20070605 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIPITEM_DAMAGED = 0x02bb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIPITEM_DAMAGED
 *
 */ 
class ZC_EQUIPITEM_DAMAGED : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIPITEM_DAMAGED(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIPITEM_DAMAGED, s)
	{}
	virtual ~ZC_EQUIPITEM_DAMAGED() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100420 || \
	PACKET_VERSION >= 20100413 || \
	PACKET_VERSION >= 20100406 || \
	PACKET_VERSION >= 20100331 || \
	PACKET_VERSION >= 20100309 || \
	PACKET_VERSION >= 0
	ID_ZC_FAILED_TRADE_BUYING_STORE_TO_BUYER = 0x081a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FAILED_TRADE_BUYING_STORE_TO_BUYER
 *
 */ 
class ZC_FAILED_TRADE_BUYING_STORE_TO_BUYER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FAILED_TRADE_BUYING_STORE_TO_BUYER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FAILED_TRADE_BUYING_STORE_TO_BUYER, s)
	{}
	virtual ~ZC_FAILED_TRADE_BUYING_STORE_TO_BUYER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_OPENSTORE = 0x012d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OPENSTORE
 *
 */ 
class ZC_OPENSTORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OPENSTORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OPENSTORE, s)
	{}
	virtual ~ZC_OPENSTORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111004 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_LOBBY_ADMISSION = 0x08df
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_LOBBY_ADMISSION
 *
 */ 
class ZC_NOTIFY_LOBBY_ADMISSION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_LOBBY_ADMISSION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_LOBBY_ADMISSION, s)
	{}
	virtual ~ZC_NOTIFY_LOBBY_ADMISSION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20131030 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_WHISPER02 = 0x09df
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_WHISPER02
 *
 */ 
enum zc_whisper_result_type {
	WRT_SUCCESS               = 0,
	WRT_RECIPIENT_OFFLINE     = 1,
	WRT_RECIPIENT_IGNORE      = 2,
	WRT_RECIPIENT_IGNORE_ALL  = 3
};
class ZC_ACK_WHISPER02 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_WHISPER02(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_WHISPER02, s)
	{}
	virtual ~ZC_ACK_WHISPER02() {}

	void deliver(zc_whisper_result_type result, int32_t recipient_char_id);
	ByteBuffer &serialize();

/* Structure */
/// result:
///     0 = success to send wisper
///     1 = target character is not loged in
///     2 = ignored by target
///     3 = everyone ignored by target
	int8_t _result;
	int32_t _recipient_char_id;
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111108 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER = 0x08fa
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER
 *
 */ 
class ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_REFUSE_VOLUNTEER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110803 || \
	PACKET_VERSION >= 20110802 || \
	PACKET_VERSION >= 0
	ID_ZC_STOPMOVE_FORCE = 0x08cd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STOPMOVE_FORCE
 *
 */ 
class ZC_STOPMOVE_FORCE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STOPMOVE_FORCE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STOPMOVE_FORCE, s)
	{}
	virtual ~ZC_STOPMOVE_FORCE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100629 || \
	PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20091006 || \
	PACKET_VERSION >= 20090929 || \
	PACKET_VERSION >= 0
	ID_ZC_BATTLE_JOIN_NOTI_DEFER = 0x07f3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BATTLE_JOIN_NOTI_DEFER
 *
 */ 
class ZC_BATTLE_JOIN_NOTI_DEFER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BATTLE_JOIN_NOTI_DEFER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BATTLE_JOIN_NOTI_DEFER, s)
	{}
	virtual ~ZC_BATTLE_JOIN_NOTI_DEFER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_WHISPER = 0x0097
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_WHISPER
 *
 */ 
class ZC_WHISPER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_WHISPER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_WHISPER, s)
	{}
	virtual ~ZC_WHISPER() {}

	void deliver(std::string name, std::string message, bool is_admin);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{4};
	char _name[MAX_UNIT_NAME_LENGTH]{'\0'};
	int32_t _is_admin{0};
	char *_message;
};

enum {
#if PACKET_VERSION >= 20041108 || \
	PACKET_VERSION >= 0
	ID_ZC_BABYMSG = 0x0216
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BABYMSG
 *
 */ 
class ZC_BABYMSG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BABYMSG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BABYMSG, s)
	{}
	virtual ~ZC_BABYMSG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_VANISH = 0x0080
#endif
};

/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_VANISH
 *
 */ 
class ZC_NOTIFY_VANISH : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_VANISH(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_VANISH, s)
	{}
	virtual ~ZC_NOTIFY_VANISH() {}

	void deliver(int32_t guid, entity_viewport_notification_type type);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid{0};
	/// type:
	///     0 = out of sight
	///     1 = died
	///     2 = logged out
	///     3 = teleport
	///     4 = trickdead
	int8_t _type{0};
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MAKINGARROW_LIST = 0x01ad
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MAKINGARROW_LIST
 *
 */ 
class ZC_MAKINGARROW_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAKINGARROW_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAKINGARROW_LIST, s)
	{}
	virtual ~ZC_MAKINGARROW_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REQ_JOIN_GUILD = 0x0169
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQ_JOIN_GUILD
 *
 */ 
class ZC_ACK_REQ_JOIN_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQ_JOIN_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQ_JOIN_GUILD, s)
	{}
	virtual ~ZC_ACK_REQ_JOIN_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140402 || \
	PACKET_VERSION >= 0
	ID_ZC_CART_ITEMLIST_EQUIP_V6 = 0x0a0f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_ITEMLIST_EQUIP_V6
 *
 */ 
class ZC_CART_ITEMLIST_EQUIP_V6 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_ITEMLIST_EQUIP_V6(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_ITEMLIST_EQUIP_V6, s)
	{}
	virtual ~ZC_CART_ITEMLIST_EQUIP_V6() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120529 || \
	PACKET_VERSION >= 0
	ID_ZC_EFST_SET_ENTER2 = 0x0984
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EFST_SET_ENTER2
 *
 */ 
class ZC_EFST_SET_ENTER2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EFST_SET_ENTER2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EFST_SET_ENTER2, s)
	{}
	virtual ~ZC_EFST_SET_ENTER2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_AUTOSPELLLIST = 0x01cd
#elif PACKET_VERSION >= 20180425 || \
	PACKET_VERSION >= 20180418 || \
	PACKET_VERSION >= 0
	ID_ZC_AUTOSPELLLIST = 0x0afb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_AUTOSPELLLIST
 *
 */ 
class ZC_AUTOSPELLLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_AUTOSPELLLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_AUTOSPELLLIST, s)
	{}
	virtual ~ZC_AUTOSPELLLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140122 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STANDENTRY11 = 0x09ff
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STANDENTRY11
 *
 */ 
class ZC_NOTIFY_STANDENTRY11 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STANDENTRY11(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STANDENTRY11, s)
	{}
	virtual ~ZC_NOTIFY_STANDENTRY11() {}

	void deliver(entity_viewport_entry entry);
	ByteBuffer &serialize();

/* Structure */
	entity_viewport_entry _entry;
};

enum {
#if PACKET_VERSION >= 20131023 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STANDENTRY10 = 0x09dd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STANDENTRY10
 *
 */ 
class ZC_NOTIFY_STANDENTRY10 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STANDENTRY10(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STANDENTRY10, s)
	{}
	virtual ~ZC_NOTIFY_STANDENTRY10() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050530 || \
	PACKET_VERSION >= 0
	ID_ZC_KILLER_RANK = 0x0238
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_KILLER_RANK
 *
 */ 
class ZC_KILLER_RANK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_KILLER_RANK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_KILLER_RANK, s)
	{}
	virtual ~ZC_KILLER_RANK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ROOM_NEWENTRY = 0x00d7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ROOM_NEWENTRY
 *
 */ 
class ZC_ROOM_NEWENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ROOM_NEWENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ROOM_NEWENTRY, s)
	{}
	virtual ~ZC_ROOM_NEWENTRY() {}

	void deliver(int owner_id, int char_id, int limit, int users, int type, std::string title);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{ 0 };
	int _owner_id{ 0 };
	int _char_id{ 0 };
	int16_t _limit{ 0 };
	int16_t _users{ 0 };
	int8_t _type{ 0 };
	char _title[CHATROOM_TITLE_SIZE];
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_FALL_ENTRY = 0x009e
#elif PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20170913 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_FALL_ENTRY = 0x0add
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_FALL_ENTRY
 *
 */ 
class ZC_ITEM_FALL_ENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_FALL_ENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_FALL_ENTRY, s)
	{}
	virtual ~ZC_ITEM_FALL_ENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_PLAYERMOVE = 0x0087
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_PLAYERMOVE
 *
 */ 
class ZC_NOTIFY_PLAYERMOVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_PLAYERMOVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_PLAYERMOVE, s)
	{}
	virtual ~ZC_NOTIFY_PLAYERMOVE() {}

	void deliver(int16_t from_x, int16_t from_y, int16_t to_x, int16_t to_y);
	ByteBuffer &serialize();

/* Structure */
	unsigned int _timestamp{0};
	int8_t _packed_pos[6]{0};
};

enum {
#if PACKET_VERSION >= 20041101 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILLMSG = 0x0215
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILLMSG
 *
 */ 
class ZC_SKILLMSG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILLMSG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILLMSG, s)
	{}
	virtual ~ZC_SKILLMSG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20040705 || \
	PACKET_VERSION >= 20040628 || \
	PACKET_VERSION >= 0
	ID_ZC_DELETE_FRIENDS = 0x020a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DELETE_FRIENDS
 *
 */ 
class ZC_DELETE_FRIENDS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DELETE_FRIENDS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DELETE_FRIENDS, s)
	{}
	virtual ~ZC_DELETE_FRIENDS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20041213 || \
	PACKET_VERSION >= 0
	ID_ZC_LESSEFFECT = 0x021e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_LESSEFFECT
 *
 */ 
class ZC_LESSEFFECT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_LESSEFFECT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_LESSEFFECT, s)
	{}
	virtual ~ZC_LESSEFFECT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140611 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_CLOSE_ROULETTE = 0x0a1e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_CLOSE_ROULETTE
 *
 */ 
class ZC_ACK_CLOSE_ROULETTE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_CLOSE_ROULETTE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_CLOSE_ROULETTE, s)
	{}
	virtual ~ZC_ACK_CLOSE_ROULETTE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20031124 || \
	PACKET_VERSION >= 0
	ID_ZC_GUILD_MEMBER_MAP_CHANGE = 0x01ec
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILD_MEMBER_MAP_CHANGE
 *
 */ 
class ZC_GUILD_MEMBER_MAP_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILD_MEMBER_MAP_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILD_MEMBER_MAP_CHANGE, s)
	{}
	virtual ~ZC_GUILD_MEMBER_MAP_CHANGE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20141119 || \
	PACKET_VERSION >= 20141008 || \
	PACKET_VERSION >= 20140416 || \
	PACKET_VERSION >= 20140226 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ADD_ITEM_RODEX = 0x0a05
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ADD_ITEM_RODEX
 *
 */ 
class ZC_ACK_ADD_ITEM_RODEX : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ADD_ITEM_RODEX(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ADD_ITEM_RODEX, s)
	{}
	virtual ~ZC_ACK_ADD_ITEM_RODEX() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070724 || \
	PACKET_VERSION >= 0
	ID_ZC_ALL_QUEST_LIST = 0x02b1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALL_QUEST_LIST
 *
 */ 
class ZC_ALL_QUEST_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALL_QUEST_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALL_QUEST_LIST, s)
	{}
	virtual ~ZC_ALL_QUEST_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20150422 || \
	PACKET_VERSION >= 0
	ID_ZC_CUSTOM_HAT_EFFECT = 0x0a3b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CUSTOM_HAT_EFFECT
 *
 */ 
class ZC_CUSTOM_HAT_EFFECT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CUSTOM_HAT_EFFECT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CUSTOM_HAT_EFFECT, s)
	{}
	virtual ~ZC_CUSTOM_HAT_EFFECT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_PLAYERCHAT = 0x008e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_PLAYERCHAT
 *
 */ 
class ZC_NOTIFY_PLAYERCHAT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_PLAYERCHAT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_PLAYERCHAT, s)
	{}
	virtual ~ZC_NOTIFY_PLAYERCHAT() {}

	void deliver(std::string &message);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{0};
	std::string _message{""};
};

enum {
#if PACKET_VERSION >= 20111101 || \
	PACKET_VERSION >= 0
	ID_ZC_HUNTING_QUEST_INFO = 0x08fe
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HUNTING_QUEST_INFO
 *
 */ 
class ZC_HUNTING_QUEST_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HUNTING_QUEST_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HUNTING_QUEST_INFO, s)
	{}
	virtual ~ZC_HUNTING_QUEST_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_JOIN_GROUP = 0x00fe
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_JOIN_GROUP
 *
 */ 
class ZC_REQ_JOIN_GROUP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_JOIN_GROUP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_JOIN_GROUP, s)
	{}
	virtual ~ZC_REQ_JOIN_GROUP() {}

	void deliver(int party_id, std::string party_name);
	ByteBuffer &serialize();

/* Structure */
	int _party_id{ 0 };
	char _party_name[MAX_PARTY_NAME_LENGTH];
};

enum {
#if PACKET_VERSION >= 20060710 || \
	PACKET_VERSION >= 0
	ID_ZC_SHANDA_PROTECT = 0x027e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SHANDA_PROTECT
 *
 */ 
class ZC_SHANDA_PROTECT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SHANDA_PROTECT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SHANDA_PROTECT, s)
	{}
	virtual ~ZC_SHANDA_PROTECT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050822 || \
	PACKET_VERSION >= 20050817 || \
	PACKET_VERSION >= 0
	ID_ZC_STARPLACE = 0x0253
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STARPLACE
 *
 */ 
class ZC_STARPLACE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STARPLACE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STARPLACE, s)
	{}
	virtual ~ZC_STARPLACE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070821 || \
	PACKET_VERSION >= 20070813 || \
	PACKET_VERSION >= 20070731 || \
	PACKET_VERSION >= 20070703 || \
	PACKET_VERSION >= 20070628 || \
	PACKET_VERSION >= 20070622 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_QUEST = 0x02b3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_QUEST
 *
 */ 
class ZC_ADD_QUEST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_QUEST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_QUEST, s)
	{}
	virtual ~ZC_ADD_QUEST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_REFUSE_ENTER_ROOM = 0x00da
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REFUSE_ENTER_ROOM
 *
 */ 
class ZC_REFUSE_ENTER_ROOM : public Base::NetworkPacketTransmitter<ZoneSession>
{
	enum chat_join_fail_type
	{
		CHAT_JOINFAIL_ROOMFULL = 0,
		CHAT_JOINFAIL_WRONGPASSWORD = 1,
		CHAT_JOINFAIL_KICKED = 2,
		CHAT_JOINFAIL_SUCCESS = 3,
		CHAT_JOINFAIL_NOZENY = 4,
		CHAT_JOINFAIL_LOWLEVEL = 5,
		CHAT_JOINFAIL_HIGHLEVEL = 6,
		CHAT_JOINFAIL_UNSUITABLE_JOB = 7
	};
public:
	ZC_REFUSE_ENTER_ROOM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REFUSE_ENTER_ROOM, s)
	{}
	virtual ~ZC_REFUSE_ENTER_ROOM() {}

	void deliver(chat_join_fail_type type);
	ByteBuffer &serialize();

/* Structure */
	int8_t _result{ 0 };
};

enum {
#if PACKET_VERSION >= 20141001 || \
	PACKET_VERSION >= 20140723 || \
	PACKET_VERSION >= 20140625 || \
	PACKET_VERSION >= 20140611 || \
	PACKET_VERSION >= 0
	ID_ZC_ACH_UPDATE = 0x0a24
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACH_UPDATE
 *
 */ 
class ZC_ACH_UPDATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACH_UPDATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACH_UPDATE, s)
	{}
	virtual ~ZC_ACH_UPDATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20040705 || \
	PACKET_VERSION >= 20040628 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_FRIENDS_LIST = 0x0209
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_FRIENDS_LIST
 *
 */ 
class ZC_ADD_FRIENDS_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_FRIENDS_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_FRIENDS_LIST, s)
	{}
	virtual ~ZC_ADD_FRIENDS_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MONSTER_INFO = 0x018c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MONSTER_INFO
 *
 */ 
class ZC_MONSTER_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MONSTER_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MONSTER_INFO, s)
	{}
	virtual ~ZC_MONSTER_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111025 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_NOTIFY_DELETE = 0x08ee
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_NOTIFY_DELETE
 *
 */ 
class ZC_PARTY_RECRUIT_NOTIFY_DELETE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_NOTIFY_DELETE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_NOTIFY_DELETE, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_NOTIFY_DELETE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_SKILL = 0x0114
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_SKILL
 *
 */ 
class ZC_NOTIFY_SKILL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_SKILL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_SKILL, s)
	{}
	virtual ~ZC_NOTIFY_SKILL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_STORE_NORMAL_ITEMLIST3 = 0x02ea
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_NORMAL_ITEMLIST3
 *
 */ 
class ZC_STORE_NORMAL_ITEMLIST3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_NORMAL_ITEMLIST3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_NORMAL_ITEMLIST3, s)
	{}
	virtual ~ZC_STORE_NORMAL_ITEMLIST3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050411 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_NEWENTRY3 = 0x022b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_NEWENTRY3
 *
 */ 
class ZC_NOTIFY_NEWENTRY3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_NEWENTRY3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_NEWENTRY3, s)
	{}
	virtual ~ZC_NOTIFY_NEWENTRY3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_NEWENTRY2 = 0x01d9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_NEWENTRY2
 *
 */ 
class ZC_NOTIFY_NEWENTRY2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_NEWENTRY2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_NEWENTRY2, s)
	{}
	virtual ~ZC_NOTIFY_NEWENTRY2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120131 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_NEWENTRY7 = 0x090f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_NEWENTRY7
 *
 */ 
class ZC_NOTIFY_NEWENTRY7 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_NEWENTRY7(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_NEWENTRY7, s)
	{}
	virtual ~ZC_NOTIFY_NEWENTRY7() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20101123 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_NEWENTRY6 = 0x0858
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_NEWENTRY6
 *
 */ 
class ZC_NOTIFY_NEWENTRY6 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_NEWENTRY6(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_NEWENTRY6, s)
	{}
	virtual ~ZC_NOTIFY_NEWENTRY6() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091103 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_NEWENTRY5 = 0x07f8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_NEWENTRY5
 *
 */ 
class ZC_NOTIFY_NEWENTRY5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_NEWENTRY5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_NEWENTRY5, s)
	{}
	virtual ~ZC_NOTIFY_NEWENTRY5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_NEWENTRY4 = 0x02ed
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_NEWENTRY4
 *
 */ 
class ZC_NOTIFY_NEWENTRY4 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_NEWENTRY4(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_NEWENTRY4, s)
	{}
	virtual ~ZC_NOTIFY_NEWENTRY4() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MVP_GETTING_SPECIAL_EXP = 0x010b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MVP_GETTING_SPECIAL_EXP
 *
 */ 
class ZC_MVP_GETTING_SPECIAL_EXP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MVP_GETTING_SPECIAL_EXP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MVP_GETTING_SPECIAL_EXP, s)
	{}
	virtual ~ZC_MVP_GETTING_SPECIAL_EXP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_PC_PURCHASE_RESULT_FROMMC = 0x0135
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PC_PURCHASE_RESULT_FROMMC
 *
 */ 
class ZC_PC_PURCHASE_RESULT_FROMMC : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PC_PURCHASE_RESULT_FROMMC(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PC_PURCHASE_RESULT_FROMMC, s)
	{}
	virtual ~ZC_PC_PURCHASE_RESULT_FROMMC() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120328 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_BEFORE_WORLD_INFO = 0x0979
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_BEFORE_WORLD_INFO
 *
 */ 
class ZC_ACK_BEFORE_WORLD_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_BEFORE_WORLD_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_BEFORE_WORLD_INFO, s)
	{}
	virtual ~ZC_ACK_BEFORE_WORLD_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NPCACK_ENABLE = 0x0093
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NPCACK_ENABLE
 *
 */ 
class ZC_NPCACK_ENABLE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NPCACK_ENABLE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NPCACK_ENABLE, s)
	{}
	virtual ~ZC_NPCACK_ENABLE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120716 || \
	PACKET_VERSION >= 20120702 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_CLAN_LEAVE = 0x0989
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_CLAN_LEAVE
 *
 */ 
class ZC_ACK_CLAN_LEAVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_CLAN_LEAVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_CLAN_LEAVE, s)
	{}
	virtual ~ZC_ACK_CLAN_LEAVE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20090520
	ID_ZC_ES_GOTO = 0x07d6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ES_GOTO
 *
 */ 
class ZC_ES_GOTO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ES_GOTO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ES_GOTO, s)
	{}
	virtual ~ZC_ES_GOTO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20151104 || \
	PACKET_VERSION >= 0
	ID_ZC_STYLE_CHANGE_RES = 0x0a47
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STYLE_CHANGE_RES
 *
 */ 
class ZC_STYLE_CHANGE_RES : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STYLE_CHANGE_RES(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STYLE_CHANGE_RES, s)
	{}
	virtual ~ZC_STYLE_CHANGE_RES() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_ACTENTRY = 0x007a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_ACTENTRY
 *
 */ 
class ZC_NOTIFY_ACTENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_ACTENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_ACTENTRY, s)
	{}
	virtual ~ZC_NOTIFY_ACTENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_DISORGANIZE_GUILD_RESULT = 0x015e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_DISORGANIZE_GUILD_RESULT
 *
 */ 
class ZC_ACK_DISORGANIZE_GUILD_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_DISORGANIZE_GUILD_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_DISORGANIZE_GUILD_RESULT, s)
	{}
	virtual ~ZC_ACK_DISORGANIZE_GUILD_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130502 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_CLOSE_GUILD_STORAGE = 0x09bf
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_CLOSE_GUILD_STORAGE
 *
 */ 
class ZC_ACK_CLOSE_GUILD_STORAGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_CLOSE_GUILD_STORAGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_CLOSE_GUILD_STORAGE, s)
	{}
	virtual ~ZC_ACK_CLOSE_GUILD_STORAGE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091222 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_BOOKING_ACK_SEARCH = 0x0805
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_BOOKING_ACK_SEARCH
 *
 */ 
class ZC_PARTY_BOOKING_ACK_SEARCH : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_BOOKING_ACK_SEARCH(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_BOOKING_ACK_SEARCH, s)
	{}
	virtual ~ZC_PARTY_BOOKING_ACK_SEARCH() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REQ_JOIN_GROUP = 0x00fd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQ_JOIN_GROUP
 *
 */ 
class ZC_ACK_REQ_JOIN_GROUP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQ_JOIN_GROUP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQ_JOIN_GROUP, s)
	{}
	virtual ~ZC_ACK_REQ_JOIN_GROUP() {}

	void deliver(std::string name, zcparty_joinreqack_result_type result);
	ByteBuffer &serialize();

/* Structure */
	char _name[MAX_UNIT_NAME_LENGTH]{ 0 };
	int8_t _result;
};

enum {
#if PACKET_VERSION >= 20120925 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_TAKEOFF_EQUIP_V5 = 0x099a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_TAKEOFF_EQUIP_V5
 *
 */ 
class ZC_ACK_TAKEOFF_EQUIP_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_TAKEOFF_EQUIP_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_TAKEOFF_EQUIP_V5, s)
	{}
	virtual ~ZC_ACK_TAKEOFF_EQUIP_V5() {}

	void deliver(int16_t inventory_index, int32_t equip_location_mask, item_unequip_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int16_t _inventory_index{0};
	int32_t _equip_location_mask{0};
	int8_t _result{0};
};

enum {
#if PACKET_VERSION >= 20071002 || \
	PACKET_VERSION >= 0
	ID_ZC_BATTLEFIELD_NOTIFY_CAMPINFO = 0x02dd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BATTLEFIELD_NOTIFY_CAMPINFO
 *
 */ 
class ZC_BATTLEFIELD_NOTIFY_CAMPINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BATTLEFIELD_NOTIFY_CAMPINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BATTLEFIELD_NOTIFY_CAMPINFO, s)
	{}
	virtual ~ZC_BATTLEFIELD_NOTIFY_CAMPINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070205 || \
	PACKET_VERSION >= 0
	ID_ZC_RESULT_CASH_PASSWORD = 0x02ac
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_RESULT_CASH_PASSWORD
 *
 */ 
class ZC_RESULT_CASH_PASSWORD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_RESULT_CASH_PASSWORD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_RESULT_CASH_PASSWORD, s)
	{}
	virtual ~ZC_RESULT_CASH_PASSWORD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110928 || \
	PACKET_VERSION >= 0
	ID_ZC_CLEAR_DIALOG = 0x08d6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CLEAR_DIALOG
 *
 */ 
class ZC_CLEAR_DIALOG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CLEAR_DIALOG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CLEAR_DIALOG, s)
	{}
	virtual ~ZC_CLEAR_DIALOG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MENU_LIST = 0x00b7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MENU_LIST
 *
 */ 
class ZC_MENU_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MENU_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MENU_LIST, s)
	{}
	virtual ~ZC_MENU_LIST() {}

	void deliver(int32_t guid, std::string const &menu);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{0};
	int32_t _guid{0};
	std::string _menu_items{""};
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_GROUNDSKILL = 0x0117
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_GROUNDSKILL
 *
 */ 
class ZC_NOTIFY_GROUNDSKILL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_GROUNDSKILL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_GROUNDSKILL, s)
	{}
	virtual ~ZC_NOTIFY_GROUNDSKILL() {}

	void deliver(int16_t skill_id, int32_t guid, int16_t level, int16_t x, int16_t y, int32_t duration);
	ByteBuffer &serialize();

/* Structure */
	int16_t _skill_id{0};
	int32_t _guid{0};
	int16_t _level{0};
	int16_t _x{0};
	int16_t _y{0};
	int32_t _duration{0};
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_CANCEL_EXCHANGE_ITEM = 0x00ee
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CANCEL_EXCHANGE_ITEM
 *
 */ 
class ZC_CANCEL_EXCHANGE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CANCEL_EXCHANGE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CANCEL_EXCHANGE_ITEM, s)
	{}
	virtual ~ZC_CANCEL_EXCHANGE_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111004 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_ENTRY_QUEUE_APPLY = 0x08d9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_ENTRY_QUEUE_APPLY
 *
 */ 
class ZC_NOTIFY_ENTRY_QUEUE_APPLY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_ENTRY_QUEUE_APPLY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_ENTRY_QUEUE_APPLY, s)
	{}
	virtual ~ZC_NOTIFY_ENTRY_QUEUE_APPLY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091229 || \
	PACKET_VERSION >= 20091228 || \
	PACKET_VERSION >= 20091222 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_BOOKING_NOTIFY_INSERT = 0x0809
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_BOOKING_NOTIFY_INSERT
 *
 */ 
class ZC_PARTY_BOOKING_NOTIFY_INSERT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_BOOKING_NOTIFY_INSERT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_BOOKING_NOTIFY_INSERT, s)
	{}
	virtual ~ZC_PARTY_BOOKING_NOTIFY_INSERT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100413 || \
	PACKET_VERSION >= 0
	ID_ZC_COSTUME_SPRITE_CHANGE = 0x0820
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_COSTUME_SPRITE_CHANGE
 *
 */ 
class ZC_COSTUME_SPRITE_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_COSTUME_SPRITE_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_COSTUME_SPRITE_CHANGE, s)
	{}
	virtual ~ZC_COSTUME_SPRITE_CHANGE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20051017 || \
	PACKET_VERSION >= 0
	ID_ZC_AUCTION_ACK_MY_SELL_STOP = 0x025e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_AUCTION_ACK_MY_SELL_STOP
 *
 */ 
class ZC_AUCTION_ACK_MY_SELL_STOP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_AUCTION_ACK_MY_SELL_STOP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_AUCTION_ACK_MY_SELL_STOP, s)
	{}
	virtual ~ZC_AUCTION_ACK_MY_SELL_STOP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_JOIN_GUILD = 0x016a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_JOIN_GUILD
 *
 */ 
class ZC_REQ_JOIN_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_JOIN_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_JOIN_GUILD, s)
	{}
	virtual ~ZC_REQ_JOIN_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070122
	ID_ZC_GAMEGUARD_LINGO_KEY = 0x02a3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GAMEGUARD_LINGO_KEY
 *
 */ 
class ZC_GAMEGUARD_LINGO_KEY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GAMEGUARD_LINGO_KEY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GAMEGUARD_LINGO_KEY, s)
	{}
	virtual ~ZC_GAMEGUARD_LINGO_KEY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_DELETE_ITEM_FROM_STORE = 0x00f6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DELETE_ITEM_FROM_STORE
 *
 */ 
class ZC_DELETE_ITEM_FROM_STORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DELETE_ITEM_FROM_STORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DELETE_ITEM_FROM_STORE, s)
	{}
	virtual ~ZC_DELETE_ITEM_FROM_STORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091103 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MOVEENTRY7 = 0x07f7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MOVEENTRY7
 *
 */ 
class ZC_NOTIFY_MOVEENTRY7 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MOVEENTRY7(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MOVEENTRY7, s)
	{}
	virtual ~ZC_NOTIFY_MOVEENTRY7() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111227 || \
	PACKET_VERSION >= 0
	ID_ZC_PREMIUM_CAMPAIGN_INFO = 0x090d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PREMIUM_CAMPAIGN_INFO
 *
 */ 
class ZC_PREMIUM_CAMPAIGN_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PREMIUM_CAMPAIGN_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PREMIUM_CAMPAIGN_INFO, s)
	{}
	virtual ~ZC_PREMIUM_CAMPAIGN_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_COMPASS = 0x0144
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_COMPASS
 *
 */ 
class ZC_COMPASS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_COMPASS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_COMPASS, s)
	{}
	virtual ~ZC_COMPASS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_STOPMOVE = 0x0088
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STOPMOVE
 *
 */ 
class ZC_STOPMOVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STOPMOVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STOPMOVE, s)
	{}
	virtual ~ZC_STOPMOVE() {}

	void deliver(int32_t guid, int16_t x, int16_t y);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid{0};
	int16_t _x{0};
	int16_t _y{0};
};

enum {
#if PACKET_VERSION >= 20130828 || \
	PACKET_VERSION >= 0
	ID_ZC_GUILDSTORAGE_ITEMLIST_NORMAL_V5 = 0x09d2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILDSTORAGE_ITEMLIST_NORMAL_V5
 *
 */ 
class ZC_GUILDSTORAGE_ITEMLIST_NORMAL_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILDSTORAGE_ITEMLIST_NORMAL_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILDSTORAGE_ITEMLIST_NORMAL_V5, s)
	{}
	virtual ~ZC_GUILDSTORAGE_ITEMLIST_NORMAL_V5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111122 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_ITEMLIST_NORMAL = 0x0904
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_ITEMLIST_NORMAL
 *
 */ 
class ZC_STORE_ITEMLIST_NORMAL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_ITEMLIST_NORMAL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_ITEMLIST_NORMAL, s)
	{}
	virtual ~ZC_STORE_ITEMLIST_NORMAL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120503 || \
	PACKET_VERSION >= 20120502 || \
	PACKET_VERSION >= 0
	ID_ZC_UPDATE_RANKING_POINT = 0x097e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_RANKING_POINT
 *
 */ 
class ZC_UPDATE_RANKING_POINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_RANKING_POINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_RANKING_POINT, s)
	{}
	virtual ~ZC_UPDATE_RANKING_POINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20041213 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_PKINFO = 0x021f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_PKINFO
 *
 */ 
class ZC_NOTIFY_PKINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_PKINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_PKINFO, s)
	{}
	virtual ~ZC_NOTIFY_PKINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070828 || \
	PACKET_VERSION >= 0
	ID_ZC_MEMORIALDUNGEON_SUBSCRIPTION_NOTIFY = 0x02cc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MEMORIALDUNGEON_SUBSCRIPTION_NOTIFY
 *
 */ 
class ZC_MEMORIALDUNGEON_SUBSCRIPTION_NOTIFY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MEMORIALDUNGEON_SUBSCRIPTION_NOTIFY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MEMORIALDUNGEON_SUBSCRIPTION_NOTIFY, s)
	{}
	virtual ~ZC_MEMORIALDUNGEON_SUBSCRIPTION_NOTIFY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20040422 || \
	PACKET_VERSION >= 0
	ID_ZC_HIGHJUMP = 0x01ff
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HIGHJUMP
 *
 */ 
class ZC_HIGHJUMP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HIGHJUMP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HIGHJUMP, s)
	{}
	virtual ~ZC_HIGHJUMP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REQNAMEALL = 0x0195
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQNAMEALL
 *
 */ 
class ZC_ACK_REQNAMEALL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQNAMEALL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQNAMEALL, s)
	{}
	virtual ~ZC_ACK_REQNAMEALL() {}

	void deliver(int32_t guid, std::string name, std::string party_name, std::string guild_name, std::string position_name);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid;
	char _name[MAX_UNIT_NAME_LENGTH];
	char _party_name[MAX_UNIT_NAME_LENGTH];
	char _guild_name[MAX_UNIT_NAME_LENGTH];
	char _position_name[MAX_UNIT_NAME_LENGTH];
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_BAN_LIST = 0x0163
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BAN_LIST
 *
 */ 
class ZC_BAN_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BAN_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BAN_LIST, s)
	{}
	virtual ~ZC_BAN_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140611 || \
	PACKET_VERSION >= 20140605 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ROULEITTE_INFO = 0x0a1c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ROULEITTE_INFO
 *
 */ 
class ZC_ACK_ROULEITTE_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ROULEITTE_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ROULEITTE_INFO, s)
	{}
	virtual ~ZC_ACK_ROULEITTE_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070711
	ID_ZC_UNUSED_SRPACKET_INIT = 0x02ae
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UNUSED_SRPACKET_INIT
 *
 */ 
class ZC_UNUSED_SRPACKET_INIT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UNUSED_SRPACKET_INIT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UNUSED_SRPACKET_INIT, s)
	{}
	virtual ~ZC_UNUSED_SRPACKET_INIT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070821 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_CONFIG = 0x02c9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_CONFIG
 *
 */ 
class ZC_PARTY_CONFIG : public Base::NetworkPacketTransmitter<ZoneSession>
{
	enum zc_party_config_type
	{
		ZC_PARTYCONFIG_TYPE_ALLOW_INVITES = 0,
		ZC_PARTYCONFIG_TYPE_DENY_INVITES = 1
	};
public:
	ZC_PARTY_CONFIG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_CONFIG, s)
	{}
	virtual ~ZC_PARTY_CONFIG() {}

	void deliver(zc_party_config_type config);
	ByteBuffer &serialize();

/* Structure */
	int8_t _config{ 0 };

};

enum {
#if PACKET_VERSION >= 20100323 || \
	PACKET_VERSION >= 0
	ID_ZC_BROADCAST4 = 0x081f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BROADCAST4
 *
 */ 
class ZC_BROADCAST4 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BROADCAST4(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BROADCAST4, s)
	{}
	virtual ~ZC_BROADCAST4() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_GUILD_NOTICE = 0x016f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILD_NOTICE
 *
 */ 
class ZC_GUILD_NOTICE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILD_NOTICE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILD_NOTICE, s)
	{}
	virtual ~ZC_GUILD_NOTICE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_BROADCAST2 = 0x01c3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BROADCAST2
 *
 */ 
class ZC_BROADCAST2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BROADCAST2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BROADCAST2, s)
	{}
	virtual ~ZC_BROADCAST2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ADD_RELATED_GUILD = 0x0185
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_RELATED_GUILD
 *
 */ 
class ZC_ADD_RELATED_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_RELATED_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_RELATED_GUILD, s)
	{}
	virtual ~ZC_ADD_RELATED_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140416 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_OPEN_WRITE_RODEX = 0x0a12
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_OPEN_WRITE_RODEX
 *
 */ 
class ZC_ACK_OPEN_WRITE_RODEX : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_OPEN_WRITE_RODEX(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_OPEN_WRITE_RODEX, s)
	{}
	virtual ~ZC_ACK_OPEN_WRITE_RODEX() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_HP_TO_GROUPM = 0x0106
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_HP_TO_GROUPM
 *
 */ 
class ZC_NOTIFY_HP_TO_GROUPM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_HP_TO_GROUPM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_HP_TO_GROUPM, s)
	{}
	virtual ~ZC_NOTIFY_HP_TO_GROUPM() {}

	void deliver(int account_id, int hp, int max_hp);
#if (CLIENT_TYPE == 'Z' && PACKET_VERSION >= 20210504)
	void deliver(int account_id, int hp, int max_hp, int sp, int max_sp);
#endif
	ByteBuffer &serialize();

/* Structure */
	int _account_id{ 0 };
	int16_t _hp{ 0 }, _max_hp{ 0 };
#if (CLIENT_TYPE == 'Z' && PACKET_VERSION >= 20210504)
	int16_t _sp{ 0 }, _max_sp{ 0 };
#endif
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20070904 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_PICKUP_ACK3 = 0x02d4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_PICKUP_ACK3
 *
 */ 
class ZC_ITEM_PICKUP_ACK3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_PICKUP_ACK3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_PICKUP_ACK3, s)
	{}
	virtual ~ZC_ITEM_PICKUP_ACK3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20061218 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_PICKUP_ACK2 = 0x029a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_PICKUP_ACK2
 *
 */ 
class ZC_ITEM_PICKUP_ACK2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_PICKUP_ACK2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_PICKUP_ACK2, s)
	{}
	virtual ~ZC_ITEM_PICKUP_ACK2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111122 || \
	PACKET_VERSION >= 0
	ID_ZC_INVENTORY_ITEMLIST_NORMAL = 0x0900
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INVENTORY_ITEMLIST_NORMAL
 *
 */ 
class ZC_INVENTORY_ITEMLIST_NORMAL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INVENTORY_ITEMLIST_NORMAL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INVENTORY_ITEMLIST_NORMAL, s)
	{}
	virtual ~ZC_INVENTORY_ITEMLIST_NORMAL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100309 || \
	PACKET_VERSION >= 0
	ID_ZC_EL_INIT = 0x081d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EL_INIT
 *
 */ 
class ZC_EL_INIT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EL_INIT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EL_INIT, s)
	{}
	virtual ~ZC_EL_INIT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20150909 || \
	PACKET_VERSION >= 0
	ID_ZC_AOE_EFFECT_SKILL = 0x0a41
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_AOE_EFFECT_SKILL
 *
 */ 
class ZC_AOE_EFFECT_SKILL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_AOE_EFFECT_SKILL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_AOE_EFFECT_SKILL, s)
	{}
	virtual ~ZC_AOE_EFFECT_SKILL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SPIRITS = 0x01d0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SPIRITS
 *
 */ 
class ZC_SPIRITS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SPIRITS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SPIRITS, s)
	{}
	virtual ~ZC_SPIRITS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120925 || \
	PACKET_VERSION >= 0
	ID_ZC_CART_ITEMLIST_NORMAL_V5 = 0x0993
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_ITEMLIST_NORMAL_V5
 *
 */ 
class ZC_CART_ITEMLIST_NORMAL_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_ITEMLIST_NORMAL_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_ITEMLIST_NORMAL_V5, s)
	{}
	virtual ~ZC_CART_ITEMLIST_NORMAL_V5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_CHANGESTATE_PET = 0x01a4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CHANGESTATE_PET
 *
 */ 
class ZC_CHANGESTATE_PET : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CHANGESTATE_PET(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CHANGESTATE_PET, s)
	{}
	virtual ~ZC_CHANGESTATE_PET() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ATTACK_FAILURE_FOR_DISTANCE = 0x0139
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ATTACK_FAILURE_FOR_DISTANCE
 *
 */ 
class ZC_ATTACK_FAILURE_FOR_DISTANCE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ATTACK_FAILURE_FOR_DISTANCE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ATTACK_FAILURE_FOR_DISTANCE, s)
	{}
	virtual ~ZC_ATTACK_FAILURE_FOR_DISTANCE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20130605 || \
	PACKET_VERSION >= 20130327 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_BARGAIN_SALE_CLOSE = 0x09b3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_BARGAIN_SALE_CLOSE
 *
 */ 
class ZC_NOTIFY_BARGAIN_SALE_CLOSE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_BARGAIN_SALE_CLOSE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_BARGAIN_SALE_CLOSE, s)
	{}
	virtual ~ZC_NOTIFY_BARGAIN_SALE_CLOSE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140508 || \
	PACKET_VERSION >= 20140430 || \
	PACKET_VERSION >= 0
	ID_ZC_GOLDPCCAFE_POINT = 0x0a15
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GOLDPCCAFE_POINT
 *
 */ 
class ZC_GOLDPCCAFE_POINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GOLDPCCAFE_POINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GOLDPCCAFE_POINT, s)
	{}
	virtual ~ZC_GOLDPCCAFE_POINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20040705 || \
	PACKET_VERSION >= 20040628 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_ADD_FRIENDS = 0x0207
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_ADD_FRIENDS
 *
 */ 
class ZC_REQ_ADD_FRIENDS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_ADD_FRIENDS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_ADD_FRIENDS, s)
	{}
	virtual ~ZC_REQ_ADD_FRIENDS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20060918 || \
	PACKET_VERSION >= 20060904 || \
	PACKET_VERSION >= 0
	ID_ZC_GANGSI_POINT = 0x0280
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GANGSI_POINT
 *
 */ 
class ZC_GANGSI_POINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GANGSI_POINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GANGSI_POINT, s)
	{}
	virtual ~ZC_GANGSI_POINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050829 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_AUCTION_ADD_ITEM = 0x0256
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_AUCTION_ADD_ITEM
 *
 */ 
class ZC_ACK_AUCTION_ADD_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_AUCTION_ADD_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_AUCTION_ADD_ITEM, s)
	{}
	virtual ~ZC_ACK_AUCTION_ADD_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091229 || \
	PACKET_VERSION >= 20091228 || \
	PACKET_VERSION >= 20091222 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_BOOKING_NOTIFY_DELETE = 0x080b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_BOOKING_NOTIFY_DELETE
 *
 */ 
class ZC_PARTY_BOOKING_NOTIFY_DELETE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_BOOKING_NOTIFY_DELETE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_BOOKING_NOTIFY_DELETE, s)
	{}
	virtual ~ZC_PARTY_BOOKING_NOTIFY_DELETE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050608 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_STORE_PASSWORD = 0x023a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_STORE_PASSWORD
 *
 */ 
class ZC_REQ_STORE_PASSWORD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_STORE_PASSWORD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_STORE_PASSWORD, s)
	{}
	virtual ~ZC_REQ_STORE_PASSWORD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_NOTIFY_UPDATECHAR = 0x0076
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_UPDATECHAR
 *
 */ 
class ZC_NOTIFY_UPDATECHAR : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_UPDATECHAR(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_UPDATECHAR, s)
	{}
	virtual ~ZC_NOTIFY_UPDATECHAR() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111122 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER = 0x0909
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER
 *
 */ 
class ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_EXCHANGE_ITEM = 0x00e5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_EXCHANGE_ITEM
 *
 */ 
class ZC_REQ_EXCHANGE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_EXCHANGE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_EXCHANGE_ITEM, s)
	{}
	virtual ~ZC_REQ_EXCHANGE_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SELECT_DEALTYPE = 0x00c4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SELECT_DEALTYPE
 *
 */ 
class ZC_SELECT_DEALTYPE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SELECT_DEALTYPE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SELECT_DEALTYPE, s)
	{}
	virtual ~ZC_SELECT_DEALTYPE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140611 || \
	PACKET_VERSION >= 0
	ID_ZC_ALL_ACH_LIST = 0x0a23
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALL_ACH_LIST
 *
 */ 
class ZC_ALL_ACH_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALL_ACH_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALL_ACH_LIST, s)
	{}
	virtual ~ZC_ALL_ACH_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130807 || \
	PACKET_VERSION >= 0
	ID_ZC_MSG_COLOR = 0x09cd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MSG_COLOR
 *
 */ 
class ZC_MSG_COLOR : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MSG_COLOR(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MSG_COLOR, s)
	{}
	virtual ~ZC_MSG_COLOR() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_TAKEOFF_EQUIP_ACK = 0x00ac
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_TAKEOFF_EQUIP_ACK
 *
 */ 
class ZC_REQ_TAKEOFF_EQUIP_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_TAKEOFF_EQUIP_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_TAKEOFF_EQUIP_ACK, s)
	{}
	virtual ~ZC_REQ_TAKEOFF_EQUIP_ACK() {}

	void deliver(int16_t index, int16_t equip_location_mask, item_unequip_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int16_t _index{0};
	int16_t _equip_location_mask{0};
	int8_t _result{0};
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20040302 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_EXCHANGE_ITEM2 = 0x01f4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_EXCHANGE_ITEM2
 *
 */ 
class ZC_REQ_EXCHANGE_ITEM2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_EXCHANGE_ITEM2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_EXCHANGE_ITEM2, s)
	{}
	virtual ~ZC_REQ_EXCHANGE_ITEM2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20131127 || \
	PACKET_VERSION >= 20131120 || \
	PACKET_VERSION >= 0
	ID_ZC_DELETEITEM_FROM_MCSTORE2 = 0x09e5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DELETEITEM_FROM_MCSTORE2
 *
 */ 
class ZC_DELETEITEM_FROM_MCSTORE2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DELETEITEM_FROM_MCSTORE2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DELETEITEM_FROM_MCSTORE2, s)
	{}
	virtual ~ZC_DELETEITEM_FROM_MCSTORE2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20090520
	ID_ZC_ES_RESULT = 0x07d0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ES_RESULT
 *
 */ 
class ZC_ES_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ES_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ES_RESULT, s)
	{}
	virtual ~ZC_ES_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_CARTITEM_COUNTINFO = 0x0121
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_CARTITEM_COUNTINFO
 *
 */ 
class ZC_NOTIFY_CARTITEM_COUNTINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_CARTITEM_COUNTINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_CARTITEM_COUNTINFO, s)
	{}
	virtual ~ZC_NOTIFY_CARTITEM_COUNTINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111004 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_ENTRY_QUEUE_ADMISSION = 0x08dc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_ENTRY_QUEUE_ADMISSION
 *
 */ 
class ZC_NOTIFY_ENTRY_QUEUE_ADMISSION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_ENTRY_QUEUE_ADMISSION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_ENTRY_QUEUE_ADMISSION, s)
	{}
	virtual ~ZC_NOTIFY_ENTRY_QUEUE_ADMISSION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20121010 || \
	PACKET_VERSION >= 0
	ID_ZC_MAPPROPERTY_R2 = 0x099b
#endif
};

struct zc_map_properties {
	unsigned pvp : 1;
	unsigned gvg : 1;
	unsigned siege : 1;
	unsigned no_effects : 1;
	unsigned party_pvp : 1;
	unsigned pvp_kill_counter : 1;
	unsigned disallow_party : 1;
	unsigned battleground : 1;
	unsigned no_costume : 1;
	unsigned allow_carts : 1;
	unsigned stargladiator_miracles : 1;
	unsigned spare_bits : 21;
};

/**
 * @brief Main object for the aegis packet: ZC_MAPPROPERTY_R2
 *
 */ 
class ZC_MAPPROPERTY_R2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAPPROPERTY_R2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAPPROPERTY_R2, s)
	{}
	virtual ~ZC_MAPPROPERTY_R2() {}

	void deliver(zc_map_properties p);
	ByteBuffer &serialize();

/* Structure */
	int16_t _type{0x28};
	int32_t _p{0};
};

enum {
#if PACKET_VERSION >= 20091006 || \
	PACKET_VERSION >= 20090929 || \
	PACKET_VERSION >= 0
	ID_ZC_JOIN_BATTLE_FIELD = 0x07ed
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_JOIN_BATTLE_FIELD
 *
 */ 
class ZC_JOIN_BATTLE_FIELD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_JOIN_BATTLE_FIELD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_JOIN_BATTLE_FIELD, s)
	{}
	virtual ~ZC_JOIN_BATTLE_FIELD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20131023 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MOVEENTRY10 = 0x09db
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MOVEENTRY10
 *
 */ 
class ZC_NOTIFY_MOVEENTRY10 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MOVEENTRY10(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MOVEENTRY10, s)
	{}
	virtual ~ZC_NOTIFY_MOVEENTRY10() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140723 || \
	PACKET_VERSION >= 0
	ID_ZC_SE_CASHSHOP_OPEN2 = 0x0a2b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SE_CASHSHOP_OPEN2
 *
 */ 
class ZC_SE_CASHSHOP_OPEN2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SE_CASHSHOP_OPEN2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SE_CASHSHOP_OPEN2, s)
	{}
	virtual ~ZC_SE_CASHSHOP_OPEN2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111122 || \
	PACKET_VERSION >= 0
	ID_ZC_CART_ITEMLIST_NORMAL = 0x0902
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_ITEMLIST_NORMAL
 *
 */ 
class ZC_CART_ITEMLIST_NORMAL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_ITEMLIST_NORMAL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_ITEMLIST_NORMAL, s)
	{}
	virtual ~ZC_CART_ITEMLIST_NORMAL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20071127 || \
	PACKET_VERSION >= 20071106 || \
	PACKET_VERSION >= 20070122 || \
	PACKET_VERSION >= 20070102 || \
	PACKET_VERSION >= 20061226 || \
	PACKET_VERSION >= 0
	ID_ZC_MER_INIT = 0x029b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MER_INIT
 *
 */ 
class ZC_MER_INIT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MER_INIT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MER_INIT, s)
	{}
	virtual ~ZC_MER_INIT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_TALKBOX_CHATCONTENTS = 0x0191
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_TALKBOX_CHATCONTENTS
 *
 */ 
class ZC_TALKBOX_CHATCONTENTS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_TALKBOX_CHATCONTENTS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_TALKBOX_CHATCONTENTS, s)
	{}
	virtual ~ZC_TALKBOX_CHATCONTENTS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_PC_SELL_ITEMLIST = 0x00c7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PC_SELL_ITEMLIST
 *
 */ 
class ZC_PC_SELL_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PC_SELL_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PC_SELL_ITEMLIST, s)
	{}
	virtual ~ZC_PC_SELL_ITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070622 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_PCBANG_PLAYING_TIME = 0x02bc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_PCBANG_PLAYING_TIME
 *
 */ 
class ZC_NOTIFY_PCBANG_PLAYING_TIME : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_PCBANG_PLAYING_TIME(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_PCBANG_PLAYING_TIME, s)
	{}
	virtual ~ZC_NOTIFY_PCBANG_PLAYING_TIME() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_UPDATE_CHARSTAT = 0x016d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_CHARSTAT
 *
 */ 
class ZC_UPDATE_CHARSTAT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_CHARSTAT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_CHARSTAT, s)
	{}
	virtual ~ZC_UPDATE_CHARSTAT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20170228 || \
	PACKET_VERSION >= 0
	ID_ZC_NPCACK_SERVERMOVE = 0x0ac7
#elif PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NPCACK_SERVERMOVE = 0x0092
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NPCACK_SERVERMOVE
 *
 */ 
class ZC_NPCACK_SERVERMOVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NPCACK_SERVERMOVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NPCACK_SERVERMOVE, s)
	{}
	virtual ~ZC_NPCACK_SERVERMOVE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_BAN_GUILD = 0x015c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_BAN_GUILD
 *
 */ 
class ZC_ACK_BAN_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_BAN_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_BAN_GUILD, s)
	{}
	virtual ~ZC_ACK_BAN_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070821 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_JOIN_REQ_ACK = 0x02c5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_JOIN_REQ_ACK
 *
 */ 
class ZC_PARTY_JOIN_REQ_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_JOIN_REQ_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_JOIN_REQ_ACK, s)
	{}
	virtual ~ZC_PARTY_JOIN_REQ_ACK() {}

	void deliver(std::string name, zcparty_joinreqack_result_type result);
	ByteBuffer &serialize();

/* Structure */
	char _name[MAX_UNIT_NAME_LENGTH]{ 0 };
	int _result{ 0 };
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140312 || \
	PACKET_VERSION >= 20140305 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_ITEM_TO_CART3 = 0x0a0b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_ITEM_TO_CART3
 *
 */ 
class ZC_ADD_ITEM_TO_CART3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_ITEM_TO_CART3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_ITEM_TO_CART3, s)
	{}
	virtual ~ZC_ADD_ITEM_TO_CART3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20060703 || \
	PACKET_VERSION >= 0
	ID_ZC_PROPERTY_MERCE = 0x027d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PROPERTY_MERCE
 *
 */ 
class ZC_PROPERTY_MERCE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PROPERTY_MERCE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PROPERTY_MERCE, s)
	{}
	virtual ~ZC_PROPERTY_MERCE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111122 || \
	PACKET_VERSION >= 0
	ID_ZC_MICROSCOPE = 0x0906
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MICROSCOPE
 *
 */ 
class ZC_MICROSCOPE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MICROSCOPE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MICROSCOPE, s)
	{}
	virtual ~ZC_MICROSCOPE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140226 || \
	PACKET_VERSION >= 20140219 || \
	PACKET_VERSION >= 20140129 || \
	PACKET_VERSION >= 20140108 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_ITEM_TO_STORE2 = 0x01c4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_ITEM_TO_STORE2
 *
 */ 
class ZC_ADD_ITEM_TO_STORE2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_ITEM_TO_STORE2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_ITEM_TO_STORE2, s)
	{}
	virtual ~ZC_ADD_ITEM_TO_STORE2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20061204 || \
	PACKET_VERSION >= 20061030 || \
	PACKET_VERSION >= 0
	ID_ZC_BOSS_INFO = 0x0293
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BOSS_INFO
 *
 */ 
class ZC_BOSS_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BOSS_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BOSS_INFO, s)
	{}
	virtual ~ZC_BOSS_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070807 || \
	PACKET_VERSION >= 0
	ID_ZC_ALL_QUEST_MISSION = 0x02b2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALL_QUEST_MISSION
 *
 */ 
class ZC_ALL_QUEST_MISSION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALL_QUEST_MISSION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALL_QUEST_MISSION, s)
	{}
	virtual ~ZC_ALL_QUEST_MISSION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_PC_PURCHASE_MYITEMLIST = 0x0136
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PC_PURCHASE_MYITEMLIST
 *
 */ 
class ZC_PC_PURCHASE_MYITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PC_PURCHASE_MYITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PC_PURCHASE_MYITEMLIST, s)
	{}
	virtual ~ZC_PC_PURCHASE_MYITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_USER_COUNT = 0x00c2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_USER_COUNT
 *
 */ 
class ZC_USER_COUNT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_USER_COUNT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_USER_COUNT, s)
	{}
	virtual ~ZC_USER_COUNT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEMCOMPOSITION_LIST = 0x017b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEMCOMPOSITION_LIST
 *
 */ 
class ZC_ITEMCOMPOSITION_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEMCOMPOSITION_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEMCOMPOSITION_LIST, s)
	{}
	virtual ~ZC_ITEMCOMPOSITION_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACK_REQ_HOSTILE_GUILD = 0x0181
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQ_HOSTILE_GUILD
 *
 */ 
class ZC_ACK_REQ_HOSTILE_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQ_HOSTILE_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQ_HOSTILE_GUILD, s)
	{}
	virtual ~ZC_ACK_REQ_HOSTILE_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILLINFO_UPDATE = 0x010e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILLINFO_UPDATE
 *
 */ 
class ZC_SKILLINFO_UPDATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILLINFO_UPDATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILLINFO_UPDATE, s)
	{}
	virtual ~ZC_SKILLINFO_UPDATE() {}

	void deliver(int16_t skill_id, int16_t skill_level, int16_t sp_cost, int16_t range, bool upgradeable);
	ByteBuffer &serialize();

/* Structure */
	int16_t _skill_id{0};
	int16_t _skill_level{0};
	int16_t _sp_cost{0};
	int16_t _range{0};
	int8_t _upgradeable{0};
};

enum {
#if (CLIENT_VERSION == 'R' && PACKET_VERSION >= 20190807) || \
	(CLIENT_VERSION == 'Z' && PACKET_VERSION >= 20190918)
	ID_ZC_SKILLINFO_UPDATE2 = 0x0b33 
#else
	ID_ZC_SKILLINFO_UPDATE2 = 0x07e1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILLINFO_UPDATE2
 *
 */ 
class ZC_SKILLINFO_UPDATE2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILLINFO_UPDATE2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILLINFO_UPDATE2, s)
	{}
	virtual ~ZC_SKILLINFO_UPDATE2() {}

	void deliver(int16_t skill_id, skill_primary_type type, int16_t level, int16_t sp_cost, int16_t range, bool upgradeable);
	ByteBuffer &serialize();

/* Structure */
	int16_t _skill_id{0};
	int32_t _type{0};
	int16_t _level{0};
	int16_t _sp_cost{0};
	int16_t _range{0};
	int8_t _up_flag{0};
#if (CLIENT_VERSION == 'R' && PACKET_VERSION >= 20190807) || \
	(CLIENT_VERSION == 'Z' && PACKET_VERSION >= 20190918)
	int16_t _level2{0};
#endif
};

enum {
#if (CLIENT_VERSION == 'R' && PACKET_VERSION >= 20190807) || \
	(CLIENT_VERSION == 'Z' && PACKET_VERSION >= 20190918)
	ID_ZA_ADD_SKILL = 0x0b31
#else
	ID_ZC_ADD_SKILL = 0x0111
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_SKILL
 *
 */ 
class ZC_ADD_SKILL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_SKILL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_SKILL, s)
	{}
	virtual ~ZC_ADD_SKILL() {}

#if (CLIENT_VERSION == 'R' && PACKET_VERSION >= 20190807) || \
	(CLIENT_VERSION == 'Z' && PACKET_VERSION >= 20190918)
	void deliver(int16_t skill_id, skill_primary_type type, int16_t level, int16_t sp_cost, int16_t range, bool upgradeable, int16_t level2);
#else
	void deliver(int16_t skill_id, skill_primary_type type, int16_t level, int16_t sp_cost, int16_t range, std::string skill_name, bool upgradeable);
#endif

	ByteBuffer &serialize();

/* Structure */
	zc_skill_info_data _info;
};

enum {
#if PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILLINFO_DELETE = 0x0441
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILLINFO_DELETE
 *
 */ 
class ZC_SKILLINFO_DELETE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILLINFO_DELETE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILLINFO_DELETE, s)
	{}
	virtual ~ZC_SKILLINFO_DELETE() {}

	void deliver(int16_t skill_id);
	ByteBuffer &serialize();

/* Structure */
	int16_t _skill_id{0};
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_DISPEL = 0x01b9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DISPEL
 *
 */ 
class ZC_DISPEL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DISPEL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DISPEL, s)
	{}
	virtual ~ZC_DISPEL() {}

	void deliver(int32_t guid);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid;
};

enum {
#if PACKET_VERSION == 20091027
	ID_ZC_NOTIFY_EXP = 0x07f6
#elif PACKET_VERSION >= 20170405 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_EXP = 0x0acc
#endif
};


enum {
	ID_ZC_ACK_TOUSESKILL = 0x0110
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_TOUSESKILL
 *
 */ 
class ZC_ACK_TOUSESKILL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_TOUSESKILL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_TOUSESKILL, s)
	{}
	virtual ~ZC_ACK_TOUSESKILL() {}

	void deliver(int16_t skill_id, int32_t message_type, int32_t item_id, skill_use_fail_cause_type cause);
	ByteBuffer &serialize();

/* Structure */
	int16_t _skill_id{0};

/// message type:
/// (only used when skill id = NV_BASIC and cause = 0):
///     0 = "skill failed" MsgStringTable[159]
///     1 = "no emotions" MsgStringTable[160]
///     2 = "no sit" MsgStringTable[161]
///     3 = "no chat" MsgStringTable[162]
///     4 = "no party" MsgStringTable[163]
///     5 = "no shout" MsgStringTable[164]
///     6 = "no PKing" MsgStringTable[165]
///     7 = "no aligning" MsgStringTable[383]
///     ? = ignored
#if (CLIENT_TYPE == 'M' && PACKET_VERSION >= 20181121) || \
	(CLIENT_TYPE == 'R' && PACKET_VERSION >= 20180704) || \
	(CLIENT_TYPE == 'Z' && PACKET_VERSION >= 20181114)
	int32_t _message_type{0};
	int32_t _item_id{0};
#else
	int16_t _message_type{0};
	int16_t _item_id{0};
#endif
	int8_t _flag{0};
/// cause:
///     0 = "not enough skill level" MsgStringTable[214] (AL_WARP)
///         "steal failed" MsgStringTable[205] (TF_STEAL)
///         "envenom failed" MsgStringTable[207] (TF_POISON)
///         "skill failed" MsgStringTable[204] (otherwise)
///   ... = @see enum useskill_fail_cause
///     ? = ignored
	int8_t _cause{0};
};

enum {
#if (CLIENT_VERSION == 'R' && PACKET_VERSION >= 20190807) || \
	(CLIENT_VERSION == 'Z' && PACKET_VERSION >= 20190918)
	ID_ZC_SKILLINFO_LIST = 0x0b32
#else
	ID_ZC_SKILLINFO_LIST = 0x010f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILLINFO_LIST
 *
 */ 
class ZC_SKILLINFO_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILLINFO_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILLINFO_LIST, s)
	{}
	virtual ~ZC_SKILLINFO_LIST() {}

	void deliver(const std::vector<zc_skill_info_data> &_skills);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length;
	std::vector<zc_skill_info_data> _skills;
};

/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_EXP
 *
 */ 
class ZC_NOTIFY_EXP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_EXP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_EXP, s)
	{}
	virtual ~ZC_NOTIFY_EXP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20031117 || \
	PACKET_VERSION >= 0
	ID_ZC_CONGRATULATION = 0x01ea
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CONGRATULATION
 *
 */ 
class ZC_CONGRATULATION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CONGRATULATION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CONGRATULATION, s)
	{}
	virtual ~ZC_CONGRATULATION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_CHANGE_GUILD = 0x01b4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CHANGE_GUILD
 *
 */ 
class ZC_CHANGE_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CHANGE_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CHANGE_GUILD, s)
	{}
	virtual ~ZC_CHANGE_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 0
	ID_ZC_PROGRESS_CANCEL = 0x02f2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PROGRESS_CANCEL
 *
 */ 
class ZC_PROGRESS_CANCEL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PROGRESS_CANCEL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PROGRESS_CANCEL, s)
	{}
	virtual ~ZC_PROGRESS_CANCEL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_LONGPAR_CHANGE = 0x00b1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_LONGPAR_CHANGE
 *
 */ 
class ZC_LONGPAR_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_LONGPAR_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_LONGPAR_CHANGE, s)
	{}
	virtual ~ZC_LONGPAR_CHANGE() {}

	void deliver(status_point_type type, int16_t value);
	ByteBuffer &serialize();

/* Structure */
	status_point_type _type;
	int16_t _value;
};

enum {
#if CLIENT_TYPE == 'Z' || \
	(CLIENT_TYPE == 'M' && PACKET_VERSION >= 20170906) || \
	(CLIENT_TYPE == 'R' && PACKET_VERSION >= 20170830)
	ID_ZC_LONGLONGPAR_CHANGE = 0x0acb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_LONGLONGPAR_CHANGE
 *
 */
class ZC_LONGLONGPAR_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_LONGLONGPAR_CHANGE(std::shared_ptr<ZoneSession> s)
		: NetworkPacketTransmitter<ZoneSession>(ID_ZC_LONGLONGPAR_CHANGE, s)
	{}
	virtual ~ZC_LONGLONGPAR_CHANGE() {}

	void deliver(status_point_type type, int64_t value);
	ByteBuffer& serialize();

	/* Structure */
	status_point_type _type;
	int64_t _value;
};

enum {
#if PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081111 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_POSTDELAY_LIST = 0x043e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_POSTDELAY_LIST
 *
 */ 
class ZC_SKILL_POSTDELAY_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_POSTDELAY_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_POSTDELAY_LIST, s)
	{}
	virtual ~ZC_SKILL_POSTDELAY_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181031 || \
	PACKET_VERSION >= 0
	ID_ZC_INVENTORY_EXPANSION_INFO = 0x0b18
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INVENTORY_EXPANSION_INFO
 *
 */ 
class ZC_INVENTORY_EXPANSION_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INVENTORY_EXPANSION_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INVENTORY_EXPANSION_INFO, s)
	{}
	virtual ~ZC_INVENTORY_EXPANSION_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120221 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_ITEMLIST_NORMAL_V2 = 0x0975
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_ITEMLIST_NORMAL_V2
 *
 */ 
class ZC_STORE_ITEMLIST_NORMAL_V2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_ITEMLIST_NORMAL_V2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_ITEMLIST_NORMAL_V2, s)
	{}
	virtual ~ZC_STORE_ITEMLIST_NORMAL_V2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION == 20150128
	ID_ZC_OPEN_UI = 0x0a38
#elif PACKET_VERSION >= 20171115 || \
	PACKET_VERSION >= 20171109 || \
	PACKET_VERSION >= 0
	ID_ZC_OPEN_UI = 0x0ae2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OPEN_UI
 *
 */ 
class ZC_OPEN_UI : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OPEN_UI(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OPEN_UI, s)
	{}
	virtual ~ZC_OPEN_UI() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20180829 || \
	PACKET_VERSION >= 20180822 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_ITEMLIST_NORMAL_V6 = 0x0b09
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_ITEMLIST_NORMAL_V6
 *
 */ 
class ZC_STORE_ITEMLIST_NORMAL_V6 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_ITEMLIST_NORMAL_V6(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_ITEMLIST_NORMAL_V6, s)
	{}
	virtual ~ZC_STORE_ITEMLIST_NORMAL_V6() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20060306 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_MAIL_RETURN = 0x0274
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_MAIL_RETURN
 *
 */ 
class ZC_ACK_MAIL_RETURN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_MAIL_RETURN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_MAIL_RETURN, s)
	{}
	virtual ~ZC_ACK_MAIL_RETURN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140312 || \
	PACKET_VERSION >= 0
	ID_ZC_BATTLEFIELD_NOTIFY_HP2 = 0x0a0e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BATTLEFIELD_NOTIFY_HP2
 *
 */ 
class ZC_BATTLEFIELD_NOTIFY_HP2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BATTLEFIELD_NOTIFY_HP2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BATTLEFIELD_NOTIFY_HP2, s)
	{}
	virtual ~ZC_BATTLEFIELD_NOTIFY_HP2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MAPPROPERTY2 = 0x01d6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MAPPROPERTY2
 *
 */ 
class ZC_NOTIFY_MAPPROPERTY2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MAPPROPERTY2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MAPPROPERTY2, s)
	{}
	virtual ~ZC_NOTIFY_MAPPROPERTY2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100113 || \
	PACKET_VERSION >= 0
	ID_ZC_SIMPLE_CASH_BTNSHOW = 0x080d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SIMPLE_CASH_BTNSHOW
 *
 */ 
class ZC_SIMPLE_CASH_BTNSHOW : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SIMPLE_CASH_BTNSHOW(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SIMPLE_CASH_BTNSHOW, s)
	{}
	virtual ~ZC_SIMPLE_CASH_BTNSHOW() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20061030 || \
	PACKET_VERSION >= 0
	ID_ZC_MSG = 0x0291
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MSG
 *
 */ 
class ZC_MSG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MSG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MSG, s)
	{}
	virtual ~ZC_MSG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120207 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER_TO_PM = 0x096c
#elif PACKET_VERSION >= 20180131 || \
	PACKET_VERSION >= 20180117 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20171227 || \
	PACKET_VERSION >= 20171121 || \
	PACKET_VERSION >= 20171115 || \
	PACKET_VERSION >= 20171018 || \
	PACKET_VERSION >= 20170823 || \
	PACKET_VERSION >= 20170816 || \
	PACKET_VERSION >= 20170201 || \
	PACKET_VERSION >= 20170125 || \
	PACKET_VERSION >= 20170104 || \
	PACKET_VERSION >= 20161228 || \
	PACKET_VERSION >= 20160913 || \
	PACKET_VERSION >= 20160907 || \
	PACKET_VERSION >= 20160817 || \
	PACKET_VERSION >= 20160810 || \
	PACKET_VERSION >= 20160727 || \
	PACKET_VERSION >= 20160720 || \
	PACKET_VERSION >= 20160713 || \
	PACKET_VERSION >= 20160629 || \
	PACKET_VERSION >= 20160622 || \
	PACKET_VERSION >= 20160106 || \
	PACKET_VERSION >= 20151021 || \
	PACKET_VERSION >= 20151014 || \
	PACKET_VERSION >= 20150527 || \
	PACKET_VERSION >= 20150520 || \
	PACKET_VERSION >= 20150408 || \
	PACKET_VERSION >= 20150401 || \
	PACKET_VERSION >= 20150318 || \
	PACKET_VERSION >= 20150311 || \
	PACKET_VERSION >= 20150107 || \
	PACKET_VERSION >= 20141210 || \
	PACKET_VERSION >= 20141203 || \
	PACKET_VERSION >= 20141008 || \
	PACKET_VERSION >= 20141001 || \
	PACKET_VERSION >= 20140416 || \
	PACKET_VERSION >= 20140409 || \
	PACKET_VERSION >= 20140319 || \
	PACKET_VERSION >= 20140312 || \
	PACKET_VERSION >= 20140108 || \
	PACKET_VERSION >= 20131120 || \
	PACKET_VERSION >= 20131113 || \
	PACKET_VERSION >= 20131016 || \
	PACKET_VERSION >= 20131008 || \
	PACKET_VERSION >= 20130925 || \
	PACKET_VERSION >= 20130917 || \
	PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20121227 || \
	PACKET_VERSION >= 20121218 || \
	PACKET_VERSION >= 20121212 || \
	PACKET_VERSION >= 20121205 || \
	PACKET_VERSION >= 20121128 || \
	PACKET_VERSION >= 20120801 || \
	PACKET_VERSION >= 20120724 || \
	PACKET_VERSION >= 20120417 || \
	PACKET_VERSION >= 20120410
	ID_ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER_TO_PM = 0x091c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER_TO_PM
 *
 */ 
class ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER_TO_PM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER_TO_PM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER_TO_PM, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_CANCEL_VOLUNTEER_TO_PM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050608 || \
	PACKET_VERSION >= 0
	ID_ZC_FEED_MER = 0x022f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FEED_MER
 *
 */ 
class ZC_FEED_MER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FEED_MER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FEED_MER, s)
	{}
	virtual ~ZC_FEED_MER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100601 || \
	PACKET_VERSION >= 0
	ID_ZC_SEARCH_STORE_INFO_ACK = 0x0836
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SEARCH_STORE_INFO_ACK
 *
 */ 
class ZC_SEARCH_STORE_INFO_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SEARCH_STORE_INFO_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SEARCH_STORE_INFO_ACK, s)
	{}
	virtual ~ZC_SEARCH_STORE_INFO_ACK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130911 || \
	PACKET_VERSION >= 0
	ID_ZC_NPC_MARKET_OPEN = 0x09d5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NPC_MARKET_OPEN
 *
 */ 
class ZC_NPC_MARKET_OPEN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NPC_MARKET_OPEN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NPC_MARKET_OPEN, s)
	{}
	virtual ~ZC_NPC_MARKET_OPEN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140312 || \
	PACKET_VERSION >= 20140305 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_PICKUP_ACK_V6 = 0x0a0c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_PICKUP_ACK_V6
 *
 */ 
class ZC_ITEM_PICKUP_ACK_V6 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_PICKUP_ACK_V6(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_PICKUP_ACK_V6, s)
	{}
	virtual ~ZC_ITEM_PICKUP_ACK_V6() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ITEM_PICKUP_ACK_V7 = 0x0a37
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_PICKUP_ACK_V7
 *
 */ 
class ZC_ITEM_PICKUP_ACK_V7 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_PICKUP_ACK_V7(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_PICKUP_ACK_V7, s)
	{}
	virtual ~ZC_ITEM_PICKUP_ACK_V7() {}

	void deliver(item_entry_data id, int16_t amount, item_inventory_addition_notif_type result);
	ByteBuffer &serialize();

/* Structure */
	item_entry_data _id;
	int16_t _amount;
	item_inventory_addition_notif_type _result;
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_DISAPPEAR = 0x0120
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_DISAPPEAR
 *
 */ 
class ZC_SKILL_DISAPPEAR : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_DISAPPEAR(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_DISAPPEAR, s)
	{}
	virtual ~ZC_SKILL_DISAPPEAR() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_CART_EQUIPMENT_ITEMLIST = 0x0122
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_EQUIPMENT_ITEMLIST
 *
 */ 
class ZC_CART_EQUIPMENT_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_EQUIPMENT_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_EQUIPMENT_ITEMLIST, s)
	{}
	virtual ~ZC_CART_EQUIPMENT_ITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_CONCLUDE_EXCHANGE_ITEM = 0x00ec
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CONCLUDE_EXCHANGE_ITEM
 *
 */ 
class ZC_CONCLUDE_EXCHANGE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
	enum zc_conclude_exchange_item_type
	{
		ZC_CONCLUDEEXCHANGE_ITEM_FOR_SELF = 0,
		ZC_CONCLUDEEXCHANGE_ITEM_FOR_OTHER_PLAYER = 1
	};
public:
	ZC_CONCLUDE_EXCHANGE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CONCLUDE_EXCHANGE_ITEM, s)
	{}
	virtual ~ZC_CONCLUDE_EXCHANGE_ITEM() {}

	void deliver(zc_conclude_exchange_item_type type);
	ByteBuffer &serialize();

/* Structure */
	int8_t _type{ 0 }; // 0 - self, 1 - other player.
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_PET_ACT = 0x01aa
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PET_ACT
 *
 */ 
class ZC_PET_ACT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PET_ACT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PET_ACT, s)
	{}
	virtual ~ZC_PET_ACT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_OTHER_GUILD_LIST = 0x0164
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OTHER_GUILD_LIST
 *
 */ 
class ZC_OTHER_GUILD_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OTHER_GUILD_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OTHER_GUILD_LIST, s)
	{}
	virtual ~ZC_OTHER_GUILD_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111004 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ENTRY_QUEUE_APPLY = 0x08d8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ENTRY_QUEUE_APPLY
 *
 */ 
class ZC_ACK_ENTRY_QUEUE_APPLY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ENTRY_QUEUE_APPLY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ENTRY_QUEUE_APPLY, s)
	{}
	virtual ~ZC_ACK_ENTRY_QUEUE_APPLY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120523 || \
	PACKET_VERSION >= 20090408 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090320 || \
	PACKET_VERSION >= 20080108 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20070611 || \
	PACKET_VERSION >= 0
	ID_ZC_HACKSH_CPX_MSG = 0x02a6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HACKSH_CPX_MSG
 *
 */ 
class ZC_HACKSH_CPX_MSG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HACKSH_CPX_MSG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HACKSH_CPX_MSG, s)
	{}
	virtual ~ZC_HACKSH_CPX_MSG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091006 || \
	PACKET_VERSION >= 0
	ID_ZC_BATTLE_JOIN_DISABLE_STATE = 0x07f4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BATTLE_JOIN_DISABLE_STATE
 *
 */ 
class ZC_BATTLE_JOIN_DISABLE_STATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BATTLE_JOIN_DISABLE_STATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BATTLE_JOIN_DISABLE_STATE, s)
	{}
	virtual ~ZC_BATTLE_JOIN_DISABLE_STATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_UPDATE_CHARSTAT2 = 0x01f2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_CHARSTAT2
 *
 */ 
class ZC_UPDATE_CHARSTAT2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_CHARSTAT2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_CHARSTAT2, s)
	{}
	virtual ~ZC_UPDATE_CHARSTAT2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20031124 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_POSITION_TO_GUILDM = 0x01eb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_POSITION_TO_GUILDM
 *
 */ 
class ZC_NOTIFY_POSITION_TO_GUILDM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_POSITION_TO_GUILDM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_POSITION_TO_GUILDM, s)
	{}
	virtual ~ZC_NOTIFY_POSITION_TO_GUILDM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_MONSTER_TALK = 0x01cc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MONSTER_TALK
 *
 */ 
class ZC_MONSTER_TALK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MONSTER_TALK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MONSTER_TALK, s)
	{}
	virtual ~ZC_MONSTER_TALK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACCEPT_QUIT = 0x0083
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACCEPT_QUIT
 *
 */ 
class ZC_ACCEPT_QUIT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACCEPT_QUIT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACCEPT_QUIT, s)
	{}
	virtual ~ZC_ACCEPT_QUIT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140226 || \
	PACKET_VERSION >= 20140219 || \
	PACKET_VERSION >= 20140129 || \
	PACKET_VERSION >= 20140108 || \
	PACKET_VERSION >= 20120925 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_PICKUP_ACK_V5 = 0x0990
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_PICKUP_ACK_V5
 *
 */ 
class ZC_ITEM_PICKUP_ACK_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_PICKUP_ACK_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_PICKUP_ACK_V5, s)
	{}
	virtual ~ZC_ITEM_PICKUP_ACK_V5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_FEED_PET = 0x01a3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FEED_PET
 *
 */ 
class ZC_FEED_PET : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FEED_PET(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FEED_PET, s)
	{}
	virtual ~ZC_FEED_PET() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091229 || \
	PACKET_VERSION >= 20091228 || \
	PACKET_VERSION >= 20091222 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_BOOKING_ACK_DELETE = 0x0807
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_BOOKING_ACK_DELETE
 *
 */ 
class ZC_PARTY_BOOKING_ACK_DELETE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_BOOKING_ACK_DELETE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_BOOKING_ACK_DELETE, s)
	{}
	virtual ~ZC_PARTY_BOOKING_ACK_DELETE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130821 || \
	PACKET_VERSION >= 0
	ID_ZC_PROGRESS_ACTOR = 0x09d1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PROGRESS_ACTOR
 *
 */ 
class ZC_PROGRESS_ACTOR : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PROGRESS_ACTOR(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PROGRESS_ACTOR, s)
	{}
	virtual ~ZC_PROGRESS_ACTOR() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081111 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_POSTDELAY = 0x043d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_POSTDELAY
 *
 */ 
class ZC_SKILL_POSTDELAY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_POSTDELAY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_POSTDELAY, s)
	{}
	virtual ~ZC_SKILL_POSTDELAY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110810 || \
	PACKET_VERSION >= 20110809 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_TAKEOFF_EQUIP_ACK2 = 0x08d1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_TAKEOFF_EQUIP_ACK2
 *
 */ 
class ZC_REQ_TAKEOFF_EQUIP_ACK2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_TAKEOFF_EQUIP_ACK2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_TAKEOFF_EQUIP_ACK2, s)
	{}
	virtual ~ZC_REQ_TAKEOFF_EQUIP_ACK2() {}

	void deliver(int16_t inventory_index, int32_t equip_location_mask, item_unequip_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int16_t _inventory_index{0};
	int32_t _equip_location_mask{0};
	int8_t _result{0};
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20051010 || \
	PACKET_VERSION >= 20050104 || \
	PACKET_VERSION >= 20050103 || \
	PACKET_VERSION >= 20040705 || \
	PACKET_VERSION >= 0
	ID_ZC_STARSKILL = 0x020e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STARSKILL
 *
 */ 
class ZC_STARSKILL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STARSKILL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STARSKILL, s)
	{}
	virtual ~ZC_STARSKILL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110816 || \
	PACKET_VERSION >= 0
	ID_ZC_SE_CASHSHOP_UPDATE = 0x08d3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SE_CASHSHOP_UPDATE
 *
 */ 
class ZC_SE_CASHSHOP_UPDATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SE_CASHSHOP_UPDATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SE_CASHSHOP_UPDATE, s)
	{}
	virtual ~ZC_SE_CASHSHOP_UPDATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130828 || \
	PACKET_VERSION >= 0
	ID_ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V5 = 0x09d3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V5
 *
 */ 
class ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V5, s)
	{}
	virtual ~ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140924 || \
	PACKET_VERSION >= 0
	ID_ZC_OPEN_RODEX_THROUGH_NPC_ONLY = 0x0a32
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OPEN_RODEX_THROUGH_NPC_ONLY
 *
 */ 
class ZC_OPEN_RODEX_THROUGH_NPC_ONLY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OPEN_RODEX_THROUGH_NPC_ONLY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OPEN_RODEX_THROUGH_NPC_ONLY, s)
	{}
	virtual ~ZC_OPEN_RODEX_THROUGH_NPC_ONLY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140402 || \
	PACKET_VERSION >= 0
	ID_ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V6 = 0x0a11
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V6
 *
 */ 
class ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V6 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V6(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V6, s)
	{}
	virtual ~ZC_GUILDSTORAGE_ITEMLIST_EQUIP_V6() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20061204 || \
	PACKET_VERSION >= 0
	ID_ZC_READ_BOOK = 0x0294
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_READ_BOOK
 *
 */ 
class ZC_READ_BOOK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_READ_BOOK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_READ_BOOK, s)
	{}
	virtual ~ZC_READ_BOOK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100629 || \
	PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20091006 || \
	PACKET_VERSION >= 20090929 || \
	PACKET_VERSION >= 0
	ID_ZC_BATTLE_NOTI_START_STEP = 0x07f2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BATTLE_NOTI_START_STEP
 *
 */ 
class ZC_BATTLE_NOTI_START_STEP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BATTLE_NOTI_START_STEP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BATTLE_NOTI_START_STEP, s)
	{}
	virtual ~ZC_BATTLE_NOTI_START_STEP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110810 || \
	PACKET_VERSION >= 20110809 || \
	PACKET_VERSION >= 0
	ID_ZC_FASTMOVE = 0x08d2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FASTMOVE
 *
 */ 
class ZC_FASTMOVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FASTMOVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FASTMOVE, s)
	{}
	virtual ~ZC_FASTMOVE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_POSITION_INFO = 0x0160
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_POSITION_INFO
 *
 */ 
class ZC_POSITION_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_POSITION_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_POSITION_INFO, s)
	{}
	virtual ~ZC_POSITION_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111122 || \
	PACKET_VERSION >= 0
	ID_ZC_INVENTORY_TAB = 0x0908
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INVENTORY_TAB
 *
 */ 
class ZC_INVENTORY_TAB : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INVENTORY_TAB(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INVENTORY_TAB, s)
	{}
	virtual ~ZC_INVENTORY_TAB() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_DELETE_MEMBER_FROM_GROUP = 0x0105
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DELETE_MEMBER_FROM_GROUP
 *
 */ 
class ZC_DELETE_MEMBER_FROM_GROUP : public Base::NetworkPacketTransmitter<ZoneSession>
{
	enum zc_delete_member_from_group_result_type
	{
		ZC_DELETEMEMBER_FROMGROUP_LEAVE = 0,
		ZC_DELETEMEMBER_FROMGROUP_EXPEL = 1,
		ZC_DELETEMEMBER_FROMGROUP_LEAVE_UNAUTHORIZED_MAP = 2,
		ZC_DELETEMEMBER_FROMGROUP_EXPEL_UNAUTHORIZED_MAP = 3
	};
public:
	ZC_DELETE_MEMBER_FROM_GROUP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DELETE_MEMBER_FROM_GROUP, s)
	{}
	virtual ~ZC_DELETE_MEMBER_FROM_GROUP() {}

	void deliver(int account_id, std::string name, zc_delete_member_from_group_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int _account_id{ 0 };
	char _name[MAX_UNIT_NAME_LENGTH]{ 0 };
	int8_t _result{ 0 };
};

enum {
#if PACKET_VERSION >= 20061226 || \
	PACKET_VERSION >= 0
	ID_ZC_MER_PROPERTY = 0x029c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MER_PROPERTY
 *
 */ 
class ZC_MER_PROPERTY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MER_PROPERTY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MER_PROPERTY, s)
	{}
	virtual ~ZC_MER_PROPERTY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140611 || \
	PACKET_VERSION >= 20140605 || \
	PACKET_VERSION >= 0
	ID_ZC_ACCEPT_ENTER3 = 0x0a18
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACCEPT_ENTER3
 *
 */ 
class ZC_ACCEPT_ENTER3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACCEPT_ENTER3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACCEPT_ENTER3, s)
	{}
	virtual ~ZC_ACCEPT_ENTER3() {}

	void deliver(int16_t x, int16_t y, int16_t dir, int16_t font, int8_t gender);
	ByteBuffer &serialize();

/* Structure */
	int32_t _start_time{0};
	char _packed_pos[3]{0};
	int8_t _x_size{0};
	int8_t _y_size{0};
	int16_t _font{0};
	int8_t _gender{0};
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACCEPT_ENTER2 = 0x02eb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACCEPT_ENTER2
 *
 */ 
class ZC_ACCEPT_ENTER2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACCEPT_ENTER2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACCEPT_ENTER2, s)
	{}
	virtual ~ZC_ACCEPT_ENTER2() {}

	void deliver(int16_t x, int16_t y, int16_t dir, int16_t font);
	ByteBuffer &serialize();

/* Structure */
	int32_t _start_time{0};
	char _packed_pos[3]{0};
	int8_t _x_size{0};
	int8_t _y_size{0};
	int16_t _font{0};
};

enum {
#if PACKET_VERSION >= 20120214 || \
	PACKET_VERSION >= 0
	ID_ZC_SAY_DIALOG2 = 0x0972
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SAY_DIALOG2
 *
 */ 
class ZC_SAY_DIALOG2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SAY_DIALOG2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SAY_DIALOG2, s)
	{}
	virtual ~ZC_SAY_DIALOG2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_GUILD_CHAT = 0x017f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILD_CHAT
 *
 */ 
class ZC_GUILD_CHAT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILD_CHAT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILD_CHAT, s)
	{}
	virtual ~ZC_GUILD_CHAT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_STATUS = 0x00bd
#endif
};

struct zc_status_data {
	int16_t status_points{0};
	int8_t  strength{1};
	int8_t  strength_req_stats{1};
	int8_t  agility{1};
	int8_t  agility_req_stats{1};
	int8_t  vitality{1};
	int8_t  vitality_req_stats{1};
	int8_t  intelligence{1};
	int8_t  intelligence_req_stats{1};
	int8_t  dexterity{1};
	int8_t  dexterity_req_stats{1};
	int8_t  luck{1};
	int8_t  luck_req_stats{1};
	int16_t status_atk{1};
	int16_t equip_atk{1};
	int16_t status_matk{1};
	int16_t equip_matk{1};
	int16_t soft_def{1};
	int16_t hard_def{1};
	int16_t soft_mdef{1};
	int16_t hard_mdef{1};
	int16_t hit{1};
	int16_t flee{1};
	int16_t perfect_dodge{1};
	int16_t critical{1};
	int16_t attack_speed{0};
	int16_t plus_aspd{0}; // always 0 apparently.
};

/**
 * @brief Main object for the aegis packet: ZC_STATUS
 *
 */ 
class ZC_STATUS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STATUS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STATUS, s)
	{}
	virtual ~ZC_STATUS() {}

	void deliver(zc_status_data &data);
	ByteBuffer &serialize();

/* Structure */
	zc_status_data _data;
};

enum {
#if PACKET_VERSION >= 20141126 || \
	PACKET_VERSION >= 0
	ID_ZC_HP_INFO_TINY = 0x0a36
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HP_INFO_TINY
 *
 */ 
class ZC_HP_INFO_TINY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HP_INFO_TINY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HP_INFO_TINY, s)
	{}
	virtual ~ZC_HP_INFO_TINY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20040628 || \
	PACKET_VERSION >= 0
	ID_ZC_DIVORCE = 0x0205
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DIVORCE
 *
 */ 
class ZC_DIVORCE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DIVORCE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DIVORCE, s)
	{}
	virtual ~ZC_DIVORCE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_MAKE_GROUP = 0x00fa
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_MAKE_GROUP
 *
 */ 
class ZC_ACK_MAKE_GROUP : public Base::NetworkPacketTransmitter<ZoneSession>
{
	enum zcack_makegroup_result_type
	{
		ZCACK_MAKEGROUP_RESULT_SUCCESS = 0,
		ZCACK_MAKEGROUP_RESULT_NAME_ALREADY_EXISTS = 1,
		ZCACK_MAKEGROUP_RESULT_ALREADY_IN_PARTY = 2,
		ZCACK_MAKEGROUP_RESULT_UNAUTHORIZED_ON_MAP = 3,
		ZCACK_MAKEGROUP_RESULT_NOMSG = 4
	};
public:
	ZC_ACK_MAKE_GROUP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_MAKE_GROUP, s)
	{}
	virtual ~ZC_ACK_MAKE_GROUP() {}

	void deliver(zcack_makegroup_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int8_t _result{ 0 };
};

enum {
#if PACKET_VERSION >= 20160727 || \
	PACKET_VERSION >= 0
	ID_ZC_OFFLINE_STORE_ITEMS = 0x0a91
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OFFLINE_STORE_ITEMS
 *
 */ 
class ZC_OFFLINE_STORE_ITEMS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OFFLINE_STORE_ITEMS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OFFLINE_STORE_ITEMS, s)
	{}
	virtual ~ZC_OFFLINE_STORE_ITEMS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACK_REQ_ALLY_GUILD = 0x0173
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQ_ALLY_GUILD
 *
 */ 
class ZC_ACK_REQ_ALLY_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQ_ALLY_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQ_ALLY_GUILD, s)
	{}
	virtual ~ZC_ACK_REQ_ALLY_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20170906 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIPWIN_OTHER = 0x0adc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIPWIN_OTHER
 *
 */ 
class ZC_EQUIPWIN_OTHER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIPWIN_OTHER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIPWIN_OTHER, s)
	{}
	virtual ~ZC_EQUIPWIN_OTHER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ITEMCOMPOSITION = 0x017d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ITEMCOMPOSITION
 *
 */ 
class ZC_ACK_ITEMCOMPOSITION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ITEMCOMPOSITION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ITEMCOMPOSITION, s)
	{}
	virtual ~ZC_ACK_ITEMCOMPOSITION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 0
	ID_ZC_PROGRESS = 0x02f0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PROGRESS
 *
 */ 
class ZC_PROGRESS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PROGRESS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PROGRESS, s)
	{}
	virtual ~ZC_PROGRESS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20070604 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_PICKUP_PARTY = 0x02b8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_PICKUP_PARTY
 *
 */ 
class ZC_ITEM_PICKUP_PARTY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_PICKUP_PARTY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_PICKUP_PARTY, s)
	{}
	virtual ~ZC_ITEM_PICKUP_PARTY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130717 || \
	PACKET_VERSION >= 20130515 || \
	PACKET_VERSION >= 0
	ID_ZC_C_MARKERINFO = 0x09c1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_C_MARKERINFO
 *
 */ 
class ZC_C_MARKERINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_C_MARKERINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_C_MARKERINFO, s)
	{}
	virtual ~ZC_C_MARKERINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100309 || \
	PACKET_VERSION >= 20100303 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ITEMLIST_BUYING_STORE = 0x0818
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ITEMLIST_BUYING_STORE
 *
 */ 
class ZC_ACK_ITEMLIST_BUYING_STORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ITEMLIST_BUYING_STORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ITEMLIST_BUYING_STORE, s)
	{}
	virtual ~ZC_ACK_ITEMLIST_BUYING_STORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_NOTIFY_SKILL_POSITION = 0x0115
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_SKILL_POSITION
 *
 */ 
class ZC_NOTIFY_SKILL_POSITION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_SKILL_POSITION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_SKILL_POSITION, s)
	{}
	virtual ~ZC_NOTIFY_SKILL_POSITION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_NOTIFY_NEWENTRY11 = 0x09fe
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_NEWENTRY11
 *
 */ 
class ZC_NOTIFY_NEWENTRY11 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_NEWENTRY11(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_NEWENTRY11, s)
	{}
	virtual ~ZC_NOTIFY_NEWENTRY11() {}

	void deliver(entity_viewport_entry entry);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length;
	entity_viewport_entry _entry;
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_REQ_ITEM_EXPLANATION_ACK = 0x00ae
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_ITEM_EXPLANATION_ACK
 *
 */ 
class ZC_REQ_ITEM_EXPLANATION_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_ITEM_EXPLANATION_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_ITEM_EXPLANATION_ACK, s)
	{}
	virtual ~ZC_REQ_ITEM_EXPLANATION_ACK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140917 || \
	PACKET_VERSION >= 0
	ID_ZC_RESULT_PACKAGE_ITEM_TEST = 0x0a31
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_RESULT_PACKAGE_ITEM_TEST
 *
 */ 
class ZC_RESULT_PACKAGE_ITEM_TEST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_RESULT_PACKAGE_ITEM_TEST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_RESULT_PACKAGE_ITEM_TEST, s)
	{}
	virtual ~ZC_RESULT_PACKAGE_ITEM_TEST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20061218 || \
	PACKET_VERSION >= 20061211 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_EQUIPMENT_ITEMLIST2 = 0x0296
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_EQUIPMENT_ITEMLIST2
 *
 */ 
class ZC_STORE_EQUIPMENT_ITEMLIST2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_EQUIPMENT_ITEMLIST2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_EQUIPMENT_ITEMLIST2, s)
	{}
	virtual ~ZC_STORE_EQUIPMENT_ITEMLIST2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070904 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_EQUIPMENT_ITEMLIST3 = 0x02d1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_EQUIPMENT_ITEMLIST3
 *
 */ 
class ZC_STORE_EQUIPMENT_ITEMLIST3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_EQUIPMENT_ITEMLIST3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_EQUIPMENT_ITEMLIST3, s)
	{}
	virtual ~ZC_STORE_EQUIPMENT_ITEMLIST3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20131030 || \
	PACKET_VERSION >= 0
	ID_ZC_WHISPER02 = 0x09de
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_WHISPER02
 *
 */ 
class ZC_WHISPER02 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_WHISPER02(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_WHISPER02, s)
	{}
	virtual ~ZC_WHISPER02() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_OPEN_EDITDLG = 0x0142
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OPEN_EDITDLG
 *
 */ 
class ZC_OPEN_EDITDLG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OPEN_EDITDLG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OPEN_EDITDLG, s)
	{}
	virtual ~ZC_OPEN_EDITDLG() {}

	void deliver(int32_t guid);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid{0};
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_GUILD_EMBLEM_IMG = 0x0152
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILD_EMBLEM_IMG
 *
 */ 
class ZC_GUILD_EMBLEM_IMG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILD_EMBLEM_IMG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILD_EMBLEM_IMG, s)
	{}
	virtual ~ZC_GUILD_EMBLEM_IMG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACK_CHANGE_GUILD_POSITIONINFO = 0x0174
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_CHANGE_GUILD_POSITIONINFO
 *
 */ 
class ZC_ACK_CHANGE_GUILD_POSITIONINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_CHANGE_GUILD_POSITIONINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_CHANGE_GUILD_POSITIONINFO, s)
	{}
	virtual ~ZC_ACK_CHANGE_GUILD_POSITIONINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120307 || \
	PACKET_VERSION >= 20120103 || \
	PACKET_VERSION >= 20111108 || \
	PACKET_VERSION >= 20111004 || \
	PACKET_VERSION >= 0
	ID_ZC_NAVIGATION_ACTIVE = 0x08e2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NAVIGATION_ACTIVE
 *
 */ 
class ZC_NAVIGATION_ACTIVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NAVIGATION_ACTIVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NAVIGATION_ACTIVE, s)
	{}
	virtual ~ZC_NAVIGATION_ACTIVE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_CART_NORMAL_ITEMLIST = 0x0123
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_NORMAL_ITEMLIST
 *
 */ 
class ZC_CART_NORMAL_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_NORMAL_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_NORMAL_ITEMLIST, s)
	{}
	virtual ~ZC_CART_NORMAL_ITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070205 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_CASH_PASSWORD = 0x02aa
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_CASH_PASSWORD
 *
 */ 
class ZC_REQ_CASH_PASSWORD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_CASH_PASSWORD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_CASH_PASSWORD, s)
	{}
	virtual ~ZC_REQ_CASH_PASSWORD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20180801 || \
	PACKET_VERSION >= 20180725 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIPWIN_MICROSCOPE_V7 = 0x0b03
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIPWIN_MICROSCOPE_V7
 *
 */ 
class ZC_EQUIPWIN_MICROSCOPE_V7 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIPWIN_MICROSCOPE_V7(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIPWIN_MICROSCOPE_V7, s)
	{}
	virtual ~ZC_EQUIPWIN_MICROSCOPE_V7() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140820 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIPWIN_MICROSCOPE_V6 = 0x0a2d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIPWIN_MICROSCOPE_V6
 *
 */ 
class ZC_EQUIPWIN_MICROSCOPE_V6 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIPWIN_MICROSCOPE_V6(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIPWIN_MICROSCOPE_V6, s)
	{}
	virtual ~ZC_EQUIPWIN_MICROSCOPE_V6() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120925 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIPWIN_MICROSCOPE_V5 = 0x0997
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIPWIN_MICROSCOPE_V5
 *
 */ 
class ZC_EQUIPWIN_MICROSCOPE_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIPWIN_MICROSCOPE_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIPWIN_MICROSCOPE_V5, s)
	{}
	virtual ~ZC_EQUIPWIN_MICROSCOPE_V5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050328 || \
	PACKET_VERSION >= 0
	ID_ZC_TAEKWON_POINT = 0x0224
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_TAEKWON_POINT
 *
 */ 
class ZC_TAEKWON_POINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_TAEKWON_POINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_TAEKWON_POINT, s)
	{}
	virtual ~ZC_TAEKWON_POINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130327 || \
	PACKET_VERSION >= 20130313 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REMOVE_BARGAIN_SALE_ITEM = 0x09b1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REMOVE_BARGAIN_SALE_ITEM
 *
 */ 
class ZC_ACK_REMOVE_BARGAIN_SALE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REMOVE_BARGAIN_SALE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REMOVE_BARGAIN_SALE_ITEM, s)
	{}
	virtual ~ZC_ACK_REMOVE_BARGAIN_SALE_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_GROUP_ISALIVE = 0x0ab2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GROUP_ISALIVE
 *
 */ 
class ZC_GROUP_ISALIVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GROUP_ISALIVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GROUP_ISALIVE, s)
	{}
	virtual ~ZC_GROUP_ISALIVE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100601 || \
	PACKET_VERSION >= 0
	ID_ZC_SEARCH_STORE_INFO_FAILED = 0x0837
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SEARCH_STORE_INFO_FAILED
 *
 */ 
class ZC_SEARCH_STORE_INFO_FAILED : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SEARCH_STORE_INFO_FAILED(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SEARCH_STORE_INFO_FAILED, s)
	{}
	virtual ~ZC_SEARCH_STORE_INFO_FAILED() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_UPDATE_MAPINFO = 0x0192
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_MAPINFO
 *
 */ 
class ZC_UPDATE_MAPINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_MAPINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_MAPINFO, s)
	{}
	virtual ~ZC_UPDATE_MAPINFO() {}

	void deliver(int16_t x, int16_t y, const char *map_name, int16_t type);
	ByteBuffer &serialize();

/* Structure */
	int16_t _x{0};
	int16_t _y{0};
	int16_t _type{0}; // 5 = icewall
	char _map_name[MAP_NAME_LENGTH_EXT]{0};
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_POSITION_TO_GROUPM = 0x0107
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_POSITION_TO_GROUPM
 *
 */ 
class ZC_NOTIFY_POSITION_TO_GROUPM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_POSITION_TO_GROUPM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_POSITION_TO_GROUPM, s)
	{}
	virtual ~ZC_NOTIFY_POSITION_TO_GROUPM() {}

	void deliver(int account_id, MapCoords current_mcoords);
	ByteBuffer &serialize();

/* Structure */
	int _account_id{ 0 };
	int16_t _x{ 0 }, _y{ 0 };
};

enum {
#if PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MEMBERMGR_INFO = 0x0154
#elif PACKET_VERSION >= 20161026 || \
	PACKET_VERSION >= 0
	ID_ZC_MEMBERMGR_INFO = 0x0aa5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MEMBERMGR_INFO
 *
 */ 
class ZC_MEMBERMGR_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MEMBERMGR_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MEMBERMGR_INFO, s)
	{}
	virtual ~ZC_MEMBERMGR_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111122 || \
	PACKET_VERSION >= 0
	ID_ZC_CART_ITEMLIST_EQUIP = 0x0903
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_ITEMLIST_EQUIP
 *
 */ 
class ZC_CART_ITEMLIST_EQUIP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_ITEMLIST_EQUIP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_ITEMLIST_EQUIP, s)
	{}
	virtual ~ZC_CART_ITEMLIST_EQUIP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20160622 || \
	PACKET_VERSION >= 0
	ID_ZC_GUILD_INFO = 0x0a84
#elif PACKET_VERSION >= 0
	ID_ZC_GUILD_INFO = 0x0150
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILD_INFO
 *
 */ 
class ZC_GUILD_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILD_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILD_INFO, s)
	{}
	virtual ~ZC_GUILD_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REQ_DISCONNECT = 0x018b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQ_DISCONNECT
 *
 */ 
class ZC_ACK_REQ_DISCONNECT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQ_DISCONNECT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQ_DISCONNECT, s)
	{}
	virtual ~ZC_ACK_REQ_DISCONNECT() {}

	void deliver(bool wait);
	ByteBuffer &serialize();

/* Structure */
	int16_t _waiting{0}; // 0 =  allowed, 1 = not allowed (wait 10 seconds)
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_MEMBER_ADD = 0x0182
#elif PACKET_VERSION >= 20161026 || \
	PACKET_VERSION >= 0
	ID_ZC_MEMBER_ADD = 0x0aa6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MEMBER_ADD
 *
 */ 
class ZC_MEMBER_ADD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MEMBER_ADD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MEMBER_ADD, s)
	{}
	virtual ~ZC_MEMBER_ADD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_STATUS_CHANGE = 0x00be
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STATUS_CHANGE
 *
 */ 
class ZC_STATUS_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STATUS_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STATUS_CHANGE, s)
	{}
	virtual ~ZC_STATUS_CHANGE() {}

	void deliver(status_point_type type, int8_t value);
	ByteBuffer &serialize();

/* Structure */
	status_point_type _type; // int16_t
	int8_t _value;
};

enum {
#if PACKET_VERSION >= 20131023 || \
	PACKET_VERSION >= 20110803 || \
	PACKET_VERSION >= 20110802 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_NEWENTRY10 = 0x09dc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_NEWENTRY10
 *
 */ 
class ZC_NOTIFY_NEWENTRY10 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_NEWENTRY10(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_NEWENTRY10, s)
	{}
	virtual ~ZC_NOTIFY_NEWENTRY10() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111025 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_NOTIFY_INSERT = 0x08ec
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_NOTIFY_INSERT
 *
 */ 
class ZC_PARTY_RECRUIT_NOTIFY_INSERT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_NOTIFY_INSERT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_NOTIFY_INSERT, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_NOTIFY_INSERT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_ALLY_GUILD = 0x0171
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_ALLY_GUILD
 *
 */ 
class ZC_REQ_ALLY_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_ALLY_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_ALLY_GUILD, s)
	{}
	virtual ~ZC_REQ_ALLY_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100303 || \
	PACKET_VERSION >= 0
	ID_ZC_OPEN_BUYING_STORE = 0x0810
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OPEN_BUYING_STORE
 *
 */ 
class ZC_OPEN_BUYING_STORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OPEN_BUYING_STORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OPEN_BUYING_STORE, s)
	{}
	virtual ~ZC_OPEN_BUYING_STORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091201 || \
	PACKET_VERSION >= 0
	ID_ZC_BROADCASTING_SPECIAL_ITEM_OBTAIN = 0x07fd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BROADCASTING_SPECIAL_ITEM_OBTAIN
 *
 */ 
class ZC_BROADCASTING_SPECIAL_ITEM_OBTAIN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BROADCASTING_SPECIAL_ITEM_OBTAIN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BROADCASTING_SPECIAL_ITEM_OBTAIN, s)
	{}
	virtual ~ZC_BROADCASTING_SPECIAL_ITEM_OBTAIN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20071127 || \
	PACKET_VERSION >= 0
	ID_ZC_MAPPROPERTY = 0x02e7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MAPPROPERTY
 *
 */ 
class ZC_MAPPROPERTY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAPPROPERTY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAPPROPERTY, s)
	{}
	virtual ~ZC_MAPPROPERTY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20031117 || \
	PACKET_VERSION >= 20031103 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_MEMBER_TO_GROUP2 = 0x01e9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_MEMBER_TO_GROUP2
 *
 */ 
class ZC_ADD_MEMBER_TO_GROUP2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_MEMBER_TO_GROUP2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_MEMBER_TO_GROUP2, s)
	{}
	virtual ~ZC_ADD_MEMBER_TO_GROUP2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20071002 || \
	PACKET_VERSION >= 0
	ID_ZC_BATTLEFIELD_NOTIFY_HP = 0x02e0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BATTLEFIELD_NOTIFY_HP
 *
 */ 
class ZC_BATTLEFIELD_NOTIFY_HP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BATTLEFIELD_NOTIFY_HP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BATTLEFIELD_NOTIFY_HP, s)
	{}
	virtual ~ZC_BATTLEFIELD_NOTIFY_HP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140611 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_GENERATE_ROULETTE = 0x0a20
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_GENERATE_ROULETTE
 *
 */ 
class ZC_ACK_GENERATE_ROULETTE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_GENERATE_ROULETTE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_GENERATE_ROULETTE, s)
	{}
	virtual ~ZC_ACK_GENERATE_ROULETTE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070711 || \
	PACKET_VERSION >= 20070423 || \
	PACKET_VERSION >= 20070227 || \
	PACKET_VERSION >= 20070102 || \
	PACKET_VERSION >= 20061204 || \
	PACKET_VERSION >= 0
	ID_ZC_PC_CASH_POINT_UPDATE = 0x0289
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PC_CASH_POINT_UPDATE
 *
 */ 
class ZC_PC_CASH_POINT_UPDATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PC_CASH_POINT_UPDATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PC_CASH_POINT_UPDATE, s)
	{}
	virtual ~ZC_PC_CASH_POINT_UPDATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_USE_ITEM_ACK = 0x00a8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_USE_ITEM_ACK
 *
 */ 
class ZC_USE_ITEM_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_USE_ITEM_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_USE_ITEM_ACK, s)
	{}
	virtual ~ZC_USE_ITEM_ACK() {}

	void deliver(int16_t index, int16_t amount, bool success);
	ByteBuffer &serialize();

/* Structure */
	int16_t _index;
	int16_t _amount;
	int8_t _success;
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20041108 || \
	PACKET_VERSION >= 0
	ID_ZC_BLACKSMITH_RANK = 0x0219
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BLACKSMITH_RANK
 *
 */ 
class ZC_BLACKSMITH_RANK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BLACKSMITH_RANK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BLACKSMITH_RANK, s)
	{}
	virtual ~ZC_BLACKSMITH_RANK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140312 || \
	PACKET_VERSION >= 20140305 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_ITEM_TO_STORE3 = 0x0a0a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_ITEM_TO_STORE3
 *
 */ 
class ZC_ADD_ITEM_TO_STORE3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_ITEM_TO_STORE3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_ITEM_TO_STORE3, s)
	{}
	virtual ~ZC_ADD_ITEM_TO_STORE3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050718 || \
	PACKET_VERSION >= 0
	ID_ZC_MAIL_REQ_SEND = 0x0249
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MAIL_REQ_SEND
 *
 */ 
class ZC_MAIL_REQ_SEND : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAIL_REQ_SEND(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAIL_REQ_SEND, s)
	{}
	virtual ~ZC_MAIL_REQ_SEND() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_REFUSE_QUIT = 0x0084
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REFUSE_QUIT
 *
 */ 
class ZC_REFUSE_QUIT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REFUSE_QUIT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REFUSE_QUIT, s)
	{}
	virtual ~ZC_REFUSE_QUIT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050801 || \
	PACKET_VERSION >= 20050718 || \
	PACKET_VERSION >= 0
	ID_ZC_MAIL_REQ_GET_ITEM = 0x0245
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MAIL_REQ_GET_ITEM
 *
 */ 
class ZC_MAIL_REQ_GET_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAIL_REQ_GET_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAIL_REQ_GET_ITEM, s)
	{}
	virtual ~ZC_MAIL_REQ_GET_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20130605 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_COUNT_BARGAIN_SALE_ITEM = 0x09c4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_COUNT_BARGAIN_SALE_ITEM
 *
 */ 
class ZC_ACK_COUNT_BARGAIN_SALE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_COUNT_BARGAIN_SALE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_COUNT_BARGAIN_SALE_ITEM, s)
	{}
	virtual ~ZC_ACK_COUNT_BARGAIN_SALE_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100608 || \
	PACKET_VERSION >= 0
	ID_ZC_SSILIST_ITEM_CLICK_ACK = 0x083d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SSILIST_ITEM_CLICK_ACK
 *
 */ 
class ZC_SSILIST_ITEM_CLICK_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SSILIST_ITEM_CLICK_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SSILIST_ITEM_CLICK_ACK, s)
	{}
	virtual ~ZC_SSILIST_ITEM_CLICK_ACK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090818 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEMLISTWIN_OPEN = 0x07e3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEMLISTWIN_OPEN
 *
 */ 
class ZC_ITEMLISTWIN_OPEN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEMLISTWIN_OPEN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEMLISTWIN_OPEN, s)
	{}
	virtual ~ZC_ITEMLISTWIN_OPEN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20161130 || \
	PACKET_VERSION >= 0
	ID_ZC_INVENTORY_MOVE_FAILED = 0x0aa7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_INVENTORY_MOVE_FAILED
 *
 */ 
class ZC_INVENTORY_MOVE_FAILED : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_INVENTORY_MOVE_FAILED(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_INVENTORY_MOVE_FAILED, s)
	{}
	virtual ~ZC_INVENTORY_MOVE_FAILED() {}

	void deliver(int16_t index, int16_t silent);
	ByteBuffer &serialize();

/* Structure */
	int16_t _index;
	int16_t _silent;
};

enum {
#if PACKET_VERSION >= 20100420 || \
	PACKET_VERSION >= 20100303 || \
	PACKET_VERSION >= 0
	ID_ZC_FAILED_OPEN_BUYING_STORE_TO_BUYER = 0x0812
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FAILED_OPEN_BUYING_STORE_TO_BUYER
 *
 */ 
class ZC_FAILED_OPEN_BUYING_STORE_TO_BUYER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FAILED_OPEN_BUYING_STORE_TO_BUYER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FAILED_OPEN_BUYING_STORE_TO_BUYER, s)
	{}
	virtual ~ZC_FAILED_OPEN_BUYING_STORE_TO_BUYER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050829 || \
	PACKET_VERSION >= 20050718 || \
	PACKET_VERSION >= 0
	ID_ZC_MAIL_REQ_GET_LIST = 0x0240
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MAIL_REQ_GET_LIST
 *
 */ 
class ZC_MAIL_REQ_GET_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAIL_REQ_GET_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAIL_REQ_GET_LIST, s)
	{}
	virtual ~ZC_MAIL_REQ_GET_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110125 || \
	PACKET_VERSION >= 0
	ID_ZC_TRYCOLLECTION = 0x08b6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_TRYCOLLECTION
 *
 */ 
class ZC_TRYCOLLECTION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_TRYCOLLECTION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_TRYCOLLECTION, s)
	{}
	virtual ~ZC_TRYCOLLECTION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090603 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_GROUPINFO_CHANGE_V2 = 0x07d8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_GROUPINFO_CHANGE_V2
 *
 */ 
class ZC_REQ_GROUPINFO_CHANGE_V2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_GROUPINFO_CHANGE_V2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_GROUPINFO_CHANGE_V2, s)
	{}
	virtual ~ZC_REQ_GROUPINFO_CHANGE_V2() {}

	void deliver(int exp_share_rule, int8_t item_pick_rule, int8_t item_share_rule);
	ByteBuffer &serialize();

/* Structure */
	int _exp_share_rule{ 0 };
	int8_t _item_pick_rule{ 0 };
	int8_t _item_share_rule{ 0 };
};

enum {
#if PACKET_VERSION >= 20170920 || \
	PACKET_VERSION >= 0
	ID_ZC_OVERWEIGHT_PERCENT = 0x0ade
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OVERWEIGHT_PERCENT
 *
 */ 
class ZC_OVERWEIGHT_PERCENT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OVERWEIGHT_PERCENT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OVERWEIGHT_PERCENT, s)
	{}
	virtual ~ZC_OVERWEIGHT_PERCENT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20131230 || \
	PACKET_VERSION >= 0
	ID_ZC_PROPERTY_HOMUN_2 = 0x09f7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PROPERTY_HOMUN_2
 *
 */ 
class ZC_PROPERTY_HOMUN_2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PROPERTY_HOMUN_2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PROPERTY_HOMUN_2, s)
	{}
	virtual ~ZC_PROPERTY_HOMUN_2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050829 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_MAIL_ADD_ITEM = 0x0255
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_MAIL_ADD_ITEM
 *
 */ 
class ZC_ACK_MAIL_ADD_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_MAIL_ADD_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_MAIL_ADD_ITEM, s)
	{}
	virtual ~ZC_ACK_MAIL_ADD_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20160706 || \
	PACKET_VERSION >= 20160615 || \
	PACKET_VERSION >= 0
	ID_ZC_OFFLINE_STORE_OWNER_ITEMS_READY = 0x0a7e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OFFLINE_STORE_OWNER_ITEMS_READY
 *
 */ 
class ZC_OFFLINE_STORE_OWNER_ITEMS_READY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OFFLINE_STORE_OWNER_ITEMS_READY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OFFLINE_STORE_OWNER_ITEMS_READY, s)
	{}
	virtual ~ZC_OFFLINE_STORE_OWNER_ITEMS_READY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_STATUS_CHANGE_ACK = 0x00bc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STATUS_CHANGE_ACK
 *
 */ 
class ZC_STATUS_CHANGE_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STATUS_CHANGE_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STATUS_CHANGE_ACK, s)
	{}
	virtual ~ZC_STATUS_CHANGE_ACK() {}

	void deliver(status_point_type type, int8_t value, bool success);
	ByteBuffer &serialize();

/* Structure */
	int16_t _type{0};
	int8_t _success{0};
	int8_t _amount{0};
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050608 || \
	PACKET_VERSION >= 0
	ID_ZC_RESULT_STORE_PASSWORD = 0x023c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_RESULT_STORE_PASSWORD
 *
 */ 
class ZC_RESULT_STORE_PASSWORD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_RESULT_STORE_PASSWORD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_RESULT_STORE_PASSWORD, s)
	{}
	virtual ~ZC_RESULT_STORE_PASSWORD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACCEPT_ENTER = 0x0073
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACCEPT_ENTER
 *
 */ 
class ZC_ACCEPT_ENTER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACCEPT_ENTER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACCEPT_ENTER, s)
	{}
	virtual ~ZC_ACCEPT_ENTER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20181024 || \
	PACKET_VERSION >= 20181017 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_PREVIEW = 0x0b13
#elif PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20170111 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_PREVIEW = 0x0ab9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_PREVIEW
 *
 */ 
class ZC_ITEM_PREVIEW : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_PREVIEW(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_PREVIEW, s)
	{}
	virtual ~ZC_ITEM_PREVIEW() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20151118 || \
	PACKET_VERSION >= 0
	ID_ZC_AIRSHIP_MAPMOVE = 0x0a4b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_AIRSHIP_MAPMOVE
 *
 */ 
class ZC_AIRSHIP_MAPMOVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_AIRSHIP_MAPMOVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_AIRSHIP_MAPMOVE, s)
	{}
	virtual ~ZC_AIRSHIP_MAPMOVE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SPRITE_CHANGE2 = 0x01d7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SPRITE_CHANGE2
 *
 */ 
class ZC_SPRITE_CHANGE2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SPRITE_CHANGE2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SPRITE_CHANGE2, s)
	{}
	virtual ~ZC_SPRITE_CHANGE2() {}

	void deliver(int32_t guid, entity_appearance_type look_type, int32_t value, int32_t value2);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid{0};
	int8_t _look_type{0};

#if ((CLIENT_TYPE == 'M' && PACKET_VERSION >= 20181121) \
	|| (CLIENT_TYPE == 'R' && PACKET_VERSION >= 20180704) \
	|| (CLIENT_TYPE == 'Z' && PACKET_VERSION >= 20181114))
	int32_t _value{0};
	int32_t _value2{0};
#else
	int16_t _value{0};
	int16_t _value2{0};
#endif
};

enum {
#if PACKET_VERSION >= 20140122 || \
	PACKET_VERSION >= 20140115 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_QUEST_EX = 0x09f9
#elif PACKET_VERSION >= 20180829 || \
	PACKET_VERSION >= 20180822 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_QUEST_EX = 0x0b0c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_QUEST_EX
 *
 */ 
class ZC_ADD_QUEST_EX : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_QUEST_EX(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_QUEST_EX, s)
	{}
	virtual ~ZC_ADD_QUEST_EX() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20090520
	ID_ZC_ES_READY = 0x07d5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ES_READY
 *
 */ 
class ZC_ES_READY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ES_READY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ES_READY, s)
	{}
	virtual ~ZC_ES_READY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050718 || \
	PACKET_VERSION >= 0
	ID_ZC_MAIL_RECEIVE = 0x024a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MAIL_RECEIVE
 *
 */ 
class ZC_MAIL_RECEIVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAIL_RECEIVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAIL_RECEIVE, s)
	{}
	virtual ~ZC_MAIL_RECEIVE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20171206 || \
	PACKET_VERSION >= 20171130 || \
	PACKET_VERSION >= 0
	ID_ZC_GROUP_LIST = 0x0ae5
#elif PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_GROUP_LIST = 0x00fb
#elif PACKET_VERSION == 20151007
	ID_ZC_GROUP_LIST = 0x0a44
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GROUP_LIST
 *
 */ 
class ZC_GROUP_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
	struct s_members {
		int32_t account_id{ 0 };
#if PACKET_VERSION >= 20171207
		int32_t char_id{ 0 };
#endif
		char player_name[MAX_UNIT_NAME_LENGTH];
		char map_name[MAP_NAME_LENGTH_EXT];
		uint8_t leader;
		uint8_t offline;
#if (CLIENT_TYPE == 'M' && PACKET_VERSION >= 20170524) || \
	(CLIENT_TYPE == 'R' && PACKET_VERSION >= 20170502) || \
	(CLIENT_TYPE == 'Z')
		int16_t class_;
		int16_t base_level;
#endif
	};
public:
	ZC_GROUP_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GROUP_LIST, s)
	{}
	virtual ~ZC_GROUP_LIST() {}

	void deliver(std::string party_name, std::vector<s_members> );
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_len{ 0 };
	char _party_name[MAX_PARTY_NAME_LENGTH];
	std::vector<s_members> _members;
};

enum {
#if PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 0
	ID_ZC_MILLENNIUMSHIELD = 0x0440
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MILLENNIUMSHIELD
 *
 */ 
class ZC_MILLENNIUMSHIELD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MILLENNIUMSHIELD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MILLENNIUMSHIELD, s)
	{}
	virtual ~ZC_MILLENNIUMSHIELD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20170215 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_MEMBER_JOB_LEVEL = 0x0abd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_MEMBER_JOB_LEVEL
 *
 */ 
class ZC_PARTY_MEMBER_JOB_LEVEL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_MEMBER_JOB_LEVEL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_MEMBER_JOB_LEVEL, s)
	{}
	virtual ~ZC_PARTY_MEMBER_JOB_LEVEL() {}

	void deliver(int account_id, int job_id, int level);
	ByteBuffer &serialize();

/* Structure */
	int _account_id{ 0 };
	int16_t _job_id{ 0 };
	int16_t _level{ 0 };
};

enum {
#if PACKET_VERSION >= 20160629 || \
	PACKET_VERSION >= 0
	ID_ZC_OFFLINE_STORE_OWNER_ITEMS = 0x0a8d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OFFLINE_STORE_OWNER_ITEMS
 *
 */ 
class ZC_OFFLINE_STORE_OWNER_ITEMS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OFFLINE_STORE_OWNER_ITEMS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OFFLINE_STORE_OWNER_ITEMS, s)
	{}
	virtual ~ZC_OFFLINE_STORE_OWNER_ITEMS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120716 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_CLAN_CHAT = 0x098e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_CLAN_CHAT
 *
 */ 
class ZC_NOTIFY_CLAN_CHAT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_CLAN_CHAT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_CLAN_CHAT, s)
	{}
	virtual ~ZC_NOTIFY_CLAN_CHAT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20180912 || \
	PACKET_VERSION >= 0
	ID_ZC_NPC_BARTER_OPEN = 0x0b0e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NPC_BARTER_OPEN
 *
 */ 
class ZC_NPC_BARTER_OPEN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NPC_BARTER_OPEN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NPC_BARTER_OPEN, s)
	{}
	virtual ~ZC_NPC_BARTER_OPEN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_START_COUPLE = 0x01e4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_START_COUPLE
 *
 */ 
class ZC_START_COUPLE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_START_COUPLE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_START_COUPLE, s)
	{}
	virtual ~ZC_START_COUPLE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20040420 || \
	PACKET_VERSION >= 0
	ID_ZC_REPAIRITEMLIST = 0x01fc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REPAIRITEMLIST
 *
 */ 
class ZC_REPAIRITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REPAIRITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REPAIRITEMLIST, s)
	{}
	virtual ~ZC_REPAIRITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091117 || \
	PACKET_VERSION >= 0
	ID_ZC_DELETE_ITEM_FROM_BODY = 0x07fa
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DELETE_ITEM_FROM_BODY
 *
 */ 
class ZC_DELETE_ITEM_FROM_BODY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DELETE_ITEM_FROM_BODY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DELETE_ITEM_FROM_BODY, s)
	{}
	virtual ~ZC_DELETE_ITEM_FROM_BODY() {}

	void deliver(int16_t index, int16_t amount, item_deletion_reason_type reason);
	ByteBuffer &serialize();

/* Structure */
	item_deletion_reason_type _reason;
	int16_t _index;
	int16_t _amount;
};

enum {
#if PACKET_VERSION >= 20100309 || \
	PACKET_VERSION >= 20100303 || \
	PACKET_VERSION >= 0
	ID_ZC_MYITEMLIST_BUYING_STORE = 0x0813
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MYITEMLIST_BUYING_STORE
 *
 */ 
class ZC_MYITEMLIST_BUYING_STORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MYITEMLIST_BUYING_STORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MYITEMLIST_BUYING_STORE, s)
	{}
	virtual ~ZC_MYITEMLIST_BUYING_STORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20070807
	ID_ZC_SRPACKETR2_INIT = 0x02bf
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SRPACKETR2_INIT
 *
 */ 
class ZC_SRPACKETR2_INIT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SRPACKETR2_INIT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SRPACKETR2_INIT, s)
	{}
	virtual ~ZC_SRPACKETR2_INIT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MOVEENTRY4 = 0x02ec
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MOVEENTRY4
 *
 */ 
class ZC_NOTIFY_MOVEENTRY4 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MOVEENTRY4(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MOVEENTRY4, s)
	{}
	virtual ~ZC_NOTIFY_MOVEENTRY4() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070918 || \
	PACKET_VERSION >= 0
	ID_ZC_CONFIG_NOTIFY = 0x02da
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CONFIG_NOTIFY
 *
 */ 
class ZC_CONFIG_NOTIFY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CONFIG_NOTIFY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CONFIG_NOTIFY, s)
	{}
	virtual ~ZC_CONFIG_NOTIFY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_PETEGG_LIST = 0x01a6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PETEGG_LIST
 *
 */ 
class ZC_PETEGG_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PETEGG_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PETEGG_LIST, s)
	{}
	virtual ~ZC_PETEGG_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20071127 || \
	PACKET_VERSION >= 20071106 || \
	PACKET_VERSION >= 20070102 || \
	PACKET_VERSION >= 20050411 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MOVEENTRY3 = 0x022c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MOVEENTRY3
 *
 */ 
class ZC_NOTIFY_MOVEENTRY3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MOVEENTRY3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MOVEENTRY3, s)
	{}
	virtual ~ZC_NOTIFY_MOVEENTRY3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MOVEENTRY2 = 0x01da
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MOVEENTRY2
 *
 */ 
class ZC_NOTIFY_MOVEENTRY2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MOVEENTRY2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MOVEENTRY2, s)
	{}
	virtual ~ZC_NOTIFY_MOVEENTRY2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120131 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MOVEENTRY9 = 0x0914
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MOVEENTRY9
 *
 */ 
class ZC_NOTIFY_MOVEENTRY9 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MOVEENTRY9(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MOVEENTRY9, s)
	{}
	virtual ~ZC_NOTIFY_MOVEENTRY9() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20101123 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MOVEENTRY8 = 0x0856
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MOVEENTRY8
 *
 */ 
class ZC_NOTIFY_MOVEENTRY8 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MOVEENTRY8(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MOVEENTRY8, s)
	{}
	virtual ~ZC_NOTIFY_MOVEENTRY8() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100824 || \
	PACKET_VERSION >= 0
	ID_ZC_SE_CASHSHOP_OPEN = 0x0845
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SE_CASHSHOP_OPEN
 *
 */ 
class ZC_SE_CASHSHOP_OPEN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SE_CASHSHOP_OPEN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SE_CASHSHOP_OPEN, s)
	{}
	virtual ~ZC_SE_CASHSHOP_OPEN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120716 || \
	PACKET_VERSION >= 20120702 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_CLAN_CONNECTINFO = 0x0988
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_CLAN_CONNECTINFO
 *
 */ 
class ZC_NOTIFY_CLAN_CONNECTINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_CLAN_CONNECTINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_CLAN_CONNECTINFO, s)
	{}
	virtual ~ZC_NOTIFY_CLAN_CONNECTINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140122 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MOVEENTRY11 = 0x09fd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MOVEENTRY11
 *
 */ 
class ZC_NOTIFY_MOVEENTRY11 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MOVEENTRY11(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MOVEENTRY11, s)
	{}
	virtual ~ZC_NOTIFY_MOVEENTRY11() {}

	void deliver(entity_viewport_entry entry);
	ByteBuffer &serialize();

/* Structure */
	entity_viewport_entry _entry;
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ATTACK_RANGE = 0x013a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ATTACK_RANGE
 *
 */ 
class ZC_ATTACK_RANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ATTACK_RANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ATTACK_RANGE, s)
	{}
	virtual ~ZC_ATTACK_RANGE() {}

	void deliver(int16_t range);
	ByteBuffer &serialize();

/* Structure */
	int16_t _range;
};

enum {
#if PACKET_VERSION >= 20130911 || \
	PACKET_VERSION >= 0
	ID_ZC_NPC_MARKET_PURCHASE_RESULT = 0x09d7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NPC_MARKET_PURCHASE_RESULT
 *
 */ 
class ZC_NPC_MARKET_PURCHASE_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NPC_MARKET_PURCHASE_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NPC_MARKET_PURCHASE_RESULT, s)
	{}
	virtual ~ZC_NPC_MARKET_PURCHASE_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MAPINFO = 0x0189
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MAPINFO
 *
 */ 
class ZC_NOTIFY_MAPINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MAPINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MAPINFO, s)
	{}
	virtual ~ZC_NOTIFY_MAPINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MVP = 0x010c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MVP
 *
 */ 
class ZC_MVP : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MVP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MVP, s)
	{}
	virtual ~ZC_MVP() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_DESTROY_ROOM = 0x00d8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DESTROY_ROOM
 *
 */ 
class ZC_DESTROY_ROOM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DESTROY_ROOM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DESTROY_ROOM, s)
	{}
	virtual ~ZC_DESTROY_ROOM() {}

	void deliver(int chat_id);
	ByteBuffer &serialize();

/* Structure */
	int _chat_id{ 0 };
};

enum {
#if PACKET_VERSION >= 20040308 || \
	PACKET_VERSION >= 0
	ID_ZC_REQ_BABY = 0x01f6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_BABY
 *
 */ 
class ZC_REQ_BABY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_BABY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_BABY, s)
	{}
	virtual ~ZC_REQ_BABY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ADD_EXCHANGE_ITEM = 0x00ea
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ADD_EXCHANGE_ITEM
 *
 */ 
class ZC_ACK_ADD_EXCHANGE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
	enum zcack_addexchangeitem_result_type
	{
		ZCACK_ADDEXCHANGEITEM_RESULT_SUCCESS = 0,
		ZCACK_ADDEXCHANGEITEM_RESULT_OVERWEIGHT = 1,
		ZCACK_ADDEXCHANGEITEM_RESULT_TRADE_CANCELLED = 2,
		ZCACK_ADDEXCHANGEITEM_RESULT_AMOUNT_EXCEEDED = 3,
		ZCACK_ADDEXCHANGEITEM_RESULT_AMOUNT_EXCEEDED2 = 4
	};
public:
	ZC_ACK_ADD_EXCHANGE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ADD_EXCHANGE_ITEM, s)
	{}
	virtual ~ZC_ACK_ADD_EXCHANGE_ITEM() {}

	void deliver(int inventory_index, zc_ack_exchange_item_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int16_t _inventory_index{ 0 };
	int8_t _result{ 0 };
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111025 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_ACK_REGISTER = 0x08e6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_ACK_REGISTER
 *
 */ 
class ZC_PARTY_RECRUIT_ACK_REGISTER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_ACK_REGISTER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_ACK_REGISTER, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_ACK_REGISTER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACTION_FAILURE = 0x013b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACTION_FAILURE
 *
 */ 
class ZC_ACTION_FAILURE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACTION_FAILURE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACTION_FAILURE, s)
	{}
	virtual ~ZC_ACTION_FAILURE() {}

	void deliver(int16_t message_type);
	ByteBuffer &serialize();

/* Structure */
	/// type:
	///     0 = MsgStringTable[242]="Please equip the proper ammunition first."
	///     1 = MsgStringTable[243]="You can't Attack or use Skills because your Weight Limit has been exceeded."
	///     2 = MsgStringTable[244]="You can't use Skills because Weight Limit has been exceeded."
	///     3 = assassin, baby_assassin, assassin_cross => MsgStringTable[1040]="You have equipped throwing daggers."
	///         gunslinger => MsgStringTable[1175]="Bullets have been equipped."
	///         NOT ninja => MsgStringTable[245]="Ammunition has been equipped."
	int16_t _message_type{0};
};

enum {
#if PACKET_VERSION >= 20120228 || \
	PACKET_VERSION >= 20120221 || \
	PACKET_VERSION >= 0
	ID_ZC_HP_INFO = 0x0977
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HP_INFO
 *
 */ 
class ZC_HP_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HP_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HP_INFO, s)
	{}
	virtual ~ZC_HP_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACK_GUILD_MEMBER_INFO = 0x0176
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_GUILD_MEMBER_INFO
 *
 */ 
class ZC_ACK_GUILD_MEMBER_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_GUILD_MEMBER_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_GUILD_MEMBER_INFO, s)
	{}
	virtual ~ZC_ACK_GUILD_MEMBER_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20040302 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_EXCHANGE_ITEM2 = 0x01f5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_EXCHANGE_ITEM2
 *
 */ 
class ZC_ACK_EXCHANGE_ITEM2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_EXCHANGE_ITEM2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_EXCHANGE_ITEM2, s)
	{}
	virtual ~ZC_ACK_EXCHANGE_ITEM2() {}

	void deliver(zc_ack_exchange_item_result_type type, int char_id, int base_level);
	ByteBuffer &serialize();

/* Structure */
	int8_t _result{ 0 };
	int _char_id{ 0 };
	int16_t _base_level{ 0 };
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20140618 || \
	PACKET_VERSION >= 20140611 || \
	PACKET_VERSION >= 0
	ID_ZC_RECV_ROULETTE_ITEM = 0x0a22
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_RECV_ROULETTE_ITEM
 *
 */ 
class ZC_RECV_ROULETTE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_RECV_ROULETTE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_RECV_ROULETTE_ITEM, s)
	{}
	virtual ~ZC_RECV_ROULETTE_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_EXCHANGE_ITEM = 0x00e9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_EXCHANGE_ITEM
 * Notifies the client about an item from other player in current trade.
 */ 
class ZC_ADD_EXCHANGE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	struct s_zc_add_exchange_item {
		/* Structure */
#if (CLIENT_TYPE == 'M' && PACKET_VERSION >= 20181121) || \
	(CLIENT_TYPE == 'R' && PACKET_VERSION >= 20180704) || \
	(CLIENT_TYPE == 'Z' && PACKET_VERSION >= 20181114)
		uint32_t item_id;
		uint8_t item_type;
		int32_t amount;
#else
		uint16_t item_id;
		uint8_t item_type;
		int32_t amount;
#endif
		uint8_t identified;
		uint8_t damaged;
#if !((CLIENT_TYPE == 'M' && PACKET_VERSION >= 20200916) || \
	(CLIENT_TYPE == 'R' && PACKET_VERSION >= 20200723) || \
	(CLIENT_TYPE == 'Z' && PACKET_VERSION >= 20221024))
		uint8_t refine;
#endif  // !(PACKETVER_MAIN_NUM >= 20200916 || PACKETVER_RE_NUM >= 20200723 || PACKETVER_ZERO_NUM >= 20221024)
		item_slot cards;
#if PACKET_VERSION >= 20150226
		struct {
			int16_t index{ 0 };
			int16_t value{ 0 };
			int16_t param{ 0 };
		} option_data[MAX_ITEM_OPTIONS];
#endif
#if (CLIENT_TYPE == 'M' && PACKET_VERSION >= 20161102) || \
	(CLIENT_TYPE == 'R' && PACKET_VERSION >= 20161026) || \
	(CILENT_TYPE == 'Z')
		uint32_t location;
		uint16_t look;
#endif  // PACKETVER_MAIN_NUM >= 20161102 || PACKETVER_RE_NUM >= 20161026 || defined(PACKETVER_ZERO)
#if (CLIENT_TYPE == 'M' && PACKET_VERSION >= 20200916) || \
	(CLIENT_TYPE == 'R' && PACKET_VERSION >= 20200723) || \
	(CLIENT_TYPE == 'Z' && PACKET_VERSION >= 20221024)
		uint8_t refine;
		uint8_t grade;
#endif  // PACKETVER_MAIN_NUM >= 20200916 || PACKETVER_RE_NUM >= 20200723 || PACKETVER_ZERO_NUM >= 20221024

	};

	ZC_ADD_EXCHANGE_ITEM(std::shared_ptr<ZoneSession> s)
		: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_EXCHANGE_ITEM, s)
	{}
	virtual ~ZC_ADD_EXCHANGE_ITEM() {}

	void deliver(s_zc_add_exchange_item item);
	ByteBuffer& serialize();
	
	s_zc_add_exchange_item _item;
};

enum {
#if PACKET_VERSION >= 20130417 || \
	PACKET_VERSION >= 0
	ID_ZC_OPEN_BARGAIN_SALE_TOOL = 0x09b5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OPEN_BARGAIN_SALE_TOOL
 *
 */ 
class ZC_OPEN_BARGAIN_SALE_TOOL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OPEN_BARGAIN_SALE_TOOL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OPEN_BARGAIN_SALE_TOOL, s)
	{}
	virtual ~ZC_OPEN_BARGAIN_SALE_TOOL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070828 || \
	PACKET_VERSION >= 0
	ID_ZC_MEMORIALDUNGEON_NOTIFY = 0x02ce
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MEMORIALDUNGEON_NOTIFY
 *
 */ 
class ZC_MEMORIALDUNGEON_NOTIFY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MEMORIALDUNGEON_NOTIFY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MEMORIALDUNGEON_NOTIFY, s)
	{}
	virtual ~ZC_MEMORIALDUNGEON_NOTIFY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111227 || \
	PACKET_VERSION >= 0
	ID_ZC_ENTRY_QUEUE_INIT = 0x090e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ENTRY_QUEUE_INIT
 *
 */ 
class ZC_ENTRY_QUEUE_INIT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ENTRY_QUEUE_INIT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ENTRY_QUEUE_INIT, s)
	{}
	virtual ~ZC_ENTRY_QUEUE_INIT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111004 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ENTRY_QUEUE_CANCEL = 0x08db
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ENTRY_QUEUE_CANCEL
 *
 */ 
class ZC_ACK_ENTRY_QUEUE_CANCEL : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ENTRY_QUEUE_CANCEL(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ENTRY_QUEUE_CANCEL, s)
	{}
	virtual ~ZC_ACK_ENTRY_QUEUE_CANCEL() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ROLE_CHANGE = 0x00e1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ROLE_CHANGE
 *
 */ 
class ZC_ROLE_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ROLE_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ROLE_CHANGE, s)
	{}
	virtual ~ZC_ROLE_CHANGE() {}

	void deliver(int role, std::string name);
	ByteBuffer &serialize();

/* Structure */
	int32_t _role;
	char _name[MAX_UNIT_NAME_LENGTH];
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20041108 || \
	PACKET_VERSION >= 0
	ID_ZC_ALCHEMIST_RANK = 0x021a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALCHEMIST_RANK
 *
 */ 
class ZC_ALCHEMIST_RANK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALCHEMIST_RANK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALCHEMIST_RANK, s)
	{}
	virtual ~ZC_ALCHEMIST_RANK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110614 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_SCHEDULER_CASHITEM = 0x08ca
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_SCHEDULER_CASHITEM
 *
 */ 
class ZC_ACK_SCHEDULER_CASHITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_SCHEDULER_CASHITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_SCHEDULER_CASHITEM, s)
	{}
	virtual ~ZC_ACK_SCHEDULER_CASHITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120604 || \
	PACKET_VERSION >= 20120601 || \
	PACKET_VERSION >= 0
	ID_ZC_SKILL_POSTDELAY_LIST2 = 0x0985
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SKILL_POSTDELAY_LIST2
 *
 */ 
class ZC_SKILL_POSTDELAY_LIST2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SKILL_POSTDELAY_LIST2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SKILL_POSTDELAY_LIST2, s)
	{}
	virtual ~ZC_SKILL_POSTDELAY_LIST2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050404 || \
	PACKET_VERSION >= 0
	ID_ZC_GAME_GUARD = 0x0227
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GAME_GUARD
 *
 */ 
class ZC_GAME_GUARD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GAME_GUARD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GAME_GUARD, s)
	{}
	virtual ~ZC_GAME_GUARD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NORMAL_ITEMLIST = 0x00a3
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NORMAL_ITEMLIST
 *
 */ 
class ZC_NORMAL_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NORMAL_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NORMAL_ITEMLIST, s)
	{}
	virtual ~ZC_NORMAL_ITEMLIST() {}

	void deliver(std::vector<item_entry_data> &items);
	ByteBuffer &serialize();

/* Structure */
	std::vector<item_entry_data> _items;
};

enum {
#if PACKET_VERSION >= 20140521 || \
	PACKET_VERSION >= 20140423
	ID_ZC_CHECK_RECEIVE_CHARACTER_NAME = 0x0a14
#elif PACKET_VERSION >= 20160302 || \
	PACKET_VERSION >= 0
	ID_ZC_CHECK_RECEIVE_CHARACTER_NAME = 0x0a51
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CHECK_RECEIVE_CHARACTER_NAME
 *
 */ 
class ZC_CHECK_RECEIVE_CHARACTER_NAME : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CHECK_RECEIVE_CHARACTER_NAME(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CHECK_RECEIVE_CHARACTER_NAME, s)
	{}
	virtual ~ZC_CHECK_RECEIVE_CHARACTER_NAME() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20061226 || \
	PACKET_VERSION >= 0
	ID_ZC_MER_SKILLINFO_LIST = 0x029d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MER_SKILLINFO_LIST
 *
 */ 
class ZC_MER_SKILLINFO_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MER_SKILLINFO_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MER_SKILLINFO_LIST, s)
	{}
	virtual ~ZC_MER_SKILLINFO_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20160706 || \
	PACKET_VERSION >= 20160629 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_OFFLINE_STORE = 0x0a89
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_OFFLINE_STORE
 *
 */ 
class ZC_NOTIFY_OFFLINE_STORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_OFFLINE_STORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_OFFLINE_STORE, s)
	{}
	virtual ~ZC_NOTIFY_OFFLINE_STORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120702 || \
	PACKET_VERSION >= 0
	ID_ZC_CLANINFO = 0x098a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CLANINFO
 *
 */ 
class ZC_CLANINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CLANINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CLANINFO, s)
	{}
	virtual ~ZC_CLANINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20070423 || \
	PACKET_VERSION >= 20070227 || \
	PACKET_VERSION >= 20061204 || \
	PACKET_VERSION >= 0
	ID_ZC_PC_CASH_POINT_ITEMLIST = 0x0287
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PC_CASH_POINT_ITEMLIST
 *
 */ 
class ZC_PC_CASH_POINT_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PC_CASH_POINT_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PC_CASH_POINT_ITEMLIST, s)
	{}
	virtual ~ZC_PC_CASH_POINT_ITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050411 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STANDENTRY3 = 0x022a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STANDENTRY3
 *
 */ 
class ZC_NOTIFY_STANDENTRY3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STANDENTRY3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STANDENTRY3, s)
	{}
	virtual ~ZC_NOTIFY_STANDENTRY3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STANDENTRY2 = 0x01d8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STANDENTRY2
 *
 */ 
class ZC_NOTIFY_STANDENTRY2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STANDENTRY2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STANDENTRY2, s)
	{}
	virtual ~ZC_NOTIFY_STANDENTRY2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130417 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_OPEN_BANKING = 0x09b7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_OPEN_BANKING
 *
 */ 
class ZC_ACK_OPEN_BANKING : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_OPEN_BANKING(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_OPEN_BANKING, s)
	{}
	virtual ~ZC_ACK_OPEN_BANKING() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20101123 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STANDENTRY7 = 0x0857
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STANDENTRY7
 *
 */ 
class ZC_NOTIFY_STANDENTRY7 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STANDENTRY7(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STANDENTRY7, s)
	{}
	virtual ~ZC_NOTIFY_STANDENTRY7() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091103 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STANDENTRY5 = 0x07f9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STANDENTRY5
 *
 */ 
class ZC_NOTIFY_STANDENTRY5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STANDENTRY5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STANDENTRY5, s)
	{}
	virtual ~ZC_NOTIFY_STANDENTRY5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STANDENTRY4 = 0x02ee
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STANDENTRY4
 *
 */ 
class ZC_NOTIFY_STANDENTRY4 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STANDENTRY4(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STANDENTRY4, s)
	{}
	virtual ~ZC_NOTIFY_STANDENTRY4() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120131 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STANDENTRY8 = 0x0915
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STANDENTRY8
 *
 */ 
class ZC_NOTIFY_STANDENTRY8 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STANDENTRY8(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STANDENTRY8, s)
	{}
	virtual ~ZC_NOTIFY_STANDENTRY8() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091201 || \
	PACKET_VERSION >= 0
	ID_ZC_PLAY_NPC_BGM = 0x07fe
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PLAY_NPC_BGM
 *
 */ 
class ZC_PLAY_NPC_BGM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PLAY_NPC_BGM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PLAY_NPC_BGM, s)
	{}
	virtual ~ZC_PLAY_NPC_BGM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20151118 || \
	PACKET_VERSION >= 0
	ID_ZC_PRIVATE_AIRSHIP_RESPONSE = 0x0a4a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PRIVATE_AIRSHIP_RESPONSE
 *
 */ 
class ZC_PRIVATE_AIRSHIP_RESPONSE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PRIVATE_AIRSHIP_RESPONSE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PRIVATE_AIRSHIP_RESPONSE, s)
	{}
	virtual ~ZC_PRIVATE_AIRSHIP_RESPONSE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110628 || \
	PACKET_VERSION >= 20110627 || \
	PACKET_VERSION >= 0
	ID_ZC_PERSONAL_INFOMATION = 0x08cb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PERSONAL_INFOMATION
 *
 */ 
class ZC_PERSONAL_INFOMATION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PERSONAL_INFOMATION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PERSONAL_INFOMATION, s)
	{}
	virtual ~ZC_PERSONAL_INFOMATION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_REQ_COUPLE = 0x01e2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REQ_COUPLE
 *
 */ 
class ZC_REQ_COUPLE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REQ_COUPLE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REQ_COUPLE, s)
	{}
	virtual ~ZC_REQ_COUPLE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_UPDATEPLAYER = 0x0077
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_UPDATEPLAYER
 *
 */ 
class ZC_NOTIFY_UPDATEPLAYER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_UPDATEPLAYER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_UPDATEPLAYER, s)
	{}
	virtual ~ZC_NOTIFY_UPDATEPLAYER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070611 || \
	PACKET_VERSION >= 0
	ID_ZC_SHORTCUT_KEY_LIST = 0x02b9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SHORTCUT_KEY_LIST
 *
 */ 
class ZC_SHORTCUT_KEY_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SHORTCUT_KEY_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SHORTCUT_KEY_LIST, s)
	{}
	virtual ~ZC_SHORTCUT_KEY_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120120 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_PARTY_NAME = 0x0911
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_PARTY_NAME
 *
 */ 
class ZC_ACK_PARTY_NAME : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_PARTY_NAME(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_PARTY_NAME, s)
	{}
	virtual ~ZC_ACK_PARTY_NAME() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_DEVOTIONLIST = 0x01cf
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DEVOTIONLIST
 *
 */ 
class ZC_DEVOTIONLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DEVOTIONLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DEVOTIONLIST, s)
	{}
	virtual ~ZC_DEVOTIONLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_PAR_CHANGE_USER = 0x01ab
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PAR_CHANGE_USER
 *
 */ 
class ZC_PAR_CHANGE_USER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PAR_CHANGE_USER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PAR_CHANGE_USER, s)
	{}
	virtual ~ZC_PAR_CHANGE_USER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20051010 || \
	PACKET_VERSION >= 0
	ID_ZC_MAKINGITEM_LIST = 0x025a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MAKINGITEM_LIST
 *
 */ 
class ZC_MAKINGITEM_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAKINGITEM_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAKINGITEM_LIST, s)
	{}
	virtual ~ZC_MAKINGITEM_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20180919 || \
	PACKET_VERSION >= 20180912 || \
	PACKET_VERSION >= 20180905 || \
	PACKET_VERSION >= 0
	ID_ZC_REMOVE_EFFECT = 0x0b0d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REMOVE_EFFECT
 *
 */ 
class ZC_REMOVE_EFFECT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REMOVE_EFFECT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REMOVE_EFFECT, s)
	{}
	virtual ~ZC_REMOVE_EFFECT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_GUILD_ZENY_ACK = 0x01b8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILD_ZENY_ACK
 *
 */ 
class ZC_GUILD_ZENY_ACK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILD_ZENY_ACK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILD_ZENY_ACK, s)
	{}
	virtual ~ZC_GUILD_ZENY_ACK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120925 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_ITEMLIST_EQUIP_V5 = 0x0996
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_ITEMLIST_EQUIP_V5
 *
 */ 
class ZC_STORE_ITEMLIST_EQUIP_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_ITEMLIST_EQUIP_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_ITEMLIST_EQUIP_V5, s)
	{}
	virtual ~ZC_STORE_ITEMLIST_EQUIP_V5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_SAY_DIALOG = 0x00b4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SAY_DIALOG
 *
 */ 
class ZC_SAY_DIALOG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SAY_DIALOG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SAY_DIALOG, s)
	{}
	virtual ~ZC_SAY_DIALOG() {}

	void deliver(int32_t npc_id, std::string &message);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{0};
	int32_t _guid{0};
	std::string _message{""};
};

enum {
#if PACKET_VERSION >= 20140115 || \
	PACKET_VERSION >= 20140108 || \
	PACKET_VERSION >= 20131230 || \
	PACKET_VERSION >= 20131223 || \
	PACKET_VERSION >= 20131218 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_READ_RODEX = 0x09eb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_READ_RODEX
 *
 */ 
class ZC_ACK_READ_RODEX : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_READ_RODEX(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_READ_RODEX, s)
	{}
	virtual ~ZC_ACK_READ_RODEX() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_GROUPINFO_CHANGE = 0x0101
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GROUPINFO_CHANGE
 *
 */ 
class ZC_GROUPINFO_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GROUPINFO_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GROUPINFO_CHANGE, s)
	{}
	virtual ~ZC_GROUPINFO_CHANGE() {}

	void deliver(int exp_share_rule);
	ByteBuffer &serialize();

/* Structure */
	int _exp_share_rule{ 0 };
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ADDITEM_TO_CART = 0x012c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ADDITEM_TO_CART
 *
 */ 
class ZC_ACK_ADDITEM_TO_CART : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ADDITEM_TO_CART(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ADDITEM_TO_CART, s)
	{}
	virtual ~ZC_ACK_ADDITEM_TO_CART() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120221 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_ITEMLIST_EQUIP_V2 = 0x0976
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_ITEMLIST_EQUIP_V2
 *
 */ 
class ZC_STORE_ITEMLIST_EQUIP_V2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_ITEMLIST_EQUIP_V2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_ITEMLIST_EQUIP_V2, s)
	{}
	virtual ~ZC_STORE_ITEMLIST_EQUIP_V2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACK_DISORGANIZE_GUILD = 0x015f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_DISORGANIZE_GUILD
 *
 */ 
class ZC_ACK_DISORGANIZE_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_DISORGANIZE_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_DISORGANIZE_GUILD, s)
	{}
	virtual ~ZC_ACK_DISORGANIZE_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100701 || \
	PACKET_VERSION >= 20100608 || \
	PACKET_VERSION >= 0
	ID_ZC_OPEN_SEARCH_STORE_INFO = 0x083a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_OPEN_SEARCH_STORE_INFO
 *
 */ 
class ZC_OPEN_SEARCH_STORE_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_OPEN_SEARCH_STORE_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_OPEN_SEARCH_STORE_INFO, s)
	{}
	virtual ~ZC_OPEN_SEARCH_STORE_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20031208 || \
	PACKET_VERSION >= 0
	ID_ZC_NORMAL_ITEMLIST2 = 0x01ee
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NORMAL_ITEMLIST2
 *
 */ 
class ZC_NORMAL_ITEMLIST2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NORMAL_ITEMLIST2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NORMAL_ITEMLIST2, s)
	{}
	virtual ~ZC_NORMAL_ITEMLIST2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_NORMAL_ITEMLIST3 = 0x02e8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NORMAL_ITEMLIST3
 *
 */ 
class ZC_NORMAL_ITEMLIST3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NORMAL_ITEMLIST3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NORMAL_ITEMLIST3, s)
	{}
	virtual ~ZC_NORMAL_ITEMLIST3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110131 || \
	PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 0
	ID_ZC_IRMAIL_NOTIFY = 0x02f5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_IRMAIL_NOTIFY
 *
 */ 
class ZC_IRMAIL_NOTIFY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_IRMAIL_NOTIFY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_IRMAIL_NOTIFY, s)
	{}
	virtual ~ZC_IRMAIL_NOTIFY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070807 || \
	PACKET_VERSION >= 20070622 || \
	PACKET_VERSION >= 0
	ID_ZC_ACTIVE_QUEST = 0x02b7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACTIVE_QUEST
 *
 */ 
class ZC_ACTIVE_QUEST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACTIVE_QUEST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACTIVE_QUEST, s)
	{}
	virtual ~ZC_ACTIVE_QUEST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110614 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_ACT3 = 0x08c8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_ACT3
 * 08c8 <src ID>.L <dst ID>.L <server tick>.L <src speed>.L <dst speed>.L <damage>.L <IsSPDamage>.B <div>.W <type>.B <damage2>.L (ZC_NOTIFY_ACT3)
 * type:
 *   0 = damage [ damage: total damage, div: amount of hits, damage2: assassin dual-wield damage ]
 *   1 = pick up item
 *   2 = sit down
 *   3 = stand up
 *   4 = damage (endure)
 *   5 = (splash?)
 *   6 = (skill?)
 *   7 = (repeat damage?)
 *   8 = multi-hit damage
 *   9 = multi-hit damage (endure)
 *   10 = critical hit
 *   11 = lucky dodge
 *   12 = (touch skill?)
 *   13 = multi-hit critical
 */ 
class ZC_NOTIFY_ACT3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_ACT3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_ACT3, s)
	{}
	virtual ~ZC_NOTIFY_ACT3() {}

	void deliver(int guid, int target_guid, int start_time, int delay_skill, int delay_damage, int damage, bool is_sp_damaged, int number_of_hits, int8_t action_type, int left_damage);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid{0};
	int32_t _target_guid{0};
	int32_t _start_time{0};
	int32_t _delay_skill{0};
	int32_t _delay_damage{0};
	int32_t _damage{0};
	int8_t _is_sp_damaged{0}; 
	int16_t _number_of_hits{0};
	uint8_t _action_type{0};
	int32_t _left_damage{0};
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_COUPLESTATUS = 0x0141
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_COUPLESTATUS
 *
 */ 
class ZC_COUPLESTATUS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_COUPLESTATUS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_COUPLESTATUS, s)
	{}
	virtual ~ZC_COUPLESTATUS() {}

	void deliver(int32_t type, int32_t base, int32_t bonus);
	ByteBuffer &serialize();

/* Structure */
	int32_t _type{0};
	int32_t _base{0};
	int32_t _bonus{0};
};

enum {
#if PACKET_VERSION >= 20140122 || \
	PACKET_VERSION >= 0
	ID_ZC_PET_EVOLUTION_RESULT = 0x09fc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PET_EVOLUTION_RESULT
 *
 */ 
class ZC_PET_EVOLUTION_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PET_EVOLUTION_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PET_EVOLUTION_RESULT, s)
	{}
	virtual ~ZC_PET_EVOLUTION_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20160330 || \
	PACKET_VERSION >= 0
	ID_ZC_FORMATSTRING_MSG_COLOR = 0x0a6f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FORMATSTRING_MSG_COLOR
 *
 */ 
class ZC_FORMATSTRING_MSG_COLOR : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FORMATSTRING_MSG_COLOR(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FORMATSTRING_MSG_COLOR, s)
	{}
	virtual ~ZC_FORMATSTRING_MSG_COLOR() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111207 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_ADD_FILTERLINGLIST = 0x090b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_ADD_FILTERLINGLIST
 *
 */ 
class ZC_PARTY_RECRUIT_ADD_FILTERLINGLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_ADD_FILTERLINGLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_ADD_FILTERLINGLIST, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_ADD_FILTERLINGLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120515 || \
	PACKET_VERSION >= 0
	ID_ZC_PERSONAL_INFOMATION_CHN = 0x0981
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PERSONAL_INFOMATION_CHN
 *
 */ 
class ZC_PERSONAL_INFOMATION_CHN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PERSONAL_INFOMATION_CHN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PERSONAL_INFOMATION_CHN, s)
	{}
	virtual ~ZC_PERSONAL_INFOMATION_CHN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20071002 || \
	PACKET_VERSION >= 0
	ID_ZC_BATTLEFIELD_NOTIFY_POINT = 0x02de
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BATTLEFIELD_NOTIFY_POINT
 *
 */ 
class ZC_BATTLEFIELD_NOTIFY_POINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BATTLEFIELD_NOTIFY_POINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BATTLEFIELD_NOTIFY_POINT, s)
	{}
	virtual ~ZC_BATTLEFIELD_NOTIFY_POINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100824 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_SE_CASH_ITEM_LIST = 0x0847
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_SE_CASH_ITEM_LIST
 *
 */ 
class ZC_ACK_SE_CASH_ITEM_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_SE_CASH_ITEM_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_SE_CASH_ITEM_LIST, s)
	{}
	virtual ~ZC_ACK_SE_CASH_ITEM_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_CHANGE_DIRECTION = 0x009c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CHANGE_DIRECTION
 *
 */ 
class ZC_CHANGE_DIRECTION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CHANGE_DIRECTION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CHANGE_DIRECTION, s)
	{}
	virtual ~ZC_CHANGE_DIRECTION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20111004 || \
	PACKET_VERSION >= 0
	ID_ZC_REPLY_ACK_LOBBY_ADMISSION = 0x08e1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_REPLY_ACK_LOBBY_ADMISSION
 *
 */ 
class ZC_REPLY_ACK_LOBBY_ADMISSION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_REPLY_ACK_LOBBY_ADMISSION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_REPLY_ACK_LOBBY_ADMISSION, s)
	{}
	virtual ~ZC_REPLY_ACK_LOBBY_ADMISSION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070911 || \
	PACKET_VERSION >= 0
	ID_ZC_ISVR_DISCONNECT = 0x02d5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ISVR_DISCONNECT
 *
 */ 
class ZC_ISVR_DISCONNECT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ISVR_DISCONNECT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ISVR_DISCONNECT, s)
	{}
	virtual ~ZC_ISVR_DISCONNECT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_CLOSE_STORE = 0x00f8
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CLOSE_STORE
 *
 */ 
class ZC_CLOSE_STORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CLOSE_STORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CLOSE_STORE, s)
	{}
	virtual ~ZC_CLOSE_STORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070622 || \
	PACKET_VERSION >= 0
	ID_ZC_DEL_QUEST = 0x02b4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DEL_QUEST
 *
 */ 
class ZC_DEL_QUEST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DEL_QUEST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DEL_QUEST, s)
	{}
	virtual ~ZC_DEL_QUEST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_RECOVERY = 0x013d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_RECOVERY
 *
 */ 
class ZC_RECOVERY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_RECOVERY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_RECOVERY, s)
	{}
	virtual ~ZC_RECOVERY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MAPPROPERTY = 0x0199
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MAPPROPERTY
 *
 */ 
class ZC_NOTIFY_MAPPROPERTY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MAPPROPERTY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MAPPROPERTY, s)
	{}
	virtual ~ZC_NOTIFY_MAPPROPERTY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACK_REQ_CHANGE_MEMBERS = 0x0156
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQ_CHANGE_MEMBERS
 *
 */ 
class ZC_ACK_REQ_CHANGE_MEMBERS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQ_CHANGE_MEMBERS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQ_CHANGE_MEMBERS, s)
	{}
	virtual ~ZC_ACK_REQ_CHANGE_MEMBERS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100309 || \
	PACKET_VERSION >= 0
	ID_ZC_EL_PAR_CHANGE = 0x081e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EL_PAR_CHANGE
 *
 */ 
class ZC_EL_PAR_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EL_PAR_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EL_PAR_CHANGE, s)
	{}
	virtual ~ZC_EL_PAR_CHANGE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050328 || \
	PACKET_VERSION >= 0
	ID_ZC_TAEKWON_RANK = 0x0226
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_TAEKWON_RANK
 *
 */ 
class ZC_TAEKWON_RANK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_TAEKWON_RANK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_TAEKWON_RANK, s)
	{}
	virtual ~ZC_TAEKWON_RANK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20160928 || \
	PACKET_VERSION >= 0
	ID_ZC_ALT_EQUIPMENT_REMOVE = 0x0a9a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALT_EQUIPMENT_REMOVE
 *
 */ 
class ZC_ALT_EQUIPMENT_REMOVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALT_EQUIPMENT_REMOVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALT_EQUIPMENT_REMOVE, s)
	{}
	virtual ~ZC_ALT_EQUIPMENT_REMOVE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050530 || \
	PACKET_VERSION >= 0
	ID_ZC_KILLER_POINT = 0x0236
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_KILLER_POINT
 *
 */ 
class ZC_KILLER_POINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_KILLER_POINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_KILLER_POINT, s)
	{}
	virtual ~ZC_KILLER_POINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20061226 || \
	PACKET_VERSION >= 0
	ID_ZC_MER_SKILLINFO_UPDATE = 0x029e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MER_SKILLINFO_UPDATE
 *
 */ 
class ZC_MER_SKILLINFO_UPDATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MER_SKILLINFO_UPDATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MER_SKILLINFO_UPDATE, s)
	{}
	virtual ~ZC_MER_SKILLINFO_UPDATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090610 || \
	PACKET_VERSION >= 0
	ID_ZC_HO_PAR_CHANGE = 0x07db
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HO_PAR_CHANGE
 *
 */ 
class ZC_HO_PAR_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HO_PAR_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HO_PAR_CHANGE, s)
	{}
	virtual ~ZC_HO_PAR_CHANGE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_COMBODELAY = 0x01d2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_COMBODELAY
 *
 */ 
class ZC_COMBODELAY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_COMBODELAY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_COMBODELAY, s)
	{}
	virtual ~ZC_COMBODELAY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130717 || \
	PACKET_VERSION >= 0
	ID_ZC_SECRETSCAN_DATA = 0x09cc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SECRETSCAN_DATA
 *
 */ 
class ZC_SECRETSCAN_DATA : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SECRETSCAN_DATA(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SECRETSCAN_DATA, s)
	{}
	virtual ~ZC_SECRETSCAN_DATA() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_LEAVE_GUILD = 0x015a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_LEAVE_GUILD
 *
 */ 
class ZC_ACK_LEAVE_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_LEAVE_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_LEAVE_GUILD, s)
	{}
	virtual ~ZC_ACK_LEAVE_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_ACT = 0x008a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_ACT
 *
 */ 
class ZC_NOTIFY_ACT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_ACT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_ACT, s)
	{}
	virtual ~ZC_NOTIFY_ACT() {}

	void deliver(int8_t action);
	ByteBuffer &serialize();

/* Structure */
	int8_t _unused_bytes[20];
	int8_t _action_type{2};
	int8_t _unused_bytes2[2];

};

enum {
#if PACKET_VERSION >= 20140723 || \
	PACKET_VERSION >= 0
	ID_ZC_SE_PC_BUY_TAIWANCASHITEM_RESULT = 0x0a2c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SE_PC_BUY_TAIWANCASHITEM_RESULT
 *
 */ 
class ZC_SE_PC_BUY_TAIWANCASHITEM_RESULT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SE_PC_BUY_TAIWANCASHITEM_RESULT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SE_PC_BUY_TAIWANCASHITEM_RESULT, s)
	{}
	virtual ~ZC_SE_PC_BUY_TAIWANCASHITEM_RESULT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050531 || \
	PACKET_VERSION >= 20050530 || \
	PACKET_VERSION >= 0
	ID_ZC_HOSKILLINFO_UPDATE = 0x0239
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HOSKILLINFO_UPDATE
 *
 */ 
class ZC_HOSKILLINFO_UPDATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HOSKILLINFO_UPDATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HOSKILLINFO_UPDATE, s)
	{}
	virtual ~ZC_HOSKILLINFO_UPDATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_EMOTION = 0x00c0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EMOTION
 *
 */ 
class ZC_EMOTION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EMOTION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EMOTION, s)
	{}
	virtual ~ZC_EMOTION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090617 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20071127 || \
	PACKET_VERSION >= 20071106 || \
	PACKET_VERSION >= 20070102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STANDENTRY_NPC = 0x007c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STANDENTRY_NPC
 *
 */ 
class ZC_NOTIFY_STANDENTRY_NPC : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STANDENTRY_NPC(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STANDENTRY_NPC, s)
	{}
	virtual ~ZC_NOTIFY_STANDENTRY_NPC() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_REMEMBER_WARPPOINT = 0x011e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REMEMBER_WARPPOINT
 *
 */ 
class ZC_ACK_REMEMBER_WARPPOINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REMEMBER_WARPPOINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REMEMBER_WARPPOINT, s)
	{}
	virtual ~ZC_ACK_REMEMBER_WARPPOINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STOREITEM_COUNTINFO = 0x00f2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STOREITEM_COUNTINFO
 *
 */ 
class ZC_NOTIFY_STOREITEM_COUNTINFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STOREITEM_COUNTINFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STOREITEM_COUNTINFO, s)
	{}
	virtual ~ZC_NOTIFY_STOREITEM_COUNTINFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20100420 || \
	PACKET_VERSION >= 0
	ID_ZC_FAILED_TRADE_BUYING_STORE_TO_SELLER = 0x0824
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FAILED_TRADE_BUYING_STORE_TO_SELLER
 *
 */ 
class ZC_FAILED_TRADE_BUYING_STORE_TO_SELLER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FAILED_TRADE_BUYING_STORE_TO_SELLER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FAILED_TRADE_BUYING_STORE_TO_SELLER, s)
	{}
	virtual ~ZC_FAILED_TRADE_BUYING_STORE_TO_SELLER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050829 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_MAIL_DELETE = 0x0257
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_MAIL_DELETE
 *
 */ 
class ZC_ACK_MAIL_DELETE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_MAIL_DELETE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_MAIL_DELETE, s)
	{}
	virtual ~ZC_ACK_MAIL_DELETE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120417 || \
	PACKET_VERSION >= 0
	ID_ZC_PERSONAL_INFOMATION2 = 0x097b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PERSONAL_INFOMATION2
 *
 */ 
class ZC_PERSONAL_INFOMATION2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PERSONAL_INFOMATION2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PERSONAL_INFOMATION2, s)
	{}
	virtual ~ZC_PERSONAL_INFOMATION2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20180117 || \
	PACKET_VERSION >= 0
	ID_ZC_UI_ACTION = 0x0af0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UI_ACTION
 *
 */ 
class ZC_UI_ACTION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UI_ACTION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UI_ACTION, s)
	{}
	virtual ~ZC_UI_ACTION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110222 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_SE_CASH_ITEM_LIST2 = 0x08c0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_SE_CASH_ITEM_LIST2
 *
 */ 
class ZC_ACK_SE_CASH_ITEM_LIST2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_SE_CASH_ITEM_LIST2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_SE_CASH_ITEM_LIST2, s)
	{}
	virtual ~ZC_ACK_SE_CASH_ITEM_LIST2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20131002 || \
	PACKET_VERSION >= 20130925 || \
	PACKET_VERSION >= 20130911 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_GUILDSTORAGE_LOG = 0x09da
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_GUILDSTORAGE_LOG
 *
 */ 
class ZC_ACK_GUILDSTORAGE_LOG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_GUILDSTORAGE_LOG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_GUILDSTORAGE_LOG, s)
	{}
	virtual ~ZC_ACK_GUILDSTORAGE_LOG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MYGUILD_BASIC_INFO = 0x014c
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MYGUILD_BASIC_INFO
 *
 */ 
class ZC_MYGUILD_BASIC_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MYGUILD_BASIC_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MYGUILD_BASIC_INFO, s)
	{}
	virtual ~ZC_MYGUILD_BASIC_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070821 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_JOIN_REQ = 0x02c6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_JOIN_REQ
 *
 */ 
class ZC_PARTY_JOIN_REQ : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_JOIN_REQ(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_JOIN_REQ, s)
	{}
	virtual ~ZC_PARTY_JOIN_REQ() {}

	void deliver(int party_id, std::string party_name);
	ByteBuffer &serialize();

/* Structure */
	int _party_id{ 0 };
	char _party_name[MAX_PARTY_NAME_LENGTH]{ 0 };
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_MOVE = 0x0086
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_MOVE
 *
 */ 
class ZC_NOTIFY_MOVE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_MOVE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_MOVE, s)
	{}
	virtual ~ZC_NOTIFY_MOVE() {}

	void deliver(int32_t guid, int16_t from_x, int16_t from_y, int16_t to_x, int16_t to_y);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid{0};
	int32_t _timestamp{0};
	char _packed_pos[6]{0};
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20050523 || \
	PACKET_VERSION >= 0
	ID_ZC_CHANGESTATE_MER = 0x0230
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CHANGESTATE_MER
 *
 */ 
class ZC_CHANGESTATE_MER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CHANGESTATE_MER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CHANGESTATE_MER, s)
	{}
	virtual ~ZC_CHANGESTATE_MER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACK_GUILD_MENUINTERFACE = 0x014e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_GUILD_MENintERFACE
 *
 */ 
class ZC_ACK_GUILD_MENUINTERFACE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_GUILD_MENUINTERFACE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_GUILD_MENUINTERFACE, s)
	{}
	virtual ~ZC_ACK_GUILD_MENUINTERFACE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACK_GIVE_MANNER_POINT = 0x014a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_GIVE_MANNER_POINT
 *
 */ 
class ZC_ACK_GIVE_MANNER_POINT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_GIVE_MANNER_POINT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_GIVE_MANNER_POINT, s)
	{}
	virtual ~ZC_ACK_GIVE_MANNER_POINT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20180605 || \
	PACKET_VERSION >= 0
	ID_ZC_GUILD_POSITION = 0x0afd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILD_POSITION
 *
 */ 
class ZC_GUILD_POSITION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILD_POSITION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILD_POSITION, s)
	{}
	virtual ~ZC_GUILD_POSITION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20061218 || \
	PACKET_VERSION >= 20061211 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIPMENT_ITEMLIST2 = 0x0295
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIPMENT_ITEMLIST2
 *
 */ 
class ZC_EQUIPMENT_ITEMLIST2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIPMENT_ITEMLIST2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIPMENT_ITEMLIST2, s)
	{}
	virtual ~ZC_EQUIPMENT_ITEMLIST2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070904 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIPMENT_ITEMLIST3 = 0x02d0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIPMENT_ITEMLIST3
 *
 */ 
class ZC_EQUIPMENT_ITEMLIST3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIPMENT_ITEMLIST3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIPMENT_ITEMLIST3, s)
	{}
	virtual ~ZC_EQUIPMENT_ITEMLIST3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130103 || \
	PACKET_VERSION >= 20111025 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_RECRUIT_NOTIFY_UPDATE = 0x08ed
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_RECRUIT_NOTIFY_UPDATE
 *
 */ 
class ZC_PARTY_RECRUIT_NOTIFY_UPDATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_RECRUIT_NOTIFY_UPDATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_RECRUIT_NOTIFY_UPDATE, s)
	{}
	virtual ~ZC_PARTY_RECRUIT_NOTIFY_UPDATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20091229 || \
	PACKET_VERSION >= 20091228 || \
	PACKET_VERSION >= 20091222 || \
	PACKET_VERSION >= 0
	ID_ZC_PARTY_BOOKING_NOTIFY_UPDATE = 0x080a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PARTY_BOOKING_NOTIFY_UPDATE
 *
 */ 
class ZC_PARTY_BOOKING_NOTIFY_UPDATE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PARTY_BOOKING_NOTIFY_UPDATE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PARTY_BOOKING_NOTIFY_UPDATE, s)
	{}
	virtual ~ZC_PARTY_BOOKING_NOTIFY_UPDATE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070813 || \
	PACKET_VERSION >= 20070703 || \
	PACKET_VERSION >= 20070628 || \
	PACKET_VERSION >= 20070622 || \
	PACKET_VERSION >= 0
	ID_ZC_UPDATE_MISSION_HUNT = 0x02b5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_MISSION_HUNT
 *
 */ 
class ZC_UPDATE_MISSION_HUNT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_MISSION_HUNT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_MISSION_HUNT, s)
	{}
	virtual ~ZC_UPDATE_MISSION_HUNT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_RESURRECTION = 0x0148
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_RESURRECTION
 *
 */ 
class ZC_RESURRECTION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_RESURRECTION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_RESURRECTION, s)
	{}
	virtual ~ZC_RESURRECTION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20050718 || \
	PACKET_VERSION >= 0
	ID_ZC_MAIL_REQ_OPEN = 0x0242
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MAIL_REQ_OPEN
 *
 */ 
class ZC_MAIL_REQ_OPEN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAIL_REQ_OPEN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAIL_REQ_OPEN, s)
	{}
	virtual ~ZC_MAIL_REQ_OPEN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_ITEM_TO_CART = 0x0124
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_ITEM_TO_CART
 *
 */ 
class ZC_ADD_ITEM_TO_CART : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ADD_ITEM_TO_CART(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_ITEM_TO_CART, s)
	{}
	virtual ~ZC_ADD_ITEM_TO_CART() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20110810 || \
	PACKET_VERSION >= 20110809 || \
	PACKET_VERSION >= 20110803 || \
	PACKET_VERSION >= 20110802 || \
	PACKET_VERSION >= 0
	ID_ZC_FAILED_GET_ITEM_FROM_ZONEDA = 0x08ce
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_FAILED_GET_ITEM_FROM_ZONEDA
 *
 */ 
class ZC_FAILED_GET_ITEM_FROM_ZONEDA : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_FAILED_GET_ITEM_FROM_ZONEDA(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_FAILED_GET_ITEM_FROM_ZONEDA, s)
	{}
	virtual ~ZC_FAILED_GET_ITEM_FROM_ZONEDA() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION == 20131218
	ID_ZC_ACK_RODEX_LIST = 0x09f0
#elif PACKET_VERSION >= 20170228 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_RODEX_LIST = 0x0ac2
#elif PACKET_VERSION == 20160601
	ID_ZC_ACK_RODEX_LIST = 0x0a7d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_RODEX_LIST
 *
 */ 
class ZC_ACK_RODEX_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_RODEX_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_RODEX_LIST, s)
	{}
	virtual ~ZC_ACK_RODEX_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_CHAT = 0x008d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_CHAT
 *
 */ 
class ZC_NOTIFY_CHAT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_CHAT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_CHAT, s)
	{}
	virtual ~ZC_NOTIFY_CHAT() {}

	void deliver(int32_t guid, std::string message);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{8};
	int32_t _guid{0};
	std::string _message{""};
};

enum {
#if PACKET_VERSION >= 20140402 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_ITEMLIST_EQUIP_V6 = 0x0a10
#elif PACKET_VERSION >= 20180829 || \
	PACKET_VERSION >= 20180822 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_ITEMLIST_EQUIP_V6 = 0x0b0a
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_ITEMLIST_EQUIP_V6
 *
 */ 
class ZC_STORE_ITEMLIST_EQUIP_V6 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_ITEMLIST_EQUIP_V6(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_ITEMLIST_EQUIP_V6, s)
	{}
	virtual ~ZC_STORE_ITEMLIST_EQUIP_V6() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20071127 || \
	PACKET_VERSION >= 20071106 || \
	PACKET_VERSION >= 20070102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_STANDENTRY = 0x0078
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_STANDENTRY
 *
 */ 
class ZC_NOTIFY_STANDENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_STANDENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_STANDENTRY, s)
	{}
	virtual ~ZC_NOTIFY_STANDENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_NOTIFY_FONT = 0x02ef
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_FONT
 *
 */ 
class ZC_NOTIFY_FONT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_FONT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_FONT, s)
	{}
	virtual ~ZC_NOTIFY_FONT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120523 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090330 || \
	PACKET_VERSION >= 0
	ID_ZC_HACKSH_ERROR_MSG = 0x0449
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_HACKSH_ERROR_MSG
 *
 */ 
class ZC_HACKSH_ERROR_MSG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_HACKSH_ERROR_MSG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_HACKSH_ERROR_MSG, s)
	{}
	virtual ~ZC_HACKSH_ERROR_MSG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20060607 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_PCBANG = 0x0278
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_PCBANG
 *
 */ 
class ZC_NOTIFY_PCBANG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_PCBANG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_PCBANG, s)
	{}
	virtual ~ZC_NOTIFY_PCBANG() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20101102 || \
	PACKET_VERSION >= 0
	ID_ZC_GPK_AUTH = 0x0853
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GPK_AUTH
 *
 */ 
class ZC_GPK_AUTH : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GPK_AUTH(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GPK_AUTH, s)
	{}
	virtual ~ZC_GPK_AUTH() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_STATE_CHANGE = 0x0119
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STATE_CHANGE
 *
 */ 
class ZC_STATE_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STATE_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STATE_CHANGE, s)
	{}
	virtual ~ZC_STATE_CHANGE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20171206 || \
	PACKET_VERSION >= 20171130 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_MEMBER_TO_GROUP = 0x0ae4
#elif PACKET_VERSION == 20151007
	ID_ZC_ADD_MEMBER_TO_GROUP = 0x0a43
#elif PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20031117 || \
	PACKET_VERSION >= 20031110 || \
	PACKET_VERSION >= 20031029 || \
	PACKET_VERSION >= 20031028 || \
	PACKET_VERSION >= 0
	ID_ZC_ADD_MEMBER_TO_GROUP = 0x0104
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ADD_MEMBER_TO_GROUP
 *
 */ 
class ZC_ADD_MEMBER_TO_GROUP : public Base::NetworkPacketTransmitter<ZoneSession>
{
	struct s_zc_add_member_to_group
	{
		uint32_t _account_id;
#if PACKET_VERSION >= 20171207
		uint32_t _char_id;
#endif
		uint32_t leader;
#if (CLIENT_TYPE == 'M' && PACKET_VERSION >= 20170524) || \
	(CLIENT_TYPE == 'R' && PACKET_VERSION >= 20170502) || \
	(CLIENT_TYPE == 'Z')
		int16_t class_;
		int16_t base_level;
#endif
		int16_t x;
		int16_t y;
		uint8_t offline;
		char party_name[MAX_PARTY_NAME_LENGTH];
		char player_name[MAX_UNIT_NAME_LENGTH];
		char map_name[MAP_NAME_LENGTH_EXT];
		int8_t share_pickup;
		int8_t share_loot;
	};
public:
	ZC_ADD_MEMBER_TO_GROUP(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ADD_MEMBER_TO_GROUP, s)
	{}
	virtual ~ZC_ADD_MEMBER_TO_GROUP() {}

	void deliver(s_zc_add_member_to_group member);
	ByteBuffer &serialize();

/* Structure */
	s_zc_add_member_to_group _member;
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_GUILD_INFO2 = 0x01b6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_GUILD_INFO2
 *
 */ 
class ZC_GUILD_INFO2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_GUILD_INFO2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_GUILD_INFO2, s)
	{}
	virtual ~ZC_GUILD_INFO2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MEMBER_NEWENTRY = 0x00dc
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MEMBER_NEWENTRY
 *
 */ 
class ZC_MEMBER_NEWENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MEMBER_NEWENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MEMBER_NEWENTRY, s)
	{}
	virtual ~ZC_MEMBER_NEWENTRY() {}

	void deliver(int16_t user_count, std::string name);
	ByteBuffer &serialize();

/* Structure */
	int _user_count{ 0 };
	char _name[MAX_UNIT_NAME_LENGTH]{ 0 };
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20130605 || \
	PACKET_VERSION >= 20130327 || \
	PACKET_VERSION >= 20130313 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_BARGAIN_SALE_SELLING = 0x09b2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_BARGAIN_SALE_SELLING
 *
 */ 
class ZC_NOTIFY_BARGAIN_SALE_SELLING : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_BARGAIN_SALE_SELLING(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_BARGAIN_SALE_SELLING, s)
	{}
	virtual ~ZC_NOTIFY_BARGAIN_SALE_SELLING() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20131218 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_DELETE_RODEX = 0x09f6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_DELETE_RODEX
 *
 */ 
class ZC_ACK_DELETE_RODEX : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_DELETE_RODEX(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_DELETE_RODEX, s)
	{}
	virtual ~ZC_ACK_DELETE_RODEX() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_PC_PURCHASE_ITEMLIST_FROMMC = 0x0133
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PC_PURCHASE_ITEMLIST_FROMMC
 *
 */ 
class ZC_PC_PURCHASE_ITEMLIST_FROMMC : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PC_PURCHASE_ITEMLIST_FROMMC(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PC_PURCHASE_ITEMLIST_FROMMC, s)
	{}
	virtual ~ZC_PC_PURCHASE_ITEMLIST_FROMMC() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20170920
	ID_ZC_ACK_REQNAME = 0x0adf
#elif PACKET_VERSION >= 0
	ID_ZC_ACK_REQNAME = 0x0095
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_REQNAME
 *
 */ 
class ZC_ACK_REQNAME : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_REQNAME(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_REQNAME, s)
	{}
	virtual ~ZC_ACK_REQNAME() {}

	void deliver(int32_t guid, const char *name);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid{0};
	char _name[MAX_UNIT_NAME_LENGTH]{0};
};

enum {
#if PACKET_VERSION >= 20130717 || \
	PACKET_VERSION >= 0
	ID_ZC_USE_SKILL2 = 0x09cb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_USE_SKILL2
 *
 */ 
class ZC_USE_SKILL2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_USE_SKILL2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_USE_SKILL2, s)
	{}
	virtual ~ZC_USE_SKILL2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20101019 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEM_FALL_ENTRY4 = 0x084b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEM_FALL_ENTRY4
 *
 */ 
class ZC_ITEM_FALL_ENTRY4 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEM_FALL_ENTRY4(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEM_FALL_ENTRY4, s)
	{}
	virtual ~ZC_ITEM_FALL_ENTRY4() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_STORE_EQUIPMENT_ITEMLIST = 0x00a6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_STORE_EQUIPMENT_ITEMLIST
 *
 */ 
class ZC_STORE_EQUIPMENT_ITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_STORE_EQUIPMENT_ITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_STORE_EQUIPMENT_ITEMLIST, s)
	{}
	virtual ~ZC_STORE_EQUIPMENT_ITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_CREATE_CHATROOM = 0x00d6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_CREATE_CHATROOM
 *
 */ 
class ZC_ACK_CREATE_CHATROOM : public Base::NetworkPacketTransmitter<ZoneSession>
{
	enum zcack_create_chatroom_result_type
	{
		ZCACK_CREATE_CHATROOM_RESULT_SUCCESS = 0,
		ZCACK_CREATE_CHATROOM_RESULT_LIMIT_EXCEEDED = 1,
		ZCACK_CREATE_CHATROOM_RESULT_DUPLICATE_ROOM = 2
	};
public:
	ZC_ACK_CREATE_CHATROOM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_CREATE_CHATROOM, s)
	{}
	virtual ~ZC_ACK_CREATE_CHATROOM() {}

	void deliver(zcack_create_chatroom_result_type result);
	ByteBuffer &serialize();

/* Structure */
	int8_t _result{ 0 };
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102
	ID_ZC_PAR_CHANGE = 0x00b0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_PAR_CHANGE
 *
 */ 
class ZC_PAR_CHANGE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_PAR_CHANGE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_PAR_CHANGE, s)
	{}
	virtual ~ZC_PAR_CHANGE() {}

	void deliver(status_point_type type, int16_t value);
	ByteBuffer &serialize();

/* Structure */
	status_point_type _type{STATUS_POINT_INVALID};
	int32_t _value{0};
};

enum {
#if PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20061218 || \
	PACKET_VERSION >= 20061211 || \
	PACKET_VERSION >= 0
	ID_ZC_CART_EQUIPMENT_ITEMLIST2 = 0x0297
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_EQUIPMENT_ITEMLIST2
 *
 */ 
class ZC_CART_EQUIPMENT_ITEMLIST2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_EQUIPMENT_ITEMLIST2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_EQUIPMENT_ITEMLIST2, s)
	{}
	virtual ~ZC_CART_EQUIPMENT_ITEMLIST2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20070904 || \
	PACKET_VERSION >= 0
	ID_ZC_CART_EQUIPMENT_ITEMLIST3 = 0x02d2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_EQUIPMENT_ITEMLIST3
 *
 */ 
class ZC_CART_EQUIPMENT_ITEMLIST3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_EQUIPMENT_ITEMLIST3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_EQUIPMENT_ITEMLIST3, s)
	{}
	virtual ~ZC_CART_EQUIPMENT_ITEMLIST3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_WHISPER = 0x0098
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_WHISPER
 *
 */ 
class ZC_ACK_WHISPER : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_WHISPER(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_WHISPER, s)
	{}
	virtual ~ZC_ACK_WHISPER() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140716 || \
	PACKET_VERSION >= 20140108 || \
	PACKET_VERSION >= 20131211 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_UNREAD_RODEX = 0x09e7
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_UNREAD_RODEX
 *
 */ 
class ZC_NOTIFY_UNREAD_RODEX : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_UNREAD_RODEX(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_UNREAD_RODEX, s)
	{}
	virtual ~ZC_NOTIFY_UNREAD_RODEX() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_ACK_ACCOUNTNAME = 0x01e0
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ACCOUNTNAME
 *
 */ 
class ZC_ACK_ACCOUNTNAME : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ACCOUNTNAME(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ACCOUNTNAME, s)
	{}
	virtual ~ZC_ACK_ACCOUNTNAME() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20160928 || \
	PACKET_VERSION >= 0
	ID_ZC_ALT_EQUIPMENT_ITEMS = 0x0a9b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ALT_EQUIPMENT_ITEMS
 *
 */ 
class ZC_ALT_EQUIPMENT_ITEMS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ALT_EQUIPMENT_ITEMS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ALT_EQUIPMENT_ITEMS, s)
	{}
	virtual ~ZC_ALT_EQUIPMENT_ITEMS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 20031218 || \
	PACKET_VERSION >= 0
	ID_ZC_CART_NORMAL_ITEMLIST2 = 0x01ef
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_NORMAL_ITEMLIST2
 *
 */ 
class ZC_CART_NORMAL_ITEMLIST2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_NORMAL_ITEMLIST2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_NORMAL_ITEMLIST2, s)
	{}
	virtual ~ZC_CART_NORMAL_ITEMLIST2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_CART_NORMAL_ITEMLIST3 = 0x02e9
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_NORMAL_ITEMLIST3
 *
 */ 
class ZC_CART_NORMAL_ITEMLIST3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_NORMAL_ITEMLIST3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_NORMAL_ITEMLIST3, s)
	{}
	virtual ~ZC_CART_NORMAL_ITEMLIST3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20041129 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_WEAPONREFINE = 0x0223
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_WEAPONREFINE
 *
 */ 
class ZC_ACK_WEAPONREFINE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_WEAPONREFINE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_WEAPONREFINE, s)
	{}
	virtual ~ZC_ACK_WEAPONREFINE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140924 || \
	PACKET_VERSION >= 0
	ID_ZC_UPDATE_ROULETTE_COIN = 0x0a33
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_ROULETTE_COIN
 *
 */ 
class ZC_UPDATE_ROULETTE_COIN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_ROULETTE_COIN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_ROULETTE_COIN, s)
	{}
	virtual ~ZC_UPDATE_ROULETTE_COIN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100420 || \
	PACKET_VERSION >= 20100309 || \
	PACKET_VERSION >= 20100303 || \
	PACKET_VERSION >= 0
	ID_ZC_BUYING_STORE_ENTRY = 0x0814
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BUYING_STORE_ENTRY
 *
 */ 
class ZC_BUYING_STORE_ENTRY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BUYING_STORE_ENTRY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BUYING_STORE_ENTRY, s)
	{}
	virtual ~ZC_BUYING_STORE_ENTRY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130306 || \
	PACKET_VERSION >= 0
	ID_ZC_BANKING_CHECK = 0x09a6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BANKING_CHECK
 *
 */ 
class ZC_BANKING_CHECK : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BANKING_CHECK(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BANKING_CHECK, s)
	{}
	virtual ~ZC_BANKING_CHECK() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20101123 || \
	PACKET_VERSION >= 0
	ID_ZC_EQUIPWIN_MICROSCOPE2 = 0x0859
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_EQUIPWIN_MICROSCOPE2
 *
 */ 
class ZC_EQUIPWIN_MICROSCOPE2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_EQUIPWIN_MICROSCOPE2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_EQUIPWIN_MICROSCOPE2, s)
	{}
	virtual ~ZC_EQUIPWIN_MICROSCOPE2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20130206 || \
	PACKET_VERSION >= 0
	ID_ZC_DISPATCH_TIMING_INFO_CHN = 0x09a4
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DISPATCH_TIMING_INFO_CHN
 *
 */ 
class ZC_DISPATCH_TIMING_INFO_CHN : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DISPATCH_TIMING_INFO_CHN(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DISPATCH_TIMING_INFO_CHN, s)
	{}
	virtual ~ZC_DISPATCH_TIMING_INFO_CHN() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090929 || \
	PACKET_VERSION >= 0
	ID_ZC_CANCEL_BATTLE_FIELD = 0x07ef
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CANCEL_BATTLE_FIELD
 *
 */ 
class ZC_CANCEL_BATTLE_FIELD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CANCEL_BATTLE_FIELD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CANCEL_BATTLE_FIELD, s)
	{}
	virtual ~ZC_CANCEL_BATTLE_FIELD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140625 || \
	PACKET_VERSION >= 0
	ID_ZC_RECOVERY2 = 0x0a27
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_RECOVERY2
 *
 */ 
class ZC_RECOVERY2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_RECOVERY2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_RECOVERY2, s)
	{}
	virtual ~ZC_RECOVERY2() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20100420 || \
	PACKET_VERSION >= 20100414 || \
	PACKET_VERSION >= 20100309 || \
	PACKET_VERSION >= 0
	ID_ZC_UPDATE_ITEM_FROM_BUYING_STORE = 0x081b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_ITEM_FROM_BUYING_STORE
 *
 */ 
class ZC_UPDATE_ITEM_FROM_BUYING_STORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_ITEM_FROM_BUYING_STORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_ITEM_FROM_BUYING_STORE, s)
	{}
	virtual ~ZC_UPDATE_ITEM_FROM_BUYING_STORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_RESULT_MAKE_GUILD = 0x0167
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_RESULT_MAKE_GUILD
 *
 */ 
class ZC_RESULT_MAKE_GUILD : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_RESULT_MAKE_GUILD(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_RESULT_MAKE_GUILD, s)
	{}
	virtual ~ZC_RESULT_MAKE_GUILD() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20090520
	ID_ZC_ES_LIST = 0x07d2
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ES_LIST
 *
 */ 
class ZC_ES_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ES_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ES_LIST, s)
	{}
	virtual ~ZC_ES_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090929 || \
	PACKET_VERSION >= 0
	ID_ZC_BATTLE_FIELD_LIST = 0x07eb
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_BATTLE_FIELD_LIST
 *
 */ 
class ZC_BATTLE_FIELD_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_BATTLE_FIELD_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_BATTLE_FIELD_LIST, s)
	{}
	virtual ~ZC_BATTLE_FIELD_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20131230 || \
	PACKET_VERSION >= 20131211 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_SEND_RODEX = 0x09ed
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_SEND_RODEX
 *
 */ 
class ZC_ACK_SEND_RODEX : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_SEND_RODEX(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_SEND_RODEX, s)
	{}
	virtual ~ZC_ACK_SEND_RODEX() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20051024 || \
	PACKET_VERSION >= 0
	ID_ZC_AUCTION_WINDOWS = 0x025f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_AUCTION_WINDOWS
 *
 */ 
class ZC_AUCTION_WINDOWS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_AUCTION_WINDOWS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_AUCTION_WINDOWS, s)
	{}
	virtual ~ZC_AUCTION_WINDOWS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_ITEMREFINING = 0x0188
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_ITEMREFINING
 *
 */ 
class ZC_ACK_ITEMREFINING : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_ITEMREFINING(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_ITEMREFINING, s)
	{}
	virtual ~ZC_ACK_ITEMREFINING() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090617 || \
	PACKET_VERSION >= 0
	ID_ZC_SEEK_PARTY = 0x07dd
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SEEK_PARTY
 *
 */ 
class ZC_SEEK_PARTY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SEEK_PARTY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SEEK_PARTY, s)
	{}
	virtual ~ZC_SEEK_PARTY() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20181121 || \
	PACKET_VERSION >= 20181114 || \
	PACKET_VERSION >= 20180704 || \
	PACKET_VERSION >= 20180103 || \
	PACKET_VERSION >= 20130327 || \
	PACKET_VERSION >= 20130313 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_CASH_BARGAIN_SALE_ITEM_INFO = 0x09ad
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_CASH_BARGAIN_SALE_ITEM_INFO
 *
 */ 
class ZC_ACK_CASH_BARGAIN_SALE_ITEM_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_CASH_BARGAIN_SALE_ITEM_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_CASH_BARGAIN_SALE_ITEM_INFO, s)
	{}
	virtual ~ZC_ACK_CASH_BARGAIN_SALE_ITEM_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_SHOWDIGIT = 0x01b1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_SHOWDIGIT
 *
 */ 
class ZC_SHOWDIGIT : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_SHOWDIGIT(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_SHOWDIGIT, s)
	{}
	virtual ~ZC_SHOWDIGIT() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120503 || \
	PACKET_VERSION >= 20120502 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_RANKING = 0x097d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_RANKING
 *
 */ 
class ZC_ACK_RANKING : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_RANKING(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_RANKING, s)
	{}
	virtual ~ZC_ACK_RANKING() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20051024 || \
	PACKET_VERSION >= 0
	ID_ZC_MAIL_WINDOWS = 0x0260
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MAIL_WINDOWS
 *
 */ 
class ZC_MAIL_WINDOWS : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAIL_WINDOWS(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAIL_WINDOWS, s)
	{}
	virtual ~ZC_MAIL_WINDOWS() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_DELETEITEM_FROM_MCSTORE = 0x0137
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_DELETEITEM_FROM_MCSTORE
 *
 */ 
class ZC_DELETEITEM_FROM_MCSTORE : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_DELETEITEM_FROM_MCSTORE(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_DELETEITEM_FROM_MCSTORE, s)
	{}
	virtual ~ZC_DELETEITEM_FROM_MCSTORE() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081015 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_ITEMIDENTIFY_LIST = 0x0177
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ITEMIDENTIFY_LIST
 *
 */ 
class ZC_ITEMIDENTIFY_LIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ITEMIDENTIFY_LIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ITEMIDENTIFY_LIST, s)
	{}
	virtual ~ZC_ITEMIDENTIFY_LIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_CHAT_PARTY = 0x0109
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_CHAT_PARTY
 *
 */ 
class ZC_NOTIFY_CHAT_PARTY : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_CHAT_PARTY(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_CHAT_PARTY, s)
	{}
	virtual ~ZC_NOTIFY_CHAT_PARTY() {}

	void deliver(int account_id, std::string message);
	ByteBuffer &serialize();

/* Structure */
	int16_t _packet_length{ 0 };
	int _account_id{ 0 };
	char _message[MAX_CHAT_STR_LENGTH];
};

enum {
#if PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090113 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081111 || \
	PACKET_VERSION >= 0
	ID_ZC_MSG_STATE_CHANGE2 = 0x043f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MSG_STATE_CHANGE2
 *
 */ 
class ZC_MSG_STATE_CHANGE2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MSG_STATE_CHANGE2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MSG_STATE_CHANGE2, s)
	{}
	virtual ~ZC_MSG_STATE_CHANGE2() {}

	void deliver(int16_t si_type, int32_t guid, int8_t state, int32_t time_remaining, int32_t val1, int32_t val2, int32_t val3);
	ByteBuffer &serialize();

/* Structure */
	int16_t _index{0};
	int32_t _guid{0};
	int8_t _state{0};
	int32_t _time_remaining{0};
	int32_t _val1{0};
	int32_t _val2{0};
	int32_t _val3{0};
};

enum {
#if PACKET_VERSION >= 20120529 || \
	PACKET_VERSION >= 0
	ID_ZC_MSG_STATE_CHANGE3 = 0x0983
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MSG_STATE_CHANGE3
 *
 */ 
class ZC_MSG_STATE_CHANGE3 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MSG_STATE_CHANGE3(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MSG_STATE_CHANGE3, s)
	{}
	virtual ~ZC_MSG_STATE_CHANGE3() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090406 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090225 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081217 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20081119 || \
	PACKET_VERSION >= 20081112 || \
	PACKET_VERSION >= 20081105 || \
	PACKET_VERSION >= 20081029 || \
	PACKET_VERSION >= 20081022 || \
	PACKET_VERSION >= 20081008 || \
	PACKET_VERSION >= 20081001 || \
	PACKET_VERSION >= 20080924 || \
	PACKET_VERSION >= 20080917 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080618 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080528 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080325 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080124 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_WAIT_DIALOG = 0x00b5
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_WAIT_DIALOG
 *
 */ 
class ZC_WAIT_DIALOG : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_WAIT_DIALOG(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_WAIT_DIALOG, s)
	{}
	virtual ~ZC_WAIT_DIALOG() {}

	void deliver(int32_t guid);
	ByteBuffer &serialize();

/* Structure */
	int32_t _guid{0};
};

enum {
#if PACKET_VERSION >= 20031110 || \
	PACKET_VERSION >= 20031029 || \
	PACKET_VERSION >= 20031028 || \
	PACKET_VERSION >= 0
	ID_ZC_COUPLENAME = 0x01e6
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_COUPLENAME
 *
 */ 
class ZC_COUPLENAME : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_COUPLENAME(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_COUPLENAME, s)
	{}
	virtual ~ZC_COUPLENAME() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20140115 || \
	PACKET_VERSION >= 0
	ID_ZC_UPDATE_MISSION_HUNT_EX = 0x09fa
#elif PACKET_VERSION >= 20180605 || \
	PACKET_VERSION >= 0
	ID_ZC_UPDATE_MISSION_HUNT_EX = 0x0afe
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_UPDATE_MISSION_HUNT_EX
 *
 */ 
class ZC_UPDATE_MISSION_HUNT_EX : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_UPDATE_MISSION_HUNT_EX(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_UPDATE_MISSION_HUNT_EX, s)
	{}
	virtual ~ZC_UPDATE_MISSION_HUNT_EX() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20090401 || \
	PACKET_VERSION >= 20090325 || \
	PACKET_VERSION >= 20090318 || \
	PACKET_VERSION >= 20090311 || \
	PACKET_VERSION >= 20090218 || \
	PACKET_VERSION >= 20090211 || \
	PACKET_VERSION >= 20090204 || \
	PACKET_VERSION >= 20090129 || \
	PACKET_VERSION >= 20090120 || \
	PACKET_VERSION >= 20090114 || \
	PACKET_VERSION >= 20090107 || \
	PACKET_VERSION >= 20081203 || \
	PACKET_VERSION >= 20081126 || \
	PACKET_VERSION >= 20080910 || \
	PACKET_VERSION >= 20080903 || \
	PACKET_VERSION >= 20080827 || \
	PACKET_VERSION >= 20080820 || \
	PACKET_VERSION >= 20080813 || \
	PACKET_VERSION >= 20080806 || \
	PACKET_VERSION >= 20080730 || \
	PACKET_VERSION >= 20080722 || \
	PACKET_VERSION >= 20080715 || \
	PACKET_VERSION >= 20080708 || \
	PACKET_VERSION >= 20080701 || \
	PACKET_VERSION >= 20080624 || \
	PACKET_VERSION >= 20080617 || \
	PACKET_VERSION >= 20080610 || \
	PACKET_VERSION >= 20080603 || \
	PACKET_VERSION >= 20080520 || \
	PACKET_VERSION >= 20080513 || \
	PACKET_VERSION >= 20080507 || \
	PACKET_VERSION >= 20080429 || \
	PACKET_VERSION >= 20080422 || \
	PACKET_VERSION >= 20080415 || \
	PACKET_VERSION >= 20080408 || \
	PACKET_VERSION >= 20080401 || \
	PACKET_VERSION >= 20080318 || \
	PACKET_VERSION >= 20080311 || \
	PACKET_VERSION >= 20080304 || \
	PACKET_VERSION >= 20080226 || \
	PACKET_VERSION >= 20080219 || \
	PACKET_VERSION >= 20080102 || \
	PACKET_VERSION >= 0
	ID_ZC_MAKABLEITEMLIST = 0x018d
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_MAKABLEITEMLIST
 *
 */ 
class ZC_MAKABLEITEMLIST : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_MAKABLEITEMLIST(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_MAKABLEITEMLIST, s)
	{}
	virtual ~ZC_MAKABLEITEMLIST() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20120925 || \
	PACKET_VERSION >= 0
	ID_ZC_CART_ITEMLIST_EQUIP_V5 = 0x0994
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_CART_ITEMLIST_EQUIP_V5
 *
 */ 
class ZC_CART_ITEMLIST_EQUIP_V5 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_CART_ITEMLIST_EQUIP_V5(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_CART_ITEMLIST_EQUIP_V5, s)
	{}
	virtual ~ZC_CART_ITEMLIST_EQUIP_V5() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_NOTIFY_TIME = 0x007f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_TIME
 *
 */ 
class ZC_NOTIFY_TIME : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_TIME(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_TIME, s)
	{}
	virtual ~ZC_NOTIFY_TIME() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
	int32_t _timestamp{0};
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_POSITION_ID_NAME_INFO = 0x0166
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_POSITION_ID_NAME_INFO
 *
 */ 
class ZC_POSITION_ID_NAME_INFO : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_POSITION_ID_NAME_INFO(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_POSITION_ID_NAME_INFO, s)
	{}
	virtual ~ZC_POSITION_ID_NAME_INFO() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100629 || \
	PACKET_VERSION >= 20100105 || \
	PACKET_VERSION >= 20090929 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_BATTLE_STATE_MONITOR = 0x07f1
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_BATTLE_STATE_MONITOR
 *
 */ 
class ZC_ACK_BATTLE_STATE_MONITOR : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_BATTLE_STATE_MONITOR(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_BATTLE_STATE_MONITOR, s)
	{}
	virtual ~ZC_ACK_BATTLE_STATE_MONITOR() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 20100119 || \
	PACKET_VERSION >= 0
	ID_ZC_NOTIFY_HP_TO_GROUPM_R2 = 0x080e
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_HP_TO_GROUPM_R2
 *
 */ 
class ZC_NOTIFY_HP_TO_GROUPM_R2 : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_HP_TO_GROUPM_R2(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_HP_TO_GROUPM_R2, s)
	{}
	virtual ~ZC_NOTIFY_HP_TO_GROUPM_R2() {}

	void deliver(int account_id, int hp, int max_hp);
	ByteBuffer &serialize();

/* Structure */
	int _account_id{ 0 };
	int _hp{ 0 }, _max_hp{ 0 };
};

enum {
#if PACKET_VERSION >= 20120221 || \
	PACKET_VERSION >= 20120214 || \
	PACKET_VERSION >= 0
	ID_ZC_ACK_MERGE_ITEM = 0x096f
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_ACK_MERGE_ITEM
 *
 */ 
class ZC_ACK_MERGE_ITEM : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_ACK_MERGE_ITEM(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_ACK_MERGE_ITEM, s)
	{}
	virtual ~ZC_ACK_MERGE_ITEM() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

enum {
#if PACKET_VERSION >= 0
	ID_ZC_NOTIFY_ACT_POSITION = 0x008b
#endif
};
/**
 * @brief Main object for the aegis packet: ZC_NOTIFY_ACT_POSITION
 *
 */ 
class ZC_NOTIFY_ACT_POSITION : public Base::NetworkPacketTransmitter<ZoneSession>
{
public:
	ZC_NOTIFY_ACT_POSITION(std::shared_ptr<ZoneSession> s)
	: NetworkPacketTransmitter<ZoneSession>(ID_ZC_NOTIFY_ACT_POSITION, s)
	{}
	virtual ~ZC_NOTIFY_ACT_POSITION() {}

	void deliver();
	ByteBuffer &serialize();

/* Structure */
};

}
}

#endif /* HORIZON_ZONE_TRANSMITTER_PACKETS_HPP */
