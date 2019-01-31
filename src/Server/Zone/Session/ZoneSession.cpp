#include "ZoneSession.hpp"

#include "Server/Common/PacketBuffer.hpp"
#include "Server/Zone/Game/Entities/Unit/Player/Player.hpp"
#include "Server/Zone/Game/Map/MapManager.hpp"
#include "Server/Zone/Game/Map/Map.hpp"
#include "Server/Zone/PacketHandler/PacketHandler.hpp"
#include "Server/Zone/PacketHandler/PacketHandlerFactory.hpp"
#include "Server/Zone/PacketHandler/Versions/PacketHandler20141022.hpp"
#include "Server/Zone/Socket/ZoneSocket.hpp"
#include "Server/Common/Models/GameAccount.hpp"
#include "Server/Common/Models/SessionData.hpp"
#include "Server/Common/Models/Character/Character.hpp"
#include "Server/Zone/Zone.hpp"

using namespace Horizon::Zone;

ZoneSession::ZoneSession(std::shared_ptr<ZoneSocket> socket)
: Session(socket)
{
	//
}

ZoneSession::~ZoneSession()
{
	//
}

/* Packet Handler */
std::shared_ptr<PacketHandler> ZoneSession::get_packet_handler() { return _packet_handler; }
void ZoneSession::set_packet_handler(std::shared_ptr<PacketHandler> handler) { _packet_handler.swap(handler); }
/* Character */
std::shared_ptr<Character> ZoneSession::get_character() { return _character; }
void ZoneSession::set_character(std::shared_ptr<Character> character) { _character.swap(character); }
/* Game Account */
std::shared_ptr<GameAccount> ZoneSession::get_game_account() { return _game_account; }
void ZoneSession::set_game_account(std::shared_ptr<GameAccount> game_acc) { _game_account.swap(game_acc); }
/* Session Data */
std::shared_ptr<SessionData> ZoneSession::get_session_data() { return _session_data; }
void ZoneSession::set_session_data(std::shared_ptr<SessionData> session_data) { _session_data.swap(session_data); }
/* Player */
std::shared_ptr<Player> ZoneSession::get_player() { return _player; }
void ZoneSession::set_player(std::shared_ptr<Player> p) { _player.swap(p); }

/**
 * @brief Validate and handle the initial char-server connection (Packet CZ_ENTER)
 * @param[in] buf   Copied instance of the PacketBuffer.
 */
void ZoneSession::handle_new_connection(PacketBuffer &buf)
{
	switch (buf.getOpCode())
	{
		case PacketVer20141022::CZ_ENTER:
		{
			_packet_handler = PacketHandlerFactory::create_packet_handler(get_socket(), 20141022);
			break;
		}
		default:
			ZoneLog->info("New connection attempt from unknown client version. Packet Id: '{0:x}'.", buf.getOpCode());
	}
}

/**
 * Update loop for each Zone Session.
 * @thread called from main thread via the client manager.
 */
void ZoneSession::update(uint32_t diff)
{
	std::shared_ptr<PacketBuffer> buf;

	while ((buf = get_socket()->get_packet_recv_queue().try_pop())) {
		if (_packet_handler == nullptr)
			handle_new_connection(*buf);

		if (_packet_handler == nullptr) {
			ZoneLog->error("Packet handler was null!");
			return;
		}

		_packet_handler->handle_received_packet(*buf);
	}
}

void ZoneSession::cleanup_on_error()
{
	std::shared_ptr<Player> player = get_player();
	get_session_data()->remove(ZoneServer);

	if (get_character())
		get_character()->save(ZoneServer, CHAR_SAVE_ALL);

	if (player && player->get_map())
		MapMgr->remove_player_from_map(player->get_map()->get_name(), player);
}
