#include "sort.h"

/**
 * getmax - return max val in array
 * @array: arr to find max val
 * @size: size of arr
 * Return: max val in arr
 */

int getmax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * count_s - do count sort for particular place value (pos)
 * @array: to be sorted
 * @size: size of arr
 * @pos: place value (1, 10)
 */
void count_sort(int *array, size_t size, int pos)
{
    int count[10] = {0};
    size_t i;
    int *arrayb = malloc(sizeof(int) * size);

    if (!arrayb)
        return;

    for (i = 0; i < size; i++)
    {
        count[(array[i] / pos) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (i = size - 1; i >= 0; i--)
    {
        arrayb[--count[(array[i] / pos) % 10]] = array[i];
    }

    for (i = 0; i < size; i++)
    {
        array[i] = arrayb[i];
    }

    free(arrayb);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: to be sorted
 * @size: size of array
 */

void radix_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int max = getmax(array, size);

    for (int pos = 1; max / pos > 0; pos * 10)
    {
        count_sort(array, size, pos);
        print_array(array, size);
    }
}