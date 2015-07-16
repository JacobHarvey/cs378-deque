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
               deque<int>,
                my_deque<int>
               >
        deque_types;

TYPED_TEST_CASE(Deque_Fixture, deque_types);


TYPED_TEST(Deque_Fixture, test_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (1);
    ASSERT_EQ(x.size(),1);
    ASSERT_EQ(x[0],0);}


TYPED_TEST(Deque_Fixture, test_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (18, 0);
    ASSERT_EQ(x.size(),18);
    ASSERT_EQ(x[17],0);}

TYPED_TEST(Deque_Fixture, constructor_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (18, 2);
    ASSERT_EQ(x.size(),18);
    ASSERT_EQ(x[17],2);
		//deque_type y(x);
		//ASSERT_EQ(y[4],2);
}

TYPED_TEST(Deque_Fixture, copy_construct_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (100, 9);
    ASSERT_EQ(x.size(),100);
    ASSERT_EQ(x[99],9);
		deque_type y(x);
		ASSERT_EQ(y[63],9);}

TYPED_TEST(Deque_Fixture, copy_construct_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (18, 2);
    ASSERT_EQ(x.size(),18);
    ASSERT_EQ(x[17],2);
	deque_type y(x);
	ASSERT_EQ(y[4],2);}

TYPED_TEST(Deque_Fixture, copy_construct_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (50, 0);
    ASSERT_EQ(x.size(),50);
    ASSERT_EQ(x[49],0);
		deque_type y(x);
		ASSERT_EQ(y[4],0);}


TYPED_TEST(Deque_Fixture, test_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (18);
    ASSERT_EQ(x.size(),18);
    ASSERT_EQ(x[17],0);}

TYPED_TEST(Deque_Fixture, front_test_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (18);
    ASSERT_EQ(x.size(),18);
    ASSERT_EQ(x.front(),0);}

TYPED_TEST(Deque_Fixture, test_4) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    ASSERT_EQ(x[999],0);}

TYPED_TEST(Deque_Fixture, test_5) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    ASSERT_EQ(x.at(0),0);
    ASSERT_EQ(x.at(9),0);
    ASSERT_EQ(x.at(99),0);
    ASSERT_EQ(x.at(999),0);}

TYPED_TEST(Deque_Fixture, test_6) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    ASSERT_EQ(x.at(9),0);
    ASSERT_EQ(x.at(99),0);
    ASSERT_EQ(x.at(999),0);}

TYPED_TEST(Deque_Fixture, test_middle_element_1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (500, 5);
    ASSERT_EQ(x.size(),500);
    ASSERT_EQ(x.at(0),5);
    ASSERT_EQ(x.at(59),5);
    ASSERT_EQ(x.at(159),5);
    ASSERT_EQ(x.at(299),5);
    ASSERT_EQ(x.at(499),5);}

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

TYPED_TEST(Deque_Fixture, test_end_1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (1000, 2);
    typename deque_type::iterator iter = x.end();
    --iter;
    ++*iter;
    ASSERT_EQ(x.at(400),2);
    ASSERT_EQ(x.at(999),3);}

TYPED_TEST(Deque_Fixture, test_back_1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (1000, 2);
    typename deque_type::iterator iter = x.end();
    --iter;
    ++*iter;
    ASSERT_EQ(x.at(400),2);
    ASSERT_EQ(x.back(),3);}



TYPED_TEST(Deque_Fixture, iterator_1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    typename deque_type::iterator b = x.begin();
		for (int i = 0; i<999; i++){
			++b;}
		ASSERT_EQ(x.at(999),*b);}
/*
TYPED_TEST(Deque_Fixture, iterator_2) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (500);
    ASSERT_EQ(x.size(),500);
    typename deque_type::iterator b = x.begin();
	for (int i = 0; i<500; i++){
			++b;}
	ASSERT_EQ(x.end(),b);}
*/
TYPED_TEST(Deque_Fixture, test_resize_1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    x.resize(500);
    ASSERT_EQ(x.size(), 500);}

TYPED_TEST(Deque_Fixture, test_resize_2) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (10);
    ASSERT_EQ(x.size(),10);
    x.resize(500);
    ASSERT_EQ(x.size(), 500);}

TYPED_TEST(Deque_Fixture, test_resize_3) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (10);
    ASSERT_EQ(x.size(),10);
    x.resize(15);
    ASSERT_EQ(x.size(), 15);}

TYPED_TEST(Deque_Fixture, test_push_front_1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (10, 4);
    ASSERT_EQ(x.size(),10);
    x.push_front (2);
    ASSERT_EQ(*x.begin(), 2);
    ASSERT_EQ (*(++x.begin()), 4);}
TYPED_TEST(Deque_Fixture, test){
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(50);
    x[0] = 300;
    x[1] = 0;
    x[2] = 0;
    x[49] = 99;
    EXPECT_EQ(x.size(), 50);
    EXPECT_EQ(x[0], 300);
    EXPECT_EQ(x[1], 0);
    EXPECT_EQ(x[2], 0);
    EXPECT_EQ(x[49], 99);
}
// ---------
// Operators
// ---------
TYPED_TEST(Deque_Fixture, oper_eq_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(5);
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 4;
    x[4] = 5;
    deque_type y(5);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[3] = 4;
    y[4] = 5;
    EXPECT_TRUE(y == x);}
    
TYPED_TEST(Deque_Fixture, oper_eq_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(1);
    deque_type y(0);
    EXPECT_FALSE(x == y);
    x.pop_front();
    EXPECT_TRUE(x == y);}
    
TYPED_TEST(Deque_Fixture, oper_eq_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(3);
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    deque_type y(5);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[3] = 4;
    y[4] = 5;
    ASSERT_FALSE(x == y);}

TYPED_TEST(Deque_Fixture, oper_assign_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(3);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    deque_type x = y; 
    EXPECT_EQ(1, x[0]);
    EXPECT_EQ(2, x[1]);
    EXPECT_EQ(3, x[2]);}
    /*
TYPED_TEST(Deque_Fixture, oper_assign_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(3);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    deque_type x = y; 
    y.push_back(4);
    y.push_back(5); 
    ASSERT_NE(x, y);}
TYPED_TEST(Deque_Fixture, oper_assign_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(1);
    y[0] = 9;
    deque_type x = y; 
    y.push_front(4);
    ASSERT_NE(x, y);}
*/

// --------------
// Element Access
// --------------
TYPED_TEST(Deque_Fixture, access_index_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(3);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[0] = 9;
    EXPECT_EQ(9,y[0]);}
TYPED_TEST(Deque_Fixture, access_index_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(3);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[2] = 9;
    EXPECT_EQ(9,y[2]);}
TYPED_TEST(Deque_Fixture, access_index_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(3);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y.push_back(4);
    y[3] = 9;
    EXPECT_EQ(9,y[3]);}

TYPED_TEST(Deque_Fixture, access_at_index_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(3);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y.at(0) = 9;
    EXPECT_EQ(9,y[0]);}
TYPED_TEST(Deque_Fixture, access_at_index_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(3);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y.at(2) = 9;
    EXPECT_EQ(9,y[2]);}
TYPED_TEST(Deque_Fixture, access_at_index_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(3);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y.push_back(4);
    y.at(3) = 9;
    EXPECT_EQ(9,y[3]);}

TYPED_TEST(Deque_Fixture, access_front_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(1);
    y[0] = 1;
    EXPECT_EQ(1, y.front());}
TYPED_TEST(Deque_Fixture, access_front_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(0);
    y.push_front(1); 
    EXPECT_EQ(1, y.front());}
TYPED_TEST(Deque_Fixture, access_front_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(5);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[3] = 4;
    y[4] = 5;
    y.pop_front(); 
    y.push_front(6);
    EXPECT_EQ(6, y.front());}

TYPED_TEST(Deque_Fixture, access_back_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(3);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    ASSERT_TRUE(3 == y.back());}
TYPED_TEST(Deque_Fixture, access_back_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(1);
    y[0] = 1;
    ASSERT_TRUE(1 == y.back());}
TYPED_TEST(Deque_Fixture, access_back_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(4);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[3] = 4;
    y.push_back(5); 
    EXPECT_EQ(5, y.back());}
TYPED_TEST(Deque_Fixture, access_back_4){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(4);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[3] = 4;
    y.push_front(5); 
    EXPECT_EQ(4, y.back());}

//------------------------------------------
// no test written for const_iterator begin()
//-------------------------------------------

// --------------
// deque iterator
// --------------
TYPED_TEST(Deque_Fixture, deq_begin_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(1);
    y[0] = 0;
    *(y.begin()) = 1; 
    EXPECT_EQ(1, *(y.begin()) );}
TYPED_TEST(Deque_Fixture, deq_begin_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(4);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[3] = 4;
    y.push_front(5); 
    *(y.begin()) = 5; 
    EXPECT_EQ(5, *(y.begin() ));}
TYPED_TEST(Deque_Fixture, deq_begin_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(1);
    y[0] = 0;
    y.push_front(5); 
    int x =  *(y.begin()) = *(y.begin())+1; 
    EXPECT_EQ(6, x);}

TYPED_TEST(Deque_Fixture, deq_end_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(3);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y.push_back(4);
    int endValue = *(y.end()-1); 
    EXPECT_EQ(4, endValue);}
TYPED_TEST(Deque_Fixture, deq_end_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(1);
    y[0] = 1;
    int endValue = *(y.end()-1); 
    EXPECT_EQ(1, endValue);}
TYPED_TEST(Deque_Fixture, deq_end_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(2);
    y[0] = 0;
    y[1] = 1;
    y.pop_back(); 
    int endValue = *(y.end()-1); 
    EXPECT_EQ(0, endValue);}

// --------
// capacity
// --------
TYPED_TEST(Deque_Fixture, cap_resize_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(5);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[3] = 4;
    y[4] = 5;
    y.resize(1);
    EXPECT_EQ(1, y.size());
    EXPECT_EQ(1, y[0]);}
TYPED_TEST(Deque_Fixture, cap_resize_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(5);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[3] = 4;
    y[4] = 5;
    y.resize(0); 
    EXPECT_EQ(0, y.size());}
TYPED_TEST(Deque_Fixture, cap_resize_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(0);
    y.resize(5);
    EXPECT_EQ(5, y.size());
    EXPECT_EQ(0, y[4]);}
TYPED_TEST(Deque_Fixture, cap_resize_4){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(0);
    y.resize(5);
    y.push_front(1); 
    y.resize(1);
    EXPECT_EQ(1, y[0]);
    y.resize(2);
    y.pop_front();
    y.resize(0);
    EXPECT_EQ(0, y.size());}

// ---------
// modifiers
// ---------
TYPED_TEST(Deque_Fixture, mod_erase_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(1);
    y[0] = 0;
    y.erase(y.begin()); 
    EXPECT_EQ(0, y.size());}
TYPED_TEST(Deque_Fixture, mod_erase_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(5);
    y[0] = 0;
    y[1] = 1;
    y[2] = 2;
    y[3] = 3;
    y[4] = 4;
    y.erase(y.begin()); 
    EXPECT_EQ(4, y[3]);}
TYPED_TEST(Deque_Fixture, mod_erase_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(1);
    y[0] = 0;
    y.erase(y.begin());
    EXPECT_EQ(0, y.size());}
TYPED_TEST(Deque_Fixture, mod_erase_4){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(5);
    y[0] = 0;
    y[1] = 1;
    y[2] = 2;
    y[3] = 3;
    y[4] = 4;
    y.erase(y.end()-1); 
    EXPECT_EQ(y.size(), 4);
    EXPECT_EQ(y[4], 4);}

TYPED_TEST(Deque_Fixture, mod_clear_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(5);
    y[0] = 1;
    y[1] = 2;
    y[2] = 3;
    y[3] = 4;
    y[4] = 5;
    y.clear(); 
    EXPECT_EQ(0, y.size());}
TYPED_TEST(Deque_Fixture, mod_clear_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(0);
    y.clear();
    EXPECT_EQ(0, y.size());}
TYPED_TEST(Deque_Fixture, mod_clear_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type y(0);
    y.clear();
    y.push_back(1);
    y.push_back(2);
    EXPECT_EQ(2, y.size());}

TYPED_TEST(Deque_Fixture, mod_swap_1){
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (0); 
    deque_type y (1,50); 
    y.swap(x); 
    EXPECT_EQ(0, y.size());
    EXPECT_EQ(50, x[0]);}
TYPED_TEST(Deque_Fixture, mod_swap_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(1);
    x[0] = 1;
    deque_type y(2);
    y[0] = 2;
    y.swap(x); 
    EXPECT_EQ(1, y[0]);
    EXPECT_EQ(2, x[0]);}
TYPED_TEST(Deque_Fixture, mod_swap_3){
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (50,2); 
    deque_type y (51,1); 
    y.swap(x); 
    EXPECT_EQ(50, y.size());
    EXPECT_EQ(1, x[50]);}

TYPED_TEST(Deque_Fixture, cons_test_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(),0);}

TYPED_TEST(Deque_Fixture, cons_test_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(),0);}

TYPED_TEST(Deque_Fixture, cons_test_3) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z);
    ASSERT_EQ(x.size(), 50);
}

TYPED_TEST(Deque_Fixture, cons_test_4) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 52;
    deque_type x(z, 100);
    ASSERT_EQ(x.size(), 52);
}


TYPED_TEST(Deque_Fixture, cons_test_5) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 52;
    deque_type x(z, 100);
    ASSERT_EQ(x.at(5), 100);
    deque_type y(x);
    ASSERT_EQ(x.size(), 52);
    ASSERT_EQ(y.size(), 52);
    ASSERT_EQ(x.at(5), 100);
    ASSERT_EQ(y.at(5), 100);
    ASSERT_EQ(x.back(), 100);
    ASSERT_EQ(x[51], 100);
}

TYPED_TEST(Deque_Fixture, cons_test_6) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 52;
    deque_type x(z, 100);
    ASSERT_EQ(x.at(5), 100);
    deque_type y(x);
    ASSERT_EQ(x.size(), 52);
    ASSERT_EQ(y.size(), 52);
    ASSERT_EQ(x.at(5), 100);
    ASSERT_EQ(y.at(5), 100);
    y.back() = 99;
    ASSERT_FALSE(x.back() == y.back());
    ASSERT_EQ(x.back(), 100);
    ASSERT_EQ(x[51], 100);
}

TYPED_TEST(Deque_Fixture, cons_test_7) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    deque_type y(10, 1);
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(),0);
    x = y;
    ASSERT_EQ(x.size(),10);
    ASSERT_EQ(x[1],1);
}

TYPED_TEST(Deque_Fixture, cons_test_8) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 51;
    deque_type x(z);
    ASSERT_EQ(x.size(), 51);
}

TYPED_TEST(Deque_Fixture, cons_test_9) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 52;
    deque_type x(z);
    ASSERT_EQ(x.size(), 52);
}

TYPED_TEST(Deque_Fixture, cons_test_10) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 53;
    deque_type x(z);
    ASSERT_EQ(x.size(), 53);
}

TYPED_TEST(Deque_Fixture, cons_test_11) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 54;
    deque_type x(z);
    ASSERT_EQ(x.size(), 54);
}

TYPED_TEST(Deque_Fixture, cons_test_12) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 55;
    deque_type x(z);
    ASSERT_EQ(x.size(), 55);
}

TYPED_TEST(Deque_Fixture, cons_test_13) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 56;
    deque_type x(z);
    ASSERT_EQ(x.size(), 56);
}

TYPED_TEST(Deque_Fixture, cons_test_14) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 57;
    deque_type x(z);
    ASSERT_EQ(x.size(), 57);
}

TYPED_TEST(Deque_Fixture, cons_test_15) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 58;
    deque_type x(z);
    ASSERT_EQ(x.size(), 58);
}

TYPED_TEST(Deque_Fixture, cons_test_16) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 59;
    deque_type x(z);
    ASSERT_EQ(x.size(), 59);
}

TYPED_TEST(Deque_Fixture, cons_test_17) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 60;
    deque_type x(z);
    ASSERT_EQ(x.size(), 60);
}

TYPED_TEST(Deque_Fixture, cons_test_18) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 61;
    deque_type x(z);
    ASSERT_EQ(x.size(), 61);
}

TYPED_TEST(Deque_Fixture, cons_test_19) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 62;
    deque_type x(z);
    ASSERT_EQ(x.size(), 62);
}

TYPED_TEST(Deque_Fixture, cons_test_20) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 63;
    deque_type x(z);
    ASSERT_EQ(x.size(), 63);
}

TYPED_TEST(Deque_Fixture, cons_test_21) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 64;
    deque_type x(z);
    ASSERT_EQ(x.size(), 64);
}

TYPED_TEST(Deque_Fixture, cons_test_22) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 65;
    deque_type x(z);
    ASSERT_EQ(x.size(), 65);
}

TYPED_TEST(Deque_Fixture, cons_test_23) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 66;
    deque_type x(z);
    ASSERT_EQ(x.size(), 66);
}

TYPED_TEST(Deque_Fixture, cons_test_24) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 67;
    deque_type x(z);
    ASSERT_EQ(x.size(), 67);
}

TYPED_TEST(Deque_Fixture, cons_test_25) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 68;
    deque_type x(z);
    ASSERT_EQ(x.size(), 68);
}

TYPED_TEST(Deque_Fixture, cons_test_26) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 69;
    deque_type x(z);
    ASSERT_EQ(x.size(), 69);
}

TYPED_TEST(Deque_Fixture, cons_test_27) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 70;
    deque_type x(z);
    ASSERT_EQ(x.size(), 70);
}

TYPED_TEST(Deque_Fixture, cons_test_28) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 71;
    deque_type x(z);
    ASSERT_EQ(x.size(), 71);
}

TYPED_TEST(Deque_Fixture, cons_test_29) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 72;
    deque_type x(z);
    ASSERT_EQ(x.size(), 72);
}

TYPED_TEST(Deque_Fixture, cons_test_30) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 73;
    deque_type x(z);
    ASSERT_EQ(x.size(), 73);
}

TYPED_TEST(Deque_Fixture, cons_test_31) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 74;
    deque_type x(z);
    ASSERT_EQ(x.size(), 74);
}

TYPED_TEST(Deque_Fixture, cons_test_32) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 75;
    deque_type x(z);
    ASSERT_EQ(x.size(), 75);
}

// -----
// Index Tests
// -----

TYPED_TEST(Deque_Fixture, index_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 50);
    ASSERT_EQ(x[0], 1);
}

TYPED_TEST(Deque_Fixture, index_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 50);
    ASSERT_EQ(x.at(5), 1);
}

TYPED_TEST(Deque_Fixture, index_test_3) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 1000;
    deque_type x(z, 25);
    ASSERT_EQ(x.size(), 1000);
    ASSERT_EQ(x.at(100), 25);
}

TYPED_TEST(Deque_Fixture, index_test_4) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 50);
    ASSERT_EQ(x[0], 1);
}

TYPED_TEST(Deque_Fixture, index_test_5) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 51;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 51);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_6) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 52;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 52);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_7) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 53;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 53);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_8) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 54;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 54);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_9) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 55;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 55);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_10) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 56;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 56);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_11) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 57;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 57);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_12) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 58;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 58);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_13) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 59;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 59);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_14) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 60;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 60);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_15) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 61;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 61);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_16) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 62;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 62);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_17) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 63;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 63);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_18) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 64;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 64);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_19) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 65;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 65);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_20) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 66;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 66);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_21) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 67;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 67);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_22) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 68;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 68);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_23) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 69;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 69);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_24) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 70;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 70);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_25) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 71;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 71);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_26) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 72;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 72);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_27) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 73;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 73);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_28) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 74;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 74);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_29) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 75;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 75);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_30) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 76;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 76);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_31) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 77;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 77);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_32) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 78;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 78);
    ASSERT_EQ(x[0], 1);
}
TYPED_TEST(Deque_Fixture, index_test_33) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 79;
    deque_type x(z, 1);
    ASSERT_EQ(x.size(), 79);
    ASSERT_EQ(x[0], 1);
}


// -----
// assignment Tests
// -----

TYPED_TEST(Deque_Fixture, assignment_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 52;
    deque_type x(z, 100);
    ASSERT_EQ(x.at(5), 100);
    deque_type y(z, 0);
    ASSERT_EQ(x.size(), 52);
    ASSERT_EQ(y.size(), 52);
    ASSERT_EQ(x.at(5), 100);
    ASSERT_EQ(y.at(5), 0);
    y = x;
    ASSERT_EQ(y.at(5), 100);
}


TYPED_TEST(Deque_Fixture, assignment_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(7, 100);
    deque_type y(3, 0);
    x = y;
    //ASSERT_EQ(x[5], 0);
}


TYPED_TEST(Deque_Fixture, assignment_test_3) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(100, 100);
    deque_type y(99, 0);
    x = y;
    ASSERT_EQ(x[5], 0);
}

TYPED_TEST(Deque_Fixture, assignment_test_4) {
    typedef typename TestFixture::deque_type deque_type;
   
    deque_type x(100, 100);
    deque_type y(101, 4);
    x = y;
    ASSERT_EQ(x[5], 4);
}

// -----
// Resize Tests
// -----

TYPED_TEST(Deque_Fixture, resize_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(51, 5);
    ASSERT_EQ(x.size(), 51);
}

TYPED_TEST(Deque_Fixture, resize_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 55;
    deque_type x(z, 1);
    x.resize(70, 5);
    ASSERT_EQ(x.size(), 70);
    ASSERT_EQ(x.back(), 5);
}

TYPED_TEST(Deque_Fixture, resize_test_3) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 55;
    deque_type x(z, 1);
    x.resize(1, 1);
    ASSERT_EQ(x.size(), 1);
    ASSERT_EQ(x.back(), 1);
}

TYPED_TEST(Deque_Fixture, resize_test_4) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 55;
    deque_type x(z, 1);
    x.resize(54, 1);
    ASSERT_EQ(x.size(), 54);
    ASSERT_EQ(x.back(), 1);
}

TYPED_TEST(Deque_Fixture, resize_test_5) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 7;
    deque_type x(z, 1);
    x.resize(6, 1);
    ASSERT_EQ(x.size(), 6);
    ASSERT_EQ(x.back(), 1);
}

TYPED_TEST(Deque_Fixture, resize_test_7) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 55;
    deque_type x(z, 1);
    x.resize(1, 1);
    ASSERT_EQ(x.size(), 1);
    ASSERT_EQ(x.back(), 1);
}

TYPED_TEST(Deque_Fixture, resize_test_8) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(52, 5);
    ASSERT_EQ(x.size(), 52);
}

TYPED_TEST(Deque_Fixture, resize_test_9) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(53, 5);
    ASSERT_EQ(x.size(), 53);
}

TYPED_TEST(Deque_Fixture, resize_test_10) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(54, 5);
    ASSERT_EQ(x.size(), 54);
}

TYPED_TEST(Deque_Fixture, resize_test_11) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(55, 5);
    ASSERT_EQ(x.size(), 55);
}

TYPED_TEST(Deque_Fixture, resize_test_12) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(56, 5);
    ASSERT_EQ(x.size(), 56);
}

TYPED_TEST(Deque_Fixture, resize_test_13) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(57, 5);
    ASSERT_EQ(x.size(), 57);
}

TYPED_TEST(Deque_Fixture, resize_test_14) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(58, 5);
    ASSERT_EQ(x.size(), 58);
}

TYPED_TEST(Deque_Fixture, resize_test_15) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(59, 5);
    ASSERT_EQ(x.size(), 59);
}

TYPED_TEST(Deque_Fixture, resize_test_16) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(60, 5);
    ASSERT_EQ(x.size(), 60);
}

TYPED_TEST(Deque_Fixture, resize_test_17) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(61, 5);
    ASSERT_EQ(x.size(), 61);
}

TYPED_TEST(Deque_Fixture, resize_test_18) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(62, 5);
    ASSERT_EQ(x.size(), 62);
}

TYPED_TEST(Deque_Fixture, resize_test_19) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(63, 5);
    ASSERT_EQ(x.size(), 63);
}

TYPED_TEST(Deque_Fixture, resize_test_20) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(64, 5);
    ASSERT_EQ(x.size(), 64);
}

TYPED_TEST(Deque_Fixture, resize_test_22) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(65, 5);
    ASSERT_EQ(x.size(), 65);
}

TYPED_TEST(Deque_Fixture, resize_test_23) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(66, 5);
    ASSERT_EQ(x.size(), 66);
}

TYPED_TEST(Deque_Fixture, resize_test_24) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(67, 5);
    ASSERT_EQ(x.size(), 67);
}

TYPED_TEST(Deque_Fixture, resize_test_25) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(68, 5);
    ASSERT_EQ(x.size(), 68);
}

TYPED_TEST(Deque_Fixture, resize_test_26) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(69, 5);
    ASSERT_EQ(x.size(), 69);
}

TYPED_TEST(Deque_Fixture, resize_test_27) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(70, 5);
    ASSERT_EQ(x.size(), 70);
}

TYPED_TEST(Deque_Fixture, resize_test_28) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(71, 5);
    ASSERT_EQ(x.size(), 71);
}

TYPED_TEST(Deque_Fixture, resize_test_29) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(72, 5);
    ASSERT_EQ(x.size(), 72);
}

TYPED_TEST(Deque_Fixture, resize_test_30) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(73, 5);
    ASSERT_EQ(x.size(), 73);
}

TYPED_TEST(Deque_Fixture, resize_test_31) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(74, 5);
    ASSERT_EQ(x.size(), 74);
}

TYPED_TEST(Deque_Fixture, resize_test_32) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(75, 5);
    ASSERT_EQ(x.size(), 75);
}

TYPED_TEST(Deque_Fixture, resize_test_33) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(76, 5);
    ASSERT_EQ(x.size(), 76);
}


TYPED_TEST(Deque_Fixture, resize_test_34) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(51, 5);
    ASSERT_EQ(x.size(), 51);
}

TYPED_TEST(Deque_Fixture, resize_test_35) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.resize(51, 5);
    ASSERT_EQ(x.size(), 51);
}



// -----
// Back Tests
// -----

TYPED_TEST(Deque_Fixture, back_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.back() = 100;
    ASSERT_EQ(x.size(), 50);
    ASSERT_EQ(x[49],100);

}

TYPED_TEST(Deque_Fixture, back_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 10000;
    deque_type x(z, 0);
    x.back() = 100;
    x.front() = 99;
    ASSERT_EQ(x.size(), z);
    ASSERT_EQ(x[z-1],100);
    ASSERT_EQ(x[0],99);

}

// -----
// Clear Tests
// -----


TYPED_TEST(Deque_Fixture, clear_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.clear();
    ASSERT_EQ(x.size(), 0);
}


TYPED_TEST(Deque_Fixture, clear_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x;
    x.clear();
    ASSERT_TRUE(x.empty());
}

// -----
// iterator Tests
// -----


// -----
// Push_back Tests
// -----


TYPED_TEST(Deque_Fixture, push_back_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 0);
    x.push_back(1);
    ASSERT_EQ(x.size(), 51);
    ASSERT_EQ(x.back(), 1);
}

TYPED_TEST(Deque_Fixture, push_back_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 0);
    x.push_back(1);
    x.push_back(2);
    ASSERT_EQ(x.size(), 52);
    ASSERT_EQ(x.back(), 2);
}

TYPED_TEST(Deque_Fixture, push_back_test_3) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 9;
    deque_type x(z, 0);
    x.push_back(1);
    x.push_back(2);
    ASSERT_EQ(x.size(), 11);
    ASSERT_EQ(x.back(), 2);
}

// -----
// Push_front Tests
// -----

TYPED_TEST(Deque_Fixture, push_front_test_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(3);
    ASSERT_EQ(x.front(), 0);
    x.push_front(1);
    ASSERT_EQ(x.front(), 1);
    }
    

TYPED_TEST(Deque_Fixture, push_front_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 0);
    x.push_front(1);
    ASSERT_EQ(x.size(), 51);
    ASSERT_EQ(x.front(), 1);
}

TYPED_TEST(Deque_Fixture, push_front_test_3) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 0);
    x.push_front(1);
    x.push_front(2);
    ASSERT_EQ(x.size(), 52);
    ASSERT_EQ(x.front(), 2);
}

TYPED_TEST(Deque_Fixture, push_front_test_4) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 9;
    deque_type x(z, 0);
    x.push_front(1);
    ASSERT_EQ(x.size(), 10);
    ASSERT_EQ(x.front(), 1);
}

// -----
// pop_back Tests
// -----


TYPED_TEST(Deque_Fixture, pop_back_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x[48] = 2;
    x.pop_back();
    ASSERT_EQ(x.size(), 49);
    ASSERT_EQ(x.back(), 2);
}

TYPED_TEST(Deque_Fixture, pop_back_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.push_back(2);
    x[49] = 50;
    x.pop_back();
    ASSERT_EQ(x.size(), 50);
    ASSERT_EQ(x.back(), 50);
}


TYPED_TEST(Deque_Fixture, pop_back_test_3) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x;
    x.push_back(1);
    ASSERT_EQ(x.size(), 1);
    ASSERT_EQ(x.front(), 1);
    ASSERT_EQ(x.back(), 1);
    x.pop_back();
    ASSERT_EQ(x.size(), 0);
}

TYPED_TEST(Deque_Fixture, pop_back_test_4) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x;
    x.push_front(1);
    ASSERT_EQ(x.size(), 1);
    ASSERT_EQ(x.front(), 1);
    ASSERT_EQ(x.back(), 1);
    x.pop_back();
    ASSERT_EQ(x.size(), 0);
}

TYPED_TEST(Deque_Fixture, pop_back_test_5) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x;
    x.push_front(1);
    ASSERT_EQ(x.size(), 1);
    ASSERT_EQ(x.front(), 1);
    ASSERT_EQ(x.back(), 1);
    x.pop_front();
    ASSERT_EQ(x.size(), 0);
}

TYPED_TEST(Deque_Fixture, pop_back_test_6) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x;
    x.push_back(1);
    ASSERT_EQ(x.size(), 1);
    ASSERT_EQ(x.front(), 1);
    ASSERT_EQ(x.back(), 1);
    x.pop_front();
    ASSERT_EQ(x.size(), 0);
}


// -----
// pop_front Tests
// -----

TYPED_TEST(Deque_Fixture, pop_front_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x[1] = 2;
    x.pop_front();
    ASSERT_EQ(x.size(), 49);
    ASSERT_EQ(x.front(), 2);
}

TYPED_TEST(Deque_Fixture, pop_front_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    int z = 50;
    deque_type x(z, 1);
    x.push_front(2);
    x[1] = 50;
    x.pop_front();
    ASSERT_EQ(x.size(), 50);
    ASSERT_EQ(x.front(), 50);
}


// -----
// Swap Tests
// -----

TYPED_TEST(Deque_Fixture, swap_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(100, 100);
    deque_type y(100, 4);
    x.swap(y);
    ASSERT_EQ(x[1], 4);
}

// -----
// Insert Tests
// -----

TYPED_TEST(Deque_Fixture, insert_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(50);
    typename deque_type::iterator it = x.begin();
    x.insert(it, 5);
    ASSERT_EQ(x.front(), 5);
}

TYPED_TEST(Deque_Fixture, insert_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(50);
    typename deque_type::iterator it = x.end();
    x.insert(it, 5);
    ASSERT_EQ(x.back(), 5);
}

TYPED_TEST(Deque_Fixture, insert_test_3) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(50);
    typename deque_type::iterator it = x.begin();
    it += 5;
    x.insert(it, 5);
    ASSERT_EQ(x[5], 5);
}

TYPED_TEST(Deque_Fixture, erase_test_1) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(50);
    x[1] = 2;
    typename deque_type::iterator it = x.begin();
    x.erase(it);
    ASSERT_EQ(x.front(), 2);
}

/*
TYPED_TEST(Deque_Fixture, erase_test_2) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(50);
    x[48] = 2;
    typename deque_type::iterator it = x.end();
    x.erase(it);
    //should do nothing because not valid address
    ASSERT_EQ(x.back(), 0);
}
*/

TYPED_TEST(Deque_Fixture, erase_test_3) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(50);
    x[6] = 5;
    typename deque_type::iterator it = x.begin();
    it += 4;
    x.erase(it);
    ASSERT_EQ(x[5], 5);
}






        // --------
        // iterator
        // --------

                // -----------
                // operator ==
                // -----------

                TYPED_TEST(Deque_Fixture, iter_equality_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(5); x[0] = 1; x[1] = 4;
                    deque_type y(5); y[0] = 1; y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ASSERT_FALSE(x_b == y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_equality_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;
                    deque_type y(2); y[0] = 1; y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ++x_b;
                    ++y_b;

                    ASSERT_FALSE(x_b == y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_equality_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator x_e = x.end();

                    ++x_b;
                    ++x_b;

                    ASSERT_TRUE(x_b == x_e);
                }

                // -----------
                // operator !=
                // -----------

                TYPED_TEST(Deque_Fixture, iter_inequality_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(5); x[0] = 1; x[1] = 4;
                    deque_type y(5); y[0] = 1; y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ASSERT_TRUE(x_b != y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_inequality_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;
                    deque_type y(2); y[0] = 1; y[1] = 3;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator y_b = y.begin();

                    ++x_b;
                    ++y_b;

                    ASSERT_TRUE(x_b != y_b);
                }

                TYPED_TEST(Deque_Fixture, iter_inequality_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b = x.begin();
                    typename deque_type::iterator x_e = x.end();

                    ++x_b;
                    ++x_b;

                    ASSERT_FALSE(x_b != x_e);
                }

                // ----------
                // operator +
                // ----------

                TYPED_TEST(Deque_Fixture, iter_plus_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1;

                    ++x_b1;

                    ASSERT_TRUE(x_b1 == x_b2 + 1);
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    ASSERT_TRUE(x_b1 + 2 == x.end());
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    ASSERT_FALSE(x_b1 + 1 == x.begin());
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type _x(100, 10); _x[24] = 1;

                    const deque_type x = _x;

                    typename deque_type::const_iterator x_b1 = x.begin() + 24;

                    ASSERT_EQ(*x_b1, 1);
                }

                // ----------
                // operator -
                // ----------

                TYPED_TEST(Deque_Fixture, iter_minus_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin() + 1;

                    ASSERT_TRUE(x_b1 - 1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin();

                    ASSERT_TRUE(x_b1 - 2 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin();

                    ASSERT_FALSE(x_b1 - 1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus_op_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(92, 31); x[50] = 1;

                    typename deque_type::iterator x_b1 = x.end();

                    ASSERT_EQ(*(x_b1 - 42), 1);
                }


                // ----------
                // operator *
                // ----------

                TYPED_TEST(Deque_Fixture, iter_deref_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    ASSERT_EQ(*x_b1, 1);
                }

                TYPED_TEST(Deque_Fixture, iter_deref_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    ++x_b1;

                    ASSERT_EQ(*x_b1, 4);
                }

                TYPED_TEST(Deque_Fixture, iter_deref_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();

                    --x_b1;

                    ASSERT_EQ(*x_b1, 4);
                }

                // -----------
                // operator ->
                // -----------

                TYPED_TEST(Deque_Fixture, my_iter_arrow_op_test_1) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    my_deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin();

                    ASSERT_EQ(x_b1->a, 1);
                }

                TYPED_TEST(Deque_Fixture, my_iter_arrow_op_test_2) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    my_deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin();

                    ASSERT_EQ(x_b1->b, 3);
                }

                TYPED_TEST(Deque_Fixture, my_iter_arrow_op_test_3) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    my_deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin(); ++x_b1;

                    ASSERT_EQ(x_b1->b, 7);
                }

                TYPED_TEST(Deque_Fixture, iter_arrow_op_test_1) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin();

                    ASSERT_EQ(x_b1->a, 1);
                }

                TYPED_TEST(Deque_Fixture, iter_arrow_op_test_2) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin();

                    ASSERT_EQ(x_b1->b, 3);
                }

                TYPED_TEST(Deque_Fixture, iter_arrow_op_test_3) {
                    struct S {
                        int a;
                        int b;
                    };

                    struct S s_a; s_a.a = 1; s_a.b = 3;
                    struct S s_b; s_b.a = 5; s_b.b = 7;

                    deque<S> x(2); 
                    x[0] = s_a;
                    x[1] = s_b;

                    auto x_b1 = x.begin(); ++x_b1;

                    ASSERT_EQ(x_b1->b, 7);
                }

                // -----------
                // operator ++
                // -----------
                
                TYPED_TEST(Deque_Fixture, iter_pre_incr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1 + 1;

                    ++x_b1;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_pre_incr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1;

                    ++x_b1;

                    ASSERT_FALSE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_pre_incr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    ++x_b1;
                    ++x_b1;

                    ASSERT_TRUE(x_b1 == x.end());
                }

                // (prefix and postfix)

                TYPED_TEST(Deque_Fixture, iter_post_incr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1 + 1;

                    x_b1++;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_post_incr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1 + 1;

                    ASSERT_FALSE(x_b1++ == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_post_incr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    x_b1++;
                    x_b1++;

                    ASSERT_TRUE(x_b1 == x.end());
                }

                // -----------
                // operator --
                // -----------

                TYPED_TEST(Deque_Fixture, iter_pre_decr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x_b1 - 1;

                    --x_b1;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_pre_decr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x.end();
                    --x_b2;

                    ASSERT_FALSE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_pre_decr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x.end();

                    --x_b2;

                    ASSERT_TRUE(x_b1 == --x_b2);
                }

                // (prefix and postfix)

                TYPED_TEST(Deque_Fixture, iter_post_decr_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x_b1 - 1;

                    x_b1--;

                    ASSERT_TRUE(x_b1 == x_b2);
                }
/*
                TYPED_TEST(Deque_Fixture, iter_post_decr_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x_b1 - 2;

                    x_b2--;

                    ASSERT_FALSE(x_b2-- == x_b1);
                }
*/
                TYPED_TEST(Deque_Fixture, iter_post_decr_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x_b1 - 2;

                    x_b1--;
                    x_b1--;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                // -----------
                // operator +=
                // -----------

                TYPED_TEST(Deque_Fixture, iter_plus_op_equal_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();
                    typename deque_type::iterator x_b2 = x_b1;

                    x_b1 += 1;

                    ASSERT_TRUE(x_b1 == x_b2 + 1);
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_equal_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    x_b1 += 2;

                    ASSERT_TRUE(x_b1 == x.end());
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_equal_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.begin();

                    x_b1 += 1;

                    ASSERT_FALSE(x_b1 == x.begin());
                }

                TYPED_TEST(Deque_Fixture, iter_plus_op_equal_test_4) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(1000); x[324] = 42;

                    typename deque_type::iterator x_b1 = x.begin();

                    x_b1 += 324;

                    ASSERT_EQ(*x_b1, 42);
                }


                // -----------
                // operator -=
                // -----------

                TYPED_TEST(Deque_Fixture, iter_minus_equal_op_test_1) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin() + 1;

                    x_b1 -= 1;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus_equal_op_test_2) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin();

                    x_b1 -= 2;

                    ASSERT_TRUE(x_b1 == x_b2);
                }

                TYPED_TEST(Deque_Fixture, iter_minus_equal_op_test_3) {
                    typedef typename TestFixture::deque_type deque_type;

                    deque_type x(2); x[0] = 1; x[1] = 4;

                    typename deque_type::iterator x_b1 = x.end();
                    typename deque_type::iterator x_b2 = x.begin();

                    x_b1 -= 1;

                    ASSERT_FALSE(x_b1 == x_b2);
                }


// -------
// my_deque
// -------

        // -----------
        // operator ==
        // -----------

        TYPED_TEST(Deque_Fixture, deque_equality_op_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;

            ASSERT_TRUE(x == y);
        }

        TYPED_TEST(Deque_Fixture, deque_equality_op_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;
            ASSERT_FALSE(x == y);
        }

        TYPED_TEST(Deque_Fixture, deque_equality_op_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;
            ASSERT_FALSE(x == y);
        }

        // -----------
        // operator !=
        // -----------

        TYPED_TEST(Deque_Fixture, deque_inequality_op_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;
            ASSERT_FALSE(x != y);
        }

        TYPED_TEST(Deque_Fixture, deque_inequality_op_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(4); x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;
            ASSERT_TRUE(x != y);
        }

        TYPED_TEST(Deque_Fixture, deque_inequality_op_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;
            ASSERT_TRUE(x != y);
        }

        // ----------
        // operator <
        // ----------

        TYPED_TEST(Deque_Fixture, deque_less_than_op_test_1) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 2; x[2] = 3;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;

            ASSERT_FALSE(x < y);
        }

        TYPED_TEST(Deque_Fixture, deque_less_than_op_test_2) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(3); x[0] = 1; x[1] = 1; x[2] = 4;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;

            ASSERT_TRUE(x < y);
        }

        TYPED_TEST(Deque_Fixture, deque_less_than_op_test_3) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x(1); x[0] = 0;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;
            ASSERT_TRUE(x < y);
        }

        TYPED_TEST(Deque_Fixture, deque_less_than_op_test_4) {
            typedef typename TestFixture::deque_type deque_type;

            deque_type x;
            deque_type y(3); y[0] = 1; y[1] = 2; y[2] = 3;
            ASSERT_TRUE(x < y);
        }

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
