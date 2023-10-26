#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int value1, value2;

	value2 = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		value1 = value2 >> i;
		if (value1 & 1)
			count++;
	}

	return (count);
}
