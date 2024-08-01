#include "fractol.h"

void error()
{
    ft_putstr_fd("MALLOC ERROR", STDERR_FILENO);
    exit(1);
}

static void data_init(t_fractal *fract)
{
    fract->escape_value = 4; 
    fract->iter = 100;
    fract->shift_a = 0.0;
    fract->shift_b = 0.0;
    fract->zoom = 1.0;
}

static void events_init(t_fractal *fract)
{
    mlx_hook(fract->mlx_window, KeyPress, KeyPressMask, keyHandler, fract);
    mlx_mouse_hook (fract->mlx_window, mouseHandler, fract);
//    mlx_hook(fract->mlx_ptr, ButtonPress, ButtonPressMask, mouseHandler, fract);
    mlx_hook(fract->mlx_ptr, MotionNotify, PointerMotionMask, juliaTracking, fract);
    mlx_hook(fract->mlx_window, DestroyNotify , StructureNotifyMask, byebye, fract); 
}

void    init(t_fractal *fract)
{
    fract->mlx_ptr = mlx_init();
    if (fract->mlx_ptr == NULL)
        error();
    fract->mlx_window = mlx_new_window(fract->mlx_ptr,
                                    WIDTH, HEIGHT, fract->name);
    if (fract->mlx_window == NULL)
        error();
    fract->img.img_ptr = mlx_new_image(fract->mlx_ptr, WIDTH, HEIGHT);
    if (fract->img.img_ptr == NULL)
        error();
    fract->img.pxl_ptr = mlx_get_data_addr(fract->img.img_ptr,
                                                &fract->img.bpp,
                                                &fract->img.size_line,
                                                &fract->img.endian);
    data_init(fract);                                             
    events_init(fract);
}
