#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node in a linked list at a certain index.
 * @head: Pointer to the first element in the list.
 * @index: Index of the node to delete.
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	listint_t *prev = *head;
	listint_t *current = (*head)->next;
	unsigned int i = 1;

	while (current && i < index)
	{
		prev = current;
		current = current->next;
		i++;
	}

	if (!current)
		return (-1);

	prev->next = current->next;
	free(current);
	return (1);
}
