/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:58:36 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/01 15:15:20 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	on_mousemove(int x, int y, t_vars *vars)
{
	static int	mouse_is_in;
	int			mouse_was_in;

	mouse_was_in = mouse_is_in;
	if (x > 0 && y >= 0 && x <= WIN_W && y <= WIN_H && vars)
		mouse_is_in = 1;
	else
		mouse_is_in = 0;
	// printf("mouse_is_in %d\n", mouse_is_in);
	// printf("mouse at (%d, %d)\n", x, y);
	if (mouse_was_in && !mouse_is_in)
		printf("Mouse leaving\n");
	else if (!mouse_was_in && mouse_is_in)
		printf("Mouse entering\n");
	// mlx_clear_window(vars->mlx, vars->win);
	return (0);
}

int	on_mousedown(int button, int x, int y, t_vars *vars)
{
	if (vars)
		;
	if (button == MOUSE_LEFT)
		printf("mouse click at (%d, %d)\n", x, y);
	printf("mouse button: %d\n", button);
	return (0);
}
