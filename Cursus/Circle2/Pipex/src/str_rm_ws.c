/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rm_ws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:55:22 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/08 18:03:38 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
		|| c == '\f');
}

char	*remove_duplicate_whitespaces(const char *str)
{
	char	*result;
	int		prev_was_whitespace;
	int		i;
	int		j;
	char	c;

	result = malloc(strlen(str) + 1);
	j = 0;
	prev_was_whitespace = 0;
	while (i < strlen(str))
	{
		c = str[i++];
		if (ft_isspace(c))
		{
			if (!prev_was_whitespace)
			{
				result[j++] = c;
				prev_was_whitespace = 1;
			}
		}
		else
		{
			result[j++] = c;
			prev_was_whitespace = 0;
		}
	}
	result[j] = '\0';
	return (result);
}
