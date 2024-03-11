#include "includes/so_long.h"

//!check file  is .ber 

bool    is_ber_file(const char *map_file)
{
    size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".ber", &map_file[i], 4) == 0)
		return (true);
	return (false);
}

void    get_map(char *map_file, t_mlx_data *game)
{
	if (!is_ber_file(map_file))
		notify(game, INVALID_MAP_FILE);
	get_nbr_rows(map_file, game);
	game->map.map = malloc((game->map.rows + 1) * sizeof(char *));
	if (!game->map.map)
		notify(game, MALLOC_ERR);
	get_lines(map_file, game);
}

static void get_nbr_rows(char *map_file, t_mlx_data *game)
{
    int     cnt;
    int     map_fd;
    char    *tmp;

    cnt = 0;
    map_fd = open(map_file, O_RDONLY);
    if (map_fd == -1)
		panic(game, OPEN_MAP_FILE_ERR);
    tmp = get_next_line(map_fd);
    while (tmp)
    {
        cnt += 1;
        free(tmp);
        tmp = get_next_line(map_fd);
    }
    if (cnt == 0)
		panic(game, EMPTY_MAP_FILE);
    game->map.rows = cnt;
    close(map_fd);
}

static void get_lines(char *map_file, t_mlx_data *game)
{
    int map_fd;
    int i;

    map_fd = open(map_file, O_RDONLY);
    if (map_fd == -1)
		panic(game, OPEN_MAP_FILE_ERR);
    i = 0;
    while (i < game->map.rows)
        game->map.map[i++] = get_next_line(map_fd);
    game->map.map[i] = NULL;
    close(map_fd);
    i = 0;
    while (i < (game->map.rows - 1))
    {
        game->map.map[i] = ft_strtrim(game->map.map[i], "\n");
        if (game->map.map[i])
			panic(game, MALLOC_ERR);
        i += 1;
    }
    game->map.columns = ft_strlen(game->map.map[0]);
}
