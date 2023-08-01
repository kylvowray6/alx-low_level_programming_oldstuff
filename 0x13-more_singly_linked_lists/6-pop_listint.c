#include "lists.h"

/**
 * pop_listint - Deletes the Head node of a linked list
 * @head: Pointer to the First element in the linked list
 *
 * Return: The data inside the element that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num = 0;

	if (head == NULL || *head == NULL)
		return (num);

	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num);
}
