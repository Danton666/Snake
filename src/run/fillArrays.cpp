#include "run/fillArrays.hpp"

void fillArrays(int* X, int* Y, size_t x, size_t y)
{
	for(size_t i = 0; i < x; ++i)
		X[i] = (i + 3) * 25;

	for (size_t i = 0; i < y; ++i)
		Y[i] = (i + 3) * 25;
}