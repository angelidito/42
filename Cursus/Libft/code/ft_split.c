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

/*
char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;
	size_t	i;
	char	*ptc;
	size_t	j;

	array = NULL;
	if (!s || ft_strlen(s) == 0)
		return (ft_emptyarray());
	words = ft_countwords(s, c);
	array = ft_calloc(words + 1, sizeof(char *));
	if (!array)
		return (0);
	i = 0;
	j = 0;
	while (i < words)
	{
		while (*(s + j) == c)
			j++;
		ptc = ft_strchr(s + j, c);
		array[i] = ft_substr(s + j, 0, ptc - s + j);
		while ((s + j) < ptc)
			j++;
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	words;

	if (!s)
		return (ft_emptyarray());
	words = ft_countwords((char *)s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < words)
	{
		ft_saveword((char **)&s, &(array[i]), c, words);
		i++;
	}
	array[words] = NULL;
	return (array);
}*/

/*
char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	len;
	size_t	pos;

	if (!s)
		return (NULL);
	array = (char **)malloc((ft_countchr(s, c) + 2) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	pos = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] != c && s[i++])
			len++;
		if (s[i] == c)
			i++;
		array[pos] = malloc(len + 1);
		ft_strlcpy(array[pos++], s + i - len, len + 1);
	}
	array[pos] = NULL;
	return (array);
}

int main(void)
{
	ft_split("     ", ' ');
	return (0);
}

size_t	ft_countchr(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
		if (*s++ == c)
			count++;
	return (count);
}
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((1 + 1 + ft_countchr(s, c)) * sizeof (char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		if (s[i] == c)
			i++;
		arr[j] = malloc(len + 1);
		ft_strlcpy(arr[j], s + i - len, len + 1);
		j++;
	}
	return (arr);
}*/
