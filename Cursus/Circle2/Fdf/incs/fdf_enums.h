/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_enums.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:55:27 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/01 16:27:56 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ENUMS_H
# define FDF_ENUMS_H

enum	e_colors
{
	RED = 0x00ff0000,
	GREEN = 0x0000ff00,
	BLUE = 0x000000ff,
};

enum	e_events
{
	ON_KEYDOWN = 2,
	ON_MOUSEDOWN = 4,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17,
};

enum	e_keycodes
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_Q = 12,
	KEY_DECREASE = 3,
	KEY_INCREASE = 15,
	KEY_PLUS = 30,
	KEY_MINUS = 44,
	KEY_COMMA = 43,
	KEY_DOT = 47,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53,
};

enum	e_mousebuttons
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_MIDDLE = 3,
	MOUSE_SCROLL_DOWN = 4,
	MOUSE_SCROLL_UP = 5,
};

enum	e_winsize
{
	WIN_W = 1800,
	WIN_H = 1200,
};

#endif
