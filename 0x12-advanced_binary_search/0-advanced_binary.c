#include "search_algos.h"

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
	size_t i, mid = start + (end - start) / 2;

	printf("Searching in array: ");
	for (i = start; i <= end; ++i)
		printf(i < end ? "%d, " : "%d\n", array[i]);

	if (start == end)
		return (-1);

	if (start <= end)
	{

		if (array[mid] == value && array[mid - 1] != value)
			return (mid);

		if (array[mid] >= value)
			return (binary_search_recursive(array, value, start, mid));

		if (array[mid] <= value)
			return (binary_search_recursive(array, value, mid + 1, end));
	}
	return (-1);
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
	if (!array || size == 0)
		return (-1);

	return (binary_search_recursive(array, value, 0, size - 1));
}
