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

double	atodb(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
