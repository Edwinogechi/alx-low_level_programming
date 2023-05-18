#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t linked list
 * @head: Pointer to the head of the doubly linked list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		/* Store the temp node and move head to next node */
		temp = head;
		head = head->next;
		free(temp); /* Free the temp node */
	}
}
