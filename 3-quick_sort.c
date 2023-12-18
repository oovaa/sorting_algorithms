#include "sort.h"


/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t start, size_t end, size_t size)
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
 * lomuto_sort - Recursively sorts a subarray using the Quick Sort algorithm
 * @array: Array to be sorted
 * @start: Starting index of the array or subarray
 * @end: Ending index of the array or subarray
 * @size: the size of the array
 */

void lomuto_sort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start >= end)
		return;

	pivot = lomuto_partition(array, start, end, size);

	lomuto_sort(array, start, pivot - 1, size);
	lomuto_sort(array, pivot + 1, end, size);
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

	 lomuto_sort(array, 0, (int)size - 1, size);
}
