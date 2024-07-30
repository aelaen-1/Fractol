#include "fractol.h"
#include "minilibx-linux/mlx.h"

/*
 * Put a pixel in my image buffer
*/
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
	
/*
 * EASY TOGGLE mandel & julia
*/
static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}


/*
 * 						 ✅ map()
		   	0__________800     -2___________+2    
 *			|			 |     |            |
 *			|			 |	   |            |
 *		800	|			 |     |            |
 *			|			 |     |            |
 *			|			 |     |            |
 *			|____________|     |____________|

 *	
 *		MANDELBROT
 *		z = z^2 + c
 *		z initially is (0, 0)
 *		c is the actual point
 *
 *		z = z^2 + c -> z1 = c + c
 *
 *		JULIA
 *		./fractol julia <real> <i> 
 *		z = pixel_point + constant
*/
static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	color = 0;
  	z.x = scale(-2, +2, 0, WIDTH, x);
	z.y = scale(-2, +2, 0, HEIGHT, y);


	mandel_vs_julia(&z, &c, fractal);

	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(multiply_complex(z, z), c);
		
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = scale(BLACK, WHITE, 0, fractal->iterations_defintion, i);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;	
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);	

}
