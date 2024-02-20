#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heapify - Helper function to heapify a subtree rooted with the node i
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @i: Index of the root of the subtree to be heapified
 *
 * Description: This function transforms an array into a max heap
 *              rooted at the given index i.
 */
void heapify(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		int temp = array[i];

		array[i] = array[largest];
		array[largest] = temp;
		printf("%d, ", array[i]);
		printf("%d\n", array[largest]);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Description: This function sorts an array of integers in ascending order
 *              using the Heap sort algorithm. It first builds a max heap
 *              from the array and then repeatedly extracts the maximum
 *              element from the heap and maintains the heap property.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		printf("%d, ", array[0]);
		printf("%d\n", array[i]);
		heapify(array, i, 0);
	}
}

