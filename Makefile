# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 12:52:27 by bahn              #+#    #+#              #
#    Updated: 2021/10/11 21:15:52 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS				= $(shell uname -s)

NAME			= fractol

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g
INCFLAGS		= -I./includes -I./minilibx-linux -I./libft

ifeq ($(OS), Linux)
	MLX_PATH	= ./minilibx-linux
	MLX_FLAGS	= -Lminilibx-linux/ -lmlx -lX11 -lXext -lm -lbsd -O3
else
	MLX_PATH	= ./minilibx-mac
	MLX_FLAGS	= -Lminilibx-mac/ -lmlx -lm -framework OpenGL -framework AppKit -O3
endif

LIBFT_PATH		= ./libft/
LIBFT_LINK		= -Llibft -lft

SRCS_PATH		= ./srcs/
SRCS_NAME		= main.c fractol.c draw.c \
					mandelbrot.c julia.c burning_ship.c \
					mouse.c keyboard.c color.c centroid.c scene.c utils.c
SRCS 			= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS			= $(SRCS:.c=.o)

all 			: $(NAME)

.c.o			:
				$(CC) $(CFLAGS) -c $< $(INCFLAGS) $(MLX_FLAGS) $(LIBFT_LINK) -o $@

$(NAME) 		: $(OBJS)
				$(MAKE) all -C $(MLX_PATH)
				$(MAKE) all -C $(LIBFT_PATH)
				$(CC) $(CFLAGS) $^ $(INCFLAGS) $(MLX_FLAGS) $(LIBFT_LINK) -o $@

clean			: 
				$(MAKE) clean -C $(MLX_PATH)
				$(MAKE) clean -C $(LIBFT_PATH)
				rm -fv $(OBJS)

fclean			: clean
				rm -fv $(NAME) $(addprefix $(LIBFT_PATH), libft.a)

re				: fclean all

.PHONY			: all clean fclean re