/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:12:10 by nchairun          #+#    #+#             */
/*   Updated: 2025/01/10 19:26:08 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr_malloc;

	ptr_malloc = malloc(ft_strlen(s1) + 1);
	if (ptr_malloc == 0)
		return (0);
	ft_strlcpy(ptr_malloc, s1, ft_strlen(s1) + 1);
	return (ptr_malloc);
}
