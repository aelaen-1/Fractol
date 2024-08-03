/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:15:17 by aboukezi          #+#    #+#             */
/*   Updated: 2024/08/02 21:15:19 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

# define WIDTH 800
# define HEIGHT 800

// KEYCODES
# define ITER_PLUS 61
# define ITER_LESS 45
# define COLOR 99 

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

enum fractal_type type
{
	MANDEL,
	JULIA
}

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pxl_ptr;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	shift_x;
	double	shift_y;
	double	zoom;
	char	*name;
	int		iter;
}			t_fractal;

// utils.c
void	putpixel(t_fractal *f, int x, int y, int colour);
int		byebye(t_fractal *f);
double	atodb(char *s);

// init.c
void	init(t_fractal *f);

// main.c
int		render(t_fractal *f, char *name);

// events.c
int		key_handler(int key, t_fractal *f);
int		mouse_handler(int button, int x, int y, t_fractal *f);
void	zoom(t_fractal *f, int x, int y, int zoom);

// render.c
void	*draw_mandelbrot(void *ununitialized);
void	draw_julia(t_fractal *f);
void	julia(t_fractal *f);
void	mandel(t_fractal *f);

#endif
