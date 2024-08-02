#include "fractol.h"


void error()
{
    ft_putstr_fd("MALLOC ERROR", STDERR_FILENO);
    exit(1);
}

static void data_init(t_fractal *fract)
{
    fract->x = 0;
	fract->y = 0;
	fract->color = 0xFCBE11;
	fract->zoom = 300;
	fract->offset_x = -1.21;
	fract->offset_y = -1.21;
	fract->max_iterations = 42;
}

// static void events_init(t_fractal *fract)
// {
//     mlx_hook(fract->mlx_window, KeyPress, KeyPressMask, keyHandler, fract);
//     mlx_mouse_hook (fract->mlx_window, mouse_hook, fract);
// //    mlx_hook(fract->mlx_ptr, ButtonPress, ButtonPressMask, mouseHandler, fract);
//     mlx_hook(fract->mlx_ptr, MotionNotify, PointerMotionMask, juliaTracking, fract);
//     mlx_hook(fract->mlx_window, DestroyNotify , StructureNotifyMask, byebye, fract); 
// }

void    init(t_fractal *fract)
{
    fract->mlx = mlx_init();
    if (fract->mlx == NULL)
        error();
    fract->window = mlx_new_window(fract->mlx_ptr,
                                    WIDTH, HEIGHT, fract->name);
    if (fract->window == NULL)
        error();
    fract->image = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
    if (fract->image == NULL)
        error();
    fract->pointer_to_image = mlx_get_data_addr(fract->image,
                                                &fract->bits_per_pixel,
                                                &fract->size_line,
                                                &fract->endian);
    data_init(fract);                                             
}