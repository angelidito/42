/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:04:29 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/26 14:40:32 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>	/* Malloc & Free functions */
# include <unistd.h> 	/* Write & Read functions */
# include <stdio.h>		/* BUFSIZ definition*/
# include <fcntl.h> 	/* Open function */
# include <limits.h>	/* Macro defined OPEN_MAX */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806L /*Double long*/
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
char	*gnl_cut_myline(char *myline);
char	*gnl_get_line2return(char *myline);
char	*gnl_read_and_add(int fd, char *myline);

//Utils
size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);
char	*gnl_strjoin(char *myline, char *buffer);

void	*ft_calloc(size_t count, size_t size);

#endif
