/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:56:35 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/22 22:06:18 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	set_map(const char *file, t_vars *vars)
{
	vars->map = ft_calloc(1, sizeof(t_map));
	if (!vars->map)
		return (-1);
	vars->map->angle = 0.5;
	vars->map->scale = 10;
	vars->map->start.x = 6;
	vars->map->start.y = WIN_H / 2;
	if (set_map_data_matrix(file, vars))
	{
		ft_printf("FREEING: free_map_data_matrix\n");
		free_data_matrix(vars->map);
		free(vars->map);
		return (-1);
	}
	set_map_point_matrix(vars);
	return (0);
}
