
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*img;
}			t_vars;

#endif
