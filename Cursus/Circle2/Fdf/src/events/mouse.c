/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:36 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 17:10:59 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"
#include "../../incs/fdf_events.h"

/**
 * It prints a message when the mouse enters or leaves the window
 * 
 * @param x The x coordinate of the mouse cursor.
 * @param y The y-coordinate of the mouse pointer.
 * @param vars A pointer to the t_vars structure.
 * 
 * @return 0
 */
int	on_mousemove(int x, int y, t_vars *vars)
{
	static int	mouse_is_in;
	int			mouse_was_in;

	mouse_was_in = mouse_is_in;
	if (x > 0 && y >= 0 && x <= WIN_W && y <= WIN_H && vars)
		mouse_is_in = 1;
	else
		mouse_is_in = 0;
	if (mouse_was_in && !mouse_is_in)
		ft_printf("Mouse leaving\n");
	else if (!mouse_was_in && mouse_is_in)
		ft_printf("Mouse entering\n");
	return (0);
}

/**
 * It prints the coordinates of the mouse click to the console, and if the 
 * mouse scroll wheel is used, it changes the scale of the fractal
 * 
 * @param button The mouse button that was pressed.
 * @param x The x coordinate of the mouse click.
 * @param y The y coordinate of the mouse click
 * @param vars A pointer to the t_vars struct
 * 
 * @return The return value is the return value of the function that was called.
 */
int	on_mousedown(int button, int x, int y, t_vars *vars)
{
	if (button == MOUSE_LEFT)
	{
		ft_printf("mouse click at (%d, %d)\n", x, y);
		return (0);
	}
	else if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		change_scale(button, vars);
	render_next_frame(vars);
	return (0);
}
