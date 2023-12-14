#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: to be sorted
 * @size: size of array
 */
void counting_sort(int *array, size_t size);

void counting_sort(int *array, size_t size)
{
	size_t i;
	int k;
	int *count;
	int *tmp;

	if (array == NULL || size <= 1)
		return;

	k = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	count = (int *)malloc((k + 1) * sizeof(int));

	if (count == NULL)
		return;

	for (i = 0; i <= (size_t)k; i++)
	{
		count[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	for (i = 1; i <= (size_t)k; i++)
	{
		count[i] += count[i - 1];
	}
	print_array(count, k + 1);

	tmp = (int *)malloc(size * sizeof(int));

	if (tmp == NULL)
	{
		free(count);
		return;
	}

	for (i = size - 1; i != SIZE_MAX; i--)
	{
		tmp[--count[array[i]]] = array[i];
	}

	for (i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}

	free(count);
	free(tmp);
}
