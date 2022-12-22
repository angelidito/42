/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:36:13 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/22 22:13:37 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

void	draw_circle(t_data *img, int x_center, int y_center, int radius)
{
	int	x;
	int	y;
	int	color;

	color = get_opposite(get_opposite(get_argb(0, 255, 255, 0)));
	y = y_center - radius - 1;
	while (y_center + radius >= ++y)
	{
		x = x_center - radius - 1;
		while (x_center + radius >= ++x)
			if (((x - x_center) * (x - x_center) + (y - y_center) * (y
						- y_center)) <= radius * radius)
				if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H)
				my_mlx_pixel_put(img, x, y, color);
	}
}
