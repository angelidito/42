/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:22:32 by angmarti          #+#    #+#             */
/*   Updated: 2022/06/30 14:43:45 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\r' || c == '\f');
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}

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

/*#include <stdlib.h>
#include <stdio.h>

void	test(int test, char *str)
{
	int	expected;
	int	obtained;

	expected = atoi(str);
	obtained = ft_atoi(str);
	if (expected == obtained)
	{
		printf("Test %d: OK!\n", test);
		//printf("%d\t<- %s\n", obtained, str);
	}
	else
	{
		printf("\nTest %d: Error ?!?!?!?!?!?!?\n", test);
		//printf("     Attention: human check is needed here if there ");
		//printf("are more than one consecutive '+' or '-' before numbers\n");
		printf("       str: %s\n", str);
		printf("  Expected: %d\n", expected);
		printf("  Obtained: %d\n", obtained);
		printf("\n");
	}
}

int	main(void)
{
	int	t;

	t = 0;
	test(t++, "");
	test(t++, "+2147483649");
	test(t++, "+2147483649984563457d98fgdghdkjgd");
	test(t++, "+2147483648");
	test(t++, "21474836489");
	test(t++, "-2147483647");
	test(t++, "-2147483648");
	test(t++, "-999999999999999");
	test(t++, "0");
	test(t++, "-0");
	test(t++, "-1");
	test(t++, "1");
	test(t++, "+1234");
	test(t++, "+12 34");
	test(t++, "+12-34");
	test(t++, "12 34");
	test(t++, "12a34");
	test(t++, "12ç34");
	test(t++, "a1234");
	test(t++, "  -  1234");
	test(t++, "  -1234");
	test(t++, " 	 -1234");
	test(t++, " \n 		 -1234");
	test(t++, "+-1234");
	test(t++, "-+-1234");
	test(t++, "-+--1234");
	test(t++, "-+-1-234");
	test(t++, "--1");
	test(t++, "---1");
	return (0);
}*/
