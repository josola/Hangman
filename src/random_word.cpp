/* src/random_word.cpp
 * Implimentation for WordChooser().
 *
 * (c) 2021 Jordan Sola
 * Written by Jordan Sola
 */

#include "random_word.h"
#include "number_generator.h"

using std::vector;
using std::string;

string WordChooser(vector<string> word_container)
{
    int position = GenerateRandomNumber(word_container.size());
    string output = word_container.at(position);
    return output;
}