#ifndef TREE_HPP
#define TREE_HPP

#include "utility.hpp"

namespace ft {

    enum node_type {
        nil_type,
        black_type,
        red_type
    };

    template<class T1, class T2>
    struct node {
        typedef ft::pair<const T1, T2> value_type;
        node_type type;
        node* parent;
        node* left;
        node* right;
        value_type* data;

        node(T1 key, T2 value, node* nil = NULL, node_type type = black_type)
                : type(type), parent(nil), left(nil), right(nil), data(new value_type(key, value)) { }

        node(const node& other) { *this = other; }

        node& operator=(const node& other)
        {
            if (this == &other)
                return *this;
            type = other.type;
            parent = other.parent;
            left = other.left;
            right = other.right;
            data = new value_type(other.data->first, other.data->second);
            return *this;
        }

        ~node()
        {
            if (data) {
                delete data;
                data = NULL;
            }
        }
    };

	template<class T1, class T2, class Compare, class Alloc>
	class tree {
	public:
        typedef T1 key_type;
        typedef T2 mapped_type;
        typedef Compare key_compare;
        typedef typename Alloc::template rebind< node<T1, T2> >::other allocator_type;
        typedef typename allocator_type::value_type value_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::size_type size_type;
        typedef typename allocator_type::difference_type difference_type;

    private:
		allocator_type alloc;
        key_compare comp;
        pointer root;
        pointer nil;
		size_type _size;

    public:
        tree() : alloc(), comp(key_compare()), root(alloc.allocate(1)), nil(root), _size(0)
        {
            alloc.construct(nil, value_type(key_type(), mapped_type(), NULL, nil_type));
        }

        ~tree()
        {
        	clear(root);
            free_node(nil);
        }

        tree& operator=(const tree& other)
        {
            if (this == &other)
                return *this;
            clear();
            comp = other.comp;
            for (pointer ptr = other.begin(); ptr != other.end(); ptr = next(ptr)) {
                insert(*ptr->data);
            }
            return *this;
        }

        pointer begin() { return minimum(root); }

        pointer begin() const { return minimum(root); }

        pointer end() { return nil; }

        pointer end() const { return nil; }

		size_type size() const {
            return _size;
        }

		size_type maxsize() const { return alloc.maxsize(); }

        void clear() { clear(root); }

		ft::pair<pointer, bool> insert(ft::pair<key_type, mapped_type> pair)
        {
            pointer current, parent, new_node;

            for (current = root, parent = nil; current != nil;) {
                if (pair.first == current->data->first)
                    return ft::pair<pointer, bool>(current, false);
                parent = current;
                current = comp(pair.first, current->data->first) ? current->left : current->right;
            }
            new_node = alloc.allocate(1);
            alloc.construct(new_node, value_type(pair.first, pair.second, nil, red_type));
            new_node->parent = parent;

            if (parent == nil)
                root = new_node;
            else {
                if (comp(pair.first, parent->data->first))
                    parent->left = new_node;
                else
                    parent->right = new_node;
            }

            insert_fixup(new_node);
            nil->parent = maximum(root);
            ++_size;
            return ft::pair<pointer, bool>(new_node, true);
        }

		bool erase(key_type key)
		{
        	pointer node = find(root, key);
        	if (node == nil)
        		return false;
            erase_node(node);
        	--_size;
        	return true;
		}

		void swap(tree& other)
		{
			std::swap(nil, other.nil);
			std::swap(root, other.root);
			std::swap(comp, other.comp);
			std::swap(alloc, other.alloc);
			std::swap(_size, other._size);
		}

        pointer find(key_type key) const { return find(root, key); }

		pointer lower_bound(const key_type key) const
		{
			if (root != nil)
			{
                pointer node, remembered;
                for (node = root, remembered = root; node != nil;) {
                    if (key == node->data->first)
                        return node;
                    if (comp(key, node->data->first)) {
                        remembered = node;
                        node = node->left;
                    }
                    else
                        node = node->right;
                }
				return comp(key, remembered->data->first) ? remembered : nil;
			}
			return nil;
		}

		pointer upper_bound(const key_type key) const
		{
			if (root != nil)
			{
                pointer node, remembered;
                for (node = root, remembered = root; node != nil;) {
                    if (comp(key, node->data->first)) {
                        remembered = node;
                        node = node->left;
                    }
                    else
                        node = node->right;
                }
				return comp(key, remembered->data->first) ? remembered : nil;
			}
			return nil;
		}

	private:
		pointer find(pointer node, key_type key) const
		{
			if (node != nil) {
				if (node->data->first == key)
					return node;
				else if (comp(key, node->data->first))
					return find(node->left, key);
				else
					return find(node->right, key);
			}
			return nil;
		}

		pointer maximum(pointer node) const
		{
            for (; node->type != nil_type && node->right->type != nil_type; node = node->right) { }
			return node;
		}

		pointer minimum(pointer node) const
		{
            for (; node->type != nil_type && node->left->type != nil_type; node = node->left) { }
			return node;
		}

		pointer next(pointer node)
		{
			if (node->type == nil_type)
				return node;

			if (node->right->type != nil_type)
				return minimum(node->right);

			pointer tmp = node->parent;
            for (; tmp->type != nil_type && node == tmp->right; node = tmp, tmp = tmp->parent) { }
            return tmp;
		}

		pointer prev(pointer node)
		{
			if (node->type == nil_type)
				return node->parent;

			if (node->type != nil_type && node->left->type != nil_type)
				return maximum(node->left);

			pointer tmp = node->parent;
            for (; tmp->type != nil_type && node == tmp->left; node = tmp, tmp = tmp->parent) { }
            return tmp->type != nil_type ? tmp : node;
		}

		void free_node(const pointer& node)
		{
			alloc.destroy(node);
			alloc.deallocate(node, 1);
		}

		void clear(pointer& node)
		{
			if (node == NULL || node == nil)
                return;

			clear(node->left);
			clear(node->right);
			if (node == root) {
                free_node(root);
                root = nil;
                nil->parent = NULL;
				_size = 0;
			}
			else
                free_node(node);
		}

        void erase_node(pointer z)
        {
            pointer x, y;

            if (z != nil) {
                if (z->left == nil || z->right == nil)
                    y = z;
                else {
                    y = z->right;
                    for (; y->left != nil; y = y->left) { }
                }

                if (y->left != nil)
                    x = y->left;
                else
                    x = y->right;

                if (x != nil)
                    x->parent = y->parent;
                if (y->parent == nil)
                    root = x;
                else {
                    if (y == y->parent->left)
                        y->parent->left = x;
                    else
                    y->parent->right = x;
                }

                if (y != z) {
                    delete z->data;
                    z->data = new ft::pair<const key_type, mapped_type>(y->data->first, y->data->second);
                }

                if (y->type == black_type)
                    delete_fixup(x);

                alloc.destroy(y);
                alloc.deallocate(y, 1);
                nil->parent = maximum(root);
            }
        }

		void insert_fixup(pointer x)
		{
            for (; x != root && x->parent->type == red_type;) {
				if (x->parent == x->parent->parent->left) {
					pointer y = x->parent->parent->right;
					if (y->type == red_type) {
						x->parent->type = black_type;
						y->type = black_type;
						x->parent->parent->type = red_type;
						x = x->parent->parent;
					} else {
						if (x == x->parent->right) {
							x = x->parent;
							rotate_left(x);
						}
						x->parent->type = black_type;
						x->parent->parent->type = red_type;
						rotate_right(x->parent->parent);
					}
				} else {
					pointer y = x->parent->parent->left;
					if (y->type == red_type) {
						x->parent->type = black_type;
						y->type = black_type;
						x->parent->parent->type = red_type;
						x = x->parent->parent;
					} else {
						if (x == x->parent->left) {
							x = x->parent;
							rotate_right(x);
						}
						x->parent->type = black_type;
						x->parent->parent->type = red_type;
						rotate_left(x->parent->parent);
					}
				}
			}
            root->type = black_type;
		}

		void delete_fixup(pointer x)
		{
            for (; x != root && x->type == black_type;) {
				if (x == x->parent->left) {
					pointer w = x->parent->right;
					if (w->type == red_type) {
						w->type = black_type;
						x->parent->type = red_type;
						rotate_left(x->parent);
						w = x->parent->right;
					}
					if (w->left->type == black_type && w->right->type == black_type) {
						w->type = red_type;
						x = x->parent;
					} else {
						if (w->right->type == black_type) {
							w->left->type = black_type;
							w->type = red_type;
							rotate_right(w);
							w = x->parent->right;
						}
						w->type = x->parent->type;
						x->parent->type = black_type;
						w->right->type = black_type;
						rotate_left(x->parent);
						x = root;
					}
				} else {
					pointer w = x->parent->left;
					if (w->type == red_type) {
						w->type = black_type;
						x->parent->type = red_type;
						rotate_right(x->parent);
						w = x->parent->left;
					}
					if (w->right->type == black_type && w->left->type == black_type) {
						w->type = red_type;
						x = x->parent;
					} else {
						if (w->left->type == black_type) {
							w->right->type = black_type;
							w->type = red_type;
							rotate_left(w);
							w = x->parent->left;
						}
						w->type = x->parent->type;
						x->parent->type = black_type;
						w->left->type = black_type;
						rotate_right(x->parent);
						x = root;
					}
				}
			}
			if (x->type != nil_type)
				x->type = black_type;
		}

		void rotate_left(pointer x)
		{
			pointer y = x->right;
			x->right = y->left;
			if (y->left != nil)
                y->left->parent = x;

			if (y != nil)
                y->parent = x->parent;
            if (x->parent == nil)
                root = y;
            else {
				if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
			}

			y->left = x;
			if (x != nil)
                x->parent = y;
		}

		void rotate_right(pointer x)
		{
			pointer y = x->left;
			x->left = y->right;
			if (y->right != nil)
                y->right->parent = x;

			if (y != nil)
                y->parent = x->parent;
            if (x->parent == nil)
                root = y;
            else {
				if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
			}

			y->right = x;
			if (x != nil)
                x->parent = y;
		}
	};
}

#endif
