/**
 * is_palindrome - Checks if an integer is a palindrome
 * @n: The number to be checked
 * Return: 1 if integer is a palindrome, otherwhise 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long sum = 0, num = n;
	int unit;

	while (num)
	{
		unit = num % 10;
		sum = sum * 10 + unit;
		num /= 10;
	}

	return (n == sum);
}
