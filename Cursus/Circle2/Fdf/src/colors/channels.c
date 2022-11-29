/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:29:40 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/29 15:32:08 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * It returns the alpha channel of the color.
 * 
 * @param argb The color to get the channel from.
 * 
 * @return The alpha channel of the color.
 */
int	get_channel_a(int argb)
{
	return ((argb >> 24) & 255);
}

/**
 * Get the red channel of an ARGB color.
 * 
 * @param argb The color to get the channel from.
 * 
 * @return The red channel of the color.
 */
int	get_channel_r(int argb)
{
	return ((argb >> 16) & 255);
}

/**
 * Get the green channel value from an ARGB color value.
 * 
 * @param argb The color to get the green channel from.
 * 
 * @return The green channel of the color.
 */
int	get_channel_g(int argb)
{
	return ((argb >> 8) & 255);
}

/**
 * It returns the blue value of a color.
 * 
 * @param argb The color to get the channel from.
 * 
 * @return The blue channel of the color.
 */
int	get_channel_b(int argb)
{
	return (argb & 255);
}
