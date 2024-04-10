#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 * Return: The first index where value is located. -1
 *         in array or if array is NULL.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t L = 0;
	size_t H = size - 1;
	size_t P;

	if (!array || size == 0)
		return (-1);

	while (value >= array[L] && value <= array[H] && L <= H)
	{
		P = L + (((double)(H - L) / (array[H] - array[L])) *
				(value - array[L]));

		printf("Value checked array[%lu] = [%d]\n", P, array[P]);

		if (array[P] == value)
			return ((int)P);

		if (array[P] < value)
			L = P + 1;
		else
			H = P - 1;
	}

	printf("Value checked array[%lu] is out of range\n", P);
	return (-1);
}
