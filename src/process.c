/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 03:02:29 by nchairun          #+#    #+#             */
/*   Updated: 2026/10/08 03:06:18 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	left_process(char *argv[], char *envp[], int fd[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		close(fd[0]);
		close(fd[1]);
		error_message("Error: cannot open infile");
	}
	if (dup2(infile, STDIN_FILENO) == -1
		|| dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close(infile);
		close(fd[0]);
		close(fd[1]);
		error_message("Error: dup2 failed");
	}
	close(infile);
	close(fd[0]);
	close(fd[1]);
	execute_cmd(argv[2], envp);
	exit(1);
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
