/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftVector.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:21:15 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/28 23:08:17 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include "vector.hpp"

void	testIteratorMine()
{
	ft::vector<std::string> a;
	for (int i = 0; i < 10; i++)
		a.push_back("wow");
	ft::vector<std::string>::iterator it = a.begin();
	it = 5 + it;
	it = it - 5;
	std::cout << "strange behavior: " << *it << std::endl;
	ft::vector<std::string>::iterator it2 = (a.begin() + 5);
	std::cout << "iterator sum: " << (it2 - it) << std::endl;

	it = a.begin();
	it = 5 + it;
	it = it - 5;
	std::cout << "strange behavior: " << *it << std::endl;
	it2 = (a.begin() + 5);
	std::cout << "iterator sum: " << (it2 - it) << std::endl;

	ft::vector<std::string>::iterator ite = a.end();
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
	ft::vector<int> a;
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
	ft::vector<int> a2(wow, wow + 5);
	for (ft::vector<int>::iterator it = a2.begin(); it != a2.end(); ++it)
		std::cout << "vector a2 contains: " << *it << std::endl;
	std::cout << "constructor fill vector capacity: " << a2.capacity() << std::endl;

	std::cout << "COPY CHECK\n\n";
	ft::vector<int> a2_copy(a2);
	std::cout << "copied a2 capacity: " << a2_copy.capacity() << std::endl;

	ft::vector<int> a_copy(a);
	std::cout << "copied a2 capacity: " << a_copy.capacity() << std::endl;
	
}

void	testIteratorBool()
{
	ft::vector<int> foo;
	foo.push_back(100);   // three ints with a value of 100
	foo.push_back(100);
	foo.push_back(100);
	ft::vector<int> bar;
	bar.push_back(200);
	bar.push_back(200);   // two ints with a value of 200

	ft::vector<int>::iterator it = foo.begin();
	ft::vector<int>::iterator it2 = bar.begin();

	if (it==it2) std::cout << "foo and bar are equal\n";
	if (it!=it2) std::cout << "foo and bar are not equal\n";
	if (it < it2) std::cout << "foo is less than bar\n";
	if (it> it2) std::cout << "foo is greater than bar\n";
	if (it<=it2) std::cout << "foo is less than or equal to bar\n";
	if (it>=it2) std::cout << "foo is greater than or equal to bar\n";

}

void	testAssignMine()
{
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator it;
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
	ft::vector<int> myvector(10);   // 10 zero-initialized ints

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
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4,100);                       // four ints with value 100
	ft::vector<int> third (second.begin(), second.end());  // iterating through second
	ft::vector<int> fourth;
	fourth = third;
	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "The contents of fourth are:";
	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	testClear()
{
	ft::vector<int> myvector;
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
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++)
		myvector.push_back(i);

	// erase the 6th element
	std::cout << "iterator pos at element1: " << *myvector.erase (myvector.begin()+5) << std::endl;

	std::cout << "myvector contains after erasing 6:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	// erase the first 3 elements:
	std::cout << "iterator pos at element2: " << *myvector.erase (myvector.begin(),myvector.end()) << std::endl;

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}


void	testFrontMine()
{
	ft::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

void	testAllocMine()
{
	ft::vector<int> myvector;
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
	ft::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i + 1);
	std::cout << "capacity: " << vec.capacity() << std::endl;
	ft::vector<int>::iterator it = vec.begin();
	ft::vector<int>::iterator it2 = it;
	// ft::vector<int>::iterator ite = vec.end();
	it2 = it + 2;
	std::cout << *it2 << std::endl;
	it += 3;
	std::cout << *it << std::endl;
	// it -= 2;
	// std::cout << *it << std::endl;
	// std::cout << it[9] << std::endl;
	// std::cout << it.operator->() << std::endl;
	// while (it != ite)
	// {
	//  std::cout << *it << std::endl;
	//  ++it;
	// }
}

void	testInsertMine()
{
	ft::vector<int> myvector(5, 100);
	ft::vector<int>::iterator it = myvector.begin();

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

	ft::vector<int> anothervector (2,400);
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
	ft::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}

void	testPopBackMine()
{
	ft::vector<int> myvector(5);
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
	ft::vector<int> myvector (10);   // 10 zero-initialized elements

	ft::vector<int>::size_type sz = myvector.size();

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
	ft::vector<int>::size_type sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	ft::vector<int> bar;
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
	ft::vector<int> myvector;

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
	ft::vector<int> myints;
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
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	// foo.swap(bar);
	ft::swap(foo, bar);

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
	ft::vector<int> a(5, 100);
	ft::vector<int>::const_iterator it = a.begin();
	ft::vector<int>::const_iterator it2;
	it2 = it;
	while (it2 != a.end())
		std::cout << *it2++ << std::endl;
}

void	testRevIteratorMine()
{
	ft::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
	std::cout << "rev iterator at begin: " << *rit << std::endl;
	std::cout << "rev iterator at end: " << *myvector.rend() << std::endl;
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i + 1);
	std::cout << "capacity: " << vec.capacity() << std::endl;
	ft::vector<int>::reverse_iterator it = vec.rbegin();
	ft::vector<int>::reverse_iterator it2 = vec.rbegin();
	// ft::vector<int>::reverse_iterator ite = vec.end();
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
	ft::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	ft::vector<int>::const_reverse_iterator rit = myvector.rbegin();
	std::cout << "rev iterator at begin: " << *rit << std::endl;
	std::cout << "rev iterator at end: " << *myvector.rend() << std::endl;
	for (; rit!= myvector.rend(); ++rit)
	{
		myvector.operator[](i) = i;
		i++;
	}

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i + 1);
	std::cout << "capacity: " << vec.capacity() << std::endl;
	ft::vector<int>::const_reverse_iterator it = vec.rbegin();
	ft::vector<int>::const_reverse_iterator it2 = vec.rbegin();
	// ft::vector<int>::const_reverse_iterator ite = vec.end();
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
	ft::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i + 1);
	std::cout << "capacity: " << vec.capacity() << std::endl;
	ft::vector<int>::const_iterator it = vec.begin();
	ft::vector<int>::const_iterator it2 = it;
	// ft::vector<int>::const_iterator ite = vec.end();
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
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void erase_test(void)
{
	ft::vector<int> my;
	for (int i = 1; i <= 10; i++)
		my.push_back(i);
	std::cout << "my size: " << my.size() << std::endl;
	ft::vector<int>::iterator it_m;
	it_m = my.erase(my.begin() + 4);
	std::cout << "\niterator points at: " << *it_m << std::endl;
	std::cout << "my contains BEFORE ERASE ITERATOR:";
	for (unsigned i = 0; i < my.size(); ++i)
		std::cout << ' ' << my.at(i);
	std::cout << std::endl;
	std::cout << "erase :" << *my.erase(my.begin(), my.begin() + 3) << std::endl;
	std::cout << "my contains AFTER ERASE ITERATOR:";
	for (unsigned i = 0; i < my.size(); ++i)
		std::cout << ' ' << my.at(i);
	std::cout << std::endl;
	std::cout << "\niterator points at AFTTER: " << *it_m << std::endl;
	std::cout << "my size after erase: " << my.size() << std::endl;
	std::cout << "my contains:";
	for (unsigned i = 0; i < my.size(); ++i)
		std::cout << ' ' << my.at(i);
	std::cout << '\n';
}

void erase_test2(void)
{
	ft::vector<int> my;
	for (int i = 1; i <= 10; i++)
		my.push_back(i);
	std::cout << "my new contains:";
	for (unsigned i = 0; i < my.size(); ++i)
		std::cout << ' ' << my.at(i);
	std::cout << '\n';
	std::cout << "after erase points at: " << *my.erase(my.begin(), my.begin() + 5) << std::endl;
}

void	blah()
{
	ft::vector<int> real(3, 100);
    ft::vector<int>::iterator itr;
    itr = real.begin();
    itr = real.insert(itr, 200);
    std::cout << *itr << std::endl;
    real.insert(itr, 2, 300);
    itr = real.begin();
    ft::vector<int> anothervector(2, 400);
    real.insert(itr + 2, anothervector.begin(), anothervector.end());
    int myarray[] = {501, 502, 503};
    real.insert(real.begin(), myarray, myarray + 3);
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
	erase_test();
	erase_test2();
	std::cout << "TEST IS FINISHED!!\n";
	// while(1);
	return (0);
}
