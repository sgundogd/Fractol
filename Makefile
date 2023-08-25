# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 04:45:20 by mugurel           #+#    #+#              #
#    Updated: 2023/08/25 02:08:14 by sgundogd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a
SRCS = ./fractol.c ./julia.c ./mandelbrot.c ./utils.c
OBJ = $(SRCS:.c =.o)
LFLAGS = -lXext -lX11 -lm -lz -L./lib/mlx_lib -lmlx
MLX = ./mlx/libmlx.a
RM = rm -rf
LIBC = ar -rcs


$(NAME): $(OBJ) ${LIBFT}
	$(CC) $(OBJ) ${LIBFT} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(MLX) ${NAME}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(MLX) :
	@make -C ./mlx
$(LIBFT):
	make -C ./libft

clean:
	${RM} $(OBJ)

fclean:
	clean
	${RM} ${NAME}
	rm libmlx.a

re:			fclean all

.PHONY: all bonus clean fclean re .c.o
