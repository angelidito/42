/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:54:06 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/11 17:15:05 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	len;

	if (!n)
		return (1);
	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*a;
	size_t	len;
	int		sign;
	int		x;

	x = n;
	len = ft_intlen(n);
	a = malloc(len + 1);
	if (!a)
		return (NULL);
	a[len] = '\0';
	while (0 < len--)
	{
		if (x % 10 < 0)
			sign = -1;
		else
			sign = 1;
		a[len] = '0' + (x % 10) * sign;
		x /= 10;
	}
	if (n < 0)
		a[0] = '-';
	return (a);
}
