#include "check_utility.h"
#include <iostream>

using std::cin;

bool CheckIntInput(const int input)
{
    if (!cin)
    {
        return false;
    }
    else
    {
        return true;
    }
}