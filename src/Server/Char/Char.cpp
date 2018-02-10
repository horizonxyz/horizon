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

#include "Char.hpp"

#include "Core/Database/MySqlConnection.hpp"
#include "Core/Logging/Logger.hpp"
#include "Server/Char/Session/Session.hpp"
#include "Server/Char/SocketMgr/ClientSocketMgr.hpp"
#include "Server/Char/SocketMgr/InterSocketMgr.hpp"
#include "Server/Common/Models/Configuration/CharServerConfiguration.hpp"

#include <boost/asio.hpp>
#include <boost/make_shared.hpp>
#include <iostream>

using namespace std;

using boost::asio::ip::udp;

/**
 * CharMain Constructor
 */
Horizon::Char::CharMain::CharMain() : Server("Char", "config/", "char-server.conf")
{
	//
}

/**
 * CharMain Destructor
 */
Horizon::Char::CharMain::~CharMain()
{
	//
}

#define char_config_error(setting_name, default) \
	CharLog->error("No setting for '{}' in configuration file, defaulting to '{}'.", setting_name, default);

/**
 * Read /config/char-server.yaml
 * @return true on success false on failure.
 */
bool Horizon::Char::CharMain::ReadConfig()
{
	libconfig::Config cfg;
	std::string tmp_string;
	int tmp_value;
	std::string file_path = getGeneralConf().getConfigFilePath() + getGeneralConf().getConfigFileName();

	// Read the file. If there is an error, report it and exit.
	try {
		cfg.readFile(file_path.c_str());
	} catch(const libconfig::FileIOException &fioex) {
		CharLog->error("I/O error while reading file '{}'.", file_path);
		return false;
	} catch(const libconfig::ParseException &pex) {
		CharLog->error("Parse error at {}:{} - {}", pex.getFile(), pex.getLine(), pex.getError());
		return false;
	}

	/**
	 * Inter Server Settings
	 * @brief Definitions of the Inter-server networking configuration.
	 */
	const libconfig::Setting &inter_server = cfg.getRoot()["inter_server"];

	if (!inter_server.lookupValue("ip_address", tmp_string)) {
		char_config_error("inter_server.ip_address", "127.0.0.1");
		getNetworkConf().setInterServerIp("127.0.0.1");
	} else {
		getNetworkConf().setInterServerIp(tmp_string);
	}

	if (!inter_server.lookupValue("port", tmp_value)) {
		char_config_error("inter_server.port", 9998);
		getNetworkConf().setInterServerPort(9998);
	} else {
		getNetworkConf().setInterServerPort(tmp_value);
	}

	if (!inter_server.lookupValue("password", tmp_string)) {
		char_config_error("inter_server.password", "ABCDEF");
		getNetworkConf().setInterServerPassword(tmp_string);
	} else {
		getNetworkConf().setInterServerPassword(tmp_string);
	}

	CharLog->info("Outbound connections: Inter-Server configured to tcp://{}:{} {}",
				  getNetworkConf().getInterServerIp(), getNetworkConf().getInterServerPort(),
				  (getNetworkConf().getInterServerPassword().length()) ? "using password" : "not using password");

	const libconfig::Setting &new_character = cfg.getRoot()["new_character"];

	if (new_character.isGroup()) {
		if (new_character.lookupValue("start_map", tmp_string))
			getCharConfig().setStartMap(tmp_string);
		else
			char_config_error("start_map", "new_1-1");

		if (new_character.lookupValue("start_x", tmp_value))
			getCharConfig().setStartX(tmp_value);
		else
			char_config_error("start_x", 53);

		if (new_character.lookupValue("start_y", tmp_value))
			getCharConfig().setStartY(tmp_value);
		else
			char_config_error("start_y", 111);

		if (new_character.lookupValue("start_zeny", tmp_value))
			getCharConfig().setStartZeny(tmp_value);

		try {
			bool items_not_found = true;
			if ((items_not_found = new_character.exists("start_items"))) {
				const libconfig::Setting &items = new_character["start_items"];
				if (items.isGroup()) {
					for (int i = 0; i < items.getLength(); ++i) {
						const libconfig::Setting &item = items[i];
						std::string name = item.getName();
						int item_id = atoi(name.substr(2).c_str());
						int amount = item;
						getCharConfig().addStartItem(std::make_pair(item_id, amount));
					}
				}
			}

			if (items_not_found) {
				getCharConfig().addStartItem(std::make_pair(1201, 1));
				getCharConfig().addStartItem(std::make_pair(2301, 1));
			}
		} catch (libconfig::SettingTypeException &e) {
			CharLog->error("{}", e.what());
		}

	} else {
		CharLog->error("Unsupported setting type for 'new_character' configuration, expected group... using hard-coded defaults.");
	}

	if (cfg.lookupValue("character_deletion_time", tmp_value)) {
		getCharConfig().setCharacterDeletionTime(tmp_value);
	} else {
		char_config_error("character_deletion_time", 86400);
		getCharConfig().setCharacterDeletionTime(86400);
	}

	const libconfig::Setting &zone_server = cfg.getRoot()["zone_server"];

	if (zone_server.lookupValue("ip_address", tmp_string)) {
		getCharConfig().setZoneServerIP(tmp_string);
	} else {
		char_config_error("zone_server.ip_address", "127.0.0.1");
		getCharConfig().setZoneServerIP("127.0.0.1");
	}

	if (zone_server.lookupValue("port", tmp_value)) {
		getCharConfig().setZoneServerPort(tmp_value);
	} else {
		char_config_error("zone_server.port", 5121);
		getCharConfig().setZoneServerPort(5121);
	}

	/**
	 * Process Configuration that is common between servers.
	 */
	if (!ProcessCommonConfiguration(cfg))
		return false;

	CharLog->info("Done reading {} configurations in '{}'.", cfg.getRoot().getLength(), file_path);

	return true;
}

#undef char_config_error

/* Initialize Char-Server CLI Commands */
void Horizon::Char::CharMain::InitializeCLICommands()
{
	Server::InitializeCLICommands();
}

void Horizon::Char::CharMain::InitializeCore()
{
	/* Inter-server connection thread. */
	std::thread inter_conn_thread(std::bind(&CharMain::ConnectWithInterServer, this));

	Server::InitializeCore();

	inter_conn_thread.join();
}

/**
 * Connect with the Inter-server.
 */
void Horizon::Char::CharMain::ConnectWithInterServer()
{
	if (!getGeneralConf().isTestRun()) {
		try {
			InterSocktMgr->Start(INTER_SESSION_NAME, this, getNetworkConf().getInterServerIp(),
			                                      getNetworkConf().getInterServerPort(), 1);
		} catch (boost::system::system_error &e) {
			CharLog->error("{}", e.what());
		}
	}
}

/**
 * Signal handler for the Char-Server main thread.
 * @param[in|out] error   boost system error code.
 * @param[in]     signal  interrupt signal code
 */
void SignalHandler(const boost::system::error_code &error, int /*signal*/)
{
	if (!error) {
		CharServer->shutdown(SIGINT);
	}
}

/**
 * Main entry point of the char-server application.
 * @param argc
 * @param argv
 * @return integer of shutdown signal.
 */
int main(int argc, const char * argv[])
{
	/* Parse Command Line Arguments */
	if (argc > 1)
		CharServer->ParseExecArguments(argv, argc);

	/* Read Char Configuration */
	if (!CharServer->ReadConfig())
		exit(SIGTERM); // Stop process if the file can't be read.

	/* Core Signal Handler  */
	boost::asio::signal_set signals(*CharServer->getIOService(), SIGINT, SIGTERM);
	signals.async_wait(SignalHandler);

	/* Start Character Network */
	ClientSocktMgr->Start(*CharServer->getIOService(),
	        CharServer->getNetworkConf().getListenIp(),
            CharServer->getNetworkConf().getListenPort(),
            CharServer->getNetworkConf().getMaxThreads());

	/* Initialize the Common Core */
	CharServer->InitializeCore();

	/* Core Cleanup */
	CharLog->info("Server shutting down...");

	/* Stop Network */
	ClientSocktMgr->StopNetwork();
	InterSocktMgr->StopNetwork();

	signals.cancel();

	return CharServer->getGeneralConf().getShutdownSignal();
}
