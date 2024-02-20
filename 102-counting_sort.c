#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Counting sort algorithm. It expects the array to
 * contain only non-negative integers.
 */
void counting_sort(int *array, size_t size) {
	size_t i;
	int max = 0;
	struct node {
		int n;
		struct node *next;
		struct node *prev;
	} *head, *current;

	/* Find the maximum number in the array */
	for (i = 0; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}

	/* Allocate memory for the linked list */
	head = malloc(sizeof(struct node) * (max + 1));
	if (!head) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* Initialize the linked list */
	for (i = 0; i <= (size_t)max; i++) {
		head[i].n = 0;
		head[i].next = NULL;
		head[i].prev = NULL;
	}

	/* Count the occurrences of each number in the array */
	for (i = 0; i < size; i++) {
		head[array[i]].n++;
	}

	/* Sort the array using the counting array */
	for (i = 0; i < size; i++) {
		current = &head[i];
		while (current->n > 0) {
			array[i] = current->n;
			current->n--;
			if (current->next) {
				current = current->next;
			}
		}
	}

	/* Free the memory allocated for the linked list */
	free(head);
}

