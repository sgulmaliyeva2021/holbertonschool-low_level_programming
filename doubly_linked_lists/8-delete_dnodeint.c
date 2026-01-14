#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index `index` of a
 * dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node to delete (starting at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i;

	if (!head || !*head)
		return (-1);

	temp = *head;

	/* If we need to delete the head node */
	if (index == 0)
	{
		*head = temp->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* Traverse to the node at position `index` */
	for (i = 0; temp && i < index; i++)
		temp = temp->next;

	if (!temp)
		return (-1);

	/* Re-link previous node */
	if (temp->prev)
		temp->prev->next = temp->next;

	/* Re-link next node */
	if (temp->next)
		temp->next->prev = temp->prev;

	free(temp);
	return (1);
}
