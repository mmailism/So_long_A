CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
INCLUDE = -I./includes
LIBFT = ./libft/libft.a
FTPRINTF = ./ft_printf/libftprintf.a
RM = rm -rf
NAME = so_long

SRCS = map.c key.c error.c img.c player.c window.c main.c check_path.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR)  $(OBJS)
	$(MAKE) -C ././libft
	$(MAKE) -C ././mlx
	$(MAKE) -C ././ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FTPRINTF) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	
re: fclean all

run: all clean

.SILENT:
