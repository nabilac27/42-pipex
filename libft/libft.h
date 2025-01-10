/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:23:26 by nchairun          #+#    #+#             */
/*   Updated: 2025/01/10 19:29:22 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int chr);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);

#endif
