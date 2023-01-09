/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:22:52 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/09 14:56:12 by angmarti         ###   ########.fr       */
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

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

/**
 * It sets and returns the address of the data of the image
 * 
 * @param img the image to get the data from
 * 
 * @return The address of the first pixel of the image.
 */
char	*my_mlx_set_data_addr(t_data	*img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
			&img->endian);
	return (img->addr);
}

void	leaks(void)
{
	ft_printf("\033[7;49;33m");
	system("leaks -q fdf");
}

int	main(int argc, const char *argv[])
{
	t_vars	vars;

	atexit(leaks);
	if (argc != 2)
	{
		ft_printf("\033[0;34mUsage : %s <filename>\n\n", *argv);
		return (-1);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "Hello Mori!");
	vars.img = ft_calloc(1, sizeof (t_data));
	vars.img->img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	hooks(&vars);
	my_mlx_set_data_addr(vars.img);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	if (set_map(argv[1], &vars))
		return (-1);
	// mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	render_next_frame(&vars);
	mlx_loop(vars.mlx);
	free_data_matrix(vars.map);
	free(vars.map);
	// int		i;
	// int		j;
	// i = -1;
	// j = -1;
	// while (vars.map_matrix[++i])
	// 	while (vars.map_matrix[i][++j])
	// 		ft_printf("%d ", vars.map_matrix[i][j]);
	return (0);
}

void	breakpoint(void)
{
	ft_printf("______BREAKPOINT______\n");
}
