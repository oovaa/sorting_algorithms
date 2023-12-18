#include "sort.h"



/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 *
 * This function swaps the positions of two nodes in a doubly linked list.
 * It updates the pointers of adjacent nodes accordingly.
 */

void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL)
		return;

	if (node1 == node2)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node2->next = node1;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - Performs Cocktail Shaker Sort on a list.
 * @list: list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *head = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		while (head->next != NULL)
		{
			if (head->n > head->next->n)
			{
				swap_nodes(head, head->next);
				swapped = 1;
				print_list(*list);
			}
			if (head->next)
				head = head->next;
		}

		if (!swapped)
			break;

		while (head->prev != NULL)
		{
			if (head->n < head->prev->n)
			{
				swap_nodes(head->prev, head);
				swapped = 1;
				print_list(*list);
			}
			if (head->prev)
				head = head->prev;
		}

	while (head->prev != NULL)
		head = head->prev;
	*list = head;
	}
}
