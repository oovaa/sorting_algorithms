#include "sort.h"
#define parent(x) (((x) - 1) / 2)

/**
 * siftdown - siftdown implementation
 * @array: array to be sorted
 * @start: start of array
 * @end: end of array
 * @size: size of array
 */

void siftdown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swapper;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swapper = root;

		if (array[swapper] < array[child])
			swapper = child;

		if (child + 1 <= end && array[swapper] < array[child + 1])
			swapper = child + 1;

		if (swapper == root)
			return;

		swap(&array[root], &array[swapper]);
		print_array(array, size);
		root = swapper;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending orde
 * @array: array to be sorted
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	size_t end;
	ssize_t start;

	if (!array || size < 2)
		return;

	start = parent(size - 1);
	for (; start >= 0; start--)
	{
		siftdown(array, start, size - 1, size);
	}

	end = size - 1;
	for (; end > 0; end--)
	{
		swap(&array[0], &array[end]);
		print_array(array, size);
		siftdown(array, 0, end - 1, size);
	}
}

