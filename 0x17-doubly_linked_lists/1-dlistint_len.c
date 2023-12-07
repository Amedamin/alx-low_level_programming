#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked lists
 * @h: linked list of type listint_t to traverse
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)

{
	int i = 0;

	for (; h ;)
	{
		i++;
		h = h->next;
	}

	return (i);
}
