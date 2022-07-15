/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:22:32 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/14 19:34:31 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\r' || c == '\f');
}

static int	ft_getsign(const char *p, unsigned long *i)
{
	char	c;

	while (*(p + *i))
	{
		c = *(p + *i);
		*i = *i + 1;
		if (ft_isspace(c))
			continue ;
		if (c == '+' || c == '-')
			return ((c - 44) * (-1));
		if (ft_isdigit((int) c))
		{
			*i = *i - 1;
			return (1);
		}
		break ;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	i;
	long long int	sign;
	long long int	n;

	n = 0;
	sign = 0;
	i = 0;
	sign = ft_getsign(str, &i);
	if (!sign)
		return (0);
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (sign * n);
}
