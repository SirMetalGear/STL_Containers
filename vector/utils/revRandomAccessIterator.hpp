/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revRandomAccessIterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:22:43 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/26 15:29:32 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVRANDOMACCESSITERATOR_HPP
#define REVRANDOMACCESSITERATOR_HPP

// template <typename T>
// class random_iterator;
// # include "randomAccessIterator.hpp"

template <typename T>
class rev_random_iterator
{
public:
	typedef typename std::ptrdiff_t	difference_type;
    T	iter;
	rev_random_iterator() { iter = 0; }
	rev_random_iterator(const rev_random_iterator &obj) { *this = obj; }
	explicit rev_random_iterator(T &obj) : iter(--obj) {}
	// rev_random_iterator(T *obj) : iter(obj) {}
	~rev_random_iterator() {}
	rev_random_iterator	&operator = (const rev_random_iterator &obj) {
		if (this == &obj)
			return (*this);
		iter = obj.iter;
		return (*this);
	}

	rev_random_iterator &operator += (int n) {
		iter = iter - n;
		return (*this);
	}

	rev_random_iterator &operator -= (int n) {
		iter = iter + n;
		return (*this);
	}

	rev_random_iterator operator + (int n) {
		rev_random_iterator temp(iter - n);
		return (temp);
	}

	rev_random_iterator operator - (int n) {
		rev_random_iterator temp(iter + n);
		return (temp);
	}

	difference_type operator - (const rev_random_iterator &obj) {
		return (this->iter - obj.iter);
	}

	rev_random_iterator	&operator ++ () {
		iter--;
		return (*this);
	}
	rev_random_iterator	operator ++ (int) {
		rev_random_iterator temp(*this);
		--iter;
		return (temp);
	}
	rev_random_iterator	&operator -- () {
		iter++;
		return (*this);
	}
	rev_random_iterator	operator -- (int) {
		rev_random_iterator temp(*this);
		++(*this);
		return (temp);
	}
	// T		*operator -> () { return (&this->iter); }
	typename T::value_type		&operator * () { return (*iter.pointer); }
	// T		&operator [] (int n) { return *(iter - n); }
	bool	operator != (const rev_random_iterator &obj) { return (this->iter != obj.iter); }
	// bool	operator == (const rev_random_iterator &obj) { return (this->iter == obj.iter); }
	// bool	operator < (const rev_random_iterator &obj) { return this->iter < obj.iter; }
	// bool	operator > (const rev_random_iterator &obj) { return this->iter > obj.iter; }
	// bool	operator >= (const rev_random_iterator &obj) { return !(this->iter < obj.iter); }
	// bool	operator <= (const rev_random_iterator &obj) { return !(this->iter > obj.iter); }
};

template <typename T>
rev_random_iterator<T> operator + (int n, const rev_random_iterator<T> &obj) {
	rev_random_iterator<T> temp(obj.iter - n);
	return (temp);
}

template <typename T>
rev_random_iterator<T> operator - (int n, const rev_random_iterator<T> &obj) {
	rev_random_iterator<T> temp(obj.iter + n);
	return (temp);
}

#endif
