#include "sort.h"

/**
 * hoare_partition - Partitions the array using the Hoare partition scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * Return: The index of the pivot after partitioning
 */
int hoare_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;
	int temp;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		/* Swap array[i] and array[j] */
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * quicksort_hoare_recursive - Recursively sorts the partitioned array
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quicksort_hoare_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high);

		quicksort_hoare_recursive(array, low, pivot, size);
		quicksort_hoare_recursive(array, pivot + 1, high, size);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort
 *algorithm with Hoare partition scheme
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare_recursive(array, 0, size - 1, size);
}

