#include "sort.h"
#include <stdio.h>

/**
 * print_subarray - Prints a subarray of integers
 * @array: The array to be printed
 * @size: Number of elements in the array
 */
void print_subarray(int *array, size_t size)
{
	printf("Merging [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);
}

/**
 * bitonic_merge - Merges two subarrays of the given array in a
 *                 bitonic manner based on the direction
 * @array: The array to be sorted
 * @start: Starting index of the first subarray
 * @size: Number of elements to be merged
 * @direction: 1 for ascending order, 0 for descending order
 */
void bitonic_merge(int *array, size_t start, size_t size, int direction)
{
	if (size > 1)
	{
		size_t k = size / 2;
		size_t i;

		for (i = start; i < start + k; ++i)
		{
			if ((array[i] > array[i + k]) == direction)
			{
				int temp = array[i];

				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}

		print_subarray(array + start, size);
		bitonic_merge(array, start, k, direction);
		bitonic_merge(array, start + k, k, direction);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts the given array in a
 *                          bitonic manner based on the direction
 * @array: The array to be sorted
 * @start: Starting index of the subarray to be sorted
 * @size: Number of elements in the subarray
 * @direction: 1 for ascending order, 0 for descending order
 */
void bitonic_sort_recursive(int *array,
size_t start, size_t size, int direction)
{
	if (size > 1)
	{
		size_t k = size / 2;

		bitonic_sort_recursive(array, start, k, 1);
		bitonic_sort_recursive(array, start + k, k, 0);

		print_subarray(array + start, size);
		bitonic_merge(array, start, size, direction);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * O(n log^2 n) - Where n is the number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	int direction = 1; /* 1 for ascending order */

	print_subarray(array, size);
	bitonic_sort_recursive(array, 0, size, direction);
}

