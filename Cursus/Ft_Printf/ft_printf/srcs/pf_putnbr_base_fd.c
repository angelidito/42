/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:28:38 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/03 13:32:04 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

/**
 * It converts a number to a string in a given base
 * 
 * @param nbr the number to be printed
 * @param base the base to convert to
 * @param fd file descriptor
 * @param str the string that will be printed
 * @param k the base
 * 
 * @return The number of characters printed.
 */
ssize_t	ft_putnbr_base_aux(int nbr, char *base, int fd, char str[], int k)
{
	int		i;
	long	num;
	ssize_t	chr_printed;

	chr_printed = 0;
	num = nbr;
	if (nbr < 0)
	{
		num *= -1;
		chr_printed = write(fd, "-", sizeof(char));
	}
	i = -1;
	while (i++ < 32)
		str[i] = ' ';
	i = 0;
	while (num >= k && i < 32)
	{
		str[31 - i] = base[num % k];
		num /= k;
		i++;
	}
	str[31 - i++] = base[num];
	return (chr_printed);
}

/**
 * It checks if the base is valid
 * 
 * @param base the base to convert to
 * 
 * @return the value of base_ok.
 */
int	ft_putnbr_ckeck_base(char *base)
{
	int		base_ok;
	int		i;
	int		j;

	i = -1;
	base_ok = 1;
	if (base[0] == '\0' || base[1] == '\0')
		base_ok = 0;
	while (base[++i] && base_ok)
	{
		if (*base == '+' || *base == '-')
			base_ok = 0;
		j = i;
		while (base[++j] && base_ok)
			if (base[i] == base[j])
				base_ok = 0;
	}
	return (base_ok);
}

/**
 * It prints the number `nbr` in base `base` to the file descriptor `fd`
 * 
 * @param nbr the number to be printed
 * @param base the base to convert to
 * @param fd file descriptor
 * 
 * @return The number of characters printed.
 */
ssize_t	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int		i;
	int		k;
	char	s[32];
	int		base_ok;
	ssize_t	chr_printed;

	chr_printed = 0;
	base_ok = ft_putnbr_ckeck_base(base);
	if (base_ok)
	{
		k = 0;
		while (base[k])
			k++;
		chr_printed = ft_putnbr_base_aux(nbr, base, fd, s, k);
		i = 0;
		while (s[i] == ' ' && i < 32)
			i++;
		while (i < 32)
			chr_printed += write(fd, &s[i++], sizeof(char));
	}
	return (chr_printed);
}
