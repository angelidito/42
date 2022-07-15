/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:23:27 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/15 12:02:02 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dst;
	size_t		dstsize;

	if (!s1)
		return (NULL);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(dstsize * sizeof (char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, dstsize);
	ft_strlcat(dst, s2, dstsize);
	return (dst);
}
