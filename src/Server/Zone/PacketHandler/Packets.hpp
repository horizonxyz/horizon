/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 * Copyright (c) 2018 Horizon Dev Team.
 *
 * Base Author - Sagun Khosla. (sagunxp@gmail.com)
 *
 * Under a proprietary license this file is not for use
 * or viewing without permission.
 **************************************************/

#ifndef HORIZON_ZONE_PACKETS_HPP
#define HORIZON_ZONE_PACKETS_HPP

#include "Server/Common/Horizon.hpp"
#include "Server/Common/PacketBuffer.hpp"
#include "Server/Zone/Game/Definitions/EntityDefinitions.hpp"

namespace Horizon
{
namespace Zone
{
enum packets
{
	/* ZC */
	ZC_ERROR                      = 0x006a,
	ZC_RESTART_ACK                = 0x00b3,
	ZC_NPCACK_MAPMOVE             = 0x0091,
	ZC_NOTIFY_TIME                = 0x007f,
	ZC_ACK_REQNAME                = 0x0095,
	ZC_NOTIFY_UNITMOVE            = 0x0086,
	ZC_NOTIFY_PLAYERMOVE          = 0x0087,
	ZC_STOPMOVE                   = 0x0088,
	ZC_PAR_CHANGE                 = 0x00b0,
	ZC_SAY_DIALOG                 = 0x00b4,
	ZC_WAIT_DIALOG                = 0x00b5,
	ZC_CLOSE_DIALOG               = 0x00b6,
	ZC_MENU_LIST                  = 0x00b7,
	ZC_INITIAL_STATUS             = 0x00bd,
	ZC_UPDATE_MAPINFO             = 0x0192,
	ZC_NOTIFY_GROUNDSKILL         = 0x0117,
	ZC_OPEN_EDITDLG               = 0x0142,
	ZC_ACK_GUILD_MENUINTERFACE    = 0x014e,
	ZC_ACK_REQ_DISCONNECT         = 0x018b,
	ZC_ACK_REQNAMEALL             = 0x0195,
	ZC_OPEN_EDITDLGSTR            = 0x01d4,
	ZC_ACCOUNT_ID                 = 0x0283,
	ZC_SPAWN_UNIT                 = 0x07f8,
	ZC_NOTIFY_STANDENTRY11        = 0x07f9,
	ZC_ACCEPT_CONNECTION          = 0x0a18,
	ZC_NOTIFY_STANDENTRY10        = 0x09dd,
	ZC_ACK_SCHEDULER_CASHITEM     = 0x08ca,
	/* CZ */
	CZ_NOTIFY_ACTORINIT           = 0x007d,
	CZ_RESTART                    = 0x00b2,
	CZ_CHOOSE_MENU                = 0x00b8,
	CZ_REQ_NEXT_SCRIPT            = 0x00b9,
	CZ_INPUT_EDITDLG              = 0x0143,
	CZ_CLOSE_DIALOG               = 0x0146,
	CZ_REQ_GUILD_MENUINTERFACE    = 0x014d,
	CZ_REQ_GUILD_MENU             = 0x014f,
	CZ_REQ_DISCONNECT             = 0x018a,
	CZ_INPUT_EDITDLGSTR           = 0x01d5,
	CZ_LOGIN_TIMESTAMP            = 0x044a,
	CZ_REQ_SCHEDULER_CASHITEM     = 0x08c9,
	CZ_CHANGE_DIRECTION           = 0x009b,
	CZ_CHANGE_DIRECTION2          = 0x0361,
};

#pragma pack(push, 1)
struct PACKET_CZ_ENTER : public Packet
{
	PACKET_CZ_ENTER(uint16_t id) : Packet(id) { }
	uint32_t account_id{0};
	uint32_t char_id{0};
	uint32_t auth_code{0};
	uint32_t client_time{0};
	uint8_t gender{0};
};
struct PACKET_CZ_REQUEST_ACT : public Packet
{
	PACKET_CZ_REQUEST_ACT(uint16_t id) : Packet(id) { }

	uint32_t target_guid{0};
	uint8_t action{0};
};
struct PACKET_CZ_REQUEST_MOVE : public Packet
{
	PACKET_CZ_REQUEST_MOVE(uint16_t id) : Packet(id) { }

	uint8_t packed_destination[3]{0};
};

enum zone_server_reject_types : uint8_t
{
	ZONE_SERV_ERROR_REJECT = 3,
};

struct PACKET_ZC_ERROR : public Packet
{
	PACKET_ZC_ERROR() : Packet(ZC_ERROR) { }

	uint8_t error{ZONE_SERV_ERROR_REJECT};
};

struct PACKET_ZC_ACCOUNT_ID : public Packet
{
	PACKET_ZC_ACCOUNT_ID() : Packet(ZC_ACCOUNT_ID) { }

	uint32_t account_id{0};
};

struct PACKET_ZC_ACCEPT_CONNECTION : public Packet
{
	PACKET_ZC_ACCEPT_CONNECTION() : Packet(ZC_ACCEPT_CONNECTION) { }

	uint32_t start_time{0};
	int8_t packed_position[3]{0};
	uint8_t x_size{0};
	uint8_t y_size{0};
	uint16_t font{0};
	uint8_t gender{0};
};

struct PACKET_ZC_NOTIFY_UNITMOVE : public Packet
{
	PACKET_ZC_NOTIFY_UNITMOVE() : Packet(ZC_NOTIFY_UNITMOVE) { }

	uint32_t guid{0};
	int8_t packed_pos[6]{0};
	uint32_t timestamp{0};
};

struct PACKET_ZC_NOTIFY_PLAYERMOVE : public Packet
{
	PACKET_ZC_NOTIFY_PLAYERMOVE() : Packet(ZC_NOTIFY_PLAYERMOVE) { }

	uint32_t timestamp{0};
	int8_t packed_pos[6]{0};
};

struct PACKET_ZC_STOPMOVE : public Packet
{
	PACKET_ZC_STOPMOVE() : Packet(ZC_STOPMOVE) { }

	uint32_t guid{0};
	uint16_t x{0};
	uint16_t y{0};
};

struct PACKET_ZC_NPCACK_MAPMOVE : public Packet
{
	PACKET_ZC_NPCACK_MAPMOVE() : Packet(ZC_NPCACK_MAPMOVE) { }

	char map_name[MAP_NAME_LENGTH_EXT]{0};
	uint16_t x{0};
	uint16_t y{0};
};

struct PACKET_ZC_PAR_CHANGE : public Packet
{
	PACKET_ZC_PAR_CHANGE() : Packet(ZC_PAR_CHANGE) { }

	uint16_t type{0};
	uint32_t value{0};
};

struct PACKET_ZC_SAY_DIALOG : public Packet
{
	PACKET_ZC_SAY_DIALOG() : Packet(ZC_SAY_DIALOG) { }

	uint16_t packet_length{0};
	uint32_t guid{0};
	/* char message[] */
};

struct PACKET_ZC_WAIT_DIALOG : public Packet
{
	PACKET_ZC_WAIT_DIALOG() : Packet(ZC_WAIT_DIALOG) { }

	uint32_t guid{0};
};

struct PACKET_ZC_CLOSE_DIALOG : public Packet
{
	PACKET_ZC_CLOSE_DIALOG() : Packet(ZC_CLOSE_DIALOG) { }

	uint32_t guid{0};
};

struct PACKET_ZC_MENU_LIST : public Packet
{
	PACKET_ZC_MENU_LIST() : Packet(ZC_MENU_LIST) { }

	uint16_t packet_length{0};
	uint32_t guid{0};
	/*char menu_items[]*/
};

struct PACKET_ZC_OPEN_EDITDLG : public Packet
{
	PACKET_ZC_OPEN_EDITDLG() : Packet(ZC_OPEN_EDITDLG) { }

	uint32_t guid{0};
};

struct PACKET_ZC_OPEN_EDITDLGSTR : public Packet
{
	PACKET_ZC_OPEN_EDITDLGSTR() : Packet(ZC_OPEN_EDITDLGSTR) { }

	uint32_t guid{0};
};

struct PACKET_ZC_INITIAL_STATUS : public Packet
{
	PACKET_ZC_INITIAL_STATUS() : Packet(ZC_INITIAL_STATUS) { }

	uint16_t status_points{0};
	uint8_t strength{1};
	uint8_t strength_req_stats{1};
	uint8_t agility{1};
	uint8_t agility_req_stats{1};
	uint8_t vitality{1};
	uint8_t vitality_req_stats{1};
	uint8_t intelligence{1};
	uint8_t intelligence_req_stats{1};
	uint8_t dexterity{1};
	uint8_t dexterity_req_stats{1};
	uint8_t luck{1};
	uint8_t luck_req_stats{1};
	uint16_t left_hand_atk{1};
	uint16_t right_hand_atk{1};
	uint16_t right_hand_matk{1};
	uint16_t left_hand_matk{1};
	uint16_t soft_defense{1};
	uint16_t hard_defense{1};
	uint16_t soft_magic_defense{1};
	uint16_t hard_magic_defense{1};
	uint16_t hit{1};
	uint16_t flee{1};
	uint16_t perfect_dodge{1};
	uint16_t critical{1};
	uint16_t attack_speed{0};
	uint16_t plus_aspd{0}; // always 0 apparently.
};

struct PACKET_ZC_SPAWN_UNIT : public Packet
{
	PACKET_ZC_SPAWN_UNIT() : Packet(ZC_SPAWN_UNIT) { }

	int16_t packet_length{sizeof(PACKET_ZC_SPAWN_UNIT)};
	uint8_t unit_type{ENTITY_PLAYER};
	uint32_t account_id{0};
	uint32_t guid{0};
	int16_t walk_speed{150};
	int16_t body_state{0};
	int16_t health_state{0};
	int32_t effect_state{0};
	int16_t job{0};
	int16_t head{0};
	int32_t weapon{0};
	int16_t accessory{0};
	int16_t accessory2{0};
	int16_t accessory3{0};
	int16_t hair_color{0};
	int16_t cloth_color{0};
	int16_t head_direction{0};
	uint32_t guild_id{0};
	int16_t guild_emblem_version{0};
	int16_t honor{0};
	int32_t virtue{0};
	uint8_t in_pk_mode{0};
	uint8_t gender{0};
	uint8_t position[3]{0};
	uint8_t x_size{5}; // unused
	uint8_t y_size{5}; // unused
	int16_t base_level{0};
	int16_t font{0};
	int32_t max_hp{0};
	int32_t hp{0};
	uint8_t is_boss{0};
	char name[MAX_UNIT_NAME_LENGTH]{0};
};

struct PACKET_ZC_UPDATE_MAPINFO : public Packet
{
	PACKET_ZC_UPDATE_MAPINFO() : Packet(ZC_UPDATE_MAPINFO) { }

	uint16_t x{0};
	uint16_t y{0};
	uint16_t type{0}; // 5 = icewall
	char map_name[MAP_NAME_LENGTH_EXT]{0};
};

struct PACKET_ZC_NOTIFY_GROUNDSKILL : public Packet
{
	PACKET_ZC_NOTIFY_GROUNDSKILL() : Packet(ZC_NOTIFY_GROUNDSKILL) { }

	uint16_t skill_id{0};
	uint32_t guid{0};
	uint16_t level{0};
	uint16_t x{0};
	uint16_t y{0};
	uint32_t duration{0};
};

struct PACKET_ZC_ACK_REQNAME : public Packet
{
	PACKET_ZC_ACK_REQNAME() : Packet(ZC_ACK_REQNAME) { }

	uint32_t guid{0};
	char name[MAX_UNIT_NAME_LENGTH]{0};
};

struct PACKET_ZC_NOTIFY_TIME : public Packet
{
	PACKET_ZC_NOTIFY_TIME() : Packet(ZC_NOTIFY_TIME) { }

	uint32_t timestamp{0};
};

struct PACKET_ZC_ACK_REQNAMEALL : public Packet
{
	PACKET_ZC_ACK_REQNAMEALL() : Packet(ZC_ACK_REQNAMEALL) { }

	uint32_t guid{0};
	char name[MAX_UNIT_NAME_LENGTH]{0};
	char party_name[MAX_PARTY_NAME_LENGTH]{0};
	char guild_name[MAX_GUILD_NAME_LENGTH]{0};
	char guild_position_name[MAX_GUILD_POSITION_NAME_LENGTH]{0};
};

enum zc_ack_guild_menuinterface_mask_types
{
	GMIF_BASIC_INFO     = 0x00,
	GMIF_MEMBER_MANAGER = 0x01,
	GMIF_POSITIONS      = 0x02,
	GMIF_SKILLS         = 0x04,
	GMIF_EXPULSION_LIST = 0x10,
	GMIF_ALLGUILDLIST   = 0x40,
	GMIF_NOTICE         = 0x80,
	GMIF_MEMBER         = GMIF_ALLGUILDLIST | GMIF_EXPULSION_LIST | GMIF_SKILLS | GMIF_POSITIONS | GMIF_MEMBER_MANAGER,
	GMIF_MASTER         = GMIF_NOTICE | GMIF_MEMBER,
};

struct PACKET_ZC_ACK_GUILD_MENUINTERFACE : public Packet
{
	PACKET_ZC_ACK_GUILD_MENUINTERFACE() : Packet(ZC_ACK_GUILD_MENUINTERFACE) { }

	uint32_t menu_interface_mask{0};
};

struct PACKET_ZC_RESTART_ACK : public Packet
{
	PACKET_ZC_RESTART_ACK() : Packet(ZC_RESTART_ACK) { }

	uint8_t type{0}; // 1 = disconnecting / char-select
};

struct PACKET_ZC_ACK_REQ_DISCONNECT : public Packet
{
	PACKET_ZC_ACK_REQ_DISCONNECT() : Packet(ZC_ACK_REQ_DISCONNECT) { }

	uint16_t type{0}; // 0 =  allowed, 1 = not allowed (wait 10 seconds)
};

struct PACKET_ZC_NOTIFY_STANDENTRY10 : public Packet
{
	PACKET_ZC_NOTIFY_STANDENTRY10(uint16_t packet_id) : Packet(packet_id) { }

	int16_t packet_length{sizeof(PACKET_ZC_NOTIFY_STANDENTRY10)};
	uint8_t unit_type{ENTITY_PLAYER};
	uint32_t account_id{0};
	uint32_t guid{0};
	int16_t speed{150};
	int16_t body_state{0};
	int16_t health_state{0};
	int32_t effectState{0};
	int16_t job{0};
	uint16_t hair_style_id{0};
	uint32_t weapon_id{0};
	uint16_t headgear_bottom_id{0};
	uint16_t headgear_top_id{0};
	uint16_t headgear_mid_id{0};
	int16_t hair_color_id{0};
	int16_t cloth_color_id{0};
	int16_t head_direction{0};
	uint16_t robe{0};
	uint32_t guild_id{0};
	int16_t guild_emblem_version{0};
	int16_t honor{0};
	int32_t virtue{0};
	uint8_t in_pk_mode{0};
	uint8_t gender{0};
	int8_t position[3];
	uint8_t x_size{0};
	uint8_t y_size{0};
	uint8_t posture{0};
	int16_t base_level{0};
	int16_t font{0};
	int32_t max_hp{0};
	int32_t hp{0};
	uint8_t is_boss{0};
	char name[MAX_UNIT_NAME_LENGTH]{0};
};

/**
 * CZ
 */
struct PACKET_CZ_LOGIN_TIMESTAMP : public Packet
{
	PACKET_CZ_LOGIN_TIMESTAMP() : Packet(CZ_LOGIN_TIMESTAMP) { }

	uint32_t timestamp{0};
};

struct PACKET_CZ_REQUEST_TIME : public Packet
{
	PACKET_CZ_REQUEST_TIME(uint16_t packet_id) : Packet(packet_id) { }

	uint32_t timestamp{0};
};

struct PACKET_CZ_RESTART : public Packet
{
	PACKET_CZ_RESTART(uint16_t packet_id) : Packet(packet_id) { }

	uint8_t type{0}; // 0 = Respawn, 1 = Char-select.
};

struct PACKET_CZ_REQNAME : public Packet
{
	PACKET_CZ_REQNAME(uint16_t packet_id) : Packet(packet_id) { }

	uint32_t guid{0};
};

struct PACKET_CZ_REQ_GUILD_MENUINTERFACE : public Packet
{
	PACKET_CZ_REQ_GUILD_MENUINTERFACE() : Packet(CZ_REQ_GUILD_MENUINTERFACE) { }
};

enum cz_req_guild_menu_types
{
	CZ_REQ_GUILD_BASIC_INFO     = 0,
	CZ_REQ_GUILD_MEMBER_MANAGER = 1,
	CZ_REQ_GUILD_POSITIONS      = 2,
	CZ_REQ_GUILD_SKILLS         = 3,
	CZ_REQ_GUILD_EXPULSION_LIST = 4,
	CZ_REQ_GM_ALLGUILDLIST      = 5,
	CZ_REQ_GUILD_NOTICE         = 6
};

struct PACKET_CZ_REQ_GUILD_MENU : public Packet
{
	PACKET_CZ_REQ_GUILD_MENU() : Packet(CZ_REQ_GUILD_MENU) { }

	cz_req_guild_menu_types info_type{CZ_REQ_GUILD_BASIC_INFO};
};

struct PACKET_CZ_REQ_DISCONNECT : public Packet
{
	PACKET_CZ_REQ_DISCONNECT() : Packet(CZ_REQ_DISCONNECT) { }

	uint16_t type{0};
};

struct PACKET_CZ_CHOOSE_MENU : public Packet
{
	PACKET_CZ_CHOOSE_MENU() : Packet(CZ_CHOOSE_MENU) { }

	uint32_t guid{0};
	// If there were more than 254 items in the list,
	// choice overflows to choice%256.
	uint8_t choice{0};
};

struct PACKET_CZ_REQ_NEXT_SCRIPT : public Packet
{
	PACKET_CZ_REQ_NEXT_SCRIPT() : Packet(CZ_REQ_NEXT_SCRIPT) { }

	uint32_t guid{0};
};

struct PACKET_CZ_INPUT_EDITDLG : public Packet
{
	PACKET_CZ_INPUT_EDITDLG() : Packet(CZ_INPUT_EDITDLG) { }

	uint32_t guid{0};
	uint32_t value{0};
};

struct PACKET_CZ_INPUT_EDITDLGSTR : public Packet
{
	PACKET_CZ_INPUT_EDITDLGSTR() : Packet(CZ_INPUT_EDITDLGSTR) { }

	uint16_t packet_length{0};
	uint32_t guid{0};
	/* char message[]*/
};

struct PACKET_CZ_CLOSE_DIALOG : public Packet
{
	PACKET_CZ_CLOSE_DIALOG() : Packet(CZ_CLOSE_DIALOG) { }

	uint32_t guid{0};
};

struct PACKET_CZ_NOTIFY_ACTORINIT : public Packet
{
	PACKET_CZ_NOTIFY_ACTORINIT() : Packet(CZ_NOTIFY_ACTORINIT) { }
};

struct PACKET_CZ_REQ_SCHEDULER_CASHITEM : public Packet
{
	PACKET_CZ_REQ_SCHEDULER_CASHITEM() : Packet(CZ_REQ_SCHEDULER_CASHITEM) { }
};

struct PACKET_CZ_CHANGE_DIRECTION : public Packet
{
	PACKET_CZ_CHANGE_DIRECTION(uint16_t packet_id = CZ_CHANGE_DIRECTION) : Packet(packet_id) { }

	uint8_t head_dir{0};
	uint8_t body_dir{0};
};

struct PACKET_CZ_CHANGE_DIRECTION2 : public Packet
{
	PACKET_CZ_CHANGE_DIRECTION2() : Packet(CZ_CHANGE_DIRECTION2) { }

	uint8_t head_dir{0};
	uint8_t body_dir{0};
};
#pragma pack(pop)
}
}


#endif // HORIZON_ZONE_PACKETS_HPP
