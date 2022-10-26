/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebaread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:38:57 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/04 13:12:10 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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

int	main(void)
{
	char c = '\0';
	printf("'%d', '%c'", (int) c, c);
/*
	int		fd;
	int		i;
	char	*buff;
	buff = (char *)malloc(6);
	if (!buff)
	{
		printf("FALLO MALLOC");
		return (-1);
	}
	i = 0;
	buff[i++] = '0';
	buff[i++] = '1';
	buff[i++] = '2';
	buff[i++] = '3';
	buff[i++] = '4';
	buff[i++] = '5';
	buff[i] = '\0';
	printf("%s\n", buff);*/
	/*
	fd = open("prueba", O_RDONLY);
	read(fd, buff, 6);
	printf("%s\n", buff);
	while (*buff)
	{
		printf("\"%c\"\n", *buff);
		buff++;
	}*//*
	printf("%ld\n%ld\n", buff+0 ,0+ ft_strchr(buff, 4));*/
	return (0);
}
