# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:47:34 by pitroin           #+#    #+#              #
#    Updated: 2025/02/10 16:59:13 by pitroin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -ggdb3
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lpthread -ldl
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
GNL_DIR = get_next_line
INCLUDES = -I $(LIBFT_DIR) -I $(GNL_DIR) -I src
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Directories
SRC_DIR = src/
OBJ_DIR = obj/
GNL_DIR_OBJ = $(OBJ_DIR)get_next_line/

# Source files and objects
SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
       src/main.c \
       src/init_map/check_map.c \
       src/init_map/check_border.c \
       src/init_map/init_info_map.c \
       src/init_map/textures_map.c \
       src/init_window/init_window.c \
       src/exec/map_rendering/DDA.c \
       src/exec/map_rendering/raycast.c \
	   src/exec/map_rendering/raycast_2.c \
	   src/exec/map_rendering/tex_render.c \
       src/exec/events/handle_keys.c \
       src/exec/events/move_player.c \
       src/utils.c \
       src/free.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

# Colors
GREEN   = "\\033[32m"
YELLOW  = "\\033[33m"
NC      = "\\033[0m"

# Progress Bar
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0

define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling cub3D... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
	$$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
endef

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)
	@echo "$(GREEN)Executable $(NAME) created!$(NC)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MLX):
	@echo "$(YELLOW)Compiling minilibx...$(NC)"
	@$(MAKE) -s -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)MiniLibX compiled successfully!$(NC)"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar)

clean:
	@rm -f $(OBJS)
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(MLX_DIR) clean > /dev/null 2>&1
	@echo "$(YELLOW)Object files cleaned.$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(MLX_DIR) clean > /dev/null 2>&1
	@echo "$(YELLOW)Executable $(NAME) removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re

