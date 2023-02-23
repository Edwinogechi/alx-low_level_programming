#include "main.h"
/**
 *  positive_or_negative - checkinf if a number is positive or negative
 *
 *  @i: the number being checked
 *
 *  Return: always 0 on success
 */


void positive_or_negative(int i)
{
	if (i < 0)
		printf("%d is negative\n", i);
	else if (i > 0)
		printf("%d is positive\n", i);
}
