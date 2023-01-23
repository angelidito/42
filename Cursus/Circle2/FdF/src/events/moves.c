/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:47:46 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/23 14:07:19 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

void	change_scale(int code, t_vars *vars)
{
	double	scale_diff;

	scale_diff = 1;
	if (code == MOUSE_SCROLL_UP || code == KEY_PLUS)
	{
		vars->map->abs_scale += scale_diff;
		vars->map->scale += scale_diff;
		if (vars->map->z_scale > 0)
			vars->map->z_scale += scale_diff;
		else if (vars->map->z_scale < 0)
			vars->map->z_scale -= scale_diff;
	}
	else if (code == MOUSE_SCROLL_DOWN || code == KEY_MINUS)
	{
		if (vars->map->abs_scale >= 1 + scale_diff)
		{
			vars->map->abs_scale -= scale_diff;
			if (vars->map->scale >= 1 + scale_diff)
				vars->map->scale -= scale_diff;
			if (vars->map->z_scale >= 1 + scale_diff)
				vars->map->z_scale -= scale_diff;
		}
	}
}

int	desviate(double variation, t_vars *vars)
{
	vars->map->desv += variation;
	// if (vars->map->desv < -1)
	// {
	// 	vars->map->desv = -1;
	// 	return (-1);
	// }
	// else if (vars->map->desv > 1)
	// {
	// 	vars->map->desv = 1;
	// 	return (1);
	// }
	// if (vars->map->desv + 2 > 2)
	// 	vars->map->scale = -0.41 * vars->map->desv + 1.41;
	// else
	// 	vars->map->scale = 0.41 * vars->map->desv + 1.41;
	// vars->map->scale *= vars->map->abs_scale;
	// if (vars->map->scale < 1)
	// 	vars->map->scale = 1;
	return (0);
}

void	change_z_scale(int keycode, t_vars *vars)
{
	double	scale_diff;

	scale_diff = 1;
	if (keycode == KEY_INCREASE)
		vars->map->z_scale += scale_diff;
	if (keycode == KEY_DECREASE)
		vars->map->z_scale -= scale_diff;
}
