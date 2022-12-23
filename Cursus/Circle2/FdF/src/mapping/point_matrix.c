/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:04:21 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/23 01:12:47 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

//PERSPECTIVA CABALLERA: CHECK UME NOTEBOOK
// TODO para hacer que rote en un punto central calcular centro del mapa
void	point_calc(int x, int y, t_vars *vars)
{
	double	a;
	double	b;
	int		z;
	t_map	*map;

	map = vars->map;
	z = map->data_matrix[y][x] * map->scale * (1 - map->angle);
	// a = (x ) * (map->scale + pow(map->scale, 2) / M_SQRT2) + map->start.x;
	// b = (y ) * (map->scale + map->scale / M_SQRT2) + map->start.y;
	a = (x+ y * map->desv) * map->scale + map->start.x;
	b = (y- x * map->desv) * map->scale * map->angle + map->start.y
		- z * map->z_scale;
	// printf("%f, %f\n", a, b);
	map->point_matrix[y][x].x = (int)trunc(a);
	map->point_matrix[y][x].y = (int)trunc(b);
	// printf("%d, %d\n", map->point_matrix[y][x].x, map->point_matrix[y][x].y);
	// ft_printf("%f, %f\n", a, b);
	// printf("%p\n", &vars->img);
	// if (map->point_matrix[y][x].x >= 0 && map->point_matrix[y][x].x < WIN_W
	// 	&& map->point_matrix[y][x].y >= 0 && map->point_matrix[y][x].y < WIN_H)
	draw_circle(vars, map->point_matrix[y][x].x, map->point_matrix[y][x].y,
			map->scale / 10);
}

void	set_points(t_vars *vars, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
			point_calc(x++, y, vars);
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
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