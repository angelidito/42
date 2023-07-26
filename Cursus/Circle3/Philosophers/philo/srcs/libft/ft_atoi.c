/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:22:32 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 18:20:33 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

/**
 * It returns 1 if the character is a whitespace, and 0 otherwise.
 * Whitespace can be space, tab, newline, vertical tab, carriage return, or 
 * form feed (' ', '\\t', '\\n', '\\v', '\\r' and '\\f', respectively).
 * 
 * @param c The character to be checked.
 * 
 * @return 1 if the character is a whitespace. Otherwise, it returns 0.
 */
int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
		|| c == '\f');
}

/**
 * It checks if the character is a digit.
 * 
 * @param c The character to be checked.
 * 
 * @return The character that is being checked.
 */
int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}

/**
 * It returns the sign of the number, or 0 if there is no sign
 * 
 * @param p The string to be parsed.
 * @param i the index of the string
 * 
 * @return The sign of the number.
 */
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

/**
 * It takes a string, and returns the integer value of the string
 * 
 * @param str The string to be converted.
 * 
 * @return the integer value of the string passed as argument.
 */
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
