#include "lists.h"

/**
 * insert_nodeint_at_index - Function inserting a new node in the linked list,
 * @head: the pointer pointing to the first node in the list
 * @idx: the index where the new node is inserted
 * @n: the data to be inserted in the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *temp = *head;
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (head == NULL || new_node == NULL)/* Check if malloc and head failed */

	return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!idx)
	{

		new_node->next = *head;

		*head = new_node;

		return (new_node);
	}

	for (i = 0; temp && i < idx; i++)
	{
	if (i == idx - 1)
	{
		new_node->next = temp->next;
		temp->next = new_node;
	return (new_node);
	}
	else

	temp = temp->next;
	}


	return (NULL);
}
