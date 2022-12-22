/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:05 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/23 00:36:46 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	asdw_keys(int keycode, t_vars *vars)
{
	if (keycode == KEY_S)
	{
		vars->map->angle += 0.01;
		if (vars->map->angle > 1)
			vars->map->angle = 1;
		printf("angle : %f\n", vars->map->angle);
	}
	else if (keycode == KEY_W)
	{
		vars->map->angle -= 0.01;
		if (vars->map->angle < 0)
			vars->map->angle = 0;
		printf("angle : %f\n", vars->map->angle);
	}
	else if (keycode == KEY_A)
	{
		vars->map->desv -= 0.01;
		vars->map->scale -= 0.01;
		// if (vars->map->desv < 0)
		// vars->map->desv = 0;
		printf("desv : %f\n", vars->map->desv);
	}
	else if (keycode == KEY_D)
	{
		vars->map->scale += 0.01;
		vars->map->desv += 0.01;
		// if (vars->map->desv > 1)
		// vars->map->desv = 1;
		printf("desv : %f\n", vars->map->desv);
	}
	return (0);
}
int	arrows_keys(int keycode, t_vars *vars)
{
	if (keycode == KEY_UP)
	{
		vars->map->start.y-=2;
		// if (vars->map->start.x > 1)
		// 	vars->map->start.x = 1;
		printf("start.x : %d\n", vars->map->start.y);
	}
	else if (keycode == KEY_DOWN)
	{
		vars->map->start.y+=2;
		// if (vars->map->start.x < 0)
		// 	vars->map->start.x = 0;
		printf("start.x : %d\n", vars->map->start.y);
	}
	else if (keycode == KEY_LEFT)
	{
		vars->map->start.x-=2;
		// if (vars->map->start.y < 0)
		// vars->map->start.y = 0;
		printf("start.y : %d\n", vars->map->start.x);
	}
	else if (keycode == KEY_RIGHT)
	{
		vars->map->start.x+=2;
		// if (vars->map->start.y > 1)
		// vars->map->start.y = 1;
		printf("start.y : %d\n", vars->map->start.x);
	}
	return (0);
}

int	on_keydown(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("Exiting program: keycode %d\n", keycode);
		exit(0);
	}
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D
			|| keycode == KEY_W)
		return (asdw_keys(keycode, vars));
	else if (keycode >= KEY_LEFT && keycode <= KEY_UP)
		return (arrows_keys(keycode, vars));
	printf("keycode: %d\n", keycode);
	return (0);
}
