/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:01:54 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/09 14:54:04 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	on_destroy(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	printf("Closing X\n");
	exit(1);
	return (0);
}
