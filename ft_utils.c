/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:12:10 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/31 08:15:23 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr_malloc;

	ptr_malloc = malloc(ft_strlen(s1) + 1);
	if (ptr_malloc == 0)
		return (0);
	ft_strlcpy(ptr_malloc, s1, ft_strlen(s1) + 1);
	return (ptr_malloc);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && 0 < n)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	error_message(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}
