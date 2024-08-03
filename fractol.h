/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:17:49 by aboukezi          #+#    #+#             */
/*   Updated: 2024/08/02 16:17:50 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

# define SIZE 700

// KEYCODES
# define ITER_PLUS 61
# define ITER_LESS 45
# define C 99 

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
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
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
void	pixel_put(int x, int y, t_fractal *fract, int color);
double	atodb(char *s);
int		byebye(t_fractal *fract);

// init.c
void	init(t_fractal *fract);

// main.c
int		render(t_fractal *fract, char *name);

// events.c
int		key_handler(int key, t_fractal *fract);
int		mouse_handler(int button, int x, int y, t_fractal *fract);
void	zoom(t_fractal *f, int x, int y, int zoom);

// render.c
void	drawer(t_fractal *fract, char *name);
void	mandel(t_fractal *f);
void	julia(t_fractal *f);

#endif
