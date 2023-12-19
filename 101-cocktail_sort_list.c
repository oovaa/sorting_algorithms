#include "sort.h"

/**
 * front_swap - Swaps two nodes in a doubly linked list.
 * @list: the full list
 * @node: Pointer to the first node.
 *
 * This function swaps the positions of two nodes in a doubly linked list.
 * It updates the pointers of adjacent nodes accordingly.
 */

void front_swap(listint_t **list, listint_t *node)
{
	listint_t *tmp = node->next;

	if (!tmp)
		return;

	if (node->prev)
		node->prev->next = tmp;
	else
		*list = tmp;

	if (tmp->next)
		tmp->next->prev = node;

	node->next = tmp->next;
	node->prev = tmp;
	tmp->next = node;
	tmp->prev = node->prev;

	printf("Front swap: ");
	print_list(*list);
}

/**
 * back_swap - Swaps two nodes in a doubly linked list.
 * @list: the full list
 * @node: Pointer to the first node.
 *
 * This function swaps the positions of two nodes in a doubly linked list.
 * It updates the pointers of adjacent nodes accordingly.
 */

void back_swap(listint_t **list, listint_t *node)
{
	listint_t *tmp = node->prev;

	if (!tmp)
		return;

	if (node->next)
		node->next->prev = tmp;
	else
		*list = node;

	if (tmp->prev)
		tmp->prev->next = node;

	node->prev = tmp->prev;
	node->next = tmp;
	tmp->prev = node;
	tmp->next = node->next;

	if (node->next)
		node->next->prev = node;

	printf("Back swap: ");
	print_list(*list);
}

/**
 * cocktail_sort_list - Performs Cocktail Shaker Sort on a list.
 * @list: list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *head;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		head = *list;
		while (head->next != NULL)
		{
			if (head->n > head->next->n)
			{
				front_swap(list, head);
				swapped = 1;
				print_list(*list);
			}
			if (head->next)
				head = head->next;
		}

		if (!swapped)
			break;

		head = *list;
		while (head->next != NULL)
		{
			if (head->n > head->next->n)
			{
				front_swap(list, head);
				swapped = 1;
				print_list(*list);
			}
			if (head->next)
				head = head->next;
		}

		head = head->prev;
		while (head != NULL)
		{
			if (head->n < head->prev->n)
			{
				back_swap(list, head);
				swapped = 1;
				print_list(*list);
			}
			if (head->prev)
				head = head->prev;
		}

		printf("After pass: ");
		print_list(*list);
	}
}
