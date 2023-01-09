/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/09 18:41:48 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

/**
 * It handles the keys A, S, D and W
 * 
 * @param keycode the key that was pressed
 * @param vars a pointer to the t_vars structure,
	which contains all the variables used in the program.
 * 
 * @return The return value is the keycode of the key pressed.
 */
int	asdw_keys(int keycode, t_vars *vars)
{
	double	angle_diff;
	double	desv_diff;

	angle_diff = 0.02;
	desv_diff = 0.02;
	if (keycode == KEY_S)
	{
		vars->map->angle += angle_diff;
		if (vars->map->angle > 1)
			vars->map->angle = 1;
		printf("angle : %f\n", vars->map->angle);
	}
	else if (keycode == KEY_W)
	{
		vars->map->angle -= angle_diff;
		if (vars->map->angle < 0)
			vars->map->angle = 0;
		printf("angle : %f\n", vars->map->angle);
	}
	else if (keycode == KEY_A)
	{
		desviate(-desv_diff, vars);
		// vars->map->desv -= desv_diff;
		// if (vars->map->desv < -1)
		// {
		// 	vars->map->desv = -1;
		// 	return (-1);
		// }
		// printf("desv  : %f\n", vars->map->desv);
		// if (vars->map->desv < desv_diff)
		// 	vars->map->scale -= desv_diff * 12 / 100;
		// else
		// 	vars->map->scale += desv_diff * 12 / 100;
		// if (vars->map->scale < 1)
		// 	vars->map->scale = 1;
		// printf("scale : %f\n", vars->map->scale);
	}
	else if (keycode == KEY_D)
	{
		desviate(desv_diff, vars);
		// vars->map->desv += desv_diff;
		// if (vars->map->desv > 1)
		// {
		// 	vars->map->desv = 1;
		// 	return (1);
		// }
		// printf("desv  : %f\n", vars->map->desv);
		// if (vars->map->desv < desv_diff)
		// 	vars->map->scale += desv_diff * 12 / 100;
		// else
		// 	vars->map->scale -= desv_diff * 12 / 100;
		// if (vars->map->scale < 1)
		// 	vars->map->scale = 1;
		// printf("scale : %f\n", vars->map->scale);
	}
	return (0);
}

/**
 * It moves the map around the screen, handling the arrow keys..
 * 
 * @param keycode the key that was pressed
 * @param vars a pointer to the structure that contains all the variables 
 * of the program.
 * 
 * @return The return value of the function is an int.
 */
int	arrow_keys(int keycode, t_vars *vars)
{
	int	var;

	var = 5;
	if (keycode == KEY_UP)
	{
		vars->map->start.y -= var;
	}
	else if (keycode == KEY_DOWN)
	{
		vars->map->start.y += var;
	}
	else if (keycode == KEY_LEFT)
	{
		vars->map->start.x -= var;
	}
	else if (keycode == KEY_RIGHT)
	{
		vars->map->start.x += var;
	}
	return (0);
}

// int	number_keys(int keycode, t_vars *vars)
// {
// 	double	scale;
// 	double	compensation;
//     &
// 	if (keycode >= 18 && keycode <= 21)
// 	{
// 		breakpoint();
// 		scale = (keycode - 17);
// 	}
// 	else if (keycode == 23)
// 		scale = 5;
// 	else if (keycode == 22)
// 		scale = 6;
// 	else if (keycode == 26)
// 		scale = 7;
// 	else if (keycode == 28)
// 		scale = 8;
// 	else if (keycode == 25)
// 		scale = 9;
// 	else if (keycode == 29)
// 		scale = 10;
// 	else
// 		return (-1);
// 	if (vars->map->desv >= 0.0000000001 || fabs(vars->map->desv) == 0)
// 		compensation = scale * 0.2 * 1 - vars->map->desv;
// 	// else
// 	// 	compensation = scale * 0.2 * 0 - vars->map->desv;
// 	if (compensation < 0)
// 		compensation *= -1;
// 	scale += compensation;
// 	vars->map->scale = scale;
// 	printf("compensation %f\n", compensation);
// 	printf("scale %f\n", scale);
// 	printf("desv  : %f\n", vars->map->desv);
// 	printf("scale : %f\n", vars->map->scale);
// 	return (0);
// }
int	on_keydown(int keycode, t_vars *vars)
{
	int	return_code;

	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("Exiting program: keycode %d\n", keycode);
		exit(0);
	}
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D
			|| keycode == KEY_W)
		return_code = asdw_keys(keycode, vars);
	else if (keycode >= KEY_LEFT && keycode <= KEY_UP)
		return_code = arrow_keys(keycode, vars);
	// else if (keycode != 24 && keycode != 27 && keycode >= KEY_1
	// 		&& keycode <= KEY_0)
	// 	return_code = number_keys(keycode, vars);
	else
		return_code = 0;
	printf("keycode: %d\n", keycode);
	render_next_frame(vars);
	return (return_code);
}
