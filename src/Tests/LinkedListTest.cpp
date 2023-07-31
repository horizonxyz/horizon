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
 * Base Author - Sagun Khosla <sagunxp@gmail.com>
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

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "LinkedListTest"

#include "Core/Structures/LinkedList/Element.hpp"
#include "Core/Structures/LinkedList/Head.hpp"
#include <boost/test/unit_test.hpp>
#include <cstring>
#include <iostream>

class TestListElem : public Horizon::Structures::LinkedList::Element
{
public:
	TestListElem(int var)
	: Element(), _var(var) { }

	int get_var() const { return _var; }
	void set_var(int var) { _var = var; }

private:
	int _var;
};

class TestListHead : public Horizon::Structures::LinkedList::Head
{
public:
	typedef Head::Iterator<TestListElem> iterator;
	TestListElem *first() { return static_cast<TestListElem *> (Head::first()); }
	TestListElem const *first() const { return static_cast<TestListElem const *> (Head::first()); }

	TestListElem *last() { return static_cast<TestListElem *> (Head::last()); }
	TestListElem const *last() const { return static_cast<TestListElem const *> (Head::last()); }

	iterator begin() { return iterator(first()); }
	iterator end()   { return iterator(last()); }
};

BOOST_AUTO_TEST_CASE(LinkedListTest)
{
	int var[10000];
	TestListHead h;

	std::shared_ptr<TestListElem> t[10000];

	for (int i = 0; i < 10000; i++) {
		var[i] = i;
		t[i] = std::make_shared<TestListElem>(var[i]);
		h.push_front(t[i].get());
		BOOST_CHECK_EQUAL(h.first()->get_var(), var[i]);
	}

	int idx = 9999;
	for (TestListHead::iterator it = h.begin(); it != TestListHead::iterator(nullptr); ++it) {
		printf("pre-increment: %d\n", it->get_var());
		BOOST_CHECK_EQUAL(it->get_var(), var[idx--]);
	}

	idx = 9999;
	for (TestListHead::iterator it = h.begin(); it != TestListHead::iterator(nullptr); it++) {
		printf("reverse post-increment: %d\n", it->get_var());
		BOOST_CHECK_EQUAL(it->get_var(), var[idx--]);
	}

	idx = 0;
	for (TestListHead::iterator it = h.end(); it != TestListHead::iterator(nullptr); --it) {
		printf("pre-decrement: %d\n", it->get_var());
		BOOST_CHECK_EQUAL(it->get_var(), var[idx++]);
	}

	idx = 0;
	for (TestListHead::iterator it = h.end(); it != TestListHead::iterator(nullptr); it--) {
		printf("post-decrement: %d\n", it->get_var());
		BOOST_CHECK_EQUAL(it->get_var(), var[idx++]);
	}
}