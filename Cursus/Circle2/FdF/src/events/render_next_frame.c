/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:37:20 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/10 20:48:58 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	render_next_frame(t_vars *vars)
{
	vars->img->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	my_mlx_set_data_addr(vars->img);
	set_points(vars, vars->map);
	printf("abs_scale : %f\n", vars->map->abs_scale);
	printf("  z_scale : %f\n", vars->map->z_scale);
	printf("    scale : %f\n", vars->map->scale);
	printf("    angle : %f\n", vars->map->angle);
	printf("     desv : %f\n", vars->map->desv);
	return (0);
}
