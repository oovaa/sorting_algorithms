#include "sort.h"


/**
 * merge - Merge two subarrays of arr[].
 * @arr: Array to be sorted.
 * @l: Left index of the subarray.
 * @m: Middle index of the subarray.
 * @r: Right index of the subarray.
 */

void merge(int *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = (int *)malloc(n1 * sizeof(int));
	int *R = (int *)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];

		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}

/**
 * merge_rec - Recursively sort a subarray using the merge sort algorithm.
 * @arr: Array to be sorted.
 * @left: Left index of the subarray.
 * @right: Right index of the subarray.
 */

void merge_rec(int *arr, unsigned int left, unsigned int right)
{

	if (left < right)
	{
		int middle = left + (right - left) / 2;

		merge_rec(arr, left, middle);
		merge_rec(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}


/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{ merge_rec(array, 0, (int)size - 1); }
