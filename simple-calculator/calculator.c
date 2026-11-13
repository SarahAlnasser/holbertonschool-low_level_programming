#include <stdio.h>

/*
 * Simple Calculator
 *
 * Number type: the calculator uses decimals (double) for every
 * operation, so the behavior is consistent: 10 / 4 gives 2.5.
 * Results are printed with %g, which drops useless trailing zeros,
 * so 10 + 25 prints 35 and not 35.000000.
 */

/**
 * clear_line - discards the rest of the current input line
 */
void clear_line(void)
{
	int c;

	c = getchar();
	while (c != '\n' && c != EOF)
		c = getchar();
}

/**
 * print_menu - prints the calculator menu
 */
void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
}

/**
 * read_number - prompts for and reads a number
 * @label: the prompt to print, such as "A: "
 * @n: where to store the number
 *
 * Return: 1 on success, 0 on end of input
 */
int read_number(char *label, double *n)
{
	int ret;

	while (1)
	{
		printf("%s", label);
		ret = scanf("%lf", n);
		if (ret == 1)
			return (1);
		if (ret == EOF)
			return (0);
		clear_line();
		printf("Invalid number\n");
	}
}

/**
 * calculate - runs one operation for a menu choice
 * @choice: the operation, from 1 to 4
 *
 * Return: 1 on success, 0 on end of input
 */
int calculate(int choice)
{
	double a;
	double b;

	if (!read_number("A: ", &a) || !read_number("B: ", &b))
		return (0);

	if (choice == 1)
		printf("Result: %g\n", a + b);
	else if (choice == 2)
		printf("Result: %g\n", a - b);
	else if (choice == 3)
		printf("Result: %g\n", a * b);
	else if (b == 0)
		printf("Error: division by zero\n");
	else
		printf("Result: %g\n", a / b);

	return (1);
}

/**
 * main - runs the menu loop until the user quits
 *
 * Return: Always 0
 */
int main(void)
{
	int choice;
	int ret;

	printf("Simple Calculator\n");
	while (1)
	{
		print_menu();
		printf("Choice: ");
		ret = scanf("%d", &choice);
		if (ret == EOF)
			break;
		if (ret != 1)
		{
			clear_line();
			printf("Invalid choice\n");
			continue;
		}
		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}
		if (!calculate(choice))
			break;
	}

	return (0);
}
