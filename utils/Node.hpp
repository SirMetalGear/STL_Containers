/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 10:57:14 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/09 13:44:03 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

template <typename T>
class BaseNode
{
public:
	T			_data;
	BaseNode	*_prev;
	BaseNode	*_next;
	BaseNode(T const &data){
		_data = data;
		_prev = 0;
		_next = 0;
	};
	BaseNode(const BaseNode &obj) {
		*this = obj;
	}
	BaseNode &operator = (const BaseNode &obj) {
		if (this == &obj)
			return (*this);
		_data = obj._data;
		_prev = obj._prev;
		_next = obj._next;
		return (*this);
	}
	~BaseNode() { std::cout << "Node is destroyed!\n"; }
};

#endif
