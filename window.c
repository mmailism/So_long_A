#include "includes/so_long.h"

/* set_start is start use a minilibx by funtion mlx_init*/

void	set_start(t_mlx_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		notify(game, MLX_INIT_ERR);
}

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
