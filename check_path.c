#include "includes/so_long.h"

void	check_fill_pni(t_mlx_data *game, int height, int width, bool *is_f)
{
	if (game->map[height][width - 1] != '1' && game->map[height][width - 1] != 'P')
	{
		game->map[height][width - 1] = 'P';
		*is_f = true;
	}
	if (game->map[height][width + 1] != '1' && game->map[height][width + 1] != 'P')
	{
		game->map[height][width + 1] = 'P';
		*is_f = true;
	}
	if (game->map[height + 1][width] != '1' && game->map[height + 1][width] != 'P')
	{
		game->map[height + 1][width] = 'P';
		*is_f = true;
	}
	if (game->map[height - 1][width] != '1' && game->map[height - 1][width] != 'P')
	{
		game->map[height - 1][width] = 'P';
		*is_f = true;
	}
}

bool	check_after(t_mlx_data *game)
{
	int	height;
	int	width;

	height = 0;
	while (game->map[height])
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'E' && game->map[height][width] == 'C')
				return (false);
			width++;
		}
		height++;
	}
	return (true);
}

bool	check_path(t_mlx_data *game)
{
	bool	is_f;
	int		height;
	int		width;

	height = 0;
	is_f = true;
	while (game->map[height])
	{
		width = 0;
		is_f = false;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'P')
				check_fill_pni(game, height, width, &is_f);
			width++;
		}
		height++;
	}
	printf("%d", is_f);
	return (0);
}
