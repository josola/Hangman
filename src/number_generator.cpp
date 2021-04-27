/* src/number_generator.cpp
 * Implimentation for GenerateRandomNumber().
 *
 * (c) 2021 Jordan Sola
 * Written by Jordan Sola
 */

#include "number_generator.h"
#include <random>

int GenerateRandomNumber(unsigned int range)
{
    srand(static_cast<unsigned int>(time(NULL)));
    int output(rand() % range + 1);
    return output;
}