/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_datamatrix.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:59:55 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/22 20:07:06 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_DATAMATRIX_H
# define AUX_DATAMATRIX_H

int		words_calc(char **line);
void	free_data_matrix_i(int i, int **data_matrix);

#endif
