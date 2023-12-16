#include "sort.h"
/**
 * insertion_sort_list - sort an array
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	tmp = (*list)->next;
	while (tmp)
	{
		temp = tmp;
		tmp = tmp->next;
		while (temp && temp->prev)
		{
			if (temp->prev->n > temp->n)
			{
				swaper(temp->prev, temp);
				if (!temp->prev)
					*list = temp;
				print_list((const listint_t *)*list);
			}
			else
				temp = temp->prev;
		}
	}
}
/**
 * swaper - swap two nodes
 * @previous: node
 * @current: node
 */
void swaper(listint_t *previous, listint_t *current)
{
	if (previous->prev)
		previous->prev->next = current;
	if (current->next)
		current->next->prev = previous;
	previous->next = current->next;
	current->prev = previous->prev;
	previous->prev = current;
	current->next = previous;
}

