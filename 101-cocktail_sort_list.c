#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm
 *
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL, *end = NULL, *current = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (current = start = *list; current->next != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		end = current;
		for (current = end->prev; current != start; current = current->prev)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current->next, current);
				print_list(*list);
				swapped = 1;
			}
		}
		start = current->next;
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to a pointer to the head of the list
 * @node_a: Pointer to the first node to be swapped
 * @node_b: Pointer to the second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node_a, listint_t *node_b)
{
	if (node_a->prev)
		node_a->prev->next = node_b;
	else
		*list = node_b;
	if (node_b->next)
		node_b->next->prev = node_a;

	node_a->next = node_b->next;
	node_b->prev = node_a->prev;
	node_a->prev = node_b;
	node_b->next = node_a;
}

