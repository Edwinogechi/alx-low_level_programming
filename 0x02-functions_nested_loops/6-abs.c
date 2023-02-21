#include "main.h"

/**
 * _abs - find absolute value
 *
 * @z: parameter being checked
 * Return: always z
 */

int _abs(int z)
{
	if (z < 0)
		z = -(z);
	else if (z >= 0)
		z = z;
	return (z);

}
