#include "main.h"

/**
 * print_binary - prints binary of a number
 * @n: number to be converted and printed in binary
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int num;

	for (i = 0; i <= 63; i++)
	{
		num = n >> i;

		if (num & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
