#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a given index
 * @head: pointer pointing to the first element in the list
 * @index: index of the node to be deleted
 * Return: 1 (Success), or -1 (Fail)
 */


int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp;
	listint_t *prev;
	unsigned int i;

	if (*head == NULL)
	return (-1);

	/* special case for first element */
	if (index == 0)
	{
	temp = *head;
	*head = temp->next;
	free(temp);
	return (1);
	}

	/* iterate over the list til the previous node before the one to be deleted */
	prev = *head;

	for (i = 0; i < index - 1 && prev != NULL; i++)
	prev = prev->next;

	if (!prev || !prev->next) /* check if index limited */
	return (-1);

	/* delete the node at index */
	temp = prev->next;

	prev->next = temp->next;

	free(temp);

	return (1);
}

