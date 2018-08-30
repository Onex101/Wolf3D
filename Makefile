# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 07:42:02 by xrhoda            #+#    #+#              #
#    Updated: 2018/08/30 07:03:50 by shillebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FILES =		main.c	\
			trig_tables_1.c	\
			trig_tables_2.c	\
			draw_line.c	\
			draw.c	\
			draw_map.c	\
			ft_struct_init_1.c	\
			input.c	\
			image.c	\
			ft_struct_free_1.c	\
			ft_struct_free_2.c	\
			new_dist.c	\
			dda_init.c	\
			dda_assign.c 	\
			dda_step.c 	\
			wall_check.c	\
			read_map.c	\
			draw_colour.c	\
			draw_background.c	\
			exit.c 	\

OBJ = $(FILES:%.c=./obj/%.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

MLX_INC	= -I /usr/X11/include -g

uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

ifeq ($(uname_S),Linux)
    MLX_LNK = -Wl,--no-as-needed -I /usr/local/include  -lX11 -lXext -L. /usr/local/lib/libmlx_Linux.a
endif
ifeq ($(uname_S),Darwin)
    MLX_LNK	= -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
endif

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

WOLF_INC = -I ./includes

INCLUDES = $(WOLF_INC) $(FT_INC) $(MLX_INC)

OBJDIR	= ./obj/

all: obj $(OBJ) $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(NAME):
	$(CC) $(OBJ) $(INCLUDES) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all