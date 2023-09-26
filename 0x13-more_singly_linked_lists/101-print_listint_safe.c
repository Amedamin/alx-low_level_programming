#include "lists.h"
#include <stdio.h>
size_t looped(const listint_t *head);
size_t print_listint_safe(const listint_t *head);
/**
 * looped - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped(const listint_t *head)
{int i, x, l;
	const listint_t *tmp, *ptr;
	size_t node = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	tmp = head->next;
	ptr = (head->next)->next;

	for (; ptr; i++)
	{

		if (tmp == ptr)
		{
			tmp = head;

			for (; tmp != ptr; x++)
			{
				node++;
				tmp = tmp->next;
				ptr = ptr->next;
			}
			tmp = tmp->next;

			for (; tmp != ptr; l++)
			{
				node++;
				tmp = tmp->next;
			}
			return (node);
		}
		tmp = tmp->next;
		ptr = (ptr->next)->next;
	}
	return (0);
}
/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node, idx = 0;

	node = looped(head);

	if (node == 0)
	{

		for (; head != NULL; node++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{

		for (idx = 0; idx < node; idx++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (node);
}
