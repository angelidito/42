/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:47:46 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 17:11:28 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

/**
 * It changes the scale of the map
 * 
 * @param code the keycode of the key pressed
 * @param vars a pointer to the t_vars struct
 */
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

/**
 * It changes the desviation of the map
 * 
 * @param variation the amount of variation to be applied to the desviation.
 * @param vars A pointer to the t_vars struct.
 * 
 * @return the value 0.
 */
int	change_desviation(double variation, t_vars *vars)
{
	vars->map->desv += variation;
	return (0);
}

/**
 * It changes the z scale of the map
 * 
 * @param keycode the keycode of the key that was pressed
 * @param vars a pointer to the t_vars struct
 */
void	change_z_scale(int keycode, t_vars *vars)
{
	double	scale_diff;

	scale_diff = 1;
	if (keycode == KEY_INCREASE)
		vars->map->z_scale += scale_diff;
	if (keycode == KEY_DECREASE)
		vars->map->z_scale -= scale_diff;
}
