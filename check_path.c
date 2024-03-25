#include "includes/so_long.h"

static void	check_fill_pni(char ***map, int i, int j, bool *is_f)
{
	if ((*map)[i][j - 1] != '1' && (*map)[i][j - 1] != 'P')
	{
		(*map)[i][j - 1] = 'P';
		*is_f = true;
	}
	if ((*map)[i][j + 1] != '1' && (*map)[i][j + 1] != 'P')
	{
		(*map)[i][j + 1] = 'P';
		*is_f = true;
	}
	if ((*map)[i + 1][j] != '1' && (*map)[i + 1][j] != 'P')
	{
		(*map)[i + 1][j] = 'P';
		*is_f = true;
	}
	if ((*map)[i - 1][j] != '1' && (*map)[i - 1][j] != 'P')
	{
		(*map)[i - 1][j] = 'P';
		*is_f = true;
	}
}

static bool	check_after(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_path(char **map)
{
	bool	is_f;
	int		i;
	int		j;

	is_f = true;
	while (is_f)
	{
		i = 0;
		is_f = false;
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] == 'P')
					check_fill_pni(&map, i, j, &is_f);
				j++;
			}
			i++;
		}
	}
	return (check_after(map));
}
