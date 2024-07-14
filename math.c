#include "fractol.h"

int    scale(int a, int b, int min, int max, int x)
{
    return(a + (b - a) * (x - min)/(max - min))
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex z; 
    z.a = z1.a + z2.a;
    z.b = z1.b + z2.b;
    return (z);
}

t_complex multiply_complex(t_complex z1, t_complex z2)
{
  t_complex z; 

  z.a = (z.a * z.a) - (z.b * z.b);
  z.b = 2 * z.a * z.b;
}