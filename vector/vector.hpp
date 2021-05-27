/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:21:07 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/24 21:41:12 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "utils/constRandomAccessIterator.hpp"
#include "utils/constRevRandomAccessIterator.hpp"
#include "utils/vector_utils.hpp"
#include <exception>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference		 	reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef random_iterator<T>							iterator;
		typedef const_random_iterator<T>					const_iterator;
		typedef rev_random_iterator<T>						reverse_iterator;
		typedef const_rev_random_iterator<T>				const_reverse_iterator;
		typedef typename std::ptrdiff_t						difference_type;
		typedef typename std::size_t						size_type;
	private:
		T 				*_array;
		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;

		void	increase_capacity() {
			size_type prev_capacity = _capacity;
			_capacity = _size * 2;
			T *tmp = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&tmp[i], _array[i]);
			for (size_type i = _size; i < _capacity; i++)
				_alloc.construct(&tmp[i], value_type());
			for (size_type i = 0; i < prev_capacity; i++)
				_alloc.destroy(&_array[i]);
			_alloc.deallocate(_array, prev_capacity);
			_array = tmp;
		}

		void	increase_capacity(size_type n) {
			size_type prev_capacity = _capacity;
			_capacity = n;
			T *tmp = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&tmp[i], _array[i]);
			for (size_type i = 0; i < prev_capacity; i++)
				_alloc.destroy(&_array[i]);
			_alloc.deallocate(_array, prev_capacity);
			_array = tmp;
		}

	public:
		explicit vector(const allocator_type& alloc = allocator_type()) : _array(0), _alloc(alloc), _size(0), _capacity(0) {}
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n)
		{
			if (n == 0)
				return ;
			_array = _alloc.allocate(_capacity);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_array[i], val);
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
												typename ft::enable_if<!ft::is_integer<InputIterator>::value>::type* = 0)
		:_alloc(alloc), _size(0), _capacity(0)
		{
			difference_type n = last - first;
			if (n < 0)
				throw std::length_error("vector");
			if (n == 0)
				return ;
			_size = n;
			_capacity = n;
			_array = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_array[i], *first++);
		}
		vector(const vector &obj) : _size(0), _capacity(0)
		{
			*this = obj;
		}
		vector &operator = (const vector & obj)
		{
			if (_size)
			{
				clear();
				_alloc.deallocate(_array, _capacity);
			}
			_alloc = obj._alloc;
			_size = obj._size;
			_capacity = obj._size;
			if (obj._size == 0)
				return *this;
			_array = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_array[i], obj._array[i]);
			return *this;
		}
		~vector() {
			clear();
			_alloc.deallocate(_array, _capacity);
		}
		reference operator[] (size_type n) { return _array[n]; }
		const_reference operator[] (size_type n) const { return _array[n]; }
		void	push_back(const value_type& val) {
			if (_size == 0 && _capacity == 0)
			{
				_array = _alloc.allocate(1);
				_alloc.construct(&_array[0], val);
				_capacity++;
			}
			else
			{
				if (_size + 1 > _capacity)
					increase_capacity();
				_alloc.construct(&_array[_size], val);
			}
			_size++;
		}
		void	clear() {
			if (_size == 0)
				return ;
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			_size = 0;
		}
		
		iterator	begin() { return &_array[0]; }
		const_iterator begin() const { return &_array[0]; }
		reverse_iterator	rbegin() { return &_array[_size - 1]; }
		const_reverse_iterator rbegin() const { return &_array[_size - 1]; }
		reverse_iterator	rend() { return &_array[-1]; }
		const_reverse_iterator	rend() const { return &_array[-1]; }
		iterator	end() { return &_array[_size]; }
		const_iterator end() const { return &_array[_size]; }
		size_type	capacity() const { return _capacity; }
		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integer<InputIterator>::value>::type* = 0) {
			size_type prev_size = _size;
			clear();
			difference_type n = last - first;
			if (n < 0)
				throw std::out_of_range("vector");
			if ((size_type)n > _capacity)
			{
				_alloc.deallocate(_array, prev_size);
				_array = _alloc.allocate(n);
			}
			_size = (size_type)n;
			for (size_type i = 0; i < (size_type)n; i++)
				_alloc.construct(&_array[i], *first++);
		}
		void	assign(size_type n, const value_type& val) {
			if (n == 0)
				return ;
			size_type prev_size = _size;
			clear();
			if (n > _capacity)
			{
				_alloc.deallocate(_array, prev_size);
				_array = _alloc.allocate(n);
			}
			_size = n;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_array[i], val);
		}
		size_type	size() const { return _size; }
		reference	at(size_type n) {
			if (n < 0 || n >= _size)
				throw std::out_of_range("Out of range");
			return (_array[n]);
		}
		const_reference	at(size_type n) const {
			if (n < 0 || n >= _size)
				throw std::out_of_range("Out of range");
			return (_array[n]);
		}
		reference	back() { return _array[_size - 1]; }
		const_reference back() const { return _array[_size - 1]; }
		bool empty() const { return _size == 0; }
		// iterator erase (iterator position) {
		// 	if (position == end() - 1)
		// 	{
		// 		_alloc.destroy(&_array[_size - 1]);
		// 		_size--;
		// 		return (&_array[_size]);
		// 	}
		// 	else
		// 	{
		// 		size_type prev_capacity = _capacity;
		// 		difference_type n = position - begin();
		// 		T *tmp = _alloc.allocate(_capacity);
		// 		size_type j = 0;
		// 		for (size_type i = 0; i < _size; i++)
		// 		{
		// 			if (i != (size_type)n)
		// 				_alloc.construct(&tmp[j++], _array[i]);
		// 		}
		// 		for (size_type i = 0; i < _size; i++)
		// 			_alloc.destroy(&_array[i]);
		// 		_alloc.deallocate(_array, prev_capacity);
		// 		_array = tmp;
		// 		_size--;
		// 		return (&_array[n]);
		// 	}
		// }
		iterator erase (iterator position) {
			if (position == end() - 1)
				_alloc.destroy(&_array[_size - 1]);
			else
			{
				difference_type n = position - begin();
				size_type j = n;
				while (j < _size - 1)
				{
					_alloc.destroy(&_array[j]);
					_alloc.construct(&_array[j], _array[j + 1]);
					_alloc.destroy(&_array[j + 1]);
					j++;
				}
			}
			_size--;
			return position;
		}
		// iterator erase (iterator first, iterator last)
		// {
		// 	difference_type start = first - begin();
		// 	difference_type end = last - begin();
		// 	if (end - start < 0)
		// 		throw std::out_of_range("Out of range");
		// 	if (end - start == 0)
		// 		return first;
		// 	T *tmp = _alloc.allocate(_capacity);
		// 	size_type j = 0;
		// 	for (size_type i = 0; i < _size; i++)
		// 	{
		// 		if ((long)i >= start && (long)i < end)
		// 			continue ;
		// 		_alloc.construct(&tmp[j++], _array[i]);
		// 	}
		// 	for (size_type i = 0; i < _size; i++)
		// 		_alloc.destroy(&_array[i]);
		// 	_alloc.deallocate(_array, _capacity);
		// 	_array = tmp;
		// 	_size -= end - start;
		// 	return &_array[start];
		// }
		iterator erase (iterator first, iterator last)
		{
			difference_type start = first - begin();
			difference_type end = last - begin();
			difference_type diff = end - start;
			if (diff < 0)
				throw std::out_of_range("Out of range");
			if (diff == 0)
				return first;
			while (start != end)
				_alloc.destroy(&_array[start++]);
			while (start < (long)_size)
			{
				_alloc.construct(&_array[start - diff], _array[start]);
				_alloc.destroy(&_array[start]);
				start++;
			}
			_size -= diff;
			return first;
		}

		reference front() { return _array[0]; }

		const_reference front() const { return _array[0]; }

		allocator_type get_allocator() const { return _alloc; }

		iterator	insert(iterator position, const value_type &val)
		{
			difference_type pos = position - begin();
			if (_size + 1 > _capacity)
				increase_capacity();
			size_type last_pos = _size;
			while (last_pos != (size_type)pos)
			{
				_alloc.construct(&_array[last_pos + 1], _array[last_pos]);
				_alloc.destroy(&_array[last_pos]);
				last_pos--;
			}
			_alloc.construct(&_array[pos], val);
			_size++;
			return (&_array[pos]);
		}

		void insert(iterator position, size_type n, const value_type& val) {
			if (n == 0)
				return ;
			difference_type pos = position - begin();
			if (_size + n > _capacity)
				increase_capacity(n + _size);
			size_type last_pos = (_size - 1) + n;
			size_type pos_n = pos + n;
			while (last_pos >= pos_n)
			{
				_alloc.construct(&_array[last_pos], _array[last_pos - n]);
				_alloc.destroy(&_array[last_pos - n]);
				if (last_pos == 0)
					break ;
				last_pos--;
			}
			while (last_pos >= (unsigned long)pos)
			{
				_alloc.construct(&_array[last_pos], val);
				_size++;
				if (last_pos == 0)
					break ;
				last_pos--;
			}
		}

		template <class InputIterator>
   		void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integer<InputIterator>::value>::type* = 0)
		{
			difference_type n = last - first;
			last--;
			if (n < 0)
				throw std::out_of_range("vector: out of range");
			if (n == 0)
				return ;
			difference_type pos = position - begin();
			if (_size + n > _capacity)
				increase_capacity(n + _size);
			size_type last_pos = _size + n - 1;
			size_type pos_n = pos + n;
			while (last_pos >= pos_n)
			{
				_alloc.construct(&_array[last_pos], _array[last_pos - n]);
				_alloc.destroy(&_array[last_pos - n]);
				if (last_pos == 0)
					break ;
				last_pos--;
			}
			while (last_pos >= (unsigned long)pos)
			{
				_alloc.construct(&_array[last_pos], *last--);
				_size++;
				if (last_pos == 0)
					break ;
				last_pos--;
			}
		}

		size_type max_size() const { return size_type(-1) / sizeof(value_type); }
		void	pop_back() {
			if (_size == 0)
				return ;
			_size--;
			_alloc.destroy(&_array[_size]);
		}
		
		void	reserve(size_type n) {
			if (n <= _capacity)
				return ;
			if (n > max_size())
				throw std::length_error("greater than possible max size");
			increase_capacity(n);
		}

		void	resize(size_type n, value_type val = value_type()) {
			while (n < _size)
				pop_back();
			while (n > _size)
				push_back(val);
		}

		void	swap(vector &x)
		{
			if (_alloc != x._alloc)
				throw std::exception();
			size_type tmp_size = _size;
			_size = x._size;
			x._size = tmp_size;
			value_type *tmp_array = _array;
			_array = x._array;
			x._array = tmp_array;
			size_type tmp_capacity = _capacity;
			_capacity = x._capacity;
			x._capacity = tmp_capacity;
		}
	};
	template <class T, class Alloc>
	void swap (vector<T, Alloc>& x, vector<T, Alloc>& y) {
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
	bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T, Alloc>::const_iterator it1 = lhs.begin();
		typename ft::vector<T, Alloc>::const_iterator ite1 = lhs.end();
		typename ft::vector<T, Alloc>::const_iterator it2 = rhs.begin();
		typename ft::vector<T, Alloc>::const_iterator ite2 = rhs.end();
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
	bool operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator < (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator > (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}
}

#endif
