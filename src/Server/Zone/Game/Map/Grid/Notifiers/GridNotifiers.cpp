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

#include "GridNotifiers.hpp"

#include "Server/Common/Definitions/NPCDefinitions.hpp"
#include "Core/Logging/Logger.hpp"
#include "Server/Zone/Game/Entities/Player/Player.hpp"
#include "Server/Zone/Game/Entities/Skill/Skill.hpp"
#include "Server/Zone/Game/Entities/NPC/NPC.hpp"
#include "Server/Zone/Game/Entities/Creature/Companion/Pet.hpp"
#include "Server/Zone/Game/Entities/Creature/Companion/Homunculus.hpp"
#include "Server/Zone/Game/Entities/Creature/Companion/Mercenary.hpp"
#include "Server/Zone/Game/Entities/Creature/Companion/Elemental.hpp"
#include "Server/Zone/Game/Entities/Creature/Hostile/Monster.hpp"
#include "Server/Zone/Game/Map/Grid/GridRefManager.hpp"
#include "Server/Zone/Session/ZoneSession.hpp"

using namespace Horizon::Zone::Entities;

void GridPlayerNotifier::notify(GridRefManager<Horizon::Zone::Entities::Player> &m)
{
	using namespace Horizon::Zone::Entities;

	std::shared_ptr<Player> pl = _entity.lock()->template downcast<Player>();

	if (pl == nullptr)
		return;

	for (typename GridRefManager<Player>::iterator iter = m.begin(); iter != typename GridRefManager<Player>::iterator(nullptr); ++iter) {
		if (iter->source() == nullptr)
			continue;

		switch (_type)
		{
			case GRID_NOTIFY_AREA_WOS:
				if (iter->source()->guid() == pl->guid())
					continue;
			default:
				break;
		}
		iter->source()->get_session()->transmit_buffer(_buf, _buf.active_length());
	}
}

template <class T>
void GridViewPortUpdater::update(GridRefManager<T> &m)
{
    using namespace Horizon::Zone;
    using namespace Horizon::Zone::Entities;

    if (_entity.expired())
        return;

    std::shared_ptr<Player> pl = _entity.lock()->template downcast<Player>();

    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != typename GridRefManager<T>::iterator(nullptr); ++iter) {
        if (iter->source() == nullptr || iter->source()->guid() == pl->guid())
            continue;

        std::shared_ptr<Entity> vp_e = iter->source()->shared_from_this();

        if (pl->is_in_range_of(vp_e, MAX_VIEW_RANGE))
            pl->add_entity_to_viewport(vp_e);
        else
            pl->remove_entity_from_viewport(vp_e, EVP_NOTIFY_OUT_OF_SIGHT);
    }
}

void GridViewPortUpdater::Visit(GridRefManager<Player> &m) { update(m); }
void GridViewPortUpdater::Visit(GridRefManager<NPC> &m) { update(m); }
void GridViewPortUpdater::Visit(GridRefManager<Elemental> &m) { update(m); }
void GridViewPortUpdater::Visit(GridRefManager<Homunculus> &m) { update(m); }
void GridViewPortUpdater::Visit(GridRefManager<Mercenary> &m) { update(m); }
void GridViewPortUpdater::Visit(GridRefManager<Pet> &m) { update(m); }
void GridViewPortUpdater::Visit(GridRefManager<Monster> &m) { update(m); }
void GridViewPortUpdater::Visit(GridRefManager<Skill> &m) { update(m); }

template <class T>
void GridEntityExistenceNotifier::notify(GridRefManager<T> &m)
{
    using namespace Horizon::Zone::Entities;

    if (!m.get_size())
        return;

    std::shared_ptr<Horizon::Zone::Entity> src_entity = _entity.lock();

    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != typename GridRefManager<T>::iterator(nullptr); ++iter) {
        if (iter->source() == nullptr)
            continue;

        std::shared_ptr<Player> tpl = iter->source()->template downcast<Player>();

        if (src_entity == nullptr || src_entity->guid() == tpl->guid())
            continue;

        bool is_in_range = tpl->is_in_range_of(src_entity);

        if (_notif_type == EVP_NOTIFY_IN_SIGHT && is_in_range) {
            // Target player realizes new entity in viewport.
            // Source entity doesn't need to realize target as update_viewport() is called when needed/
            tpl->add_entity_to_viewport(src_entity);
        } else if (_notif_type > EVP_NOTIFY_OUT_OF_SIGHT || (_notif_type == EVP_NOTIFY_OUT_OF_SIGHT && !is_in_range)) {
            tpl->remove_entity_from_viewport(src_entity, _notif_type);
        }
    }
}

void GridEntityExistenceNotifier::Visit(GridRefManager<Player> &m) { notify(m); }
template <> void GridEntityExistenceNotifier::Visit<NPC>(GridRefManager<NPC> &m);
template <> void GridEntityExistenceNotifier::Visit<Elemental>(GridRefManager<Elemental> &m);
template <> void GridEntityExistenceNotifier::Visit<Homunculus>(GridRefManager<Homunculus> &m);
template <> void GridEntityExistenceNotifier::Visit<Mercenary>(GridRefManager<Mercenary> &m);
template <> void GridEntityExistenceNotifier::Visit<Pet>(GridRefManager<Pet> &m);
template <> void GridEntityExistenceNotifier::Visit<Monster>(GridRefManager<Monster> &m);
template <> void GridEntityExistenceNotifier::Visit<Skill>(GridRefManager<Skill> &m);

template <class T>
void GridEntitySpawnNotifier::notify(GridRefManager<T> &m)
{
    using namespace Horizon::Zone::Entities;

    if (!m.get_size())
        return;

    std::shared_ptr<Horizon::Zone::Entity> src_entity = _entity.lock();

    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != typename GridRefManager<T>::iterator(nullptr); ++iter) {
        if (iter->source() == nullptr)
            continue;

        std::shared_ptr<Player> tpl = iter->source()->template downcast<Player>();

        if (src_entity == nullptr || src_entity->guid() == tpl->guid())
            continue;

        tpl->spawn_entity_in_viewport(src_entity);
    }
}

void GridEntitySpawnNotifier::Visit(GridRefManager<Player> &m) { notify<Player>(m); }
template <> void GridEntitySpawnNotifier::Visit<NPC>(GridRefManager<NPC> &m);
template <> void GridEntitySpawnNotifier::Visit<Elemental>(GridRefManager<Elemental> &m);
template <> void GridEntitySpawnNotifier::Visit<Homunculus>(GridRefManager<Homunculus> &m);
template <> void GridEntitySpawnNotifier::Visit<Mercenary>(GridRefManager<Mercenary> &m);
template <> void GridEntitySpawnNotifier::Visit<Pet>(GridRefManager<Pet> &m);
template <> void GridEntitySpawnNotifier::Visit<Monster>(GridRefManager<Monster> &m);
template <> void GridEntitySpawnNotifier::Visit<Skill>(GridRefManager<Skill> &m);

template <class T>
void GridEntityMovementNotifier::notify(GridRefManager<T> &m)
{
    using namespace Horizon::Zone::Entities;

    if (!m.get_size())
        return;

    std::shared_ptr<Horizon::Zone::Entity> src_entity = _entity.lock();

    if (src_entity == nullptr)
        return;

    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != typename GridRefManager<T>::iterator(nullptr); ++iter) {
        if (iter->source() == nullptr)
            continue;

        std::shared_ptr<Player> tpl = iter->source()->template downcast<Player>();

        if (src_entity->guid() == tpl->guid())
            continue;

        tpl->realize_entity_movement(src_entity);
    }
}

void GridEntityMovementNotifier::Visit(GridRefManager<Player> &m) { notify(m); }

template <> void GridEntityMovementNotifier::Visit<NPC>(GridRefManager<NPC> &m);
template <> void GridEntityMovementNotifier::Visit<Elemental>(GridRefManager<Elemental> &m);
template <> void GridEntityMovementNotifier::Visit<Homunculus>(GridRefManager<Homunculus> &m);
template <> void GridEntityMovementNotifier::Visit<Mercenary>(GridRefManager<Mercenary> &m);
template <> void GridEntityMovementNotifier::Visit<Pet>(GridRefManager<Pet> &m);
template <> void GridEntityMovementNotifier::Visit<Monster>(GridRefManager<Monster> &m);
template <> void GridEntityMovementNotifier::Visit<Skill>(GridRefManager<Skill> &m);

template <class T>
void GridEntitySearcher::search(GridRefManager<T> &m)
{
    // Found check.
    if (!_result.expired())
        return;

    using namespace Horizon::Zone;
    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != typename GridRefManager<T>::iterator(nullptr); ++iter) {
        if (iter->source() == nullptr)
            continue;

        std::weak_ptr<Entity> entity = iter->source()->shared_from_this();
        if (!entity.expired() && _predicate(entity)) {
            _result = entity;
            return;
        }
    }
}

std::shared_ptr<Horizon::Zone::Entity> GridEntitySearcher::get_result() const { return _result.lock(); }

void GridEntitySearcher::Visit(GridRefManager<Player> &m) { search<Player>(m); }
void GridEntitySearcher::Visit(GridRefManager<NPC> &m) { search<NPC>(m); }
void GridEntitySearcher::Visit(GridRefManager<Elemental> &m) { search<Elemental>(m); }
void GridEntitySearcher::Visit(GridRefManager<Homunculus> &m) { search<Homunculus>(m); }
void GridEntitySearcher::Visit(GridRefManager<Mercenary> &m) { search<Mercenary>(m); }
void GridEntitySearcher::Visit(GridRefManager<Pet> &m) { search<Pet>(m); }
void GridEntitySearcher::Visit(GridRefManager<Monster> &m) { search<Monster>(m); }
void GridEntitySearcher::Visit(GridRefManager<Skill> &m) { search<Skill>(m); }

template <class T>
void GridNPCTrigger::check_and_trigger(GridRefManager<T> &m)
{
    if (_source.expired())
        return;

    using namespace Horizon::Zone::Entities;
    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != typename GridRefManager<T>::iterator(nullptr); ++iter) {
        std::shared_ptr<NPC> npc = iter->source()->template downcast<NPC>();
        if (npc == nullptr)
            continue;

        std::shared_ptr<npc_db_data> const &nd = npc->script_manager()->get_npc_from_db(npc->guid());
        if (nd != nullptr && nd->trigger_range && _predicate(npc, nd->trigger_range)) {
            std::shared_ptr<Player> player = _source.lock()->downcast<Player>();
            _source.lock()->script_manager()->contact_npc_for_player(player, npc->guid());
        }
    }
}

void GridNPCTrigger::Visit(GridRefManager<NPC> &m) { check_and_trigger(m); }
template<> void GridNPCTrigger::Visit<Player>(GridRefManager<Player> &m);
template<> void GridNPCTrigger::Visit<Elemental>(GridRefManager<Elemental> &m);
template<> void GridNPCTrigger::Visit<Homunculus>(GridRefManager<Homunculus> &m);
template<> void GridNPCTrigger::Visit<Mercenary>(GridRefManager<Mercenary> &m);
template<> void GridNPCTrigger::Visit<Pet>(GridRefManager<Pet> &m);
template<> void GridNPCTrigger::Visit<Monster>(GridRefManager<Monster> &m);
template<> void GridNPCTrigger::Visit<Skill>(GridRefManager<Skill> &m);

void GridPlayerNotifier::Visit(GridRefManager<Player> &m) { notify(m); }
template<> void GridPlayerNotifier::Visit<NPC>(GridRefManager<NPC> &m);
template<> void GridPlayerNotifier::Visit<Elemental>(GridRefManager<Elemental> &m);
template<> void GridPlayerNotifier::Visit<Homunculus>(GridRefManager<Homunculus> &m);
template<> void GridPlayerNotifier::Visit<Mercenary>(GridRefManager<Mercenary> &m);
template<> void GridPlayerNotifier::Visit<Pet>(GridRefManager<Pet> &m);
template<> void GridPlayerNotifier::Visit<Monster>(GridRefManager<Monster> &m);
template<> void GridPlayerNotifier::Visit<Skill>(GridRefManager<Skill> &m);
