/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
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

#ifndef HORIZON_ZONE_CLIENT_DEFINITIONS_HPP
#define HORIZON_ZONE_CLIENT_DEFINITIONS_HPP

#include "Server/Zone/Definitions/ItemDefinitions.hpp"
#include "Server/Zone/Definitions/SkillDefinitions.hpp"

#define MAX_GUILD_SUBJECT_STR_LENGTH 60
#define MAX_GUILD_NOTICE_STR_LENGTH 120
#define MAX_GUILD_LEAVE_REASON_STR_LENGTH 40
#define MAX_EMBLEM_LENGTH 1800

enum grid_notifier_type
{
    GRID_NOTIFY_AREA,               // area
    GRID_NOTIFY_AREA_WOS,           // area, without self
    GRID_NOTIFY_AREA_WOC,           // area, without chatrooms
    GRID_NOTIFY_AREA_WOSC,          // area, without own chatrooms
    GRID_NOTIFY_AREA_CHAT_WOC,      // hearable area, without chatrooms
    GRID_NOTIFY_AREA_DEAD,          // area, for clear unit (monster death)
    GRID_NOTIFY_CHAT,               // current chatroom
    GRID_NOTIFY_CHAT_WOS,           // current chatroom, without self
    GRID_NOTIFY_PARTY,
    GRID_NOTIFY_PARTY_WOS,
    GRID_NOTIFY_PARTY_AREA,
    GRID_NOTIFY_PARTY_AREA_WOS,
    GRID_NOTIFY_GUILD,
    GRID_NOTIFY_GUILD_WOS,
    GRID_NOTIFY_GUILD_AREA,
    GRID_NOTIFY_GUILD_AREA_WOS,
    GRID_NOTIFY_GUILD_NOBG,
    GRID_NOTIFY_DUEL,
    GRID_NOTIFY_DUEL_WOS,
    GRID_NOTIFY_SELF
};


/**   0 = damage [ damage: total damage, div: amount of hits, damage2: assassin dual-wield damage ]
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
enum zc_notify_act_3_action_types
{
    ZCNA3_DAMAGE = 0,
    ZCNA3_PICKUP_ITEM = 1,
    ZCNA3_SIT    = 2,
    ZCNA3_STAND  = 3,
    ZCNA3_ENDURE_DAMAGE = 4,
    ZCNA3_SPLASH = 5,
    ZCNA3_SKILL  = 6,
    ZCNA3_REPEAT_DAMAGE = 7,
    ZCNA3_MULTI_HIT_DAMAGE = 8,
    ZCNA3_MULTI_HIT_ENDURE_DAMAGE = 9,
    ZCNA3_CRITICAL_HIT = 10,
    ZCNA3_LUCKY_DODGE = 11,
    ZCNA3_TOUCH_SKILL = 12,
    ZCNA3_MULTI_HIT_CRITICAL = 13
};

#pragma pack(push, 1)
struct s_zc_membermgr_info_member
{
	int account_id{ 0 };
	int character_id{ 0 };
	int16_t hair_style_id{ 0 }, hair_color_id{ 0 };
	int16_t gender{ 0 };
	int16_t job{ 0 };
	int16_t level{ 0 };
	int contribution_exp{ 0 };
	int current_state{ 0 };
	int position_id{ 0 };
	int last_login{ 0 };
	char name[MAX_UNIT_NAME_LENGTH]{ 0 };
};
#pragma pack(pop)


struct s_zc_guild_info
{
	int guild_id{ 0 };
	int level{ 0 };
	int member_num{ 0 };
	int member_max{ 0 };
	int exp{ 0 };
	int max_exp{ 0 };
	int points{ 0 };
	int honor{ 0 };
	int virtue{ 0 };
	int emblem_id{ 0 };
	char name[MAX_UNIT_NAME_LENGTH];
	char master_name[MAX_UNIT_NAME_LENGTH];
	char managed_castle[MAP_NAME_LENGTH_EXT];
};

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

#pragma pack(push, 1)
struct s_related_guild_info
{
	int relation{ 0 };
	int guild_id{ 0 };
	char guild_name[MAX_GUILD_NAME_LENGTH]{ 0 };
};
#pragma pack(pop)


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

struct s_zc_guild_info2
{
	int guild_id{ 0 };
	int level{ 0 };
	int member_num{ 0 };
	int member_max{ 0 };
	int exp{ 0 };
	int max_exp{ 0 };
	int points{ 0 };
	int honor{ 0 };
	int virtue{ 0 };
	int emblem_id{ 0 };
	char name[MAX_UNIT_NAME_LENGTH];
	char master_name[MAX_UNIT_NAME_LENGTH];
	char managed_castle[MAP_NAME_LENGTH_EXT];
	int zeny{ 0 };
};


#pragma pack(push, 1)
struct s_zc_position_id_name_info
{
	int position_id{ 0 };
	char position_name[MAX_GUILD_POSITION_NAME_LENGTH];
};
#pragma pack(pop)

struct chatroom_user { int8_t _type; char name[MAX_UNIT_NAME_LENGTH]; };

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

struct s_zc_position_info
{
#pragma pack(push, 1)
	int position_id{ 0 };
	int mode{ 0 };
	int ranking{ 0 };
	int pay_rate{ 0 };
#pragma pack(pop)
};

struct zc_status_data {
	int16_t status_points{ 0 };
	int8_t  strength{ 1 };
	int8_t  strength_req_stats{ 1 };
	int8_t  agility{ 1 };
	int8_t  agility_req_stats{ 1 };
	int8_t  vitality{ 1 };
	int8_t  vitality_req_stats{ 1 };
	int8_t  intelligence{ 1 };
	int8_t  intelligence_req_stats{ 1 };
	int8_t  dexterity{ 1 };
	int8_t  dexterity_req_stats{ 1 };
	int8_t  luck{ 1 };
	int8_t  luck_req_stats{ 1 };
	int16_t status_atk{ 1 };
	int16_t equip_atk{ 1 };
	int16_t status_matk{ 1 };
	int16_t equip_matk{ 1 };
	int16_t soft_def{ 1 };
	int16_t hard_def{ 1 };
	int16_t soft_mdef{ 1 };
	int16_t hard_mdef{ 1 };
	int16_t hit{ 1 };
	int16_t flee{ 1 };
	int16_t perfect_dodge{ 1 };
	int16_t critical{ 1 };
	int16_t attack_speed{ 0 };
	int16_t plus_aspd{ 0 }; // always 0 apparently.
};

struct s_zcack_change_guild_positioninfo
{
#pragma pack(push, 1)
	int position_id;
	int mode;
	int ranking;
	int pay_rate;
	char position_name[MAX_GUILD_POSITION_NAME_LENGTH];
#pragma pack(pop)
};

#define CHATROOM_TITLE_SIZE 36 + 1
#define CHATROOM_PASS_SIZE 8 + 1

enum party_invite_response_type
{
	PARTY_INVITE_RESPONSE_REJECTED = 0,
	PARTY_INVITE_RESPONSE_ACCEPTED = 1
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

enum zc_update_charstat_status_type
{
	ZC_UPDATECHARSTAT_STATUS_OFFLINE = 0,
	ZC_UPDATECHARSTAT_STATUS_ONLINE = 1
};

enum zcack_makegroup_result_type
{
	ZCACK_MAKEGROUP_RESULT_SUCCESS = 0,
	ZCACK_MAKEGROUP_RESULT_NAME_ALREADY_EXISTS = 1,
	ZCACK_MAKEGROUP_RESULT_ALREADY_IN_PARTY = 2,
	ZCACK_MAKEGROUP_RESULT_UNAUTHORIZED_ON_MAP = 3,
	ZCACK_MAKEGROUP_RESULT_NOMSG = 4
};

enum zc_change_chatroom_type
{
	ZC_CHANGECHATROOM_PRIVATE = 0, // password protected
	ZC_CHANGECHATROOM_PUBLIC = 1,
	ZC_CHANGECHATROOM_ARENA = 2, // npc waiting room
	ZC_CHANGECHATROOM_PKZONE = 3 // non-clickable
};

enum zc_exec_exchange_item_result_type
{
	ZCEXEC_EXCHANGEITEM_RESULT_SUCCESS = 0,
	ZCEXEC_EXCHANGEITEM_RESULT_FAILURE = 1,
};

enum zc_result_make_guild_type
{
	ZC_RESULTMAKEGUILD_SUCCESS = 0,
	ZC_RESULTMAKEGUILD_ALREADY_IN_GUILD = 1,
	ZC_RESULTMAKEGUILD_NAME_ALREADY_EXISTS = 2,
	ZC_RESULTMAKEGUILD_NEED_REQUIRED_ITEM = 3,
	ZC_RESULTMAKEGUILD_MAP_RESTRICTED = 4
};

enum zcack_create_chatroom_result_type
{
	ZCACK_CREATE_CHATROOM_RESULT_SUCCESS = 0,
	ZCACK_CREATE_CHATROOM_RESULT_LIMIT_EXCEEDED = 1,
	ZCACK_CREATE_CHATROOM_RESULT_DUPLICATE_ROOM = 2
};

enum zc_ackguild_menuinterface_mask
{
	ZC_ACKGUILD_MENUINTERFACE_BASICINFO = 0x00,
	ZC_ACKGUILD_MENUINTERFACE_MEMBERMANAGER = 0x01,
	ZC_ACKGUILD_MENUINTERFACE_POSITIONS = 0x02,
	ZC_ACKGUILD_MENUINTERFACE_SKILLS = 0x04,
	ZC_ACKGUILD_MENUINTERFACE_EXPULSION_LIST = 0x10,
	ZC_ACKGUILD_MENUINTERFACE_ALLGUILDLIST = 0x40,
	ZC_ACKGUILD_MENUINTERFACE_NOTICE = 0x80
};

enum zcack_addexchangeitem_result_type
{
	ZCACK_ADDEXCHANGEITEM_RESULT_SUCCESS = 0,
	ZCACK_ADDEXCHANGEITEM_RESULT_OVERWEIGHT = 1,
	ZCACK_ADDEXCHANGEITEM_RESULT_TRADE_CANCELLED = 2,
	ZCACK_ADDEXCHANGEITEM_RESULT_AMOUNT_EXCEEDED = 3,
	ZCACK_ADDEXCHANGEITEM_RESULT_AMOUNT_EXCEEDED2 = 4
};

enum zc_delete_member_from_group_result_type
{
	ZC_DELETEMEMBER_FROMGROUP_LEAVE = 0,
	ZC_DELETEMEMBER_FROMGROUP_EXPEL = 1,
	ZC_DELETEMEMBER_FROMGROUP_LEAVE_UNAUTHORIZED_MAP = 2,
	ZC_DELETEMEMBER_FROMGROUP_EXPEL_UNAUTHORIZED_MAP = 3
};

enum zc_conclude_exchange_item_type
{
	ZC_CONCLUDEEXCHANGE_ITEM_FOR_SELF = 0,
	ZC_CONCLUDEEXCHANGE_ITEM_FOR_OTHER_PLAYER = 1
};

enum zc_party_config_type
{
	ZC_PARTYCONFIG_TYPE_ALLOW_INVITES = 0,
	ZC_PARTYCONFIG_TYPE_DENY_INVITES = 1
};

enum zc_server_reject_type : int8_t
{
	ZONE_SERV_ERROR_REJECT = 3,
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

enum zc_whisper_result_type {
	WRT_SUCCESS = 0,
	WRT_RECIPIENT_OFFLINE = 1,
	WRT_RECIPIENT_IGNORE = 2,
	WRT_RECIPIENT_IGNORE_ALL = 3
};

struct s_zc_guild_skillinfo
{
#pragma pack(push, 1)
	int16_t skill_id;
	int type;
	int16_t level;
	int16_t sp_cost;
	int16_t attack_range;
	char skill_name[MAX_SKILL_NAME_LENGTH];
	int8_t upgradeable;
#pragma pack(pop)
};

struct s_zc_ban_list
{
#pragma pack(push, 1)
	char name[MAX_UNIT_NAME_LENGTH];
	char reason[MAX_GUILD_LEAVE_REASON_STR_LENGTH];
#pragma pack(pop)
};

struct s_zcack_reqchange_members
{
#pragma pack(push, 1)
	int account_id;
	int char_id;
	int position_id;
#pragma pack(pop)
};

enum zc_ack_req_join_guild_type
{
	ZC_ACK_REQJOINGUILD_ALREADY_IN_GUILD = 0,
	ZC_ACK_REQJOINGUILD_OFFER_REJECTED = 1,
	ZC_ACK_REQJOINGUILD_OFFER_ACCEPTED = 2,
	ZC_ACK_REQJOINGUILD_GUILD_FULL = 3,
	ZC_ACK_REQJOINGUILD_OFFLINE_OR_NOTEXISTS = 4
};

enum zc_ack_disorganizeguild_result
{
	ZCACK_DISORGANIZEGUILD_SUCCESS = 0,
	ZCACK_DISORGANIZEGUILD_INVALID_KEY = 1,
	ZCACK_DISORGANIZEGUILD_STILL_HAS_MEMBERS = 2
};

enum zc_ack_req_hostile_guild_response_type
{
	ZCACK_REQHOSTILEGUILD_SUCCESS = 0,
	ZCACK_REQHOSTILEGUILD_LIMIT_REACHED = 1,
	ZCACK_REQHOSTILEGUILD_ALREADY_SET = 2,
	ZCACK_REQHOSTILEGUILD_GLOBALLY_DISABLED = 3
};

enum zc_ack_req_ally_guild_response_type
{
	ZCACK_REQALLYGUILD_ALREADY_ALLIED = 0,
	ZCACK_REQALLYGUILD_REJECTED_OFFER = 1,
	ZCACK_REQALLYGUILD_ACCEPTED_OFFER = 2,
	ZCACK_REQALLYGUILD_INVITEE_ALLIANCE_LIMIT_REACHED = 3,
	ZCACK_REQALLYGUILD_ALLIANCE_LIMIT_REACHED = 4,
	ZCACK_REQALLYGUILD_GLOBALLY_DISABLED = 5
};

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

struct s_cz_reg_change_guild_positioninfo
{
	int position_id;
	int mode;
	int ranking;
	int pay_rate;
	char name[MAX_GUILD_POSITION_NAME_LENGTH];
};

struct s_cz_req_change_memberpos
{
#pragma pack(push, 1)
	int account_id;
	int char_id;
	int position_id;
#pragma pack(pop)
};

enum cz_join_guild_response_type
{
	CZ_JOIN_GUILD_RESPONSE_REFUSE = 0,
	CZ_JOIN_GUILD_RESPONSE_ACCEPT = 1
};

enum cz_ally_guild_response_type
{
	CZ_ALLY_GUILD_RESPONSE_REFUSE = 0,
	CZ_ALLY_GUILD_RESPONSE_ACCEPT = 1
};

enum cz_req_delete_related_guild_relation_type
{
	CZ_REQDELETE_RELATEDGUILD_RELATION_ALLY = 0,
	CZ_REQDELETE_RELATEDGUILD_RELATION_ENEMY = 1
};

#endif /* HORIZON_ZONE_CLIENT_DEFINITIONS_HPP */