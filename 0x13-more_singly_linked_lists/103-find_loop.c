#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{int i = 0;
	listint_t *tmp = head;
	listint_t *ptr = head;

	if (!head)
		return (NULL);

	for (; tmp && ptr && ptr->next; i++)
	{
		ptr = ptr->next->next;
		tmp = tmp->next;

		if (ptr == tmp)
		{
			tmp = head;

			while (tmp != ptr)
			{
				tmp = tmp->next;
				ptr = ptr->next;
			}
			return (ptr);
		}
	}
	return (NULL);
}
