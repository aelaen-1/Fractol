#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void data_init(t_fractal *fract)
{
    fract->escape_value = 4; 
    fract->iter = 42;
    fract->shift_a = 0.0;
    fract->shift_b = 0.0;
    fract->zoom = 1.0;
}

void	init(t_fractal *fract)
{
	//MLX stuff
	fract->mlx_ptr = mlx_init();
	if (NULL == fract->mlx_ptr)
		malloc_error();
	fract->mlx_window = mlx_new_window(fract->mlx_ptr,
						WIDTH,
						HEIGHT,
						fract->name);
	if (NULL == fract->mlx_window)
	{
		mlx_destroy_display(fract->mlx_ptr);
		free(fract->mlx_ptr);
		malloc_error();
	}
	fract->img.img_ptr = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
	if (NULL == fract->img.img_ptr)
	{
		mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
		mlx_destroy_display(fract->mlx_ptr);
		free(fract->mlx_ptr);
		malloc_error();
	}
	fract->img.pxl_ptr = mlx_get_data_addr(fract->img.img_ptr,
						  	&fract->img.bpp,
							&fract->img.size_line,
							&fract->img.endian);
	// events_init(fractal);
	data_init(fract);
}


/*static void events_init(t_fractal *fract)
{
    mlx_hook(fract->mlx_ptr, KeyPress, KeyPressMask, keyHandler, fract);
    mlx_hook(fract->mlx_ptr, ButtonPress, ButtonPressMask, mouseHandler, fract);
    mlx_hook(fract->mlx_ptr, MotionNotify, PointerMotionMask, juliaTracking, fract);
    mlx_hook(fract->mlx_ptr, DestroyNotify , StructureNotifyMask, byebye, fract);
}
 
void    init(t_fractal *fract)
{
    fract->mlx_ptr = mlx_init();
    if (fract->mlx_ptr == NULL) // corr fract == NULL
        malloc_error();
    fract->mlx_window = mlx_new_window(fract->mlx_ptr,
                                    WIDTH, HEIGHT, fract->name);
    if (fract->mlx_window == NULL)
    {
        mlx_destroy_display(fract->mlx_ptr);
        free(fract->mlx_ptr);
        malloc_error();
    }
    fract->img.img_ptr = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
    if (fract->img.img_ptr == NULL)
    {
        mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
        mlx_destroy_display(fract->mlx_ptr);
        free(fract->mlx_ptr);
        malloc_error();
    }
    fract->img.pxl_ptr = mlx_get_data_addr(fract->img.img_ptr,
                                                &fract->img.bpp,
                                                &fract->img.size_line,
                                                &fract->img.endian);
    data_init(fract);                                            
    //events_init(fract);
}
*/
