# ifndef FRACTOL_H
 # define FRACTOL_H

#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h> // malloc&free

# define WIDTH 800
# define HEIGHT 800 //window size
# define MAX_ITERATIONS 40

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
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

# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ITER_PLUS 61
# define ITER_LESS 45

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

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
    int bpp;
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
    double zoom; 
    double escape_value;
    double iter;

    //if julia
    double julia_a; 
    double julia_b;

} t_fractal;

int keyHandler(int keysym, t_fractal *fract);
//int mouseHandler(int button, int x, int y, t_fractal *fract);
int juliaTracking(int x, int y, t_fractal *fract);
int byebye(t_fractal *fract);

void    init(t_fractal *fract);
void render(t_fractal *fract);


double  atodb(char *s);
double  scale(double a, double b, double min, double max, double x);
void error();

t_complex multiply_complex(t_complex z1, t_complex z2);
t_complex sum_complex(t_complex z1, t_complex z2);



void	zoom(t_fractal *fract, int x, int y, int zoom);
int	mouse_hook(int mouse_code, int x, int y, t_fractal *fract);



#endif
