/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:36:13 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 17:08:28 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

/**
 * It draws a circle
 * 
 * @param vars the structure containing all the variables
 * @param x_center the x coordinate of the center of the circle
 * @param y_center the y coordinate of the center of the circle
 * @param radius the radius of the circle
 */
void	draw_circle(t_vars *vars, int x_center, int y_center, int radius)
{
	int		x;
	int		y;
	int		color;
	t_data	*img;

	img = vars->img;
	color = (get_opposite(get_argb(0, 200, 0, 0)));
	y = y_center - radius - 1;
	while (y_center + radius >= ++y)
	{
		x = x_center - radius - 1;
		while (x_center + radius >= ++x)
			if (((x - x_center) * (x - x_center) + (y - y_center) * (y
						- y_center)) <= radius * radius)
				if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
					my_mlx_pixel_put(img, x, y, color);
	}
}
