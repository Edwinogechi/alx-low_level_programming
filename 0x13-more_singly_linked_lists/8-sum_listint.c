#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data (n) of a listint_t list
 * @head: pointer pointing to the head of the linked list
 *
 * Return: the sum of the data (n).
 */
int sum_listint(listint_t *head)
{
	listint_t *temp = head;
	int sum = 0;

	/* Iterate through the linked list */
	while (temp != NULL)
	{
		/* Add the data (n) of the temp node and move to the next node */
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}

