#include "check_utility.h"
#include <iostream>

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