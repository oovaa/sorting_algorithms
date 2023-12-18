#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Prototypes*/

void swap(int *a, int *b);

void quick_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void print_list(const listint_t *list);

void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);

void selection_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);

void counting_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);

void merge_sort(int *array, size_t size);

/*Heap sort*/

void swap_ints(int *a, int *b);

void siftdown(int *array, size_t start, size_t end, size_t size);

void heap_sort(int *array, size_t size);

/*Radix*/

int get_max(int *array, size_t size);

void count_s(int *array, size_t size, int pos);

void radix_sort(int *array, size_t size);

#endif
