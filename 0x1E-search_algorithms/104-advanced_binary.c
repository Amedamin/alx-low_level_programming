#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers * @array: Pointer to the first element of the array to search in * @size: Number of elements in array * @value: Value to search
 *
 * Return: The index where value is located, or -1 if not
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int index;

	if (!array || size == 0)
		return -1;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");

	if (size == 1)
	{
		if (array[0] == value)
			return 0;

		return -1;
	}

	index = size / 2;

	if (array[index] == value)
	{
		if (array[index - 1] < value)
			return index;
	}

	if (array[index] < value)
	{
		int sub_index = advanced_binary(array + index + 1, size - index - 1, value);
		if (sub_index == -1)
			return -1;
		return index + 1 + sub_index;
	}
	else    {
		return advanced_binary(array, index, value);
	}
}
