# My Get Next Line project 


## The Idea
```mermaid
flowchart TD
  0("get_next_line()") --> isLineEmpty{Is the actual line empty or NULL?}
  isLineEmpty -- No --> checkEOL[Check for EOL in the line]
  isLineEmpty -- Yes --> read[Read \n BUFFER_SIZE bytes\n of the file \n and add them to line] --> checkEOL
  checkEOL --> containsEOL{Do line contains EOL?}
  containsEOL -- No -->  isEOFreached{Is EOF reached?}
  isEOFreached -- Yes --> returnLine[/Return the actual line/]
  isEOFreached -- No --> read 
  containsEOL -- Yes --> returnSub[/Return the substring \n and clean the line/]
  returnSub --> 1(End)
  returnLine --> 1
 ```

## Score
Get next line Score: [![angmarti's 42 get_next_line Score](https://badge42.vercel.app/api/v2/cl5nvqyx2001109jk9d48eq0s/project/2670153)](https://github.com/angelidito/42/tree/main/Cursus/Get%20Next%20Line)
