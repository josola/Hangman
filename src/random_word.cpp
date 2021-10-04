/* 
 * Implimentation for WordChooser().
 * (c) 2020-2021 Jordan Sola. All rights reserved. (MIT License)
 * Written by Jordan Sola 2020-2021
 */

#include "random_word.h"
#include "number_generator.h"

std::string WordChooser(std::vector<std::string> word_container) {

	int position = GenerateRandomNumber(word_container.size());
	std::string output = word_container.at(position);

	return output;
}