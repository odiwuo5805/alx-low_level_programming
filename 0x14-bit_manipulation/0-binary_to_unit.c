#include "main.h"
/**
 * binary_to_uint - Converts binary to unsigned int
 *
 * @b: Pointer to string of chars
 *
 * Return: Converted number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int uint, st;
	int len;

	if (!b)
		return (0);

	for (len = 0; b[len]; len++)
		;
	len--;
	for (st = 1, uint = 0; len >= 0; len--)
	{
		if (b[len] == '0')
		{
			st *= 2;
			continue;
		}
		else if (b[len] == '1')
		{
			uint += st;
			st *= 2;
			continue;
		}
		return (0);
	}
	return (uint);
}

