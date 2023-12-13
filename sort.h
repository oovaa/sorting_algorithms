#ifndef SORT_H
#define SORT_H
<<<<<<< HEAD

#include <stdio.h>
#include <stdlib.h>

=======
#include <stdio.h>
>>>>>>> 266e99bf2b10c51203a3ba23c1b9e7b188bbe730

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

<<<<<<< HEAD

void swap(int *a, int *b);
void print_list(const listint_t *list);
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif  /* SORT_H */
=======
/*Prototypes*/

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);

void selection_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);
#endif
>>>>>>> 266e99bf2b10c51203a3ba23c1b9e7b188bbe730
