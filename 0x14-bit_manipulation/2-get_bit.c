#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to determine bit value
 * @index: bit index
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int value;

	if (index > 63)
		return (-1);

	value = ((n >> index) & 1);

	return (value);
}
