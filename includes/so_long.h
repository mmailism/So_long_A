#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>//open, O_RDONLY
# include <unistd.h>//read, close, write
# include <stdlib.h>//malloc
# include <stdio.h>//printf
# include <stdbool.h>//bool
# include <stdarg.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "error_msg.h"
# include "../mlx/mlx.h"
# include "key.h"
# include "assets.h"

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define ENEMY '2'

# define KEYPRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17
# define MOVE_STEP 5
# define TILE_SIZE 64

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	// int		counter;
	int		collectables;
	int		moves;

	char	**map;

	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	// char	*addr;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;

}	t_mlx_data;

void	set_window(t_mlx_data *game);
void	notify(t_mlx_data *game, char *error_msg);
int		handle_key_press(int key, t_mlx_data *game);
int		quit_game(t_mlx_data *game);
void	draw_image(t_mlx_data *game);
void	create_player(t_mlx_data *game, int height, int width);
void	runningman(t_mlx_data *game);
void	check_error(t_mlx_data *game);
int		exit_point(t_mlx_data *game);
void	character_valid(t_mlx_data *game);
void	place_images_in_game(t_mlx_data *game);
void	adding_in_graphics(t_mlx_data *game);
void	place_collectable(t_mlx_data *game, int height, int width);
int		map_reading(t_mlx_data *game, char **argv);
void	put_player_tile(t_mlx_data *game);
void	place_player(t_mlx_data *game, int height, int width);
void	put_img_to_win(t_mlx_data *game);
void	put_graphics(t_mlx_data *game, int height, int width);

#endif