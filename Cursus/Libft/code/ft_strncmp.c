/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:46:57 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/04 13:54:22 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrcmp(unsigned char c1, unsigned char c2)
{
	return (c1 - c2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	//"1234", "1235", 4
	i = 0;
	while (i < n)
	{
		if(ft_chrcmp(s1[i], s2[i]))
			return (ft_chrcmp(s1[i], s2[i]));
		else if (!*(s1 + i))
			return (0 - s2[i]);
		else if (!*(s2 + i))
			return (s1[i]);
		else
			i++;
	}
	return (0);
}
