#include "includes/so_long.h"

void	place_player(t_mlx_data *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->player, width * 64, height * 64);
	game->y_axis = height;
	game->x_axis = width;
}

void runningman(t_mlx_data *game)
{
	mlx_hook(game->win_ptr, KEYPRESS_EVENT, (1L << 0), handle_key_press, game);
	mlx_hook(game->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), quit_game, game);

	adding_in_graphics(game);

	mlx_loop(game->mlx_ptr);
}
