#include "sort.h"
/**
 * bubble_sort - sort an array of ints in ascending order
 * @array: to sort
 * @size: size of arr
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int tmp;

	if (array == NULL)
		return;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
