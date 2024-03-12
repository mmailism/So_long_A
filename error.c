#include "includes/so_long.h"

static void	check_error_xpm(t_mlx_data *game)
{
	if (!game->tiles.wall)
		panic(game, WALL_XPM_ERR);
	if (!game->tiles.floor)
		panic(game, PLAYER_XPM_ERR);
	if (!game->tiles.player)
		panic(game, PLAYER_XPM_ERR);
	if (!game->tiles.collectible)
		panic(game, COLLECTIBLE_XPM_ERR);
	if (!game->tiles.exit)
		panic(game, EXIT_XPM_ERR);
}

int	exit_point(t_mlx_data *game)
{
	int	line;

	line = 0;
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	while (line < game->heightmap - 1)
		free(game->map.map[line++]);
	free(game->map.map);
	exit(0);
}

static int	vertical_wall(t_mlx_data *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map.map[height][0] == '1' && game->map.map[height][width - 1] == '1'))
			return (0);
		height++;
		
	}
	return (1);
}

static int	horizontal_wall(t_mlx_data *game)
{
	
}

static void	is_wall(t_mlx_data *game)
{
	int	vertwall;
	int	horiwall;

	vertwall = vertical_wall(game);
	horiwall = horizontal_wall(game);
	if (!vertwall || !horiwall)
	{
		printf("\nTHIS MAP IS MISSING THE WALLS\n");
		exit_point(quit_game);
	}
}

void	check_error(t_mlx_data *game)
{
	is_wall(game);
	character_valid(game);
}