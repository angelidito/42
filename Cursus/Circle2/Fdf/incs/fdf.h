/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:44:24 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/01 15:00:23 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

/**
 * Struct that contains a void pointer, a char pointer, 
 * and three ints: *img, *addr, bits_per_pixel, line_length, and endian.
 * @property {void*} img - the image pointer
 * @property {char*} addr - the address of the first pixel of the image
 * @property {int} bits_per_pixel - The number of bits per pixel.
 * @property {int} line_length - The length of a line in bytes.
 * @property {int} endian - The endianness of the image.
 */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

enum		e_winsize
{
	WIN_W = 1024,
	WIN_H = 1024
};

enum		e_keycodes
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESC = 53
};
enum		e_mousebuttons
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT= 2,
	MOUSE_MIDDLE = 3,
	MOUSE_SCROLL_DOWN = 4,
	MOUSE_SCROLL_UP = 5,
};

enum		e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// color

int			get_channel_a(int argb);
int			get_channel_r(int argb);
int			get_channel_g(int argb);
int			get_channel_b(int argb);

int			get_argb(int r, int g, int b, int a);
int			get_rgb(int r, int g, int b);
int			add_shade(double shade, int argb);
int			get_opposite(int argb);

// events

int			on_keydown(int keycode, t_vars *vars);
// ON_KEYUP*		3	int (*f)(int keycode, void *param);
int			on_mousedown(int button, int x, int y, t_vars *vars);

// ON_MOUSEUP		5	int (*f)(int button, int x, int y, void *param);
int			on_mousemove(int x, int y, t_vars *vars);
// ON_EXPOSE*		12	int (*f)(void *param);
// ON_DESTROY		17	int (*f)(void *param);

//skils
void		draw_sqr0(t_data *img, int x_start, int y_start, int side_len);
void		draw_sqr1(t_data *img, int x_start, int y_start, int side_len);
void		draw_circle(t_data *img, int x_center, int y_center, int radius);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
char		*my_mlx_get_data_addr(t_data *img);

#endif
