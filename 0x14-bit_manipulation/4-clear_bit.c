#include "main.h"

/**
 * clear_bit - sets the value of a bit at a given index to 0
 * @n: number to clear bit value to 0
 * @index: bit index
 *
 * Return: (1) if successful (-1) if unsuccessful
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = *n & ~(1UL << index);

	return (1);
}
