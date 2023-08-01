#include "lists.h"

/**
 * free_listint_safe - Frees a linked list, even if it contains a loop.
 * @h: Pointer to the first node in the linked list.
 *
 * Return: The number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		if (*h - (*h)->next > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			break;
		}
	}

	return (len);
}
