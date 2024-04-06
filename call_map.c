#include "so_long.h"

//!check file is correct (.ber)

static bool	is_ber_file(const char *map_file)
{
	size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".ber", &map_file[i], 4) == 0)
		return (true);
	return (false);
}

static void get_nbr_row(char *map_file, t_mlx_data *game)
{
    int     cnt;
    int     map_fd;
    char    *tmp;

    cnt = 0;
    map_fd = open(map_file, O_RDONLY);
    if (map_fd == -1)
        quit_game(game);
    tmp = get_next_line(map_fd);
    while (tmp)
    {
        cnt += 1;
        free(tmp);
        tmp = get_next_line(map_fd);
    }
    if (cnt == 0)
        quit_game(game);
    game->map.rows = cnt;
    close(map_fd);
}

// Function to trim specified characters from the end of a string and free the original memory.
char *trim_free(char *str, const char *chars_to_trim)
{
    if (str == NULL || chars_to_trim == NULL)
        return NULL;

    size_t len = ft_strlen(str);

    // Traverse the string from the end and remove specified characters
    while (len > 0 && ft_strchr(chars_to_trim, str[len - 1]) != NULL) {
        str[len - 1] = '\0';
        len--;
    }

    // If the entire string was trimmed, free the original and return NULL
    if (len == 0) {
        free(str);
        return (NULL);
    }

    // Return the trimmed string
    return (str);
}

static void get_lines(char *map_file, t_mlx_data *game)
{
    int map_fd;
    int i;

    map_fd = open(map_file, O_RDONLY);
    if (map_fd == -1)
        quit_game(game);
    i = 0;
    while (i < game->map.rows)
        game->map.map[i++] = get_next_line(map_fd);
    game->map.map[i] = NULL;
    close(map_fd);
    i = 0;
    while (i < (game->map.rows - 1))
    {
        game->map.map[i] = trim_free(game->map.map[i], "\n");
        if (game->map.map[i])
            quit_game(game);
        i += 1;
    }
    game->map.columns = ft_strlen(game->map.map[0]);
}

void    get_map(char *map_file, t_mlx_data *game)
{
    if (!is_ber_file(map_file))
        quit_game(game);
    get_nbr_row(map_file, game);
    game->map.map = malloc((game->map.rows + 1) * sizeof(char *));
    if (!game->map.map)
        quit_game(game);
    get_lines(map_file, game);
}

int main(int argc, char **argv)
{
    // Check command-line arguments
    if (argc != 2)
    {
        // Print usage information
        return 1;
    }

    // Initialize game data structure
    t_mlx_data game;
    // Initialize or set default values for members of game structure

    // Check if it's a valid .ber file
    if (!is_ber_file(argv[1]))
        quit_game(&game);

    // Read and process the map
    get_map(argv[1], &game);

    // Create a new window
    if (create_new_window(&game) != EXIT_SUCCESS)
        quit_game(&game);

    // Run the game loop or perform other tasks

    // Clean up resources
    quit_game(&game);

    return (0);
}

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         printf("Usage: %s <map.ber>\n", argv[0]);
//         return 1;
//     }

//     t_mlx_data vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 800, 600, "MiniLibX Example");

//     if (!read_map_from_file(argv[1], &vars))
//         return 1;

//     draw_map(&vars);

//     mlx_loop(vars.mlx);

//     return 0;
// }
