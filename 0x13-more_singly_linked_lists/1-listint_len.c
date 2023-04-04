#include "lists.h"

/**
 * listint_len - a function that returns the elements in a listint_t list
 * @h: a pointer to the head of the listint_t list
 * Return: the number of nodes in the listint_t list
 */
size_t listint_len(const listint_t *h)
{
	size_t numb = 0;

	while (h != NULL)
	{
		h = h->next;
		numb++;
	}

	return (numb);
}
