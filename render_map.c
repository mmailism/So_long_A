#include "so_long.h"

static void	check_error_xpm(t_mlx_data *game)
{
	if (!game->tiles.wall)
		return (EXIT_SUCCESS);
	if (!game->tiles.floor)
		return (EXIT_FAILURE);
	if (!game->tiles.exit)
		return (EXIT_SUCCESS);
	if (!game->tiles.collectible)
		return (EXIT_SUCCESS);
}

void	open_file_xpm(t_mlx_data *game)
{
	int img_size;

	img_size = TILE_SIZE;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL_TILE, &img_size, &img_size);
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_TILE, &img_size, &img_size);
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_TILE, &img_size, &img_size);
	game->tiles.collectible = mlx_xpm_file_to_image(game->mlx_ptr, COLLECTIBLE_TILE, &img_size, &img_size);
	check_error_xpm(game);
}

void	render_tiles(t_mlx_data *game)
{
	int	p;
	int	j;
	
	p = -1;
	while (++p < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.map[p][j] == WALL)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.wall, TILE_SIZE * j, TILE_SIZE * p);
			else if (game->map.map[p][j] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.collectible, TILE_SIZE * j, TILE_SIZE * p);
			else if (game->map.map[p][j] == EXIT)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.exit, TILE_SIZE * j, TILE_SIZE * p);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.floor, TILE_SIZE * j, TILE_SIZE * p);
		}
	}
}