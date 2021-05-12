/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 13:55:52 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/11 14:12:16 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode fake(-1);
		ListNode *last = &fake;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				last->next = l1;
				last = l1;
				l1 = l1->next;
			}
			else {
				last->next = l2;
				last = l2;
				l2 = l2->next;
			}
		}
		if (l1 != NULL) {
			last->next = l1;
		}
		if (l2 != NULL) {
			last->next = l2;
		}
		return (fake.next);
	}
};


int	main()
{
	ListNode *a = new ListNode(1);
	a->next = new ListNode(2);
	a->next->next = new ListNode(4);
	a->next->next->next = 0;

	ListNode *b = new ListNode(1);
	b->next = new ListNode(3);
	b->next->next = new ListNode(4);
	b->next->next->next = 0;\
	Solution sol;
	ListNode *sorted = sol.mergeTwoLists(a, b);
	while (sorted != 0)
	{
		std::cout << "first element: " << sorted->val << std::endl;
		sorted = sorted->next;
	}
}