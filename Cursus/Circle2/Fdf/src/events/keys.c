/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/25 19:43:46 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"
#include "../../incs/fdf_events.h"

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

	breakpoint();
	angle_diff = 0.02;
	desv_diff = 0.02;
	if (keycode == KEY_S)
	{
		vars->map->angle += angle_diff;
		if (vars->map->angle > 1)
			vars->map->angle = 1;
	}
	else if (keycode == KEY_W)
	{
		vars->map->angle -= angle_diff;
		if (vars->map->angle < 0)
			vars->map->angle = 0;
	}
	else if (keycode == KEY_A)
		desviate(-desv_diff, vars);
	else if (keycode == KEY_D)
		desviate(desv_diff, vars);
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
	int	pos_diff;

	pos_diff = 10;
	ft_printf("%d", pos_diff);
	if (keycode == KEY_UP)
	{
		vars->map->start.y -= pos_diff;
	}
	else if (keycode == KEY_DOWN)
	{
		vars->map->start.y += pos_diff;
	}
	else if (keycode == KEY_LEFT)
	{
		vars->map->start.x -= pos_diff;
	}
	else if (keycode == KEY_RIGHT)
	{
		vars->map->start.x += pos_diff;
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
	if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("Exiting program: keycode %d\n", keycode);
		exit(0);
	}
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D
			|| keycode == KEY_W)
		asdw_keys(keycode, vars);
	else if (keycode >= KEY_LEFT && keycode <= KEY_UP)
		arrow_keys(keycode, vars);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		change_scale(keycode, vars);
	else if (keycode == KEY_INCREASE || keycode == KEY_DECREASE)
		change_z_scale(keycode, vars);
	else if (keycode == KEY_COMMA)
	{
		vars->map->lines_on = (vars->map->lines_on + 1) % 2;
		if (!vars->map->lines_on)
			if (!vars->map->dots_on)
				vars->map->dots_on = 1;
	}
	else if (keycode == KEY_DOT)
	{
		vars->map->dots_on = (vars->map->dots_on + 1) % 3;
		if (!vars->map->dots_on)
			vars->map->lines_on = 1;
	}
	// else if (keycode != 24 && keycode != 27 && keycode >= KEY_1
	// 		&& keycode <= KEY_0)
	// 	number_keys(keycode, vars);
	printf("keycode: %d\n", keycode);
	render_next_frame(vars);
	return (0);
}
