#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in 'array'
 * @value: Value to search for
 * Return: The first index where 'value' is located, or -1
 */
int jump_search(int *array, size_t size, int value)
{
	int i, S, P;

	if (!array || size == 0)
		return (-1);

	S = sqrt(size);
	P = 0;

	while (array[P] < value && P < (int)size)
	{
		printf("Value checked array[%d] = [%d]\n", P, array[P]);
		P += S;
	}

	printf("Value found between indexes [%d] and [%d]\n", P - S, P);

	for (i = P - S; i <= P && i < (int)size; ++i)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
