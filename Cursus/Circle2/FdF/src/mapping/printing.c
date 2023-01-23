/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:27:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/11 13:55:09 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

void	print_f_x(t_point *p1, t_point *p2, t_vars *vars)
{
	int	x;
	int	y;

	x = p1->x;
	y = p1->y;
	while (x < p2->x)
	{
		y = (p1->y - p2->y) / (p1->x - p2->x) * (x - p1->x) + p1->y;
		draw_circle(vars, x, y, 2);
		x++;
	}
}
void	print_f_y(t_point *p1, t_point *p2, t_vars *vars)
{
	int	x;
	int	y;

	x = p1->x;
	y = p1->y;
	while (y < p2->y)
	{
		x = (p1->x - p2->x) / (p1->y - p2->y) * (y - p1->y) + p1->x;
		// my_mlx_pixel_put(vars->img, x, y, 255);
		draw_circle(vars, x, y, 2);
		y++;
	}
}
void	print_line(t_point a, t_point b, t_vars *vars)
{
	t_point	p1;
	t_point	*p2;

	p1.x = a.x;
	p1.y = a.y;
	p2 = &b;
	if (a.x > b.x)
	{
		p1.x = b.x;
		p1.y = b.y;
		p2 = &a;
	}
	if (a.y != b.y)
		print_f_x(&p1, p2, vars);
	p1.x = a.x;
	p1.y = a.y;
	p2 = &b;
	if (a.y > b.y)
	{
		p1.x = b.x;
		p1.y = b.y;
		p2 = &a;
	}
	if (a.x != b.x)
		print_f_y(&p1, p2, vars);
}

// void	print_lines(t_vars *vars)
// {
// 	t_map *map;
// 	t_point **matrix;
// 	int i;
// 	int j;

// 	j = 0;
// 	map = vars->map;
// 	matrix = map->point_matrix;
// 	while (++j < map->height)
// 	{
// 		i = 0;
// 		while (++i < map->width)
// 		{
// 			print_line(matrix[j - 1][i - 1], matrix[j][i], vars);
// 			draw_circle(vars, matrix[j][i].x, matrix[j][i].y,
// 						0); // map->z_scale / 30);
// 		}
// 	}
// }