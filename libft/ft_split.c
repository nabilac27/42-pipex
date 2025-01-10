/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 06:25:48 by nchairun          #+#    #+#             */
/*   Updated: 2025/01/10 19:28:03 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_str(char const *str, char c);
int		split_str(char const *str, char c, char **result, int i);
void	free_str(char **str);
void	ft_split_free(char **split);

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc((count_str(s, c) + 1) * sizeof(char *));
	if (!result)
		return (0);
	if ((split_str(s, c, result, 0)) == -1)
		return (0);
	return (result);
}

void	ft_split_free(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	count_str(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	split_str(char const *str, char c, char **result, int i)
{
	int	len;

	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			len = 0;
			while (*str != c && *str)
			{
				str++;
				len++;
			}
			result[i] = (char *)malloc(len + 1);
			if (!result[i])
			{
				free_str(result);
				return (-1);
			}
			ft_strlcpy((char *)result[i++], (char *)str - len, len + 1);
		}
	}
	result[i] = 0;
	return (1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
