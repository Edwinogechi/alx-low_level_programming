#include "lists.h"

/**
 * get_dnodeint_at_index - Return data from nth node of a dlistint_t list
 * @head: Pointer to the head of the dlistint_t linked list
 * @index: Index of node to return from 0
 *
 * Return: The nth node on Success, NULL on Failure
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp = head; /* The pointer to traverse the list */
	unsigned int count = 0; /* The variable to monitor the index */

	while (temp != NULL)
	{
		/* If index matches the count, return the current node */
		if (count == index)
			return (temp);

		/* Move to the next node and increment the index */
		temp = temp->next;
		count++;
	}

	/* If the node doesn't exist, return NULL */
	return (NULL);
}
