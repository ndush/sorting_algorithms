#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with the Knuth sequence.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    /* Calculate the initial gap using the Knuth sequence */
    gap = 1;
    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        /* Perform insertion sort with the current gap */
        for (i = gap; i < size; i++)
        {
            int temp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        /* Print the array after each decrease in the gap size */
        print_array(array, size);

        /* Calculate the next gap using the Knuth sequence */
        gap = (gap - 1) / 3;
    }

    /* Print the final sorted array */
    printf("Array after final gap 1: ");
    print_array(array, size);
}
