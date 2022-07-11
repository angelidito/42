/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:30:02 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/11 12:43:30 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countchr(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (*s)
		if (s[i++] == c)
			count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*beggining;
	size_t	i;
	size_t	len;
	size_t	pos;

	if (!s)
		return (NULL);
	array = calloc(ft_countchr(s, c) + 2, sizeof (char *));
	if (!array)
		return (NULL);
	i = 0;
	pos = 0;
	while (s[i])
	{
		beggining = (char *)s + i;
		len = 0;
		while (s[i] != c && s[i++])
			len++;
		array[pos] = malloc(len + 1);
		ft_strlcpy(array[pos++], beggining, len + 1);
	}
	array[pos] = NULL;
	return (array);
}
