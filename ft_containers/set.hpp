#ifndef SET_HPP
#define SET_HPP

#include "tree.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft {

    template <class T, class Iter>
    class set_iterator {
    public:
        typedef Iter iterator_type;
        typedef ft::bidirectional_iterator_tag iterator_category;
        typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
        typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
        typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
        typedef typename ft::iterator_traits<iterator_type>::reference reference;

    private:
        typedef node<T, bool>* nodePointer;
        nodePointer nodePtr;

    public:
        set_iterator(nodePointer ptr = 0) : nodePtr(ptr) { }

        template<class U>
        set_iterator(const set_iterator<T, U>& other) :nodePtr(other.base()) { }

        set_iterator& operator=(const set_iterator& other)
        {
            if (this == &other)
                return *this;
            nodePtr = other.nodePtr;
            return *this;
        }

        ~set_iterator() { }

        nodePointer base() const {
            return nodePtr; 
        }

        bool operator==(const set_iterator& other) const { 
            return nodePtr == other.base(); }

        bool operator!=(const set_iterator& other) const { 
            return nodePtr != other.base(); 
        }

        reference operator*() const { 
            return nodePtr->data->first;
        }

        pointer operator->() const { 
            return &nodePtr->data->first; 
        }

        set_iterator& operator++()
        {
            nodePtr = next(nodePtr);
            return *this;
        }

        set_iterator operator++(int)
        {
            set_iterator tmp(*this);
            nodePtr = next(nodePtr);
            return tmp;
        }

        set_iterator& operator--()
        {
            nodePtr = prev(nodePtr);
            return *this;
        }

        set_iterator operator--(int)
        {
            set_iterator tmp(*this);
            nodePtr = prev(nodePtr);
            return tmp;
        }

    private:
        nodePointer maximum(nodePointer node)
        {
            while (node->right->type != nil_type) {
                node = node->right;
            }
            return node;
        }

        nodePointer minimum(nodePointer node)
        {
            while (node->left->type != nil_type) {
                node = node->left;
            }
            return node;
        }

        nodePointer next(nodePointer node)
        {
            if (node->type == nil_type)
                return node;

            if (node->right->type != nil_type)
                return minimum(node->right);

            nodePointer ptr = node->parent;
            while (ptr->type != nil_type && node == ptr->right) {
                node = ptr;
                ptr = ptr->parent;
            }
            return ptr;
        }

        nodePointer prev(nodePointer node)
        {
            if (node->type == nil_type)
                return node->parent;

            if (node->type != nil_type && node->left->type != nil_type)
                return maximum(node->left);

            nodePointer ptr = node->parent;
            while (ptr->type != nil_type && node == ptr->left) {
                node = ptr;
                ptr = ptr->parent;
            }

            return ptr->type != nil_type ? ptr : node;
        }
    };

    template<class Key,
            class Compare = std::less<Key>,
            class Allocator = std::allocator<Key>
    >
    class set {
    public:
        typedef Key key_type;
        typedef key_type value_type;
        typedef Compare key_compare;
        typedef key_compare value_compare;
        typedef Allocator allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::size_type size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ft::set_iterator<Key, const value_type*> iterator;
        typedef ft::set_iterator<Key, const value_type*> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
        tree<Key, bool, Compare, Allocator> tree;
        key_compare _key_compare;
        allocator_type alloc;

    public:

        set() :tree(), _key_compare(key_compare()), alloc(allocator_type()) { }

        set(
                const Compare& comp,
                const Allocator& alloc = allocator_type()
                        ) :tree(), _key_compare(comp), alloc(alloc) { }

        template< class InputIt >
        set(
                InputIt first,
                InputIt last,
                const Compare& comp = Compare(),
                const Allocator& alloc = allocator_type()
                    ) :tree(), _key_compare(comp), alloc(alloc) {
            insert(first, last);
        }

        set(const set& other) {
            *this = other;
        }
        ~set() { }

        set& operator=(const set& other)
        {
            if (this == &other)
                return *this;
            tree = other.tree;
            alloc = other.alloc;
            _key_compare = other._key_compare;
            return *this;
        }

        allocator_type getallocator() const {
            return alloc;
        }

        iterator begin() {
            return iterator(tree.begin());
        }

        const_iterator begin() const {
            return const_iterator(tree.begin());
        }

        iterator end() {
            return iterator(tree.end());
        }

        const_iterator end() const {
            return const_iterator(tree.end());
        }

        reverse_iterator rbegin() {
            return reverse_iterator(tree.end());
        }

        const_reverse_iterator rbegin() const {
            return reverse_iterator(tree.end());
        }

        reverse_iterator rend() {
            return reverse_iterator(tree.begin());
        }

        const_reverse_iterator rend() const {
            return reverse_iterator(tree.begin());
        }

        bool empty() const {
            return tree.size() == 0;
        }

        size_type size() const {
            return tree.size();
        }

        size_type max_size() const {
            return tree.max_size();
        }

        void clear() {
            tree.clear();
        }

        ft::pair<iterator, bool> insert(const value_type& value) {
            return tree.insert(ft::pair<const value_type, bool>(value, true));
        }

        iterator insert(iterator hint, const value_type& value)
        {
            (void) hint;
            return tree.insert(ft::pair<value_type, bool>(value, true)).first;
        }

        template<class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            for (; first!=last; ++first) {
                tree.insert(ft::pair<value_type, bool>(*first, true));
            }
        }

        void erase(iterator pos) { tree.erase(*pos); }

        void erase(iterator first, iterator last)
        {
            for (; first!=last;) {
                Key key = *first;
                ++first;
                tree.erase(key);
            }
        }

        size_type erase(const key_type& key) {
            return tree.erase(key) ? 1 : 0;
        }

        void swap(set& other)
        {
            tree.swap(other.tree);
            std::swap(alloc, other.alloc);
            std::swap(_key_compare, other._key_compare);
        }

        size_type count(const key_type& key) const {
            return (const_iterator(tree.find(key)) != end()) ? 1 : 0;
        }

        iterator find(const key_type& key) {
            return iterator(tree.find(key));
        }

        const_iterator find(const key_type& key) const {
            return const_iterator(tree.find(key));
        }

        ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
            return ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
        }

        ft::pair<iterator, iterator> equal_range(const key_type& key)
        {
            return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
        }

        iterator lower_bound(const key_type& key) {
            return iterator(tree.lower_bound(key));
        }

        const_iterator lower_bound(const key_type& key) const {
            return const_iterator(tree.lower_bound(key));
        }

        iterator upper_bound(const key_type& key) { 
            return iterator(tree.upper_bound(key));
        }

        const_iterator upper_bound(const key_type& key) const {
            return const_iterator(tree.upper_bound(key));
        }

        key_compare key_comp() const { 
            return _key_compare;
        }

        value_compare value_comp() const {
            return value_compare(Compare()); 
        }

        friend bool operator==(
                const set<Key, Compare, Allocator>& left,
                const set<Key, Compare, Allocator>& right)
        {
            return left.size() == right.size() && ft::equal(left.begin(), left.end(), right.begin());
        }

        friend bool operator!=(
                const set<Key, Compare, Allocator>& left,
                const set<Key, Compare, Allocator>& right)
        {
            return !(left==right);
        }

        friend bool operator<(
                const set<Key, Compare, Allocator>& left,
                const set<Key, Compare, Allocator>& right)
        {
            return ft::lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
        }

        friend bool operator<=(
                const set<Key, Compare, Allocator>& left,
                const set<Key, Compare, Allocator>& right)
        {
            return !(right<left);
        }

        friend bool operator>(
                const set<Key, Compare, Allocator>& left,
                const set<Key, Compare, Allocator>& right)
        {
            return right<left;
        }

        friend bool operator>=(
                const set<Key, Compare, Allocator>& left,
                const set<Key, Compare, Allocator>& right)
        {
            return !(left<right);
        }
    };
}

#endif
