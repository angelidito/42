/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:05 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/22 20:24:19 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

// int	asdw(int keycode, t_vars *vars)
// {
// 	static int		o;
// 	static t_data	*img;

// 	if (!o)
// 	{
// 		o = 1;
// 		img->img = mlx_new_image(vars->mlx, 100, 100);
// 		// img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
// 		// 		&img->line_length, &img->endian);
// 		// draw_circle(img->img, 50, 50, 50);
// 	}
// 	if (keycode == KEY_A)
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img,
// 				vars->img->x, vars->img->y);
// 	if (keycode == KEY_S)
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img,
// 				vars->img->x, vars->img->y++);
// 	if (keycode == KEY_D)
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img,
// 				vars->img->x++, vars->img->y);
// 	if (keycode == KEY_W)
// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img,
// 				vars->img->x, vars->img->y--);
// 	return (0);
// }

int	on_keydown(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("Exiting program: keycode %d\n", keycode);
		exit(0);
	}
	printf("keycode: %d\n", keycode);
	// if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D
	// 	|| keycode == KEY_W)
	// 	return (asdw(keycode, vars));
	return (0);
}
