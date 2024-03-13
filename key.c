#include "includes/so_long.h"

// static void	which_tile(t_mlx_data *game);
// void	put_player_tile(t_mlx_data *game);
// static void	update_left_behide(t_mlx_data *game);
// void	player_pos(t_mlx_data *game, bool horizontal, int len);

// void draw_image(t_mlx_data *game)
// {
// 	if (game->img_ptr == NULL)
// 	{
// 		printf("Error: Image not loaded.\n");
// 		return ;
// 	}
// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, game->x_axis, game->y_axis);
// }

void	put_player_tile(t_mlx_data *game)
{
	char	*moves_str;

	game->moves += 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player,
		TILE_SIZE * game->x_axis, TILE_SIZE * game->y_axis);
	// place_player(game, game->x_axis, game->y_axis);
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
		printf("WIN_MSG");
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
	{
		printf("Key ESC or Key x has been pressed\n");
		quit_game(game);
	}
	else if (key == W || key == UP)
	{
		printf("Key W or Key Arrow UP has been pressed\n");
		player_pos(game, false, -1);
		// game->y_axis -= 25;
	}
	else if (key == A || key == LEFT)
	{
		printf("Key A or Key Arrow LEFT has been pressed\n");
		player_pos(game, true, -1);
		// game->x_axis -= 25;
	}
	else if (key == S || key == DOWN)
	{
		printf("Key S or Key Arrow DOWN has been pressed\n");
		player_pos(game, false, 1);
		// game->y_axis += 25;
	}
	else if (key == D || key == RIGHT)
	{
		printf("Key D or Key Arrow RIGHT has been pressed\n");
		player_pos(game, true, 1);
		// game->x_axis += 25;
	}
	// adding_in_graphics(game);
	return (EXIT_SUCCESS);
}
