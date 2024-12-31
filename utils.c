/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 06:17:07 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/31 07:41:19 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *argv, char *envp[])
{
	char	**cmd;
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
	char	**env;
	char	*whole_path;
	int		i;
	char	*path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	env = ft_split(envp[i] + 5, '/');
	while (env[i] != NULL)
	{
		whole_path = ft_strjoin_free(env[i], "/");
		path = ft_strjoin_free(whole_path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	i = 0;
	ft_split_free(env);
	return (0);
}

void	error_message(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
