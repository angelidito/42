/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:56:35 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/07 16:14:00 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	set_map(const char *file, t_vars *vars)
{
	t_map	*map;

	vars->map = ft_calloc(1, sizeof(t_map));
	if (!vars->map)
		return (-1);
	map = vars->map;
	map->desv = 1;
	map->angle = 0.9;
	map->scale = 30.0;
	map->z_scale = 30;
	map->start.x = 6 ;
	map->start.y = 3 * WIN_H / 4;
	if (set_map_data_matrix(file, vars))
	{
		ft_printf("FREEING: free_map_data_matrix\n");
		free_data_matrix(map);
		free(map);
		return (-1);
	}
	set_map_point_matrix(vars, map);
	return (0);
}
