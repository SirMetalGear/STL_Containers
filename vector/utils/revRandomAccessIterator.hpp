/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revRandomAccessIterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:22:43 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/18 14:46:14 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVRANDOMACCESSITERATOR_HPP
#define REVRANDOMACCESSITERATOR_HPP

template <typename T>
class rev_random_iterator
{
public:
	typedef typename std::ptrdiff_t	difference_type;
    T	*pointer;
	rev_random_iterator() { pointer = 0; }
	rev_random_iterator(const rev_random_iterator &obj) { *this = obj; }
	rev_random_iterator(T *obj) : pointer(obj) {}
	~rev_random_iterator() {}
	rev_random_iterator	&operator = (const rev_random_iterator &obj) {
		if (this == &obj)
			return (*this);
		pointer = obj.pointer;
		return (*this);
	}

	rev_random_iterator &operator += (int n) {
		pointer = pointer - n;
		return (*this);
	}

	rev_random_iterator &operator -= (int n) {
		pointer = pointer + n;
		return (*this);
	}

	rev_random_iterator operator + (int n) {
		rev_random_iterator temp(pointer - n);
		return (temp);
	}

	rev_random_iterator operator - (int n) {
		rev_random_iterator temp(pointer + n);
		return (temp);
	}

	difference_type operator - (const rev_random_iterator &obj) {
		return (this->pointer - obj.pointer);
	}

	rev_random_iterator	&operator ++ () {
		pointer--;
		return (*this);
	}
	rev_random_iterator	operator ++ (int) {
		rev_random_iterator temp(*this);
		--(*this);
		return (temp);
	}
	rev_random_iterator	&operator -- () {
		pointer++;
		return (*this);
	}
	rev_random_iterator	operator -- (int) {
		rev_random_iterator temp(*this);
		++(*this);
		return (temp);
	}
	T		*operator -> () { return (&this->pointer); }
	T		&operator * () { return (*this->pointer); }
	T		&operator [] (int n) { return *(pointer - n); }
	bool	operator != (const rev_random_iterator &obj) { return (this->pointer != obj.pointer); }
	bool	operator == (const rev_random_iterator &obj) { return (this->pointer == obj.pointer); }
	bool	operator < (const rev_random_iterator &obj) { return this->pointer < obj.pointer; }
	bool	operator > (const rev_random_iterator &obj) { return this->pointer > obj.pointer; }
	bool	operator >= (const rev_random_iterator &obj) { return !(this->pointer < obj.pointer); }
	bool	operator <= (const rev_random_iterator &obj) { return !(this->pointer > obj.pointer); }
};

template <typename T>
rev_random_iterator<T> operator + (int n, const rev_random_iterator<T> &obj) {
	rev_random_iterator<T> temp(obj.pointer - n);
	return (temp);
}

template <typename T>
rev_random_iterator<T> operator - (int n, const rev_random_iterator<T> &obj) {
	rev_random_iterator<T> temp(obj.pointer + n);
	return (temp);
}

#endif
