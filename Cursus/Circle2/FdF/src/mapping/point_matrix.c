/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:04:21 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/22 20:12:00 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

//PERSPECTIVA CABALLERA: CHECK UME NOTEBOOK
void	point_calc(int x, int y, t_vars *vars)
{
	double	a;
	double	b;
	t_map	*map;

	map = vars->map;
	// printf(": %f\n", x * (map->scale + pow(map->scale, 2) / M_SQRT2)
	// 		+ map->start.x);
	a = (x + 1) * (map->scale + pow(map->scale, 2) / M_SQRT2) + map->start.x;
	b = (y + 1) * (map->scale / M_SQRT2) + map->start.y;
	// printf("%f, %f\n", a, b);
	map->point_matrix[y][x].x = (int)trunc(a);
	map->point_matrix[y][x].y = (int)trunc(b);
	printf("%d, %d\n", map->point_matrix[y][x].x, map->point_matrix[y][x].y);
	// ft_printf("%f, %f\n", a, b);
	printf("%p\n", &vars->img);
	breakpoint();
	// if (x == 0)
	// 	draw_circle(&vars->img, map->point_matrix[y][x].x,
	// 			map->point_matrix[y][x].y, 10);
}

int	set_map_point_matrix(t_vars *vars)
{
	int x;
	int y;
	int malloc_error;
	t_map *map;

	map = vars->map;
	map->point_matrix = ft_calloc(map->height + 1, sizeof(t_point *));
	if (!map->point_matrix)
		return (-1);
	malloc_error = 0;
	y = 0;
	while (y < map->height && !malloc_error)
	{
		map->point_matrix[y] = ft_calloc(map->width + 1, sizeof(t_point));
		if (!map->point_matrix[y])
			malloc_error = 1;
		x = 0;
		while (x < map->width && !malloc_error)
		{
			point_calc(x, y, vars);
			x++;
		}
		y++;
	}
	if (malloc_error)
	{
		ft_printf("malloc_error at set_map_point_matrix()\n");
		malloc_error = 0;
		while (malloc_error < y)
		{
			free(map->point_matrix[malloc_error]);
		}
		free(map->point_matrix);
		return (-1);
	}
	return (0);
}