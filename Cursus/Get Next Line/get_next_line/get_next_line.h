/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:04:29 by angmarti          #+#    #+#             */
/*   Updated: 2022/08/31 14:34:57 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is a header guard. It prevents the header from being included twice.
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// These are the libraries that are needed for the program to work.
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

// This is a preprocessor directive. 
// It checks if the macro BUFFER_SIZE is not defined. 
// If it is not defined, it defines it as 1.
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// These are the function prototypes. 
// They tell the compiler what the function will return, 
// what the function will be called, and what parameters the function will take.

ssize_t	gnl_read_and_add(int fd, char **currentline, size_t len);
char	*gnl_cut_line(char **currentline, size_t len);
char	*get_next_line(int fd);

// Prototypes of the first version
// int		freecat(char **oldline, char *buff, ssize_t bytes);
// int		read_until_newline(int fd, char **line);
// char	*get_until_newline(char **oldline);

//Utils
/*
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
*/

// The end of the header guard.
#endif
