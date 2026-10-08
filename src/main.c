/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:30:19 by nchairun          #+#    #+#             */
/*   Updated: 2026/10/08 03:02:22 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	parent should create two children.
	Both children run concurrently, and the parent closes its pipe descriptors before waiting
*/

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
