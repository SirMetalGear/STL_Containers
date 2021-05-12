/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:12:50 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/12 16:45:40 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <numeric>
# include <memory>
# include <iostream>
# include <numeric>
# include "./../utils/Node.hpp"
# include "./../utils/const_iterator.hpp"

namespace ft
{
	template<bool B, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <typename T>
	struct is_integer {
		static const bool value = std::numeric_limits<T>::is_integer;
	};

	template<typename T>
	void	swap(T &a, T &b) {
		if (&a != &b)
		{
			T tmp = a;
			a = b;
			b = tmp;
		}
	}

	

	template<typename T, typename Alloc = std::allocator<T> >
	class list
	{
	public:
		typedef T								value_type;
		typedef	Alloc							allocator_type;
		typedef std::ptrdiff_t					difference_type;
		typedef typename Alloc::reference		reference;
		typedef typename Alloc::const_reference	const_reference;
		typedef typename Alloc::pointer			pointer;
		typedef typename Alloc::const_pointer	const_pointer;
		typedef	std::size_t						size_type;
	private:
		typedef BaseNode<T>						Node;
		typedef typename Alloc::template rebind<Node>::other	NodeAllocator;
		size_type		_size;
		Node			*_key;
		NodeAllocator	_nAlloc;
		allocator_type	_vAlloc;

		Node		*new_node(const T &ref) {
			Node *newNode = _nAlloc.allocate(1);
			_nAlloc.construct(newNode, ref);
			return newNode;
		}

		void			delete_node(Node *position) {
			position->_prev->_next = position->_next;
			position->_next->_prev = position->_prev;
			_nAlloc.deallocate(position, 1);
			_size = _size - 1;
			_key->_data = _size;
		}

		template <class _T1>
		struct default_comp
		{
			bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
		};

	public:
		typedef base_iterator<T, Node>			iterator;
		typedef	const_iterator<T, Node>			const_iterator;
			list() : _size(0) {
			_key = new_node(T());
			_key->_next = _key;
			_key->_prev = _key;
		}

		list(const list &obj) {
			*this = obj;
		}

		list &operator = (const list &obj) {
			if (this == &obj)
				return (*this);
			_size = obj._size;
			_key = obj._key;
			_nAlloc = obj._nAlloc;
			_vAlloc = obj._vAlloc;
			return (*this);
		}

		~list() {
			if (_size)
				clear();
			_nAlloc.deallocate(_key, 1);
		}

		iterator		begin() { return _key->_next; }
		const_iterator	begin() const { return _key->_next; }
		const_iterator	cbegin() const { return _key->_next; }
		iterator		end() { return _key; }
		const_iterator	end() const { return _key; }
		const_iterator	cend() const { return _key; }
		size_type		size() { return _size; }

		void		assign(size_type n, const value_type &val) {
			std::cout << "SIZE BEFORE ASSIGN VAL: " << _size << std::endl;
			if (_size != 0)
				clear();
			while (n)
			{
				push_back(val);
				n--;
			}
		}

		template<typename IT>
		void	assign(IT first, IT last,
		typename ft::enable_if<!ft::is_integer<IT>::value>::type* = 0)
		{
			if (_size != 0)
				clear();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void		clear() {
			for (iterator it = begin(); it != end(); ++it)
				delete_node(it.pointer);
		}

		void		push_back(const T &ref) {
			Node *tmp = new_node(ref);
			tmp->_next = _key;
			tmp->_prev = _key->_prev;
			_key->_prev->_next = tmp;
			_key->_prev = tmp;
			_size++;
			_key->_data = _size;
		}

		reference		back() { return _key->_prev->_data; }
		
		const_reference back() const { return _key->_prev->_data; }

		bool			empty() const { return _size == 0; }

		iterator		erase(iterator position) {
			iterator tmp = position.pointer->_prev;
			delete_node(position.pointer);
			return (tmp);
		}

		iterator	erase(iterator first, iterator last) {
			iterator tmp = first.pointer->_prev;
			while (first != last)
			{
				tmp = first.pointer->_prev;
				delete_node(first.pointer);
				++first;
			}
			std::cout << "size after erase: " << _size << std::endl;
			return (tmp);
		}

		reference 		front() { return _key->_next->_data; }

		const_reference front() const { return _key->_next->_data; }

		allocator_type	get_allocator() const { return _nAlloc; }

		iterator		insert(iterator position, const value_type &val) {
			Node *nNode = new_node(val);
			nNode->_next = position.pointer;
			nNode->_prev = position.pointer->_prev;
			position.pointer->_prev->_next = nNode;
			position.pointer->_prev = nNode;
			_size++;
			_key->_data = _size;
			return (nNode);
		}
		
		void	insert(iterator position, size_type n, const value_type &val) {
			while (n)
			{
				insert(position, val);
				n--;
			}
		}

		template <class _InpIter>
		void	 insert(iterator position, _InpIter first, _InpIter last,
		typename ft::enable_if<!ft::is_integer<_InpIter>::value>::type* = 0)
		{
			while (first != last)
				insert(position, *first++);
		}

		size_type	max_size() const { return size_type(-1); }

		void		resize(size_type n, value_type val = value_type()) {
			while (n < _size)
				pop_back();
			while (n > _size)
				push_back(val);
		}

		void	pop_back() { delete_node(_key->_prev); }

		void	pop_front() { delete_node(_key->_next); }

		void	push_front(const value_type &val) {
			Node *tmp = new_node(val);
			tmp->_prev = _key;
			tmp->_next = _key->_next;
			_key->_next->_prev = tmp;
			_key->_next = tmp;
			_size++;
			_key->_data = _size;
		}

		void	remove(const value_type &val) {
			for (iterator start = begin(); start != end(); start++)
				if (*start == val)
					delete_node(start.pointer);
		}

		template <class Predicate>
		void remove_if (Predicate pred) {
			for (iterator start = begin(); start != end(); start++)
				if (pred(*start))
					delete_node(start.pointer);
		}

		void	reverse() {
			iterator it = begin();
			iterator ite = end();
			while (it != --ite)
			{
				ft::swap(*it, *ite);
				++it;
			}
		}

		void	sort() {
			sort(default_comp<value_type>());
		}

		template <class Compare>
		void sort (Compare comp) {
			iterator it = begin();
			iterator ite = end();
			iterator tmp;
			while (it != ite)
			{
				tmp = it.pointer->_next;
				if (tmp == ite)
					break ;
				if (comp(it.pointer->_data, tmp.pointer->_data))
					++it;
				else
				{
					ft::swap(it.pointer->_data, tmp.pointer->_data);
					it.pointer->_next->_data = tmp.pointer->_data;
					it = begin();
				}
			}
		}

		void merge(list &x) {
			merge(x, default_comp<value_type>());
		}

		template <class Compare>
		void mergeTwoLists(iterator start1, iterator end1, iterator start2, itertart end2, Compare comp) {
			
		}

		template <class Compare>
		void merge(list &x, Compare comp) {
			if (this == &x)
				return ;
			iterator start1 = begin();
			iterator end1 = end();
			iterator start2 = x.begin();
			iterator end2 = x.end();
			Node *last = _key;
			while (start1 != end1 && start2 != end2) {
				if (comp(start1.pointer->_data, start2.pointer->_data)) {
					last->_next = start1.pointer;
					last->_next->_prev = last;
					last = start1.pointer;
					start1++;
				}
				else {
					last->_next = start2.pointer;
					start2.pointer->_prev = last;
					last = start2.pointer;
					start2++;
				}
			}
			if (start1 != end1) {
				last->_next = start1.pointer;
				start1.pointer->_prev = last;
			}
			if (start2 != end2) {
				last->_next = start2.pointer;
				start2.pointer->_prev = last;
				_key->_prev = end2.pointer->_prev;
				end2.pointer->_prev->_next = _key;
			}
			x._key->_next = x._key;
			x._key->_prev = x._key;
			_size += x._size;
			x._size = 0;
		}
	};
}

#endif
