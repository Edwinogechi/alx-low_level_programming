#include "lists.h"


/**
 * print_dlistint - Prints all elements of a dlistint_t linked list
 * @h: Pointer to the head of the doubly linked list
 *
 * Return: The number of nodes in the list
 */


size_t print_dlistint(const dlistint_t *h)
{
	/* The variable to count the number of nodes present*/
	size_t node_number = 0;
	const dlistint_t *current = h;

	while (current != NULL)
	{
		/* Print the value of the current node, traverse and increment*/
		printf("%d\n", current->n);
		current = current->next;
		node_number++;
	}

	/* Return the total count of nodes*/
	return (node_number);
}
