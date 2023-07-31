
#ifndef HORIZON_CORE_STRUCTURES_LINKEDLIST_HEAD_HPP
#define HORIZON_CORE_STRUCTURES_LINKEDLIST_HEAD_HPP

#include <cstdlib>
#include <iterator>

#include "Element.hpp"
#include <cstdint>

namespace Horizon
{
namespace Structures
{
namespace LinkedList
{
//! @brief LinkedList Head class. This class is used to manage a linked list of Elements.
//! It is used as a base class for other classes that need to manage a linked list.
//! It is not intended to be used directly.
//! @param Element The Element type that will be managed by this Head.
//! @param _first The first Element in the list.
//! @param _last The last Element in the list.
//! @param _size The size of the list.
//! Thread safety: This class is not thread safe and is not intended to be used in a multi-threaded environment.
class Head
{
private:
	Element _first;
	Element _last;
	uint32_t _size;

public:
	Head(): _size(0)
	{
		// create empty list

		_first._next = &_last;
		_last._prev = &_first;
	}

	//! @brief Returns true if the list is empty.
	//! @return True if the list is empty.
	bool is_empty() const { return(_first._next == &_last); }

	//! @brief Returns the first Element in the list.
	Element *first()      { return (is_empty() ? nullptr : _first._next); }
	Element const *first() const { return (is_empty() ? nullptr : _first._next); }

	//! @brief Returns the last Element in the list.
	Element *last()       { return(is_empty() ? nullptr : _last._prev); }
	Element const *last() const { return(is_empty() ? nullptr : _last._prev); }

	//! push_front() and push_back() are used to add an Element to the list.
	//! @param pElem The Element to add to the list.
	//! @note The Element must not already be in a list.
	void push_front(Element *pElem)
	{
		_first.push_after(pElem);
	}

	//! @param pElem The Element to add to the list.
	//! @note The Element must not already be in a list.
	void push_back(Element *pElem)
	{
		_last.push_before(pElem);
	}

	//! returns the number of Elements in the list (not including the head and tail Elements or the first and last Elements)
	uint32_t get_size() const
	{
		if (!_size)
		{
			uint32_t result = 0;
			Element const* e = first();
			while (e)
			{
				e = e->next();
				if (e)
					++result;
			}
			return result;
		}
		else
			return _size;
	}

	void inc_size() { ++_size; }
	void dec_size() { --_size; }

	// iterator support. These are used to iterate through the list. The iterator is a pointer to an Element.
	// The iterator is not a pointer to a Head. The iterator is not a pointer to a list of Elements.
	// The iterator is not a pointer to a list of Heads or Elements. The iterator is a pointer to an Element.
	template<class _Ty>
	class Iterator
	{
	public:
		typedef std::bidirectional_iterator_tag     iterator_category;
		typedef _Ty                                 value_type;
		typedef _Ty*                                pointer;
		typedef _Ty const*                          const_pointer;
		typedef _Ty&                                reference;
		typedef _Ty const &                         const_reference;

		Iterator() : _Ptr(nullptr)
		{                                           // construct with null node pointer
		}

		Iterator(pointer _Pnode) : _Ptr(_Pnode)
		{                                           // construct with node pointer _Pnode
		}

		Iterator& operator=(Iterator const &_Right)
		{
			_Ptr = _Right._Ptr;
			return *this;
		}

		Iterator& operator=(const_pointer const &_Right)
		{
			_Ptr = pointer(_Right);
			return *this;
		}

		reference operator*()
		{                                           // return designated value
			return *_Ptr;
		}

		pointer operator->()
		{                                           // return pointer to class object
			return _Ptr;
		}

		Iterator& operator++()
		{                                           // preincrement
			_Ptr = static_cast<pointer>(_Ptr->next());
			return (*this);
		}

		Iterator operator++(int)
		{                                           // postincrement
			Iterator<_Ty> _Tmp = *this;
			++*this;
			return (_Tmp);
		}

		Iterator& operator--()
		{                                           // predecrement
			_Ptr = static_cast<pointer>(_Ptr->prev());
			return (*this);
		}

		Iterator operator--(int)
		{                                           // postdecrement
			Iterator<_Ty> _Tmp = *this;
			--*this;
			return (_Tmp);
		}

		bool operator==(Iterator const &_Right) const
		{                                           // test for iterator equality
			return (_Ptr == _Right._Ptr);
		}

		bool operator!=(Iterator const &_Right) const
		{                                           // test for iterator inequality
			return (!(*this == _Right));
		}

		bool operator==(pointer const &_Right) const
		{                                           // test for pointer equality
			return (_Ptr != _Right);
		}

		bool operator!=(pointer const &_Right) const
		{                                           // test for pointer equality
			return (!(*this == _Right));
		}

		bool operator==(const_reference _Right) const
		{                                           // test for reference equality
			return (_Ptr == &_Right);
		}

		bool operator!=(const_reference _Right) const
		{                                           // test for reference equality
			return (_Ptr != &_Right);
		}

		pointer _Mynode()
		{                                           // return node pointer
			return (_Ptr);
		}

	protected:
		pointer _Ptr;                               // pointer to node
	};

	typedef Iterator<Element> iterator;

private:
	Head(Head const&) = delete;
	Head& operator=(Head const&) = delete;

protected:
	~Head() { }
};
}
}
}

#endif
