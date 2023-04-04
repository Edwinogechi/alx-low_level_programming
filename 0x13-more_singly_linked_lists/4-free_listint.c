#include "lists.h"


/**
 * free_listint - A function that frees a listint_t list.
 * @head: Pointer pointing to the first node in the listint_t list.
 */

void free_listint(listint_t *head)
{
	listint_t *current_node;

	listint_t *temp;

	current_node = head;

	while (current_node)
	{
		temp = current_node;

		current_node = current_node->next;

		free(temp);
	}
}
