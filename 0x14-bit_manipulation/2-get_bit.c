#include "main.h"
/**
 * get_bit - Write a function that returns the value of a bit at a given index.
 * @n: unsigned long int
 * @index: index is the index, starting from 0 of the bit you want to get
 * Return: the value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	n = n >> index;

	if (n == 0)
		return (0);

	else if (!n)
		return (-1);

	else if (index > (sizeof(n) * 8) - 1)
		return (-1);

	else if (n)
	{
		n = n % 2;
		return (n);
	}

	else
		return (-1);
}
