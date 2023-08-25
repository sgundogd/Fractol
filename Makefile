NAME = fractol
NAME_BONUS = fractol_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = ./fractol.c ./julia.c ./mandelbrot.c ./utils.c
SRCS_BONUS = ./fractol_bonus.c ./julia_bonus.c ./mandelbrot_bonus.c ./utils_bonus.c
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)
RM = rm -rf
MLX = mlx/libmlx.a


%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c  $< -o $@

$(NAME):$(MLX) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(MLX) $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)


all: $(MLX) $(NAME) bonus

$(MLX):
	make -C mlx/

clean:
	make clean -C mlx/
	${RM} $(OBJ)
	${RM} $(OBJ_BONUS)

fclean: clean
	${RM} ${NAME}
	${RM} $(MLX)
	${RM} ${NAME_BONUS}

re:			fclean all

.PHONY: all bonus clean fclean re
