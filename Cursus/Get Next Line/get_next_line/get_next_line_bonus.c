/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:54:26 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/26 11:09:56 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * It cuts the line at the first newline character, and returns the rest of 
 * the line
 * 
 * @param myline the string that contains the line we want to cut
 * 
 * @return A pointer to a string.
 */
char	*gnl_cut_myline(char *myline)
{
	char	*newline;
	int		i;
	int		j;

	i = 0;
	while (myline[i] && myline[i] != '\n')
		i++;
	if (!myline[i])
	{
		free(myline);
		return (NULL);
	}
	newline = ft_calloc((ft_strlen(myline) - i + 1), sizeof(char));
	if (!newline)
		return (NULL);
	i++;
	j = 0;
	while (myline[i])
		newline[j++] = myline[i++];
	free(myline);
	return (newline);
}

/**
 * It returns a copy of the line up to the first newline character
 * 
 * @param myline the string that contains the line to return
 * 
 * @return A pointer to a string.
 */
char	*gnl_get_line2return(char *myline)
{
	char		*line2return;
	size_t		i;
	size_t		j;

	if (!*myline)
		return (NULL);
	i = 0;
	while (myline[i])
		if (myline[i++] == '\n')
			break ;
	line2return = ft_calloc(i + 1, sizeof(char));
	if (!line2return)
		return (NULL);
	j = 0;
	while (j++ < i)
		line2return[j - 1] = myline[j - 1];
	return (line2return);
}

/**
 * It reads from the file descriptor and adds the read data to the line
 * 
 * @param fd the file descriptor
 * @param myline the string that will be returned
 * 
 * @return A pointer to a string.
 */
char	*gnl_read_and_add(int fd, char *myline)
{
	char	*buffer;
	ssize_t	result;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	result = 1;
	while (!ft_strchr(myline, '\n') && result)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			free(buffer);
			free(myline);
			return (NULL);
		}
		buffer[result] = '\0';
		myline = gnl_strjoin(myline, buffer);
	}
	free(buffer);
	return (myline);
}

/**
 * Reads a file descriptor and returns a line from it
 * 
 * @param fd file descriptor
 * 
 * @return A line of text from a file.
 */
char	*get_next_line(int fd)
{
	static char	*myline[4096];
	char		*line2return;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	if (!myline[fd])
		myline[fd] = ft_calloc(1, sizeof(char));
	myline[fd] = gnl_read_and_add(fd, myline[fd]);
	if (!myline[fd])
		return (NULL);
	line2return = gnl_get_line2return(myline[fd]);
	myline[fd] = gnl_cut_myline(myline[fd]);
	return (line2return);
}
