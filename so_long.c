#include "so_long.h"

void	notify(t_mlx_data *game, char *error_msg)
{
	quit_game(game);
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_SUCCESS);
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

void draw_image(t_mlx_data *game)
{
	if (game->img_ptr == NULL)
	{
		printf("Error: Image not loaded.\n");
		return;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, game->horizontal, game->vertical);
}

int handle_key_press(int key, t_mlx_data *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (key == ESC || key == Key_x)
	{
		printf("Key ESC or Key x has been pressed\n");
		quit_game(game);
	}
	else if (key == W || key == UP)
	{
		printf("Key W or Key Arrow UP has been pressed\n");
		game->vertical -= 25;
	}
	else if (key == A || key == LEFT)
	{
		printf("Key A or Key Arrow LEFT has been pressed\n");
		game->horizontal -= 25;
	}
	else if (key == S || key == DOWN)
	{
		printf("Key S or Key Arrow DOWN has been pressed\n");
		game->vertical += 25;
	}
	else if (key == D || key == RIGHT)
	{
		printf("Key D or Key Arrow RIGHT has been pressed\n");
		game->horizontal += 25;
	}
	draw_image(game);
	return (0);
}

void create_player(t_mlx_data *game)
{
	game->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "img/player.xpm", &game->horizontal, &game->vertical);
	game->addr = mlx_get_data_addr(game->img_ptr, &game->bits_per_pixel, &game->line_length, &game->endian);
	game->horizontal = 0;
	game->vertical = 0;
}

void runningman(t_mlx_data *game)
{
	mlx_hook(game->win_ptr, KEYPRESS_EVENT, 1L << 0, handle_key_press, game);
	mlx_hook(game->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), quit_game, game);

	create_player(game);
	draw_image(game);

	mlx_loop(game->mlx_ptr);
}

void set_window(t_mlx_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		quit_game(game);

	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "So long GAME!!");
	if (game->win_ptr == NULL)
		quit_game(game);
}

