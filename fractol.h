/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:27:48 by aboukezi          #+#    #+#             */
/*   Updated: 2024/05/17 17:27:50 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>

# define MAX_I 100
# define WIDTH 800
# define HEIGHT 800
# define ERROR_MSG "Saisie invalide. Réessayez avec \n ./fractol mandelbrot \n ou \n ./fractol julia <R> <I>"

// STRUCTURES (COMPLEX VALUES)
typedef struct s_complex
{
    double a; 
    double b;
}   t_complex;


typedef struct s_image
{
    void *img_ptr; //points to image structure
    char *pixels_ptr; // points to the pixel
    int bpp; //bits per pixel
    int endian; // == 0 ou 1 
    int size_line;
}   t_image;


typedef struct s_fract
{
    char *name;
    //MLX
    void *mlx_ptr; //void *mlx_init()
    void *mlx_window; //void *mlx_new_window()
    //image
    t_image img;
    
    double escape_value; // module
    double shift_a; 
    double shift_b;
    double zoom;
    double julia_a;
    double julia_b;
}   t_fractal;

// FUNCTION PROTOTYPES

void init(t_fractal *fract); // why using a pointer to struct ? 
void render(t_fractal *fract);

// event functions
int keyboard(int keycode, t_fractal *fract);


/* UTILS */ 
t_complex  sum(t_complex z1, t_complex z2);
t_complex  square(t_complex z);
double atodb(char *s);


#endif
