# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkaewsae <lkaewsae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 21:24:45 by npiya-is          #+#    #+#              #
#    Updated: 2023/05/28 23:59:56 by lkaewsae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt

CC=gcc 

CFLAGS= -Wall -Werror -Wextra -fsanitize=address -I$(INCLUDE_DIR)

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
	check_file.c \
	check_func1.c \
	check_func2.c \
	check_range.c \
	check_subfunc.c 

SRCS= ${addprefix ${SRCS_DIR}, ${SRC}}

#=======

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	$(CC) $(CFLAGS) $(LIBFT)/libft.a $^ -o $@

#=======


# LIBFT=libft/

# LIBFT_LIB = libft/libft.a

# SRCS_LIBFT = ${addprefix ${LIBFT}, ${SRC_LIBFT}}

# SRCS_INCLUDE= include/getnextline/get_next_line.c\
# 	include/getnextline/get_next_line_utils.c\

# OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)

# OBJS_INC=$(SRC_INCLUDE:%.c=$(BUILD_DIR)/%.o)

# OBJS_LIBFT=$(SRCS_LIBFT:%.c=$(BUILD_DIR)/%.o)


# MLX=mlx/

# LIBS= -lpthread -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT_LIB)

# LIB_FT=-Llibft #-lft 

# all: $(NAME)

# $(NAME):$(OBJS) $(OBJS_IN) 
# 	@make -C $(LIBFT)
# 	@make -C $(MLX)
# 	$(CC) $(CFLAGS)$(LIBS) $^ -o $@

# debug:$(SRCS)
# 	@make -C $(LIBFT)
# 	@make -C $(MLX)
# 	@$(CC) -g $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)

# leaks:$(SRCS)
# 	@$(CC) -g $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME) $(NAME).dSYM

re:fclean all

.PHONY: all clean fclean re