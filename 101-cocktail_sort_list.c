#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		/* Forward traversal */
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
				print_list(*list);
			}
			else
				start = start->next;
		}

		/* Update the end pointer */
		end = start;

		/* Backward traversal */
		while (start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				swapped = 1;
				print_list(*list);
			}
			else
				start = start->prev;
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node_a: Pointer to the first node
 * @node_b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
	if (*list == NULL || node_a == NULL || node_b == NULL)
		return;

	if (node_a->prev != NULL)
		node_a->prev->next = node_b;
	else
		*list = node_b;

	if (node_b->next != NULL)
		node_b->next->prev = node_a;

	node_a->next = node_b->next;
	node_b->prev = node_a->prev;
	node_a->prev = node_b;
	node_b->next = node_a;
}
