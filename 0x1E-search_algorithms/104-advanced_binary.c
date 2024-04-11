#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to print
 * @S: The starting index to print from
 * @E: The ending index to print to
 */
void print_array(int *array, size_t S, size_t E)
{
	size_t i = S;

	printf("Searching in array: ");
	while (i <= E)
	{
		printf("%d", array[i]);
		if (i < E)
			printf(", ");
		++i;
	}
	printf("\n");
}

/**
 * advanced_binary_R - Searches for a value in a sorted array of integers
 * @array: A pointer to the first element of the array to search in.
 * @S: The starting index of the subarray to search in.
 * @E: The ending index of the subarray to search in.
 * @value: The value to search for.
 * Return: The index where value is located or -1 if not found.
 */
int advanced_binary_R(int *array, size_t S, size_t E, int value)
{
	size_t M = S + (E - S) / 2;

	if (S > E)
		return (-1);

	print_array(array, S, E);

	if (array[M] == value)
	{
		if (M == 0 || (array[M - 1] != value))
			return (M);
		else
			return (advanced_binary_R(array, S, M, value));
	}
	else if (array[M] < value)
	{
		return (advanced_binary_R(array, M + 1, E, value));
	}
	else
	{
		return (advanced_binary_R(array, S, M, value));
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
		return (-1);

	return (advanced_binary_R(array, 0, size - 1, value));
}
