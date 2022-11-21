/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:36:13 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/21 15:47:53 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

void	draw_sqr1(t_data *img, int x_start, int y_start, int side_len)
{
	int	x;
	int	y;

	y = y_start - 1;
	while (y_start + side_len - ++y > 0)
	{
		x = x_start - 1;
		while (x_start + side_len - ++x > 0)
				my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
	}
}

void	draw_sqr0(t_data *img, int x_start, int y_start, int side_len)
{
	int	x;
	int	y;

	y = y_start - 1;
	while (y_start + side_len - ++y > 0)
	{
		x = x_start - 1;
		while (x_start + side_len - ++x > 0)
		{
			if (y == y_start || y == y_start + side_len - 1 || x == x_start
				|| x == x_start + side_len - 1)
				my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
			// else
			// printf("x = %d; %d\n", x, x_start + side_len);
			// else
			// 	my_mlx_pixel_put(img, x, y, x);
		}
	}
}
