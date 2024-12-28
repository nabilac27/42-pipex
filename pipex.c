/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:32:55 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/28 02:43:18 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
    Pipex
        making a program that can take input from one file, 
        process it through two programs (using pipes), 
        and then output the result to another file.
        
    Pipes
        tunnel between two programs, 
        allowing the output of one program to become the input for the next program.
*/

// Input files
// Command 1    : first program (eg: cat, ls) that does something with input file
// Pipe         : link between two commands
// Command 2    : second program that will process data coming from Command 1
// Output File  : final file where the result will be written

// 1. Open Input and Output Files
// 2. Create a Pipe
// 3. Fork the Processes
// 4. Execute the Commands
// 5. Close Pipes and Files
// 6. Handle Errors

// input    : ./pipex file1 cmd1 cmd2 file2
//           file: file names
//           cmd : shell commands with parameter

/* ---------- */

// Main function: run child process, parent process, display error message
// int main(int argc, char *argv[], char *envp[])
// {
//     int     fd[2];
//     pid_t   pid;

//     if (argc == 5)
//     {
//         if (pipe(fd) == -1)
//             error();
//         pid = fork();
//         if (pid == -1)
//             error();
//         if (pid == 0)
//             parent_process(fd, argv, envp);
//     }
//     else
//     {
//         ft_putstr_fd("Error", "Wrong number of arguments");
//         ft_putstr_fd("Correct Input", "./pipex <file1> <cmd1> <cmd2> <file2>");
// 		exit(1);
//     }
//     return(0);
// }

// test
// int main()
// {
// 	pid_t pid;

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}

// 	if (pid == 0)
// 		printf("This is the child process. (pid: %d)\n", getpid());
// 	else
// 		printf("This is the parent process. (pid: %d)\n", getpid());

// 	return (0);
// }


/*
	needed functions;
	dup, dup2 -- duplicate an existing file descriptor
		int		dup(int fildes);
		int		dup2(int fildes, int fildes2);
	RETURN VALUES: new file descriptor is returned.  Otherwise, a value of -1

	accesss -- checks the accessibility of the file named by the path argument 
			for the access permissions indicated by the mode argument
		int	access(const char *path, int mode);
		mode: R_OK, W_OK, X_OK
	RETURN VALUES: 0 is returned; otherwise -1

	execve -- execute a file
			  transforms the calling process into a new process.
	     int	execve(const char *path, char *const argv[], char *const envp[]);
	RETURN VALUES:	the successful call has no process to return to, otherwise -1

	fork -- create a new process
		pid_t	fork(void);
	RETURN VALUES: 0 to the child process.
					The child's PID (process ID) to the parent process.
					-1 if the fork fails 
	Parent vs. Child:
		You know which process you’re in because fork returns:
	0 in the child.
	A positive number (child’s PID) in the parent.

	pipe -- create descriptor pair for interprocess communication
		int		pipe(int fildes[2]);
	RETURN VALUES: zero is returned. Otherwise, -1

	rm, unlink -- remove directory entries
		int		unlink(const char *pathname);
	RETURN VALUES: zero is returned. Otherwise, -1

	wait	-- wait for process termination
		pid_t	wait(int *stat_loc);
		stat_loc: A pointer to an integer where the exit status 
				of the child process is stored.
				It can be NULL if you don't care about the child process's exit status.
	RETURN VALUES: zero is returned. Otherwise, -1
*/

// pipe example
int main()
{
    int fd[2];          // File descriptors for the pipe
    pid_t pid;
    char buffer[13];    // Buffer to store the message

    // Create the pipe
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();  // Create a child process
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)  // Child process
    {
        close(fd[0]);  // Close the read end of the pipe (not needed by the child)
        write(fd[1], "Hello parent!", 13);  // Write message to the pipe
        close(fd[1]);  // Close the write end after writing
        exit(EXIT_SUCCESS);  // Exit the child process
    }
    else  // Parent process
    {
        close(fd[1]);  // Close the write end of the pipe (not needed by the parent)
        read(fd[0], buffer, 13);  // Read message from the pipe
        close(fd[0]);  // Close the read end after reading
        printf("Message from child: '%s'\n", buffer);  // Print the message
        exit(EXIT_SUCCESS);  // Exit the parent process
    }
}
