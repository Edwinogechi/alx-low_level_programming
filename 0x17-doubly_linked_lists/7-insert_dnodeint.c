#include "lists.h"
/**
 * insert_dnodeint_at_index - Inserts a new node at the specific nth index
 * @h: Double pointer to the head node  of the dlistint_t list
 * @idx: Index of inserting the new node
 * @n: Data value for new node
 *
 * Return: pointer to new node, NULL on Failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current;
	dlistint_t *new;
	unsigned int j = 0;

	if (!h)
		return (NULL);
	/* If the list is present */
	if (*h)
	{
		current = *h;
		/* Iterate to end of list or to the index */
		while (j < idx && current->next)
		{
			current = current->next;
			j++;
		}
		/* If the index is present */
		if (j == idx)
		{
			if (idx == 0)
				return (add_dnodeint(&(*h), n));
			new = malloc(sizeof(dlistint_t));/* Malloc new node*/
			if (!new)
				return (NULL);
			new->n = n;
			new->next = current;
			new->prev = current->prev;
			current->prev->next = new;
			current->prev = new;
			return (new);
		}
		if (j + 1 == idx)/* If the index is present at the end of the list */
			return (add_dnodeint_end(&(*h), n));
	}
	else
		/* Whether index is 0 and the list is empty */
		if (idx == 0)
			return (add_dnodeint(&(*h), n));

	return (NULL);/* Return NULL if the index is not found */
}
