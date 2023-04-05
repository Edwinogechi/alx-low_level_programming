#include "lists.h"

/**
 * free_listint_safe - A function that frees a listint_t list
 * @h: A pointer pointing to a pointer to the head of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *temp;

	/* Iterate through and check for a null pointer*/
	if (!h || !*h)
		return (0);
	/* Go through the list and free every node available*/

	while (*h)
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
		len++;

	/* Confirm if the current node is freed then set the rest to NULL*/

	if ((*h)->next >= *h && *h != NULL)
	{
		(*h)->next = NULL;
		*h = NULL;
		return (len);

	}

	}
	/* set head to NULL and  return the length of the list */
	*h = NULL;
	return (len);
}
