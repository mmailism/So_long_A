static void	check_error_on_xpms(t_mlx_data *game)
{	
	if (!game->wall)
		quit_game(game);
	if (!game->floor)
		quit_game(game);
	if (!game->player)
		quit_game(game);
	if (!game->collectible)
		quit_game(game);
	if (!game->exit)
		quit_game(game);
}

void	render_tiles(t_mlx_data *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->columns)
		{
			if (game->map[i][j] == WALL)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->wall, TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->collectible, TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map[i][j] == EXIT)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->exit, TILE_SIZE * j, TILE_SIZE * i);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->floor, TILE_SIZE * j, TILE_SIZE * i);
		}
	}
	create_player(game);
}

void	get_map(t_mlx_data *game)
{
	map_open(game);
	game->map = malloc((game->rows + 1) * sizeof(char *));
	if (!game->map)
		quit_game(game);
	get_lines(game);
}

void	render_map(t_mlx_data *game)
{
	open_xpm(game);
	render_tiles(game);
}

static void	open_xpm(t_mlx_data *game)
{	
	int	img_size;

	img_size = TILE_SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL_TILE, &img_size, &img_size);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR_TILE, &img_size, &img_size);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_TILE, &img_size, &img_size);
	game->collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &img_size, &img_size);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_TILE, &img_size, &img_size);
	// check_error_on_xpms(game);
}
