/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 06:51:26 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/30 07:19:20 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* envp would be an array containing environment variables such as:
	envp[0]: "PATH=/usr/local/bin:/usr/bin:/bin"
	envp[1]: "HOME=/home/username"
	envp[2]: "USER=username"
	and so on.
*/

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid_fork;

	if (argc == 5)
	{
		pid_fork = fork();
		if (pid_fork == 0)
        {
            left_pipe_process(argv, envp, fd);
        }
		waitpid(pid_fork, NULL, 0);
		second_pipe_process(argv, envp, fd);
	}
	else
	{
		printf("(error)");
	}
	return (0);
}
