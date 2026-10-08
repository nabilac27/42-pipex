/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:16:35 by nchairun          #+#    #+#             */
/*   Updated: 2025/01/10 19:26:04 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	int		i;
	char	char_chr;

	i = 0;
	char_chr = (char)chr;
	while (str && str[i] != '\0')
	{
		if (str[i] == char_chr)
			return ((char *)&str[i]);
		i++;
	}
	if (char_chr == '\0')
		return ((char *)&str[i]);
	return (0);
}
