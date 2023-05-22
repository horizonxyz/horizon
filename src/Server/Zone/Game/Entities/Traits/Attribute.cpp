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

#include "Server/Zone/Game/Entities/Creature/Hostile/Monster.hpp"
#include "Server/Zone/Game/Entities/Entity.hpp"
#include "Server/Zone/Game/Entities/Player/Player.hpp"
#include "Server/Zone/Game/Entities/Player/Assets/Inventory.hpp"
#include "Server/Zone/Game/StaticDB/JobDB.hpp"
#include "Server/Zone/Game/StaticDB/ExpDB.hpp"
#include "Server/Zone/Game/Entities/Traits/Status.hpp"
#include "Server/Zone/Definitions/EntityDefinitions.hpp"
#include "Server/Zone/Session/ZoneSession.hpp"
#include "Server/Zone/Interface/ZoneClientInterface.hpp"
#include "Core/Logging/Logger.hpp"

using namespace Horizon::Zone;
using namespace Horizon::Zone::Traits;

template <class STATUS_COST_T, class STATUS_T>
void set_new_point_cost(std::shared_ptr<Horizon::Zone::Entity> entity, STATUS_COST_T *cost_t, STATUS_T *stat)
{
	if (entity == nullptr || stat == nullptr)
		return;

	int32_t new_cost = entity->status()->get_required_statpoints(stat->get_base(), stat->get_base() + 1);

	cost_t->set_base(new_cost);
}

void StrengthPointCost::on_observable_changed(Strength *str)
{
	set_new_point_cost(entity(), this, str);
}

void AgilityPointCost::on_observable_changed(Agility *agi)
{
	set_new_point_cost(entity(), this, agi);
}

void VitalityPointCost::on_observable_changed(Vitality *vit)
{
	set_new_point_cost(entity(), this, vit);
}

void IntelligencePointCost::on_observable_changed(Intelligence *_int)
{
	set_new_point_cost(entity(), this, _int);
}

void DexterityPointCost::on_observable_changed(Dexterity *dex)
{
	set_new_point_cost(entity(), this, dex);
}

void LuckPointCost::on_observable_changed(Luck *luk)
{
	set_new_point_cost(entity(), this, luk);
}

void BaseLevel::set_base(int32_t val)
{
	std::shared_ptr<const job_config_data> job = JobDB->get_job_by_id(entity()->job_id());
	std::shared_ptr<const exp_group_data> bexpg = ExpDB->get_exp_group(job->base_exp_group, EXP_GROUP_TYPE_BASE);

	if (val >= bexpg->max_level) {
		val = bexpg->max_level;
	}

	Attribute::set_base(val);
	this->notify_observers();

	if (entity()->type() == ENTITY_PLAYER) {
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_BASELEVEL, val);
	}
}

void BaseLevel::on_observable_changed(BaseExperience *bexp)
{
	if (entity() == nullptr || bexp == nullptr)
		return;

	if (get_base() >= MAX_LEVEL)
		return;

	int prev_nbexp = 0;
	if (bexp->get_base() >= (prev_nbexp = entity()->status()->next_base_experience()->get_base())) {
		int carry_over = bexp->get_base();
		do {
			carry_over = carry_over - prev_nbexp;
			add_base(1);
		} while (carry_over >= (prev_nbexp = entity()->status()->next_base_experience()->total()));
		bexp->set_base(carry_over);
	}
}

void JobLevel::set_base(int32_t val)
{
	std::shared_ptr<const job_config_data> job = JobDB->get_job_by_id(entity()->job_id());
	std::shared_ptr<const exp_group_data> jexpg = ExpDB->get_exp_group(job->job_exp_group, EXP_GROUP_TYPE_JOB);

	if (val >= jexpg->max_level) {
		val = jexpg->max_level;
	}

	Attribute::set_base(val);
	this->notify_observers();

	if (entity()->type() == ENTITY_PLAYER) {
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_JOBLEVEL, val);
	}
}

void JobLevel::on_observable_changed(JobExperience *jexp)
{
	if (entity() == nullptr || jexp == nullptr)
		return;

	int prev_njexp = 0;
	if (jexp->total() >= (prev_njexp = entity()->status()->next_job_experience()->get_base())) {
		int carry_over = jexp->total();
		do {
			carry_over = carry_over - prev_njexp;
			add_base(1);
		} while (carry_over >= (prev_njexp = entity()->status()->next_job_experience()->total()));
		
		jexp->set_base(carry_over);
	}
}

void BaseExperience::set_base(int32_t val)
{
	std::shared_ptr<const job_config_data> job = JobDB->get_job_by_id(entity()->job_id());
	std::shared_ptr<const exp_group_data> bexpg = ExpDB->get_exp_group(job->base_exp_group, EXP_GROUP_TYPE_BASE);

	if (entity()->status()->base_level()->total() >= bexpg->max_level)
		return;

	Attribute::set_base(val);
	this->notify_observers();

	if (entity()->type() == ENTITY_PLAYER) {
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_experience_update(STATUS_BASEEXP, val);
	}
}

void JobExperience::set_base(int32_t val)
{
	std::shared_ptr<const job_config_data> job = JobDB->get_job_by_id(entity()->job_id());
	std::shared_ptr<const exp_group_data> jexpg = ExpDB->get_exp_group(job->job_exp_group, EXP_GROUP_TYPE_JOB);

	if (entity()->status()->job_level()->total() >= jexpg->max_level)
		return;

	Attribute::set_base(val);

	this->notify_observers();

	if (entity()->type() == ENTITY_PLAYER) {
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_experience_update(STATUS_JOBEXP, val);
	}
}

void CurrentHP::damage(int damage)
{
	if (damage >= total())
		set_base(0);
	else
		sub_base(damage);

	if (entity()->type() == ENTITY_PLAYER)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_CURRENTHP, total());
}

void CurrentSP::reduce(int amount)
{
	if (amount >= total())
		set_base(0);
	else
		sub_base(amount);

	if (entity()->type() == ENTITY_PLAYER)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_CURRENTSP, total());
}


void NextBaseExperience::set_base(int32_t val)
{
	Attribute::set_base(val);

	if (entity()->type() == ENTITY_PLAYER) {
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_experience_update(STATUS_NEXTBASEEXP, val);
	}
}

void NextBaseExperience::on_observable_changed(BaseLevel *blvl)
{
	if (entity() == nullptr || blvl == nullptr)
		return;

	std::shared_ptr<const job_config_data> job = JobDB->get_job_by_id(entity()->job_id());
	std::shared_ptr<const exp_group_data> bexpg = ExpDB->get_exp_group(job->base_exp_group, EXP_GROUP_TYPE_BASE);

	if (blvl->total() >= bexpg->max_level) {
		set_base(bexpg->exp[bexpg->exp.size() - 1]);
		return;
	}

	set_base(bexpg->exp[blvl->get_base() - 1]);
}

void NextJobExperience::set_base(int32_t val)
{
	Attribute::set_base(val);

	if (entity()->type() == ENTITY_PLAYER) {
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_experience_update(STATUS_NEXTJOBEXP, val);
	}
}

void NextJobExperience::on_observable_changed(JobLevel *jlvl)
{
	if (entity() == nullptr || jlvl == nullptr)
		return;

	std::shared_ptr<const job_config_data> job = JobDB->get_job_by_id(entity()->job_id());
	std::shared_ptr<const exp_group_data> jexpg = ExpDB->get_exp_group(job->job_exp_group, EXP_GROUP_TYPE_JOB);
	
	if (jlvl->total() >= jexpg->max_level) {
		set_base(jexpg->exp[jexpg->exp.size() - 1]);
		return;
	}

	set_base(jexpg->exp[jlvl->get_base() - 1]);
}

void StatusPoint::on_observable_changed(BaseLevel *blvl)
{
	if (entity() == nullptr || blvl == nullptr)
		return;

	add_base(ExpDB->get_status_point(blvl->get_base()) - ExpDB->get_status_point(blvl->get_base() - 1));
}

void SkillPoint::on_observable_changed(JobLevel *jlvl)
{
	if (entity() == nullptr || jlvl == nullptr)
		return;

	add_base(1);
}

void SkillPoint::set_base(int32_t val)
{
	Attribute<SkillPoint>::set_base(val);

	if (entity()->type() == ENTITY_PLAYER)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_SKILLPOINT, total());
}

int32_t MaxWeight::compute(bool notify)
{
	if (entity() == nullptr || _str == nullptr)
		return 0;

	std::shared_ptr<const job_config_data> job = JobDB->get_job_by_id(entity()->job_id());

	set_base(job->max_weight + _str->get_base() * 300);

	if (entity()->type() == ENTITY_PLAYER && notify)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_MAX_WEIGHT, total());
	
	return total();
}

void MovementSpeed::set_base(int32_t val)
{
	Attribute<MovementSpeed>::set_base(val);

	if (entity()->type() == ENTITY_PLAYER)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_MOVEMENT_SPEED, total());
}

int32_t StatusATK::compute(bool notify)
{
	int32_t blvl = 1, str = 1, dex = 1, luk = 1;

	if (_blvl != nullptr)
		blvl = _blvl->get_base();

	if (_str != nullptr)
		str = _str->total();

	if (_dex != nullptr)
		dex = _dex->total();

	if (_luk != nullptr)
		luk = _luk->total();

	// Ranged: floor[(BaseLevel ÷ 4) + (Str ÷ 5) + Dex + (Luk ÷ 3)]
	if (((1ULL << _weapon_type) & IT_WTM_RANGED) & ~(1ULL<<IT_WT_FIST))
		set_base(dex + (blvl / 4) + (str / 5) + (luk / 3));

	// Melee: floor[(BaseLevel ÷ 4) + Str + (Dex ÷ 5) + (Luk ÷ 3)]
	set_base(str + (blvl / 4) + (dex / 5) + (luk / 3));

	if (entity()->type() == ENTITY_PLAYER && notify)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_STATUS_ATK, total());
	
	return total();
}

int32_t StatusMATK::compute(bool notify)
{
	int32_t blvl = 1, int_ = 1, dex = 1, luk = 1;

	if (_blvl != nullptr)
		blvl = _blvl->get_base();

	if (_int != nullptr)
		int_ = _int->total();

	if (_dex != nullptr)
		dex = _dex->total();

	if (_luk != nullptr)
		luk = _luk->total();

	// floor[floor[BaseLevel ÷ 4] + Int + floor[Int ÷ 2] + floor[Dex ÷ 5] + floor[Luk ÷ 3]]
	set_base(int_ + (blvl / 4) + (int_ / 2) + (dex / 5) + (luk / 3));

	if (entity()->type() == ENTITY_PLAYER && notify)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_STATUS_MATK, total());
	
	return total();
}

int32_t SoftDEF::compute(bool notify)
{
	int32_t vit = 1;

	if (_vit != nullptr)
		vit = _vit->total();

	// (VIT ÷ 2) + Max[(VIT × 0.3), (VIT ^ 2 ÷ 150) − 1]
	set_base((vit / 2) + std::max((vit * 0.3), (std::pow(vit, 2) / 150) - 1));

	if (entity()->type() == ENTITY_PLAYER && notify)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_SOFT_DEF, total());
	
	return total();
}

int32_t SoftMDEF::compute(bool notify)
{
	int32_t blvl = 1, int_ = 1, dex = 1, vit = 1;

	if (_blvl != nullptr)
		blvl = _blvl->get_base();

	if (_int != nullptr)
		int_ = _int->total();

	if (_dex != nullptr)
		dex = _dex->total();

	if (_vit != nullptr)
		vit = _vit->total();

	// INT + VIT ÷ 5 + DEX ÷ 5 + BaseLv ÷ 4
	set_base(int_ + (vit / 5) + (dex / 5) + (blvl / 4));

	if (entity()->type() == ENTITY_PLAYER && notify)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_SOFT_MDEF, total());
	
	return total();
}

int32_t HIT::compute(bool notify)
{
	int32_t blvl = 1, dex = 1, luk = 1;

	if (_blvl != nullptr)
		blvl = _blvl->get_base();

	if (_dex != nullptr)
		dex = _dex->total();

	if (_luk != nullptr)
		luk = _luk->total();

	// 175 + BaseLv + DEX + Floor(LUK ÷ 3) + Bonus
	set_base(175 + blvl + dex + (luk / 3));

	if (entity()->type() == ENTITY_PLAYER && notify)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_HIT, total());
	
	return total();
}

int32_t CRIT::compute(bool notify)
{
	int32_t luk = 1;

	if (_luk != nullptr)
		luk = _luk->total();

	// LUK × 0.3 + Bonus
	set_base(luk / 3);

	if (entity()->type() == ENTITY_PLAYER && notify)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_CRITICAL, total());
	
	return total();
}

//! @brief Computes FLEE status based on agility, luck and Base Level.
//! FLEE = 100 + BaseLv + AGI + Floor(LUK ÷ 5)
int32_t FLEE::compute(bool notify)
{
	int32_t blvl = 1, agi = 1, luk = 1;

	if (_agi != nullptr)
		agi = _agi->total();

	if (_blvl != nullptr)
		blvl = _blvl->get_base();

	if (_luk != nullptr)
		luk = _luk->total();

	set_base(100 + blvl + agi + (luk / 5));

	if (entity()->type() == ENTITY_PLAYER && notify)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_FLEE, total());
	
	return total();
}

//! @brief Computes the EquipATK property of physical attacks.
//! EquipATK = floor[((BaseWeaponDamage + Variance + StatBonus + RefinementBonus + OverUpgradeBonus) × SizePenaltyMultiplier]
int32_t EquipATK::compute(bool notify)
{
	int32_t str = 1, dex = 1;

	if (entity() == nullptr || entity()->type() != ENTITY_PLAYER)
		return 0;

	if (_str != nullptr)
		str = _str->total();

	if (_dex != nullptr)
		dex = _dex->total();

	std::shared_ptr<Horizon::Zone::Entities::Player> player = entity()->downcast<Horizon::Zone::Entities::Player>();
	EquipmentListType const &equipments = player->inventory()->equipments();

	std::shared_ptr<const item_entry_data> lhw = equipments[IT_EQPI_HAND_L].second.lock();
	std::shared_ptr<const item_entry_data> rhw = equipments[IT_EQPI_HAND_R].second.lock();

	if (lhw && lhw->type == IT_TYPE_WEAPON) {
		// Base Weapon Damage
		_left_hand_val = lhw->config->attack;
		// StatBonus = BaseWeaponDamage × (Melee: Str / Ranged: Dex) ÷ 200
		_left_hand_val += (lhw->config->attack * (((1ULL << lhw->config->sub_type.weapon_t) & IT_WTM_MELEE) ? str : dex) / 200.00f);
	} else {
		_left_hand_val = 0;
	}

	if (rhw && rhw->type == IT_TYPE_WEAPON) {
		// Base Weapon Damage
		_right_hand_val = rhw->config->attack;
		// StatBonus = BaseWeaponDamage × (Melee: Str / Ranged: Dex) ÷ 200
		_right_hand_val += (rhw->config->attack * ((( 1ULL << rhw->config->sub_type.weapon_t) & IT_WTM_MELEE) ? str : dex) / 200.00f);
	} else {
		_right_hand_val = 0;
	}

	set_base(_left_hand_val + _right_hand_val);

	if (entity()->type() == ENTITY_PLAYER && notify)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_EQUIP_ATK, total());

	return total();
}

int32_t EquipATK::compute_variance(int8_t weapon_lvl, int32_t base_weapon_dmg)
{
	srand(time(0));

	return floor(((rand() % 1000 + (-500)) / 10000.f) * weapon_lvl * base_weapon_dmg);
}

int32_t AttackSpeed::compute(bool notify)
{
	float temp_aspd = 0.00f;
	int amotion = 0;

	if (entity()->type() == ENTITY_PLAYER) {
		EquipmentListType const &equipments = entity()->downcast<Horizon::Zone::Entities::Player>()->inventory()->equipments();
		std::shared_ptr<const item_entry_data> rhw = equipments[IT_EQPI_HAND_R].second.lock();
		std::shared_ptr<const item_entry_data> lhw = equipments[IT_EQPI_HAND_L].second.lock();
		std::shared_ptr<const job_config_data> job = JobDB->get_job_by_id(entity()->job_id());

		item_weapon_type rhw_type, lhw_type;

		if (rhw == nullptr) { 
			rhw_type = IT_WT_FIST;
		} else {
			rhw_type = rhw->config->sub_type.weapon_t;
		}

		amotion = job->weapon_base_aspd[rhw_type];

		if (rhw_type > IT_WT_SINGLE_MAX && lhw != nullptr) {
			lhw_type = lhw->config->sub_type.weapon_t;
			amotion += job->weapon_base_aspd[lhw_type] / 4; // Dual-wield
		}

		if (_dex == nullptr || _blvl == nullptr || _agi == nullptr) {
			HLog(error) << "AttackSpeed::compute: Couldn't compute... Dex, Blvl or Agi was null.";
			return amotion;
		}

		switch(rhw_type) {
			case IT_WT_BOW:
			case IT_WT_MUSICAL:
			case IT_WT_WHIP:
			case IT_WT_REVOLVER:
			case IT_WT_RIFLE:
			case IT_WT_GATLING:
			case IT_WT_SHOTGUN:
			case IT_WT_GRENADE:
				temp_aspd = _dex->get_base() * _dex->get_base() / 7.0f + _agi->get_base() * _agi->get_base() * 0.5f;
				break;
			default:
				temp_aspd = _dex->get_base() * _dex->get_base() / 5.0f + _agi->get_base() * _agi->get_base() * 0.5f;
				break;
		}

		temp_aspd = (float)(sqrt(temp_aspd) * 0.25f) + 196;

#define ASPD_FROM_STATUS_EFFECTS 0
#define ASPD_FROM_SKILLS 0
		amotion = (int)(temp_aspd + ((float)((ASPD_FROM_STATUS_EFFECTS + ASPD_FROM_SKILLS) * _agi->get_base() / 200)) - std::min(amotion, 200));
		amotion += (std::max(0xc3 - amotion, 2) * (ASPD_FROM_STATUS_EFFECTS)) / 100;
		amotion = 10 * (200 - amotion);
#undef ASPD_FROM_STATUS_EFFECTS
#undef ASPD_FROM_SKILLS
	}

 	set_base(amotion);

	if (entity()->type() == ENTITY_PLAYER && notify)
		entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_compound_attribute_update(STATUS_ASPD, total());

	return total();
}

int32_t AttackRange::compute(bool notify)
{
	if (entity()->type() == ENTITY_PLAYER) {
		EquipmentListType const &equipments = entity()->downcast<Horizon::Zone::Entities::Player>()->inventory()->equipments();
		
		if (equipments[IT_EQPI_HAND_R].second.expired() == true)
			return 0;

		std::shared_ptr<const item_entry_data> rhw = equipments[IT_EQPI_HAND_R].second.lock();
		
		if (rhw == nullptr || rhw->config == nullptr)
			return 0;

		set_base(rhw->config->attack_range);

		if (notify == true)
			entity()->downcast<Horizon::Zone::Entities::Player>()->get_session()->clif()->notify_attack_range_update(total());
	} else if (entity()->type() == ENTITY_MONSTER) {
		set_base(entity()->downcast<Horizon::Zone::Entities::Monster>()->monster_config()->attack_range);
	}

	return total();
}

int32_t CreatureAttackDamage::compute()
{
	set_min(_blvl->total() + _str->total() + (_cw_atk->total() * 8 / 10));
	set_max(_blvl->total() + _str->total() + (_cw_atk->total() * 12 / 10));

	return std::rand() % ((_max - _min + 1) + _min);
}

int32_t CreatureMagicAttackDamage::compute()
{
	set_min(_blvl->total() + _int->total() + (_cw_atk->total() * 7 / 10));
	set_max(_blvl->total() + _int->total() + (_cw_atk->total() * 13 / 10));

	return std::rand() % (_max - _min + 1) + _min;
}

int32_t AttackMotion::compute()
{
	if (entity()->type() == ENTITY_PLAYER)
		set_base(_attack_speed->get_base());
	else if (entity()->type() == ENTITY_MONSTER)
		set_base(entity()->downcast<Horizon::Zone::Entities::Monster>()->monster_config()->attack_motion);

	return total();
}

int32_t AttackDelay::compute()
{
	if (entity()->type() == ENTITY_PLAYER)
		set_base(2 * _attack_motion->total());
	else if (entity()->type() == ENTITY_MONSTER)
		set_base(entity()->downcast<Horizon::Zone::Entities::Monster>()->monster_config()->attack_delay);

	return total();
}

int32_t DamageMotion::compute()
{
	if (entity()->type() == ENTITY_PLAYER)
		set_base(800 - _agi->get_base() * 4);
	else if (entity()->type() == ENTITY_MONSTER)
		set_base(entity()->downcast<Horizon::Zone::Entities::Monster>()->monster_config()->damage_motion);

	return total();
}

int32_t BaseAttack::compute()
{
	if (entity()->type() == ENTITY_PLAYER) {
		bool melee = true;
		EquipmentListType const &equipments = entity()->downcast<Horizon::Zone::Entities::Player>()->inventory()->equipments();
		std::shared_ptr<const item_entry_data> rhw = nullptr;

		if (!equipments[IT_EQPI_HAND_R].second.expired()) {
			rhw = equipments[IT_EQPI_HAND_R].second.lock();

			switch (rhw->config->sub_type.weapon_t)
			{
			case IT_WT_BOW:
			case IT_WT_MUSICAL:
			case IT_WT_WHIP:
			case IT_WT_REVOLVER:
			case IT_WT_RIFLE:
			case IT_WT_GATLING:
			case IT_WT_SHOTGUN:
			case IT_WT_GRENADE:
				melee = false;
			default:
				break;
			}
		}
		set_base((melee ? _str->total() : _dex->total()) + (float) ((melee ? _dex->get_base() : _str->total()) / 5) + (float) (_luk->get_base() / 3) + (_blvl->get_base() / 4));
	}
	else if (entity()->type() == ENTITY_MONSTER)
		set_base(_str->total() + _blvl->get_base());

	return total();
}