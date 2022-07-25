# My Get Next Line project 


## The idea
```mermaid
flowchart TD
subgraph Main idea
	0main("get_next_line()") --> isLineEmpty{Is the actual line empty or NULL?}
  isLineEmpty -- No --> checkEOL[Check for EOL in the line]
  isLineEmpty -- Yes --> read[/Read from file \n and add to line/] --> checkEOL
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


## Score
Get next line Score: [![angmarti's 42 get_next_line Score](https://badge42.vercel.app/api/v2/cl5nvqyx2001109jk9d48eq0s/project/2670153)](https://github.com/angelidito/42/tree/main/Cursus/Get%20Next%20Line)
