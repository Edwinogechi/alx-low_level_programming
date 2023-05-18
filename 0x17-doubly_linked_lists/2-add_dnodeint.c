#include "lists.h"

/**
 * add_dnodeint - function that adds new node to head of list
 * @head: head parameter of the double-linked list
 * @n: node data
 *
 * Return: address of the new element, NULL on Failure
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));

	if (!head)
		return (NULL);

	/* Initialize the given data in the list*/
	new_node->prev = NULL;
	new_node->n = n;
	new_node->next = *head;

	/* If the list is already present */

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}
