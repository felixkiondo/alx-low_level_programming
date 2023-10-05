#include <stdio.h>

/**
*main - prints all the hexadecimal values
*in lowercase and adds a new line
*Return: Always (0) sucess
*/
int main(void)
{
	int num;

	for (num = 48; num < 58; num++)
		putchar(num);
	for (num = 97; num < 103; num++)
		putchar(num);
	putchar('\n');

	return (0);
}
