/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:34:46 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/05 14:03:04 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	i;
	unsigned long	p;

	i = 0;
	p = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			p = i;
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	if (p != 0)
		return ((char *)(s + p));
	if (p == 0 && (char)*s == (char)c)
		return ((char *)s);
	return (NULL);
}
