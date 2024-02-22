#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Description: This function sorts an array of integers in ascending order
 *              using the Merge sort algorithm. It implements the top-down
 *              merge sort approach where the array is divided into two
 *              sub-arrays, each of which is sorted recursively, and then
 *              merged to produce a single sorted array.
 */
void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        size_t i, j, k;
        int *left = array;
        int *right = array + mid;
        size_t left_size = mid;
        size_t right_size = size - mid;
        int *temp = malloc(size * sizeof(int));

        if (temp == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        merge_sort(left, left_size);
        merge_sort(right, right_size);

        printf("Merging...\n[left]: ");
        print_array(left, left_size);
        printf("[right]: ");
        print_array(right, right_size);

        i = 0;
        j = 0;
        k = 0;

        while (i < left_size && j < right_size)
        {
            if (left[i] <= right[j])
            {
                temp[k++] = left[i++];
            }
            else
            {
                temp[k++] = right[j++];
            }
        }

        while (i < left_size)
        {
            temp[k++] = left[i++];
        }

        while (j < right_size)
        {
            temp[k++] = right[j++];
        }

        for (i = 0; i < size; i++)
        {
            array[i] = temp[i];
        }

        printf("[Done]: ");
        print_array(array, size);

        free(temp);
    }
}

