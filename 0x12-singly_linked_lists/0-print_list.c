#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all elements
 * @h: pointer
 *
 * Return: number of node
 */
size_t print_list(const list_t *r)
{
	size_t s = 0;

	while (r)
	{
		if (!r->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", r->len, r->str);
		r = r->next;
		s++;
	}

	return (s);
}
