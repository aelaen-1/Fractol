#include "fractol.h"

long int skip_and_sign(char *s, int *sign)
{
    long int i; 

    i = 0; 
    while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
        i++;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            *sign = -1;
        i++;
    }
    return (i);
}
double atodouble(char *s)
{
    long int i;
    int sign;
    double result;
    double decimal;

    sign = 1;
    result = 0.0; 
    decimal = 0.1; 
    i = skip_and_sign(s, &sign);
    while (ft_isdigit(s[i]))
    {
        result += s[i] - 48;
        i++; 
    }
    if (s[i] == '.')
        i++;
    while(ft_isdigit(s[i]))
    {
        result+= decimal * (s[i] - 48);
        decimal *= 0.1;
        i++; 
    }
    if (ft_isdigit(s[i]) == 0)
        return (-666); 
    return (sign * result);
}

double	atodbl(char *s)
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
