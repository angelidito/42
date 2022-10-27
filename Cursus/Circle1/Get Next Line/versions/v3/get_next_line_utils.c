 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:43:45 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/05 15:56:04 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * It allocates memory for a given size and sets all the bytes to 0.
 * 
 * @param count The number of elements to allocate.
 * @param size The size of the memory block, in bytes.
 * 
 * @return A pointer to the allocated memory.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			len;
	unsigned char	*p;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	if (!count || !size)
		len = 1;
	else
		len = count * size;
	ptr = malloc(len);
	if (!ptr || ptr == NULL)
		return (NULL);
	p = (unsigned char *) ptr;
	while (0 < len--)
		*p++ = 0;
	return (ptr);
}

/**
 * If the string is too short, return an empty string, otherwise return a 
 * substring of the given string.
 * 
 * @param s The string to be split.
 * @param start the index of the first character to include in the substring.
 * @param len the length of the substring to be returned
 * 
 * @return A pointer to a new string.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
	{
		sub = malloc(sizeof (char));
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	if (ft_strlen(s) - start - 1 < len)
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof (char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	sub[len] = '\0';
	return (sub);
}

/*
 * Copy the string pointed to by src, including the terminating 
 * null byte ('\0'), to the buffer pointed to by dst
 * 
 * @param dst This is the destination string.
 * @param src The string to be copied.
 * @param dstsize The size of the destination buffer.
 * 
 * @return The length of the string src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (0 < dstsize)
	{
		while (i < dstsize - 1 && *(src + i))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (ft_strlen(src));
}

/**
 * It returns the length of a string.
 * 
 * @param s This is the string we want to find the length of.
 * 
 * @return The length of the string.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}
