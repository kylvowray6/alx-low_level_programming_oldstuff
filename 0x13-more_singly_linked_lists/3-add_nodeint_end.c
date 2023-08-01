#include "lists.h"
/**
* add_nodeint_end function appends a new node with the given data to the end of a linked list.
* @head: pointer to the first node in the list
* @n: data to be inserted into the new element
* Return: Returns a pointer to the new node if successful, or NULL if the allocation fails.
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;

	return (new);
}
