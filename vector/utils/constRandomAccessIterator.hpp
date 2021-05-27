/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constRandomAccessIterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:22:43 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/18 15:04:03 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTRANDOMACCESSITERATOR_HPP
#define CONSTRANDOMACCESSITERATOR_HPP

#include "randomAccessIterator.hpp"

template <typename T>
class const_random_iterator
{
public:
	typedef typename std::ptrdiff_t	difference_type;
    T *pointer;
	const_random_iterator() { pointer = 0; }
	const_random_iterator(const const_random_iterator &obj) { *this = obj; }
	const_random_iterator(const random_iterator<T> &obj) : pointer(obj.pointer) {}
	const_random_iterator(T *obj) : pointer(obj) {}
	~const_random_iterator() {}
	const_random_iterator	&operator = (const const_random_iterator &obj) {
		if (this == &obj)
			return (*this);
		pointer = obj.pointer;
		return (*this);
	}

	const_random_iterator &operator += (int n) {
		pointer = pointer + n;
		return (*this);
	}

	const_random_iterator &operator -= (int n) {
		pointer = pointer - n;
		return (*this);
	}

	const_random_iterator operator + (int n) {
		const_random_iterator temp(pointer + n);
		return (temp);
	}

	const_random_iterator operator - (int n) {
		const_random_iterator temp(pointer - n);
		return (temp);
	}

	difference_type operator - (const const_random_iterator &obj) {
		return (this->pointer - obj.pointer);
	}

	const_random_iterator	&operator ++ () {
		pointer++;
		return (*this);
	}
	const_random_iterator	operator ++ (int) {
		const_random_iterator temp(*this);
		++(*this);
		return (temp);
	}
	const_random_iterator	&operator -- () {
		pointer--;
		return (*this);
	}
	const_random_iterator	operator -- (int) {
		const_random_iterator temp(*this);
		--(*this);
		return (temp);
	}
	T	const	*operator -> () { return (&this->pointer); }
	T	const	&operator * () { return (*this->pointer); }
	T	const	&operator [](int n) { return *(pointer + n); }
	bool	operator != (const const_random_iterator &obj) { return (this->pointer != obj.pointer); }
	bool	operator == (const const_random_iterator &obj) { return (this->pointer == obj.pointer); }
	bool	operator < (const const_random_iterator &obj) { return this->pointer < obj.pointer; }
	bool	operator > (const const_random_iterator &obj) { return this->pointer > obj.pointer; }
	bool	operator >= (const const_random_iterator &obj) { return !(this->pointer < obj.pointer); }
	bool	operator <= (const const_random_iterator &obj) { return !(this->pointer > obj.pointer); }
};

template <typename T>
const_random_iterator<T> operator + (int n, const const_random_iterator<T> &obj) {
	const_random_iterator<T> temp(obj.pointer + n);
	return (temp);
}

template <typename T>
const_random_iterator<T> operator - (int n, const const_random_iterator<T> &obj) {
	const_random_iterator<T> temp(obj.pointer - n);
	return (temp);
}

#endif