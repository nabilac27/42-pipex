/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 06:17:07 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/31 06:35:49 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *cmd, char *envp[])
{
	char	*cmd;
	int		i;
	char	*path;
}

void	error_message(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}