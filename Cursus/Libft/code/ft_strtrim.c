/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:00:17 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/13 11:30:45 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_findtrimpos(char const *s1, char const *set, int last)
{
	size_t	i;
	size_t	j;
	size_t	match;

	i = 0;
	if (last != 0)
	{
		last = 1;
		i = ft_strlen(s1) - 1;
	}
	while ((s1[i] && !last) || (0 <= i && last))
	{
		match = 0;
		j = 0;
		while (set[j])
			if (s1[i] == set[j++])
				match++;
		if (!match)
			return (i);
		if (i || !last)
			i = i + 1 - 2 * last;
		else
			last = 0;
	}
	return (ft_strlen(s1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s0;
	size_t	a;
	size_t	z;
	size_t	i;

	if (!s1)
		return (NULL);
	a = ft_findtrimpos(s1, set, 0);
	z = ft_findtrimpos(s1, set, 1);
	if (a >= ft_strlen(s1) || z >= ft_strlen(s1) || z < a)
		return ((char *)calloc(1, 1));
	s0 = calloc(z - a + 2, sizeof (char));
	if (!s0)
		return (NULL);
	i = 0;
	while (a <= z)
		*(s0 + i++) = *(s1 + a++);
	return (s0);
}
