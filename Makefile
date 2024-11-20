# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:47:34 by pitroin           #+#    #+#              #
#    Updated: 2024/11/18 21:50:52 by pitroin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -ggdb3
MLX_FLAGS = -framework OpenGL -framework AppKit
LIBFT_DIR = libft
GNL_DIR = gnl
INCLUDES = -I $(LIBFT_DIR) -I $(GNL_DIR) -I $(PRINTF_DIR) -I src
LIBFT = $(LIBFT_DIR)/libft.a

# Fichiers source et objets
SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c \
		src/main.c \
		src/init_map/check_map.c \
		src/init_map/init_info_map.c \
		src/utils.c \
		src/free.c

OBJS = ${SRCS:.c=.o}

# Règles
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re