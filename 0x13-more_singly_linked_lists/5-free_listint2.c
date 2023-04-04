#include "lists.h"

/**
 * free_listint2 - Function freeing a listint_t list setting the head to NULL.
 * @head: A pointer pointing to the head of the list.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (!head || !*head)

	return;

	while (*head != NULL)
	{
		temp = *head;

		*head = (*head)->next;

		free(temp);
	}

	*head = NULL;
}
