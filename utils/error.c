#include "../include/fractol.h"

void error()
{
    ft_putstr_fd("MALLOC ERROR", STDERR_FILENO);
    exit(EXIT_FAILURE);
}