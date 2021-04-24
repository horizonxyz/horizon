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

#ifndef HORIZON_SQL_CHARACTER_INVENTORY_HPP
#define HORIZON_SQL_CHARACTER_INVENTORY_HPP

#include <sqlpp11/table.h>
#include <sqlpp11/data_types.h>
#include <sqlpp11/char_sequence.h>

namespace Horizon
{
namespace SQL
{
namespace TableCharacterInventory_
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

struct char_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "char_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T char_id;
			T& operator()()
			{
				return char_id;
			}
			const T& operator()() const
			{
				return char_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct item_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "item_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T item_id;
			T& operator()()
			{
				return item_id;
			}
			const T& operator()() const
			{
				return item_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct amount
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "amount";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T amount;
			T& operator()()
			{
				return amount;
			}
			const T& operator()() const
			{
				return amount;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct equip_location_mask
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "equip_location_mask";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T equip_location_mask;
			T& operator()()
			{
				return equip_location_mask;
			}
			const T& operator()() const
			{
				return equip_location_mask;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct is_identified
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "is_identified";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T is_identified;
			T& operator()()
			{
				return is_identified;
			}
			const T& operator()() const
			{
				return is_identified;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct refine_level
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "refine_level";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T refine_level;
			T& operator()()
			{
				return refine_level;
			}
			const T& operator()() const
			{
				return refine_level;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::tinyint>;
};

struct element_type
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "element_type";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T element_type;
			T& operator()()
			{
				return element_type;
			}
			const T& operator()() const
			{
				return element_type;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::tinyint>;
};

struct slot_item_id_0
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "slot_item_id_0";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T slot_item_id_0;
			T& operator()()
			{
				return slot_item_id_0;
			}
			const T& operator()() const
			{
				return slot_item_id_0;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct slot_item_id_1
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "slot_item_id_1";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T slot_item_id_1;
			T& operator()()
			{
				return slot_item_id_1;
			}
			const T& operator()() const
			{
				return slot_item_id_1;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct slot_item_id_2
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "slot_item_id_2";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T slot_item_id_2;
			T& operator()()
			{
				return slot_item_id_2;
			}
			const T& operator()() const
			{
				return slot_item_id_2;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct slot_item_id_3
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "slot_item_id_3";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T slot_item_id_3;
			T& operator()()
			{
				return slot_item_id_3;
			}
			const T& operator()() const
			{
				return slot_item_id_3;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct opt_idx0
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "opt_idx0";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T opt_idx0;
			T& operator()()
			{
				return opt_idx0;
			}
			const T& operator()() const
			{
				return opt_idx0;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct opt_val0
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "opt_val0";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T opt_val0;
			T& operator()()
			{
				return opt_val0;
			}
			const T& operator()() const
			{
				return opt_val0;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct opt_idx1
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "opt_idx1";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T opt_idx1;
			T& operator()()
			{
				return opt_idx1;
			}
			const T& operator()() const
			{
				return opt_idx1;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct opt_val1
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "opt_val1";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T opt_val1;
			T& operator()()
			{
				return opt_val1;
			}
			const T& operator()() const
			{
				return opt_val1;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct opt_idx2
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "opt_idx2";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T opt_idx2;
			T& operator()()
			{
				return opt_idx2;
			}
			const T& operator()() const
			{
				return opt_idx2;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct opt_val2
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "opt_val2";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T opt_val2;
			T& operator()()
			{
				return opt_val2;
			}
			const T& operator()() const
			{
				return opt_val2;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct opt_idx3
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "opt_idx3";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T opt_idx3;
			T& operator()()
			{
				return opt_idx3;
			}
			const T& operator()() const
			{
				return opt_idx3;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct opt_val3
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "opt_val3";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T opt_val3;
			T& operator()()
			{
				return opt_val3;
			}
			const T& operator()() const
			{
				return opt_val3;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct opt_idx4
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "opt_idx4";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T opt_idx4;
			T& operator()()
			{
				return opt_idx4;
			}
			const T& operator()() const
			{
				return opt_idx4;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct opt_val4
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "opt_val4";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T opt_val4;
			T& operator()()
			{
				return opt_val4;
			}
			const T& operator()() const
			{
				return opt_val4;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::smallint>;
};

struct hire_expire_date
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "hire_expire_date";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T hire_expire_date;
			T& operator()()
			{
				return hire_expire_date;
			}
			const T& operator()() const
			{
				return hire_expire_date;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct is_favorite
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "is_favorite";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T is_favorite;
			T& operator()()
			{
				return is_favorite;
			}
			const T& operator()() const
			{
				return is_favorite;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::integer>;
};

struct bind_type
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "bind_type";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T bind_type;
			T& operator()()
			{
				return bind_type;
			}
			const T& operator()() const
			{
				return bind_type;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::tinyint>;
};

struct unique_id
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "unique_id";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T unique_id;
			T& operator()()
			{
				return unique_id;
			}
			const T& operator()() const
			{
				return unique_id;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::bigint>;
};


struct is_broken
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "is_broken";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T is_broken;
			T& operator()()
			{
				return is_broken;
			}
			const T& operator()() const
			{
				return is_broken;
			}
		};
	};
	using _traits = sqlpp::make_traits<sqlpp::tinyint>;
};

}

struct TableCharacterInventory : sqlpp::table_t<TableCharacterInventory,
TableCharacterInventory_::id, TableCharacterInventory_::char_id, TableCharacterInventory_::item_id, TableCharacterInventory_::amount,
TableCharacterInventory_::equip_location_mask, TableCharacterInventory_::is_identified, TableCharacterInventory_::refine_level, TableCharacterInventory_::element_type,
TableCharacterInventory_::slot_item_id_0, TableCharacterInventory_::slot_item_id_1, TableCharacterInventory_::slot_item_id_2, TableCharacterInventory_::slot_item_id_3,
TableCharacterInventory_::opt_idx0, TableCharacterInventory_::opt_val0, TableCharacterInventory_::opt_idx1, TableCharacterInventory_::opt_val1,
TableCharacterInventory_::opt_idx2, TableCharacterInventory_::opt_val2, TableCharacterInventory_::opt_idx3, TableCharacterInventory_::opt_val3, TableCharacterInventory_::opt_idx4, TableCharacterInventory_::opt_val4,
TableCharacterInventory_::hire_expire_date, TableCharacterInventory_::is_favorite, TableCharacterInventory_::bind_type, TableCharacterInventory_::is_broken, TableCharacterInventory_::unique_id>
{
	struct _alias_t
	{
		static constexpr const char _literal[] = "character_inventory";
		using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
		template <typename T>
		struct _member_t
		{
			T character_inventory;
			T& operator()()
			{
				return character_inventory;
			}
			const T& operator()() const
			{
				return character_inventory;
			}
		};
	};
};

}
}
#endif // HORIZON_MODELS_CHARACTERS_INVENTORY_HPP
