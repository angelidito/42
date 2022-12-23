/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:55:32 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/23 00:45:42 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

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
	int		x;
	int		y;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_point
{
	int		x;
	int		y;

}			t_point;

typedef struct s_map
{
	t_point	start;
	t_point	**point_matrix;
	int		**data_matrix;
	int		width;
	int		height;
	double	scale;
	double	desv;
	double	angle;
	double	z_scale;
}			t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*img;
	t_map	*map;

}			t_vars;

#endif
