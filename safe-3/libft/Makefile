# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 13:53:51 by aboukezi          #+#    #+#              #
#    Updated: 2024/01/09 14:41:52 by aboukezi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rsc
RM = rm -f

OBJECTS = $(MAIN:.c=.o) 
BONUS_OBJECTS = $(BONUS:.c=.o)

MAIN = 		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_putchar.c\
		ft_printf/ft_putstr.c \
		ft_printf/ft_putnbr.c \
		ft_printf/ft_putunbr.c \
		ft_printf/ft_hex_num.c \
		ft_printf/ft_printhex.c \
		
		
		
BONUS = 	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c 

HEADER = libft.h

.c.o: $(MAIN) $(BONUS)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS) $(HEADER)
	$(AR) $(NAME) $(OBJECTS)

all: $(NAME)

re: clean fclean all

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

bonus: $(OBJECTS) $(BONUS_OBJECTS) $(HEADER)
	$(AR) $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
	
.PHONY: all clean fclean re bonus
