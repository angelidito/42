# Pipex - Go dance salsa somewhere :)

The Pipex project is a demonstration of the "Pipes and Filters" 
software design pattern implemented in the C programming language.
The goal of the project is to process data through a series of stages, 
where each stage is represented by a separate process that is connected by a pipe.

## Getting Started

To run the Pipex project, you will need a C compiler and a Unix-like operating system.

1. Clone or download this repository to your local machine.
2. Navigate to the repository directory in your terminal.
3. Compile the source code using the command `make`.
4. Run the Pipex project by executing the following command:  
	> `./pipex file1 command1 command1 file2`


## Allowed functions

| | |
|:---      | :---
|     open | opens a file or device and returns a file descriptor that can be used for reading, writing, or manipulating the file or device.
|    close | closes a file descriptor, freeing up system resources and allowing the file or device to be reused.
|     read | reads data from a file descriptor into a buffer.
|    write | writes data from a buffer to a file descriptor.
|   malloc | allocates a block of memory dynamically and returns a pointer to the first byte of the block.
|     free | frees a block of memory that was previously allocated with malloc.
|   perror | prints a error message to stderr indicating the error that occurred in the last system call.
| strerror | returns a string describing the error code passed as an argument.
|   access | checks the accessibility of a file or directory, returns 0 if the file or directory can be accessed, otherwise -1.
|      dup | duplicates a file descriptor, creating a new descriptor that refers to the same file or device as the original.
|     dup2 | duplicates a file descriptor, closing the new descriptor first if necessary to ensure it refers to the same file or device as the original.
|   execve | replaces the current process image with a new process image specified by the file path.
|     exit | terminates the calling process and returns the status code to the parent process.
|     fork | creates a new child process that is a copy of the parent process.
|     pipe | creates a unidirectional communication channel between two processes, returning a pair of file descriptors, one for reading and one for writing.
|   unlink | deletes a file or symbolic link.
|     wait | suspends the execution of the calling process until one of its child processes terminates.
|  waitpid | suspends the execution of the calling process until a specific child process terminates, and returns information about the terminated process.
