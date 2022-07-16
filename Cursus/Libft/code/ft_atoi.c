/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:22:32 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/16 12:27:22 by angmarti         ###   ########.fr       */
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
	int				sign;
	long long int	n;

	i = 0;
	sign = ft_getsign(str, &i);
	if (!sign)
		return (0);
	n = 0;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if ((n > 2147483648 || n < -2147483648) && sign == 1)
		return (-1);
	else if ((n > 2147483648 || n < -2147483648) && sign == -1)
		return (0);
	return (sign * n);
}
