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

    cout << endl;

    int failed_attempts = 0;
    cout << "How many failed attempts do you need? [1-25] ";
    cin >> failed_attempts;

    cout << endl;
    
    int word_length = 0;
    cout << "How many letters do you want in your word? [1-25] ";
    cin >> word_length;

    cout << endl;

    cout << "Generating a word for you..." << endl;

    cout << endl;

    return 0;
}