/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorette <mlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:27:27 by mlorette          #+#    #+#             */
/*   Updated: 2021/05/12 16:41:13 by mlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef struct	Node {
	int			value;
	struct Node	*next;
	Node(int x, Node *nxt = 0) : value(x), next(nxt) {}
	Node() : value(0), next(0) {}
	~Node() {}
}				Node;

void merge(Node *a, Node *b, Node **c)
{
	Node tmp;
	*c = NULL;
	if (a == NULL) {
		*c = b;
		return ;
	}
	if (b == NULL) {
		*c = a;
		return ;
	}
	if (a->value < b->value) {
		*c = a;
		a = a->next;
	}
	else {
		*c = b;
		b = b->next;
	}
	tmp.next = *c;
	while (a && b) {
		if (a->value < b->value) {
			(*c)->next = a;
			a = a->next;
		}
		else {
			(*c)->next = b;
			b = b->next;
		}
		(*c) = (*c)->next;
	}
}

void	merge_sort(Node **head)
{
	T *low = NILL;
	T* high = NULL;
	if (*head == NULL || (*head)->_next == NULL)
		return ;
	split(*head, &low, &high);
	merge_sort(&low);
	merge_sort(&high);
	merge(low, high, head);
}

void	print(Node *tmp)
{
	std::cout << "list:";
	for (int i = 0; i < 10; i++)
	{
		std::cout << " " << tmp->value;
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void sort()
{
	srand(time(NULL));
	int	size = 50;
	Node *head = new Node(5);
	Node *tmp = head;
	for (int i = 0; i < size; i++)
	{
		tmp->next = new Node(rand() % 100);
		tmp = tmp->next;
	}
	print(head);
	mergeSort(&head);
	print(head);
}

int	main(int, char **argv)
{
	sort();
	return (0);
}