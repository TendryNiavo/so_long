NAME		=	so_long
CC			=	cc
FLAG		=	-Wall -Wextra -Werror
LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libft.a
MLX_FILE	=	libmlx.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_FLAG	=	-lX11 -lXext
MLX_PATH	=	./minilibx-linux/
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)
C_FILE		=	main.c utils.c check_map_format.c map_utils.c init.c map_handle.c check_path.c key_handler.c map_render.c extract_map.c exit_game.c
SRC_DIR		=	./sources/
INC_DIR		=	./includes/
SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))
OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -I $(INC_DIR) -c $< -o $@

all: $(NAME)

lib: $(LIBFT_LIB)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

mlx: $(MLX_LIB)

$(MLX_LIB):
	@make -sC $(MLX_PATH)

$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
