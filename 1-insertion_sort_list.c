#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 *
 * @list: Pointer to the first element of the list to be sorted
 */
void jj(void);
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *prev;
	listint_t *next;

	if (!list || !*list)
		return;

	current = (*list)->next;

	while (current)
	{
		prev = current->prev;
		next = current->next;

		while (prev && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;
			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;
			prev = current->prev;
		}

		current = next;
	}
}
