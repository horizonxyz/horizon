/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
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

#include "Status.hpp"
#include "Server/Common/Configuration/Horizon.hpp"
#include "Server/Zone/Game/StaticDB/JobDB.hpp"
#include "Server/Zone/Game/StaticDB/ExpDB.hpp"
#include "Server/Zone/Game/Entities/Traits/Appearance.hpp"
#include "Server/Zone/Game/Entities/Traits/ObservableStatus.hpp"
#include "Server/Zone/Game/Entities/Player/Player.hpp"
#include "Server/Common/SQL/Character/Status.hpp"
#include "Server/Zone/Packets/TransmittedPackets.hpp"
#include "Server/Zone/Session/ZoneSession.hpp"
#include "Server/Zone/Zone.hpp"

#include <stdio.h>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/mysql/connection.h>

using namespace Horizon::Zone::Entities::Traits;

void Status::initialize()
{
	set_movement_speed(std::make_shared<MovementSpeed>(_entity, DEFAULT_MOVEMENT_SPEED));

	set_base_level(std::make_shared<BaseLevel>(_entity, 1));
	set_job_level(std::make_shared<JobLevel>(_entity, 1));

	set_current_hp(std::make_shared<CurrentHP>(_entity, 1));
	set_current_sp(std::make_shared<CurrentSP>(_entity, 1));
	set_max_hp(std::make_shared<MaxHP>(_entity, 1));
	set_max_sp(std::make_shared<MaxSP>(_entity, 1));

	set_base_appearance(std::make_shared<BaseAppearance>(_entity, 0));
	set_hair_color(std::make_shared<HairColor>(_entity, 0));
	set_cloth_color(std::make_shared<ClothColor>(_entity, 0));
	set_head_top_sprite(std::make_shared<HeadTopSprite>(_entity, 0));
	set_head_mid_sprite(std::make_shared<HeadMidSprite>(_entity, 0));
	set_head_bottom_sprite(std::make_shared<HeadBottomSprite>(_entity, 0));
	set_hair_style(std::make_shared<HairStyle>(_entity, 0));
	set_shield_sprite(std::make_shared<ShieldSprite>(_entity, 0));
	set_weapon_sprite(std::make_shared<WeaponSprite>(_entity, 0));
	set_robe_sprite(std::make_shared<RobeSprite>(_entity, 0));
	set_body_style(std::make_shared<BodyStyle>(_entity, 0));
}

void Status::initialize(std::shared_ptr<Entity> entity)
{
	std::shared_ptr<Player> pl = entity->template downcast<Player>();
	SQL::TableCharacterStatus tcs;
	
	std::shared_ptr<sqlpp::mysql::connection> conn = sZone->get_db_connection();
	
	auto res = (*conn)(select(all_of(tcs)).from(tcs).where(tcs.id == pl->character()._character_id));
	
	if (res.empty()) {
		ZC_REFUSE_ENTER zre(pl->get_session());
		HLog(error) << "Error initializing status for character " << pl->character()._character_id << ".";
		zre.deliver(ZONE_SERV_ERROR_REJECT);
		return;
	}
	
	uint32_t job_id = res.front().job_id;
	
	pl->set_job_id(job_id);
	
	std::shared_ptr<const job_config_data> job = JobDB->get_job_by_id(job_id);
	std::shared_ptr<const exp_group_data> bexpg = ExpDB->get_exp_group(job->base_exp_group, EXP_GROUP_TYPE_BASE);
	std::shared_ptr<const exp_group_data> jexpg = ExpDB->get_exp_group(job->job_exp_group, EXP_GROUP_TYPE_JOB);

	uint32_t str = res.front().strength;
	uint32_t agi = res.front().agility;
	uint32_t vit = res.front().vitality;
	uint32_t _int = res.front().intelligence;
	uint32_t dex = res.front().dexterity;
	uint32_t luk = res.front().luck;

	/**
	 * Main Attributes.
	 */
	set_strength(std::make_shared<Strength>(_entity, str));
	set_agility(std::make_shared<Agility>(_entity, agi, 0, 0));
	set_vitality(std::make_shared<Vitality>(_entity, vit, 0, 0));
	set_intelligence(std::make_shared<Intelligence>(_entity, _int, 0, 0));
	set_dexterity(std::make_shared<Dexterity>(_entity, dex, 0, 0));
	set_luck(std::make_shared<Luck>(_entity, luk, 0, 0));

	set_strength_cost(std::make_shared<StrengthPointCost>(_entity, get_required_statpoints(str, str + 1)));
	set_agility_cost(std::make_shared<AgilityPointCost>(_entity, get_required_statpoints(agi, agi + 1)));
	set_vitality_cost(std::make_shared<VitalityPointCost>(_entity, get_required_statpoints(vit, vit + 1)));
	set_intelligence_cost(std::make_shared<IntelligencePointCost>(_entity, get_required_statpoints(_int, _int + 1)));
	set_dexterity_cost(std::make_shared<DexterityPointCost>(_entity, get_required_statpoints(dex, dex + 1)));
	set_luck_cost(std::make_shared<LuckPointCost>(_entity, get_required_statpoints(luk, luk + 1)));

	set_status_point(std::make_shared<StatusPoint>(_entity, uint32_t(res.front().status_points)));
	set_skill_point(std::make_shared<SkillPoint>(_entity, uint32_t(res.front().skill_points)));

	set_current_hp(std::make_shared<CurrentHP>(_entity, uint32_t(res.front().hp)));
	set_current_sp(std::make_shared<CurrentSP>(_entity, uint32_t(res.front().sp)));
	set_max_hp(std::make_shared<MaxHP>(_entity, uint32_t(res.front().maximum_hp)));
	set_max_sp(std::make_shared<MaxSP>(_entity, uint32_t(res.front().maximum_sp)));

	uint32_t base_level = uint32_t(res.front().base_level);
	uint32_t job_level = uint32_t(res.front().job_level);
	
	set_base_level(std::make_shared<BaseLevel>(_entity, base_level));
	set_job_level(std::make_shared<JobLevel>(_entity, job_level));

	set_base_experience(std::make_shared<BaseExperience>(_entity, uint64_t(res.front().base_experience)));
	set_job_experience(std::make_shared<JobExperience>(_entity, uint64_t(res.front().job_experience)));
	set_next_base_experience(std::make_shared<NextBaseExperience>(_entity, bexpg->exp[base_level - 1]));
	set_next_job_experience(std::make_shared<NextJobExperience>(_entity, bexpg->exp[job_level - 1]));
	set_movement_speed(std::make_shared<MovementSpeed>(_entity, DEFAULT_MOVEMENT_SPEED));

	set_base_appearance(std::make_shared<BaseAppearance>(_entity, job_id));
	set_hair_color(std::make_shared<HairColor>(_entity, uint32_t(res.front().hair_color_id)));
	set_cloth_color(std::make_shared<ClothColor>(_entity, uint32_t(res.front().cloth_color_id)));
	set_head_top_sprite(std::make_shared<HeadTopSprite>(_entity, uint32_t(res.front().head_top_view_id)));
	set_head_mid_sprite(std::make_shared<HeadMidSprite>(_entity, uint32_t(res.front().head_mid_view_id)));
	set_head_bottom_sprite(std::make_shared<HeadBottomSprite>(_entity, uint32_t(res.front().head_bottom_view_id)));
	set_hair_style(std::make_shared<HairStyle>(_entity, uint32_t(res.front().hair_style_id)));
	set_shield_sprite(std::make_shared<ShieldSprite>(_entity, uint32_t(res.front().shield_id)));
	set_weapon_sprite(std::make_shared<WeaponSprite>(_entity, uint32_t(res.front().weapon_id)));
	set_robe_sprite(std::make_shared<RobeSprite>(_entity, uint32_t(res.front().robe_view_id)));
	set_body_style(std::make_shared<BodyStyle>(_entity, uint32_t(res.front().body_id)));

	initialize_compound_attributes(job);

	initialize_observable_statuses();

	max_weight()->compute(true);
	
	status_atk()->compute(false);
	status_matk()->compute(false);
	soft_def()->compute(false);
	soft_mdef()->compute(false);
	hit()->compute(false);
	crit()->compute(false);
	flee()->compute(false);

	pl->get_session()->clif()->notify_initial_status(shared_from_this());
}

void Status::initialize_compound_attributes(std::shared_ptr<const job_config_data> job)
{
	std::shared_ptr<StatusATK> status_atk;
	std::shared_ptr<EquipATK> equip_atk;
	std::shared_ptr<StatusMATK> status_matk;
	std::shared_ptr<SoftDEF> soft_def;
	std::shared_ptr<SoftMDEF> soft_mdef;
	std::shared_ptr<HIT> hit;
	std::shared_ptr<CRIT> crit;
	std::shared_ptr<FLEE> flee;
	std::shared_ptr<AttackSpeed> aspd;
	std::shared_ptr<MaxWeight> max_weight;

	set_max_weight(max_weight = std::make_shared<MaxWeight>(_entity, job->max_weight));
	max_weight->set_strength(strength().get());

	// Calculated when inventory is synced.
	set_current_weight(std::make_shared<CurrentWeight>(_entity, 0));

	set_status_atk(status_atk = std::make_shared<StatusATK>(_entity));
	status_atk->set_base_level(base_level().get());
	status_atk->set_strength(strength().get());
	status_atk->set_dexterity(dexterity().get());
	status_atk->set_luck(luck().get());

	set_equip_atk(equip_atk = std::make_shared<EquipATK>(_entity));
	equip_atk->set_strength(strength().get());
	equip_atk->set_dexterity(dexterity().get());

	set_status_matk(status_matk = std::make_shared<StatusMATK>(_entity));
	status_matk->set_base_level(base_level().get());
	status_matk->set_intelligence(intelligence().get());
	status_matk->set_dexterity(dexterity().get());
	status_matk->set_luck(luck().get());

	set_soft_def(soft_def = std::make_shared<SoftDEF>(_entity));
	soft_def->set_vitality(vitality().get());

	set_soft_mdef(soft_mdef = std::make_shared<SoftMDEF>(_entity));
	soft_mdef->set_base_level(base_level().get());
	soft_mdef->set_intelligence(intelligence().get());
	soft_mdef->set_dexterity(dexterity().get());
	soft_mdef->set_vitality(vitality().get());

	set_hit(hit = std::make_shared<HIT>(_entity));
	hit->set_base_level(base_level().get());
	hit->set_dexterity(dexterity().get());
	hit->set_luck(luck().get());

	set_crit(crit = std::make_shared<CRIT>(_entity));
	crit->set_luck(luck().get());

	set_flee(flee = std::make_shared<FLEE>(_entity));
	flee->set_base_level(base_level().get());
	flee->set_agility(agility().get());
	flee->set_luck(luck().get());

	set_aspd(aspd = std::make_shared<AttackSpeed>(_entity));
	aspd->set_base_level(base_level().get());
	aspd->set_agility(agility().get());
	aspd->set_dexterity(dexterity().get());
}

//! @brief Registers status observers for observable statuses.
void Status::initialize_observable_statuses()
{
	// Register Status Observables
	strength()->register_observable(strength().get());
	agility()->register_observable(agility().get());
	vitality()->register_observable(vitality().get());
	intelligence()->register_observable(intelligence().get());
	dexterity()->register_observable(dexterity().get());
	luck()->register_observable(luck().get());
	base_experience()->register_observable(base_experience().get());
	job_experience()->register_observable(job_experience().get());
	base_level()->register_observable(base_level().get());
	job_level()->register_observable(job_level().get());

	// Register Status Observers
	strength()->register_observers(
		strength_cost().get(),
		max_weight().get(),
		status_atk().get(),
		equip_atk().get());

	agility()->register_observers(
		agility_cost().get(),
		flee().get(),
		aspd().get());

	vitality()->register_observers(
		vitality_cost().get(),
		soft_def().get(),
		soft_mdef().get());

	intelligence()->register_observers(
		intelligence_cost().get(),
		status_matk().get(),
		soft_mdef().get());

	dexterity()->register_observers(
		dexterity_cost().get(),
		status_atk().get(),
		equip_atk().get(),
		status_matk().get(),
		soft_mdef().get(),
		hit().get(),
		aspd().get());

	luck()->register_observers(
		luck_cost().get(),
		status_atk().get(),
		status_matk().get(),
		hit().get(),
		crit().get(),
		flee().get());

	base_level()->register_observers(
		status_point().get(),
		next_base_experience().get(),
		status_atk().get(), 
		status_matk().get(), 
		soft_mdef().get(), 
		hit().get(), 
		flee().get(), 
		aspd().get());

	job_level()->register_observers(
		skill_point().get(), 
		next_job_experience().get());

	base_experience()->register_observers(base_level().get());

	job_experience()->register_observers(job_level().get());
}

void Status::compute_and_notify_compound_attributes()
{	
	max_weight()->compute(true);
	status_atk()->compute(true);
	equip_atk()->compute(true);
	status_matk()->compute(true);
	soft_def()->compute(true);
	soft_mdef()->compute(true);
	hit()->compute(true);
	crit()->compute(true);
	flee()->compute(true);
	aspd()->compute(true);
}

uint32_t Status::get_required_statpoints(uint16_t from, uint16_t to)
{
	uint32_t sp = 0;

	for (; from < to; from++)
		sp += (from < 100) ? (2 + (from - 1) / 10) : (16 + 4 * ((from - 100) / 5));

	return sp;
}

uint32_t Status::get_status_base(status_point_type type)
{
	uint32_t value = 0;
	switch (type)
	{
		case STATUS_STRENGTH: value = strength()->get_base(); break;
		case STATUS_AGILITY: value = agility()->get_base(); break;
		case STATUS_VITALITY: value = vitality()->get_base(); break;
		case STATUS_INTELLIGENCE: value = intelligence()->get_base(); break;
		case STATUS_DEXTERITY: value = dexterity()->get_base(); break;
		case STATUS_LUCK: value = luck()->get_base(); break;
		default: return 0;
	}

	return value;
}

/**
 * @brief Increases a status point to a certain limit
 * and returns the current total of the stat.
 * @param type[in] Type of the status point @see status_point_type
 * @param limit[in] Limit to increase the status point to.
 * @return The total base value of the current status point.
 */
bool Status::increase_status_point(status_point_type type, uint16_t limit)
{
	uint32_t value = 0;

	if (limit <= 0 || limit > MAX_STATUS_POINTS)
		return false;

	if (_entity.expired())
		return false;

	uint32_t available_points = status_point()->get_base();
	uint32_t required_points = 0;

	limit += get_status_base(type);

#define notify_status(t, amount, result) \
		entity()->template downcast<Player>()->get_session()->clif()->notify_status_attribute_update(t, amount, result)
#define notify_compound_attribute(t, amount) \
		entity()->template downcast<Player>()->get_session()->clif()->notify_compound_attribute_update(t, amount)
#define notify_required_attribute(t, amount) \
		entity()->template downcast<Player>()->get_session()->clif()->notify_required_attribute_update(t, amount)
	do {
		value = get_status_base(type);
		required_points = get_required_statpoints(value + 1, value + 2);

		if (required_points > available_points || value >= MAX_STATUS_POINTS)
			break;

		available_points -= required_points;
		switch (type)
		{
			case STATUS_STRENGTH:
				strength()->add_base(1);
				notify_required_attribute(STATUS_STRENGTH_COST, required_points);
				break;
			case STATUS_AGILITY:
				agility()->add_base(1);
				notify_required_attribute(STATUS_AGILITY_COST, required_points);
				break;
			case STATUS_VITALITY:
				vitality()->add_base(1);
				notify_required_attribute(STATUS_VITALITY_COST, required_points);
				break;
			case STATUS_INTELLIGENCE:
				intelligence()->add_base(1);
				notify_required_attribute(STATUS_INTELLIGENCE_COST, required_points);
				break;
			case STATUS_DEXTERITY:
				dexterity()->add_base(1);
				notify_required_attribute(STATUS_DEXTERITY_COST, required_points);
				break;
			case STATUS_LUCK:
				luck()->add_base(1);
				notify_required_attribute(STATUS_LUCK_COST, required_points);
				break;
			default:
				notify_status(type, get_status_base(type), false);
				return false;
		}

		notify_status(type, get_status_base(type), true);

		status_point()->set_base(available_points);
		notify_compound_attribute(STATUS_STATUSPOINT, available_points);

	} while (get_status_base(type) < limit);
#undef notify_status
#undef notify_compound_attribute
#undef notify_required_attribute
	return true;
}

