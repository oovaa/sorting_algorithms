#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
<<<<<<< HEAD

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
=======
>>>>>>> 266e99bf2b10c51203a3ba23c1b9e7b188bbe730
