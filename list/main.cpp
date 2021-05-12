/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:12:54 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/12 12:46:40 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "list.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

void	example()
{
	std::list<int> a;
	std::cout << "BEGIN: " << *a.begin() << std::endl;
	for(int i = 0; i < 10; i++)
		a.push_back(i);
	std::list<int> b;
	std::list<int>::iterator start = a.begin();
	std::list<int>::iterator end = a.end();
	b.assign(start, end);
	b.assign(10, 35);
	b.assign(start, end);
	std::list<int>::const_iterator start2 = b.begin();
	std::cout << "const iterator to begin: " << *start2 << std::endl;
	////// ATTEMPT TO CHANGE IS FAILING //////
	// *start2 = 10;
	std::list<int>::iterator end2 = b.end();
	while (start2 != end2)
	{
		std::cout << *start2 << std::endl;
		start2++;
	}
	std::cout << "BACK: " << b.back() << std::endl;
	if (b.empty())
		std::cout << "LIST IS EMPTY!\n";
	else
		std::cout << "LIST IS NOT EMPTY!\n";
	start2 = a.begin();
	end2 = a.end();
	while (start2 != end2)
	{
		std::cout << *start2 << std::endl;
		start2++;
	}
	std::list<int>::iterator wow = --b.end();
	std::cout << "iterator pos after erase: " << *b.erase(wow) << std::endl;
	wow = --b.end();
	std::cout << "iterator pos after erase: " << *b.erase(wow) << std::endl;
	std::cout << "iterator pos after erase: " << *b.erase(b.begin(), b.end()) << std::endl;
}

void	testIterators()
{
	ft::list<int> a;

	a.push_back(5);
	// a.push_back(10);
	// a.push_back(15);
	// a.push_back(20);
	// a.push_back(25);
	ft::list<int>::iterator	it = a.begin();
	ft::list<int>::iterator	ite = a.end();
	--it;
	std::cout << "PRE INCREMENT AND PRE DECREMENT CHECK\n";
	while (it != ite)
	{
		std::cout << "INSIDE WHILE LOOP element of list: " << *it << std::endl;
		++it;
	}
}

void	testFuncsReal()
{
	std::list<int> a;
	std::cout << "BEGIN: " << *a.begin() << std::endl;
	for(int i = 0; i < 10; i++)
		a.push_back(i);
	std::list<int>::iterator start = a.begin();
	std::list<int>::iterator end = a.end();
	std::list<int> b;
	b.assign(start, end);
	b.assign(10, 35);
	b.assign(start, end);
	std::list<int>::iterator start2 = b.begin();
	std::cout << "const iterator to begin: " << *start2 << std::endl;
	////// ATTEMPT TO CHANGE IS FAILING //////
	// *start2 = 10;
	std::list<int>::iterator end2 = b.end();
	while (start2 != end2)
	{
		std::cout << *start2 << std::endl;
		start2++;
	}
	std::cout << "BACK: " << b.back() << std::endl;
	if (b.empty())
		std::cout << "LIST IS EMPTY!\n";
	else
		std::cout << "LIST IS NOT EMPTY!\n";
	b.erase(b.begin(), b.end());
}

void	testFuncs()
{
	ft::list<int> a;
	std::cout << "BEGIN: " << *a.begin() << std::endl;
	for(int i = 0; i < 10; i++)
		a.push_back(i);
	ft::list<int>::iterator start = a.begin();
	ft::list<int>::iterator end = a.end();
	ft::list<int> b;
	b.assign(start, end);
	std::cout << "SIZE AFTER ASSIGN1: " << b.size() << std::endl;
	b.assign(10, 35);
	std::cout << "SIZE AFTER ASSIGN2: " << b.size() << std::endl;
	b.assign(start, end);
	std::cout << "SIZE AFTER ASSIGN3: " << b.size() << std::endl;
	ft::list<int>::iterator start2 = b.begin();
	std::cout << "iterator to begin: " << *start2 << std::endl;
	ft::list<int>::iterator end2 = b.end();
	while (start2 != end2)
	{
		std::cout << *start2 << std::endl;
		start2++;
	}
	std::cout << "BACK: " << b.back() << std::endl;
	if (b.empty())
		std::cout << "LIST IS EMPTY!\n";
	else
		std::cout << "LIST IS NOT EMPTY!\n";
	std::cout << "SIZE BEFORE ERASE: " << b.size() << std::endl;
	b.erase(b.begin(), b.end());
}

void	testFront()
{
	ft::list<int> mylist;
	mylist.push_back(77);
	mylist.push_back(22);
	// now front equals 77, and back 22
	mylist.front() -= mylist.back();
	std::cout << "mylist.front() is now " << mylist.front() << '\n';
}

void	testAllocator()
{
	ft::list<int> mylist;
	int * p;

	// allocate an array of 5 elements using mylist's allocator:
	p=mylist.get_allocator().allocate(5);

	// assign some values to array
	for (int i=0; i<5; ++i) p[i]=i;

	std::cout << "The allocated array contains:";
	for (int i=0; i<5; ++i) std::cout << ' ' << p[i];
	std::cout << '\n';

	mylist.get_allocator().deallocate(p,5);
}

void	testInsertReal()
{
	std::list<int> mylist;
	std::list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; ++i)
		mylist.push_back(i); // 1 2 3 4 5

	it = mylist.begin();
	++it;       // it points now to number 2           ^
	std::cout << "iterator pos: " << *it << std::endl;

	it = mylist.insert (it, 10);
	std::cout << "iterator after insert: " << *it << std::endl;
	it = mylist.begin();
	// ++it;
	// ++it;
	// ++it;
	// std::cout << "iterator after ++: " << *it << std::endl;
	mylist.insert (it,2,20);
	// --it;
	std::vector<int> myvector;
	myvector.push_back(30);
	myvector.push_back(30);
	myvector.push_back(20);
	std::cout << "size of iterator: " <<  sizeof(it) << std::endl;
	if (sizeof(it) == sizeof(int) || sizeof(it) == sizeof(unsigned int))
		std::cout << "SAME SIZE!\n";
  	mylist.insert(it,myvector.begin(),myvector.end());
	std::list<int>::iterator start = mylist.begin();
	std::list<int>::iterator end = mylist.end();
	std::cout << "size of iterator start: " <<  sizeof(start) << std::endl;
	if (sizeof(start) == sizeof(int) || sizeof(start) == sizeof(unsigned int))
		std::cout << "START ITERATOR SAME SIZE!\n";
	std::cout << "SIZE: " << mylist.size() << std::endl;
	int a[8] = {1, 2, 3, 4, 5};
	mylist.insert(mylist.end(), a, a + 6);
	while (start != end)
	{
		std::cout << *start << std::endl;
		start++;
	}
}

void	testInsert()
{
	ft::list<int> mylist;
	ft::list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; ++i)
		mylist.push_back(i); // 1 2 3 4 5

	it = mylist.begin();
	++it;       // it points now to number 2           ^
	std::cout << "iterator pos: " << *it << std::endl;

	it = mylist.insert (it, 10);
	std::cout << "iterator after insert: " << *it << std::endl;
	it = mylist.begin();
	// ++it;
	// ++it;
	// ++it;
	// std::cout << "iterator after ++: " << *it << std::endl;
	mylist.insert (it,2,20);
	// --it;
	std::vector<int> myvector;
	myvector.push_back(30);
	myvector.push_back(30);
	myvector.push_back(20);
	std::cout << "size of iterator: " <<  sizeof(it) << std::endl;
	if (sizeof(it) == sizeof(int) || sizeof(it) == sizeof(unsigned int))
		std::cout << "SAME SIZE!\n";
  	mylist.insert(it,myvector.begin(),myvector.end());
	ft::list<int>::iterator start = mylist.begin();
	ft::list<int>::iterator end = mylist.end();
	std::cout << "size of iterator start: " <<  sizeof(start) << std::endl;
	if (sizeof(start) == sizeof(int) || sizeof(start) == sizeof(unsigned int))
		std::cout << "START ITERATOR SAME SIZE!\n";
	std::cout << "SIZE: " << mylist.size() << std::endl;
	int a[8] = {1, 2, 3, 4, 5};
	mylist.insert(mylist.end(), a, a + 6);
	while (start != end)
	{
		std::cout << *start << std::endl;
		start++;
	}
}

void	test_clearInsert()
{
	ft::list<int> mylist;
	ft::list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

	it = mylist.begin();
	++it;       // it points now to number 2           ^

	mylist.insert (it,10);                        // 1 10 2 3 4 5

	// "it" still points to number 2                      ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

	--it;       // it points now to the second 20            ^

	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
													// 1 10 20 30 30 20 2 3 4 5
													//               ^
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

bool mycomparison (double first, double second){
	return ( int(first)<int(second) );
}

void	testMerge()
{
	std::list<double> first;
	std::list<double> second;
	first.push_back (2.2);
	// first.push_back (3.1);
	// first.push_back (4.1);
	// first.push_back (2.9);
	second.push_back (1.4);
	second.push_back (1.6);
	second.push_back (6.6);
	second.push_back (8.6);
	second.push_back (1.5);
	second.push_back (5.6);
	second.push_back (7.6);
	second.push_back (9.6);
	
	first.merge(second);
	second.push_back (5.6);
	first.merge(second,mycomparison);
	std::cout << "real contains:";
	for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::list<double>::iterator it = first.end();
	std::list<double>::iterator ite = first.begin();
	std::cout << "\nrev. contains:";
	while (it != ite)
	{
		--it;
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
}

void	testMergeMine()
{
	ft::list<double> first;
	ft::list<double> second;
	first.push_back (2.2);
	// first.push_back (3.1);
	// first.push_back (4.1);
	// first.push_back (2.9);
	second.push_back (1.4);
	second.push_back (1.6);
	second.push_back (6.6);
	second.push_back (8.6);
	second.push_back (1.5);
	second.push_back (5.6);
	second.push_back (7.6);
	second.push_back (9.6);

	first.merge(second);
	second.push_back (5.6);
	first.merge(second,mycomparison);
	std::cout << "mine contains:";
	for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	ft::list<double>::iterator it = first.end();
	ft::list<double>::iterator ite = first.begin();
	std::cout << "\nrev. contains:";
	while (it != ite)
	{
		--it;
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
}


void	testMerge2()
{
	std::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	// first.sort();
	// second.sort();

	first.merge(second);

	// (second is now empty)

	second.push_back (2.1);

	first.merge(second,mycomparison);

	std::cout << "real contains:";
	for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	testMerge2mine()
{
	ft::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	// first.sort();
	// second.sort();

	first.merge(second);

	// (second is now empty)

	second.push_back (2.1);

	first.merge(second,mycomparison);

	std::cout << "mine contains:";
	for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	testPop_back()
{
	ft::list<int> mylist;
	int sum (0);
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	while (!mylist.empty())
	{
		sum+=mylist.back();
		mylist.pop_back();
	}

	std::cout << "The elements of mylist summed " << sum << '\n';
}

void	testPop_front()
{
	ft::list<int> mylist;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	std::cout << "Popping out the elements in mylist:";
	while (!mylist.empty())
	{
	std::cout << ' ' << mylist.front();
	mylist.pop_front();
	}

	std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';
}

void	testPush_back()
{
	ft::list<int> mylist;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
	std::cin >> myint;
	mylist.push_back (myint);
	} while (myint);

	std::cout << "mylist stores " << mylist.size() << " numbers.\n";
	for (ft::list<int>::iterator item = mylist.begin(); item != mylist.end(); ++item) {
		std::cout << *item << std::endl; }
}

void	testPush_front()
{
	ft::list<int> mylist;
	mylist.assign(2,100);         // two ints with a value of 100
	mylist.push_front (200);
	mylist.push_front (300);

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
	std::cout << ' ' << *it;

	std::cout << '\n';
}

void	testRemove() 
{
	int myints[]= {17,89,7,14};
	ft::list<int> mylist;
	mylist.assign(myints,myints+4);

	mylist.remove(89);

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}
//////////// TO DO : REVERSE ITERATOR, MERGE, RBEGIN, REND

bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

void	testRemove_if()
{
	int myints[]= {15,36,7,17,20,39,4,1};
	ft::list<int> mylist;
	mylist.assign(myints,myints+8);            // 15 36 7 17 20 39 4 1

	mylist.remove_if (single_digit);           // 15 36 17 20 39

	mylist.remove_if (is_odd());               // 36 20

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	testResize()
{
	ft::list<int> mylist;

	// set some initial content:
	for (int i=1; i<10; ++i)
		mylist.push_back(i);

	mylist.resize(5);
	mylist.resize(8,100);
	mylist.resize(12);

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
	std::cout << ' ' << *it;

	std::cout << '\n';
}

void	testReverse()
{
	ft::list<int> mylist;

	for (int i=1; i<10; ++i) mylist.push_back(i);

	mylist.reverse();

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
	std::cout << ' ' << *it;

	std::cout << '\n';
}

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

void	testSort()
{
	ft::list<std::string> mylist;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");

	mylist.sort();
	std::cout << "mine contains:";
	for (ft::list<std::string>::iterator it = mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::list<int> mylist2;
	mylist2.push_back (1);
	mylist2.push_back (3);
	mylist2.push_back (2);

	mylist2.sort();
	std::cout << "mine contains:";
	for (ft::list<int>::iterator it2 = mylist2.begin(); it2 != mylist2.end(); ++it2)
		std::cout << ' ' << *it2;
	std::cout << '\n';

	mylist.sort(compare_nocase);

	std::cout << "mine contains:";
	for (ft::list<int>::iterator it2 = mylist2.begin(); it2 != mylist2.end(); ++it2)
		std::cout << ' ' << *it2;
	std::cout << '\n';
}

void	testSortReal()
{
	std::list<std::string> mylist;
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("Three");

	mylist.sort();
	std::cout << "real contains:";
	for (std::list<std::string>::iterator it = mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::list<int> mylist2;
	mylist2.push_back (1);
	mylist2.push_back (3);
	mylist2.push_back (2);

	mylist2.sort();
	std::cout << "real contains:";
	for (std::list<int>::iterator it2 = mylist2.begin(); it2 != mylist2.end(); ++it2)
		std::cout << ' ' << *it2;
	std::cout << '\n';

	mylist.sort(compare_nocase);

	std::cout << "real contains:";
	for (std::list<int>::iterator it2 = mylist2.begin(); it2 != mylist2.end(); ++it2)
		std::cout << ' ' << *it2;
	std::cout << '\n';
}

int	main()
{
	// example();
	// testIterators();
	// testFuncsReal();
	// std::cout << "MINE!\n";
	// testFuncs();
	// std::cout << "AFTER FUNC TEST!\n";
	// testFront();
	// testAllocator();
	// testInsertReal();
	// testInsert();
	// test_clearInsert();
	// testMerge();
	// testMergeMine();
	// testMerge2();
	// testMerge2mine();
	// testPop_back();
	// testPop_front();
	// testPush_back();
	// testPush_front();
	// testRemove();
	// testRemove_if();
	// testResize();
	// testReverse();
	testSortReal();
	testSort();
	// std::string		b[5] = {"1", "2", "3", "6", "7"};
	// ft::list<std::string> a;
	// a.insert(a.end(), b, b + 3);
	// for (ft::list<std::string>::iterator item = a.begin(); item != a.end(); ++item) {
	// 	std::cout << *item << std::endl;
	// }
	std::cout << "TEST FINISHED!\nNow in Loop\n";
	while(1);
	return (0);
}
