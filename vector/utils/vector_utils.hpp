/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:36:20 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/15 20:37:54 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_UTILS
#define VECTOR_UTILS

namespace ft
{
    template<bool B, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <typename T>
	struct is_integer {
		static const bool value = std::numeric_limits<T>::is_integer;
	};
}

#endif
