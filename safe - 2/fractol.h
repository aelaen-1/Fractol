
#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

# define SIZE 700
# define WIDTH 800
# define HEIGHT 800

// KEYCODES
# define ITER_PLUS 61
# define ITER_LESS 45
# define COLOR 99 

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

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
void		putpixel(t_fractal *fractal, int x, int y, int colour);
int			byebye(t_fractal *fractal);

// init.c
void		init(t_fractal *fractal);


// main.c
int			draw_fractal(t_fractal *fractal, char *query);
// mouse_and_keys.c
int			key_handler(int key, t_fractal *fract);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

// draw.c
void		*draw_mandelbrot(void *fractal_void);
void		draw_julia(t_fractal *fractal);
void		julia(t_fractal *fractal);
void		mandel(t_fractal *fractal);

// bordel

int	render(t_fractal *fract, char *name);
double	atodb(char *s);
void	zoom(t_fractal *f, int x, int y, int zoom);

#endif
