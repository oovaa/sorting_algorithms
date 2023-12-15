#include "sort.h"
#include <stdio.h>

/**
 * cocktailShakerSort - Performs Cocktail Shaker Sort on an array.
 * @arr: array to sort
 * @n: size of the array to sort
 */

void cocktailShakerSort(int arr[], int n)
{
	int i, swapped = 1, start = 0, end = n - 1;

	while (swapped)
	{
		swapped = 0;
		for (i = start; i < end; i++)
			if (arr[i] > arr[i + 1])
			{
				swapped = 1;
				swap(&arr[i], &arr[i + 1]);
			}
		end--;
		if (!swapped)
			break;

		for (i = end; i >= start; i--)
			if (arr[i] < arr[i - 1])
			{
				swapped = 1;
				swap(&arr[i], &arr[i - 1]);
			}
		start++;
	}
}
