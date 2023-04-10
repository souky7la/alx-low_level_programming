#include "main.h"
/**
 * flip_bits - function that returns number of bits needed to flip to get
 * from one number to another.
 *@n: unsigned long int
 *@m: unsigned long int
 *You are not allowed to use the % or / operators
 *Return: number of bits needed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int flip = 0;
	int i = 0;
	int size = ((sizeof(n) * 8) - 1);

	for (; i <= size; i++)
	{
		if (((n ^ m) >> i)  & 1)
			flip++;
	}

	return (flip);
}
