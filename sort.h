#ifndef SORT_H
#define SORT_H

#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *              using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Big O notations:
 * O(n) - Best case: when the array is already sorted
 * O(n^2) - Average and worst cases
 */
void bubble_sort(int *array, size_t size);
void swap(int *a, int *b);
#endif /* SORT_H */
