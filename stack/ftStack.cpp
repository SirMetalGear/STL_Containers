/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftStack.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:52:25 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/29 00:03:06 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include "stack.hpp"

void empty()
{
	ft::stack<int> mystack;
	int sum(0);

	for (int i = 1; i <= 10; i++)
		mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	std::cout << "total: " << sum << '\n';
}
void pop()
{
	ft::stack<int> mystack;

	for (int i = 0; i < 5; ++i)
		mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

void push()
{
	ft::stack<int> mystack;

	for (int i = 0; i < 5; ++i)
		mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

void size()
{
	ft::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i = 0; i < 5; i++)
		myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
}

void top()
{
	ft::stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

// void	bool_check()
// {

// }

int main()
{
	empty();
	pop();
	push();
	size();
	top();
	std::cout << "TEST FINISHED\n";
	// bool_check();
	// while(1);
	return 0;
}