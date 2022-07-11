/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:22:32 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/11 17:09:20 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\r' || c == '\f');
}

/*int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}*/

// '+' value is 43; '-' value es 45; That's how sign is calculated.
int	ft_getsign(const char *p, unsigned long *i)
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

int	ft_atoi_logic(const char *p, unsigned long i)
{
	int				n;

	n = 0;
	while (*(p + i))
	{
		if (!ft_isdigit((int) *(p + i)))
			return (n);
		n = n * 10 + (*(p + i) - '0');
		i++;
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	unsigned long	i;
	int				sign;
	int				n;

	n = 0;
	sign = 0;
	i = 0;
	sign = ft_getsign(str, &i);
	if (!sign)
		return (0);
	n = ft_atoi_logic(str, i);
	return (sign * n);
}
