/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:04:21 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 14:20:08 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

void	point_print(int x, int y, int z, t_vars *vars)
{
	if (vars->map->lines_on)
	{
		if (y != 0)
			draw_line(vars, vars->map->point_matrix[y - 1][x],
				vars->map->point_matrix[y][x]);
		if (x != 0)
			draw_line(vars, vars->map->point_matrix[y][x - 1],
				vars->map->point_matrix[y][x]);
	}
	if (vars->map->dots_on)
		draw_circle(vars, vars->map->point_matrix[y][x].x,
			vars->map->point_matrix[y][x].y, vars->map->dots_on - 1);
	z++;
}

int	point_calc(int x, int y, t_vars *vars)
{
	int		z;
	double	sin_theta;
	double	cos_theta;
	t_map	*map;
	t_point	p;

	map = vars->map;
	z = map->data_matrix[y][x] * map->z_scale * (1 - map->angle);
	sin_theta = sin(map->desv);
	cos_theta = cos(map->desv);
	p.x = ((x - map->width / 2) * cos_theta - (y - map->height / 2) * sin_theta)
		* map->scale;
	p.y = ((y - map->height / 2) * cos_theta + (x - map->width / 2) * sin_theta)
		* map->scale * map->angle;
	p.x += map->start.x;
	p.y += map->start.y - z;
	map->point_matrix[y][x].x = p.x;
	map->point_matrix[y][x].y = p.y;
	return (z);
}

void	set_points(t_vars *vars, t_map *map)
{
	int		x;
	int		y;
	int		z;
	t_point	**matrix;

	matrix = vars->map->point_matrix;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			z = point_calc(x, y, vars);
			point_print(x, y, z, vars);
			x++;
		}
		y++;
	}
}

int	set_map_point_matrix(t_vars *vars, t_map *map)
{
	int	y;

	map = vars->map;
	map->point_matrix = ft_calloc(map->height + 1, sizeof(t_point *));
	if (!map->point_matrix)
		return (-1);
	y = 0;
	while (y < map->height)
	{
		map->point_matrix[y] = ft_calloc(map->width + 1, sizeof(t_point));
		if (!map->point_matrix[y])
		{
			while (y-- > 0)
				free(map->point_matrix[y]);
			free(map->point_matrix);
			return (-1);
		}
		y++;
	}
	return (0);
}
