#include <stdio.h>
/**
 * main - Entry point
 * description 'print single digit number'
 * return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		printf("%d", n);
	}
	printf("\n");
	return (0);
}
