/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:04:44 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/15 17:12:58 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP

#include "iterator.hpp"

template <typename T, typename Node>
class const_iterator
{
public:
	typedef base_iterator<T, Node>	iterator;
    Node const						*pointer;
	const_iterator() { pointer = 0; }
	const_iterator(const Node *obj) : pointer(obj) {}
	const_iterator(const iterator &obj) : pointer(obj.pointer) {}
	const_iterator(Node *obj) : pointer(obj) {}
	~const_iterator() {}
	const_iterator &operator ++ () {
		pointer = pointer->_next;
		return (*this);
	}
	const_iterator operator ++ (int) {
		const_iterator temp(*this);
		++*this;
		return (temp);
	}
	const_iterator &operator -- () {
		pointer = pointer->_prev;
		return (*this);
	}
	const_iterator operator -- (int) {
		const_iterator temp(*this);
		--*this;
		return (temp);
	}
	T const	 *operator -> () const { return (&this->pointer->_data); }
	T const	 &operator * () const { return (this->pointer->_data); }
	bool	operator != (const const_iterator &obj) const { return (this->pointer != obj.pointer); }
	bool	operator == (const const_iterator &obj) const { return (this->pointer == obj.pointer); }
};

#endif
