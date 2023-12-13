#include "sort.h"

void insertion_sort_list(listint_t **list)
	{
	listint_t *cur = (*list)->next, *pre, *hold;

	while (cur)
	{
		pre = cur->prev;
		hold = cur->next;

		while (pre && cur->n < pre->n)
		{

		pre->next = cur->next;
		if (cur->next)
			cur->next->prev = pre;

		cur->prev = pre->prev;
		if (pre->prev)
			pre->prev->next = cur;

		if (pre->prev)
			pre->prev->next = cur;

		else
			*list = cur;

		pre->prev = cur;
		cur->next = pre;
		pre = cur->prev;
		print_list(*list);
		}
		cur = hold;
	}
}
