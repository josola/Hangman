/* 
 * Implimentation for GenerateRandomNumber().
 * (c) 2020-2021 Jordan Sola. All rights reserved. (MIT License)
 * Written by Jordan Sola 2020-2021
 */

#include <random>

#include "number_generator.h"

int GenerateRandomNumber(unsigned int range) {

	srand(static_cast<unsigned int>(time(NULL)));
	int output(rand() % range + 1);
	
	return output;

}