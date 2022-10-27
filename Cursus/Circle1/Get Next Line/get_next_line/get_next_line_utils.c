/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:11:38 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/25 18:13:05 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/**
 * It returns a pointer to the first occurrence of the character c in the 
 * string s
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * 
 * @return A pointer to the first occurrence of the character c in the 
 * string s.
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;

	i = 0;
	while (*(s + i))
	{
		if ((c % 256) == *(s + i))
			break ;
		i++;
	}
	if ((c % 256) == *(s + i))
		return ((char *)(s + i));
	return (NULL);
}

/**
 * It takes two strings and returns a new string that is the concatenation of 
 * the two strings
 * 
 * @param myline the line that was read in the previous iteration of the loop
 * @param buffer the buffer that is being read from the file descriptor
 * 
 * @return A pointer to a string.
 */
char	*gnl_strjoin(char *myline, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	if (!buffer)
		return (myline);
	if (!myline)
		return (buffer);
	str = (char *) ft_calloc(ft_strlen(myline) + ft_strlen(buffer) + 1,
			sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while ((myline)[i])
		str[i++] = (myline)[j++];
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	free(myline);
	return (str);
}

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
