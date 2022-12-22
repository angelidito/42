/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_matrix_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:36:25 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/22 20:05:47 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

/**
 * It counts the number of words in a line
 * 
 * @param line The line of text that was read from the file.
 * 
 * @return The number of words in the line.
 */
int	words_calc(char **line)
{
	int	j;
	int	words;

	j = 0;
	words = 0;
	while (line[j])
		if (*line[j++])
			words++;
	return (words);
}

/**
 * It frees the memory allocated for the data matrix
 * 
 * @param i the number of rows in the matrix
 * @param data_matrix The matrix that will be freed.
 */
void	free_data_matrix_i(int i, int **data_matrix)
{
	while (i-- > 0)
		free(data_matrix[i]);
	free(data_matrix);
}

void	free_data_matrix(t_map *map)
{
	int	i;

	i = 0;
	while (map->data_matrix[i])
		free(map->data_matrix[i++]);
	free(map->data_matrix);
}
