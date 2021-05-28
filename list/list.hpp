/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:12:50 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/29 00:28:40 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <numeric>
# include <memory>
# include <iostream>
# include <numeric>
# include "./utils/Node.hpp"
# include "./utils/const_iterator.hpp"
# include "./utils/const_rev_iterator.hpp"

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
		typedef BaseNode<T>						Node;
		typedef typename Alloc::template rebind<Node>::other	NodeAllocator;
	public:
		typedef T								value_type;
		typedef	Alloc							allocator_type;
		typedef std::ptrdiff_t					difference_type;
		typedef typename Alloc::reference		reference;
		typedef typename Alloc::const_reference	const_reference;
		typedef typename Alloc::pointer			pointer;
		typedef typename Alloc::const_pointer	const_pointer;
		typedef base_iterator<T, Node>			iterator;
		typedef	const_iterator<T, Node>			const_iterator;
		typedef rev_iterator<T, Node>			reverse_iterator;
		typedef constRev_iterator<T, Node>		const_reverse_iterator;
		typedef	std::size_t						size_type;
	private:
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
			_nAlloc.destroy(position);
			_nAlloc.deallocate(position, 1);
			_size = _size - 1;
			_key->_data = _size;
		}

		template <class _T1>
		struct default_comp
		{
			bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
		};

		template <class _T2>
		struct default_equal_comp
		{
			bool operator()(const _T2& __x, const _T2& __y) const {return __x == __y;}
		};

		template <typename S>
		Node *merge(Node *a, Node *b, S comp) {
			Node *tmp;
			if (a == NULL)
				return b;
			if (b == NULL)
				return a;
			if (comp(a->_data, b->_data))
			{
				tmp = a;
				a = a->_next;
			}
			else
			{
				tmp = b;
				b = b->_next;
			}
			Node *head = tmp;
			tmp->_prev = 0;
			while (a && b)
			{
				if (comp(a->_data, b->_data))
				{
					tmp->_next = a;
					a = a->_next;
				}
				else
				{
					tmp->_next = b;
					b = b->_next;
				}
				tmp->_next->_prev = tmp;
				tmp = tmp->_next;
			}
			if (a)
			{
				tmp->_next = a;
				a->_prev = tmp;
			}
			if (b)
			{
				tmp->_next = b;
				b->_prev = tmp;
			}
			return head;
		}

		void split(Node *src, Node **low, Node **high) {
			Node *firstHalf = NULL;
			Node *secondHalf = NULL;

			if (src == NULL || src->_next == NULL)
			{
				(*low) = src;
				(*high) = NULL;
				return;
			}
			firstHalf = src;
			secondHalf = src->_next;
			while (secondHalf != NULL)
			{
				secondHalf = secondHalf->_next;
				if (secondHalf != NULL)
				{
					secondHalf = secondHalf->_next;
					firstHalf = firstHalf->_next;
				}
			}
			*low = src;
			*high = firstHalf->_next;
			(*high)->_prev = NULL;
			firstHalf->_next = NULL;
		}

		template <typename S>
		void	merge_sort(Node **head, S comp)
		{
			Node *low = NULL;
			Node *high = NULL;
			if (*head == NULL || (*head)->_next == NULL)
				return ;
			split(*head, &low, &high);
			merge_sort(&low, comp);
			merge_sort(&high, comp);
			*head = merge(low, high, comp);
		}

		template <typename S>
		void	listSorted(S comp) {
			Node *tmp = _key->_next;
			tmp->_prev = 0;
			_key->_prev->_next = 0;
			merge_sort(&tmp, comp);
			tmp->_prev = _key;
			_key->_next = tmp;
			while (tmp->_next != 0)
				tmp = tmp->_next;
			tmp->_next = _key;
			_key->_prev = tmp;
		}

	public:

		explicit list(const allocator_type& alloc = allocator_type()) : _size(0), _vAlloc(alloc) {
			_key = new_node(T());
			_key->_next = _key;
			_key->_prev = _key;
		}

		explicit list(size_type n,const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()) : _vAlloc(alloc) {
			_key = new_node(T());
			_key->_next = _key;
			_key->_prev = _key;
			assign(n, val);
		}
		template <class InputIterator>
		list (InputIterator first, InputIterator last,
							const allocator_type& alloc = allocator_type()) : _vAlloc(alloc){
			_key = new_node(T());
			_key->_next = _key;
			_key->_prev = _key;
			assign(first, last);
		}

		list(const list &obj) {
			_key = new_node(T());
			_key->_next = _key;
			_key->_prev = _key;
			*this = obj;
		}

		list &operator = (const list &obj) {
			if (this == &obj)
				return (*this);
			// if (_size)
			// 	clear();
			_nAlloc = obj._nAlloc;
			_vAlloc = obj._vAlloc;
			// _size = obj._size;
			assign(obj.begin(), obj.end());
			return (*this);
		}

		~list() {
			if (_size)
				clear();
			_nAlloc.deallocate(_key, 1);
		}

		iterator					begin() { return _key->_next; }
		const_iterator				begin() const { return _key->_next; }
		const_iterator				cbegin() const { return _key->_next; }
		iterator					end() { return _key; }
		const_iterator				end() const { return _key; }
		const_iterator				cend() const { return _key; }
		reverse_iterator			rbegin() { return _key->_prev; }
		const_reverse_iterator		rbegin() const { return _key->_prev; }
		reverse_iterator			rend() { return _key; }
		const_reverse_iterator		rend() const { return _key; }
		size_type					size() const { return _size; }

		void		assign(size_type n, const value_type &val) {
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
			Node *tmp = _key->_next;
			Node *tmp2 = tmp;
			while (tmp != _key)
			{
				tmp2 = tmp2->_next;
				_nAlloc.destroy(tmp);
				_nAlloc.deallocate(tmp, 1);
				tmp = tmp2;
				// _size--;
			}
			_size = 0;
			_key->_next = _key;
			_key->_prev = _key;
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
			iterator tmp = position.pointer->_next;
			delete_node(position.pointer);
			return (tmp);
		}

		iterator	erase(iterator first, iterator last) {
			iterator tmp = first.pointer->_next;
			while (first != last)
			{
				tmp = first.pointer->_prev;
				delete_node(first.pointer);
				++first;
			}
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

		size_type	max_size() const {
			return size_type(-1) / sizeof(T);
		}

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



		void merge(list &x) {
			merge(x, default_comp<value_type>());
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
			x._key->_next = x._key;
			x._key->_prev = x._key;
		}

		void	sort() {
			sort(default_comp<value_type>());
		}

		template <class Compare>
		void sort (Compare comp) {
			if (_size <= 1)
				return ;
			listSorted(comp);
		}

		void	splice(iterator position, list &x) {
			if (x._size == 0)
				return ;
			x.begin().pointer->_prev = position.pointer->_prev;
			position.pointer->_prev->_next = x.begin().pointer;
			position.pointer->_prev = x.end().pointer->_prev;
			x.end().pointer->_prev->_next = position.pointer;
			_size += x._size;
			x._size = 0;
			x._key->_next = x._key;
			x._key->_prev = x._key;
		}

		void	splice(iterator position, list &x, iterator i) {
			if (x._size == 0)
				return ;
			i.pointer->_prev->_next = i.pointer->_next;
			i.pointer->_next->_prev = i.pointer->_prev;
			position.pointer->_prev->_next = i.pointer;
			i.pointer->_prev = position.pointer->_prev;
			position.pointer->_prev = i.pointer;
			i.pointer->_next = position.pointer;
			x._size--;
			_size++;
		}

		void	splice (iterator position, list& x, iterator first, iterator last) {
			if (x._size == 0)
				return ;
			for (iterator tmp = first; tmp != last; ++tmp)
			{
				x._size--;
				_size++;
			}
			--last;
			first.pointer->_prev->_next = last.pointer->_next;
			last.pointer->_next->_prev = first.pointer->_prev;
			position.pointer->_prev->_next = first.pointer;
			first.pointer->_prev = position.pointer->_prev;
			last.pointer->_next = position.pointer;
			position.pointer->_prev = last.pointer;
		}

		void swap (list& x) {
			if (_size == 0 && x._size == 0)
				return ;
			Node *tmp = _key;
			_key = x._key;
			x._key = tmp;
			size_type tmp_size = _size;
			_size = x._size;
			x._size = tmp_size;
		}

		void	unique() {
			unique(default_equal_comp<value_type>());
		}

		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred) {
		if (_size <= 1)
				return ;
			Node *first = _key->_next;
			Node *second = _key->_next->_next;
			Node *tmp;
			while (second != _key)
			{
				if (binary_pred(second->_data, first->_data))
				{
					tmp = second->_next;
					delete_node(second);
					second = tmp;
				}
				else
				{
					first = first->_next;
					second = second->_next;
				}
			}
		}
	};

	template <class T, class Alloc>
	void swap (list<T, Alloc>& x, list<T, Alloc>& y) {
			x.swap(y);
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2) {
		while (first1!=last1)
		{
			if (first2==last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class T, class Alloc>
	bool operator == (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::list<T, Alloc>::const_iterator it1 = lhs.begin();
		typename ft::list<T, Alloc>::const_iterator ite1 = lhs.end();
		typename ft::list<T, Alloc>::const_iterator it2 = rhs.begin();
		typename ft::list<T, Alloc>::const_iterator ite2 = rhs.end();
		while (it1 != ite1)
		{
			if (*it1 != *it2)
				return (false);
			++it1;
			++it2;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator != (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator < (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator > (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool operator <= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	bool operator >= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return !(rhs < lhs);
	}

}

#endif
