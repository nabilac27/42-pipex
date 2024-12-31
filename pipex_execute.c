/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 06:17:07 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/31 08:25:24 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *argv, char *envp[])
{
	char	**cmd;
	char	*path;

	if (!argv || !envp)
		error_message("Error: null argument.");
	cmd = ft_split(argv, ' ');
	if (!cmd)
		error_message("Error: split failed.");
	if (!cmd[0])
	{
		ft_split_free(cmd);
		error_message("Error: empty command.");
	}
	path = get_path(cmd[0], envp);
	if (path == NULL)
	{
		ft_split_free(cmd);
		error_message("Error: command not found.");
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_split_free(cmd);
		error_message("Error: execve failed.");
	}
}

char	*get_path(char *cmd, char *envp[])
{
	char	**env;
	char	*whole_path;
	int		i;
	int		j;
	char	*path;

	if (!cmd || !envp)
		return (NULL);
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	env = ft_split(envp[i] + 5, ':');
	if (!env)
		return (NULL);
	j = 0;
	while (env[j] != NULL)
	{
		whole_path = ft_strjoin(env[j], "/");
		if (!whole_path)
		{
			ft_split_free(env);
			return (NULL);
		}
		path = ft_strjoin(whole_path, cmd);
		free(whole_path);
		if (!path)
		{
			ft_split_free(env);
			return (NULL);
		}
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_split_free(env);
			return (path);
		}
		free(path);
		j++;
	}
	ft_split_free(env);
	return (NULL);
}
