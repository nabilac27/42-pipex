/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:30:19 by nchairun          #+#    #+#             */
/*   Updated: 2025/01/19 03:41:44 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid_fork;

	if (pipe(fd) == -1)
		error_message("Error: pipe()");
	if (argc == 5)
	{
		pid_fork = fork();
		if (pid_fork == -1)
			error_message("Error: fork()");
		if (pid_fork == 0)
			left_child_process(argv, envp, fd);
		else if (pid_fork > 0)
			waitpid(pid_fork, NULL, 0);
		right_parent_process(argv, envp, fd);
	}
	else
		error_message("Error.");
	return (0);
}

void	left_child_process(char *argv[], char *envp[], int fd[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error_message("Error: infile");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute_cmd(argv[2], envp);
}

void	right_parent_process(char *argv[], char *envp[], int fd[])
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error_message("Error: outfile");
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute_cmd(argv[3], envp);
}
