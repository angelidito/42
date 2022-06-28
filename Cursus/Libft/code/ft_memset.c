/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:09:31 by angmarti          #+#    #+#             */
/*   Updated: 2022/06/28 16:11:56 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *) b;
	i = 0;
	while (i < len)
		*(s + i++) = c;
	return (b);
}

/*
int	main(void)
{
	char	s26[50] = "america";
	ft_memset(s26, 'y', 10);
	printf("%s\n", s26);
	
	char	s27[50] = "america";
	memset(s27, 'y', 10);
	printf("%s\n\n", s27);
	return (0);
}*/
