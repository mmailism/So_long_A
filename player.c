#include "includes/so_long.h"

// void create_player(t_mlx_data *game, int height, int width)
// {
// 	// game->x_axis = height;
// 	// game->y_axis = width;
// 	mlx_put_image_to_window(game->mlx_ptr,
// 		game->win_ptr, game->player, width, height);
// 	// game->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "img/player.xpm", &game->horizontal, &game->vertical);
// 	// game->addr = mlx_get_data_addr(game->img_ptr, &game->bits_per_pixel, &game->line_length, &game->endian);
// 	// game->horizontal = 0;
// 	// game->vertical = 0;
// }

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

	// adding_in_graphics(game);

	mlx_loop(game->mlx_ptr);
}
