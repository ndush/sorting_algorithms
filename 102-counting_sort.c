#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max = array[0], min = array[0], range, i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum and minimum elements in the array */
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}

	/* Calculate the range of elements */
	range = max - min + 1;

	/* Create a counting array of size range and initialize all elements to 0 */
	count = malloc(range * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i < range; i++)
		count[i] = 0;

	/* Count the occurrences of each element in the input array */
	for (i = 0; i < (int)size; i++)
		count[array[i] - min]++;

	/* Modify the count array to contain the actual position of each element in the output array */
	for (i = 1; i < range; i++)
		count[i] += count[i - 1];

	/* Create the output array */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	/* Fill the output array with sorted elements */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i] - min] - 1] = array[i];
		count[array[i] - min]--;
	}

	/* Copy the sorted elements back to the input array */
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	/* Free dynamically allocated memory */
	free(count);
	free(output);
}

