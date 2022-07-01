/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:00:37 by angmarti          #+#    #+#             */
/*   Updated: 2022/06/30 21:54:51 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*p;
	char			ch;
	unsigned long	i;

	i = 0;
	ch = (char) c;
	p = (char *) s;
	while (*(p + i) != ch || ch != '\0')
		i++;
	if (*(p + i) == ch)
		return (p + i);
	return (NULL);
}
