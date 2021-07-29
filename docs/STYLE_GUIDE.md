# Style Guide

Contained within are a few concrete guidelines on how the look and feel of this project should be.

## Formatting

Banners should be formatted as follows:

```c++
/* path_to_file/filename.extension
 * Description of what the file does
 * or why it needs to exist.
 *
 * (c) year and copyright holder
 * Written by author_name
 */
```

Include directives should be organized as user includes before standard library includes.

```c++
#include "user_include.h"
#include <iostream>
```

Function names should be Capitalized(). Do not use camelCase(), lowercase_with_underscores(), ALL_CAPS(), or lowercasewithoutunderscores().

```c++
int GetSum(int num_a, int num_b)
{
    ...
}
```

Block scope identifiers should be on their own lines.

```c++
for (int num : arr)
{
    ...
}
```

Add spacing within expressions, do not bunch up information that doesn't require it.

Good:
```c++
if (1 + 1 == 2)
{
    ...
}
```

Bad:
```c++
if(1+1==2)
{
    ...
}
```

Place ``const`` to the west of your expression.

```c++
const int limit = 100;
```

Do not leave trailing line breaks at the end of source files.

## Good Practices

Initialize variables at their declarations.

```c++
int sum = 0;
string name = "";
float gpa = 0.0;
bool found = false;
```

Always return a value at the end of your main function's execution.

```c++
int main()
{
    ...
    return 0;
}
```

Write expressive names for variables, classes, and so on. Do not use single letter variables.

Good:
```c++
vector<int> grades = {89, 73, 92, 97};
string first_name = "Jordan";
char grade_mark = 'C';
int RenameTitles(vector<string> titles);
```

Bad:
```c++
vector<int> arr = {89, 73, 92, 97};
string a = "Jordan";
char g = 'C';
int Rename(vector<string> arr);
```

Use ``#include`` guards in header (.h) files. Do not use ``#pragma once``. It is not portable, and some compilers do not recognize it.

```c++
// file foo.h
#ifndef FOO_H
#define FOO_H
// ... declarations ...
#endif // FOO_H
```

Do not use ``using namespace std`` in a global scope within header files. It has a detrimental effective on the preprocessor's ability to properly look at the ``#include`` directives within each header file.

Bad:
```c++
// file foo.h
using namespace std;
// ... declarations ...
```

Standard library classes should be written inline, instead of following any ``using namespace`` directives.

```c++
#include <iostream>

int main()
{
    std::cout << "The proper way to use library classes" << std::endl;
    return 0;
}
```

Use the **Standard Template Library** *STL* as often as you can. Do not rewrite STL functions when you don't have to.