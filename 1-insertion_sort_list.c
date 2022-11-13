#include "sort.h"
/**
 * swap_nodes - swap nodes in a linked list
 * @head: head
 * @node1: node 1
 * @node2: node2
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Insertion sort function
 * @list: list to be sorted
 * Description: sorts list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterration, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterration = (*list)->next; iterration != NULL; iterration = temp)
	{
		temp = iterration->next;
		insert = iterration->prev;
		while (insert != NULL && iterration->n < insert->n)
		{
			swap_nodes(list, &insert, iterration);
			print_list((const listint_t *)*list);
		}
	}
}
