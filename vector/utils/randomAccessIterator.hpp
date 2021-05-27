/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:22:43 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/27 11:41:11 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

template <typename T>
class random_iterator
{
public:
	typedef typename std::ptrdiff_t	difference_type;
	typedef T	value_type;
    value_type	*pointer;
	random_iterator() { pointer = 0; }
	random_iterator(const random_iterator &obj) { *this = obj; }
	random_iterator(T *obj) : pointer(obj) {}
	~random_iterator() {}
	random_iterator	&operator = (const random_iterator &obj) {
		if (this == &obj)
			return (*this);
		pointer = obj.pointer;
		return (*this);
	}

	random_iterator &operator += (int n) {
		pointer = pointer + n;
		return (*this);
	}

	random_iterator &operator -= (int n) {
		pointer = pointer - n;
		return (*this);
	}

	random_iterator operator + (int n) {
		random_iterator temp(pointer + n);
		return (temp);
	}

	random_iterator operator - (int n) {
		random_iterator temp(pointer - n);
		return (temp);
	}

	difference_type operator - (const random_iterator &obj) {
		return (this->pointer - obj.pointer);
	}

	random_iterator	&operator ++ () {
		pointer++;
		return (*this);
	}
	random_iterator	operator ++ (int) {
		random_iterator temp(*this);
		++(*this);
		return (temp);
	}
	random_iterator	&operator -- () {
		pointer--;
		return (*this);
	}
	random_iterator	operator -- (int) {
		random_iterator temp(*this);
		--(*this);
		return (temp);
	}
	value_type		*operator -> () { return (&this->pointer); }
	value_type		&operator * () const { return (*this->pointer); }
	value_type		&operator [] (int n) { return *(pointer + n); }
	bool	operator != (const random_iterator &obj) { return (this->pointer != obj.pointer); }
	bool	operator == (const random_iterator &obj) { return (this->pointer == obj.pointer); }
	bool	operator < (const random_iterator &obj) { return this->pointer < obj.pointer; }
	bool	operator > (const random_iterator &obj) { return this->pointer > obj.pointer; }
	bool	operator >= (const random_iterator &obj) { return !(this->pointer < obj.pointer); }
	bool	operator <= (const random_iterator &obj) { return !(this->pointer > obj.pointer); }
};

template <typename T>
random_iterator<T> operator + (int n, const random_iterator<T> &obj) {
	random_iterator<T> temp(obj.pointer + n);
	return (temp);
}

template <typename T>
random_iterator<T> operator - (int n, const random_iterator<T> &obj) {
	random_iterator<T> temp(obj.pointer - n);
	return (temp);
}

#endif
