#include "sort.h"

/**
 * Node_Swap_Ahead - A function that is used to swap
 *  a node in a doubly-linked list that's type listint_t
 *  which is a list of integers with the node after it.
 * @list: represents a pointer that points to the head
 *  of the doubly-linked list.
 * @last: represents a pointer that points to the tail 
 *  of the doubly-linked list.
 * @curr: represents a pointer that points to the current
 *  swapping node of the Cocktail shaker algorithm.
 * Return: It returns Nothing.
 */

void Node_Swap_Ahead(listint_t **list, listint_t **last, listint_t **curr)
{
	listint_t *Temp = (*curr)->next;

	if ((*curr)->prev != NULL)
		(*curr)->prev->next = Temp;
	else
		*list = Temp;

    Temp->prev = (*curr)->prev;
	(*curr)->next = Temp->next;

    if (Temp->next != NULL)
		Temp->next->prev = *curr;
	else
		*last = *curr;
	(*curr)->prev = Temp;
	Temp->next = *curr;
	*curr = Temp;
}

/**
 * Node_Swap_Before - A function that is used to swap
 *  a node in a doubly-linked list that's type listint_t
 *  which is a list of integers with the node before it.
 * @list: represents a pointer that points to the head
 *  of the doubly-linked list.
 * @last: represents a pointer that points to the tail 
 *  of the doubly-linked list.
 * @curr: represents a pointer that points to the current
 *  swapping node of the Cocktail shaker algorithm.
 * Return: It returns Nothing.
 */

void Node_Swap_Before(listint_t **list, listint_t **last, listint_t **curr)
{
	listint_t *Temp = (*curr)->prev;

	if ((*curr)->next != NULL)
		(*curr)->next->prev = Temp;
	else
		*last = Temp;

    Temp->next = (*curr)->next;
	(*curr)->prev = Temp->prev;

    if (Temp->prev != NULL)
		Temp->prev->next = *curr;
	else
		*list = *curr;
	(*curr)->next = Temp;
	Temp->prev = *curr;
	*curr = Temp;
}

/**
 * cocktail_sort_list - A function that is used to sort
 *  a doubly-linked list of type listint_t of integers
 *  in ascending order(by using the cocktail shaker
 *  algorithm).
 * @list: represents a pointer that points to the head
 *  of the doubly-linked list that's type listint_t.
 * Return: It returns Nothing.
 */

void cocktail_sort_list(listint_t **list)
{
	bool Shaked = false;
	listint_t *last, *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (last = *list; last->next != NULL;)
		last = last->next;

	while (Shaked == false)
	{
		Shaked = true;

        for (curr = *list; curr != last; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				Node_Swap_Ahead(list, &last, &curr);
				print_list((const listint_t *)*list);
				Shaked = false;
			}
		}

        for (curr = curr->prev; curr != *list;
				curr = curr->prev)
		{

            if (curr->n < curr->prev->n)
			{
				Node_Swap_Before(list, &last, &curr);
				print_list((const listint_t *)*list);
				Shaked = false;
			}
		}
	}
}
