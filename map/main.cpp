/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:04:49 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/27 12:57:02 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <map>
#include <iostream>
#include "map.hpp"

int		main()
{
	ft::tree<int, int> a;
	ft::pair<int, int> b(0, 5);
	a.insert(b);
	a.insert(ft::pair<int, int>(10, 6));
	a.insert(ft::pair<int, int>(6, 9));
	a.insert(ft::pair<int, int>(7, 9));
	a.insert(ft::pair<int, int>(15, 9));
	a.insert(ft::pair<int, int>(16, 9));
	a.insert(ft::pair<int, int>(1, 6));
	a.insert(ft::pair<int, int>(17, 9));
	a.insert(ft::pair<int, int>(18, 9));
	a.insert(ft::pair<int, int>(2, 2));
	a.insert(ft::pair<int, int>(11, 6));
	a.insert(ft::pair<int, int>(12, 2));
	a.insert(ft::pair<int, int>(13, 4));
	a.insert(ft::pair<int, int>(14, 9));
	a.insert(ft::pair<int, int>(5, 9));
	a.insert(ft::pair<int, int>(3, 4));
	a.insert(ft::pair<int, int>(4, 9));
	a.insert(ft::pair<int, int>(8, 9));
	a.insert(ft::pair<int, int>(9, 9));
	a.insert(ft::pair<int, int>(19, 9));

	a.delete_tree_element(a.begin());
	a.delete_tree_element(a.begin());
	ft::Node<ft::pair<const int, int> > *it = a.begin();
	// std::cout<< it->val.first << std::endl;
	while (it != a.end())
	{
		std::cout << "forward:  " << it->val.first << std::endl;
		it = a.move_forward(it);
		// while (true);
	}
	// a.delete_tree_element(a.end());
	ft::Node<ft::pair<const int, int> > *ite = a.end();
	while (ite != a.begin())
	{
		std::cout << "backward: " << ite->val.first << std::endl;
		ite = a.move_backward(ite);
	}
	return 0;
}

// int		main()
// {
// 	std::map<int, int> a;
// 	std::pair<int, int> b(0, 5);
// 	a.insert(std::pair<int, int>(1, 6));
// 	a.insert(std::pair<int, int>(2, 2));
// 	a.insert(std::pair<int, int>(3, 4));
// 	a.insert(std::pair<int, int>(4, 9));
// 	a.insert(std::pair<int, int>(5, 9));
// 	a.insert(std::pair<int, int>(6, 9));
// 	a.insert(std::pair<int, int>(7, 9));
// 	a.insert(std::pair<int, int>(8, 9));
// 	a.insert(std::pair<int, int>(9, 9));
// 	a.insert(std::pair<int, int>(10, 6));
// 	a.insert(std::pair<int, int>(11, 6));
// 	a.insert(std::pair<int, int>(12, 2));
// 	a.insert(std::pair<int, int>(13, 4));
// 	a.insert(std::pair<int, int>(14, 9));
// 	a.insert(std::pair<int, int>(15, 9));
// 	a.insert(std::pair<int, int>(16, 9));
// 	a.insert(std::pair<int, int>(17, 9));
// 	a.insert(std::pair<int, int>(18, 9));
// 	a.insert(std::pair<int, int>(19, 9));
// 	a.insert(b);

// 	std::map<int, int>::iterator it = a.begin();
// 	while (it != a.end())
// 	{
// 		std::cout << "forward:  " << (*it).first << std::endl;
// 		++it;
// 	}
// 	// a.erase(a.end());
// 	std::map<int, int>::iterator ite = a.end();
// 	while (ite != a.begin())
// 	{
// 		std::cout << "backward: " << (*ite).first << std::endl;
// 		--ite;
// 	}
// 	return 0;
// }