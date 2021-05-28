/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdMap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:04:49 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/28 20:44:21 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <map>
#include <iostream>
#include "map.hpp"


void	insert()
{
	std::map<char, int> mymap;

	// first insert function version (single parameter):
	mymap.insert(std::pair<char, int>('a', 100));
	mymap.insert(std::pair<char, int>('z', 200));

	std::pair<std::map<char, int>::iterator, bool> ret;
	ret = mymap.insert(std::pair<char, int>('z', 500));
	if (ret.second == false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	std::map<char, int>::iterator it = mymap.begin();
	mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
	mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting

	// third insert function version (range insertion):
	std::map<char, int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));

	// showing contents:
	// mymap.clear();
	mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
	mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting
	std::cout << "mymap contains:\n";
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	operatorSquare()
{
	std::map<char, std::string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}

void	clear()
{
	std::map<char, int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;
	std::cout << "mymap size: " << mymap.size() << std::endl;
	std::cout << "mymap contains:\n";
	for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a'] = 1101;
	mymap['b'] = 2202;
	std::cout << "mymap size: " << mymap.size() << std::endl;
	std::cout << "mymap contains:\n";
	for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	count()
{
	std::map<char, int> mymap;
	char c;

	mymap['a'] = 101;
	mymap['c'] = 202;
	mymap['f'] = 303;

	for (c = 'a'; c < 'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c) > 0)
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}
}

void	empty()
{
	std::map<char, int> mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
}

void	erase()
{
	std::map<char, int> mymap;
	std::map<char, int>::iterator it;

	// insert some values:
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	it = mymap.find('b');
	mymap.erase(it); // erasing by iterator

	mymap.erase('c'); // erasing by key

	it = mymap.find('e');
	mymap.erase(it, mymap.end()); // erasing by range

	// show content:
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	find()
{
	std::map<char, int> mymap;
	std::map<char, int>::iterator it;

	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;
	mymap['d'] = 200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase(it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}

void	equal_range()
{
	std::map<char, int> mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;

	std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret;
	ret = mymap.equal_range('c');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void	get_allocator()
{
	int psize;
	std::map<char, int> mymap;
	std::pair<const char, int> *p;

	// allocate an array of 5 elements using mymap's allocator:
	p = mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(std::map<char, int>::value_type) * 5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p, 5);
}

void	key_comp()
{
	std::map<char, int> mymap;

	std::map<char, int>::key_compare mycomp = mymap.key_comp();

	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;

	std::cout << "mymap contains:\n";

	char highest = 'c'; // key value of last element

	std::map<char, int>::iterator it = mymap.begin();
	do
	{
		std::cout << it->first << " => " << it->second << '\n';
	} while (mycomp((*it++).first, highest));

	std::cout << '\n';
}

void	lower_bound()
{
	std::map<char, int> mymap;
	std::map<char, int>::iterator itlow, itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow, itup); // erases [itlow,itup)

	// print content:
	for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	stress_test()
{
	std::map<int, int> mymap;
	for (int i = 0; i < 10000000; ++i)
	{
		mymap.insert(std::pair<int, int>(i, i + 10));
	}
	mymap.erase(--mymap.begin(), mymap.end());
	// for (std::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';
}

void	max_size()
{
	int i;
	std::map<int, int> mymap;

	if (mymap.max_size() > 1000)
	{
		for (i = 0; i < 1000; i++)
			mymap[i] = 0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else
		std::cout << "The map could not hold 1000 elements.\n";
}

void	operatorEqual()
{
	std::map<char, int> first;
	std::map<char, int> second;

	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;

	second = first;				   // second now contains 3 ints
	first = std::map<char, int>(); // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
}

void	size()
{
	std::map<char, int> mymap;
	mymap['a'] = 101;
	mymap['b'] = 202;
	mymap['c'] = 302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
}

void	swap()
{
	std::map<char, int> foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (std::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (std::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	value_comp()
{
	std::map<char, int> mymap;

	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;

	std::cout << "mymap contains:\n";

	std::pair<char, int> highest = *--mymap.end(); // last element

	std::map<char, int>::iterator it = mymap.begin();
	do
	{
		std::cout << it->first << " => " << it->second << '\n';
	} while (mymap.value_comp()(*it++, highest));
}

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
	bool operator()(const char &lhs, const char &rhs) const
	{
		return lhs > rhs;
	}
};

void	construct()
{
	std::map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	std::map<char, int> second(first.begin(), first.end());

	std::map<char, int> third(second);

	std::map<char, int, classcomp> fourth; // class as Compare
	fourth['a'] = 10;
	fourth['b'] = 30;
	fourth['c'] = 50;
	fourth['d'] = 70;
	bool (*fn_pt)(char, char) = fncomp;
	std::map<char, int, bool (*)(char, char)> fifth(fn_pt); // function pointer as Compare
	fifth['a'] = 10;
	fifth['b'] = 20;
	fifth['c'] = 30;
	fifth['d'] = 40;
	fifth['e'] = 50;
	fifth['f'] = 60;
	fifth['g'] = 70;
	fifth['h'] = 80;
	fifth['j'] = 90;
	fifth['k'] = 100;
	fifth['l'] = 110;
	fifth['q'] = 120;
	fifth['w'] = 130;
	fifth['e'] = 140;
	std::cout << "first contains: \n";
	for (std::map<char, int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "second contains: \n";
	for (std::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "third contains: \n";
	for (std::map<char, int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "fourth contains: \n";
	for (std::map<char, int, classcomp>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "fifth contains: \n";
	for (std::map<char, int, bool (*)(char, char)>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "asd\n";
}

void	reverse_iterator()
{
	std::map<char, int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	std::map<char, int>::reverse_iterator rit = mymap.rbegin();
	for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
}

int		main()
{
	insert();
	operatorSquare();
	clear();
	count();
	empty();
	erase();
	find();
	equal_range();
	get_allocator();
	key_comp();
	lower_bound();
	// stress_test();
	max_size();
	operatorEqual();
	size();
	swap();
	value_comp();
	construct();
	reverse_iterator();
	std::cout << "TEST IS FINISHED\n";
	// while (1);
	return 0;
}