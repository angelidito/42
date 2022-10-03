/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:21:11 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/03 12:21:13 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
// #include "../psegura-printf/ft_printf.h"

int	main(void)
{	
	char	*str = "Printing_F";
	unsigned int		n;
	unsigned char	c;

	n = 42;
	c = 'P';
	printf("%%c\n");
	ft_printf("%c\n", str[0]);
	printf("%c\n", str[0]);
	printf("\n%%s\n");
	ft_printf("%s\n", str);
	printf("%s\n", str);
	printf("\n%%p\n");
	ft_printf("%p\n", str);
	printf("%p\n", str);
	printf("\n%%d\n");
	ft_printf("%d\n", n);
	printf("%d\n", n);
	printf("\n%%i\n");
	ft_printf("%i\n", n);
	printf("%i\n", n);
	printf("\n%%u\n");
	ft_printf("%u\n", n);
	printf("%u\n", n);
	printf("\n%%x\n");
	ft_printf("%x\n", n);
	printf("%x\n", n);
	printf("\n%%X\n");
	ft_printf("%X\n", n);
	printf("%X\n", n);
	printf("\n\n");


	printf("\n%%p\n");
	ft_printf("%p\n", &c);
	printf("%p\n", &c);
	printf("\n%%p\n");
	ft_printf("%p\n", &n);
	printf("%p\n", &n);
	return (0);
}
