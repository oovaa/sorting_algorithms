#include "sort.h"
#define parent(x) (((x)-1) / 2)
#define leftchild(x) (((x) * 2) + 1)
#define rightchild(x) (((x) * 2) + 2)

/**
 * swap2 - swaps
 * @array: array to be sorted
 * @size: size of array
 * @a: value 1
 * @b: value 2
 */

void swap2(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
	print_array((const int *)array, size);
}

/**
 * siftdown - siftdown implementation
 * @array: array to be sorted
 * @start: start of array
 * @end: end of array
 * @size: size of array
 */

void siftdown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, swapper;
	size_t left = leftchild(root);
	size_t right = rightchild(root);

	while (leftchild(root) <= end)
	{
		swapper = root;

		if (right <= end && array[swapper] < array[right])
			swapper = right;

		if (left <= end && array[swapper] < array[left])
			swapper = left;

		if (swapper == root)
			return;

		swap2(array, size, &array[root], &array[swapper]);
		root = swapper;
	}
}

/**
 * heapify - puts heap in place
 * @array: array to be sorted
 * @size: size of array


void heapify(int *array, size_t size)
{
	ssize_t start;

	start = parent(size - 1);
	for (; start >= 0; start--)
	{
		siftdown(array, start, size - 1, size);
	}
}*/

/**
 * heap_sort - sorts an array of integers in ascending orde
 * @array: array to be sorted
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;

	/*Built-in heapify*/
	for (ssize_t start = parent(size - 1); start >= 0; start--)
	{
		siftdown(array, start, size - 1, size);
	}

	end = size - 1;
	while (end > 0)
	{
		swap2(array, size, &array[0], &array[end]);
		end--;
		siftdown(array, 0, end - 1, size);

		end--;
	}
}
