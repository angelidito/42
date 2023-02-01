/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:01:54 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 15:40:06 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	on_destroy(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	ft_printf("Destroyed window.\nExiting program\n");
	exit(0);
	return (0);
}
