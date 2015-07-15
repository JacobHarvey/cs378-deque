// --------------------------------
// projects/c++/deque/TestDeque.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// http://www.cplusplus.com/reference/deque/deque/

// --------
// includes
// --------

#include <deque>     // deque
#include <stdexcept> // invalid_argument, out_of_range

#include "gtest/gtest.h"

#include "Deque.h"

// -----
// Using
// -----

using namespace std;

using testing::Test;
using testing::Types;

// -----
// Types
// -----

template <typename T>
struct Deque_Fixture : Test {
    typedef T                               deque_type;
    typedef typename deque_type::value_type value_type;};

typedef Types<
               //deque<int>
                my_deque<int>
               >
        deque_types;

TYPED_TEST_CASE(Deque_Fixture, deque_types);


TYPED_TEST(Deque_Fixture, test_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (1);
    ASSERT_EQ(x.size(),1);
    ASSERT_EQ(x[0],0);}


TYPED_TEST(Deque_Fixture, test_4) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (18, 0);
    ASSERT_EQ(x.size(),18);
    ASSERT_EQ(x[17],0);}


TYPED_TEST(Deque_Fixture, test_11) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (18);
    ASSERT_EQ(x.size(),18);
    ASSERT_EQ(x[17],0);}

TYPED_TEST(Deque_Fixture, test_5) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    ASSERT_EQ(x[999],0);}

TYPED_TEST(Deque_Fixture, test_6) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    ASSERT_EQ(x.at(0),0);
    ASSERT_EQ(x.at(9),0);
    ASSERT_EQ(x.at(99),0);
    ASSERT_EQ(x.at(999),0);}

TYPED_TEST(Deque_Fixture, test_8) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    ASSERT_EQ(x.at(9),0);
    ASSERT_EQ(x.at(99),0);
    ASSERT_EQ(x.at(999),0);}

TYPED_TEST(Deque_Fixture, test_middle_element_1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (500);
    ASSERT_EQ(x.size(),500);
    ASSERT_EQ(x.at(0),0);
    ASSERT_EQ(x.at(59),0);
    ASSERT_EQ(x.at(159),0);
    ASSERT_EQ(x.at(299),0);
    ASSERT_EQ(x.at(499),0);}

TYPED_TEST(Deque_Fixture, test_middle_element_2) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    ASSERT_EQ(x.at(0),0);
    ASSERT_EQ(x.at(9),0);
    ASSERT_EQ(x.at(25),0);
    ASSERT_EQ(x.at(38),0);
    ASSERT_EQ(x.at(67),0);
    ASSERT_EQ(x.at(400),0);
    ASSERT_EQ(x.at(999),0);}

TYPED_TEST(Deque_Fixture, test_7) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    typename deque_type::iterator b = x.begin();
		for (int i = 0; i<999; i++){
			++b;}
		ASSERT_EQ(x.at(999),*b);}

// -----
// Tests
// -----
/*
TYPED_TEST(Deque_Fixture, test_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(),0);}
*/
/*
TYPED_TEST(Deque_Fixture, test_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(5);
    ASSERT_TRUE(x.back()==5);
    ASSERT_EQ(x.size(),1);}
*/
