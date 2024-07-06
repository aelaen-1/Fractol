 NAME	= fractol
OS		= $(shell uname)

SRCDIR	= ./src
INCDIR	= ./include
LIBFT   = ./libft

# Minilibx
MLX_PATH	= include/minilibx/
MLX_NAME	= libmlx.a
MLX		=   $(MLX_PATH)libmlx.a

# Libft
LIBFT_PATH	= include/libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)libft.a

SRC		= 	fractolmain.c \
		  	init.c \
		 	events.c \
			utils/atodouble.c \
			utils/error.c \
			utils/math.c 
		  
CCFLAGS = cc -Wall -Wextra -Werror

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "Fractol ready."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean


