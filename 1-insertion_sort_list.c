#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		swap = current->prev;
		while (swap && current->n < swap->n)
		{
			swap->next = current->next;
			if (current->next != NULL)
				current->next->prev = swap;

			current->prev = swap->prev;
			current->next = swap;

			if (swap->prev != NULL)
				swap->prev->next = current;
			else
				*list = current;

			swap->prev = current;
			print_list(*list);

			swap = current->prev;
		}
	}
}
