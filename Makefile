# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleonell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 22:33:13 by gleonell          #+#    #+#              #
#    Updated: 2020/12/01 22:33:37 by gleonell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

SRC = main.c screenshot.c ray_hit_wall.c rays.c \
	floor_and_ceilling.c sprite.c \
	sprite_list.c get_player_pos.c get_win_params.c utils.c \
	take_texture_path.c walls.c moving.c parsing.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	put_textures.c checks.c


NAME = cub3D

HEADER = cub3d.h

OSRC = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME) $(OSRC)

$(NAME): $(SRC) $(HEADER)
	@make -C libft
	@make -C mlx_statlib
	@make -C mlx_dylib
	@cp ./mlx_dylib/libmlx.dylib ./
	@gcc $(FLAGS) ./libft/libft.a ./mlx_statlib/libmlx.a ./mlx_dylib/libmlx.dylib -framework OpenGl -framework AppKit $(SRC) -o $(NAME)

clean:
	@make -C libft clean
	@make -C mlx_statlib clean
	@make -C mlx_dylib clean
	@rm -f $(OSRC) libmlx.dylib
fclean: clean
	@make -C libft fclean
	@make -C mlx_statlib clean
	@make -C mlx_dylib clean
	@rm -f $(NAME) libmlx.dylib
	@rm -rf cub3D.dSYM

re: fclean all
