## **pipex**

The **pipex** project is a C program that simulates a shell pipeline. 
It uses pipes to connect commands, handles file redirection, and manages multiple processes. 
The program takes two input files and a set of commands, then pipes the commands together and outputs the result.


#### **Key Concepts**

- **Pipes**: Used to pass the output of one command as input to another.
  
- **Process Management**: The program uses `fork()` to create child processes to execute commands, with communication happening through pipes.
  
- **File Redirection**: Reads from or writes to files by redirecting input/output.

- **Environment Variables**: Uses the `PATH` variable to locate commands in system directories.

- **Error Handling**: Displays an error message and exits the program if something goes wrong (e.g., invalid commands or failure to create pipes).


#### **Functions Overview**

| **Function**                            | **Description** |
|-----------------------------------------|-----------------|
| `left_process(char *argv[], char *envp[], int fd[])` | Executes the first command in the pipeline and manages its redirection. |
| `right_process(char *argv[], char *envp[], int fd[])` | Executes the second command in the pipeline and manages its redirection. |
| `execute_cmd(char *cmd, char *envp[])`  | Finds and runs a command by checking the system's `PATH`. |
| `get_path(char *cmd, char *envp[])`     | Finds the full path of a command in the `PATH` directories. |
| `error_message(char *message)`          | Displays an error message and exits the program if something goes wrong. |
