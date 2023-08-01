#include "lists.h"
/**
* get_nodeint_at_index - Returns the node at the specified index in a linked list.
* @head: Pointer to the first node in the linked list.
* @index: Index of the node to retrieve.
* Return: A pointer to the node at the given index, or NULL if the index is out of bounds.
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (i < index && temp)
	{
		temp = temp->next;
		i++;
	}

	return (temp);
}
