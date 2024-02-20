#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the Counting sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Return: Void
 */
void co(void);
void counting_sort(int *array, size_t size)
{
	size_t count_size;
	int *count, *output;
	int i;
	int max;

	/* Find the maximum element in the array */
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Allocate memory for the counting array */
	count_size = max + 1;
	count = malloc(count_size * sizeof(int));

	/* Initialize the counting array */
	for (i = 0; i < (int)count_size; i++)
		count[i] = 0;

	/* Count the occurrence of each element in the array */
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	/* Print the counting array */
	for (i = 0; i < (int)count_size; i++)
		printf("%d, ", count[i]);
	printf("\n");

	/* Calculate the prefix sum of the counting array */
	for (i = 1; i < (int)count_size; i++)
		count[i] += count[i - 1];

	/* Allocate memory for the output array */
	output = malloc(size * sizeof(int));

	/* Build the output array */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the output array back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	/* Free the memory allocated for the counting array and the output array */
	free(count);
	free(output);
}
