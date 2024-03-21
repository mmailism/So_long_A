#include "includes/so_long.h"

void	put_player_tile(t_mlx_data *game)
{
	char	*moves_str;

	game->moves += 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player,
		TILE_SIZE * game->x_axis, TILE_SIZE * game->y_axis);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->wall, 0, 0);
	moves_str = ft_itoa(game->moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 10, 1, moves_str);
	free(moves_str);
}

static void	which_tile(t_mlx_data *game)
{
	if (game->map[game->y_axis]
		[game->x_axis] == COLLECTIBLE)
	{
		game->map[game->y_axis]
		[game->x_axis] = OPEN_SPACE;
		game->collectables -= 1;
		return ;
	}
	if (game->map[game->y_axis][game->x_axis] == EXIT
		&& game->collectables == 0)
	{
		ft_printf("You Found the EXIT!!!!\n");
		quit_game(game);
	}
}

static void	update_left_behide(t_mlx_data *game)
{
	if (game->map[game->y_axis][game->x_axis] == EXIT)
	{
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->exit,
			TILE_SIZE * game->x_axis,
			TILE_SIZE * game->y_axis);
	}
	else
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->floor,
			TILE_SIZE * game->x_axis,
			TILE_SIZE * game->y_axis);
}

void	player_pos(t_mlx_data *game, bool horizontal, int len)
{
	if (horizontal)
	{
		if (game->map[game->y_axis][game->x_axis + len] == WALL)
			return ;
		update_left_behide(game);
		game->x_axis += len;
	}
	else
	{
		if (game->map[game->y_axis + len]
			[game->x_axis] == WALL)
			return ;
		update_left_behide(game);
		game->y_axis += len;
	}
	which_tile(game);
	put_player_tile(game);
}

int	handle_key_press(int key, t_mlx_data *game)
{
	if (key == ESC || key == Key_x)
		quit_game(game);
	else if (key == W || key == UP)
		player_pos(game, false, -1);
	else if (key == A || key == LEFT)
		player_pos(game, true, -1);
	else if (key == S || key == DOWN)
		player_pos(game, false, 1);
	else if (key == D || key == RIGHT)
		player_pos(game, true, 1);
	return (EXIT_SUCCESS);
}
