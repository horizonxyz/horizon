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

#include "EntityComponent.hpp"

#include "Server/Common/Configuration/Horizon.hpp"
#include "Server/Zone/Game/Entities/Player/Player.hpp"
#include "Server/Zone/Game/Entities/Entity.hpp"
#include "Server/Zone/Game/Entities/Battle/Combat.hpp"
#include "Server/Zone/Game/Entities/Traits/Status.hpp"
#include "Server/Zone/Definitions/ClientDefinitions.hpp"

#include "EntityDefinitions.hpp"

using namespace Horizon::Zone;

void EntityComponent::sync_definitions(std::shared_ptr<sol::state> state)
{
	state->create_named_table("EntitySize",
		"Small", (int) ESZ_SMALL,
		"Medium", (int) ESZ_MEDIUM,
		"Large", (int) ESZ_LARGE,
		"Max", (int) ESZ_MAX
	);

	state->create_named_table("Element",
		"Neutral", (int) ELE_NEUTRAL,
		"Water", (int) ELE_WATER,
		"Earth", (int) ELE_EARTH,
		"Fire", (int) ELE_FIRE,
		"Wind", (int) ELE_WIND,
		"Poison", (int) ELE_POISON,
		"Holy", (int) ELE_HOLY,
		"Dark", (int) ELE_DARK,
		"Ghost", (int) ELE_GHOST,
		"Undead", (int) ELE_UNDEAD,
		"Max", (int) ELE_MAX,
		"Weapon", (int) ELE_WEAPON,
		"Endowed", (int) ELE_ENDOWED,
		"Random", (int) ELE_RANDOM
	);

	state->create_named_table("EntityType",
		"Player", (int) ENTITY_MASK_PLAYER,
		"NPC", (int) ENTITY_MASK_NPC,
		"Item", (int) ENTITY_MASK_ITEM,
		"Skill", (int) ENTITY_MASK_SKILL,
		"Monster", (int) ENTITY_MASK_MONSTER,
		"Event", (int) ENTITY_MASK_EVENT,
		"Pet", (int) ENTITY_MASK_PET,
		"Homunculus", (int) ENTITY_MASK_HOMNUCLUS,
		"Mercenary", (int) ENTITY_MASK_MERCNARY,
		"Elemental", (int) ENTITY_MASK_ELEMENTAL
	);

	state->create_named_table("Directions",
		"North", (int) DIR_NORTH,
		"NorthWest", (int) DIR_NORTH_WEST,
		"West", (int) DIR_WEST,
		"SouthWest", (int) DIR_SOUTH_WEST,
		"South", (int) DIR_SOUTH,
		"SouthEast", (int) DIR_SOUTH_EAST,
		"East", (int) DIR_EAST,
		"NorthEast", (int) DIR_NORTH_EAST
	);


	state->create_named_table("Posture",
		"Standing", (int) POSTURE_STANDING,
		"Dead", (int) POSTURE_DEAD,
		"Sitting", (int) POSTURE_SITTING
	);

	state->create_named_table("Job",
		"Novice", (int) JOB_NOVICE,
		"Swordman", (int) JOB_SWORDMAN,
		"Magician", (int) JOB_MAGE,
		"Archer", (int) JOB_ARCHER,
		"Acolyte", (int) JOB_ACOLYTE,
		"Merchant", (int) JOB_MERCHANT,
		"Thief", (int) JOB_THIEF,
		"Knight", (int) JOB_KNIGHT,
		"Priest", (int) JOB_PRIEST,
		"Wizard", (int) JOB_WIZARD,
		"Blacksmith", (int) JOB_BLACKSMITH,
		"Hunter", (int) JOB_HUNTER,
		"Assassin", (int) JOB_ASSASSIN,
		//JOB_KNIGHT2
		"Crusader", (int) JOB_CRUSADER,
		"Monk", (int) JOB_MONK,
		"Sage", (int) JOB_SAGE,
		"Rogue", (int) JOB_ROGUE,
		"Alchemist", (int) JOB_ALCHEMIST,
		"Bard", (int) JOB_BARD,
		"Dancer", (int) JOB_DANCER,
		"Wedding", (int) JOB_WEDDING,
		"SuperNovice", (int) JOB_SUPER_NOVICE,
		"Gunslinger", (int) JOB_GUNSLINGER,
		"Ninja", (int) JOB_NINJA,
		"Xmas", (int) JOB_XMAS,
		"Summer", (int) JOB_SUMMER,
		//4000-
		"HighNovice", (int) JOB_NOVICE_HIGH,
		"HighSwordman", (int) JOB_SWORDMAN_HIGH,
		"HighMagician", (int) JOB_MAGE_HIGH,
		"HighArcher", (int) JOB_ARCHER_HIGH,
		"HighAcolyte", (int) JOB_ACOLYTE_HIGH,
		"HighMerchant", (int) JOB_MERCHANT_HIGH,
		"HighThief", (int) JOB_THIEF_HIGH,
		"LordKnight", (int) JOB_LORD_KNIGHT,
		"HighPriest", (int) JOB_HIGH_PRIEST,
		"HighWizard", (int) JOB_HIGH_WIZARD,
		"Whitesmith", (int) JOB_WHITESMITH,
		"Sniper", (int) JOB_SNIPER,
		"AssassinCross", (int) JOB_ASSASSIN_CROSS,
		"Paladin", (int) JOB_PALADIN,
		"Champion", (int) JOB_CHAMPION,
		"Professor", (int) JOB_PROFESSOR,
		"Stalker", (int) JOB_STALKER,
		"Creator", (int) JOB_CREATOR,
		"Clown", (int) JOB_CLOWN,
		"Gypsy", (int) JOB_GYPSY,
		"BabyNovice", (int) JOB_BABY_NOVICE,
		"BabySwordman", (int) JOB_BABY_SWORDMAN,
		"BabyMagician", (int) JOB_BABY_MAGE,
		"BabyArcher", (int) JOB_BABY_ARCHER,
		"BabyAcolyte", (int) JOB_BABY_ACOLYTE,
		"BabyMerchant", (int) JOB_BABY_MERCHANT,
		"BabyThief", (int) JOB_BABY_THIEF,
		"BabyKnight", (int) JOB_BABY_KNIGHT,
		"BabyPriest", (int) JOB_BABY_PRIEST,
		"BabyWizard", (int) JOB_BABY_WIZARD,
		"BabyBlacksmith", (int) JOB_BABY_BLACKSMITH,
		"BabyHunter", (int) JOB_BABY_HUNTER,
		"BabyAssassin", (int) JOB_BABY_ASSASSIN,
		"BabyCrusader", (int) JOB_BABY_CRUSADER,
		"BabyMonk", (int) JOB_BABY_MONK,
		"BabySage", (int) JOB_BABY_SAGE,
		"BabyRogue", (int) JOB_BABY_ROGUE,
		"BabyAlchemist", (int) JOB_BABY_ALCHEMIST,
		"BabyBard", (int) JOB_BABY_BARD,
		"BabyDancer", (int) JOB_BABY_DANCER,
		"SuperBaby", (int) JOB_SUPER_BABY,
		"Taekwon", (int) JOB_TAEKWON,
		"StarGladiator", (int) JOB_STAR_GLADIATOR,
		"SoulLinker", (int) JOB_SOUL_LINKER,
		"Gangsi", (int) JOB_GANGSI,
		"DeathKnight", (int) JOB_DEATH_KNIGHT,
		"DarkCollector", (int) JOB_DARK_COLLECTOR,
		// 4053-
		"RuneKnight", (int) JOB_RUNE_KNIGHT,
		"Warlock", (int) JOB_WARLOCK,
		"Ranger", (int) JOB_RANGER,
		"Archbishop", (int) JOB_ARCH_BISHOP,
		"Mechanic", (int) JOB_MECHANIC,
		"GuillotineCross", (int) JOB_GUILLOTINE_CROSS,
		"RuneKnightTrans", (int) JOB_RUNE_KNIGHT_T,
		"WarlockTrans", (int) JOB_WARLOCK_T,
		"RangerTrans", (int) JOB_RANGER_T,
		"ArchbishopTrans", (int) JOB_ARCH_BISHOP_T,
		"MechanicTrans", (int) JOB_MECHANIC_T,
		"GuillotineCrossTrans", (int) JOB_GUILLOTINE_CROSS_T,
		"RoyalGuard", (int) JOB_ROYAL_GUARD,
		"Sorcerer", (int) JOB_SORCERER,
		"Minstrel", (int) JOB_MINSTREL,
		"Wanderer", (int) JOB_WANDERER,
		"Sura", (int) JOB_SURA,
		"Genetic", (int) JOB_GENETIC,
		"ShadowChaser", (int) JOB_SHADOW_CHASER,
		"RoyalGuardTrans", (int) JOB_ROYAL_GUARD_T,
		"SorcererTrans", (int) JOB_SORCERER_T,
		"MinstrelTrans", (int) JOB_MINSTREL_T,
		"WandererTrans", (int) JOB_WANDERER_T,
		"SuraTrans", (int) JOB_SURA_T,
		"GeneticTrans", (int) JOB_GENETIC_T,
		"ShadowChaserTrans", (int) JOB_SHADOW_CHASER_T,
		//4088-4097
		"BabyRuneKnight", (int) JOB_BABY_RUNE_KNIGHT,
		"BabyWarlock", (int) JOB_BABY_WARLOCK,
		"BabyRanger", (int) JOB_BABY_RANGER,
		"BabyArchbishop", (int) JOB_BABY_ARCH_BISHOP,
		"BabyMechanic", (int) JOB_BABY_MECHANIC,
		"BabyGuillotineCross", (int) JOB_BABY_GUILLOTINE_CROSS,
		"BabyRoyalGuard", (int) JOB_BABY_ROYAL_GUARD,
		"BabySorcerer", (int) JOB_BABY_SORCERER,
		"BabyMinstrel", (int) JOB_BABY_MINSTREL,
		"BabyWanderer", (int) JOB_BABY_WANDERER,
		"BabySura", (int) JOB_BABY_SURA,
		"BabyGenetic", (int) JOB_BABY_GENETIC,
		"BabyShadowChaser", (int) JOB_BABY_SHADOW_CHASER,
		"SuperNoviceExpanded", (int) JOB_SUPER_NOVICE_E,
		"SuperBabyExpanded", (int) JOB_SUPER_BABY_E,
		"Kagerou", (int) JOB_KAGEROU,
		"Oboro", (int) JOB_OBORO,
		"Rebellion", (int) JOB_REBELLION,
		"Summoner", (int) JOB_SUMMONER,
		"StartBase", (int) JOB_BASE_START,
		"EndBase", (int) JOB_BASE_END,
		"Start_2_1", (int) JOB_2_1_START,
		"End_2_1", (int) JOB_2_1_END,
		"Start_2_2", (int) JOB_2_2_START,
		"End_2_2", (int) JOB_2_2_END,
		"StartTransBase", (int) JOB_TRANS_BASE_START,
		"EndTransBase", (int) JOB_TRANS_BASE_END,
		"Start_Trans_2_1", (int) JOB_TRANS_2_1_START,
		"End_Trans_2_1", (int) JOB_TRANS_2_1_END,
		"Start_Trans_2_2", (int) JOB_TRANS_2_2_START,
		"End_Trans_2_2", (int) JOB_TRANS_2_2_END,
		"Start_Baby_Base", (int) JOB_BABY_BASE_START,
		"End_Baby_Base", (int) JOB_BABY_BASE_END,
		"Start_Baby_2_1", (int) JOB_BABY_2_1_START,
		"End_Baby_2_1", (int) JOB_BABY_2_1_END,
		"Start_Baby_2_2", (int) JOB_BABY_2_2_START,
		"End_Baby_2_2", (int) JOB_BABY_2_2_END,
		"Start_3_1", (int) JOB_3_1_START,
		"End_3_1", (int) JOB_3_1_END,
		"Start_3_2", (int) JOB_3_2_START,
		"End_3_2", (int) JOB_3_2_END,
		"Start_Trans_3_1", (int) JOB_TRANS_3_1_START,
		"End_Trans_3_1", (int) JOB_TRANS_3_1_END,
		"Start_Trans_3_2", (int) JOB_TRANS_3_2_START,
		"End_Trans_3_2", (int) JOB_TRANS_3_2_END,
		"Start_Baby_3_1", (int) JOB_BABY_3_1_START,
		"End_Baby_3_1", (int) JOB_BABY_3_1_END,
		"Start_Baby_3_2", (int) JOB_BABY_3_2_START,
		"End_Baby_3_2", (int) JOB_BABY_3_2_END
	);

	state->create_named_table("JobMask",
		"Invalid", (int) JMASK_INVALID,
		"Novice", (int) JMASK_NOVICE,
		"Swordman", (int) JMASK_SWORDMAN,
		"Magician", (int) JMASK_MAGE,
		"Archer", (int) JMASK_ARCHER,
		"Acolyte", (int) JMASK_ACOLYTE,
		"Merchant", (int) JMASK_MERCHANT,
		"Thief", (int) JMASK_THIEF,
		"Gangsi", (int) JMASK_GANGSI,
		"Summoner", (int) JMASK_SUMMONER,
		"Taekwon", (int) JMASK_TAEKWON_BASE,
		"Gunslinger", (int) JMASK_GUNSLINGER_BASE,
		"Ninja", (int) JMASK_NINJA_BASE,
		"BaseClass", (int) JMASK_BASE,
		"Wedding", (int) JMASK_WEDDING,
		"2_1_Class", (int) JMASK_2_1,
		"2_2_Class", (int) JMASK_2_2,
		"BabyBaseClass", (int) JMASK_BABY_BASE,
		"Baby_1_1_Class", (int) JMASK_BABY_1_1,
		"Baby_1_2_Class", (int) JMASK_BABY_1_2,
		"Baby_2_1_Class", (int) JMASK_BABY_2_1,
		"Baby_2_2_Class", (int) JMASK_BABY_2_2,
		"TransBaseClass", (int) JMASK_TRANS_BASE,
		"Trans_1_1_Class", (int) JMASK_TRANS_1_1,
		"Trans_1_2_Class", (int) JMASK_TRANS_1_2,
		"Trans_2_1_Class", (int) JMASK_TRANS_2_1,
		"Trans_2_2_Class", (int) JMASK_TRANS_2_2,
		"3_1_Class", (int) JMASK_3_1,
		"3_2_Class", (int) JMASK_3_2,
		"Trans_3_1_Class", (int) JMASK_TRANS_3_1,
		"Trans_3_2_Class", (int) JMASK_TRANS_3_2,
		"Baby_3_1_Class", (int) JMASK_BABY_3_1,
		"Baby_3_3_Class", (int) JMASK_BABY_3_2,
		"ExpandedClass", (int) JMASK_EXPANDED,
		"ExpandedBabyClass", (int) JMASK_EXPANDED_BABY,
		"Expanded_2_1_Class", (int) JMASK_EXPANDED_2_1,
		"Expanded_2_2_Class", (int) JMASK_EXPANDED_2_2,

		"NormalClass", (int) JMASK_NORMAL,
		"BabyClass", (int) JMASK_BABY,
		"TransClass", (int) JMASK_TRANS,
		"ThirdClass", (int) JMASK_3,
		"TransThirdClass", (int) JMASK_TRANS_3,
		"BabyThirdClass", (int) JMASK_BABY_3,

		// 2-1 Jobs
		"Knight", (int) JMASK_KNIGHT,
		"Wizard", (int) JMASK_WIZARD,
		"Hunter", (int) JMASK_HUNTER,
		"Priest", (int) JMASK_PRIEST,
		"Blacksmith", (int) JMASK_BLACKSMITH,
		"Assassin", (int) JMASK_ASSASSIN,
		"DeathKnight", (int) JMASK_DEATH_KNIGHT,

		// 2-2 Jobs
		"Crusader", (int) JMASK_CRUSADER,
		"Sage", (int) JMASK_SAGE,
		"BardOrDancer", (int) JMASK_BARDDANCER,
		"Monk", (int) JMASK_MONK,
		"Alchemist", (int) JMASK_ALCHEMIST,
		"Rogue", (int) JMASK_ROGUE,
		"DarkCollector", (int) JMASK_DARK_COLLECTOR,

		//Trans Novice And Trans 1-1 J
		"HighNovice", (int) JMASK_NOVICE_HIGH,
		"HighSwordman", (int) JMASK_SWORDMAN_HIGH,
		"HighMagician", (int) JMASK_MAGE_HIGH,
		"HighArcher", (int) JMASK_ARCHER_HIGH,
		"HighAcolyte", (int) JMASK_ACOLYTE_HIGH,
		"HighMerchant", (int) JMASK_MERCHANT_HIGH,
		"HighThief", (int) JMASK_THIEF_HIGH,

		//Trans 2-1 Jobs
		"LordKnight", (int) JMASK_LORD_KNIGHT,
		"HighWizard", (int) JMASK_HIGH_WIZARD,
		"Sniper", (int) JMASK_SNIPER,
		"HighPriest", (int) JMASK_HIGH_PRIEST,
		"Whitesmith", (int) JMASK_WHITESMITH,
		"AssassinCross", (int) JMASK_ASSASSIN_CROSS,

		//Trans 2-2 Jobs
		"Paladin", (int) JMASK_PALADIN,
		"Professor", (int) JMASK_PROFESSOR,
		"ClownOrGypsy", (int) JMASK_CLOWNGYPSY,
		"Champion", (int) JMASK_CHAMPION,
		"Creator", (int) JMASK_CREATOR,
		"Stalker", (int) JMASK_STALKER,

		//Baby Novice And Baby 1-1 Job
		"BabyNovice", (int) JMASK_BABY_NOVICE,
		"BabySwordman", (int) JMASK_BABY_SWORDMAN,
		"BabyMage", (int) JMASK_BABY_MAGE,
		"BabyArcher", (int) JMASK_BABY_ARCHER,
		"BabyAcolyte", (int) JMASK_BABY_ACOLYTE,
		"BabyMerchant", (int) JMASK_BABY_MERCHANT,
		"BabyThief", (int) JMASK_BABY_THIEF,

		//Baby 2-1 Jobs
		"BabyKnight", (int) JMASK_BABY_KNIGHT,
		"BabyWizard", (int) JMASK_BABY_WIZARD,
		"BabyHunter", (int) JMASK_BABY_HUNTER,
		"BabyPriest", (int) JMASK_BABY_PRIEST,
		"BabyBlacksmith", (int) JMASK_BABY_BLACKSMITH,
		"BabyAssassin", (int) JMASK_BABY_ASSASSIN,

		//Baby 2-2 Jobs
		"BabyCrusader", (int) JMASK_BABY_CRUSADER,
		"BabySage", (int) JMASK_BABY_SAGE,
		"BabyBardOrDancer", (int) JMASK_BABY_BARDDANCER,
		"BabyMonk", (int) JMASK_BABY_MONK,
		"BabyAlchemist", (int) JMASK_BABY_ALCHEMIST,
		"BabyRogue", (int) JMASK_BABY_ROGUE,

		//3-1 Jobs
		"RuneKnight", (int) JMASK_RUNE_KNIGHT,
		"Warlock", (int) JMASK_WARLOCK,
		"Ranger", (int) JMASK_RANGER,
		"Archbishop", (int) JMASK_ARCH_BISHOP,
		"Mechanic", (int) JMASK_MECHANIC,
		"GuillotineCross", (int) JMASK_GUILLOTINE_CROSS,

		//3-2 Jobs
		"RoyalGuard", (int) JMASK_ROYAL_GUARD,
		"Sorcerer", (int) JMASK_SORCERER,
		"MinstrelOrWanderer", (int) JMASK_MINSTRELWANDERER,
		"Sura", (int) JMASK_SURA,
		"Genetic", (int) JMASK_GENETIC,
		"ShadowChaser", (int) JMASK_SHADOW_CHASER,

		//Trans 3-1 Jobs
		"RuneKnightTrans", (int) JMASK_RUNE_KNIGHT_T,
		"WarlockTrans", (int) JMASK_WARLOCK_T,
		"RangerTrans", (int) JMASK_RANGER_T,
		"ArchbishopTrans", (int) JMASK_ARCH_BISHOP_T,
		"MechanicTrans", (int) JMASK_MECHANIC_T,
		"GuillotineCrossTrans", (int) JMASK_GUILLOTINE_CROSS_T,

		//Trans 3-2 Jobs
		"RoyalGuardTrans", (int) JMASK_ROYAL_GUARD_T,
		"SorcererTrans", (int) JMASK_SORCERER_T,
		"MinstrelOrWandererTrans", (int) JMASK_MINSTRELWANDERER_T,
		"SuraTrans", (int) JMASK_SURA_T,
		"GeneticTrans", (int) JMASK_GENETIC_T,
		"ShadowChaserTrans", (int) JMASK_SHADOW_CHASER_T,

		//Baby 3-1 Jobs
		"BabyRuneKnight", (int) JMASK_BABY_RUNE_KNIGHT,
		"BabyWarlock", (int) JMASK_BABY_WARLOCK,
		"BabyRanger", (int) JMASK_BABY_RANGER,
		"BabyArchbishop", (int) JMASK_BABY_ARCH_BISHOP,
		"BabyMechanic", (int) JMASK_BABY_MECHANIC,
		"BabyGuillotineCross", (int) JMASK_BABY_GUILLOTINE_CROSS,

		//Baby 3-2 Jobs
		"BabyRoyalGuard", (int) JMASK_BABY_ROYAL_GUARD,
		"BabySorcerer", (int) JMASK_BABY_SORCERER,
		"BabyMinstrelOrWanderer", (int) JMASK_BABY_MINSTRELWANDERER,
		"BabySura", (int) JMASK_BABY_SURA,
		"BabyGenetic", (int) JMASK_BABY_GENETIC,
		"BabyShadowChaser", (int) JMASK_BABY_SHADOW_CHASER,

		// Expanded Jobs
		"Taekwon", (int) JMASK_TAEKWON,
		"StarGladiator", (int) JMASK_STAR_GLADIATOR,
		"SoulLinker", (int) JMASK_SOUL_LINKER,

		"SuperNovice", (int) JMASK_SUPER_NOVICE,
		"SuperNoviceExpanded", (int) JMASK_SUPER_NOVICE_E,

		"SuperBaby", (int) JMASK_SUPER_BABY,
		"SuperBabyExpanded", (int) JMASK_SUPER_BABY_E,

		"Gunslinger", (int) JMASK_GUNSLINGER,
		"Rebellion", (int) JMASK_REBELLION,

		"Ninja", (int) JMASK_NINJA,
		"KagerouOrOboro", (int) JMASK_KAGEROUOBORO,

		"All", (int) JMASK_ALL
	);
}

void EntityComponent::sync_data_types(std::shared_ptr<sol::state> state)
{
    state->new_usertype<Horizon::Zone::Traits::Status>("Status",
        "strength", &Horizon::Zone::Traits::Status::strength,
        "agility", &Horizon::Zone::Traits::Status::agility,
        "vitality", &Horizon::Zone::Traits::Status::vitality,
        "dexterity", &Horizon::Zone::Traits::Status::dexterity,
        "intelligence", &Horizon::Zone::Traits::Status::intelligence,
        "luck", &Horizon::Zone::Traits::Status::luck,
        "max_hp", &Horizon::Zone::Traits::Status::max_hp,
        "max_sp", &Horizon::Zone::Traits::Status::max_sp,
        "current_hp", &Horizon::Zone::Traits::Status::current_hp,
        "current_sp", &Horizon::Zone::Traits::Status::current_sp,
        "base_level", &Horizon::Zone::Traits::Status::base_level,
        "job_level", &Horizon::Zone::Traits::Status::job_level,
        "base_experience", &Horizon::Zone::Traits::Status::base_experience,
        "job_experience", &Horizon::Zone::Traits::Status::job_experience,
        "next_base_experience", &Horizon::Zone::Traits::Status::next_base_experience,
        "next_job_experience", &Horizon::Zone::Traits::Status::next_job_experience,
        "movement_speed", &Horizon::Zone::Traits::Status::movement_speed,
        "max_weight", &Horizon::Zone::Traits::Status::max_weight,
        "current_weight", &Horizon::Zone::Traits::Status::current_weight,
        "hair_color", &Horizon::Zone::Traits::Status::hair_color,
        "cloth_color", &Horizon::Zone::Traits::Status::cloth_color,
        "weapon_sprite", &Horizon::Zone::Traits::Status::weapon_sprite,
        "shield_sprite", &Horizon::Zone::Traits::Status::shield_sprite,
        "robe_sprite", &Horizon::Zone::Traits::Status::robe_sprite,
        "head_top_sprite", &Horizon::Zone::Traits::Status::head_top_sprite,
        "head_mid_sprite", &Horizon::Zone::Traits::Status::head_mid_sprite,
        "head_bottom_sprite", &Horizon::Zone::Traits::Status::head_bottom_sprite,
        "hair_style", &Horizon::Zone::Traits::Status::hair_style,
        "body_style", &Horizon::Zone::Traits::Status::body_style,
        "status_point", &Horizon::Zone::Traits::Status::status_point,
        "skill_point", &Horizon::Zone::Traits::Status::skill_point
    );

		state->new_usertype<Combat>("Combat",
			sol::constructors<Combat(std::shared_ptr<Entity>, std::shared_ptr<Entity>)>(),
			"source", &Combat::entity,
			"target", &Combat::target
		);

    state->new_usertype<Horizon::Zone::Traits::BaseLevel>("BaseLevel",
        "add", &Horizon::Zone::Traits::BaseLevel::add_base,
        "sub", &Horizon::Zone::Traits::BaseLevel::sub_base,
        "get", &Horizon::Zone::Traits::BaseLevel::get_base,
        "set", &Horizon::Zone::Traits::BaseLevel::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::JobLevel>("JobLevel",
        "add", &Horizon::Zone::Traits::JobLevel::add_base,
        "sub", &Horizon::Zone::Traits::JobLevel::sub_base,
        "get", &Horizon::Zone::Traits::JobLevel::get_base,
        "set", &Horizon::Zone::Traits::JobLevel::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::MaxHP>("MaxHP",
        "add", &Horizon::Zone::Traits::MaxHP::add_base,
        "sub", &Horizon::Zone::Traits::MaxHP::sub_base,
        "get", &Horizon::Zone::Traits::MaxHP::get_base,
        "set", &Horizon::Zone::Traits::MaxHP::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::MaxSP>("MaxSP",
        "add", &Horizon::Zone::Traits::MaxSP::add_base,
        "sub", &Horizon::Zone::Traits::MaxSP::sub_base,
        "get", &Horizon::Zone::Traits::MaxSP::get_base,
        "set", &Horizon::Zone::Traits::MaxSP::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::CurrentHP>("CurrentHP",
        "add", &Horizon::Zone::Traits::CurrentHP::add_base,
        "sub", &Horizon::Zone::Traits::CurrentHP::sub_base,
        "get", &Horizon::Zone::Traits::CurrentHP::get_base,
        "set", &Horizon::Zone::Traits::CurrentHP::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::CurrentSP>("CurrentSP",
        "add", &Horizon::Zone::Traits::CurrentSP::add_base,
        "sub", &Horizon::Zone::Traits::CurrentSP::sub_base,
        "get", &Horizon::Zone::Traits::CurrentSP::get_base,
        "set", &Horizon::Zone::Traits::CurrentSP::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::MovementSpeed>("MovementSpeed",
        "add", &Horizon::Zone::Traits::MovementSpeed::add_base,
        "sub", &Horizon::Zone::Traits::MovementSpeed::sub_base,
        "get", &Horizon::Zone::Traits::MovementSpeed::get_base,
        "set", &Horizon::Zone::Traits::MovementSpeed::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::MaxWeight>("MaxWeight",
        "add", &Horizon::Zone::Traits::MaxWeight::add_base,
        "sub", &Horizon::Zone::Traits::MaxWeight::sub_base,
        "get", &Horizon::Zone::Traits::MaxWeight::get_base,
        "set", &Horizon::Zone::Traits::MaxWeight::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::CurrentWeight>("CurrentWeight",
        "add", &Horizon::Zone::Traits::CurrentWeight::add_base,
        "sub", &Horizon::Zone::Traits::CurrentWeight::sub_base,
        "get", &Horizon::Zone::Traits::CurrentWeight::get_base,
        "set", &Horizon::Zone::Traits::CurrentWeight::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::Strength>("Strength",
        "add", &Horizon::Zone::Traits::Strength::add_base,
        "sub", &Horizon::Zone::Traits::Strength::sub_base,
        "get", &Horizon::Zone::Traits::Strength::get_base,
        "set", &Horizon::Zone::Traits::Strength::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::Agility>("Agility",
        "add", &Horizon::Zone::Traits::Agility::add_base,
        "sub", &Horizon::Zone::Traits::Agility::sub_base,
        "get", &Horizon::Zone::Traits::Agility::get_base,
        "set", &Horizon::Zone::Traits::Agility::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::Vitality>("Vitality",
        "add", &Horizon::Zone::Traits::Vitality::add_base,
        "sub", &Horizon::Zone::Traits::Vitality::sub_base,
        "get", &Horizon::Zone::Traits::Vitality::get_base,
        "set", &Horizon::Zone::Traits::Vitality::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::Intelligence>("Intelligence",
        "add", &Horizon::Zone::Traits::Intelligence::add_base,
        "sub", &Horizon::Zone::Traits::Intelligence::sub_base,
        "get", &Horizon::Zone::Traits::Intelligence::get_base,
        "set", &Horizon::Zone::Traits::Intelligence::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::Dexterity>("Dexterity",
        "add", &Horizon::Zone::Traits::Dexterity::add_base,
        "sub", &Horizon::Zone::Traits::Dexterity::sub_base,
        "get", &Horizon::Zone::Traits::Dexterity::get_base,
        "set", &Horizon::Zone::Traits::Dexterity::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::Luck>("Luck",
        "add", &Horizon::Zone::Traits::Luck::add_base,
        "sub", &Horizon::Zone::Traits::Luck::sub_base,
        "get", &Horizon::Zone::Traits::Luck::get_base,
        "set", &Horizon::Zone::Traits::Luck::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::BaseExperience>("BaseExperience",
        "add", &Horizon::Zone::Traits::BaseExperience::add_base,
        "sub", &Horizon::Zone::Traits::BaseExperience::sub_base,
        "get", &Horizon::Zone::Traits::BaseExperience::get_base,
        "set", &Horizon::Zone::Traits::BaseExperience::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::JobExperience>("JobExperience",
        "add", &Horizon::Zone::Traits::JobExperience::add_base,
        "sub", &Horizon::Zone::Traits::JobExperience::sub_base,
        "get", &Horizon::Zone::Traits::JobExperience::get_base,
        "set", &Horizon::Zone::Traits::JobExperience::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::NextBaseExperience>("NextBaseExperience",
        "add", &Horizon::Zone::Traits::NextBaseExperience::add_base,
        "sub", &Horizon::Zone::Traits::NextBaseExperience::sub_base,
        "get", &Horizon::Zone::Traits::NextBaseExperience::get_base,
        "set", &Horizon::Zone::Traits::NextBaseExperience::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::NextJobExperience>("NextJobExperience",
        "add", &Horizon::Zone::Traits::NextJobExperience::add_base,
        "sub", &Horizon::Zone::Traits::NextJobExperience::sub_base,
        "get", &Horizon::Zone::Traits::NextJobExperience::get_base,
        "set", &Horizon::Zone::Traits::NextJobExperience::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::StatusPoint>("StatusPoint",
        "add", &Horizon::Zone::Traits::StatusPoint::add_base,
        "sub", &Horizon::Zone::Traits::StatusPoint::sub_base,
        "get", &Horizon::Zone::Traits::StatusPoint::get_base,
        "set", &Horizon::Zone::Traits::StatusPoint::set_base
    );
    state->new_usertype<Horizon::Zone::Traits::SkillPoint>("SkillPoint",
        "add", &Horizon::Zone::Traits::SkillPoint::add_base,
        "sub", &Horizon::Zone::Traits::SkillPoint::sub_base,
        "get", &Horizon::Zone::Traits::SkillPoint::get_base,
        "set", &Horizon::Zone::Traits::SkillPoint::set_base
    );
	state->new_usertype<Entity>("Entity",
		"dest_coords", &Entity::dest_coords,
		"walk_to_coordinates", &Entity::walk_to_coordinates,
		"is_walking", &Entity::is_walking,
		"stop_movement", &Entity::stop_movement,
		"guid", &Entity::guid,
		"job_id", &Entity::job_id,
		"posture", &Entity::posture,
		"set_posture", &Entity::set_posture,
		"name", &Entity::name,
		"direction", &Entity::direction,
		"status", &Entity::status,
		"force_movement_stop_internal", &Entity::force_movement_stop_internal,
		"map", &Entity::map,
		"type", &Entity::type,
		"map_coords", &Entity::map_coords,
		"grid_coords", &Entity::grid_coords,
		"is_in_range_of", &Entity::is_in_range_of,
		"notify_nearby_players_of_existence", &Entity::notify_nearby_players_of_existence,
		"notify_nearby_players_of_movement", &Entity::notify_nearby_players_of_movement,
		"notify_nearby_players_of_spawn", &Entity::notify_nearby_players_of_spawn,
		"get_nearby_entity", &Entity::get_nearby_entity,
		"status_effect_start", &Entity::status_effect_start,
		"status_effect_end", &Entity::status_effect_end,
		"get_walk_path", &Entity::get_walk_path,
		"cast_skill_at_target", &Entity::notify_nearby_players_of_skill_use,
		"show_skill_damage", &Entity::notify_nearby_players_of_skill_damage,
		"is_dead", &Entity::is_dead,
		"combat", &Entity::combat
	);
}

void EntityComponent::sync_functions(std::shared_ptr<sol::state> state)
{
}