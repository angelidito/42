/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:22:52 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/21 16:07:52 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"
#include <mlx.h>

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

	// Do not knock making a ft_offset
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
char	*my_mlx_get_data_addr(t_data *img)
{
	return (mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
			&img->endian));
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello Mori!");
	// mlx_loop(mlx);
	img.img = mlx_new_image(mlx, 1920, 1080);
	/* 
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// 			&img.line_length, &img.endian);
	img.addr = my_mlx_get_data_addr(&img);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	draw_circle(&img, 500, 500, 100);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
