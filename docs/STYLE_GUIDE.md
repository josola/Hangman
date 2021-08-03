# Style Guide 🧶

### Project structure should be as follows:

```
project
|   .gitignore
|   LICENSE
|   README.md
| 
└───bin
|   |   executables
|
└───docs
|   |   documentation
|
└───src
    |   source_files
```

### The main point of entry source file should be named ```main```, regardless of file type.

### Banners should be formmated as follows:

```c++
/* file_directory/file_name.extension
 * File description.
 * copyright
 * author */
```

### User ```include``` directives should be placed before library directives.

```c++
#include "user_file.h"
#include <library>
```

### ``using namespace`` should not be included in source files.

Wrong:

```c++
#include <vector>

using namespace std;
```

Wrong:

```c++
#include <iostream>

using std::cout;
```

### The ``main()`` function should have a return type.

```c++
int main()
{
 ...
}
```

### Curly braces should be placed on newlines.

```c++
int main()
{
 ...
}
```

### Definitions should occur at declarations when possible.

```c++
int num = 12;
const int limit = 32;
```

``const`` should be west.

Right:

```c++
const int limit = 12;
```

Wrong:

```c++
int const limit = 12;
```

### Spaces should be included in expressions.

Right:

```c++
while (limit != 12)
{

}
```

Wrong:

```c++
while(limit!=12)
{

}
```

### New lines to the output stream should use ``std::endl;``.

```c++
std::cout << "Hello World!" << std::endl;
```

### The ``main()`` function should return 0 at the end of execution.

```c++
int main()
{
 ...
 return 0;
}
```

### Do not include trailing newlines in source files.

### Project documentation filenames should be all caps:

```
BUILD_GUIDE.md
CONTRIBUTING.md
README.md
```