# [CheckGuessInput](https://github.com/josola/Hangman/blame/60038d7b368ae67a87aa9a3b370b988839be7d82/src/check_utility.h#L10)

**Checks input against an array of bad guesses.**

Takes a character as input, then compares that character against every element within an array of characters that are not acceptable as input. If the comparison is true, a false value is returned indicated bad input. Otherwise true is returned, indicating good input.

📐 **Parameters**

``input``<br>
Const unsigned integer.

↩️ **Return value**

Returns a ``bool`` value.

🗺️ **Include file**

[src\check_utility.h](src\check_utility.h)

💡 **Example**

```c++
// Check guess input example.

#include <iostream>

int main()
{
    char guess = '';

    bool good_guess = false;
    while (!good_guess)
    {
        cin >> guess;

        if (!CheckGuessInput(guess))
        {
            std::cout << "Guess is not valid." << std::endl;
        }
        else
        {
            good_guess = true;
        }
    }

    std::cout << guess << good_guess << std::endl;

    return 0;
}
```

📺 **Output**

```
#
Guess is not valid.
t
t TRUE
```