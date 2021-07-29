/* src/main.cpp
 * Program that lets you play a text version of Hangman.
 *
 * (c) 2021 Jordan Sola
 * Written by Jordan Sola
 */

#include <iostream>
#include <limits>
#include <algorithm>
#include "read_file.h"
#include "read_file.h"
#include "random_word.h"
#include "check_utility.h"

/* 
 * -- TO-DO --
 * Add functionality for checking duplicate guesses
 */

int main()
{
    std::cout << "Starting a new game of hangman..." << std::endl;

    std::cout << std::endl;

    int failed_attempts = 0;
    std::cout << "How many failed attempts do you need? [1-25] ";
    std::cin >> failed_attempts;

    //error handling for attempt input
    int remaining_attempts = 0;
    bool correct_attempt_input = false;
    while (!correct_attempt_input)
    {
        if (!std::cin)
        {
            std::cout << "Invalid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> failed_attempts;
        }
        else if (!CheckAttemptInput(failed_attempts))
        {
            std::cout << "Please enter a number between 1 and 25!" << std::endl;
            std::cin >> failed_attempts;
        }
        else
        {
            remaining_attempts = failed_attempts;
            correct_attempt_input = true;
        }
    }

    std::cout << std::endl;

    int word_length = 0;
    std::cout << "How many letters do you want in your word? [2-14] ";
    std::cin >> word_length;

    //error handling for word length input
    bool correct_word_input = false;
    while (!correct_word_input)
    {
        if (!std::cin)
        {
            std::cout << "Invalid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> word_length;
        }
        else if (!CheckWordLengthInput(word_length))
        {
            std::cout << "Please enter a number between 2 and 14!" << std::endl;
            std::cin >> word_length;
        }
        else
        {
            correct_word_input = true;
        }
    }

    std::cout << std::endl;

    std::cout << "Generating a word for you..." << std::endl;

    std::cout << std::endl;

    //get word from source text file
    std::string word = "";
    switch (word_length)
    {
    case 2:
    {
        word = WordChooser(AcquireFileContents("src/words/two_letter_words.txt"));
        break;
    }
    case 3:
    {
        word = WordChooser(AcquireFileContents("src/words/three_letter_words.txt"));
        break;
    }
    case 4:
    {
        word = WordChooser(AcquireFileContents("src/words/four_letter_words.txt"));
        break;
    }
    case 5:
    {
        word = WordChooser(AcquireFileContents("src/words/five_letter_words.txt"));
        break;
    }
    case 6:
    {
        word = WordChooser(AcquireFileContents("src/words/six_letter_words.txt"));
        break;
    }
    case 7:
    {
        word = WordChooser(AcquireFileContents("src/words/seven_letter_words.txt"));
        break;
    }
    case 8:
    {
        word = WordChooser(AcquireFileContents("src/words/eight_letter_words.txt"));
        break;
    }
    case 9:
    {
        word = WordChooser(AcquireFileContents("src/words/nine_letter_words.txt"));
        break;
    }
    case 10:
    {
        word = WordChooser(AcquireFileContents("src/words/ten_letter_words.txt"));
        break;
    }
    case 11:
    {
        word = WordChooser(AcquireFileContents("src/words/eleven_letter_words.txt"));
        break;
    }
    case 12:
    {
        word = WordChooser(AcquireFileContents("src/words/twelve_letter_words.txt"));
        break;
    }
    case 13:
    {
        word = WordChooser(AcquireFileContents("src/words/thirteen_letter_words.txt"));
        break;
    }
    case 14:
    {
        word = WordChooser(AcquireFileContents("src/words/fourteen_letter_words.txt"));
        break;
    }
    }

    //Create a holder for '#' to be replaced by correct guesses.
    std::vector<char> word_holder;
    for (std::string::size_type i = 0; i < word.size(); i++)
    {
        word_holder.push_back('#');
    }

    //game state
    bool game_over = false;
    bool correct = false;
    int total_attempts = 0;

    //game variables
    std::vector<char> previous_guesses;
    char guess = ' ';

    //game loop
    while (!game_over)
    {
        if (any_of(word_holder.begin(), word_holder.end(), [](char i) { return i == '#'; }))
        {
            std::cout << "Word: ";
            for (size_t i = 0; i < word_holder.size(); i++)
            {
                std::cout << word_holder[i];
            }

            std::cout << std::endl;

            if (previous_guesses.empty())
            {
                std::cout << "First guess: ";
                std::cin >> guess;

                //error handling for guess input
                bool correct_guess = false;
                while (!correct_guess)
                {
                    if (!CheckGuessInput(guess))
                    {
                        std::cout << "Invalid input!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> guess;
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
                        std::cout << "One failed attempt remaining!" << std::endl;
                    }
                    else if (remaining_attempts == 0)
                    {
                        std::cout << "You ran out of attempts!" << std::endl;
                        std::cout << "Better luck next time." << std::endl;

                        std::cout << std::endl;

                        std::cout << "Game over..." << std::endl;
                        return 0;
                    }
                    else
                    {
                        std::cout << "Failed attempts remaining: " << remaining_attempts << std::endl;
                    }
                }
                if (previous_guesses.size() < 2)
                {
                    std::cout << "Previous guess: " << previous_guesses[0] << std::endl;
                }
                else
                {
                    std::cout << "Previous guesses: ";
                    for (size_t i = 0; i < previous_guesses.size(); i++)
                    {
                        if (i != previous_guesses.size() - 1)
                        {
                            std::cout << previous_guesses[i] << ", ";
                        }
                        else
                        {
                            std::cout << previous_guesses[i] << std::endl;
                        }
                    }
                }
                std::cout << "Next guess: ";
                std::cin >> guess;

                //error handling for guess input
                bool correct_guess = false;
                while (!correct_guess)
                {
                    if (!CheckGuessInput(guess))
                    {
                        std::cout << "Invalid input!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> guess;
                    }
                    //duplicate guess
                    else if (any_of(previous_guesses.begin(), previous_guesses.end(), [guess](char i) { return i == guess; }))
                    {
                        std::cout << guess << " has already been guessed!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Next guess: ";
                        std::cin >> guess;
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
                std::cout << guess << " is NOT in your word!" << std::endl;
                remaining_attempts--;
            }
            total_attempts++;

            std::cout << std::endl;
        }
        else
        {
            std::cout << "Word: ";
            for (size_t i = 0; i < word_holder.size(); i++)
            {
                std::cout << word_holder[i];
            }
            std::cout << std::endl;
            std::cout << "You guessed your word!" << std::endl;
            std::cout << "Total attempts: " << total_attempts << std::endl;
            std::cout << "Leftover failed attempts: " << remaining_attempts << std::endl;

            std::cout << std::endl;

            std::cout << "Game Over." << std::endl;
            return 0;
        }
    }
    return 0;
}