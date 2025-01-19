/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:30:05 by nchairun          #+#    #+#             */
/*   Updated: 2025/01/19 10:41:31 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// pipex.c
void	left_process(char *argv[], char *envp[], int fd[]);
void	right_process(char *argv[], char *envp[], int fd[]);

// utils.c
void	execute_cmd(char *cmd, char *envp[]);
char	*get_path(char *cmd, char *envp[]);
void	error_message(char *message);

#endif
