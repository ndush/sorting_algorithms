#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void counting_sort(int *array, size_t size) {
    size_t i;

    int *count; /* Declare count here */
    int *sorted; /* Declare sorted here */

    /* Find the maximum element in the array */
    size_t max = (size_t) array[0]; /* Cast array[0] to size_t */
    for (i = 1; i < size; i++) {
        if ((size_t)array[i] > max) /* Cast array[i] to size_t */
            max = (size_t) array[i]; /* Cast array[i] to size_t */
    }

    /* Create and initialize the counting array */
    count = malloc((max + 1) * sizeof(int)); /* Move declaration here */
    if (count == NULL)
        return;

    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Count occurrences of each element */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Update count array to store the actual position of each element */
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Build the sorted array */
    sorted = malloc(size * sizeof(int)); /* Move declaration here */
    if (sorted == NULL) {
        free(count);
        return;
    }

    for (i = size - 1; i < size; i--) {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted array back to the original array */
    for (i = 0; i < size; i++)
        array[i] = sorted[i];

    /* Free allocated memory */
    free(count);
    free(sorted);
}

