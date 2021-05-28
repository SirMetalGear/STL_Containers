/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:06:12 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/28 21:13:13 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "utils/utils.hpp"
# include "utils/red_black_tree.hpp"
# include "utils/map_iterator.hpp"

namespace ft
{
	template <typename Key, class T,
		class Compare = less<Key>, class Alloc = std::allocator< pair<const Key, T> > >
	class map
	{
	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef pair<const key_type, mapped_type>			value_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef	std::ptrdiff_t								difference_type;
		typedef std::size_t									size_type;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		protected:
			key_compare comp;
			value_compare(key_compare c) : comp(c) {}
		public:
			bool operator()(const value_type& __x, const value_type& __y) const {
				return comp(__x.first, __y.first);
			}
		};

	private:
		typedef ft::Node<value_type>								Node;
		typedef ft::tree<key_type, mapped_type, key_compare, Alloc>	Tree;
		typedef typename Alloc::template rebind<Node>::other		NodeAllocator;
		Tree	tree;
		size_type	_size;
	public:
		typedef ft::map_iterator<Node, key_compare>				iterator;
		typedef ft::const_map_iterator<const Node, key_compare>	const_iterator;
		typedef ft::rev_map_iterator<iterator>					reverse_iterator;
		typedef ft::const_rev_map_iterator<iterator>			const_reverse_iterator;
		explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : tree(), _size(0) {
			tree.comp = comp;
			tree.alloc = alloc;
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) {
			tree.comp = comp;
			tree.alloc = alloc;
			_size = 0;
			insert(first, last);
		}
		map (const map& x) { *this = x; }
		~map() {}
		map&	operator = (const map &obj)
		{
			if (this == &obj)
				return *this;
			clear();
			tree.comp = obj.tree.comp;
			tree.alloc = obj.tree.alloc;
			insert(obj.begin(), obj.end());
			return *this;
		}
		iterator	begin() { return iterator(tree.find_min(), tree.nil, tree.root, tree.comp); }
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
		iterator	end()	{ return iterator(tree.nil, tree.nil, tree.root, tree.comp); }
		const_iterator	begin() const { return const_iterator(tree.find_min(), tree.nil, tree.root, tree.comp); }
		const_iterator	end() const	{ return const_iterator(tree.nil, tree.nil, tree.root, tree.comp); }
		ft::pair<iterator, bool> insert(const value_type& val)
		{
			ft::pair<Node *, bool> return_value = tree.insert(val);
			if (return_value.second == true)
				_size++;
			ft::pair<iterator, bool> tmp(iterator(return_value.first, tree.nil, tree.root, tree.comp), return_value.second);
			return tmp;
		}
		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			ft::pair<Node *, bool> return_value = tree.insert(val);
			if (return_value.second == true)
				_size++;
			return (iterator(return_value.first, tree.nil, tree.root, tree.comp));
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integer<InputIterator>::value>::type* = 0)
		{
			while (first != last)
			{
				if (tree.insert(*first++).second == true)
					_size++;
			}
		}
		mapped_type& operator[] (const key_type& k)
		{
			Node *tmp = tree.getNode(tree.root, k);
			if (tmp != tree.nil)
				return tmp->val.second;
			else
				return (*insert(value_type(k, mapped_type())).first).second;
		}
		size_type size() const { return _size; }
		void	clear() {
			if (_size == 0)
				return ;
			tree.clear();
			_size = 0;
		}
		size_type count (const key_type& k) const {
			if (tree.getNode(tree.root, k)!= tree.nil)
				return 1;
			return 0;
		}
		bool	empty() const { return _size == 0; }
		void	erase(iterator position) {
			if (_size == 0)
				return ;
			tree.delete_tree_element(position.current);
			_size--;
		}
		size_type	erase(const key_type& k) {
			if(_size == 0)
				return 0;
			Node *tmp = tree.getNode(tree.root, k);
			if (tmp != tree.nil)
			{
				tree.delete_tree_element(tmp);
				_size--;
				return 1;
			}
			return 0;
		}
		void erase (iterator first, iterator last)
		{
			if (_size == 0)
				return ;
			Node *begin = first.current;
			Node *next;
			while (begin != last.current)
			{
				next = tree.move_forward(begin);
				tree.delete_tree_element(begin);
				begin = next;
				_size--;
			}
		}
		iterator find(const key_type& k) {
			return iterator(tree.getNode(tree.root, k), tree.nil, tree.root, tree.comp);
		}
		const_iterator find (const key_type& k) const {
			return const_iterator(tree.getNode(tree.root, k), tree.nil, tree.root, tree.comp);
		}
		pair<iterator,iterator> equal_range (const key_type& k) {
			Node *tmp = tree.getNode(tree.root, k);
			if (tmp == tree.nil)
				return pair<iterator, iterator>(iterator(tmp, tree.nil, tree.root, tree.comp),
							iterator(tmp, tree.nil, tree.root, tree.comp));
			return pair<iterator, iterator>(iterator(tmp, tree.nil, tree.root, tree.comp),
							iterator(tree.move_forward(tmp), tree.nil, tree.root, tree.comp));
		}
		allocator_type get_allocator() const { return allocator_type(); }
		key_compare key_comp() const { return key_compare(); }
		iterator lower_bound (const key_type& k) {
			return find(k);
		}
		const_iterator lower_bound (const key_type& k) const {
			return find(k);
		}
		iterator upper_bound (const key_type& k) {
			return iterator(tree.move_forward(tree.getNode(tree.root, k)),
														tree.nil, tree.root, tree.comp);
		}
		const_iterator upper_bound (const key_type& k) const {
			return const_iterator(tree.move_forward(tree.getNode(tree.root, k)),
														tree.nil, tree.root, tree.comp);
		}
		size_type max_size() const { return size_type(-1) / (sizeof(value_type)); }
		void swap (map& x) {
			if (&x == this)
				return ;
			tree.swap(x.tree);
			size_type tmp_size = _size;
			_size = x._size;
			x._size = tmp_size;
		}
		value_compare value_comp() const { return value_compare(key_compare()); }
	};

	template <typename Key, class T>
	void swap (map<Key, T>& x, map<Key, T>& y) {
		x.swap(y);
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2) {
		while (first1!=last1)
		{
			if (first2==last2 || first2->first < first1->first || first2->second < first1->second)
				return false;
			else if (first1->first < first2->first || first1->second < first2->second)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class T, class Alloc>
	bool operator == (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::map<T, Alloc>::const_iterator it1 = lhs.begin();
		typename ft::map<T, Alloc>::const_iterator ite1 = lhs.end();
		typename ft::map<T, Alloc>::const_iterator it2 = rhs.begin();
		typename ft::map<T, Alloc>::const_iterator ite2 = rhs.end();
		while (it1 != ite1)
		{
			if (it1->first != it2->first || it1->second != it2->second)
				return (false);
			++it1;
			++it2;
		}
		return (true);
	}

	template <class Key, class T>
	bool operator != (const map<Key,T>& lhs, const map<Key,T>& rhs) {
		return (!(lhs == rhs));
	}

	template <class Key, class T>
	bool operator < (const map<Key,T>& lhs, const map<Key,T>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T>
	bool operator > (const map<Key,T>& lhs, const map<Key,T>& rhs) {
		return rhs < lhs;
	}

	template <class Key, class T>
	bool operator <= (const map<Key,T>& lhs, const map<Key,T>& rhs) {
		return !(rhs < lhs);
	}

	template <class Key, class T>
	bool operator >= (const map<Key,T>& lhs, const map<Key,T>& rhs) {
		return !(lhs < rhs);
	}
}


#endif