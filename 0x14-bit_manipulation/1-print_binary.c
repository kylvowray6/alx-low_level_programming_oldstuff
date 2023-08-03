#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int size = sizeof(n) * 8;
	int leading_zeros = 1;
	int i;

	mask <<= (size - 1);

	for (i = 0; i < size; i++)
	{
		if ((n & mask) != 0)
		{
			leading_zeros = 0;
			_putchar('1');
		}
		else if (!leading_zeros || i == size - 1)
		{
			_putchar('0');
		}

		if (i < size - 1)
			mask >>= 1;
	}
}
