

#ifndef HORIZON_CORE_STRUCTURES_REFMANAGER_HPP
#define HORIZON_CORE_STRUCTURES_REFMANAGER_HPP

#include "Core/Structures/LinkedList/Head.hpp"
#include "Core/Structures/LinkedList/ReferenceList/Reference.hpp"

namespace Horizon
{
namespace Structures
{
namespace LinkedList
{
//!	@brief This class is used to manage a linked list of References.
//! It is not intended to be used directly. It is used as a base class for other classes that need to manage a linked list.
//! The Head class is a friend of this class to allow it to access the private members of this class.
//! The functionality of this class is identical to the Element class except that it is used to manage a linked list of References.
//! The RefManager can be used to manage a linked list of References to any type of object. The object type is specified by the TO template parameter.
//! And the type of object that the Reference is managing is specified by the FROM template parameter.
//! By default the TO and FROM template parameters are the same type. But they can be different types if the Reference is managing a base class of the object. 
//! The reference list is a doubly linked list. The list is circular so the first element's previous element is the last element and the last element's next element is the first element.
//! The reason we link the TO and FROM objects together is so that we can easily invalidate all the References in the list when the FROM object is destroyed.
//! By creating a dynamic responsibility chain between the ReferenceManager and the Reference, 
//! we can provide a simple and efficient way to manage a linked list of References and visit objects of a specific type by using the ReferenceManager.
//! @param _next The next Reference in the list.
//! @param _prev The previous Reference in the list.
//! @param _ref The Reference that this Reference is managing.
//! @param _head The Head that this Reference is in.
//! @param _valid True if the Reference is valid.
template <class TO, class FROM>
class RefManager : public Head
{
public:
	typedef Head::Iterator<Reference<TO, FROM>> iterator;
	RefManager() { }
	
	//! Returns the first Reference in the list.
	Reference<TO, FROM> *first() { return static_cast<Reference<TO, FROM> *>(Head::first()); }
	Reference<TO, FROM> const *first() const { return static_cast<Reference<TO, FROM> const *>(Head::first()); }

	//! Returns the iterator at the beginning of the list.
	iterator begin() { return iterator(first()); }
	//! Returns the iterator at the end of the list.
	iterator end() { return iterator(nullptr); }

	virtual ~RefManager()
	{
		clear_all();
	}

	void clear_all()
	{
		while (Reference<TO, FROM> *ref = first())
			ref->invalidate();
	}
};
}
}
}

#endif
