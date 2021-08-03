/* src/random_word.cpp
 * Implimentation for WordChooser().
 * (c) 2020-2021 Jordan Sola
 * Written by Jordan Sola */

#include "random_word.h"
#include "number_generator.h"

std::string WordChooser(std::vector<std::string> word_container)
{
    int position = GenerateRandomNumber(word_container.size());
    std::string output = word_container.at(position);
    return output;
}