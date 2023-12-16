#include "sort.h"

/**
 * find_gap - gets the largest sequence gap
 * @size: size of array
 * Return: size of gap
 */

size_t find_gap(size_t size)
{
	size_t g;

	g = 1;

	while (g <= size / 3)
		g = g * 3 + 1;

	return (g);
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array : to be sorted
 * @size : size of array
 */

void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t gap, a, b;

	gap = find_gap(size);

	if (!array || !size)
		return;

	while (gap > 0)
	{
		for (a = 0; a < size; a++)
		{
			for (b = a; b < size && b >= gap && array[b - gap] > array[b]; b -= gap)
			{
				tmp = array[b - gap];
				array[b - gap] = array[b];
				array[b] = tmp;
			}
		}
		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
