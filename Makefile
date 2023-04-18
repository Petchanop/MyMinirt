# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 21:24:45 by npiya-is          #+#    #+#              #
#    Updated: 2023/04/18 21:44:59 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt

CC=gcc 

CFLAGS= -Wall -Werror -Wextra

SRCS_DIR= srcs/

INCLUDE_DIR= include/

BUILD_DIR = build/

SRCS= $(SRCS_DIR)minirt.c \
	$(SRCS_DIR)adjust_point.c \
	$(SRCS_DIR)finddxdy.c \
	$(SRCS_DIR)write_line.c \
	$(SRCS_DIR)checkpoint.c	\
	$(SRCS_DIR)camera.c \
	$(SRCS_DIR)object.c \
	$(SRCS_DIR)calculate_vector.c \
	$(SRCS_DIR)vector_operation.c \
	$(SRCS_DIR)sphere.c \
	$(SRCS_DIR)color.c \
	$(SRCS_DIR)ray.c \
	$(SRCS_DIR)antialiasing.c \
	$(SRCS_DIR)diffuse.c \
	$(SRCS_DIR)texture.c \
	$(SRCS_DIR)light.c \
	bg.c \


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
	# $(CC) -g $(CFLAGS) $(SRCS) $(SRCS_INCLUDE) $(LIBS) -o $(NAME)
	@$(CC) -g $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)

leaks:$(SRCS)
	@$(CC) -g $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME) $(NAME).dSYM

re:fclean all

.PHONY: all clean fclean re