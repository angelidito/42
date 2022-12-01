/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:01:54 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/01 15:13:35 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	on_destroy(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	printf("Closing X\n");
	quit(1);
	return (0);
}
