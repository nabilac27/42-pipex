# **pipex**

The **pipex** project is a C program that simulates a shell pipeline. 

It uses pipes to connect commands, handles file redirection, and manages multiple processes. 

The program takes two input files and a set of commands, then pipes the commands together and outputs the result.


## **Key Concepts**

- **Pipes**: Used to pass the output of one command as input to another.
  
- **Process Management**: The program uses `fork()` to create child processes to execute commands, with communication happening through pipes.
  
- **File Redirection**: Reads from or writes to files by redirecting input/output.

- **Environment Variables**: Uses the `PATH` variable to locate commands in system directories.

- **Error Handling**: Displays an error message and exits the program if something goes wrong (e.g., invalid commands or failure to create pipes).

## How to Run
#### **Make the project**:
To compile the `pipex` project, run the following command:
```bash
$ make
```

#### **Run the program**:
To run the program, use the following format:
```bash
$ ./pipex file1 cmd1 cmd2 file2
```
- file1 is the input file for the first command.
- cmd1 is the first command to execute.
- cmd2 is the second command to execute.
- file2 is the output file where the result of the pipeline will be written.

#### **Example**:
```bash
$ ./pipex input.txt "cat" "grep keyword" output.txt
```

#### **Rebuild**:
To rebuild the project from scratch (after using fclean), run:
```bash
$ make re
```

---

## **Functions Overview**

| **Function**                            | **Description** |
|-----------------------------------------|-----------------|
| `left_process(char *argv[], char *envp[], int fd[])` | Executes the first command in the pipeline and manages its redirection. |
| `right_process(char *argv[], char *envp[], int fd[])` | Executes the second command in the pipeline and manages its redirection. |
| `execute_cmd(char *cmd, char *envp[])`  | Finds and runs a command by checking the system's `PATH`. |
| `get_path(char *cmd, char *envp[])`     | Finds the full path of a command in the `PATH` directories. |
| `error_message(char *message)`          | Displays an error message and exits the program if something goes wrong. |
