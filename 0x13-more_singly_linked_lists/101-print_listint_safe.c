#include "lists.h"
#include <stdio.h>

/**
 * looped_listint_len - Function that counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer pointing to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes present in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t nodes = 1;

	/* If the list is empty, terminate */
	if (head == NULL || head->next == NULL)
	return (0);

	/*Initialize the *slow,*fast to the second and third nodes, respectively*/
	slow = head->next;
	fast = (head->next)->next;

	/* Traverse the list til the *fast terminates */
	while (fast)
	{
	/* Incase the *slow and *fast meet, the loop is presesnt in the list */
	if (slow == fast)
	{
		/* Interchange the *slow to the head of the list */
		slow = head;

		/* Count the number of node til they meet again*/
		while (slow != fast)
		{
			nodes++;
			slow = slow->next;
			fast = fast->next;
		}

		/* Count the number of nodes outside the loop til they meet again */
		slow = slow->next;
		while (slow != fast)
		{
			nodes++;
			slow = slow->next;
		}

		/* Return the total number of nodes in the list */
		return (nodes);
	}

	/* Advance the *slow by one node and the *fast by two nodes */
	slow = slow->next;
	fast = (fast->next)->next;
	}

	/* Incase the *fast reaches the end of the list, there is no loop */
	return (0);
}

/**
 * print_listint_safe - A function that prints a listint_t list safely.
 * @head: A pointer pointing to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	/* Check if the list is looped and count the number of nodes*/
	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
	/* If not looped, print all the nodes*/
	for (; head != NULL; nodes++)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	}
	else
	{
	/* If the list is looped, print the nodes before the loop starts */
	for (index = 0; index < nodes; index++)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	printf("-> [%p] %d\n", (void *)head, head->n);
	}

	/* Return the total number of nodes in the linked list */
	return (nodes);
}

