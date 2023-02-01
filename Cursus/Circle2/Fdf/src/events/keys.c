/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 16:53:55 by angmarti         ###   ########.fr       */
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
		change_desviation(-desv_diff, vars);
	else if (keycode == KEY_D)
		change_desviation(desv_diff, vars);
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

void	dot_n_comma(int keycode, t_vars *vars)
{
	if (keycode == KEY_COMMA)
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
}

int	on_keydown(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_printf("Exiting program: keycode %d\n", keycode);
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
	else if (keycode == KEY_COMMA || keycode == KEY_DOT)
		dot_n_comma(keycode, vars);
	render_next_frame(vars);
	return (0);
}
