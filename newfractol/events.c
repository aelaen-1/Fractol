#include "fractol.h"


void	zoom(t_fractal *fract, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fract->offset_x = (x / fract->zoom + fract->offset_x) - (x
				/ (fract->zoom * zoom_level));
		fract->offset_y = (y / fract->zoom + fract->offset_y) - (y
				/ (fract->zoom * zoom_level));
		fract->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fract->offset_x = (x / fract->zoom + fract->offset_x) - (x
				/ (fract->zoom / zoom_level));
		fract->offset_y = (y / fract->zoom + fract->offset_y) - (y
				/ (fract->zoom / zoom_level));
		fract->zoom /= zoom_level;
	}
	else
		return ;
}

/**
 * @brief    The handler for keyboard events.
 * 				ESC: exit the program.
 * 				LEFT: move the fractal to the left.
 * 				RIGHT: move the fractal to the right.
 * 				UP: move the fractal up.
 * 				DOWN: move the fractal down.
 * 				R: reset the fractal.
 * 				C: change the color scheme.
 * 				J: set the constants of Julia to random values.
 * 				P: increase the max iterations.
 * 				M: reduce the max iterations.
 *
 * @param    key_code
 * @param    fract
 */
int	key_hook(int key_code, t_fractal *fract)
{
	if (key_code == ESC)
		exit(1);
	else if (key_code == LEFT)
		fract->offset_x -= 42 / fract->zoom;
	else if (key_code == RIGHT)
		fract->offset_x += 42 / fract->zoom;
	else if (key_code == UP)
		fract->offset_y -= 42 / fract->zoom;
	else if (key_code == DOWN)
		fract->offset_y += 42 / fract->zoom;
	else if (key_code == C)
		fract->color += (255 * 255 * 255) / 100;
	else if (key_code == M || key_code == P)
		change_iterations(fract, key_code);
	draw_fractal(fract, fract->name);
	return (0);
}

/**
 * @brief    The handler for mouse events.
 * 				SCROLL_UP: zoom in.
 * 				SCROLL_DOWN: zoom out.
 *
 * @param    mouse_code The code of the mouse event.
 * @param    x          The x coordinate of the mouse.
 * @param    y          The y coordinate of the mouse.
 * @param    fract
 */
int	mouse_hook(int mouse_code, int x, int y, t_fractal *fract)
{
	if (mouse_code == SCROLL_UP)
		zoom(fract, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fract, x, y, -1);
	draw_fractal(fract, fractal->name);
	return (0);
}