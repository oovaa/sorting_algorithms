#include "sort.h"


/**
 * partition - Lomuto partition scheme
 * @array: Array to be sorted
 * @start: Starting index of the array or subarray
 * @end: Ending index of the array or subarray
 *
 * Return: Index of the pivot element after partitioning
 */

int partition(int *array, size_t start, size_t end)
{
	int pivot = array[end];
	int i = start - 1, j;

	for (j = start; j < (int)end; j++)
		if (array[j] < pivot)
			swap(&array[++i], &array[j]);

	swap(&array[++i], &array[end]);
	return (i);
}


/**
 * quick_rec - Recursively sorts a subarray using the Quick Sort algorithm
 * @array: Array to be sorted
 * @start: Starting index of the array or subarray
 * @end: Ending index of the array or subarray
 */

void quick_rec(int *array, int start, int end)
{
	int pivot;

	if (start >= end)
		return;

	pivot = partition(array, start, end);

	quick_rec(array, start, pivot - 1);
	quick_rec(array, pivot + 1, end);
}

/**
 * quick_sort - Sorts an array using the Quick Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	 quick_rec(array, 0, (int)size - 1);
}
