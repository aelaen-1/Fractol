#include "fractol.h"

//void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)

// int (*f)(int keycode, void *param) for ON_KEYDOWN and ON_KEYUP hooking events
int keyboard(int keycode, t_fractal *fract)
{
    if (keycode == XK_LEFT)
        fract->shift_a += (0.5 * fract->zoom);
    
}

//  * int (*f)(int button, int x, int y, void *param) for ON_MOUSEUP and ON_MOUSEDOWN
int mouse(int button, int x, int y, t_fractal *fract)
{
    //zoom in, Button4 is the scrollUp on the mouse
    if (button == Button4)
        fract->zoom *= 0.95;

    //zoom out, Button5 is the scrollDown on the mouse
    if(button == Button5)
        fract->zoom *= 1.05;
    //refresh
    render(fract);
    return 0;
}