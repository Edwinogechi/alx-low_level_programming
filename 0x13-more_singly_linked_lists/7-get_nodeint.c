#include "lists.h"

/**
 * get_nodeint_at_index - function returning the nth node of a listint_t list.
 * @head: pointer to the head of the linked list.
 * @index: index of the node to be returned, starting at 0.
 * Return: pointer to the nth node, or NULL if the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp;
	unsigned int i;

	/* Initialize the temp node to the head of the list */

	temp = head;

	/* Traverse the list upto the index */

	for (i = 0; temp != NULL && i < index; i++)
	{
		temp = temp->next;
	}

	 /* Check if the index is off limits */

	if (i != index)
	{
		return (NULL);
	}

	return (temp);
}
