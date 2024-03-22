#include "includes/so_long.h"

/*	check argc is 2 if not return it
	ft_memset is set 0 for argument game
	set_start is start minilibx
	map_reading is function read a map_file 
*/

int	main(int argc, char **argv)
{
	t_mlx_data	game;

	if (argc != 2)
	{
		ft_printf("Usage: %s <name_map_file.ber>\n", argv[0]);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_mlx_data));
	set_start(&game);
	map_reading(&game, argv);
	check_error(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr,
			(game.widthmap * 64), (game.heightmap * 64), "OS GOLN MEAG!");
	if (!game.win_ptr)
		notify (&game, MLX_NEW_WINDOW_ERR);
	place_images_in_game(&game);
	adding_in_graphics(&game);
	runningman(&game);
	mlx_loop(&game.mlx_ptr);
}
