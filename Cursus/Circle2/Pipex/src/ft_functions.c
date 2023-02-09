/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:40 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/09 17:08:52 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/**
 * It frees an array of strings.
 * 
 * @param chararr The array of strings to be freed.
 */
void	ft_freechararr(char **chararr)
{
	int i = -1;
	while (chararr[++i])
		free(chararr[i]);
	free(chararr);
}
