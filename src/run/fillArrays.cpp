#include "run/fillArrays.hpp"

// Fill the array with certain numbers (positions)
// to generate a random position for the apple
void fillArrays(int* X, int* Y, size_t x, size_t y)
{
    for(size_t i = 0; i < x; ++i)
        X[i] = (i + 2) * 25;

    for (size_t i = 0; i < y; ++i)
        Y[i] = (i + 2) * 25;

}