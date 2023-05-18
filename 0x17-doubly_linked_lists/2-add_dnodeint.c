#include "lists.h"

/**
 * add_dnodeint - function adding new node at the beginning of a dlistint_t list.
 * @head: pointer pointing to the head of the dlistint_t list.
 * @n: integer parameter for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - pointer to the new node.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}
