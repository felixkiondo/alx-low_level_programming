#include "main.h"

/**
 * set_bit - sets the value of a bit at a given index to 1
 * @n: number to set bit value to 1
 * @index: bit index
 *
 * Return: 1 if correct
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	int a;

	a = sizeof(unsigned long int) * 8 - 1;

	if (index > a)
		return (-1);

	*n = *n | (1UL << index);

	return (1);
}
