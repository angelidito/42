/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:54:06 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/10 20:09:48 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int ft_intlen(int n)
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
	printf("\nlen: %d\n", len);
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
	sign = 1;
	a[len] = '\0';
	if (n < 0)
	{
		a[0] = '-';
		sign = -1;
	}
	while ((0 < len && sign == 1)
		|| (1 < len && sign == -1))
	{
		len--;
		
		a[len] = '0' + sign * n % 10;
		n /= 10;
	}
	return (a);
}
int main(void)
{
	printf("%s\n", ft_itoa(1234));
	printf("%s\n", ft_itoa(-1234));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(00000));
	printf("%s\n", ft_itoa(-0));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
}
