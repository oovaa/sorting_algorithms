#include "sort.h"


/**
 * partition - Lomuto partition scheme
 * @array: Array to be sorted
 * @start: Starting index of the array or subarray
 * @end: Ending index of the array or subarray
 * @size: the size of the array
 *
 * Return: Index of the pivot element after partitioning
 */

int partition(int *array, size_t start, size_t end, size_t size)
{
	int pivot = array[end];
	size_t i = start - 1, j;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	i++;
	if (i != end)
	{
		swap(&array[i], &array[end]);
		print_array(array, size);
	}

	return (i);

}


/**
 * quick_rec - Recursively sorts a subarray using the Quick Sort algorithm
 * @array: Array to be sorted
 * @start: Starting index of the array or subarray
 * @end: Ending index of the array or subarray
 * @size: the size of the array
 */

void quick_rec(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start >= end)
		return;

	pivot = partition(array, start, end, size);

	quick_rec(array, start, pivot - 1, size);
	quick_rec(array, pivot + 1, end, size);
}

/**
 * quick_sort - Sorts an array using the Quick Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	 quick_rec(array, 0, (int)size - 1, size);
}
