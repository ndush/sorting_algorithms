#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Performs heapify operation on the array
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @root: Index of the root of the heap
 * @end: Index of the end of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max, left, right;

	while ((left = 2 * root + 1) <= end)
	{
		max = left;
		right = left + 1;
		if (right <= end && array[right] > array[left])
			max = right;
		if (array[root] < array[max])
		{
			swap(&array[root], &array[max]);
			print_array(array, size);
			root = max;
		}
		else
			break;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * O(n*log(n)) - Best, Average, and Worst case time complexity
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}

