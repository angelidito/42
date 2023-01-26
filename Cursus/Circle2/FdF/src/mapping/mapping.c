/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:56:35 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/26 13:52:17 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

void	set_map_vars(t_map *map)
{
	int	aux;

	map->desv = 0;
	map->desv = -0.8;
	aux = 3 * WIN_W / 4 / (sqrt(map->width * map->width * 2));
	map->dots_on = 0;
	map->lines_on = 1;
	map->angle = 1;
	map->angle = 0.4;
	map->start.x = 2 * WIN_W / 4;
	map->start.y = 2 * WIN_H / 4;
	map->abs_scale = 1.0;
	if (aux > 0)
		map->abs_scale = aux;
	map->scale = map->abs_scale;
	map->z_scale = map->abs_scale;
}

int	set_map(const char *file, t_vars *vars)
{
	t_map	*map;

	vars->map = ft_calloc(1, sizeof(t_map));
	if (!vars->map)
		return (-1);
	map = vars->map;
	if (set_map_data_matrix(file, vars))
	{
		ft_printf("FREEING: free_map_data_matrix\n");
		free_data_matrix(map);
		free(map);
		return (-1);
	}
	set_map_vars(map);
	set_map_point_matrix(vars, map);
	return (0);
}
