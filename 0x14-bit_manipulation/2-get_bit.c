#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The unsigned long integer to analyze.
 * @index: The index of the bit to retrieve.
 *
 * Return: Value of the bit at index index or -1 if error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	return ((n >> index) & 1);
}
