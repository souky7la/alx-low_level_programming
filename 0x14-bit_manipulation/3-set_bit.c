#include "main.h"
/**
 * set_bit - a function that sets the value of a bit to 1 at a given index
 *@n: unsigned long int *
 *@index: unsigned int, is the index, starting from 0 of the bit to set
 *Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == 0)
		return (-1);

	else if (!n)
		return (-1);

	else if (index > (sizeof(*n) * 8) - 1)
		return (-1);

	else
		*n = *n | 1 << index;

	return (1);
}
