#include "main.h"

/**
 * print_binary - prints binary of a number
 * @n: number to be converted and printed in binary
 */
void print_binary(unsigned long int n)
{
	int i, j = 0;
	unsigned long int current_num;

	for (i = 0; i <= 0; i++)
	{
		current_num = n >> i;

		if (current_num & 1)
		{
			_putchar('1');
			j++;
		}
		else if (j)
			_putchar('0');
	}
	if (!j)
		_putchar('0');
}
