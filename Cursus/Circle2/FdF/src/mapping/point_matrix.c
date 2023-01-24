/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:04:21 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/24 14:40:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

//PERSPECTIVA CABALLERA: CHECK UME NOTEBOOK
void	point_calc(int x, int y, t_vars *vars)
{
	int		z;
	t_point	p;
	t_map	*map;
	double	sinTheta;
	double	cosTheta;

	map = vars->map;
	z = map->data_matrix[y][x] * map->z_scale * (1 - map->angle);
	// p.x = (x ) * (map->scale + pow(map->scale, 2) / M_SQRT2) + map->start.x;
	// p.y = (y ) * (map->scale + map->scale / M_SQRT2) + map->start.y;
	// p.x = (x + y * map->desv) * map->scale + map->start.x;
	// p.y = (y - x * map->desv) * map->scale * map->angle + map->start.y - z;
	sinTheta = sin(map->desv);
	cosTheta = cos(map->desv);
	// r = sqrt(x * x + y * y);
	// p.x = r * (x * cosTheta - y * sinTheta) * map->scale;
	// p.y = r * (y * cosTheta + x * sinTheta) * map->scale * map->angle;
	p.x = ((x - map->width / 2) * cosTheta - (y - map->height / 2) * sinTheta) * map->scale;
	p.y = ((y - map->height / 2) * cosTheta + (x - map->width / 2) * sinTheta) * map->scale * map->angle;
	
	p.x += map->start.x;
	p.y += map->start.y - z;
	// printf("%f, %f\n", p.x, p.y);
	map->point_matrix[y][x].x = (int)trunc(p.x);
	map->point_matrix[y][x].y = (int)trunc(p.y);
	// if (y != 0)
	// 	print_line(map->point_matrix[y - 1][x], map->point_matrix[y][x], vars);
	// if (x != 0)
	// 	print_line(map->point_matrix[y][x - 1], map->point_matrix[y][x], vars);
	draw_circle(vars, map->point_matrix[y][x].x, map->point_matrix[y][x].y, 2);
	// map->z_scale / 30);d
	// printf("%d, %d\n", map->point_matrix[y][x].x, map->point_matrix[y][x].y);
	// ft_printf("%f, %f\n", p.x, p.y);
	// printf("%p\n", &vars->img);
	// if (map->point_matrix[y][x].x >= 0 && map->point_matrix[y][x].x < WIN_W
	// 	&& map->point_matrix[y][x].y >= 0 && map->point_matrix[y][x].y < WIN_H)
}

void	set_points(t_vars *vars, t_map *map)
{
	int		x;
	int		y;
	t_point	**matrix;

	matrix = vars->map->point_matrix;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
			point_calc(x++, y, vars);
		y++;
	}
}

int	set_map_point_matrix(t_vars *vars, t_map *map)
{
	int y;

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