/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdVector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:42:09 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/18 15:57:59 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include "vector.hpp"

void	testIteratorMine()
{
	std::vector<std::string> a;
	for (int i = 0; i < 10; i++)
		a.push_back("wow");
	std::vector<std::string>::iterator it = a.begin();
	it = 5 + it;
	it = it - 5;
	std::cout << "strange behavior: " << *it << std::endl;
	std::vector<std::string>::iterator it2 = (a.begin() + 5);
	std::cout << "iterator sum: " << (it2 - it) << std::endl;

	it = a.begin();
	it = 5 + it;
	it = it - 5;
	std::cout << "strange behavior: " << *it << std::endl;
	it2 = (a.begin() + 5);
	std::cout << "iterator sum: " << (it2 - it) << std::endl;

	std::vector<std::string>::iterator ite = a.end();
	std::cout << "last iterator points at element: " << *ite << std::endl;
	std::cout << "first element: " << *it << std::endl;
	it++;
	it++;
	std::cout << "second element: " << *it << std::endl;
	std::cout << "WHILE LOOP\n";
	for (int i = 0; i < 10; i++)
		std::cout << "vector element: " << it[i] << std::endl;
	std::cout << "FOR LOOP\n";
	while (it != ite)
		std::cout << "vector element: " << *it++ << std::endl;
}

void	capacityCheck()
{
	std::vector<int> a;
	std::cout << "empty vector capacity: " << a.capacity() << std::endl;
	a.push_back(1);
	std::cout << "vector capacity with one element: " << a.capacity() << std::endl;
	a.push_back(2);
	std::cout << "vector capacity with two elements: " << a.capacity() << std::endl;
	a.push_back(2);
	std::cout << "vector capacity with three elements: " << a.capacity() << std::endl;
	a.push_back(2);
	std::cout << "vector capacity with four elements: " << a.capacity() << std::endl;
	a.push_back(2);
	std::cout << "vector capacity with five elements: " << a.capacity() << std::endl;
	a.push_back(2);
	std::cout << "vector capacity with six elements: " << a.capacity() << std::endl;
	a.push_back(2);
	std::cout << "vector capacity with seven elements: " << a.capacity() << std::endl;

	int wow[5] = {1, 3, 6, 7, 2};
	std::vector<int> a2(wow, wow + 5);
	for (std::vector<int>::iterator it = a2.begin(); it != a2.end(); ++it)
		std::cout << "vector a2 contains: " << *it << std::endl;
	std::cout << "constructor fill vector capacity: " << a2.capacity() << std::endl;

	std::cout << "COPY CHECK\n\n";
	std::vector<int> a2_copy(a2);
	std::cout << "copied a2 capacity: " << a2_copy.capacity() << std::endl;

	std::vector<int> a_copy(a);
	std::cout << "copied a2 capacity: " << a_copy.capacity() << std::endl;
	
}

void	testIteratorBool()
{
	std::vector<int> foo;
	foo.push_back(100);   // three ints with a value of 100
	foo.push_back(100);
	foo.push_back(100);
	std::vector<int> bar;
	bar.push_back(200);
	bar.push_back(200);   // two ints with a value of 200

	std::vector<int>::iterator it = foo.begin();
	std::vector<int>::iterator it2 = bar.begin();

	if (it==it2) std::cout << "foo and bar are equal\n";
	if (it!=it2) std::cout << "foo and bar are not equal\n";
	if (it < it2) std::cout << "foo is less than bar\n";
	if (it> it2) std::cout << "foo is greater than bar\n";
	if (it<=it2) std::cout << "foo is less than or equal to bar\n";
	if (it>=it2) std::cout << "foo is greater than or equal to bar\n";

}

void	testAssignMine()
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}

void	testAt()
{
	std::vector<int> myvector(10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
	myvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
	std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
}

void	testConstructMine()
{
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(), second.end());  // iterating through second
	std::vector<int> fourth;
	fourth = third;
	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "The contents of fourth are:";
	for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	testClear()
{
	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	testErase()
{
	std::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++)
		myvector.push_back(i);

	// erase the 6th element
	std::cout << "iterator pos at element: " << *myvector.erase (myvector.begin()+5) << std::endl;

	std::cout << "myvector contains after erasing 6:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	// erase the first 3 elements:
	std::cout << "iterator pos at element: " << *myvector.erase (myvector.begin(),myvector.end()) << std::endl;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}


void	testFrontMine()
{
	std::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

void	testAllocMine()
{
	std::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void iterator_test(void)
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i + 1);
	std::cout << "capacity: " << vec.capacity() << std::endl;
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator it2 = it;
	// std::vector<int>::iterator ite = vec.end();
	it2 = it + 2;
	std::cout << *it2 << std::endl;
	it += 3;
	std::cout << *it << std::endl;
	// it -= 2;
	// std::cout << *it << std::endl;
	std::cout << it[9] << std::endl;
	// std::cout << it.operator->() << std::endl;
	// while (it != ite)
	// {
	//  std::cout << *it << std::endl;
	//  ++it;
	// }
}

void	testInsertMine()
{
	std::vector<int> myvector(5, 100);
	std::vector<int>::iterator it = myvector.begin();

	it = myvector.begin();
	std::cout << "Capacity before insert: " << myvector.capacity() << std::endl;
	it = myvector.insert ( it , 200 );

	std::cout << "After Insert 1 elem:";
	for (it=myvector.begin(); it<myvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';

	// std::cout << "it pos after insert: " << *it << std::endl;
	myvector.insert (myvector.begin(), 50, 42);
	for (it=myvector.begin(); it<myvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';
	myvector.insert (it, 50, 42);
	std::cout << "After Insert 50 elems:";
	for (it=myvector.begin(); it<myvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';

	myvector.insert (it,2,300);

	std::cout << "After Insert 2 elems with 300 val:";
	for (it=myvector.begin(); it<myvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	maxSizeTestMine()
{
	std::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}

void	testPopBackMine()
{
	std::vector<int> myvector(5);
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
	sum+=myvector.back();
	myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
}

void	testOperatorMine()
{
	std::vector<int> myvector (10);   // 10 zero-initialized elements

	std::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	testReserveMine()
{
	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void	testResizeMine()
{
	std::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	testSizeMine()
{
	std::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}

void	testSwapMine()
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200

	// foo.swap(bar);
	std::swap(foo, bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
	std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
	std::cout << ' ' << bar[i];
	std::cout << '\n';
}

void	testConstIteratorMine()
{
	std::vector<int> a(5, 100);
	std::vector<int>::const_iterator it = a.begin();
	std::vector<int>::const_iterator it2;
	it2 = it;
	while (it2 != a.end())
		std::cout << *it2++ << std::endl;
}

void	testRevIteratorMine()
{
	std::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	std::cout << "rev iterator at begin: " << *rit << std::endl;
	std::cout << "rev iterator at end: " << *myvector.rend() << std::endl;
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i + 1);
	std::cout << "capacity: " << vec.capacity() << std::endl;
	std::vector<int>::reverse_iterator it = vec.rbegin();
	std::vector<int>::reverse_iterator it2 = vec.rbegin();
	// std::vector<int>::reverse_iterator ite = vec.end();
	it2 = it + 2;
	std::cout << *it2 << std::endl;
	it += 3;
	std::cout << *it << std::endl;
	it -= 2;
	std::cout << *it << std::endl;
	std::cout << it[9] << std::endl;
	std::cout << vec.operator[](9) << std::endl;
}

void	testConstRevIteratorMine()
{
	std::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	std::vector<int>::const_reverse_iterator rit = myvector.rbegin();
	std::cout << "rev iterator at begin: " << *rit << std::endl;
	std::cout << "rev iterator at end: " << *myvector.rend() << std::endl;
	for (; rit!= myvector.rend(); ++rit)
	{
		myvector.operator[](i) = i;
		i++;
	}

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i + 1);
	std::cout << "capacity: " << vec.capacity() << std::endl;
	std::vector<int>::const_reverse_iterator it = vec.rbegin();
	std::vector<int>::const_reverse_iterator it2 = vec.rbegin();
	// std::vector<int>::const_reverse_iterator ite = vec.end();
	it2 = it + 2;
	std::cout << *it2 << std::endl;
	it += 3;
	std::cout << *it << std::endl;
	it -= 2;
	std::cout << *it << std::endl;
	std::cout << it[9] << std::endl;
	std::cout << vec.operator[](9) << std::endl;
	std::cout << "MINE PASSED INSIDE FUNC\n";
}

void const_iterator_test(void)
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i + 1);
	std::cout << "capacity: " << vec.capacity() << std::endl;
	std::vector<int>::const_iterator it = vec.begin();
	std::vector<int>::const_iterator it2 = it;
	// std::vector<int>::const_iterator ite = vec.end();
	it2 = it + 2;
	std::cout << *it2 << std::endl;
	it += 3;
	std::cout << *it << std::endl;
	// it -= 2;
	// std::cout << *it << std::endl;
	// std::cout << it.operator->() << std::endl;
	it = vec.begin();
	while (it != vec.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	testBoolMine()
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

int	main()
{
	testConstructMine();
	iterator_test();
	testIteratorBool();
	testIteratorMine();
	capacityCheck();
	testAssignMine();
	testAt();
	testClear();
	testErase();
	testFrontMine();
	testAllocMine();
	testInsertMine();
	maxSizeTestMine();
	testPopBackMine();
	testOperatorMine();
	testReserveMine();
	testResizeMine();
	testSizeMine();
	testSwapMine();
	testConstIteratorMine();
	std::cout << "PASSED1_______\n";
	testRevIteratorMine();
	std::cout << "PASSED2_______\n";
	testConstRevIteratorMine();
	std::cout << "PASSED3_______\n";
	const_iterator_test();
	std::cout << "PASSED4_______\n";
	testBoolMine();
	std::cout << "TEST IS FINISHED!!\n";
	// while(1);
	return (0);
}
