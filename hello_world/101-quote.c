#include <unistd.h>

/**
 * main - Writes a quote to the standard error
 *
 * Return: Always 1
 */
int main(void)
{
	char first[] = "and that piece of art is useful\" - ";
	char second[] = "Dora Korpar, 2015-10-19\n";

	write(2, first, sizeof(first) - 1);
	write(2, second, sizeof(second) - 1);
	return (1);
}
