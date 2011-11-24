
# ENCRYPTED STRINGS

##INTRODUCTION
This project aims to study how to encrypt and obfuscate explicit text strings used programs in C and C++. A common technique used to investigate into an executable file, is to analyze these text strings to extract information.

```
$ ./simple_hello_world
Hello world
$ strings simple_hello_world
Hello world
```

With the exposed technique in this project, a developer will "hide" those string.

```
$ ./hello_c
hello world
foo bar
$ strings hello_c
cnggd+|dygoahh'efu
Utpc1cxry1spbepcu
$ ./hello_cpp
hello world
foo bar
$ strings hello_cpp
zPLR
cnggd+|dygoahh'efu
Utpc1cxry1spbepcu
```

## USAGE

### C

```c
#include <stdio.h>
#include "encrypted_strings.h"

int main(int argc, char **argv) {
	/*
	 * Create a buffer for each string before any instructions has been
	 * executed (just like declaring local variables)
	 */
	ES_CREATE_BUFFER(HELLO_WORLD, hw);
	ES_CREATE_BUFFER(FOO_BAR, fb);

	/*
	 * Decrypt the strings
	 */
	ES_DECRYPT(HELLO_WORLD, hw);
	ES_DECRYPT(FOO_BAR, fb);

	/*
	 * Use them
	 */
	puts(hw);
	puts(fb);
}
```

### C++

```cpp
#include <iostream>
#include "encrypted_strings.h"

int main(int argc, char **argv) {
	/*
	 * Decrypt the strings and use them
	 */
	ES_DECRYPT(HELLO_WORLD, hw);
	std::cout << hw << std::endl;

	ES_DECRYPT(FOO_BAR, fb);
	std::cout << fb << std::endl;
}
```

## LICENSE
Copyright (c) 2011 Javier Escalada Gómez
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of copyright holders nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.