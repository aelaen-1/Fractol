#include "fractol.h"

/*double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}
*/
double    scale(double a, double b, double min, double max, double x)
{
    return(a + (b - a) * (x - min)/(max - min));
}

t_complex   sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}

t_complex multiply_complex(t_complex z1, t_complex z2)
{
  t_complex z; 

  z.x = (z1.x * z2.x) - (z2.y * z2.y);
  z.y = (z1.x * z2.y) + (z1.y * z2.x);
  return(z);
}