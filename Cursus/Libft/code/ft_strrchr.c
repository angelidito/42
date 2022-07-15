/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:34:46 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/14 18:09:23 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (!c)
		return ((char *) s + i);
	while (i-- > 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *) s + i);
	}
	return (NULL);
}
