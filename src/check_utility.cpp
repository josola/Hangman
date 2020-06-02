#include "check_utility.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cin;

bool CheckAttemptInput(const int input)
{
    if (input < 1 || input > 25)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool CheckWordLengthInput(const int input)
{
    if (input < 2 || input > 14)
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
    vector<char> bad_guesses = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=',
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