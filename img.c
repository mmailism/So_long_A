#include "includes/so_long.h"

static void	check_error_xpm(t_mlx_data *game)
{
	if (!game->wall)
		notify(game, WALL_XPM_ERR);
	if (!game->floor)
		notify(game, PLAYER_XPM_ERR);
	if (!game->player)
		notify(game, PLAYER_XPM_ERR);
	if (!game->collectable)
		notify(game, COLLECTIBLE_XPM_ERR);
	if (!game->exit)
		notify(game, EXIT_XPM_ERR);
}

void	place_images_in_game(t_mlx_data *game)
{
	int	img;

	img = TILE_SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL_TILE, &img, &img);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR_TILE, &img, &img);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_TILE, &img, &img);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_TILE, &img, &img);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &img, &img);
	check_error_xpm(game);
}

void	adding_in_graphics(t_mlx_data *game)
{
	int	height;
	int	width;

	game->collec_cnt = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			put_graphics(game, height, width);
			width++;
		}
		height++;
	}
}

void	put_graphics(t_mlx_data *game, int height, int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall, width * TILE_SIZE, height * TILE_SIZE);
	if (game->map[height][width] == 'C')
		place_collectable(game, height, width);
	if (game->map[height][width] == 'P')
		place_player(game, height, width);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit, width * TILE_SIZE, height * TILE_SIZE);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->floor, width * TILE_SIZE, height * TILE_SIZE);
}

void	place_collectable(t_mlx_data *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->collectable, width * TILE_SIZE, height * TILE_SIZE);
	game->collec_cnt++;
}
