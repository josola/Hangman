# [WordChooser](https://github.com/josola/Hangman/blame/60038d7b368ae67a87aa9a3b370b988839be7d82/src/random_word.h#L14)

**Return random word from a string container**

Chooses a word at a random position within a vector of strings and returns that word as a string literal.

📐 **Parameters**

``word_container``<br>
Vector array of type string that contains at least one string literal within it.

↩️ **Return value**

A copy of a string literal that is contained within the input array.

🗺️ **Include file**

[src\random_word.h](src\random_word.h)

💡 **Example**

```c++
// Word chooser example.

#include <iostream>
#include <vector>
#include <string>

int main()
{
    vector<string> word_arr = {apple, carrot, pineapple, strawberry};

    string random_word = WordChooser(word_arr);

    cout << random_word << endl;

    return 0;
}
```

📺 **Output**

```
strawberry
```