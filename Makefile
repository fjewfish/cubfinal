# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 18:40:46 by fjewfish          #+#    #+#              #
#    Updated: 2020/11/07 18:40:00 by fjewfish         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX = -framework OpenGL -framework AppKit

FLAGS = -O3 -Wall -Wextra -Werror -o

INCLUDES = -I./includes

CC = gcc

RM = rm -f

LIBFT = ./libft/libft.a

MLX_LIB = ./mlx/libmlx.dylib

SRC =	src/a1_main.c\
		src/c3_parse.c\
		src/c7_parse_useful_fun.c\
		src/e1_hooks_function_v2.c\
		src/f3_mlx_map_v2.c\
		src/i1_exit_errors_v2.c\
		src/b1_initialization.c\
		src/c4_parse.c\
		src/d1_put_image_to_window.c\
		src/e2_hooks_function_v2.c\
		src/g1_sprite.c\
		src/j1_useful_fun_v2.c\
		src/c1_parse.c\
		src/c5_parse.c\
		src/d2_put_image_to_window.c\
		src/d0_put_image_to_window.c\
		src/f1_mlx_map_v2.c\
		src/g2_sprite.c\
		src/c2_parse.c\
		src/c6_parse_rnswesfc.c\
		src/d3_put_image_to_window.c\
		src/f2_mlx_map_v2.c\
		src/h1_screenshot.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) bonus -C ./libft
	$(MAKE) -C ./mlx
	mv $(MLX_LIB) .
	$(CC) $(FLAGS) $(NAME) $(INCLUDES) $(OBJ) $(MLX) libmlx.dylib $(LIBFT)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) mlx/*.o
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./mlx
	$(RM) $(LIBFT)
	$(RM) $(NAME)
	$(RM) libmlx.dylib
	$(RM) *.bmp

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
