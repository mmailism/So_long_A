#include "includes/so_long.h"

int main(int argc, char **argv) 
{
	t_mlx_data game_data;

	if (argc != 2) 
    {
	   fprintf(stderr, "Usage: %s <map_file.ber>\n", argv[0]);
	   return 1;  // Exit with an error code
    }
    ft_memset(&game_data, 0, sizeof(t_mlx_data)); //set 0 for game_data 
    set_window(&game_data);
    map_reading(&game_data, argv);

    check_error(&game_data);
    game_data.win_ptr = mlx_new_window(game_data.mlx_ptr, (game_data.widthmap * 64), (game_data.heightmap * 64), "SO_LONG!");
	if (!game_data.win_ptr)
		notify (&game_data, MLX_NEW_WINDOW_ERR);
    put_img_to_win(&game_data);
    place_images_in_game(&game_data);
	adding_in_graphics(&game_data);

    runningman(&game_data);
    mlx_loop(&game_data.mlx_ptr);
}