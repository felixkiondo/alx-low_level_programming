#include <stdio.h>

/**
 * main - prints lower alphabet letters in reverse
 * followed by a new line
 * Return: Always (0) success
*/
int main(void)
{
	int a, b;

	for (a = 122; a >= 97; a--)
	{
		putchar (a);
	}
	putchar ('\n');

	return (0);
}
