/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_rev_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:38:27 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/15 17:13:20 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_REV_ITERATOR_HPP
# define CONST_REV_ITERATOR_HPP

#include "rev_iterator.hpp"

template <typename T, typename Node>
class constRev_iterator
{
public:
    typedef rev_iterator<T, Node>	rev_iterator;
    Node	*pointer;
	constRev_iterator() { pointer = 0; }
	constRev_iterator(const constRev_iterator &obj) { *this = obj; }
    constRev_iterator(const rev_iterator &obj) : pointer(obj.pointer) {}
	constRev_iterator(Node *obj) : pointer(obj) {}
	~constRev_iterator() {}
	constRev_iterator	&operator = (const constRev_iterator &obj) {
		if (this == &obj)
			return (*this);
		pointer = obj.pointer;
		return (*this);
	}
	constRev_iterator	&operator -- () {
		pointer = pointer->_next;
		return (*this);
	}
	constRev_iterator	operator -- (int) {
		constRev_iterator temp(*this);
		++(*this);
		return (temp);
	}
	constRev_iterator	&operator ++ () {
		pointer = pointer->_prev;
		return (*this);
	}
	constRev_iterator	operator ++ (int) {
		constRev_iterator temp(*this);
		--(*this);
		return (temp);
	}
	T	const	*operator -> () const { return (&this->pointer->_data); }
	T	const	&operator * () const { return (this->pointer->_data); }
	bool	operator != (const constRev_iterator &obj) const { return (this->pointer != obj.pointer); }
	bool	operator == (const constRev_iterator &obj) const { return (this->pointer == obj.pointer); }
};

#endif
