/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:04:44 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/09 21:53:55 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

template <typename T, typename Node>
class base_iterator
{
public:
    Node	*pointer;
	base_iterator() { pointer = 0; }
	base_iterator(const base_iterator &obj) { *this = obj; }
	base_iterator(Node *obj) : pointer(obj) {}
	~base_iterator() {}
	base_iterator	&operator = (const base_iterator &obj) {
		if (this == &obj)
			return (*this);
		pointer = obj.pointer;
		return (*this);
	}
	base_iterator	&operator ++ () {
		pointer = pointer->_next;
		return (*this);
	}
	base_iterator	operator ++ (int) {
		base_iterator *temp = this;
		++(*this);
		return (*temp);
	}
	base_iterator	&operator -- () {
		pointer = pointer->_prev;
		return (*this);
	}
	base_iterator	operator -- (int) {
		base_iterator *temp = this;
		--(*this);
		return (*temp);
	}
	T		*operator -> () { return (&this->pointer->_data); }
	T		&operator * () { return (this->pointer->_data); }
	bool	operator != (const base_iterator &obj) { return (this->pointer != obj.pointer); }
	bool	operator == (const base_iterator &obj) { return (this->pointer == obj.pointer); }
};

#endif