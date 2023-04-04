#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a linked list,
 * and returns the head node’s data (n).
 * @head: A double pointer to the head of the listint_t list.
 * Return: the data in the deleted head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (!head || !*head)
	return (0);

	data = (*head)->n;

	temp = (*head)->next;

	free(*head);

	*head = temp;

	return (data);

}

