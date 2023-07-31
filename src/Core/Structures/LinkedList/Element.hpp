

#ifndef HORIZON_CORE_STRUCTURES_LINKEDLIST_ELEMENT_HPP
#define HORIZON_CORE_STRUCTURES_LINKEDLIST_ELEMENT_HPP

namespace Horizon
{
namespace Structures
{
namespace LinkedList
{
//! @brief This class is used to manage a linked list of Elements. It is not intended to be used directly. 
//! It is used as a base class for other classes that need to manage a linked list.
//! The Head class is a friend of this class to allow it to access the private members of this class.
//! @param _next The next Element in the list.
//! @param _prev The previous Element in the list.
class Element
{
private:
	friend class Head;

	Element *_next;
	Element *_prev;

public:
	Element() : _next(nullptr), _prev(nullptr) { }

	//! @brief Returns true if this Element has a next Element in the list.
	bool has_next() const  { return (_next && _next->_next != nullptr); }
	//! @brief Returns true if this Element has a previous Element in the list.
	bool has_prev() const  { return (_prev && _prev->_prev != nullptr); }
	//! @brief Returns true if this Element is in a list.
	bool is_in_list() const { return (_next != nullptr && _prev != nullptr); }

	//! @brief Returns the next Element in the list.
	Element *next()       { return has_next() ? _next : nullptr; }
	Element const *next() const { return has_next() ? _next : nullptr; }
	//! @brief Returns the previous Element in the list.
	Element *prev()       { return has_prev() ? _prev : nullptr; }
	Element const *prev() const { return has_prev() ? _prev : nullptr; }

	//! @brief Returns the next Element in the list without checking if it exists.
	Element *nocheck_next()       { return _next; }
	Element const *nocheck_next() const { return _next; }
	//! @brief Returns the previous Element in the list without checking if it exists.
	Element *nocheck_prev()       { return _prev; }
	Element const *nocheck_prev() const { return _prev; }

	//! @brief Removes this Element from the list.
	void delink()
	{
		if (!is_in_list())
			return;

		_next->_prev = _prev;
		_prev->_next = _next;
		_next = nullptr;
		_prev = nullptr;
	}

	//! @brief Pushes this Element before the given Element.
	//! @param pElem The Element to push this Element before.
	//! @note This Element must not be in a list.
	void push_before(Element* pElem)
	{
		pElem->_next = this;
		pElem->_prev = _prev;
		_prev->_next = pElem;
		_prev = pElem;
	}

	//! @brief Pushes this Element after the given Element.
	//! @param pElem The Element to push this Element after.
	//! @note This Element must not be in a list.
	void push_after(Element* pElem)
	{
		pElem->_prev = this;
		pElem->_next = _next;
		_next->_prev = pElem;
		_next = pElem;
	}

private:
	// disable copy and assignment because we don't want to copy Elements and we don't want to assign Elements to each other.
	// This is a linked list, not a copyable list because it is used to manage a list of objects that are not copyable.
	// Copying the objects could result in unexpected behavior.
	Element(Element const&) = delete;
	Element& operator=(Element const&) = delete;

protected:
	~Element()
	{
		delink();
	}
};
}
}
}

#endif /* HORIZON_CORE_STRUCTURES_HPP */
