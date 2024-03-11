#include "includes/so_long.h"

static void	check_error_xpm(t_mlx_data *game)
{
	if (!game->tiles.wall)
		panic(game, WALL_XPM_ERR);
	if (!game->tiles.floor)
		panic(game, PLAYER_XPM_ERR);
	if (!game->tiles.player)
		panic(game, PLAYER_XPM_ERR);
	if (!game->tiles.collectible)
		panic(game, COLLECTIBLE_XPM_ERR);
	if (!game->tiles.exit)
		panic(game, EXIT_XPM_ERR);
}
