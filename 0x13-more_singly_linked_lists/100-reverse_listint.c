#include "lists.h"

/**
 * reverse_listint - Function reversing a listint_t linked list
 *
 * @head: Pointer pointing to the pointer of the first node of the list
 * Return: A pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	/*Initialize a pointer to the previous and next node to NULL*/
	listint_t *prev = NULL;
	listint_t *next = NULL;


	/*  Loop through the list until the current head is NULL */
	while (*head)
	{
		next = (*head)->next;

		(*head)->next = prev;

		prev = *head;

		*head = next;
	}

	*head = prev;

	return (*head);
}
