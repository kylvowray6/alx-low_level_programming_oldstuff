#include "lists.h"

/**
 * free_listint - Frees a linked list
 * @head: listint_t List to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *current = head;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
