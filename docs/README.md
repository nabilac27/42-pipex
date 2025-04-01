## **pipex**

The **pipex** project is a C program that simulates a shell pipeline. It uses pipes and process management to execute commands, handle file redirection, and facilitate inter-process communication (IPC).

The program takes in two input files, a set of commands, and outputs the result of piping these commands together.

#### **Functions Overview**

| **Function**                           | **Description** |
|----------------------------------------|-----------------|
| `left_process(char *argv[], char *envp[], int fd[])` | Handles the execution of the first command in the pipeline. It manages input/output redirection and the pipe between processes. |
| `right_process(char *argv[], char *envp[], int fd[])` | Handles the execution of the second command in the pipeline, managing output redirection and the pipe from the first process. |
| `execute_cmd(char *cmd, char *envp[])` | Executes a command by locating it in the system's PATH and running it with the given environment variables. |
| `get_path(char *cmd, char *envp[])`   | Retrieves the full path of a command by searching through the directories listed in the system's PATH environment variable. |
| `error_message(char *message)`        | Displays an error message and exits the program when something goes wrong during execution. |

#### **Key Concepts**

- **Pipes**: A pipe is a method of inter-process communication that allows the output of one process to be used as the input of another. In **Pipex**, pipes are used to connect the standard output of one process to the standard input of another.
  
- **Process Management**: This project involves managing multiple processes using `fork()`. The parent process creates child processes for executing commands. Each child process communicates with others via pipes.

- **File Redirection**: **Pipex** handles file redirection to read from or write to files. For instance, it redirects input from a file and outputs the result to another file.

- **Environment Variables**: The environment variable `PATH` is used to locate the commands to be executed in the system. The function `get_path` checks for the presence of commands within the directories specified in the `PATH`.

- **Error Handling**: Proper error handling is crucial in **Pipex**. The function `error_message` is used to output error messages and terminate the program if anything goes wrong, such as invalid commands or failure to create pipes.
