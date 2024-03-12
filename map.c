#include "includes/so_long.h"

//!check file  is .ber 

bool	is_ber_file(const char *map_file)
{
	size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".ber", &map_file[i], 4) == 0)
		return (true);
	return (false);
}

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int  add_line(t_mlx_data *game, char *line)
{
    char    **tmppo;
    int     i;

    if (!line)
        return (0);
    i = 0;
    game->heightmap++;
    tmppo = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
    tmppo[game->heightmap] = NULL;
    while (i < game->heightmap - 1)
    {
        tmppo[i] = game->map.map[i];
        i++;
    }
    tmppo[i] = line;
    if (game->map.map)
        free(game->map.map);
    game->map.map = tmppo;
    return (1);
}

int map_reading(t_mlx_data *game, char **argv)
{
    char    *readmap;

    game->fd = open(argv[1], O_RDONLY);
    if (game->fd < 0)
        return (0);
    while (1)
    {
        readmap = get_next_line(game->fd);
        if (!add_line(game, readmap))
            break;
    }
    close (game->fd);
    game->widthmap = width_of_map(game->map.map[0]);
    return (1);
}

int main(int argc, char **argv) {
    // Initialize your game data structure
    t_mlx_data game_data;
    // Set appropriate initial values for game_data members
     if (argc != 2) {
        fprintf(stderr, "Usage: %s <map_file.ber>\n", argv[0]);
        return 1;  // Exit with an error code
    }
    // Call the function to check if the file is a .ber file and load the map
    ft_memset(&game_data, 0, sizeof(t_mlx_data));
    map_reading(&game_data, argv);
    printf("%d", map_reading(&game_data, argv));

    set_window(&game_data);
    runningman(&game_data);
    // printf("%s", (char *)argv[1]);
    // Perform other tasks or game logic

    return 0;  // Exit successfully
}