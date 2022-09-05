/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:01:43 by psegura-          #+#    #+#             */
/*   Updated: 2022/07/22 10:50:38 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//Librerías de C
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

//Printf
int	ft_printf(char const *string, ...) __attribute__((format(printf, 1, 2)));

//Utils
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_strlen(char *str);

//Put_nbr
int	ft_putnbr_base(size_t nbr, char *b);
int	ft_putnbr(int n);
int	ft_pointer(void *p);

#endif
