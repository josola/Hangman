/*
 * Hangman
 * Program that lets you play a text version of Hangman.
 * Written by Jordan Sola 2020
 * This program uses the MIT license.
 */

#include <iostream>
#include <limits>
#include <algorithm>
#include "read_file.h"
#include "read_file.h"
#include "random_word.h"
#include "check_utility.h"

using std::any_of;
using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

/* 
 * -- TO-DO --
 * Add functionality for checking duplicate guesses
 */

int main()
{
    cout << "Starting a new game of hangman..." << endl;

    cout << endl;

    int failed_attempts = 0;
    cout << "How many failed attempts do you need? [1-25] ";
    cin >> failed_attempts;

    //error handling for attempt input
    int remaining_attempts = 0;
    bool correct_attempt_input = false;
    while (!correct_attempt_input)
    {
        if (!cin)
        {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> failed_attempts;
        }
        else if (!CheckAttemptInput(failed_attempts))
        {
            cout << "Please enter a number between 1 and 25!" << endl;
            cin >> failed_attempts;
        }
        else
        {
            remaining_attempts = failed_attempts;
            correct_attempt_input = true;
        }
    }

    cout << endl;

    int word_length = 0;
    cout << "How many letters do you want in your word? [2-14] ";
    cin >> word_length;

    //error handling for word length input
    bool correct_word_input = false;
    while (!correct_word_input)
    {
        if (!cin)
        {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> word_length;
        }
        else if (!CheckWordLengthInput(word_length))
        {
            cout << "Please enter a number between 2 and 14!" << endl;
            cin >> word_length;
        }
        else
        {
            correct_word_input = true;
        }
    }

    cout << endl;

    cout << "Generating a word for you..." << endl;

    cout << endl;

    //get word from source text file
    string word = "";
    switch (word_length)
    {
    case 2:
    {
        word = WordChooser(AcquireFileContents("src/words/two_letter_words.txt"));
        break;
    }
    }

    //Create a holder for '#' to be replaced by correct guesses.
    vector<char> word_holder;
    for (string::size_type i = 0; i < word.size(); i++)
    {
        word_holder.push_back('#');
    }

    //game state
    bool game_over = false;
    bool correct = false;
    int total_attempts = 0;

    //game variables
    vector<char> previous_guesses;
    char guess = ' ';

    //game loop
    while (!game_over)
    {
        if (any_of(word_holder.begin(), word_holder.end(), [](char i) { return i == '#'; }))
        {
            cout << "Word: ";
            for (size_t i = 0; i < word_holder.size(); i++)
            {
                cout << word_holder[i];
            }

            cout << endl;

            if (previous_guesses.empty())
            {
                cout << "First guess: ";
                cin >> guess;

                //error handling for guess input
                bool correct_guess = false;
                while (!correct_guess)
                {
                    if (!CheckGuessInput(guess))
                    {
                        cout << "Invalid input!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> guess;
                    }
                    else
                    {
                        correct_guess = true;
                    }
                }
                //track previous guesses
                previous_guesses.push_back(guess);
            }
            else
            {
                if (remaining_attempts != failed_attempts)
                {
                    if (remaining_attempts == 1)
                    {
                        cout << "One failed attempt remaining!" << endl;
                    }
                    else if (remaining_attempts == 0)
                    {
                        cout << "You ran out of attempts!" << endl;
                        cout << "Better luck next time." << endl;

                        cout << endl;

                        cout << "Game over..." << endl;
                        return 0;
                    }
                    else
                    {
                        cout << "Failed attempts remaining: " << remaining_attempts << endl;
                    }
                }
                if (previous_guesses.size() < 2)
                {
                    cout << "Previous guess: " << previous_guesses[0] << endl;
                }
                else
                {
                    cout << "Previous guesses: ";
                    for (size_t i = 0; i < previous_guesses.size(); i++)
                    {
                        if (i != previous_guesses.size() - 1)
                        {
                            cout << previous_guesses[i] << ", ";
                        }
                        else
                        {
                            cout << previous_guesses[i] << endl;
                        }
                    }
                }
                cout << "Next guess: ";
                cin >> guess;

                //error handling for guess input
                bool correct_guess = false;
                while (!correct_guess)
                {
                    if (!CheckGuessInput(guess))
                    {
                        cout << "Invalid input!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> guess;
                    }
                    //duplicate guess
                    else if (any_of(previous_guesses.begin(), previous_guesses.end(), [guess](char i) { return i == guess; }))
                    {
                        cout << guess << " has already been guessed!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Next guess: ";
                        cin >> guess;
                    }
                    else
                    {
                        correct_guess = true;
                    }
                }
                //track previous guesses
                previous_guesses.push_back(guess);
            }

            //check guess against word
            for (size_t i = 0; i < word.size(); i++)
            {
                if (word[i] == guess)
                {
                    word_holder[i] = guess;
                    correct = true;
                }
            }

            //output appropriate guess prompt
            if (correct)
            {
                correct = false;
            }
            else
            {
                cout << guess << " is NOT in your word!" << endl;
                remaining_attempts--;
            }
            total_attempts++;

            cout << endl;
        }
        else
        {
            cout << "Word: ";
            for (size_t i = 0; i < word_holder.size(); i++)
            {
                cout << word_holder[i];
            }
            cout << endl;
            cout << "You guessed your word!" << endl;
            cout << "Total attempts: " << total_attempts << endl;
            cout << "Leftover failed attempts: " << remaining_attempts << endl;

            cout << endl;

            cout << "Game Over." << endl;
            return 0;
        }
    }
    return 0;
}