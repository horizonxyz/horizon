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

#include "MonsterComponent.hpp"

#include "Server/Common/Configuration/Horizon.hpp"
#include "Server/Zone/Game/Entities/Creature/Hostile/Monster.hpp"
#include "Server/Zone/Game/Map/Map.hpp"
#include "Server/Zone/Game/StaticDB/MonsterDB.hpp"

using namespace Horizon::Zone;
using namespace Horizon::Zone::Entities;

void MonsterComponent::sync_definitions(std::shared_ptr<sol::state> state)
{
	state->create_named_table("MonsterRace",
		"Formless", (int) MONSTER_RACE_FORMLESS,
		"Undead", (int) MONSTER_RACE_UNDEAD,
		"Brute", (int) MONSTER_RACE_BRUTE,
		"Plant", (int) MONSTER_RACE_PLANT,
		"Insect", (int) MONSTER_RACE_INSECT,
		"Fish", (int) MONSTER_RACE_FISH,
		"Demon", (int) MONSTER_RACE_DEMON,
		"DemiHuman", (int) MONSTER_RACE_DEMIHUMAN,
		"Angel", (int) MONSTER_RACE_ANGEL,
		"Dragon", (int) MONSTER_RACE_DRAGON,
		"Player", (int) MONSTER_RACE_PLAYER,
		"Boss", (int) MONSTER_RACE_BOSS,
		"NonBoss", (int) MONSTER_RACE_NONBOSS
	);

	state->create_named_table("MonsterMode",
		"None", (int) MONSTER_MODE_MASK_NONE,
		"CanMove", (int) MONSTER_MODE_MASK_CANMOVE,
		"Looter", (int) MONSTER_MODE_MASK_LOOTER,
		"Aggressive", (int) MONSTER_MODE_MASK_AGGRESSIVE,
		"Assist", (int) MONSTER_MODE_MASK_ASSIST,
		"CastSensorIdle", (int) MONSTER_MODE_MASK_CASTSENSOR_IDLE,
		"Boss", (int) MONSTER_MODE_MASK_BOSS,
		"Plant", (int) MONSTER_MODE_MASK_PLANT,
		"CanAttack", (int) MONSTER_MODE_MASK_CANATTACK,
		"Detector", (int) MONSTER_MODE_MASK_DETECTOR,
		"CastSensorChase", (int) MONSTER_MODE_MASK_CASTSENSOR_CHASE,
		"ChangeChase", (int) MONSTER_MODE_MASK_CHANGECHASE,
		"Angry", (int) MONSTER_MODE_MASK_ANGRY,
		"ChangeTargetMelee", (int) MONSTER_MODE_MASK_CHANGETARGET_MELEE,
		"ChangeTargetChase", (int) MONSTER_MODE_MASK_CHANGETARGET_CHASE,
		"TargetWeak", (int) MONSTER_MODE_MASK_TARGETWEAK,
		"NoKnockBack", (int) MONSTER_MODE_MASK_NOKNOCKBACK
	);

	state->create_named_table("MonsterSkillState",
		"Any", MONSTER_SKILL_STATE_ANY,
		"Idle", MONSTER_SKILL_STATE_IDLE,
		"Walk", MONSTER_SKILL_STATE_WALK,
		"Loot", MONSTER_SKILL_STATE_LOOT,
		"Dead", MONSTER_SKILL_STATE_DEAD,
		"Berserk", MONSTER_SKILL_STATE_BERSERK, //Aggressive mob attacking
		"Angry", MONSTER_SKILL_STATE_ANGRY,   //Mob retaliating from being attacked.
		"Rush", MONSTER_SKILL_STATE_RUSH,    //Mob following a player after being attacked.
		"Follow", MONSTER_SKILL_STATE_FOLLOW,  //Mob following a player without being attacked.
		"AnyTarget", MONSTER_SKILL_STATE_ANYTARGET
	);

	state->create_named_table("MonsterSkillTarget",
		"CurrentTarget", MONSTER_SKILL_TARGET_CURRENT,
		"Random", MONSTER_SKILL_TARGET_RANDOM,
		"Self", MONSTER_SKILL_TARGET_SELF,
		"Friend", MONSTER_SKILL_TARGET_FRIEND,
		"Master", MONSTER_SKILL_TARGET_MASTER,
		"Around5", MONSTER_SKILL_TARGET_AROUND5,
		"Around6", MONSTER_SKILL_TARGET_AROUND6,
		"Around7", MONSTER_SKILL_TARGET_AROUND7,
		"Around8", MONSTER_SKILL_TARGET_AROUND8,
		"Around1", MONSTER_SKILL_TARGET_AROUND1,
		"Around2", MONSTER_SKILL_TARGET_AROUND2,
		"Around3", MONSTER_SKILL_TARGET_AROUND3,
		"Around4", MONSTER_SKILL_TARGET_AROUND4,
		"Around", MONSTER_SKILL_TARGET_AROUND
	);


	state->create_named_table("MonsterSkillCastCondition",
		"Always", MONSTER_SKILL_CC_ALWAYS,
		"MyHpLtMaxRate", MONSTER_SKILL_CC_MYHPLTMAXRATE,
		"MyHpInRate", MONSTER_SKILL_CC_MYHPINRATE,
		"FriendHpLtMaxRate", MONSTER_SKILL_CC_FRIENDHPLTMAXRATE,
		"FriendHpInRate", MONSTER_SKILL_CC_FRIENDHPINRATE,
		"MyStatusOn", MONSTER_SKILL_CC_MYSTATUSON,
		"MyStatusOff", MONSTER_SKILL_CC_MYSTATUSOFF,
		"FriendStatusOn", MONSTER_SKILL_CC_FRIENDSTATUSON,
		"FriendStatusOff", MONSTER_SKILL_CC_FRIENDSTATUSOFF,
		"AttackPCGT", MONSTER_SKILL_CC_ATTACKPCGT,
		"AttackPCGE", MONSTER_SKILL_CC_ATTACKPCGE,
		"SlaveLT", MONSTER_SKILL_CC_SLAVELT,
		"SlaveLE", MONSTER_SKILL_CC_SLAVELE,
		"CloseRangeAttacked", MONSTER_SKILL_CC_CLOSERANGEATTACKED,
		"LongRangeAttacked", MONSTER_SKILL_CC_LONGRANGEATTACKED,
		"AfterSkill", MONSTER_SKILL_CC_AFTERSKILL,
		"SkillUsed", MONSTER_SKILL_CC_SKILLUSED,
		"CastTargeted", MONSTER_SKILL_CC_CASTTARGETED,
		"RudeAttacked", MONSTER_SKILL_CC_RUDEATTACKED,
		"MasterHPLTMaxRate", MONSTER_SKILL_CC_MASTERHPLTMAXRATE,
		"MasterAttacked", MONSTER_SKILL_CC_MASTERATTACKED,
		"Alchemist", MONSTER_SKILL_CC_ALCHEMIST,
		"Spawn", MONSTER_SKILL_CC_SPAWN,
		"MagicAttacked", MONSTER_SKILL_CC_MAGICATTACKED
	);
}

void MonsterComponent::sync_data_types(std::shared_ptr<sol::state> state)
{
	state->new_usertype<Monster>("Monster",
		"entity", [](std::shared_ptr<Horizon::Zone::Entities::Monster> monster) { return monster->shared_from_this(); },
		"stop_movement", &Monster::stop_movement,
		"on_pathfinding_failure", &Monster::on_pathfinding_failure,
		"on_movement_begin", &Monster::on_movement_begin,
		"on_movement_step", &Monster::on_movement_step,
		"on_movement_end", &Monster::on_movement_end,
		"set_spotted", &Monster::set_spotted,
		"was_spotted_once", &Monster::was_spotted_once,
		"on_status_effect_start", &Monster::on_status_effect_start,
		"on_status_effect_end", &Monster::on_status_effect_end,
		"on_status_effect_change", &Monster::on_status_effect_change,
		"set_next_walk_time", &Monster::set_next_walk_time,
		"next_walk_time", &Monster::next_walk_time,
		"on_damage_received", &Monster::on_damage_received
	);
}

void MonsterComponent::sync_functions(std::shared_ptr<sol::state> state, std::shared_ptr<MapContainerThread> container)
{
	state->set_function("cast_entity_to_monster",
					[] (std::shared_ptr<Entity> e)
					{
						return e->template downcast<Monster>();
					});

	// Monster Spawn Script Function
	state->set_function("Monster",
		[this, container] (std::string const &map_name, uint16_t x, uint16_t y, uint16_t x_area, uint16_t y_area, std::string const &name, uint16_t monster_id, uint16_t amount, uint16_t spawn_delay_base, uint16_t spawn_delay_variance) 
		{
			if (container == nullptr)
				return;
			
			std::shared_ptr<Map> map;

			MAP_CONTAINER_THREAD_ASSERT_MAP(map, container, map_name);

			std::shared_ptr<const monster_config_data> md = MonsterDB->get_monster_by_id(monster_id);

			if (md == nullptr) {
				HLog(warning) << "Monster " << monster_id << " set for spawn in " << map_name << " does not exist in the database.";
				return;
			}

			std::shared_ptr<std::vector<std::shared_ptr<const monster_skill_config_data>>> mskd = MonsterDB->get_monster_skill_by_id(monster_id);

			for (int i = 0; i < amount; i++) {
				MapCoords mcoords = MapCoords(x, y);

				if (mcoords == MapCoords(0, 0))
					mcoords = map->get_random_accessible_coordinates();
				else if (x_area && y_area) {
					if ((mcoords = map->get_random_coordinates_in_walkable_area(x, y, x_area, y_area)) == MapCoords(0, 0)) {
						HLog(warning) << "Couldn't spawn monster " << md->name << " in area, spawning it on random co-ordinates.";
						mcoords = map->get_random_accessible_coordinates();
					}
				}

				std::shared_ptr<Monster> monster = std::make_shared<Monster>(map, mcoords, md, mskd);
				monster->initialize();
				
				register_single_spawned_monster(monster->guid(), monster);
			}

			monster_spawn_data spwd;

			spwd.map_name = map_name;
			spwd.x = x;
			spwd.y = y;
			spwd.x_area = x_area;
			spwd.y_area = y_area;
			spwd.mob_name = name;
			spwd.monster_id = monster_id;
			spwd.amount = amount;
			spwd.spawn_delay_base = spawn_delay_base;
			spwd.spawn_delay_variance = spawn_delay_variance;

			register_monster_spawn_info(_last_monster_spawn_id++, std::make_shared<monster_spawn_data>(spwd));
		});
}

void MonsterComponent::deregister_single_spawned_monster(uint32_t guid) {
	for (auto i = _monster_spawned_map.begin(); i != _monster_spawned_map.end(); i++)
		if ((*i).second->guid() == guid) {
			(*i).second->finalize();
			_monster_spawned_map.erase(i);
			return;
		}
}