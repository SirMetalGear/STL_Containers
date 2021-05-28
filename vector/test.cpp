/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:16:16 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/28 22:27:15 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <list>
// void    test()
// {
// 	ft::vector<int> myvector;
// 	for (int i = 0; i < 10; i++)
// 		myvector.push_back(i);

// 	typedef ft::vector<int>::iterator iter_type;
// 	// ? 0 1 2 3 4 5 6 7 8 9 ?
// 	iter_type from(myvector.begin());				  //   ^
// 													  //         ------>
// 	iter_type until(myvector.end());				  //                       ^
// 													  //
// 	rev_random_iterator<iter_type> rev_until(from); // ^
// 													  //         <------
// 	rev_random_iterator<iter_type> rev_from(until); //                     ^

// 	std::cout << "reversed begin: " << *rev_from << std::endl;
// 	std::cout << "reversed end  : " << *rev_until << std::endl;
// 	std::cout << "myvector:";
// 	while (rev_from != rev_until)
// 	{
// 		std::cout << ' ' << *rev_from++;
// 	}
// 	std::cout << '\n';
// }

// void    test2()
// {
// 	std::vector<int> myvector;
// 	for (int i = 0; i < 10; i++)
// 		myvector.push_back(i);

// 	typedef std::vector<int>::iterator iter_type;
// 	// ? 0 1 2 3 4 5 6 7 8 9 ?
// 	iter_type from(myvector.begin());				  //   ^
// 													  //         ------>
// 	iter_type until(myvector.end());				  //                       ^
// 													  //
// 	std::reverse_iterator<iter_type> rev_until(from); // ^
// 													  //         <------
// 	std::reverse_iterator<iter_type> rev_from(until); //                     ^

// 	std::cout << "myvector:";
// 	while (rev_from != rev_until)
// 		std::cout << ' ' << *rev_from++;
// 	std::cout << '\n';
// }

int main()
{
	// std::vector<int> real(5);
	// int j=0;
	// std::vector<int>::reverse_iterator rit_r = real.rbegin();
	// std::cout << "rev iterator at begin: " << *rit_r << std::endl;
	// std::cout << "rev iterator at end: " << *real.rend() << std::endl;
	// for (; rit_r!= real.rend(); ++rit_r)
	//     *rit_r = ++j;
	// std::cout << "real contains:";
	// for (std::vector<int>::iterator it_r = real.begin(); it_r != real.end(); ++it_r)
	//     std::cout << ' ' << *it_r;
	// std::cout << '\n';
	// std::vector<int> vec_r;
	// for (int k = 0; k < 10; k++)
	//     vec_r.push_back(k + 1);
	// std::cout << "capacity: " << vec_r.capacity() << std::endl;
	// std::vector<int>::reverse_iterator it_r = vec_r.rbegin();
	// std::vector<int>::reverse_iterator it2_r = vec_r.rbegin();
	// it2_r = it_r + 2;
	// std::cout << *it2_r << std::endl;
	// it_r += 3;
	// std::cout << *it_r << std::endl;
	// it_r -= 2;
	// std::cout << *it_r << std::endl;
	// std::cout << it_r[9] << std::endl;
	// std::cout << vec_r.operator[](9) << std::endl;
	// ft::vector<int> my(5);
	// int i=0;
	// ft::vector<int>::reverse_iterator rit_m = my.rbegin();
	// std::cout << "rev iterator at begin: " << *rit_m << std::endl;
	// std::cout << "rev iterator at end: " << *my.rend() << std::endl;
	// for (; rit_m!= my.rend(); ++rit_m)
	//     *rit_m = ++i;
	ft::vector<int> vec_m;
	for (int i = 0; i < 10; i++)
	    vec_m.push_back(i + 1);
	// std::cout << "capacity: " << vec_m.capacity() << std::endl;
	std::cout << &vec_m[0] << std::endl;
	// ft::vector<int>::iterator it = &vec_m[0];
	ft::vector<int>::const_iterator it_m = vec_m.begin();
	it_m += 2;
	std::cout << *it_m;
	// std::cout << "my contains:";
	// for (std::vector<int>::const_iterator it_m = vec_m.begin(); it_m != vec_m.end(); ++it_m)
	// {
	//     std::cout << ' ' << *it_m;
	// 	it_m -= 2;
	// }
	std::cout << '\n';
	// ft::vector<int>::reverse_iterator it2_m = vec_m.rbegin();
	// it2_m = it_m + 2;
	// std::cout << *it2_m << std::endl;
	// it_m += 3;
	// std::cout << *it_m << std::endl;
	// it_m -= 2;
	// std::cout << *it_m << std::endl;
	// std::cout << it_m[9] << std::endl;
	// std::cout << vec_m.operator[](9) << std::endl;
	// test();
	// test2();
	return 0;
}