#include "sort.h"

/**
 * swap_two_nodes - A function that is used to
 *  swap two nodes of doubly-linked list that
 *  are type listint_t.
 * @head: represents the head pointer of
 *  doubly-linked list.
 * @node1: represents the first node to be swapped.
 * @node2: represents the second node to be swapped.
 */

void swap_two_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - A function that is used for
 *  sorting a doubly linked list of integers in
 *  ascending order.
 * @list: represents a pointer that points to the
 *  head of the doubly linked list.
 * Description: This function sorts a doubly linked list and
 *  it's time complexity is Big O of n square and
 *  it's notation is O(n^2).
 */

void insertion_sort_list(listint_t **list)
{
listint_t *Temp;
listint_t *i, *Ins;

if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

for (i = (*list)->next; i != NULL; i = Temp)
{
Temp = i->next;
Ins = i->prev;

while (Ins != NULL && i->n < Ins->n)
{
swap_two_nodes(list, &Ins, i);
print_list((const listint_t *)*list);
}
}
}
