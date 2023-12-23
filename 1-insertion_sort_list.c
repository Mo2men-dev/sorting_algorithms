#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		prev = current->prev;

		while (prev && prev->n > current->n)
		{
			current->prev = prev->prev;
			if (prev->prev)
			{
				prev->prev->next = current;
			}
			else
			{
				*list = current;
			}
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;

			prev->prev = current;
			current->next = prev;

			print_list(*list);

			prev = current->prev;
		}

		current = next;
	}
}
