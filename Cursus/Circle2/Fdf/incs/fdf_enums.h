
#ifndef FDF_ENUMS_H
# define FDF_ENUMS_H

enum	e_keycodes
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESC = 53,
	KEY_ENTER = 36,
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
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
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
	WIN_W = 1024,
	WIN_H = 1024,
};

#endif
