/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:44:24 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 14:52:24 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/mylibft/incs/libft.h"
# include "fdf_enums.h"
# include "fdf_structs.h"
# include <fcntl.h> /* Open function */
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

//	DEBUGGING

void	breakpoint(void);

//	COLORS

int		get_argb(int r, int g, int b, int a);
int		get_channel_a(int argb);
int		get_channel_r(int argb);
int		get_channel_g(int argb);
int		get_channel_b(int argb);
int		get_opposite(int argb);
int		get_rgb(int r, int g, int b);
int		add_shade(double shade, int argb);

//	DRAWING

void	draw_circle(t_vars *vars, int x_center, int y_center, int radius);
void	draw_line(t_vars *vars, t_point begin, t_point end);

//	EVENTS

int		on_destroy(t_vars *vars);
int		on_keydown(int keycode, t_vars *vars);
int		on_mousedown(int button, int x, int y, t_vars *vars);
int		on_mousemove(int x, int y, t_vars *vars);
int		render_next_frame(t_vars *vars);
void	hooks(t_vars *vars);

//	MAPPING

int		set_map_data_matrix(const char *file, t_vars *vars);
int		set_map(const char *file, t_vars *vars);
int		set_map_point_matrix(t_vars *vars, t_map *map);
void	free_data_matrix(t_map *map);
void	set_points(t_vars *vars, t_map *map);

//	MY MLX

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	*my_mlx_get_data_addr(t_data *img);
char	*my_mlx_set_data_addr(t_data *img);

#endif
