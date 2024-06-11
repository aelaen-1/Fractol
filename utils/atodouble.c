#include "../include/fractol.h"

long int skip_and_sign(char *s, int *sign)
{
    long int i; 

    i = 0; 
    while (s[i] >= 9 && s[i] <= 13 || s[i] == 32)
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
