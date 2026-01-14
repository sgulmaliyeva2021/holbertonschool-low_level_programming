#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the head of the list
 * @idx: index where the new node should be added (starting at 0)
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int i;

	if (!h)
		return (NULL);

	/* If inserting at the beginning */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Traverse to the node just before the desired index */
	current = *h;
	for (i = 0; current && i < idx - 1; i++)
		current = current->next;

	/* If the previous node doesn't exist, index is out of bounds */
	if (!current)
		return (NULL);

	/* If inserting at the end, reuse add_dnodeint_end */
	if (!current->next)
		return (add_dnodeint_end(h, n));

	/* Allocate new node */
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = current;
	new_node->next = current->next;
	current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}
