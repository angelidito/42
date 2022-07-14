/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:30:02 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/12 19:11:26 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (*s && *s != c)
		count++;
	while (s[++i])
		if (s[i - 1] == c && s[i] != c)
			count++;
	return (count);
}

static char	**ft_emptyarray(void)
{
	char	**emptyarr;

	emptyarr = (char **)calloc(1, sizeof(char *));
	if (!emptyarr)
		return (NULL);
	return (emptyarr);
}

static void	ft_saveword(char **pts, char **auxi, char c)
{
	char	*ptc;

	while (**pts == c)
		(*pts)++;
	ptc = ft_strchr(*pts, c);
	*auxi = ft_substr(*pts, 0, ptc - *pts);
	while (*pts < ptc)
		(*pts)++;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;

	array = NULL;
	if (!s || ft_strlen(s) == 0)
		return (ft_emptyarray());
	words = ft_countwords(s, c);
	array = ft_calloc(words + 1, sizeof(char *));
	if (!array)
		return (0);
	i = 0;
	while (i < words)
		ft_saveword((char **)&s, &(array[i++]), c);
	return (array);
}
