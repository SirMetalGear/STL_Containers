/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftList.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:12:54 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/28 23:32:01 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "list.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

void	example()
{
	ft::list<int> a;
	std::cout << "BEGIN: " << *a.begin() << std::endl;
	for(int i = 0; i < 10; i++)
		a.push_back(i);
	ft::list<int> b;
	ft::list<int>::iterator start = a.begin();
	ft::list<int>::iterator end = a.end();
	b.assign(start, end);
	b.assign(10, 35);
	b.assign(start, end);
	ft::list<int>::const_iterator start2 = b.begin();
	std::cout << "const iterator to begin: " << *start2 << std::endl;
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
	start2 = a.begin();
	end2 = a.end();
	while (start2 != end2)
	{
		std::cout << *start2 << std::endl;
		start2++;
	}
	ft::list<int>::iterator wow = --b.end();
	std::cout << "iterator pos after erase: " << *b.erase(wow) << std::endl;
	wow = --b.end();
	std::cout << "iterator pos after erase: " << *b.erase(wow) << std::endl;
	std::cout << "iterator pos after erase: " << *b.erase(b.begin(), b.end()) << std::endl;
}

void	testIterators()
{
	ft::list<int> a;

	a.push_back(5);
	a.push_back(10);
	a.push_back(15);
	a.push_back(20);
	a.push_back(25);
	ft::list<int>::iterator	it = a.begin();
	ft::list<int>::iterator	ite = a.end();
	// --it;
	std::cout << "PRE INCREMENT AND PRE DECREMENT CHECK\n";
	while (it != ite)
	{
		std::cout << "INSIDE WHILE LOOP element of list: " << *it++ << std::endl;
	}
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

	for (int i = 0; i < 500; i++)
		mylist.push_back(i);

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

template <typename T>
void	print(T &mylist, int flag = 0)
{
	if (flag == 0)
		std::cout << "mine contains:";
	else
		std::cout << "real contains:";
	for (typename T::iterator it = mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "rev contains: ";
	for (typename T::reverse_iterator it = mylist.rbegin(); it!=mylist.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << ' ' << *mylist.begin();
	std::cout << '\n';
}

void	testMergeSort(int *start, int *end)
{
	ft::list<int> mylist;
	mylist.insert(mylist.end(), start, end);
	mylist.sort();
	print(mylist);
}

void	superSortTest()
{
	int	size = 100000;
	int *val = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			val[i] =  i * 2;
		else
			val[i] =  i / 2;
	}
	std::cout << "Val is created! Size of val: " << size << std::endl;

	testMergeSort(val, val + size);

	delete [] val;
}

void	testSpliceMine()
{
	ft::list<int> mylist1;
	ft::list<int> mylist2;
	ft::list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i=1; i<=3; ++i)
		mylist2.push_back(i*10);   // mylist2: 10 20 30

	it = mylist1.begin();
	++it;                         // points to 2

	mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)

	mylist2.splice (mylist2.begin(),mylist1, it);

	it = mylist1.begin();
	++it;
	++it;
	++it;
	mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
	std::cout << "mine contains:";
	for (it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "mylist2 contains:";
	for (it=mylist2.begin(); it!=mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	testSwapMine()
{
	ft::list<int> first;
	first.assign (3,100);   // three ints with a value of 100
	ft::list<int> second;
	second.assign(5,200);  // five ints with a value of 200

	first.swap(second);
	// ft::swap(first, second);

	std::cout << "first contains:";
	for (ft::list<int>::iterator it=first.begin(); it!=first.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (ft::list<int>::iterator it=second.begin(); it!=second.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}

// a binary predicate implemented as a class:
struct is_near
{
	bool operator()(double first, double second)
	{
		return (fabs(first - second) < 5.0);
	}
};

void	testUniqueMine()
{
	double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14,
						  12.77, 73.35, 72.25, 15.3, 72.25};
	ft::list<double> mylist;
	mylist.assign(mydoubles, mydoubles + 10);

	mylist.sort(); //  2.72,  3.14, 12.15, 12.77, 12.77,
				   // 15.3,  72.25, 72.25, 73.0,  73.35

	mylist.unique(); //  2.72,  3.14, 12.15, 12.77
					 // 15.3,  72.25, 73.0,  73.35

	mylist.unique(same_integral_part); //  2.72,  3.14, 12.15
									//    15.3,  72.25, 73.0

	mylist.unique(is_near()); //  2.72, 12.15, 72.25

	print<ft::list<double> >(mylist);

}

void	testNonMemberFuncs()
{
	ft::list<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);

	ft::list<int> b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	
	ft::list<int> c;
	c.push_back(30);
	c.push_back(20);
	c.push_back(10);
	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";

}

void	testConstructMine()
{
	ft::list<int> first;                                // empty list of ints
	ft::list<int> second (4,100);                       // four ints with value 100
	ft::list<int> third (second.begin(),second.end());  // iterating through second
	ft::list<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	ft::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth MINE are: ";
	for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << *it << ' ';

	std::cout << '\n';
}

void		testRevIteratorMine()
{
	ft::list<int> mylist;
	for (int i=1; i<=5; ++i) mylist.push_back(i);

	std::cout << "mylist backwards:";
	for (ft::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
	std::cout << ' ' << *rit;

	std::cout << '\n';
}

void	testEqualOperator()
{
	ft::list<int> first (3, 100);      // list of 3 zero-initialized ints
	ft::list<int> second (5, 200);     // list of 5 zero-initialized ints

	second = first;
	first = ft::list<int>();

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	for (ft::list<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << "elem of first: " << *it << std::endl;
	for (ft::list<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << "elem of second: " << *it << std::endl;
}

void	testConstIterator()
{
	ft::list<int> a(5, 100);
	ft::list<int>::const_iterator it = a.begin();
	ft::list<int>::const_iterator it2;
	it2 = it;
	while (it2 != a.end())
		std::cout << *it2++ << std::endl;
}

int	main()
{
	srand(time(NULL));
	testConstructMine();
	example();
	testIterators();
	testRevIteratorMine();
	testFuncs();
	testFront();
	testAllocator();
	testInsert();
	test_clearInsert();
	testMergeMine();
	testMerge2mine();
	testPop_back();
	testPop_front();
	testPush_back();
	testPush_front();
	testRemove();
	testRemove_if();
	testResize();
	testReverse();
	testSort();
	superSortTest();
	testSpliceMine();
	testSwapMine();
	testNonMemberFuncs();
	testUniqueMine();
	testEqualOperator();
	testConstIterator();
	std::string		b[5] = {"1", "2", "3", "6", "7"};
	ft::list<std::string> a;
	a.insert(a.end(), b, b + 3);
	for (ft::list<std::string>::iterator item = a.begin(); item != a.end(); ++item) {
		std::cout << *item << std::endl;
	}
	std::cout << "TEST FINISHED!\n";
	// while (1);
	return (0);
}
