#include "includes/so_long.h"

// static void	check_error_xpm(t_mlx_data *game)
// {
// 	if (!game->tiles.wall)
// 		notify(game, WALL_XPM_ERR);
// 	if (!game->tiles.floor)
// 		notify(game, PLAYER_XPM_ERR);
// 	if (!game->tiles.player)
// 		notify(game, PLAYER_XPM_ERR);
// 	if (!game->tiles.collectible)
// 		notify(game, COLLECTIBLE_XPM_ERR);
// 	if (!game->tiles.exit)
// 		notify(game, EXIT_XPM_ERR);
// }

int	exit_point(t_mlx_data *game)
{
	int	line;

	line = 0;
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
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
		if (!(game->map[height][0] == '1' && game->map[height][width - 1] == '1'))
			return (0);
		height++;
		
	}
	return (1);
}

static int	horizontal_wall(t_mlx_data *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->heightmap - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
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
		exit_point(game);
	}
}

static void	count_check(t_mlx_data *game, int height, int width)
{
	if (game->map[height][width] != WALL &&
		game->map[height][width] != OPEN_SPACE &&
		game->map[height][width] != PLAYER &&
		game->map[height][width] != EXIT &&
		game->map[height][width] != COLLECTIBLE &&
		game->map[height][width] != '\n')
	{
		//printf("cerror: %c", game->map[height][width]);
		printf("h: %d\n",  height);
		printf("w: %d\n",  width);
		printf("\nError Here!\n");
		exit_point(game);
	}
	if (game->map[height][width] == COLLECTIBLE)
			game->columncount++;
	if (game->map[height][width] == PLAYER)
			game->playercount++;
	if (game->map[height][width] == EXIT)
			game->exitcount++;
}

void	character_valid(t_mlx_data *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_check(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->columncount >= 1 && game->exitcount == 1))
	{
		printf("play_c: %d \n col_c : %d \n exit_c: %d", game->playercount, game->columncount, game->exitcount);
		printf("\nERROR SOMETHING IS WRONG\n");
		printf("either player, exit or collectable issue\n");
		exit_point(game);
	}

}

void	check_error(t_mlx_data *game)
{
	is_wall(game);
	//printf("play_c: %d \n col_c : %d \n exit_c: %d", game->playercount, game->columncount, game->exitcount);
	character_valid(game);
}
