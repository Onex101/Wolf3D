# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 07:42:02 by xrhoda            #+#    #+#              #
#    Updated: 2018/07/26 06:26:36 by xrhoda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FILES = 	main.c	\
			basic_raycast.c \
			trig_tables.c	\
			draw_line.c	\
			draw_square.c	\
			read_map.c	\
			vertex.c	\

OBJ = $(FILES:%.c=./obj/%.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

MLX_INC	= -I /usr/X11/include -g
MLX_LNK	= -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
#MLX_LNK = -Wl,--no-as-needed -I /usr/local/include  -lX11 -lXext -L. /usr/local/lib/libmlx_Linux.a

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

VECT	= ./vector/
VECT_LIB = $(addprefix $(V_),vector.a)
VECT_INC = -I ./vector/includes
VECT_LNK = -L. ./vector/vector.a

WOLF_INC = -I ./includes

INCLUDES = $(WOLF_INC) $(FT_INC) $(MLX_INC) $(VECT_INC)

OBJDIR	= ./obj/

all: obj $(OBJ) $(FT_LIB) $(VECT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(VECT_LIB):
	make -C $(VECT)

$(NAME):
	$(CC) $(OBJ) $(INCLUDES) $(MLX_LNK) $(FT_LNK) $(VECT_LNK) $(VECT_INC) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(VECT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean
	make -C $(VECT) fclean

re: fclean all
