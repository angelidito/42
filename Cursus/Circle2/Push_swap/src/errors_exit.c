/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:30:24 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/16 11:26:13 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/**
 * It frees an array of strings
 * 
 * @param chararr The array of strings to be freed.
 */
void	free_chararr(char **chararr)
{
	size_t	i;

	i = 0;
	while (chararr[i])
		free(chararr[i++]);
	free(chararr);
}

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
