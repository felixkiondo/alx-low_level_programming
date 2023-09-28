#include "main.h"

/**
 * set_bit - sets the value of a bit at a given index to 1
 * @n: number to set bit value to 1
 * @index: bit index
 *
 * Return: (1) if successful (-1) if unsuccessful
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = *n | (1UL << index);

	return (1);
}
