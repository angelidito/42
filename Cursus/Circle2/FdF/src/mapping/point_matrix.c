/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:04:21 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/23 16:19:02 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

//PERSPECTIVA CABALLERA: CHECK UME NOTEBOOK
void	point_calc(int x, int y, t_vars *vars)
{
	double	x_p;
	double	y_p;
	int		z;
	t_map	*map;
	double	sinTheta;
	double	cosTheta;
	double	r;

	map = vars->map;
	z = map->data_matrix[y][x] * map->z_scale * (1 - map->angle);
	// x_p = (x ) * (map->scale + pow(map->scale, 2) / M_SQRT2) + map->start.x;
	// y_p = (y ) * (map->scale + map->scale / M_SQRT2) + map->start.y;
	// x_p = (x + y * map->desv) * map->scale + map->start.x;
	// y_p = (y - x * map->desv) * map->scale * map->angle + map->start.y - z;
	sinTheta = sin(map->desv);
	cosTheta = cos(map->desv);
	r = 1;
	// r = sqrt(x * x + y * y);
	x_p = r * (x * cosTheta - y * sinTheta) * map->scale;
	y_p = r * (y * cosTheta + x * sinTheta) * map->scale * map->angle;
	x_p += map->start.x;
	y_p += map->start.y - z;
	// printf("%f, %f\n", x_p, y_p);
	map->point_matrix[y][x].x = (int)trunc(x_p);
	map->point_matrix[y][x].y = (int)trunc(y_p);
	if (y != 0)
		print_line(map->point_matrix[y - 1][x], map->point_matrix[y][x], vars);
	if (x != 0)
		print_line(map->point_matrix[y][x - 1], map->point_matrix[y][x], vars);
	// draw_circle(vars, map->point_matrix[y][x].x, map->point_matrix[y][x].y, 2);
	// map->z_scale / 30);d
	// printf("%d, %d\n", map->point_matrix[y][x].x, map->point_matrix[y][x].y);
	// ft_printf("%f, %f\n", x_p, y_p);
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