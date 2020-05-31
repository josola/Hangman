#include "random_word.h"
#include "number_generator.h"

string WordChooser(vector<string> word_container)
{
    int position = GenerateRandomNumber(word_container.size());
    string output = word_container.at(position);
    return output;
}