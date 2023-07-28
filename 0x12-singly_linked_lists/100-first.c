#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * prints sentence
 * cod ethat prints
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("bore my house upon my back!\n");
}
