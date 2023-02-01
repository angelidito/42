/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:59:55 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 14:35:06 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_EVENTS_H
# define FDF_EVENTS_H

# include "fdf.h"

int		words_calc(char **line);
int		desviate(double variation, t_vars *vars);
void	change_scale(int code, t_vars *vars);
void	change_z_scale(int keycode, t_vars *vars);
void	free_data_matrix_i(int i, int **data_matrix);

#endif
