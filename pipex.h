/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 05:30:05 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/31 08:27:19 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// pipex.c
void	left_child_process(char *argv[], char *envp[], int fd[]);
void	right_parent_process(char *argv[], char *envp[], int fd[]);

// pipex_execute.c
void	execute_cmd(char *cmd, char *envp[]);
char	*get_path(char *cmd, char *envp[]);

// ft_utils
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	error_message(char *message);

// ft_strjoin.c
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strchr(const char *str, int chr);
int		ft_strlen(const char *str);
int		ft_strlcpy(char *dst, const char *src, int dstsize);

// ft_split.c
char	**ft_split(char const *s, char c);
void	ft_split_free(char **split);
void	free_str(char **str);
int		count_str(char const *str, char c);
int		split_str(char const *str, char c, char **result, int i);

#endif