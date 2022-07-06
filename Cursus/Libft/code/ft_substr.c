/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:08:44 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/06 13:21:33 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	if (ft_strlen(s) - start - 1 < len)
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
