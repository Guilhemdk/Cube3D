# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:47:34 by pitroin           #+#    #+#              #
#    Updated: 2024/11/25 13:41:30 by pitroin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -ggdb3
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lpthread -lXrandr -lXrender -ldl
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
GNL_DIR = gnl
INCLUDES = -I $(LIBFT_DIR) -I $(GNL_DIR) -I $(PRINTF_DIR) -I src
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Fichiers source et objets
SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c \
		src/main.c \
		src/init_map/check_map.c \
		src/init_map/check_border.c \
		src/init_map/check_path.c \
		src/init_map/init_info_map.c \
		src/init_map/utils_map.c \
		src/init_window/init_window.c \
		src/utils.c \
		src/free.c

OBJS = ${SRCS:.c=.o}

# Règles
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
