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

#ifndef HORIZON_SQL_CHARACTER_STATUS_HPP
#define HORIZON_SQL_CHARACTER_STATUS_HPP

#include <sqlpp11/table.h>
#include <sqlpp11/data_types.h>
#include <sqlpp11/char_sequence.h>

namespace Horizon
{
namespace SQL
{
namespace TableCharacterStatus_
{

struct id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T id;
			T& operator()()
			{
				return id;
			}
			const T& operator()() const
			{
				return id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct job_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "job_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T job_id;
			T& operator()()
			{
				return job_id;
			}
			const T& operator()() const
			{
				return job_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct base_level
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "base_level";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T base_level;
			T& operator()()
			{
				return base_level;
			}
			const T& operator()() const
			{
				return base_level;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct job_level
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "job_level";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T job_level;
			T& operator()()
			{
				return job_level;
			}
			const T& operator()() const
			{
				return job_level;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct base_experience
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "base_experience";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T base_experience;
			T& operator()()
			{
				return base_experience;
			}
			const T& operator()() const
			{
				return base_experience;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::bigint>;
};

struct job_experience
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "job_experience";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T job_experience;
			T& operator()()
			{
				return job_experience;
			}
			const T& operator()() const
			{
				return job_experience;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::bigint>;
};

struct zeny
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "zeny";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T zeny;
			T& operator()()
			{
				return zeny;
			}
			const T& operator()() const
			{
				return zeny;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct strength
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "strength";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T strength;
			T& operator()()
			{
				return strength;
			}
			const T& operator()() const
			{
				return strength;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct agility
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "agility";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T agility;
			T& operator()()
			{
				return agility;
			}
			const T& operator()() const
			{
				return agility;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct vitality
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "vitality";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T vitality;
			T& operator()()
			{
				return vitality;
			}
			const T& operator()() const
			{
				return vitality;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct intelligence
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "intelligence";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T intelligence;
			T& operator()()
			{
				return intelligence;
			}
			const T& operator()() const
			{
				return intelligence;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct dexterity
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "dexterity";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T dexterity;
			T& operator()()
			{
				return dexterity;
			}
			const T& operator()() const
			{
				return dexterity;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct luck
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "luck";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T luck;
			T& operator()()
			{
				return luck;
			}
			const T& operator()() const
			{
				return luck;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct maximum_hp
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "maximum_hp";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T maximum_hp;
			T& operator()()
			{
				return maximum_hp;
			}
			const T& operator()() const
			{
				return maximum_hp;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct hp
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "hp";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T hp;
			T& operator()()
			{
				return hp;
			}
			const T& operator()() const
			{
				return hp;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct maximum_sp
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "maximum_sp";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T maximum_sp;
			T& operator()()
			{
				return maximum_sp;
			}
			const T& operator()() const
			{
				return maximum_sp;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct sp
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "sp";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T sp;
			T& operator()()
			{
				return sp;
			}
			const T& operator()() const
			{
				return sp;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct status_points
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "status_points";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T status_points;
			T& operator()()
			{
				return status_points;
			}
			const T& operator()() const
			{
				return status_points;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct skill_points
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "skill_points";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T skill_points;
			T& operator()()
			{
				return skill_points;
			}
			const T& operator()() const
			{
				return skill_points;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct body_state
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "body_state";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T body_state;
			T& operator()()
			{
				return body_state;
			}
			const T& operator()() const
			{
				return body_state;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct virtue
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "virtue";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T virtue;
			T& operator()()
			{
				return virtue;
			}
			const T& operator()() const
			{
				return virtue;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct honor
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "honor";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T honor;
			T& operator()()
			{
				return honor;
			}
			const T& operator()() const
			{
				return honor;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct manner
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "manner";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T manner;
			T& operator()()
			{
				return manner;
			}
			const T& operator()() const
			{
				return manner;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct hair_style_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "hair_style_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T hair_style_id;
			T& operator()()
			{
				return hair_style_id;
			}
			const T& operator()() const
			{
				return hair_style_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct hair_color_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "hair_color_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T hair_color_id;
			T& operator()()
			{
				return hair_color_id;
			}
			const T& operator()() const
			{
				return hair_color_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct cloth_color_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "cloth_color_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T cloth_color_id;
			T& operator()()
			{
				return cloth_color_id;
			}
			const T& operator()() const
			{
				return cloth_color_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct body_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "body_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T body_id;
			T& operator()()
			{
				return body_id;
			}
			const T& operator()() const
			{
				return body_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct weapon_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "weapon_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T weapon_id;
			T& operator()()
			{
				return weapon_id;
			}
			const T& operator()() const
			{
				return weapon_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct shield_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "shield_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T shield_id;
			T& operator()()
			{
				return shield_id;
			}
			const T& operator()() const
			{
				return shield_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct head_top_view_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "head_top_view_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T head_top_view_id;
			T& operator()()
			{
				return head_top_view_id;
			}
			const T& operator()() const
			{
				return head_top_view_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct head_mid_view_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "head_mid_view_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T head_mid_view_id;
			T& operator()()
			{
				return head_mid_view_id;
			}
			const T& operator()() const
			{
				return head_mid_view_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct head_bottom_view_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "head_bottom_view_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T head_bottom_view_id;
			T& operator()()
			{
				return head_bottom_view_id;
			}
			const T& operator()() const
			{
				return head_bottom_view_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct robe_view_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "robe_view_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T robe_view_id;
			T& operator()()
			{
				return robe_view_id;
			}
			const T& operator()() const
			{
				return robe_view_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};
}

struct TableCharacterStatus : sqlpp::table_t<TableCharacterStatus,
TableCharacterStatus_::id, TableCharacterStatus_::job_id, TableCharacterStatus_::base_level, TableCharacterStatus_::job_level, TableCharacterStatus_::base_experience, TableCharacterStatus_::job_experience,
TableCharacterStatus_::zeny, TableCharacterStatus_::strength, TableCharacterStatus_::agility, TableCharacterStatus_::vitality, TableCharacterStatus_::intelligence, TableCharacterStatus_::dexterity,
TableCharacterStatus_::luck, TableCharacterStatus_::maximum_hp, TableCharacterStatus_::hp, TableCharacterStatus_::maximum_sp, TableCharacterStatus_::sp, TableCharacterStatus_::status_points,
TableCharacterStatus_::skill_points, TableCharacterStatus_::body_state, TableCharacterStatus_::virtue, TableCharacterStatus_::honor, TableCharacterStatus_::manner, TableCharacterStatus_::hair_style_id,
TableCharacterStatus_::hair_color_id, TableCharacterStatus_::cloth_color_id, TableCharacterStatus_::body_id, TableCharacterStatus_::weapon_id, TableCharacterStatus_::shield_id,
TableCharacterStatus_::head_top_view_id, TableCharacterStatus_::head_mid_view_id, TableCharacterStatus_::head_bottom_view_id, TableCharacterStatus_::robe_view_id>
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "character_status";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T character_status;
			T& operator()()
			{
				return character_status;
			}
			const T& operator()() const
			{
				return character_status;
			}
		};
	};
};

}
}
#endif // HORIZON_SQL_CHARACTERS_STATUS_HPP
