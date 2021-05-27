/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:25:52 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/27 12:30:46 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE
# define RED_BLACK_TREE

# include <iostream>
# include <string>
# include "./../map/utils/utils.hpp"

# define RED	0
# define BLACK	1

namespace ft
{
	template <typename value_type>
	struct Node
	{
		value_type	val;
		bool		color : 1;
		Node		*left;
		Node		*right;
		Node		*parent;
		Node(const value_type &_val, const bool &_color = RED,
			Node *_left = 0, Node *_right = 0, Node *_parent = 0)
				: val(_val), color(_color), left(_left), right(_right), parent(_parent) {}
	};

	template <typename T1, typename T2, typename Compare = ft::less<T1>, typename Alloc = std::allocator<ft::pair<const T1, T2> > >
	struct	tree
	{
		typedef ft::pair<const T1, T2>	value_type;
		typedef	Node<value_type>	Node;
		typedef Compare				key_compare;
		typedef typename Alloc::template rebind<Node>::other	NodeAllocator;
		key_compare		comp;
		NodeAllocator	alloc;
		Node			*root;
		Node			*nil;
		tree() {
			nil = alloc.allocate(1);
			alloc.construct(nil, value_type(), BLACK);
			nil->left = nil;
			nil->right = nil;
			nil->parent = nil;
			root = nil;
		}
		Node*	new_node(const value_type& val)
		{
			Node *nNode = alloc.allocate(1);
			alloc.construct(nNode, val, RED);
			return nNode;
		}
		void	left_rotate(Node* x)
		{
			Node *tmp = x->right;
			x->right = tmp->left;
			if (tmp->left != nil)
				tmp->left->parent = x;
			tmp->parent = x->parent;
			if (x->parent == nil)
				root = tmp;
			else if (x->parent->left == x)
				x->parent->left = tmp;
			else
				x->parent->right = tmp;
			x->parent = tmp;
			tmp->left = x;
		}
		void	right_rotate(Node *x)
		{
			Node *tmp = x->left;
			x->left = tmp->right;
			if (tmp->right != nil)
				tmp->right->parent = x;
			tmp->parent = x->parent;
			if (x->parent == nil)
				root = tmp;
			else if (x->parent->left == x)
				x->parent->left = tmp;
			else
				x->parent->right = tmp;
			x->parent = tmp;
			tmp->right = x;
		}
		ft::pair<Node *, bool>	insert_val(Node* &parent, Node* &current, const value_type &val)
		{
			if (current == nil)
			{
				current = new_node(val);
				current->left = nil;
				current->right = nil;
				current->parent = parent;
				if (parent == nil)
					root = current;
				if (comp(val.first, parent->val.first))
					parent->left = current;
				else
					parent->right = current;
			}
			else
			{
				if (val.first == current->val.first)
					return ft::pair<Node *, bool>(current, false);
				if (comp(val.first, current->val.first))
					return insert_val(current, current->left, val);
				else
					return insert_val(current, current->right, val);
			}
			return ft::pair<Node *, bool>(current, true);
		}

		void	balance_after_insert(Node* tmp)
		{
			while (tmp->parent->color == RED)
			{
				if (tmp->parent->parent->left == tmp->parent)
				{
					if (tmp->parent->parent->right->color == RED)
					{
						tmp->parent->color = BLACK;
						tmp->parent->parent->color = RED;
						tmp->parent->parent->right->color = BLACK;
						tmp = tmp->parent->parent;
					}
					else
					{
						if (tmp->parent->right == tmp)
						{
							tmp = tmp->parent;
							left_rotate(tmp);
						}
						tmp->parent->color = BLACK;
						tmp->parent->parent->color = RED;
						right_rotate(tmp->parent->parent);
					}
				}
				else
				{
					if (tmp->parent->parent->left->color == RED)
					{
						tmp->parent->color = BLACK;
						tmp->parent->parent->color = RED;
						tmp->parent->parent->left->color = BLACK;
						tmp = tmp->parent->parent;
					}
					else
					{
						if (tmp->parent->left == tmp)
						{
							tmp = tmp->parent;
							right_rotate(tmp);
						}
						tmp->parent->color = BLACK;
						tmp->parent->parent->color = RED;
						left_rotate(tmp->parent->parent);
					}
				}
			}
			root->color = BLACK;
		}
		ft::pair<Node *, bool>	insert(const value_type& val)
		{
			ft::pair<Node *, bool> return_value = insert_val(nil, root, val);
			if (return_value.second == false)
				return return_value;
			balance_after_insert(return_value.first);
			return (return_value);
		}
		Node* find_min()
		{
			Node *current = root;
			while (current->left != nil)
				current = current->left;
			return (current);
		}
		Node* find_min(Node *current)
		{
			while (current->left != nil)
				current = current->left;
			return (current);
		}
		Node* find_max()
		{
			Node *current = root;
			while (current->right != nil)
				current = current->right;
			return (current);
		}
		Node* end() { return nil; }
		Node* begin() { return find_min(); }
		Node* find_max(Node *current)
		{
			while (current->right != nil)
				current = current->right;
			return (current);
		}
		Node *move_forward(Node *currentPosition)
		{
			if (currentPosition->right != nil)
				return (find_min(currentPosition->right));
			if (currentPosition == currentPosition->parent->left)
				currentPosition = currentPosition->parent;
			else
			{
				while (comp(currentPosition->parent->val.first, currentPosition->val.first))
					currentPosition = currentPosition->parent;
				if (currentPosition != nil)
					currentPosition = currentPosition->parent;
			}
			return currentPosition;
		}
		Node *move_backward(Node *currentPosition)
		{
			if (currentPosition == nil)
				return find_max();
			if (currentPosition->left != nil)
				return (find_max(currentPosition->left));
			if (currentPosition == currentPosition->parent->right)
				currentPosition = currentPosition->parent;
			else
			{
				while (comp(currentPosition->val.first, currentPosition->parent->val.first))
					currentPosition = currentPosition->parent;
				if (currentPosition != nil)
					currentPosition = currentPosition->parent;
			}
			return currentPosition;
		}
		void replace(Node* &node1, Node* &node2)
		{
			if (node1->parent == nil)
				root = node2;
			else if (node1 == node1->parent->left)
				node1->parent->left = node2;
			else
				node1->parent->right = node2;
			node2->parent = node1->parent;
		}
		void delete_node(Node* z)
		{
			alloc.destroy(z);
			alloc.deallocate(z, 1);
		}
		void balance_after_delete(Node *x)
		{
			while (x != root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					Node *w = x->parent->right;
					if (w->color == RED)
					{
						w->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent);
						w = x->parent->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
						w->color = RED;
						x = x->parent;
					}
					else
					{
						if (w->right->color == BLACK)
						{
							w->left->color = BLACK;
							w->color = RED;
							right_rotate(w);
							w = x->parent->right;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->right->color = BLACK;
						left_rotate(x->parent);
						x = root;
					}
				}
				else
				{
					Node *w = x->parent->left;
					if (w->color == RED)
					{
						w->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent);
						w = x->parent->left;
					}
					if (w->right->color == BLACK && w->left->color == RED)
					{
						w->color = RED;
						x = x->parent;
					}
					else
					{
						if (w->left->color == BLACK)
						{
							w->right->color = BLACK;
							w->color = RED;
							left_rotate(w);
							w = x->parent->left;
						}
						w->color = x->parent->color;
						x->parent->color = BLACK;
						w->left->color = BLACK;
						right_rotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		}
		void delete_tree_element(Node *z)
		{
			Node *y = z;
			bool delcol = y->color;
			Node *x = z;
			if (z->left == nil)
			{
				x = z->right;
				replace(z, z->right);
			}
			else if (z->right == nil)
			{
				x = z->left;
				replace(z, z->left);
			}
			else
			{
				y = find_min(z->right);
				delcol = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else
				{
					replace(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				replace(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			if (delcol == BLACK)
				balance_after_delete(x);
			delete_node(z);
		}
	};
}

#endif
