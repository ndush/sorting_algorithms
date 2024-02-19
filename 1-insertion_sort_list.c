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
	listint_t *next;
	listint_t *prev;
	listint_t *sorted;

	if (!list || !*list)
		return;

	sorted = *list;
	current = sorted->next;

	while (current)
	{
		prev = sorted;
		next = current->next;

		/* Move the current node to the beginning of the sorted list */
		if (current->n < sorted->n)
		{
			current->prev = NULL;
			current->next = sorted;
			sorted->prev = current;
			*list = current;
			sorted = current;
		}

		/* Find the correct position for the current node in the sorted list */
		while (prev->next && prev->next->n > current->n)
		{
			prev = prev->next;
		}

		/* Swap the current node with the previous node */
		if (prev != sorted)
		{
			prev->next->prev = current;
			current->next = prev->next;
			current->prev = prev;
			prev->next = current;
			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;
			sorted = current;
		}

		/* Move to the next node */
		current = next;
	}
}
