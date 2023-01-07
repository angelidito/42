/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/07 18:02:27 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

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
		vars->map->desv -= desv_diff;
		if (vars->map->desv < -1)
		{
			vars->map->desv = -1;
			return (0);
		}
		printf("desv  : %f\n", vars->map->desv);
		if (vars->map->desv < desv_diff)
			vars->map->scale -= desv_diff * 12;
		else
			vars->map->scale += desv_diff * 12;
		if (vars->map->scale < 1)
			vars->map->scale = 1;
		printf("scale : %f\n", vars->map->scale);
	}
	else if (keycode == KEY_D)
	{
		vars->map->desv += desv_diff;
		if (vars->map->desv > 1)
		{
			vars->map->desv = 1;
			return (0);
		}
		printf("desv  : %f\n", vars->map->desv);
		if (vars->map->desv < desv_diff)
			vars->map->scale += desv_diff * 12;
		else
			vars->map->scale -= desv_diff * 12;
		if (vars->map->scale < 1)
			vars->map->scale = 1;
		printf("scale : %f\n", vars->map->scale);
	}
	return (0);
}

int	arrows_keys(int keycode, t_vars *vars)
{
	int	var;

	var = 5;
	if (keycode == KEY_UP)
	{
		vars->map->start.y -= var;
		// if (vars->map->start.x > 1)
		// 	vars->map->start.x = 1;
		printf("start.x : %d\n", vars->map->start.y);
	}
	else if (keycode == KEY_DOWN)
	{
		vars->map->start.y += var;
		// if (vars->map->start.x < 0)
		// 	vars->map->start.x = 0;
		printf("start.x : %d\n", vars->map->start.y);
	}
	else if (keycode == KEY_LEFT)
	{
		vars->map->start.x -= var;
		// if (vars->map->start.y < 0)
		// vars->map->start.y = 0;
		printf("start.y : %d\n", vars->map->start.x);
	}
	else if (keycode == KEY_RIGHT)
	{
		vars->map->start.x += var;
		// if (vars->map->start.y > 1)
		// vars->map->start.y = 1;
		printf("start.y : %d\n", vars->map->start.x);
	}
	return (0);
}

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
		return_code = arrows_keys(keycode, vars);
	else
		return_code = 0;
	printf("keycode: %d\n", keycode);
	render_next_frame(vars);
	return (return_code);
}
