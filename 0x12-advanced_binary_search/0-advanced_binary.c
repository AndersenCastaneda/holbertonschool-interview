#include "search_algos.h"
#include <unistd.h>

/**
 * print_array - Prints an array
 * @array: Array to print
 * @start: Start point of the array
 * @end: End point of the array
 */
void print_array(int *array, size_t start, size_t end)
{
	printf("Searching in array: ");
	for (; start <= end; start++)
	{
		if (start < end)
			printf("%d, ", array[start]);
		else
			printf("%d\n", array[start]);
	}
}

/**
 * binary_search_recursive - binary algorithm in recursion
 * @array: The array to search in
 * @value: Value to search for
 * @start: Start of the array
 * @end: End of the array
 * Return: The index where value was found, if the value
 * is not found or array is null return -1
 */
int binary_search_recursive(int *array, int value, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;

	print_array(array, start, end);
	if (start == end && value != array[start])
		return (-1);

	if (value == array[mid])
	{
		if (mid > 0 && array[mid - 1] == value)
			return (binary_search_recursive(array, value, start, mid));
		else
			return (mid);
	}
	else if (value < array[mid])
		return (binary_search_recursive(array, value, start, mid - 1));
	else
		return (binary_search_recursive(array, value, mid + 1, end));
}

/**
 * advanced_binary - Searches for a value in a sorted array
 * of integers using the Binary search algorithm
 * @array: The array to search in
 * @size: Lenght of the array
 * @value: Value to search for
 * Return: The index where value was found, if the value
 * is not found or array is null return -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	int ret = -1;

	if (array && size > 0)
		ret = binary_search_recursive(array, value, 0, size - 1);

	return (ret);
}
