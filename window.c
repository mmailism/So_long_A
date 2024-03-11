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

void	set_window(t_mlx_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		notify (game, MLX_INIT_ERR);

	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns, game->map.rows, "SO_LONG!");
	if (!game->win_ptr)
		notify (game, MLX_NEW_WINDOW_ERR);
}

int main()
{
	t_mlx_data game;

	// args_check(argc, argv);
	// game = init_game();
	// get_map(argv[1], &game);
	// check_map(&game);
	set_window(&game);
	// render_map(&game);
	runningman(&game);
	return (EXIT_SUCCESS);
}