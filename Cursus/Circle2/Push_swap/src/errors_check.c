/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:30:08 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/15 16:29:14 by angmarti         ###   ########.fr       */
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
long	ft_getsign(const char *p, unsigned long *i)
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
 * It takes a string, and returns the integer value of the string.
 * If the number is not in the int range, it will return the error code
 * 6666666666.
 * 
 * @param str The string to be converted.
 * 
 * @return the number of characters that are in the string.
 */
size_t	ps_atoi(const char *str)
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
	if ((n >= 2147483648 || n < -2147483648) && sign == 1)
		return (6666666666);
	else if ((n > 2147483648 || n < -2147483648) && sign == -1)
		return (6666666666);
	return (sign * n);
}

/**
 * It checks if a string is a number
 * 
 * @param str The string to check.
 */
int	isnumber(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (str[0] == '-' && !str[1])
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

/**
 * It checks for errors in the input
 * 
 * @param chararr the array of strings to be checked
 */
void	check_errors_chararr(char **chararr)
{
	int		i;
	int		j;
	long	n;

	i = -1;
	while (chararr[++i])
	{
		n = ft_strlen(chararr[i]);
		if (!n)
			continue ;
		if (n > 11 || (n > 10 && chararr[i][0] != '-'))
			error_free(chararr);
		if (!isnumber((char *)chararr[i]))
			error_free(chararr);
		if (ps_atoi(chararr[i]) == 6666666666)
			error_free(chararr);
		j = i;
		while (chararr[++j])
			if (n == (long)ft_strlen(chararr[j]) && !ft_strncmp(chararr[i],
					chararr[j], n))
				error_free(chararr);
	}
}

/**
 * It checks for any error in the arguments and terminates the program if found
 * 
 * @param argc the number of arguments passed to the program
 * @param argv The array of arguments passed to the program.
 * 
 * @attention It uses exit function
 * 
 */
void	check_errors_argv(int argc, const char *argv[])
{
	int		i;
	int		j;
	long	n;

	if (argc < 2)
		exit(0);
	i = 0;
	while (argv[++i])
	{
		n = ft_strlen(argv[i]);
		if (n > 11 || (n > 10 && argv[i][0] != '-'))
			error();
		if (!isnumber((char *)argv[i]))
			error();
		if (ps_atoi(argv[i]) == 6666666666)
			error();
		j = i;
		while (argv[++j])
			if (n == (long)ft_strlen(argv[j]) && !ft_strncmp(argv[i], argv[j],
					n))
				error();
	}
}
