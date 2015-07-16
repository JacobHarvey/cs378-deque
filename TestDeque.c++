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
               //deque<int>,
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

TYPED_TEST(Deque_Fixture, iterator_2) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (500);
    ASSERT_EQ(x.size(),500);
    typename deque_type::iterator b = x.begin();
	for (int i = 0; i<500; i++){
			++b;}
	ASSERT_EQ(x.end(),b);}

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
    /*
TYPED_TEST(Deque_Fixture, oper_eq_2){
    typedef typename TestFixture::deque_type deque_type;
    deque_type x(1);
    deque_type y(0);
    EXPECT_FALSE(x == y);
    x.pop_front();
    EXPECT_TRUE(x == y);}
    */
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

    
/*
TYPED_TEST(Deque_Fixture, test_resize_2) {
    typedef typename TestFixture::deque_type deque_type;
    deque_type x (1000);
    ASSERT_EQ(x.size(),1000);
    x.resize(0);
    ASSERT_EQ(x.size(), 0);
    typename deque_type::iterator e = x.end();
    typename deque_type::iterator b = x.begin();
    ASSERT_EQ(e, b);}
*/

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
