/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:44:24 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/21 16:09:37 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
#include <math.h>

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

//skils
void		draw_sqr0(t_data *img, int x_start, int y_start, int side_len);
void		draw_sqr1(t_data *img, int x_start, int y_start, int side_len);
void		draw_circle(t_data *img, int x_center, int y_center, int radius);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
char		*my_mlx_get_data_addr(t_data *img);

#endif
