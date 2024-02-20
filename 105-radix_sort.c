#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Gets the maximum element from an array
 * @array: The array to find the maximum element from
 * @size: Number of elements in the array
 * Return: The maximum element in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * countingSort - Sorts an array of integers based on a significant digit
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: The significant digit to be considered
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * O(n * k) - Where n is the number of elements and k is the number of digits
 *             in the maximum element
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
	}
}

