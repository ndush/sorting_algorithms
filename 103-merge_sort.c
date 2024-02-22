#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of arr[].
 * @array: The array to be sorted
 * @left: Index of the left subarray
 * @mid: Index of the middle element
 * @right: Index of the right subarray
 * @temp: Temporary array to store merged subarrays
 **/
void merge(int *array, size_t left, size_t mid, size_t right, int *temp)
{
	size_t i = left, j = mid + 1, k = left;

	printf("Merging...\n");

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	print_array(array + left, right - left + 1);
}

/**
 * divide - Divides the array recursively.
 * @array: The array to be sorted
 * @left: Index of the left subarray
 * @right: Index of the right subarray
 * @temp: Temporary array to store merged subarrays
 **/
void divide(int *array, size_t left, size_t right, int *temp);

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 **/
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	divide(array, 0, size - 1, temp);

	free(temp);
}

/**
 * divide - Divides the array recursively.
 * @array: The array to be sorted
 * @left: Index of the left subarray
 * @right: Index of the right subarray
 * @temp: Temporary array to store merged subarrays
 **/
void divide(int *array, size_t left, size_t right, int *temp)
{
	size_t mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		divide(array, left, mid, temp);
		divide(array, mid + 1, right, temp);
		merge(array, left, mid, right, temp);
	}
}

