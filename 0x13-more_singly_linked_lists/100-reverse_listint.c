#include "lists.h"

/**
 * reverse_listint - Function reversing a listint_t linked list
 *
 * @head: Pointer pointing to the pointer of the first node of the list
 * Return: A pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *next = NULL;
	listint_t *prev = NULL;
	listint_t *current = *head;


	/* Iterating over the list while reversing the "next" pointers */
	while (current != NULL)
	{
		next = current->next;

		current->next = prev;

		prev = current;

		current = next;
	}

	*head = prev;

	return (*head);
}
