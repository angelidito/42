/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:44:42 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/25 19:32:39 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

void	draw_line(t_vars *vars, t_point begin, t_point end)
{
	double delta_x;
	double delta_y;
	int pixels;
	double pixel_x;
	double pixel_y;

	delta_x = end.x - begin.x;
	delta_y = end.y - begin.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = begin.x;
	pixel_y = begin.y;
	while (pixels)
	{
		if (pixel_x >= 0 && pixel_x < WIN_W && pixel_y >= 0 && pixel_y < WIN_H)
			if (!(((pixel_x == begin.x && pixel_y == begin.y)
						|| (pixel_x == end.x && pixel_y == end.y))
					&& vars->map->dots_on))
				my_mlx_pixel_put(vars->img, pixel_x, pixel_y, get_argb(0, 200,
							0, 0));
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}