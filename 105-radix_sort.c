#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - Get the maximum value in an array
 * @array: The array
 * @size: Size of the array
 * Return: Maximum value
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - Perform counting sort based on a significant digit
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The exponent representing the significant digit
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];


	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	size_t exp;

	for (exp = 1; max / exp > 0; exp *= 10)
		count_sort(array, size, exp);
}

