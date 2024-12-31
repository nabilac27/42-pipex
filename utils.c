/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 06:17:07 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/31 07:09:21 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *argv, char *envp[])
{
	char	**cmd;
	int		i;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], envp);
	if (path == NULL)
		error_message("Error: no path.");
	if (execve(path, cmd, envp) == -1)
		error_message("Error: execve error.");
}

char	*get_path(char *cmd, char *envp[])
{
	char	**whole_env;
	char	*whole_path;
	int		i;
	char	*path;

	i = 0;
	while (whole_env[i] != 0)
	{
		path = ft_split(path[i], '/');
		whole_path = ft_strjoin_free(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	i = 0;
	ft_split_free(whole_env);
	return (0);
}

void	error_message(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}