/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:22:52 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 17:16:09 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

/**
 * It takes a t_data struct, an x and y coordinate, and a color, and it puts 
 * a pixel at that coordinate with that color
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
char	*my_mlx_set_data_addr(t_data *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img->addr);
}

/**
 * It runs the command `leaks -q fdf` and prints the result in yellow.
 * Usage: atexit(leaks);
 */
void	leaks(void)
{
	ft_printf("\033[0m\n\033[7;49;33m");
	system("leaks -q fdf");
	ft_printf("\033[0m");
}

/**
 * It prints a message to the standard output
 */
void	breakpoint(void)
{
	ft_printf("______BREAKPOINT______\n");
}

/**
 * It initializes the mlx library, 
 * creates a window, 
 * creates an image, 
 * sets the image data address,
 * reads the map, 
 * renders the first frame,
 * starts the loop,
 * and frees vars.
 * 
 * @param argc the number of arguments passed to the program
 * @param argv the arguments passed to the program
 * 
 * @return The return value of the last expression in the function.
 */
int	main(int argc, const char *argv[])
{
	t_vars	vars;

	atexit(leaks);
	if (argc != 2)
	{
		ft_printf("\n\033[0;34mUsage : %s <filename>\n\n", *argv);
		return (-1);
	}
	ft_printf("Map: %s\n", argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, (char *) argv[1]);
	vars.img = ft_calloc(1, sizeof(t_data));
	vars.img->img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	hooks(&vars);
	my_mlx_set_data_addr(vars.img);
	if (set_map(argv[1], &vars))
		return (-1);
	render_next_frame(&vars);
	mlx_loop(vars.mlx);
	free_data_matrix(vars.map);
	free(vars.map);
	return (0);
}
