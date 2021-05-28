/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revRandomAccessIterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:22:43 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/28 23:01:19 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVRANDOMACCESSITERATOR_HPP
#define REVRANDOMACCESSITERATOR_HPP

namespace ft
{
	template <typename T>
	class rev_random_iterator
	{
	public:
		typedef typename std::ptrdiff_t difference_type;
		T iter;
		rev_random_iterator() : iter() {}
		template <class _Up>
		rev_random_iterator(const rev_random_iterator<_Up> &obj) : iter(obj.iter) {}
		rev_random_iterator(T obj) : iter(obj) {}
		~rev_random_iterator() {}

		rev_random_iterator &operator+=(int n)
		{
			iter = iter - n;
			return (*this);
		}

		rev_random_iterator &operator-=(int n)
		{
			iter = iter + n;
			return (*this);
		}

		rev_random_iterator operator+(int n) const
		{
			return rev_random_iterator(iter - n);
		}

		rev_random_iterator operator-(int n) const
		{
			return rev_random_iterator(iter + n);
		}

		difference_type operator-(const rev_random_iterator &obj)
		{
			return (this->iter - obj.iter);
		}

		rev_random_iterator &operator++()
		{
			iter--;
			return (*this);
		}
		rev_random_iterator operator++(int)
		{
			rev_random_iterator temp(*this);
			--iter;
			return (temp);
		}
		rev_random_iterator &operator--()
		{
			iter++;
			return (*this);
		}
		rev_random_iterator operator--(int)
		{
			rev_random_iterator temp(*this);
			++(*this);
			return (temp);
		}
		T *operator->() const { return (&this->iter); }
		typename T::value_type &operator*() const
		{
			T tmp = iter;
			return *--tmp;
		}
		typename T::value_type &operator[](int n) const
		{
			return *(*this + n);
		}
		bool operator!=(const rev_random_iterator &obj) const { return (iter != obj.iter); }
		bool operator==(const rev_random_iterator &obj) const { return (iter == obj.iter); }
		bool operator<(const rev_random_iterator &obj) const { return iter < obj.iter; }
		bool operator>(const rev_random_iterator &obj) const { return iter > obj.iter; }
		bool operator>=(const rev_random_iterator &obj) const { return !(iter < obj.iter); }
		bool operator<=(const rev_random_iterator &obj) const { return !(iter > obj.iter); }
	};

	template <typename T>
	rev_random_iterator<T> operator+(int n, const rev_random_iterator<T> &obj)
	{
		rev_random_iterator<T> temp(obj.iter - n);
		return (temp);
	}

	template <typename T>
	rev_random_iterator<T> operator-(int n, const rev_random_iterator<T> &obj)
	{
		rev_random_iterator<T> temp(obj.iter + n);
		return (temp);
	}
}

#endif
