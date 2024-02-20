#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size) {
	size_t i;
	int max = 0;
	int *count;
	int *output;

	if (size < 2)
		return;

	for (i = 0; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}

	count = malloc((max + 1) * sizeof(int));
	if (!count)
		return;

	for (i = 0; i <= (size_t)max; i++) {
		count[i] = 0;
	}

	for (i = 0; i < size; i++) {
		count[array[i]]++;
	}

	for (i = 1; i <= (size_t)max; i++) {
		count[i] += count[i - 1];
	}

	output = malloc(size * sizeof(int));
	if (!output) {
		free(count);
		return;
	}

	for (i = size - 1; i < size; i--) {
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++) {
		array[i] = output[i];
	}

	free(count);
	free(output);
}

