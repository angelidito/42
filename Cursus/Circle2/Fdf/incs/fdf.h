/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:44:24 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/13 14:01:23 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_enums.h"
# include "fdf_structs.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

char	*my_mlx_set_data_addr(t_vars *vars);
int		render_next_frame(t_vars *vars);

// color

int		get_channel_a(int argb);
int		get_channel_r(int argb);
int		get_channel_g(int argb);
int		get_channel_b(int argb);

int		get_argb(int r, int g, int b, int a);
int		get_rgb(int r, int g, int b);
int		add_shade(double shade, int argb);
int		get_opposite(int argb);

// events

int		on_keydown(int keycode, t_vars *vars);
// ON_KEYUP*		3	int (*f)(int keycode, void *param);
int		on_mousedown(int button, int x, int y, t_vars *vars);

// ON_MOUSEUP		5	int (*f)(int button, int x, int y, void *param);
int		on_mousemove(int x, int y, t_vars *vars);
// ON_EXPOSE*		12	int (*f)(void *param);
// ON_DESTROY		17	int (*f)(void *param);

//skils
void	draw_sqr0(t_data *img, int x_start, int y_start, int side_len);
void	draw_sqr1(t_data *img, int x_start, int y_start, int side_len);
void	draw_circle(t_data *img, int x_center, int y_center, int radius);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	*my_mlx_get_data_addr(t_data *img);

#endif
