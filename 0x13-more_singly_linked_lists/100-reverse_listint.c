#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *tmp = NULL;
	listint_t *ptr = NULL;

	while (*head)
	{
		ptr = (*head)->next;
		(*head)->next = tmp;
		tmp = *head;
		*head = ptr;
	}

	*head = tmp;

	return (tmp);
}
