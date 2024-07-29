#include "fractol.h"

static void data_init(t_fractal *fract)
{
    fract->escape_value = 4; 
    fract->iter = 400;
    fract->shift_a = 0.0;
    fract->shift_b = 0.0;
    fract->zoom = 1.0;
}

static void events_init(t_fractal *fract)
{
    mlx_hook(fract->mlx_ptr, KeyPress, KeyPressMask, keyHandler, fract);
    mlx_hook(fract->mlx_ptr, ButtonPress, ButtonPressMask, mouseHandler, fract);
    mlx_hook(fract->mlx_ptr, MotionNotify, PointerMotionMask, juliaTracking, fract);
    mlx_hook(fract->mlx_ptr, DestroyNotify, StructureNotifyMask, byebye, fract);
}

void    init(t_fractal *fract)
{
    fract->mlx_ptr = mlx_init();
    if (fract == NULL)
        error();
    fract->mlx_window = mlx_new_window(fract->mlx_ptr,
                                    WIDTH, HEIGHT, fract->name);
    if (fract->mlx_window == NULL)
    {
        mlx_destroy_display(fract->mlx_ptr);
        free(fract->mlx_ptr);
        error();
    }
    fract->img.img_ptr = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
    if (fract->img.img_ptr == NULL)
    {
        mlx_destroy_window(fract->mlx_ptr, fract->mlx_window);
        mlx_destroy_display(fract->mlx_ptr);
        free(fract->mlx_ptr);
        error();
    }
    fract->img.pxl_ptr = mlx_get_data_addr(fract->img.img_ptr,
                                                &fract->img.bpp,
                                                &fract->img.line_len, //corr
                                                &fract->img.endian);
    data_init(fract);                                            
    events_init(fract);
}
