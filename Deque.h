// --------------------------
// projects/c++/deque/Deque.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Deque_h
#define Deque_h

// --------
// includes
// --------

#include <algorithm> // copy, equal, lexicographical_compare, max, swap
#include <cassert>   // assert
#include <iterator>  // iterator, bidirectional_iterator_tag
#include <memory>    // allocator
#include <stdexcept> // out_of_range
#include <utility>   // !=, <=, >, >=
#include <iostream> //cout

#define AWIDTH 5


// -----
// using
// -----

using std::rel_ops::operator!=;
using std::rel_ops::operator<=;
using std::rel_ops::operator>;
using std::rel_ops::operator>=;

// -------
// destroy
// -------

template <typename A, typename BI>
BI destroy (A& a, BI b, BI e) {
    while (b != e) {
        --e;
        a.destroy(&*e);}
    return b;}

// ------------------
// uninitialized_copy
// ------------------

template <typename A, typename II, typename BI>
BI uninitialized_copy (A& a, II b, II e, BI x) {
    BI p = x;
    try {
        while (b != e) {
            a.construct(&*x, *b);
            ++b;
            ++x;}}
    catch (...) {
        destroy(a, p, x);
        throw;}
    return x;}

// ------------------
// uninitialized_fill
// ------------------

template <typename A, typename BI, typename U>
BI uninitialized_fill (A& a, BI b, BI e, const U& v) {
    BI p = b;
    try {
        while (b != e) {
            a.construct(&*b, v);
            ++b;}}
    catch (...) {
        destroy(a, p, b);
        throw;}
    return e;}

// -------
// my_deque
// -------
template < typename T, typename A = std::allocator<T> >
class my_deque {
    public:
        // --------
        // typedefs
        // --------

        typedef A                                               allocator_type; // inner?
        typedef typename allocator_type::value_type             value_type;

        typedef typename allocator_type::size_type              size_type;
        typedef typename allocator_type::difference_type        difference_type;

        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;

        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;

        typedef typename A::template rebind<pointer>::other      B; //outer array
        typedef typename B::pointer                              b_pointer;


    public:
        // -----------
        // operator ==
        // -----------

        /**
         * <your documentation>
         */
        friend bool operator == (const my_deque& lhs, const my_deque& rhs) {
            if (rhs.size() != lhs.size())
                return false;
            typename my_deque::const_iterator b1 = lhs.begin();// <your code>
            typename my_deque::const_iterator b2 = rhs.begin();// <your code>
            typename my_deque::const_iterator e = lhs.end();// <your code>
            return std::equal (b1, e, b2);}

        // ----------
        // operator <
        // ----------

        /**
         * <your documentation>
         */
        friend bool operator < (const my_deque& lhs, const my_deque& rhs) {
            // <your code>
            typename my_deque::const_iterator first1 = lhs.begin();// <your code>
            typename my_deque::const_iterator first2 = rhs.begin();// <your code>
            typename my_deque::const_iterator last1 = lhs.end();// <your code>
            typename my_deque::const_iterator last2 = rhs.end();// <your code>
            while (first1!=last1){
                    if (first2==last2 || *first2<*first1) return false;
                    else if (*first1<*first2) return true;
                    ++first1; ++first2;
            }
            return (first2!=last2);}
            // you must use std::lexicographical_compare()}

    private:
        // ----
        // data
        // ----
        //AWIDTH for inner array size
        allocator_type _a; // allocator for inner arrays
        B _outter; //allocator for outer array?
        b_pointer _top; //points to first container
        size_type _e; //end of size
        size_type _b; // begining
        //pointer_l; //for capacity of current
        size_type _top_size;
        difference_type _offset;
        size_type _size;
        
        // <your data>

    private:
        // -----
        // valid
        // -----

        bool valid () const {
            // <your code>
            return true;}
        pointer get_last(){
            return _e[((_size)-(AWIDTH-_offset))%AWIDTH];}
    public:
        // --------
        // iterator
        // --------

        class iterator {
            public:
                // --------
                // typedefs
                // --------

                typedef          std::bidirectional_iterator_tag iterator_category;
                typedef typename my_deque::value_type            value_type;
                typedef typename my_deque::difference_type       difference_type;
                typedef typename my_deque::pointer               pointer;
                typedef typename my_deque::reference             reference;

            public:
                // -----------
                // operator ==
                // -----------

                /**
                 */
                friend bool operator == (const iterator& lhs, const iterator& rhs) {
                    if (&lhs._outter != &rhs._outter)
                        return false;
                    return (lhs._index == rhs._index);}

                /**
                 * <your documentation>
                 */
                friend bool operator != (const iterator& lhs, const iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * <your documentation>
                 */
                friend iterator operator + (iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * <your documentation>
                 */
                friend iterator operator - (iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}

            private:
                // ----
                // data
                // ----
                difference_type _index;
                my_deque& _outter;
                // <your data>

            private:
                // -----
                // valid
                // -----
                bool valid () const {
                if (_index < 0 || _index>_outter.size())
                    return false;
                return true;}

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * <your documentation>
                 */
                iterator (difference_type index, my_deque& outter): _index(index), _outter(outter) {
                    assert(valid());}

                // Default copy, destructor, and copy assignment.
                // iterator (const iterator&);
                // ~iterator ();
                // iterator& operator = (const iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * <your documentation>
                 */
                reference operator * () const {
                    reference dummy = _outter[_index]; 
                    return dummy;}

                // -----------
                // operator ->
                // -----------

                /**
                 * <your documentation>
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator ++ () {
                    ++_index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                iterator operator ++ (int) {
                    iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator --
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator -- () {
                    --_index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                iterator operator -- (int) {
                    iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator +=
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator += (difference_type d) {
                    _index+=d;
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * <your documentation>
                 */
                iterator& operator -= (difference_type d) {
                    _index-=d;
                    assert(valid());
                    return *this;}};

    public:
        // --------------
        // const_iterator
        // --------------

        class const_iterator {
            public:
                // --------
                // typedefs
                // --------

                typedef          std::bidirectional_iterator_tag iterator_category;
                typedef typename my_deque::value_type            value_type;
                typedef typename my_deque::difference_type       difference_type;
                typedef typename my_deque::const_pointer         pointer;
                typedef typename my_deque::const_reference       reference;

            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * <your documentation>
                 */
                friend bool operator == (const const_iterator& lhs, const const_iterator& rhs) {
                    if (&lhs._outter != &rhs._outter)
                        return false;
                    return lhs._index == rhs._index;}

                /**
                 * <your documentation>
                 */
                friend bool operator != (const const_iterator& lhs, const const_iterator& rhs) {
                    return !(lhs == rhs);}

                // ----------
                // operator +
                // ----------

                /**
                 * <your documentation>
                 */
                friend const_iterator operator + (const_iterator lhs, difference_type rhs) {
                    return lhs += rhs;}

                // ----------
                // operator -
                // ----------

                /**
                 * <your documentation>
                 */
                friend const_iterator operator - (const_iterator lhs, difference_type rhs) {
                    return lhs -= rhs;}

            private:
                // ----
                // data
                // ----
                difference_type _index;
                const my_deque& _outter;
                // <your data>

            private:
                // -----
                // valid
                // -----
                bool valid () const {
                    if (_index < 0 || _index>_outter.size())
                        return false;
                    return true;}

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator (difference_type index, const my_deque& outter): _index(index), _outter(outter) {
                    assert(valid());}

                // Default copy, destructor, and copy assignment.
                // const_iterator (const const_iterator&);
                // ~const_iterator ();
                // const_iterator& operator = (const const_iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * <your documentation>
                 */
                reference operator * () const { 
                    return _outter[_index];}

                // -----------
                // operator ->
                // -----------

                /**
                 * <your documentation>
                 */
                pointer operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator ++ () {
                    ++_index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                const_iterator operator ++ (int) {
                    const_iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator --
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator -- () {
                    --_index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                const_iterator operator -- (int) {
                    const_iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator +=
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator += (difference_type i2) {
                    _index += i2;
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * <your documentation>
                 */
                const_iterator& operator -= (difference_type i2) {
                    _index -= i2;
                    assert(valid());
                    return *this;}};

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        explicit my_deque (const allocator_type& a = allocator_type()):_a(a) {
            const_reference v = value_type();
            difference_type s =0;
            _top = _outter.allocate(2);
            _top_size = 2;
            _top[0]=_a.allocate(AWIDTH);
            _top[1]=_a.allocate(AWIDTH);
            _b = 1;
            _e = _b;

            //allocate all the needed inner arrays
            //set variables
            _size=0;
            _offset=0;

            //do the fill stuff
            //uninitialized_fill(_a, begin(), end(), v);
            //assert(valid());
            assert(valid());}

        /**
         * <your documentation>
         *  allocator_type _a; // allocator for inner arrays
        B _b; //allocator for outer array?
        b_pointer _top; //points to first container
        pointer _e; //end of size
        pointer _b; // begining
        //pointer_l; //for capacity of current
        difference_type _top_size;
        difference_type offset;
        size_type size;

         */
        explicit my_deque (size_type s, const_reference v = value_type(), const allocator_type& a = allocator_type()): _a(a) {
            _top = _outter.allocate((s/AWIDTH + 1)*2);
            _top_size = (s/AWIDTH + 1)*2; //always even
            _top[0]=_a.allocate(AWIDTH);
            _top[1]=_a.allocate(AWIDTH);
            _b = 1;
            //allocate all the needed inner arrays
            int i = 0;
            for (i=1; i<= s/AWIDTH; i++){
                _top[i+1] = _a.allocate(AWIDTH);}
            if (s<AWIDTH)
                _e=_b;
            //else if (s%AWIDTH){
            //    _e = i-1;}
            else{
                _e = i;}
            //alocating all of the arrays n stuff
            ++i;
            for ( ;i<_top_size;i++){
                _top[i] = _a.allocate(AWIDTH);
            }
            //set variables
            _size=s;
            _offset=0;

            //do the fill stuff
            uninitialized_fill(_a, begin(), end(), v);
            assert(valid());}

        /**
         * Copy Constructor
         */
        my_deque (const my_deque& that):_a(that._a) {
            _top = _outter.allocate(that._top_size);
            _top_size = that._top_size;
            _size = that._size;
            _b = that._b;
            _offset = that._offset;
            _e = that._e;
            for (difference_type temp = 0; temp < _top_size;++temp){
                _top[temp]=_a.allocate(AWIDTH);
            }
            uninitialized_copy (_a, that.begin(), that.end(), begin());
            
            assert(valid());}

        // ----------
        // destructor
        // ----------

        /**
         * <your documentation>
         */
        ~my_deque () {
            //call _a.destroy(); and then deallocate each array, then deallocate outside array
            destroy (_a, begin(), end());
            for (difference_type i = 0; i <_top_size; i++)
                _a.deallocate(_top[i], AWIDTH);
            _outter.deallocate (_top, _top_size);
            assert(valid());}

        // ----------
        // operator =
        // ----------

        /**
         * <your documentation>
         */
        my_deque& operator = (const my_deque& rhs) {
            clear();
            while (_top_size < rhs._top_size){
                grow_outter();
            }
            _offset = rhs._offset;
            _size = rhs._size;
            _b = rhs._b;
            _e = rhs._e;
            std::copy (rhs.begin(), rhs.end(), begin());
            assert(valid());
            return *this;}

        // -----------
        // operator []
        // -----------

        /**
         * <your documentation>
         */
        reference operator [] (size_type index) {
            // dummy is just to be able to compile the skeleton, remove it
            //std::cout << "offset is " << _offset << std::endl;
            //std::cout << "index is " << index << std::endl;
            if(index < (AWIDTH-_offset)){
                reference dummy = _top[_b][(index+_offset)];
                //std::cout << "here" << " index is " << index << "b is " << _b << std::endl;
                //std::cout << "innner array is _b" << "inner index is " << index+_offset<< std::endl;
                return dummy;
            } 
                if(_offset){
                    index -= AWIDTH-_offset;}
                //std::cout << "getting second shit " << " index is " << index << "b is " << _b << std::endl;

                reference dummy = _top[_b+1+(index/AWIDTH)][index%AWIDTH];

                //std::cout << "inner array is " << _b+(index/AWIDTH) << std::endl;
                return dummy;}

        /**
         * <your documentation>
         */
        const_reference operator [] (size_type index) const {
            return const_cast<my_deque*>(this)->operator[](index);}

        // --
        // at
        // --

        /**
         * <your documentation>
         */
        reference at (size_type index) {
            // 
            // dummy is just to be able to compile the skeleton, remove it
            return this->operator[](index);}

        /**
         * <your documentation>
         */
        const_reference at (size_type index) const {
            return const_cast<my_deque*>(this)->at(index);}

        // ----
        // back
        // ----

        /**
         * <your documentation>
         */
        reference back () {
            // dummy is just to be able to compile the skeleton, remove it
            return *(--end());}

        /**
         * <your documentation>
         */
        const_reference back () const {
            return const_cast<my_deque*>(this)->back();}

        // -----
        // begin
        // -----

        /**
         * <your documentation>
         */
        iterator begin () { 
            return iterator(0, *this);}

        /**
         * <your documentation>
         */
        const_iterator begin () const {
            return const_iterator(0, *this);}

        // -----
        // clear
        // -----

        /**
         * <your documentation>
         */
        void clear () {
            resize(0);
            assert(valid());}

        // -----
        // empty
        // -----

        /**
         * <your documentation>
         */
        bool empty () const {
            return !size();}

        // ---
        // end
        // ---

        /**
         * <your documentation>
         */
        iterator end () {
            return iterator(_size, *this);}

        /**
         * <your documentation>
         */
        const_iterator end () const {
            return const_iterator(_size, *this);}

        // -----
        // erase
        // -----

        /**
         * @param iterator iter, points to location to be erased
         * result: size()==
         */
        iterator erase (iterator iter) {
            if (iter==end())
                return iter;
            _a.destroy (&*iter);
            iterator cur = iter;
            iterator next = iter+1;
            while (next!=end()){
                *cur = *next;
                ++cur;
                ++next;
            }
            pop_back();
            assert(valid());
            return iter;}

        // -----
        // front
        // -----

        /**
         * <your documentation>
         */
        reference front () {
            // <your code>
            // dummy is just to be able to compile the skeleton, remove it
            reference dummy = this->operator[](0);
            return dummy;}

        /**
         * <your documentation>
         */
        const_reference front () const {
            return const_cast<my_deque*>(this)->front();}

        // ------
        // insert
        // ------

        /**
         * <your documentation>
         * @ret iterator pointing to spot where inserted
         */
        iterator insert (iterator iter, const_reference val) {
            resize(_size+1);
            iterator source = ----end();
            iterator dest = --end();
            while (dest!= iter && source!=begin()){
                *dest = *source;
                --dest;
                --source;}

            *iter=val;
            assert(valid());
            return iter;}

        // ---
        // pop
        // ---

        /**
         * <your documentation>
         */
        void pop_back () {
        	this->resize(_size-1);
            assert(valid());}

        /**
         * <your documentation>
         */
        void pop_front () {
            if (_offset == AWIDTH-1){
                _a.destroy(&*begin());
                ++_b;
                _offset=0;
                --_size;}
            else{
                _a.destroy(&*begin());
                ++_offset;
                --_size;}
            assert(valid());}

        // ----
        // push
        // ----

        /**
         * <your documentation>
         */
        void push_back (const_reference val) {
            resize(_size+1, val);
            assert(valid());}

        /**
         * <your documentation>
         */
        void push_front (const_reference val) {
            if(_offset == 0 && _b == 0)
                grow_outter();
            if(_offset == 0){
                _offset = AWIDTH-1;
                --_b;
                _a.construct(&(_top[_b][_offset]), val);
                ++_size;}
            else{
                 --_offset;
                 _a.construct (&*begin(), val);
                 ++_size;}   
            assert(valid());}

        // ------
        // resize
        // ------

        /**
         * User-level, number of objects
         * <your documentation>
         */
        void resize (size_type s, const_reference v = value_type()) {
            //if longer but within _top_size but if allocated
            // if longer than _top_size, _b.allocate new, and transfer pointers,
            // 
            if (s==_size) return;
            //shrink, get bi direction iterator, deallocate each element, until s, calculate new e, set size, 
            if (s<_size){
                while (s<--_size){
                    _a.destroy(&*end());}
                //update _e by calculating last elements
                size_type index = _size;
                if (_offset)
                    index -= AWIDTH- _offset;
                _e = _b + index/AWIDTH;} 
            else{
                //grow this badboy
                //if 
                while (s>_size){
                    //
                    if (_e+1==_top_size){
                        grow_outter();
                    }
                    //add elements
                    pointer cur = &*end();
                    ++_size;
                    _a.construct (cur, v);
                    //update _e
                    size_type index = _size;
                    if (_offset)
                        index -= AWIDTH- _offset;
                    _e = _b + index/AWIDTH;
                }
            }
            assert(valid());}
        //grows outter array to _top_size*2
        void grow_outter(){
            assert(_top_size % 2 == 0); //algrotihm will break with uneven top
            b_pointer new_top = _outter.allocate (_top_size*2);
            size_type temp=_b;
            size_type c;
            for (c = 0; c<_top_size/2;c++)
                new_top[c]=_a.allocate(AWIDTH);
            for (c = 0; c< _top_size; c++){
                new_top[c+(_top_size/2)]= _top[c];}
            for (c = (_top_size * 3) /2; c < _top_size*2; c++){
                new_top[c]=_a.allocate(AWIDTH);}
            _b = _b + (_top_size/2);
            _e = --c;
            _outter.deallocate (_top, _top_size);
            _top = new_top;
            _top_size = _top_size*2;};

        // ----
        // size
        // ----

        /**
         * <your documentation>
         */
        size_type size () const {
            // <your code>
            return _size;}

        // ----
        // swap
        // ----

        /**
         * <your documentation>
         */
        void swap (my_deque& that) {
            std::swap (this->_a, that._a); // allocator for inner arrays
            std::swap (this->_outter, that._outter); //allocator for outer array?
            std::swap (this->_top, that._top); //points to first container
            std::swap (this->_e, that._e); //end of size
            std::swap (this->_b, that._b); // begining
            std::swap (this->_top_size, that._top_size);
            std::swap (this->_offset, that._offset);
            std::swap (this->_size, that._size);
            assert(valid());}};

#endif // Deque_h
