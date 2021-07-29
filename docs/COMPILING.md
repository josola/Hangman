# Compiling 🔧

Compiling the Hangman game is straight forward and can be done using whatever compiler you wish. In this guide we will use the GNU C Compiler for its simplicity and ease of use. Although, C++ 11 features are used and the C++ release should be set to a minimum of C++ 11 during compilation.

The folder structure used for this project is ``/src``, where all the source code is held, and ``/bin``, where your binaries will live. In a Terminal shell, type the following command to compile the Hangman game.

After you have created a binary folder, type the following command into a Terminal shell.

``g++ -std=c++11 src/**.cpp -o bin/hangman``