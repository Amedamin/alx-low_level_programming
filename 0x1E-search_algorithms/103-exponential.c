#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 * Return: The first index where value is located. -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i , M, B, L, H;
	if (!array || size == 0)
		return (-1);

	if (array[0] == value)
	{
		printf("Value checked array[0] = [%d]\n", array[0]);
		return (0);
	}

	B = 1;
	while (B < size && array[B] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", B, array[B]);
		B *= 2;
	}

	L = B / 2;
	H = (B < size) ? B : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", L, H);

	while (L <= H)
	{
		M = L + (H - L) / 2;
		printf("Searching in array: ");
		for (i = L; i <= H; ++i)
		{
			printf("%d", array[i]);
			if (i < H)
				printf(", ");
		}
		printf("\n");

		if (array[M] == value)
			return ((int)M);

		if (array[M] < value)
			L = M + 1;
		else
			H = M - 1;
	}

	return (-1);
}
