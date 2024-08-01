#include "fractol.h"

double    scale(double a, double b, double min, double max, double x)
{
    return(a + (b - a) * (x - min)/(max - min));
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

  z.a = (z1.a * z2.a) - (z2.b * z2.b);
  z.b = (z1.a * z2.b) + (z1.b * z2.a);
  return(z);
}