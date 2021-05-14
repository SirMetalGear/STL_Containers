/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:22:43 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/14 16:28:21 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
class random_iterator
{
public:
    T	*pointer;
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
	random_iterator	&operator ++ () {
		pointer = pointer->_next;
		return (*this);
	}
	random_iterator	operator ++ (int) {
		random_iterator *temp = this;
		++(*this);
		return (*temp);
	}
	random_iterator	&operator -- () {
		pointer = pointer->_prev;
		return (*this);
	}
	random_iterator	operator -- (int) {
		random_iterator *temp = this;
		--(*this);
		return (*temp);
	}
	T		*operator -> () { return (&this->pointer->_data); }
	T		&operator * () { return (this->pointer->_data); }
	bool	operator != (const random_iterator &obj) { return (this->pointer != obj.pointer); }
	bool	operator == (const random_iterator &obj) { return (this->pointer == obj.pointer); }
};
