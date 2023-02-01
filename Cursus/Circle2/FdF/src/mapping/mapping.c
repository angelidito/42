/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:56:35 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 17:13:11 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

/**
 * It sets the variables that control the map's appearance
 * 
 * @param map the map structure
 */
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

/**
 * It reads the map file,
 * allocates memory for the map, and sets the map's variables
 * 
 * @param file the file name of the map
 * @param vars a pointer to the t_vars struct that holds all the variables 
 * for the program.
 * 
 * @return the value of the variable "map"
 */
int	set_map(const char *file, t_vars *vars)
{
	t_map	*map;

	vars->map = ft_calloc(1, sizeof(t_map));
	if (!vars->map)
		return (-1);
	map = vars->map;
	if (set_map_data_matrix(file, vars))
	{
		free_data_matrix(map);
		free(map);
		return (-1);
	}
	set_map_vars(map);
	set_map_point_matrix(vars, map);
	return (0);
}
