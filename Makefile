# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 21:24:45 by npiya-is          #+#    #+#              #
#    Updated: 2023/06/04 23:55:07 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt

CC=gcc

CFLAGS= -Wall -Werror -Wextra
# -fsanitize=address

SRCS_DIR= srcs/

INCLUDE_DIR= include/

LIBFT = libft

MLX= mlx

LIBFT_LIB = -lft
LIB_DIR= ${addprefix ${INCLUDE_DIR}, ${LIBFT}}

LIBS= -Linclude/libft $(LIBFT_LIB) -lpthread -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS_INCLUDE= include/getnextline/get_next_line.c\
	include/getnextline/get_next_line_utils.c\

SRC= minirt.c \
	write_line.c \
	camera.c \
	object.c \
	calculate_vector.c \
	vector_operation.c \
	sphere.c \
	cylinder.c \
	plane.c \
	cone.c \
	color.c \
	ray.c \
	antialiasing.c \
	diffuse.c \
	texture.c \
	light.c \
	bg.c \
	intersect.c \
	compute_light.c \
	thread.c \
	math_utils.c \
	color_operation.c \
	check_file1.c \
	check_func1.c \
	check_func2.c \
	check_iden1.c \
	check_iden2.c \
	check_range.c \
	check_subfunc.c \
	check_error.c \
	keyhook.c \

SRCS= ${addprefix ${SRCS_DIR}, ${SRC}}

#=======

OBJS = $(SRCS:%.c=%.o)
OBJS_INCLUDE = $(SRCS_INCLUDE:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_INCLUDE)
	make -C $(LIB_DIR)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_INCLUDE) $(LIBS) -o $(NAME)

debug:$(SRCS) $(SRCS_INCLUDE)
	@make -C $(LIB_DIR)
	@make -C $(MLX)
	@$(CC) -g $(CFLAGS) $(SRCS) $(SRCS_INCLUDE) $(LIBS) -o $(NAME)

leaks:$(SRCS) $(SRCS_INCLUDE)
	@make -C $(LIB_DIR)
	@make -C $(MLX)
	@$(CC) -g $(CFLAGS) $(SRCS) $(SRCS_INCLUDE) $(LIBS) -o $(NAME)

clean:
	make clean -C $(MLX)
	make clean -C $(LIB_DIR)
	rm -rf $(OBJS) $(OBJS_INCLUDE)

fclean:clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME) $(NAME).dSYM

re:fclean all

.PHONY: all clean fclean re
