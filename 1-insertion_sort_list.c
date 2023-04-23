#include "sort.h"

/**
 * len_list - returns the length of a linked list
 * @b: pointer to the list
 *
 * Return: length of list
 */

int len_list(listint_t *b)
{
	int len = 0;

	while (b)
	{
		len++;
		b = b->next;
	}
	return (len);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * @list: double pointer to the list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur = NULL, *one = NULL;
	listint_t *two = NULL, *three = NULL, *four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	cur = *list;

	while (cur)
	{
		if (cur->prev && cur->n < cur->prev->n)
		{
			one = cur->prev->prev;
			two = cur->prev;
			three = cur;
			four = cur->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*list = three;
			two->prev = three;
			cur = *list;
			print_list(*list);
			continue;
		}
		else
			cur = cur->next;
	}
}
