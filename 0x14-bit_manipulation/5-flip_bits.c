#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int Result = n ^ m;

	return (countSetBits(Result));
}

/**
 * countSetBits - counts the number of set bits (1s)
 * @num: the integer for which set bits are counted
 *
 * Return:
 *   The count of set bits in the binary representation of 'num'.
 */

int countSetBits(int num)
{
	int count = 0;

	while (num)
	{
		count += num & 1;
		num >>= 1;
	}
	return (count);
}
