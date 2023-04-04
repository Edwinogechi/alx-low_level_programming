#include "lists.h"

/**
 * add_nodeint_end - function adding a new node at the end of a listint_t list
 * @head: a pointer pointing to a pointer to the head of the listint_t list
 * @n: the value of the new node added
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *last_node;

	/*Memory allocation for new node*/

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
	return (new_node);
	}

	last_node = *head;
	while (last_node->next)
		last_node = last_node->next;

	last_node->next = new_node;

	return (new_node);
}
