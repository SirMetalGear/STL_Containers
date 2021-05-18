/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:23:05 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/15 17:15:03 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_ITERATOR_HPP
# define REV_ITERATOR_HPP

template <typename T, typename Node>
class rev_iterator
{
public:
    Node	*pointer;
	rev_iterator() { pointer = 0; }
	rev_iterator(const rev_iterator &obj) { *this = obj; }
	rev_iterator(Node *obj) : pointer(obj) {}
	~rev_iterator() {}
	rev_iterator	&operator = (const rev_iterator &obj) {
		if (this == &obj)
			return (*this);
		pointer = obj.pointer;
		return (*this);
	}
	rev_iterator	&operator -- () {
		pointer = pointer->_next;
		return (*this);
	}
	rev_iterator	operator -- (int) {
		rev_iterator temp(*this);
		++(*this);
		return (temp);
	}
	rev_iterator	&operator ++ () {
		pointer = pointer->_prev;
		return (*this);
	}
	rev_iterator	operator ++ (int) {
		rev_iterator temp(*this);
		--(*this);
		return (temp);
	}
	T		*operator -> () { return (&this->pointer->_data); }
	T		&operator * () { return (this->pointer->_data); }
	bool	operator != (const rev_iterator &obj) { return (this->pointer != obj.pointer); }
	bool	operator == (const rev_iterator &obj) { return (this->pointer == obj.pointer); }
};

#endif
