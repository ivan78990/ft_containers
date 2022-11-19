#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utility.hpp"
#include <memory>
#include <iostream>
#include "reverse_iterator.hpp"

namespace ft {

    template <typename Iterator>
    class vector_iterator {
    public:
        typedef Iterator iterator_type;
        typedef typename ft::random_access_iterator_tag iterator_category;
        typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
        typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
        typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
        typedef typename ft::iterator_traits<iterator_type>::reference reference;

    private:
        pointer ptr;

    public:
        vector_iterator(pointer ptr = 0) : ptr(ptr) { }

        template<class U>
        vector_iterator(const vector_iterator<U>& other) : ptr(other.base()) {}

        virtual ~vector_iterator() { }

        pointer base() const {
            return ptr; 
        }

        vector_iterator& operator=(const vector_iterator& other)
        {
            if (this == &other)
                return *this;
            ptr = other.ptr;
            return *this;
        }

        vector_iterator& operator-=(difference_type i)
        {
            ptr -= i;
            return *this;
        }

        vector_iterator& operator+=(difference_type i)
        {
            ptr += i;
            return *this;
        }

        vector_iterator operator-(difference_type i) const { 
            return ptr - i; 
        }

        template <typename T>
        ptrdiff_t operator-(const vector_iterator<T>& it) {
            return this->base() - it.base(); 
        }

        vector_iterator operator+(difference_type i) const { 
            return ptr + i; 
        }

        vector_iterator& operator++()
        {
            ptr++;
            return *this;
        }

        vector_iterator& operator--()
        {
            ptr--;
            return *this;
        }

        vector_iterator operator++(int)
        {
            vector_iterator temp(*this);
            ptr++;
            return temp;
        }

        vector_iterator operator--(int)
        {
            vector_iterator temp(*this);
            ptr--;
            return temp;
        }

        reference operator*() { return *ptr; }

        pointer operator->() { return ptr; }

        reference operator[](difference_type n) const {
            return *(ptr + n); 
        }

        template <typename T>
        bool operator==(const vector_iterator<T>& other) const {
            return ptr == other.base(); 
        }

        template <typename T>
        bool operator!=(const vector_iterator<T>& other) const {
            return ptr != other.base(); 
        }

        template <typename T>
        bool operator>(const vector_iterator<T>& other) const {
            return ptr > other.base();
        }

        template <typename T>
        bool operator<(const vector_iterator<T>& other) const { 
            return ptr < other.base(); 
        }

        template <typename T>
        bool operator>=(const vector_iterator<T>& other) const {
            return ptr >= other.base(); 
        }

        template <typename T>
        bool operator<=(const vector_iterator<T>& other) const {
            return ptr <= other.base(); 
        }
    };

    template <typename T>
    vector_iterator<T> operator+(size_t n, const vector_iterator<T> &iter) {
        return iter + n; 
    }

    template <typename T>
    ptrdiff_t operator-(const vector_iterator<T>& left, const vector_iterator<T>& right) {
        return left.base() - right.base(); 
    }

    template<class T, class Alloc = std::allocator<T> >
    class vector {

    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::size_type size_type;
        typedef ft::vector_iterator<pointer> iterator;
        typedef ft::vector_iterator<const_pointer> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
        allocator_type alloc;
        pointer ptr;
        size_type _size;
        size_type cap;

    public:
        explicit vector(const allocator_type& alloc = allocator_type()) :alloc(alloc), ptr(0), _size(0), cap(0) { }

        explicit vector(size_type n, const value_type& value = value_type(),
                        const allocator_type& alloc = allocator_type())
                :alloc(alloc), ptr(0), _size(0), cap(0) { assign(n, value); }

        template<class InputIterator>
        vector(InputIterator first,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
                const allocator_type& alloc = allocator_type())
                :alloc(alloc), ptr(0), _size(0), cap(0) {
            assign(first, last);
        }

        vector(const vector& other) :alloc(other.alloc), ptr(0), _size(0), cap(0) { assign(other.begin(), other.end()); }

        ~vector()
        {
            clear();
            alloc.deallocate(ptr, cap);
        }

        vector& operator=(const vector& other)
        {
            if (this == &other)
                return *this;
            clear();
            insert(begin(), other.begin(), other.end());
            return *this;
        }

        iterator begin() {
            return iterator(ptr); 
        }

        const_iterator begin() const {
            return const_iterator(ptr); 
        }

        iterator end() {
            return iterator(ptr + _size);
        }

        const_iterator end() const {
            return const_iterator(ptr + _size); 
        }

        reverse_iterator rbegin() { 
            return reverse_iterator(ptr + _size); 
        }

        const_reverse_iterator rbegin() const { 
            return const_reverse_iterator(ptr + _size); 
        }

        reverse_iterator rend() {
            return reverse_iterator(ptr); 
        }

        const_reverse_iterator rend() const {
            return const_reverse_iterator(ptr); 
        }

        size_type size() const { 
            return _size; 
        }

        size_type max_size() const {
            return alloc.max_size(); 
        }

        void resize(size_type n, value_type value = value_type())
        {
            if (_size > n) {
                for (; _size > n; --_size)
                    alloc.destroy(ptr + _size - 1);
            }
            else {
                if (!cap || n > 2 * cap)
                    reserve(n);
                else if (n > cap)
                    reserve(cap * 2);
                for (; _size < n; ++_size)
                    alloc.construct(ptr + _size, value);
            }
        }

        size_type capacity() const {
            return cap; 
        }

        bool empty() const {
            return _size == 0; 
        }

        void reserve(size_type i)
        {
            if (i > cap) {
                check_max_size(i);
                pointer new_ptr;
                size_type new_cap = i;
                size_type new_size = 0;
                try {
                    new_ptr = alloc.allocate(new_cap);
                    for (; new_size < _size; ++new_size)
                        alloc.construct(new_ptr + new_size, *(ptr + new_size));
                    for (size_type i = 0; i < _size; ++i)
                        alloc.destroy(ptr + i);
                    replacement(new_ptr, new_size, new_cap);
                } catch (...) {
                    clear(new_ptr, new_size, new_cap);
                }
            }
        }

        reference operator[](size_type i) {
            return *(ptr + i); 
        }

        const_reference operator[](size_type i) const { 
            return *(ptr + i); 
        }

        reference at(size_type i)
        {
            check_range(i);
            return *(ptr + i);
        }

        const_reference at(size_type i) const
        {
        	check_range(i);
        	return *(ptr + i);
        }

        reference front() { 
            return *ptr; 
        }

        const_reference front() const {
            return *ptr; 
        }

        reference back() {
            return *(ptr + _size - 1); 
        }

        const_reference back() const {
            return *(ptr + _size - 1); 
        }

        template<class InputIterator>
        void assign(
                InputIterator first,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
        {
            clear();
            reserve(ft::distance(first, last));
            insert(begin(), first, last);
        }

        void assign(size_type i, const value_type& value)
        {
            clear();
            reserve(i);
            insert(begin(), i, value);
        }

        void push_back(const value_type& value)
        {
            if (_size == cap)
                resize(_size + 1, value);
            else
                alloc.construct(ptr + _size++, value);
        }

        void pop_back()
        {
            --_size;
            alloc.destroy(ptr + _size);
        }

        iterator insert(iterator position, const value_type& value)
        {
        	size_type pos = ft::distance(begin(), position);
            insert(position, 1, value);
            return iterator(ptr + pos);
        }
        
        void insert(iterator position, size_type n, const value_type& value)
        {
            size_type pos = ft::distance(begin(), position);
            size_type new_size = 0;
            size_type new_cap;
            pointer new_ptr;

            if (_size + n > cap) {
                new_cap = !cap ? n : cap * 2 < n + _size ? _size + n : cap * 2;
                check_max_size(new_cap);
                try {
                    new_ptr = alloc.allocate(new_cap);
                    for (; new_size < n; ++new_size)
                        alloc.construct(new_ptr + pos + new_size, value);
                    move(new_ptr, ptr, pos, new_size);
                    move(new_ptr + pos + n, ptr + pos, ft::distance(position, end()), new_size);
                    replacement(new_ptr, new_size, new_cap);
                } catch (...) {
                    clear(new_ptr + pos, new_size, new_cap);
                    throw;
                }
            } else {
                move_reverse(ptr + _size - 1 + n, ptr + _size - 1, ft::distance(position, end()));
                for (size_type i = 0; i < n; ++i, ++_size)
                    alloc.construct(ptr + pos + i, value);
            }
        }
        
        template<class InputIterator>
        void insert(
                iterator position,
                InputIterator first,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
            size_type j = ft::distance(first, last);
            size_type pos = ft::distance(begin(), position);
            size_type new_size(0);
            size_type new_cap(0);
            pointer new_ptr(0);

            if (_size + j > cap) {
                new_cap = cap == 0 ? j : cap * 2 < _size + j ? _size + j : cap * 2;
                check_max_size(new_cap);
                try {
                    new_ptr = alloc.allocate(new_cap);
                    for (; new_size < j; ++new_size, ++first)
                        alloc.construct(new_ptr + pos + new_size, *first);
                    move(new_ptr, ptr, pos, new_size);
                    move(new_ptr + pos + j, ptr + pos, end() - position, new_size);
                    replacement(new_ptr, new_size, new_cap);
                } catch (...) {
                    clear(new_ptr, new_size, new_cap);
                    throw;
                }
            } else {
                move_reverse(ptr + _size - 1 + j, ptr + _size - 1, end() - position);
                for (size_type i = 0; i < j; ++i, ++_size, ++first)
                    alloc.construct(ptr + pos + i, *first);
            }
        }

        iterator erase(iterator position) { 
            return erase(position, position + 1); 
        }

        iterator erase(iterator first, iterator last)
        {
            size_type j = ft::distance(first, last);
            for (size_type i = 0; i < j; ++i) {
                alloc.destroy(first.base() + i);
            }
            for (size_type i = 0, remains = ft::distance(last, end()); i < remains; ++i) {
                *(first.base() + i) = *(last.base() + i);
            }
            _size -= j;
            return first;
        }

        void swap(vector& other)
        {
            std::swap(alloc, other.alloc);
            std::swap(ptr, other.ptr);
            std::swap(_size, other._size);
            std::swap(cap, other.cap);
        }

        void clear()
        {
            for (; _size > 0; --_size)
                alloc.destroy(ptr + _size - 1);
        }

        allocator_type getallocator() const { return alloc; }

        pointer data() { return ptr; }

    private:
        void check_max_size(size_type i)
        {
            if (i > max_size())
                throw std::length_error("vector");
        }

        void check_range(size_type n) const
        {
            if (n > size())
                throw std::out_of_range("vector");
        }

        void replacement(pointer new_ptr, size_type new_size, size_type new_cap)
        {
            alloc.deallocate(ptr, cap);
            _size = new_size;
            cap = new_cap;
            ptr = new_ptr;
        }

        void clear(pointer new_ptr, size_type new_size, size_type new_cap)
        {
            for (; new_size > 0; --new_size)
                alloc.destroy(new_ptr + new_size - 1);
            alloc.deallocate(new_ptr, new_cap);
        }

        void move(pointer dst, pointer src, size_type n, size_type& new_size)
        {
            for (size_type i = 0; i < n; ++i, ++new_size)
                *(dst + i) = *(src + i);
        }

        void move_reverse(pointer dst, pointer src, size_type n)
        {
            for (size_type i = 0; i < n; ++i)
                *(dst - i) = *(src - i);
        }
    };

    template<class T, class Alloc>
    bool operator==(const vector<T, Alloc>& left, const vector<T, Alloc>& right)
    {
        if (left.size() != right.size())
            return false;

        typename vector<T, Alloc>::const_iterator it1 = left.begin();
        typename vector<T, Alloc>::const_iterator it2 = right.begin();

        for (; it1 != left.end(); ++it1, ++it2)
            if (*it1 != *it2)
                return false;
        return true;
    }

    template<class T, class Alloc>
    bool operator!=(const vector<T, Alloc>& left, const vector<T, Alloc>& right) { return !(left == right); }

    template<class T, class Alloc>
    bool operator<(const vector<T, Alloc>& left, const vector<T, Alloc>& right)
    {
        typename vector<T, Alloc>::const_iterator it1 = left.begin();
        typename vector<T, Alloc>::const_iterator it2 = right.begin();

        for (; it1 != left.end(); ++it1, ++it2) {
            if (it2 == right.end() || *it2 < *it1)
                return false;
            else if (*it1 < *it2)
                return true;
        }
        return it2 != right.end();
    }

    template<class T, class Alloc>
    bool operator<=(const vector<T, Alloc>& left, const vector<T, Alloc>& right) {
        return !(right < left);
    }

    template<class T, class Alloc>
    bool operator>(const vector<T, Alloc>& left, const vector<T, Alloc>& right) {
        return right < left;
    }

    template<class T, class Alloc>
    bool operator>=(const vector<T, Alloc>& left, const vector<T, Alloc>& right) {
        return !(left < right);
    }

    template<class T, class Alloc>
    void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
        x.swap(y);
    }
}

#endif
