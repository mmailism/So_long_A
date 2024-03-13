#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "error_msg.h"
# include "../mlx/mlx.h"
# include "key.h"
# include "assert.h"

// # define MALLOC_ERR 1
# define SIDE_LEN 800
# define WIDTH 800
# define HEIGHT 600
# define SQUARE_SIZE 50
# define X 50
# define Y 50

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

# define KEYPRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17
# define MOVE_STEP 5

# define WALL_TILE "./img/wall.xpm"
# define FLOOR_TILE "./img/floor.xpm"
# define PLAYER_TILE "./img/player.xpm"
# define ENEMY_TILE "./img/ghost.xpm"
# define COLLECTIBLE_TILE "./img/coin.xpm"
# define EXIT_TILE "./img/exit.xpm"

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
	int		counter;
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
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_mlx_data;

void	set_window(t_mlx_data *game);
void	notify(t_mlx_data *game, char *error_msg);
int handle_key_press(int key, t_mlx_data *game);
int quit_game(t_mlx_data *game);
void draw_image(t_mlx_data *game);
void create_player(t_mlx_data *game, int height, int width);
void runningman(t_mlx_data *game);
void	check_error(t_mlx_data *game);
int	exit_point(t_mlx_data *game);
void	character_valid(t_mlx_data *game);
void	place_images_in_game(t_mlx_data *game);
void	adding_in_graphics(t_mlx_data *game);
void	place_collectable(t_mlx_data *game, int height, int width);
int	map_reading(t_mlx_data *game, char **argv);
// int	right_move(t_mlx_data *game, int i, int j);
void	put_player_tile(t_mlx_data *game);
void	place_player(t_mlx_data *game, int height, int width);

#endif