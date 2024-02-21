#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail Shaker Sort algorithm
 * @list: Pointer to pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		start = (*list);
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->next;
		}
		if (!swapped)
			break;
		end = start;
		while (start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->prev;
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;

	if (*list == node1)
		*list = node2;
}

