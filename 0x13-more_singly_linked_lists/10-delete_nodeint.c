#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *ptr = *head;
	listint_t *tmp = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		(*head) = ptr->next;
		free(ptr);
		return (1);
	}
	for (; i < index - 1; i++)
	{
		if (!ptr || !(ptr->next))
			return (-1);
		ptr = ptr->next;
	}
	tmp = ptr;
	ptr = ptr->next;
	tmp->next = ptr->next;
	free(ptr);
	return (1);
}
