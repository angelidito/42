/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:30:08 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/03 16:33:55 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/**
 * It returns the sign of the number, or 0 if there is no number
 * 
 * @param p The string to be parsed.
 * @param i the index of the string
 * 
 * @return The sign of the number.
 */
static long	ft_getsign(const char *p, unsigned long *i)
{
	char	c;

	while (*(p + *i))
	{
		c = *(p + *i);
		*i = *i + 1;
		if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
			|| c == '\f')
			continue ;
		if (c == '+' || c == '-')
			return ((c - 44) * (-1));
		if (ft_isdigit((int)c))
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
size_t	ft_atos(const char *str)
{
	unsigned long	i;
	long			sign;
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

/**
 * It checks if a string is a number
 * 
 * @param str The string to check.
 */
int	ft_isnumber(char *str)
{
	int	i;

	if (!str || *str)
		return (0);
	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

/**
 * It checks for errors in the arguments
 * 
 * @param argc the number of arguments passed to the program
 * @param argv The array of arguments passed to the program.
 * 
 * @return The number of errors.
 */
int	check_errors(int argc, const char *argv[])
{
	int		errors;
	int		i;
	int		j;
	long	n;

	errors = 0;
	if (argc < 2)
		exit(1);
	i = 0;
	while (argv[++i])
	{
		if (!ft_isnumber((char *)argv[i]))
			error();
		n = ft_atos(argv[i]);
		if (n < -2147483648 || n > 2147483647)
			error();
		j = i;
		n = ft_strlen(argv[i]);
		while (argv[++j])
			if (n == (long) ft_strlen(argv[j]) && !ft_strncmp(argv[i], argv[j], n))
				error();
	}
	return (errors);
}

/**
 * It prints it to the standard error output and terminates the program
 */
void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
