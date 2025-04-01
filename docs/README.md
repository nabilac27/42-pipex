## **pipex** - Custom Implementation

The **pipex** project is a C program that simulates a shell pipeline. 
It uses pipes and process management to execute commands, handle file redirection, 
and facilitate inter-process communication (IPC).

The program takes in two input files, a set of commands, and outputs the result of piping these commands together.

#### **Functions Overview**

| **Function**                           | **Description** |
|----------------------------------------|-----------------|
| `left_process(char *argv[], char *envp[], int fd[])` | Handles the execution of the first command in the pipeline. It manages input/output redirection and the pipe between processes. |
| `right_process(char *argv[], char *envp[], int fd[])` | Handles the execution of the second command in the pipeline, managing output redirection and the pipe from the first process. |
| `execute_cmd(char *cmd, char *envp[])` | Executes a command by locating it in the system's PATH and running it with the given environment variables. |
| `get_path(char *cmd, char *envp[])`   | Retrieves the full path of a command by searching through the directories listed in the system's PATH environment variable. |
| `error_message(char *message)`        | Displays an error message and exits the program when something goes wrong during execution. |
