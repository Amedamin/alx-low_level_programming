#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	int i, x, n;
	unsigned int int_num = 0;

	if (!b)
		return (0);

	x = strlen(b);

	for (n = 0; b[n]; n++)
	{
		if (b[n] < '0' || b[n] > '1')
			return (0);
	}

	for (i = 0; i < x; i++)
		int_num = int_num * 2 + (b[i] - '0');


	return (int_num);
}
