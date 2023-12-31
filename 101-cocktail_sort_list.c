#include "sort.h"



/**
 * front_swap - Swaps two nodes in a doubly linked list.
 * @list: the full list
 * @node: Pointer to the first node.
 *
 * This function swaps the positions of two nodes in a doubly linked list.
 * It updates the pointers of adjacent nodes accordingly.
 */

void front_swap(listint_t *node)
{
	listint_t *tmp;

	tmp = node->next;
	if (!tmp)
		return;

	if (node->prev)
		node->prev->next = tmp;

	if (tmp->next)
		tmp->next->prev = node;

	tmp->prev = node->prev;
	node->next = tmp->next;
	node->prev = tmp;
	tmp->next = node;
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
	listint_t *tmp;

	tmp = node->prev;
	if (!tmp)
		return;

	if (node->next)
		node->next->prev = tmp;

	if (tmp->prev)
		tmp->prev->next = node;
	else
		*list = node;

	tmp->next = node->next;
	node->prev = tmp->prev;
	node->next = tmp;

	if (tmp->prev)
		tmp->prev = node;
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
				front_swap(head);
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
				back_swap(list, head);
				swapped = 1;
				print_list(*list);
			}
			if (head->prev)
				head = head->prev;
		}
		*list = head;
	}
}
