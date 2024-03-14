#include "includes/so_long.h"

int quit_game(t_mlx_data *game)
{
	if (!game)
		return (0);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}

void	notify(t_mlx_data *game, char *error_msg)
{
	quit_game(game);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_SUCCESS);
}
//! start window
void	set_window(t_mlx_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		notify (game, MLX_INIT_ERR);
}

void	put_img_to_win(t_mlx_data *game)
{
	void	*image;
	int		size;

	size = TILE_SIZE;
	image = mlx_xpm_file_to_image(game->mlx_ptr, "/img/1.xpm", &size, &size);
    if (!image) {
        // Handle error loading image
        fprintf(stderr, "Error loading image.\n");
        return ;
    }

    // Draw the image onto the window as the background
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, game->widthmap * 64, game->heightmap * 64);
}
