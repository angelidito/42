/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:37:20 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 16:51:13 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

/**
 * It creates a new image, sets the data address of the image, sets the points 
 * of the image, and then puts the image to the window.
 * 
 * Include this for more info:
 * 	printf("abs_scale : %f\n", vars->map->abs_scale);
 *	printf("  z_scale : %f\n", vars->map->z_scale);
 *	printf("    scale : %f\n", vars->map->scale);
 *	printf("    angle : %f\n", vars->map->angle);
 *	printf("     desv : %f\n", vars->map->desv);
 *
 * @param vars a pointer to the t_vars structure
 * 
 * @return The return value is the address of the first element of the array.
 */
int	render_next_frame(t_vars *vars)
{
	vars->img->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	my_mlx_set_data_addr(vars->img);
	set_points(vars, vars->map);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}
