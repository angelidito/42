/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:54:06 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It returns the number of digits in an integer
 * 
 * @param n the number to be converted
 * 
 * @return The length of the number.
 */
static int	ft_intlen(int n)
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

/**
 * It takes an integer and returns a string representation of that integer
 * 
 * @param n the number to be converted to a string
 * 
 * @return A pointer to a string.
 */
char	*ft_itoa(int n)
{
	char	*a;
	size_t	len;
	int		sign;
	int		x;

	x = n;
	len = ft_intlen(n);
	a = malloc((1 + len) * sizeof (char));
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
