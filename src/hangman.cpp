/*
 * Hangman
 * Program that lets you play a text version of Hangman.
 * Written by Jordan Sola 2020
 * This program uses the MIT license.
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    cout << "Starting a new game of hangman..." << endl;

    int failed_attempts = 0;
    cout << "How many failed attempts do you need? [1-25] ";
    cin >> failed_attempts;
    
    return 0;
}