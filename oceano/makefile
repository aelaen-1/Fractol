NAME	= fractol
# MLX
INC=/usr/include
INCLIB=$(INC)/../lib
MLX_PATH	= ./minilibx-linux
MLX_LIB := -L$(MLX_PATH) -lmlx

# Libft
LIBFT_PATH := libft
LIBFT_MAKE := $(MAKE) -C $(LIBFT_PATH)
LIBFT_LIB := -L./libft -lft

SRC		= main.c \
		  init.c \
		  render.c \
		  math_utils.c \
		  string_utils.c
		  
OBJ   := $(SRC:.c=.o)
DEPS  := ${SRC:.c=.d}

CCFLAGS = gcc -Wall -Wextra -Werror


all: ${NAME}

%.o: %.c 
	@$(CCFLAGS) -MMD -MP -MF $(<:.c=.d)  -c $< -o $@ 

$(MLX_PATH):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH)
	@make -C $(MLX_PATH)

-include $(DEPS)
$(NAME): $(MLX_PATH) $(OBJ)
	$(MAKE) -sC $(LIBFT_PATH)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) -L$(INCLIB) -lXext -lX11 -lm -lbsd

clean:
	$(LIBFT_MAKE) clean
	${RM} ${OBJ}
	${RM} ${DEPS}

fclean: clean
	$(LIBFT_MAKE) fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all re clean fclean


