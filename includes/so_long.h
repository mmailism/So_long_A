#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "error_msg.h"
# include "../mlx/mlx.h"
# include "key.h"
// # include "assert.h"

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

# define WALL_TILE "../img/wall.xpm"
# define FLOOR_TILE "../img/floor.xpm"
# define PLAYER_TILE "../img/player.xpm"
# define ENEMY_TILE "../img/ghost.xpm"
# define COLLECTIBLE_TILE "../img/coin.xpm"
# define EXIT_TILE "../img/exit.xpm"

# define TILE_SIZE 64

// typedef struct s_mlx_data
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	int		x;
// 	int		y;
// 	void	*img_ptr;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	void	*wall;
// 	void	*floor;
// 	void	*player;
// 	void	*collectibles;
// 	void	*exit;
// 	void	*tiles;
// 	char	**map;
// 	int		rows;
// 	int		columns;
//     int		moves;
// }			t_mlx_data;

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_map {
	char			**map;
	int				rows;
	int				columns;
	int				collectibles;
	int				exit;
	int				player;
	t_point			player_pos;
}				t_map;

typedef struct s_tiles {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_tiles;

typedef struct s_mlx_data {
	t_map		map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_tiles		tiles;
	int			moves;
	int			i;
	int			v;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx_data;

static inline t_mlx_data	init_game(void)
{
	return ((t_mlx_data){
		.map.map = NULL,
		.map.rows = 0,
		.map.columns = 0,
		.map.collectibles = 0,
		.map.exit = 0,
		.map.player = 0,
		.tiles.collectible = NULL,
		.tiles.exit = NULL,
		.tiles.floor = NULL,
		.tiles.player = NULL,
		.tiles.wall = NULL,
		.moves = -1,
	});
}

int create_new_window(t_mlx_data *game);
int handle_key_press(int key, t_mlx_data *game);
int quit_game(t_mlx_data *game);

#endif