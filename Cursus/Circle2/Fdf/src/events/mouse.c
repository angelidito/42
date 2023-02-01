/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:36 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 14:21:41 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"
#include "../../incs/fdf_events.h"

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
		printf("Mouse leaving\n");
	else if (!mouse_was_in && mouse_is_in)
		printf("Mouse entering\n");
	return (0);
}

int	on_mousedown(int button, int x, int y, t_vars *vars)
{
	if (button == MOUSE_LEFT)
	{
		printf("mouse click at (%d, %d)\n", x, y);
		return (0);
	}
	else if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		change_scale(button, vars);
	render_next_frame(vars);
	return (0);
}
