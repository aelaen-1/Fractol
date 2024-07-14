#include "fractol.h"

void is_mandel(t_complex *z, t_complex *c, t_fractal *fract)
{

    if (!ft_strncmp(fract->name, "mandelbrot", 10))
    {
        c->a = z->a; 
        c->b = z->b;
    }
    else
    {
        c->a = fract->julia_a; 
        c->b = fract->julia_b;
    }
}

void pixel_color()
{

}

void   printpixel(int a, int b,  t_fractal *fract)
{
    t_complex z;
    t_complex c;
    int i;
    int color; 

    i = 0; 
    z.a = scale(-2, 2, 0, WIDTH, a);
    z.b = scale(-2, 2, 0, HEIGHT, b);

    is_mandel(&z, &c, &fract);

    while (i < fract->iter)
    {
        z = sum_complex(multiply_complex(z, z), c);
        if((z.a * z.a + z.b * z.b) <= 4)
        {
            color = scale(0, fract->iter, BLACK, WHITE, i);
            pixel_color();
        }
        else

    }
    

    
}

void render(t_fractal *fract)
{
    int a; 
    int b; 

    a = 0; 
    b = 0; 
    while (b <= HEIGHT)
    {
        while (a <= WIDTH)
        {
            print_pixel(a, b, &fract);
            a++;
        }
        b++;
    }
    mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_window, fract->img.img_ptr, 0, 0);
}
