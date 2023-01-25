/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:22:52 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/25 17:29:05 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

/**
 * It takes a t_data struct, an x and y coordinate, and a color, and it puts
 * a pixel at that coordinate with that color
 * 
 * ! The image is represented in real time in a window, changing  it will cause
 * ! a bunch of screen-tearing when writing to it.
 * ! Create two or more images to hold the frames temporarily.
 * ! Then write to a temporary image.
 * 
 * @param data the structure that contains all the information about the image
 * @param x the x-coordinate of the pixel
 * @param y the y-coordinate of the pixel
 * @param color the color of the pixel
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	// if (!(x >= 0 && x < WIN_W && y >= 0 && y < WIN_H))
	// 	return ;
	// Think about making a ft_offset function
	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

/**
 * It returns the address of the data of the image
 * 
 * @param img the image to get the data from
 * 
 * @return The address of the first pixel of the image.
 */
char	*my_mlx_set_data_addr(t_vars *vars)
{
	t_data	*img;

	img = &vars->img;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img->addr);
}

void	hooks(t_vars *vars)
{
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, on_keydown, vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, 1L << 0, on_mousemove, vars);
	mlx_hook(vars->win, ON_MOUSEDOWN, 1L << 0, on_mousedown, vars);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "Hello Mori!");
	img.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	vars.img = &img;
	hooks(&vars);
	my_mlx_set_data_addr(&vars);
	draw_circle(&vars, 500, 500, 100);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
