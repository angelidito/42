/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:36:13 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/21 16:05:58 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

void	draw_circle(t_data *img, int x_center, int y_center, int radius)
{
	int	x;
	int	y;

	y = y_center - radius - 1;
	while (y_center + radius >= ++y)
	{
		x = x_center - radius - 1;
		while (x_center + radius >= ++x)
			if (((x - x_center) * (x - x_center) + (y - y_center) * (y
						- y_center)) <= radius * radius)
				my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
	}
}
