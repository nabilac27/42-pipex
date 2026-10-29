*This project has been created as part of the 42 curriculum by **nchairun**.*

# pipex

## Overview

`pipex` is a C program that reproduces the shell pipeline `|`. It runs two commands connected by a pipe, with input and output redirected from and to files.

```sh
./pipex file1 cmd1 cmd2 file2
```

is equivalent to:

```sh
< file1 cmd1 | cmd2 > file2
```

| Argument | Description |
|----------|-------------|
| `file1` | Input file for the first command |
| `cmd1` | First command, reads from `file1` |
| `cmd2` | Second command, reads the output of `cmd1` |
| `file2` | Output file, receives the result of `cmd2` |

## Concepts Learned

- Pipes with `pipe()`
- Process creation with `fork()`
- File descriptor redirection with `dup2()`
- Command execution with `execve()`
- Locating commands through the `PATH` environment variable
- Error handling for invalid commands, missing files and failed system calls

## Structure

| Function | Role |
|----------|------|
| `left_process` | Runs `cmd1`, reading from `file1` and writing to the pipe |
| `right_process` | Runs `cmd2`, reading from the pipe and writing to `file2` |
| `execute_cmd` | Finds and executes a command |
| `get_path` | Resolves the full path of a command from `PATH` |
| `error_message` | Prints an error and exits |

## Usage

```sh
git clone https://github.com/nabilac27/pipex.git
cd pipex
make                     # builds pipex
./pipex input.txt "cat" "grep keyword" output.txt
make re                  # rebuild from scratch
```

## Example

```sh
$ cat input.txt
apple
keyword here
banana

$ ./pipex input.txt "cat" "grep keyword" output.txt
$ cat output.txt
keyword here
```

## Resources

- [man 2 pipe](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [man 2 fork](https://man7.org/linux/man-pages/man2/fork.2.html)
- [man 2 dup2](https://man7.org/linux/man-pages/man2/dup2.2.html)
- [man 2 execve](https://man7.org/linux/man-pages/man2/execve.2.html)
