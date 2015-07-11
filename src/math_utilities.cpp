#include "math_utilities.h"

int MathUtilities::Factorial(int n)
{
	int result = 1;
	for (int i = n; i > 1; --i)
	{
		result *= i;
	}

	return result;
}
