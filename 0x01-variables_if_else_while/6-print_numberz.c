#include <stdio.h>
/**
 * main - Entry point
 * Description: 'print all base 10 numbers without using char'
 * Return: Always 0 (Successs)
 */
int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		putchar(n + 48);
	}
	putchar('\n');
	return (0);
}
