/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:37:17 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It compares the first n bytes of the memory areas s1 and s2
 * 
 * @param s1 This is the first string to be compared.
 * @param s2 The string to be compared.
 * @param n The number of bytes to compare.
 * 
 * @return The difference between the first two different bytes.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while (i < n)
	{
		if (*(c1 + i) != *(c2 + i))
			return (*(c1 + i) - *(c2 + i));
		else
			i++;
	}
	return (0);
}
