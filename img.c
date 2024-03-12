#include "includes/so_long.h"

void	place_images_in_game(t_mlx_data *game)
{
	int	i;

	i = TILE_SIZE;
    printf("mlx : %p", game->mlx_ptr);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL_TILE, &i, &i);
    printf("wall : %p", game->wall);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR_TILE, &i, &i);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_TILE, &i, &i);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_TILE, &i, &i);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &i, &i);
}

void	adding_in_graphics(t_mlx_data *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
            {
                printf("wall : %p", game->wall);
                printf("wIN : %p", game->win_ptr);
                //exit(0);
    			mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->wall, width * 40, height * 40);
                //exit(0);
            }
            printf("Here");
        //    exit(0);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				create_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->exit, width * 40, height * 40);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->floor, width * 40, height * 40);
			width++;
		}
		height++;
	}
}

void	place_collectable(t_mlx_data *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->collectable, width * 40, height * 40);
	game->collectables++;
}
