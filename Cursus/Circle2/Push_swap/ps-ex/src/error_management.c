/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:40:58 by danicn            #+#    #+#             */
/*   Updated: 2022/10/20 19:51:16 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	int		i;
	long	res;
	long	coeff;

	i = 0;
	res = 0;
	coeff = 1;
	while (s[i] && (s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i])
		return (0);
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		coeff = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * coeff);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	equal_number(char **argv, int i)
{
	int	k;
	int	q;

	q = 0;
	k = 1;
	while (k < i)
	{
		q = ft_strcmp(argv[i], argv[k]);
		if (q == 0)
			exit_error();
		k++;
	}
}

void	limits(char *arg)
{
	int		v;
	long	num;

	v = ft_strlen(arg);
	if (v > 11)
		exit_error();
	if (v == 10 || v == 11)
	{
		num = atol(arg);
		if (num < -2147483648 || num > 2147483647)
			exit_error();
	}
}

void	args_err(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strlen(argv[i]) > 11)
			exit_error();
		j = 0;
		while (argv[i][j] != 0)
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
				exit_error();
			j++;
		}
		limits(argv[i]);
		equal_number(argv, i);
		i++;
	}
}
