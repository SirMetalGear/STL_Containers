/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:10:04 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/21 19:03:17 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	template <class _T1>
	struct less
	{
		bool operator()(const _T1& __x, const _T1& __y) const {return __x < __y;}
	};

	template<bool B, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <typename T>
	struct is_integer {
		static const bool value = std::numeric_limits<T>::is_integer;
	};

	template <typename T1, typename T2>
	class pair
	{
	public:
		typedef T1	first_type;
		typedef	T2	second_type;
		T1			first;
		T2			second;
		pair() : first(first_type()), second(second_type()) {}
		pair(T1 const &_t1, T2 const &_t2) : first(_t1), second(_t2) {}
		template <typename U1, typename U2>
		pair(const pair<U1, U2> &obj) : first(obj.first), second(obj.second) {}
		pair& operator=(pair const &obj) {
			if (this == &obj)
				return *this;
			first = obj.first;
			second = obj.second;
			return *this;
		}
		~pair() {}
	};
}

#endif