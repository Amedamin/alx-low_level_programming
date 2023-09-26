#include "lists.h"
/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{int i = 0;
	size_t num = 0;
	int tmp;
	listint_t *ptr;

	if (!h || !*h)
		return (0);

	for (; *h; i++)
	{
		tmp = *h - (*h)->next;

		if (tmp > 0)
		{
			ptr = (*h)->next;
			free(*h);
			*h = ptr;
			num++;
		}

		else
		{
			free(*h);
			*h = NULL;
			num++;
			break;
		}
	}
	*h = NULL;
	return (num);
}
