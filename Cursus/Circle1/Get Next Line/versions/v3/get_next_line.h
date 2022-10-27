/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:04:29 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/25 11:39:43 by angmarti         ###   ########.fr       */
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

char	*get_next_line(int fd);
void	gnl_replace_line(char **currentline, char *newline);
char	*gnl_getsubstr_cutmyline(char **ptr2myline, size_t len);
char	*gnl_strjoin(char **myline, char *buffer);

//Utils
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);

/*
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
*/

// The end of the header guard.
#endif
