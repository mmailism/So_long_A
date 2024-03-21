#include "includes/so_long.h"

bool	is_ber_file(const char *map_file)
{
	size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".ber", &map_file[i], 4) == 0)
		return (true);
	return (false);
}

int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

int	add_line(t_mlx_data *game, char *line)
{
	char	**tmppo;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	tmppo = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	tmppo[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		tmppo[i] = game->map[i];
		i++;
	}
	tmppo[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmppo;
	return (1);
}

int	map_reading(t_mlx_data *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (is_ber_file(argv[1]) == false)
	{
		ft_printf("Usage: %s <name_map_file.ber>\n", argv[0]);
		exit(0);
	}
	if (game->fd == -1)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close(game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
