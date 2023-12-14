#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: to be sorted
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
    if (array == NULL, size <= 1)
        return;

    int k = array[0];
    size_t i;
    for (i = 1; i < size; i++)
    {
        if (array[i] > k)
            k = array[i];
    }

    int *count = malloc((k + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (i = 0, i <= k, i++)
    {
        count[i] = 0;
    }

    int i;
    for (i = 0, i < size, i++)
    {
        count[array[i]]++;
    }

    for (i = 1, i <= k, i++)
    {
        count[i] += count[i - 1];
    }

    int *tmp = malloc(size * sizeof(int));
    if (tmp == NULL)
    {
        free(count);
        return;
    }

    for (i = 0; i < size; i++)
    {
        array[i] = tmp[i];
    }

    free(count);
    free(tmp);
}