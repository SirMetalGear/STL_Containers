/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdQueue.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:52:25 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/29 00:28:54 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <queue>
#include "queue.hpp"

void empty()
{
	std::queue<int> myqueue;
	int sum(0);

	for (int i = 1; i <= 10; i++)
		myqueue.push(i);

	while (!myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}

	std::cout << "total: " << sum << '\n';
}
void pop()
{
	std::queue<int> myqueue;

	for (int i = 0; i < 20; i++)
		myqueue.push(i);

	std::cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
		std::cout << ' ' << myqueue.front();
		myqueue.pop();
	}
	std::cout << '\n';
}

void push()
{
	std::queue<int> myqueue;
	
	for (int i = 0; i < 20; i++)
		myqueue.push(i);

	std::cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
		std::cout << ' ' << myqueue.front();
		myqueue.pop();
	}
	std::cout << '\n';
}

void size()
{
	std::queue<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i = 0; i < 5; i++)
		myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
}

void back()
{
	std::queue<int> myqueue;

	myqueue.push(12);
	myqueue.push(75); // this is now the back

	myqueue.back() -= myqueue.front();

	std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
}

void front()
{
	std::queue<int> myqueue;

	myqueue.push(77);
	myqueue.push(16);

	myqueue.front() -= myqueue.back(); // 77-16=61

	std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
}

int main()
{
	empty();
	pop();
	push();
	size();
	back();
	std::cout << "TEST FINISHED\n";
	// while(1);
	return 0;
}