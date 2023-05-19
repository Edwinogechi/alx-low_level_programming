#include "lists.h"
/**
 * sum_dlistint - Adds the sum of data (n) in a dlistint_t linked list.
 * @head: Pointer to the head node of the list
 *
 * Return: The sum of all the data (n), 0 if empty
 */
int sum_dlistint(dlistint_t *head)
{

	int sum = 0;
	dlistint_t *temp = head;

	if (head)
	{

		/* Iterate over the list and get the sum */

		while (temp != NULL)
		{
			sum += temp->n;
			temp = temp->next;
		}

		return (sum);
	}
	return (0);
}
