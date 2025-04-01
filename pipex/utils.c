/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 06:17:07 by nchairun          #+#    #+#             */
/*   Updated: 2025/01/19 04:51:05 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *argv, char *envp[])
{
	char	**cmd;
	char	*path;

	path = NULL;
	if (!argv || !envp)
		error_message("Error: no arguments/envp");
	cmd = ft_split(argv, ' ');
	if (!cmd[0])
	{
		ft_split_free(cmd);
		error_message("Error: no command");
	}
	path = get_path(cmd[0], envp);
	if (path == NULL)
	{
		ft_split_free(cmd);
		perror("Error: no path");
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("Error: execve()");
		free(path);
		ft_split_free(cmd);
	}
}

char	**get_env_paths(char *envp[])
{
	int		i;
	char	**env;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	env = ft_split(envp[i] + 5, ':');
	if (!env)
		return (NULL);
	return (env);
}

char	*get_path(char *cmd, char *envp[])
{
	char	**env;
	char	*whole_path;
	char	*path;
	int		j;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	env = get_env_paths(envp);
	if (!env || !cmd || !envp)
		return (NULL);
	j = 0;
	while (env[j] != NULL)
	{
		whole_path = ft_strjoin(env[j], "/");
		if (!whole_path || !path)
			return (ft_split_free(env), NULL);
		path = ft_strjoin(whole_path, cmd);
		free(whole_path);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_split_free(env), path);
		free(path);
		j++;
	}
	ft_split_free(env);
	return (NULL);
}

void	error_message(char *message)
{
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	else
		write(2, "Error\n", 6);
	exit(1);
}
