#include "lists.h"
/**
 * add_dnodeint_end - Adds a new node to end of a doubly linked list
 * @head: Double pointer to the head of the list
 * @n: New node data value to be stored
 *
 * Return: Pointer to new node, NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	/* Create a new node */
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
	dlistint_t *current;

	/* Return NULL if malloc failed */
	if (!new_node)
		return (NULL);

	/* Set the data of the newly created node */
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		/* Make the new node the head if the list is empty */
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		/* Traverse to the end of the doubly linked list*/
		current = current->next;

		/* Update the last node's next pointer and new node's prev pointer*/
		current->next = new_node;
		new_node->prev = current;
	}
	/* Return the pointer to the new_node */
	return (new_node);
}
