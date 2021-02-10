/**
 * is_palindrome - Checks if an integer is a palindrome
 * @n: The number to be checked
 * Return: 1 if integer is a palindrome, otherwhise 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long sum = n % 10, num = n;

	while (num /= 10)
		sum = (sum * 10) + (num % 10);

	return (n == sum);
}
