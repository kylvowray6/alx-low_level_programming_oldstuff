#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *k)
{
    size_t num = 0;

    for (; k != NULL; k = k->next)
    {
        printf("%d\n", k->n);
        num++;
    }

    return num;
}
