/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_enums.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:55:27 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/10 19:50:16 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ENUMS_H
# define FDF_ENUMS_H

enum	e_keycodes
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_Q = 12,
	KEY_ESC = 53,
	KEY_ENTER = 36,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 23,
	KEY_6 = 22,
	KEY_7 = 26,
	KEY_8 = 28,
	KEY_9 = 25,
	KEY_0 = 29,
	KEY_INCREASE = 116,
	KEY_DECREASE = 121,
	KEY_PLUS = 30,
	KEY_MINUS = 44,
};

enum	e_mousebuttons
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_MIDDLE = 3,
	MOUSE_SCROLL_DOWN = 4,
	MOUSE_SCROLL_UP = 5,
};

enum	e_events
{
	ON_KEYDOWN = 2,
	// ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	// ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	// ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

enum	e_colors
{
	RED = 0x00ff0000,
	GREEN = 0x0000ff00,
	BLUE = 0x000000ff,
};

enum	e_winsize
{
	WIN_W = 1200,
	WIN_H = 1200,
};

#endif
