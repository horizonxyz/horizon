

#ifndef HORIZON_CORE_STRUCTURES_REFERENCE_HPP
#define HORIZON_CORE_STRUCTURES_REFERENCE_HPP

#include "Core/Structures/LinkedList/Element.hpp"
#include <cassert>

namespace Horizon
{
namespace Structures
{
namespace LinkedList
{
// write a detailed description of this class here
//! @details This class is used to manage a linked list of References.
//! It is not intended to be used directly. It is used as a base class for other classes that need to manage a linked list.
//! The Head class is a friend of this class (derived from Element) to allow it to access the private members of this class.
//! The relationship between the Reference and the ReferenceManager is a one-to-many relationship, where the ReferenceManager 
//! is the one and the Reference is the many. The ReferenceManager is responsible for creating and destroying the Reference.
//! The ReferenceManager is also responsible for calling the link() and remove() methods of the Reference. 
//! This creates a dynamic responsibility chain between the ReferenceManager and the Reference.
//! @param _next (derived from Element)The next Reference in the list.
//! @param _prev (derived from Element) The previous Reference in the list.
//! @param _ref_to The object that is being referenced.
//! @param _ref_from The object that is referencing.
template <class TO, class FROM>
class Reference : public Element
{
private:
	TO *_ref_to;
	FROM *_ref_from;

protected:
	// Tell our refTo (target) object that we have a link
	virtual void target_object_build_link() = 0;

	// Tell our refTo (taget) object, that the link is cut
	virtual void target_object_destroy_link() = 0;

	// Tell our refFrom (source) object, that the link is cut (Target destroyed)
	virtual void source_object_destroy_link() = 0;
public:
	Reference() { _ref_to = nullptr; _ref_from = nullptr; }
	virtual ~Reference() { }

	//! Links the Reference to the specified object by adding it to the front of the list.
	//! @param toObj The object to reference.
	//! @param fromObj The object that is referencing.
	void link(TO *toObj, FROM *fromObj)
	{
		assert(fromObj);

		// Clear if any previous references to a reference manager.
		if (is_valid())
			remove();

		// Build the link.
		if (toObj != nullptr) {
			_ref_to = toObj;
			_ref_from = fromObj;
			target_object_build_link();
		}
	}

	// We don't need the reference anymore. Call comes from the refFrom object
	// Tell our refTo object, that the link is cut
	void remove()
	{
		target_object_destroy_link();
		delink();
		_ref_to = nullptr;
		_ref_from = nullptr;
	}

	// Link is invalid due to destruction of referenced target object. Call comes from the refTo object
	// Tell our refFrom object, that the link is cut
	void invalidate()                                   // the _ref_from MUST remain!!
	{
		source_object_destroy_link();
		delink();
		_ref_to = nullptr;
	}

	bool is_valid() const                                // Only check the _ref_to
	{
		return _ref_to != nullptr;
	}

	Reference<TO, FROM> *next()       { return((Reference<TO, FROM> *) Element::next()); }
	Reference<TO, FROM> const *next() const { return((Reference<TO, FROM> const*) Element::next()); }
	Reference<TO, FROM> *prev()       { return((Reference<TO, FROM> *) Element::prev()); }
	Reference<TO, FROM> const *prev() const { return((Reference<TO, FROM> const*) Element::prev()); }

	Reference<TO, FROM> *nocheck_next()       { return((Reference<TO, FROM> *) Element::nocheck_next()); }
	Reference<TO, FROM> const *nocheck_next() const { return((Reference<TO, FROM> const *) Element::nocheck_next()); }
	Reference<TO, FROM> *nocheck_prev()       { return((Reference<TO, FROM> *) Element::nocheck_prev()); }
	Reference<TO, FROM> const *nocheck_prev() const { return((Reference<TO, FROM> const *) Element::nocheck_prev()); }

	TO *operator->() const { return _ref_to; }
	TO *target() const { return _ref_to; }

	FROM *source() const { return _ref_from; }

private:
	Reference(Reference const&) = delete;
	Reference& operator=(Reference const&) = delete;
};
}
}
}

#endif
