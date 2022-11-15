/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:30:24 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/15 16:31:47 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/**
 * It prints "Error\n" to the standard error output and terminates the program.
 * 
 * @attention It uses exit function
 */
void	error_free(char **chararr)
{
	free_chararr(chararr);
	error();
}

/**
 * It prints "Error\n" to the standard error output and terminates the program.
 * 
 * @attention It uses exit function
 */
void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
