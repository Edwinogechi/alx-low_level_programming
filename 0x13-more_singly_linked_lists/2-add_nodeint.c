#include "lists.h"

/**
 * add_nodeint - function adding a node at the beginning of a listint_t list
 * @head: pointer pointing to a pointer to the head of the listin_t list
 * @n: the value of the new node added
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	while (new_node == NULL)
	return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

