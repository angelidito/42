/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:37:20 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/09 14:29:32 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	render_next_frame(t_vars *vars)
{
	vars->img->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	my_mlx_set_data_addr(vars->img);
	set_points(vars, vars->map);
	return (0);
}
