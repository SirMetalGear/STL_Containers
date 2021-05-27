/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:06:12 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/27 12:55:44 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "utils/utils.hpp"
# include "utils/red_black_tree.hpp"

namespace ft
{
	template <typename Key, class T,
		class Compare = less<Key>, class Alloc = std::allocator< pair<const Key, T> > >
	class map
	{
	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef pair<const key_type, mapped_type>		value_type;
		typedef Compare									key_compare;
		typedef Alloc									allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
	private:
		typedef typename Alloc::template rebind<Node>::other	NodeAllocator;
	public:
		map(/* args */);
		~map();
	};
	
}


#endif