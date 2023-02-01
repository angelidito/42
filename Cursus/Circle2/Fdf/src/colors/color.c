/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:13:55 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 17:08:10 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

/**
 * It returns the value of the parameter if it's between 0 and 255, 
 * otherwise it returns the closest value to the parameter that is 
 * between 0 and 255 (obscure explanation, but true).
 * 
 * @param value The value to be checked.
 * 
 * @return The value of the variable "value" is being returned.
 */
int	inrange(int value)
{
	if (value > 255)
		return (255);
	if (value < 0)
		return (0);
	return (value);
}

/**
 * It takes four integers, each in the range 0-255, and returns a single integer
 * that represents the same color in ARGB format
 * 
 * @param a alpha (transparency)
 * @param r red
 * @param g green
 * @param b blue
 * 
 * @return the rgb value of the color.
 */
int	get_argb(int a, int r, int g, int b)
{
	a = inrange(a);
	r = inrange(r);
	g = inrange(g);
	b = inrange(b);
	return (a << 24 | r << 16 | g << 8 | b);
}

/**
 * It takes three integers, each in the range 0-255, and returns a single 
 * integer that represents the same color in ARGB format
 * 
 * @param r red
 * @param g green
 * @param b blue
 * 
 * @return the rgb value of the color.
 */
int	get_rgb(int r, int g, int b)
{
	return (get_argb(0, r, g, b));
}

/**
 * It takes a color and a shade value, and returns a new color that is the 
 * original color with the shade value applied to it
 * 
 * @param shade a double between 0 and 1. 0 is no shade, 1 is full shade.
 * @param argb The color to be shaded.
 * 
 * @return the color of the pixel after the shade has been applied.
 */
int	add_shade(double shade, int argb)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = get_channel_a(argb);
	r = get_channel_r(argb) - get_channel_r(argb) * shade;
	g = get_channel_g(argb) - get_channel_g(argb) * shade;
	b = get_channel_b(argb) - get_channel_b(argb) * shade;
	return (get_argb(a, r, g, b));
}

/**
 * It takes an ARGB color and returns the opposite color
 * 
 * @param argb The color to get the opposite of.
 * 
 * @return The opposite of the color.
 */
int	get_opposite(int argb)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = get_channel_a(argb);
	r = ~get_channel_r(argb) & 255;
	g = ~get_channel_g(argb) & 255;
	b = ~get_channel_b(argb) & 255;
	return (get_argb(a, r, g, b));
}
