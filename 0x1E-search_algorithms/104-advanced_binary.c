#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to print
 * @start: The starting index to print from
 * @end: The ending index to print to
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;
	printf("Searching in array: ");
	for (i = start; i <= end; ++i)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary_R - Searches for a value in a sorted array of integers
 * @array: A pointer to the first element of the array to search in.
 * @start: The starting index of the subarray to search in.
 * @end: The ending index of the subarray to search in.
 * @value: The value to search for.
 * Return: The index where value is located or -1 if not found.
 */
int advanced_binary_R(int *array, size_t start, size_t end, int value)
{
	size_t mid = start + (end - start) / 2;

	if (start > end)
		return -1;

	print_array(array, start, end);

	if (array[mid] == value)
	{
		if (mid == 0 || (array[mid - 1] != value))
			return mid;
		else
			return advanced_binary_R(array, start, mid, value);
	}
	else if (array[mid] < value)
	{
		return advanced_binary_R(array, mid + 1, end, value);
	}
	else
	{
		return advanced_binary_R(array, start, mid, value);
	}
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 * Return: The index where value is located or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return -1;

	return advanced_binary_R(array, 0, size - 1, value);
}
