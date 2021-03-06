/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:47:35 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/29 00:08:36 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "../list/list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class stack
	{
	public:
		typedef Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;
		typedef typename container_type::size_type			size_type;

	private:
		container_type	c;
	public:
		explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
		~stack() {}
		bool			empty() const { return c.empty(); }
		size_type		size() const { return c.size(); }
		reference		top() { return c.back(); }
		const_reference	top() const { return c.back(); }
		void			pop() { c.pop_back(); }
		void			push(const value_type &__v) { c.push_back(__v); }
	};
	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.c == rhs.c;
	}
	
	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return !(lhs == rhs);
	}
	
	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.c < rhs.c;
	}
	
	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return !(rhs < lhs);
	}
	
	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return rhs < lhs;
	}
	
	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return !(lhs < rhs);
	}
}

#endif
