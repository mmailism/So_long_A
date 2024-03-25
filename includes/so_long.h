#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>//open, O_RDONLY
# include <unistd.h>//read, close, write
# include <stdlib.h>//malloc
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
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		colleccount;
	int		exitcount;
	int		fill_cnt;
	int		x_axis;
	int		y_axis;
	int		collec_cnt;
	int		moves;

	char	**map;

	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;
}	t_mlx_data;

void	set_start(t_mlx_data *game);
void	notify(t_mlx_data *game, char *error_msg);
int		handle_key_press(int key, t_mlx_data *game);
int		quit_game(t_mlx_data *game);
void	draw_image(t_mlx_data *game);
void	create_player(t_mlx_data *game, int height, int width);
void	runningman(t_mlx_data *game);
void	check_error(t_mlx_data *game);
void	character_valid(t_mlx_data *game);
void	place_images_in_game(t_mlx_data *game);
void	adding_in_graphics(t_mlx_data *game);
void	place_collectable(t_mlx_data *game, int height, int width);
int		map_reading(t_mlx_data *game, char **argv);
void	place_player(t_mlx_data *game, int height, int width);
void	put_img_to_win(t_mlx_data *game);
void	put_graphics(t_mlx_data *game, int height, int width);
void	check_error(t_mlx_data *game);
void	character_valid(t_mlx_data *game);
void	count_check(t_mlx_data *game, int height, int width);
bool	check_after(t_mlx_data *game);
bool	check_path(t_mlx_data *game);
void	check_fill_pni(t_mlx_data *game, int height, int width, bool *is_f);

#endif