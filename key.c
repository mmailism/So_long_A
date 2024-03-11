#include "includes/so_long.h"

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