/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:02:11 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/09 14:51:57 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

/**
 * It hooks the window to thefunctions that will be called when the user 
 * interacts with the window
 * 
 * @param vars a pointer to the t_vars struct
 */
void	hooks(t_vars *vars)
{
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, on_keydown, vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, 1L << 0, on_mousemove, vars);
	mlx_hook(vars->win, ON_MOUSEDOWN, 1L << 0, on_mousedown, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 0, on_destroy, vars);
}
