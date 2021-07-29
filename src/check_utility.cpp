/* src/check_utility.cpp
 * Implimentation for checking utilities.
 *
 * (c) 2021 Jordan Sola
 * Written by Jordan Sola
 */

#include "check_utility.h"
#include <iostream>
#include <vector>

bool CheckAttemptInput(const unsigned int input)
{
    int min = 1;
    int max = 25;

    if (input < min || input > max)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool CheckWordLengthInput(const unsigned int input)
{
    int min = 2;
    int max = 14;

    if (input < min || input > max)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool CheckGuessInput(const char input)
{
    std::vector<char> bad_guesses = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=',
    ',', '.', '/', '<', '>', '?', ';', ':', '[', ']',
    '{', '}', '|', '`', '~'
    };

    bool output = false;
    for (size_t i = 0; i < bad_guesses.size(); i++)
    {
        if (input == bad_guesses[i])
        {
            return false;
        }
        else
        {
            output = true;
        }
    }
    return output;
}