/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:27:12 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/28 20:30:00 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

namespace ft
{
	template <typename T, typename Compare>
	class map_iterator
	{
	public:
		typedef T	Node;
		Node	*current;
		Node	*nil;
		Node	*root;
		Compare	comp;
		map_iterator() : current(0), nil(0), root(0) {}
		map_iterator(Node *node, Node *last, Node *start, const Compare& compare = Compare())
			: current(node), nil(last), root(start), comp(compare)  {}
		map_iterator(const map_iterator &obj)
			: current(obj.current), nil(obj.nil), root(obj.root), comp(obj.comp) {}
		~map_iterator() {}
		map_iterator	&operator = (const map_iterator &obj) {
			if (this == &obj)
				return (*this);
			comp = obj.comp;
			current = obj.current;
			nil = obj.nil;
			root = obj.root;
			return (*this);
		}
		map_iterator	&operator ++ () {
			if (current->right != nil)
			{
				current = current->right;
				while (current->left != nil)
					current = current->left;
				return *this;
			}
			if (current == current->parent->left)
				current = current->parent;
			else
			{
				while (comp(current->parent->val.first, current->val.first))
					current = current->parent;
				if (current != nil)
					current = current->parent;
			}
			return (*this);
		}
		map_iterator	operator ++ (int) {
			map_iterator temp(*this);
			++(*this);
			return (temp);
		}
		map_iterator	&operator -- () {
			if (current == nil)
			{
				current = root;
				while (current->right != nil)
					current = current->right;
				return *this;
			}
			if (current->left != nil)
			{
				current = current->left;
				while (current->right != nil)
					current = current->right;
				return *this;
			}
			if (current == current->parent->right)
				current = current->parent;
			else
			{
				while (comp(current->val.first, current->parent->val.first))
					current = current->parent;
				if (current != nil)
					current = current->parent;
			}
			return (*this);
		}
		map_iterator	operator -- (int) {
			map_iterator temp(*this);
			--(*this);
			return (temp);
		}
		typename Node::value_type	*operator -> () { return (&current->val); }
		typename Node::value_type	&operator * () { return (current->val); }
		bool		operator != (const map_iterator &obj) { return (current != obj.current); }
		bool		operator == (const map_iterator &obj) { return (current == obj.current); }
	};

	template <typename T, typename Compare>
	class const_map_iterator
	{
	public:
		typedef T	Node;
		Node	*current;
		Node	*nil;
		Node	*root;
		Compare	comp;
		const_map_iterator() : current(0), nil(0), root(0) {}
		const_map_iterator(Node *node, Node *last, Node *start, const Compare& compare = Compare())
			: current(node), nil(last), root(start), comp(compare) {}
		const_map_iterator(const const_map_iterator &obj)
			: current(obj.current), nil(obj.nil), root(obj.root), comp(obj.comp) {}
		const_map_iterator(const map_iterator<T, Compare> &obj)
			: current(obj.current), nil(obj.nil), root(obj.root) {}
		~const_map_iterator() {}
		const_map_iterator	&operator = (const const_map_iterator &obj) {
			if (this == &obj)
				return (*this);
			comp = obj.comp;
			current = obj.current;
			nil = obj.nil;
			root = obj.root;
			return (*this);
		}
		const_map_iterator	&operator ++ () {
			if (current->right != nil)
			{
				current = current->right;
				while (current->left != nil)
					current = current->left;
				return *this;
			}
			if (current == current->parent->left)
				current = current->parent;
			else
			{
				while (comp(current->parent->val.first, current->val.first))
					current = current->parent;
				if (current != nil)
					current = current->parent;
			}
			return (*this);
		}
		const_map_iterator	operator ++ (int) {
			const_map_iterator temp(*this);
			++(*this);
			return (temp);
		}
		const_map_iterator	&operator -- () {
			if (current == nil)
			{
				current = root;
				while (current->right != nil)
					current = current->right;
				return *this;
			}
			if (current->left != nil)
			{
				current = current->left;
				while (current->right != nil)
					current = current->right;
				return *this;
			}
			if (current == current->parent->right)
				current = current->parent;
			else
			{
				while (comp(current->val.first, current->parent->val.first))
					current = current->parent;
				if (current != nil)
					current = current->parent;
			}
			return (*this);
		}
		const_map_iterator	operator -- (int) {
			const_map_iterator temp(*this);
			--(*this);
			return (temp);
		}
		typename Node::value_type const	*operator -> () const { return (&current->val); }
		typename Node::value_type const	&operator * () const { return (current->val); }
		bool		operator != (const const_map_iterator &obj) const { return (current != obj.current); }
		bool		operator == (const const_map_iterator &obj) const { return (current == obj.current); }
	};

	template <typename _Iter>
	class rev_map_iterator
	{
	public:
		_Iter	iter;
		rev_map_iterator() : iter(0) {}
		rev_map_iterator(const _Iter &obj) : iter(obj) {}
		rev_map_iterator(const rev_map_iterator &obj) : iter(obj.iter) {}
		~rev_map_iterator() {}
		rev_map_iterator	&operator = (const rev_map_iterator &obj) {
			if (this == &obj)
				return (*this);
			iter = obj.iter;
			return (*this);
		}
		rev_map_iterator	&operator ++ () {
			--iter;
			return *this;
		}
		rev_map_iterator	operator ++ (int) {
			rev_map_iterator temp(*this);
			++(*this);
			return (temp);
		}
		rev_map_iterator	&operator -- () {
			++iter;
			return *this;
		}
		rev_map_iterator	operator -- (int) {
			rev_map_iterator temp(*this);
			--(*this);
			return (temp);
		}
		typename _Iter::Node::value_type	*operator -> () {
			_Iter tmp(iter);
			--tmp;
			return tmp.operator->();
		}
		typename _Iter::Node::value_type	&operator * () {
			_Iter tmp(iter);
			--tmp;
			return *tmp;
		}
		bool		operator != (const rev_map_iterator &obj) { return (iter.operator!=(obj.iter)); }
		bool		operator == (const rev_map_iterator &obj) { return (iter.operator==(obj.iter)); }
	};

	template <typename _Iter>
	class const_rev_map_iterator
	{
	public:
		_Iter	iter;
		const_rev_map_iterator() : iter(0) {}
		const_rev_map_iterator(const _Iter &obj) : iter(obj) {}
		const_rev_map_iterator(const const_rev_map_iterator &obj) : iter(obj.iter) {}
		~const_rev_map_iterator() {}
		const_rev_map_iterator	&operator = (const const_rev_map_iterator &obj) {
			if (this == &obj)
				return (*this);
			iter = obj.iter;
			return (*this);
		}
		const_rev_map_iterator	&operator ++ () {
			--iter;
			return *this;
		}
		const_rev_map_iterator	operator ++ (int) {
			const_rev_map_iterator temp(*this);
			++(*this);
			return (temp);
		}
		const_rev_map_iterator	&operator -- () {
			++iter;
			return *this;
		}
		const_rev_map_iterator	operator -- (int) {
			const_rev_map_iterator temp(*this);
			--(*this);
			return (temp);
		}
		typename _Iter::Node::value_type const	*operator -> () {
			_Iter tmp(iter);
			--tmp;
			return tmp.operator->();
		}
		typename _Iter::Node::value_type const	&operator * () {
			_Iter tmp(iter);
			--tmp;
			return *tmp;
		}
		bool		operator != (const const_rev_map_iterator &obj) { return (iter.operator!=(obj.iter)); }
		bool		operator == (const const_rev_map_iterator &obj) { return (iter.operator==(obj.iter)); }
	};
}

#endif
