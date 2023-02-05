# Get Next Line - A Line Reader Function
Welcome to my implementation of the `get_next_line` function!  
This function is designed to read a single line from a file descriptor and is commonly used for reading from standard input or a file.

## What is get_next_line?
`get_next_line` is a function that reads a single line from a file descriptor and returns it as a null-terminated string. The function is designed to be called multiple times in succession to read the entire contents of a file or input stream.

## Getting Started
To get started with using `get_next_line`, simply ~~download `get_next_line_bonus.c`, `get_next_line_utils_bonus.c` and `get_next_line_bonus.h`~~ make **your own get_next_line** and include the header file `get_next_line.h` in your project. You can then call the `get_next_line` function and pass it a file descriptor to read from.

## Usage
Here is an example of how to use `get_next_line`:
```C++
#include "get_next_line.h"
int main(int argc, char *argv[])
{
    int fd;
    char *line;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while (get_next_line(fd, &line) == 1)
        {
            ft_putendl(line);
            free(line);
        }
        close(fd);
    }
    return (0);
}
```

## Score
Get next line Score: [![angmarti's 42 get_next_line Score](https://badge42.vercel.app/api/v2/cl5nvqyx2001109jk9d48eq0s/project/2670153)](https://github.com/angelidito/42/tree/main/Cursus/Get%20Next%20Line)

## Features
`get_next_line` has the following features:
- Reads a single line from a file descriptor
- Supports multiple file descriptors (bonus)
- Handles error cases and returns -1 on failure
- Supports reading from standard input
- Returns 0 when the end of the file is reached

## The idea
```mermaid
flowchart TD
subgraph Main idea
	0main("get_next_line()") --> isLineEmpty{Is the current line NULL?}
  isLineEmpty -- No --> checkEOL[Check for EOL in the line]
  isLineEmpty -- Yes --> instance[Inicializate line with calloc] --> read[/Read from file \n and add to line/] --> checkEOL
  checkEOL --> containsEOL{Do line contains EOL?}
  containsEOL -- No -->  isEOFreached{Is EOF reached?}
  isEOFreached -- Yes --> returnLine(Return \n the actual line)
  isEOFreached -- No --> read 
  containsEOL -- Yes --> returnSub(Return the substring \n and clean the line)
  returnSub --> 1main(End)
  returnLine --> 1main
 end
 subgraph Read from file and add to line explained
  0read("read()") --> makeBuffer[Instance string buffer\n and NULL-terminate it]
  makeBuffer --> getBytes[read BUFFER_SIZE bytes to \n buffer and store number of bytes read]
  getBytes --> readCheckEOL[Check for for EOL in buff \n and set boolean var]
  readCheckEOL --> mallocNewLine[Malloc new line, \n copy there actual line + buffer \n and NULL-terminate it]
  mallocNewLine --> freeLine[Free actual line\nand substitute it with new line]
  freeLine --> returnRead[Return number of bytes read]
  returnRead --> 1read(End)
 end
 ```

## Contact
If you have any questions or feedback, please feel free to reach out to me at slack.

