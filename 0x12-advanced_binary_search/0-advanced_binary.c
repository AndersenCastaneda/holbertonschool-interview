#include "search_algos.h"

/**
 * advanced_binary - Search a value in an array
 * @array: The array to search in
 * @size: The array's size
 * @value: The value to search for
 * Return: the index of the first value in the array
 * (if this value appears more than once in the array)
 * otherwise returns -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid, idx = 0;
	int ret = -1;

	if (!array || size == 0)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; ++i)
		printf(i < size - 1 ? "%d, " : "%d\n", array[i]);

	if (size == 1 && array[0] != value)
		return (-1);

	mid = (size - 1) / 2;
	if (array[mid] == value && array[mid - 1] != value)
		return (mid);

	if (array[mid] < value)
	{
		idx += mid + 1;
		array += mid + 1;
		if (size % 2 != 0)
			mid--;
	}
	mid++;
	ret = advanced_binary(array, mid, value);
	if (ret != -1)
		return (ret);

	return (ret);
}
