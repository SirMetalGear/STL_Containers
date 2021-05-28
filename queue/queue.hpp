/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:47:35 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/29 00:28:29 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "../list/list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue
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
		explicit queue (const container_type& ctnr = container_type()) : c(ctnr) {}
		~queue() {}
		bool			empty() const { return c.empty(); }
		size_type		size() const { return c.size(); }
		reference		back() { return c.back(); }
		const_reference	back() const { return c.back(); }
		reference		front() { return c.front(); }
		const_reference	front() const { return c.front(); }
		void			pop() { c.pop_front(); }
		void			push(const value_type &__v) { c.push_back(__v); }
	};
	template <class T, class Container>
	bool operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return lhs.c == rhs.c;
	}
	
	template <class T, class Container>
	bool operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return !(lhs == rhs);
	}
	
	template <class T, class Container>
	bool operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return lhs.c < rhs.c;
	}
	
	template <class T, class Container>
	bool operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return !(rhs < lhs);
	}
	
	template <class T, class Container>
	bool operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return rhs < lhs;
	}
	
	template <class T, class Container>
	bool operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return !(lhs < rhs);
	}
}

#endif
