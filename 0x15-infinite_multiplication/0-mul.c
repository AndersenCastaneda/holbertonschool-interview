#include "holberton.h"

/**
 * _print - print a string
 * @str: string to print
 */
void _print(char *str)
{
	int i;

	for (i = 0; str[i]; ++i)
		_putchar(str[i]);

	_putchar('\n');
}

/**
 * _len - check if a string is a number
 * @str: string to check
 * Return: length of the string
 */
int _len(char *str)
{
	int i, len = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			_print("Error\n");
			exit(98);
		}

		++len;
	}

	return (len);
}

/**
 * _malloc - allocate a string
 * @len1: string len1
 * @len2: string len2
 * Return: pointer to the string allocated
 */
char *_malloc(int len1, int len2)
{
	int i, len = len1 + len2;
	char *result = malloc(len);

	if (!result)
	{
		_print("Error\n");
		exit(98);
	}

	for (i = 0; i < len; i++)
		result[i] = '0';

	return (result);
}

/**
 * _multiply - multiplies
 * @num1: first number.
 * @num2: second number.
 * @len1: length of num1.
 * @len2: length of num2.
 * Return: result of multiplies.
 */
char *_multiply(char *num1, char *num2, int len1, int len2)
{
	int i, j, carry;
	char *result = _malloc(len1, len2);

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			carry += (num1[i] - '0') * (num2[j] - '0');
			carry += result[i + j + 1] - '0';
			result[i + j + 1] = (carry % 10) + '0';
			carry /= 10;
		}

		if (carry)
			result[i + j + 1] = (carry % 10) + '0';
	}

	return (result);
}

/**
 * main - program entry point
 * @argv: arguments vector
 * @argc: arguments count
 * Return: 0 if success otherwise 98 and print Error.
 */
int main(int argc, char *argv[])
{
	int len1 = 0, len2 = 0;
	char *result = NULL;

	if (argc != 3)
	{
		_print("Error");
		exit(98);
	}

	len1 = _len(argv[1]);
	len2 = _len(argv[2]);

	result = _multiply(argv[1], argv[2], len1, len2);

	if (result[0] == '0')
		_print(result + 1);
	else
		_print(result);

	free(result);
	return (0);
}
