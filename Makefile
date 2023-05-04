# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 21:24:45 by npiya-is          #+#    #+#              #
#    Updated: 2023/05/04 15:43:25 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt

CC=gcc 

CFLAGS= -Wall -Werror -Wextra

SRCS_DIR= srcs/

INCLUDE_DIR= include/

BUILD_DIR = build/

SRC= minirt.c \
	write_line.c \
	camera.c \
	object.c \
	calculate_vector.c \
	vector_operation.c \
	sphere.c \
	cylinder.c \
	plane.c \
	color.c \
	ray.c \
	antialiasing.c \
	diffuse.c \
	texture.c \
	light.c \
	bg.c \
	intersect.c \

SRCS= ${addprefix ${SRCS_DIR}, ${SRC}}

SRCS_INCLUDE= include/getnextline/get_next_line.c\
	include/getnextline/get_next_line_utils.c\

OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)

OBJS_INC=$(SRC_INCLUDE:%.c=$(BUILD_DIR)/%.o)

# LIBFT=libft/

MLX=mlx/

LIBS= -Lmlx -lmlx -framework OpenGL -framework AppKit

# LIB_FT=-Llibft -lft 

all:$(NAME)

$(NAME):$(OBJS) $(OBJS_IN)
	# @make -C $(LIBFT)
	@make -C $(MLX)
	# $(CC) $(CFLAGS) $(OBJS) (OBJS_INC) $(LIBS) -o $(NAME) 

debug:$(SRCS)
	# @make -C $(LIBFT)
	@make -C $(MLX)
	@$(CC) -g $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)

leaks:$(SRCS)
	@$(CC) -g $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME) $(NAME).dSYM

re:fclean all

.PHONY: all clean fclean re