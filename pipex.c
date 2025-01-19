/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:30:19 by nchairun          #+#    #+#             */
/*   Updated: 2025/01/19 08:03:00 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid_left;
	pid_t	pid_right;

	if (argc != 5)
	{
		perror("Error: argument is not 5\n");
		return (1);
	}
	
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("Error: infile");
		return (1);
	}
	
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("Error: outfile");
		close(infile);
		return (1);
	}
	
	if (pipe(fd) == -1)
		error_message("Error: pipe()");
		
	pid_left = fork();
	
	if (pid_left == -1)
		error_message("Error: fork()");
	if (pid_left == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		dup2(infile, STDIN_FILENO);
		close(infile);
		execute_cmd(argv[2], envp);
		perror("Error: execve");
		exit(1);
	}
	
	pid_right = fork();
	if (pid_right == -1)
		error_message("Error: fork()");
	if (pid_right == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		execute_cmd(argv[3], envp);
		perror("Error: execve");
		exit(1);
	}
	
	close(fd[0]);
	close(fd[1]);
	close(infile);
	close(outfile);
	
	waitpid(pid_left, NULL, 0);
	waitpid(pid_right, NULL, 0);
	
	return (0);
}

void	left_process(char *argv[], char *envp[], int fd[], int infile)
{
	if (infile == -1)
	{
		perror("Error: infile");
		exit(1);
	}
	dup2(fd[1], STDOUT_FILENO);
	execute_cmd(argv[2], envp);
	perror("Error: execve");
	exit(1);
	close(fd[0]);
	execute_cmd(argv[2], envp);
}

void	right_process(char *argv[], char *envp[], int fd[], int outfile)
{
	if (outfile == -1)
	{
		perror("Error: outfile");
		exit(1);
	}
	execute_cmd(argv[3], envp);
	perror("Error: execve");
	exit(1);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute_cmd(argv[3], envp);
}
