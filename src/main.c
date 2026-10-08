/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:30:19 by nchairun          #+#    #+#             */
/*   Updated: 2026/10/08 03:00:11 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	parent should create two children.
	Both children run concurrently, and the parent closes its pipe descriptors before waiting
*/

void	left_process(char *argv[], char *envp[], int fd[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error_message("Infile is not opened succesfully.");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute_cmd(argv[2], envp);
}

void	right_process(char *argv[], char *envp[], int fd[])
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error_message("Infile is not opened succesfully.");
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute_cmd(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (argc != 5)
		error_message("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (pipe(fd) == -1)
		error_message("Pipe creation failed");
	pid1 = fork();
	if (pid1 == -1)
	{
		close(fd[0]);
		close(fd[1]);
		error_message("Fork creation failed");
	}
	if (pid1 == 0)
		left_process(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		error_message("Fork creation failed");
	}
	if (pid2 == 0)
		right_process(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	if (waitpid(pid2, &status, 0) == -1)
		error_message("waitpid failed");
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

// int	main(int argc, char *argv[], char *envp[])
// {
// 	int		fd[2];
// 	pid_t	pid_fork;

// 	if (pipe(fd) == -1)
// 		error_message("Pipe creation failed.");
// 	if (argc == 5)
// 	{
// 		pid_fork = fork();
// 		if (pid_fork == -1)
// 			error_message("Fork creation failed.");
// 		if (pid_fork == 0)
// 			left_process(argv, envp, fd);
// 		else if (pid_fork > 0)
// 			waitpid(pid_fork, NULL, 0);
// 		right_process(argv, envp, fd);
// 	}
// 	else
// 		error_message("Error.");
// 	return (0);
// }
