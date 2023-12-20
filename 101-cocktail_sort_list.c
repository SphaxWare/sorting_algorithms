#include "sort.h"
/**
 * cocktail_sort_list - sort a list
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		temp = *list;
		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				temp = node_swaper(temp->next, list);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			if (temp->next != NULL)
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				temp = node_swaper(temp, list);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
			if (temp->prev != NULL)
				temp = temp->prev;
		}
	} while (swapped);
}
/**
 * node_swaper - swap two nodes
 * @node : node
 * @list: the list
 * Return: current node
 */
listint_t *node_swaper(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
