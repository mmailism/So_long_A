#include "includes/so_long.h"

// mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 10, 1, moves_str);

static void	put_player_n_move_count(t_mlx_data *game)
{
	game->moves += 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player,
		TILE_SIZE * game->x_axis, TILE_SIZE * game->y_axis);
	ft_printf("move count: %i\n", game->moves);
}

static void	which_tile(t_mlx_data *game)
{
	if (game->map[game->y_axis]
		[game->x_axis] == COLLECTIBLE)
	{
		game->map[game->y_axis]
		[game->x_axis] = OPEN_SPACE;
		game->collec_cnt -= 1;
		return ;
	}
	if (game->map[game->y_axis][game->x_axis] == EXIT
		&& game->collec_cnt == 0)
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
		if (game->map[game->y_axis + len][game->x_axis] == WALL)
			return ;
		update_left_behide(game);
		game->y_axis += len;
	}
	which_tile(game);
	put_player_n_move_count(game);
}

int	handle_key_press(int key, t_mlx_data *game)
{
	if (key == ESC || key == KEY_X)
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
