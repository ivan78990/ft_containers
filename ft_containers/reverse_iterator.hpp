#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
    template<class Iterator>
    class reverse_iterator {
    public:
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
        typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
        typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
        typedef typename ft::iterator_traits<iterator_type>::reference reference;

    private:
        iterator_type iter;

    public:
        reverse_iterator() { }

        reverse_iterator(const Iterator& other) :iter(other.base()) { }

        reverse_iterator(const reverse_iterator& other) :iter(other.base()) { }

        template<typename U>
        reverse_iterator(const reverse_iterator<U>& other) :iter(other.base()) { }

        virtual ~reverse_iterator() { }

        iterator_type base() const {
            return iter;
        }

        reference operator*() const
        {
            iterator_type it(iter);
            --it;
            return *it;
        }

        pointer operator->() const {
            return &(operator*());
        }

        reverse_iterator operator+(difference_type n) const {
            return reverse_iterator(iter-n); }

        reverse_iterator operator-(difference_type n) const {
            return reverse_iterator(iter+n);
        }

        reverse_iterator& operator++()
        {
            iter--;
            return *this;
        }

        reverse_iterator& operator--()
        {
            iter++;
            return *this;
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator temp(*this);
            iter--;
            return temp;
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator temp(*this);
            iter++;
            return temp;
        }

        reverse_iterator& operator+=(difference_type n)
        {
            iter -= n;
            return *this;
        }

        reverse_iterator& operator-=(difference_type n)
        {
            iter += n;
            return *this;
        }

        reference operator[](difference_type n) const { 
            return (this->base()[-n-1]); 
        }

        template <class U>
        bool operator==(const reverse_iterator<U>& other) const {
            return iter == other.base(); 
        };

        template <class U>
        bool operator!=(const reverse_iterator<U>& other) const {
            return iter != other.base(); 
        };

        template <class U>
        bool operator<(const reverse_iterator<U>& other) const {
            return iter >  other.base(); 
        };

        template <class U>
        bool operator<=(const reverse_iterator<U>& other) const {
            return iter >= other.base(); 
        };

        template <class U>
        bool operator>(const reverse_iterator<U>& other) const {
            return iter <  other.base(); 
        };

        template <class U>
        bool operator>=(const reverse_iterator<U>& other) const {
            return iter <= other.base(); 
        };

        template <class U>
        difference_type operator-(const reverse_iterator<U>& other) {
            return other.base() - iter; 
        };

        friend reverse_iterator operator+(difference_type n, const reverse_iterator& other) {
            return other + n;
        };
    };
}

#endif
