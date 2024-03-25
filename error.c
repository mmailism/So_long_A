#include "includes/so_long.h"

static int	vertical_wall(t_mlx_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->widthmap;
	while (i < game->heightmap)
	{
		if (!(game->map[i][0] == '1' && game->map[i][j - 1] == '1'))
			return (0);
		i++;
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
		ft_printf("\nTHIS MAP IS MISSING THE WALLS\n");
		quit_game(game);
	}
}

void	count_check(t_mlx_data *game, int height, int width)
{
	if (game->map[height][width] != WALL &&
		game->map[height][width] != OPEN_SPACE &&
		game->map[height][width] != PLAYER &&
		game->map[height][width] != EXIT &&
		game->map[height][width] != COLLECTIBLE &&
		game->map[height][width] != '\n')
	{
		ft_printf("error: %c\n", game->map[height][width]);
		quit_game(game);
	}
	if (game->map[height][width] == COLLECTIBLE)
		game->colleccount++;
	if (game->map[height][width] == PLAYER)
		game->playercount++;
	if (game->map[height][width] == EXIT)
		game->exitcount++;
}

void	check_error(t_mlx_data *game)
{
	is_wall(game);
	character_valid(game);
	// if (!check_path(game))
}
