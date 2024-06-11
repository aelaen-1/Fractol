# ifndef FRACTOL_H
 # define FRACTOL_H

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include <stdlib.h> // malloc&free

# define WIDTH 800
# define HEIGHT 800 //window size
# define MAX_ITERATIONS 40

/**/
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>

# define KEY_ESC 65307
# define KEY_SHIFT 65505
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_RIGHT 2
# define MOUSE_CENTER 3
# define MOUSE_LEFT 1

// structures
typedef struct s_complex
{
    double a; 
    double b;
} t_complex;

typedef struct s_image
{
    void *img_ptr; 
    char *pxl_ptr; 
    int bitperpixel;
    int endian; 
    int size_line; 
} t_image; 

typedef struct s_fractal
{
    char *name; 
    void *mlx_ptr;
    void *mlx_window;

    t_image img; 

    double shift_a; 
    double shift_b;
    double offset_a;
    double offset_b;
    double zoom; 
    double escape_value;
    double iter;

    //if julia
    double julia_a; 
    double julia_b;

} t_fractal;

void keyHandler(int keysym, t_fractal *fract);
int mouseHandler(int mousekey, int x, int y, t_fractal *fract);
int juliaTracking ();
void byebye(t_fractal *fract);


// Main functions

void    error();
//Utils
double atodouble(char *s);

#endif
