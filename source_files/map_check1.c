#include "../so_long.h"

void	ft_map_check(t_game *init_game)
{
	ft_check_rows(init_game);
	ft_check_columns(init_game);
	ft_count_map_parameters(init_game);
	ft_verify_map_parameters(init_game);
}

void	ft_check_rows(t_game *init_game)
{
	int	i;

	i = 0;
	while (i < init_game->map.rows)
	{
		if (init_game->map.grid[i][0] != '1')
			ft_handle_error("Invalid Map. \
There's a Wall missing from the first row.\n\
The Map must be surrounded by walls!.", init_game);
		else if (init_game->map.grid[i][init_game->map.columns - 1] != '1')
			ft_handle_error("Invalid Map. \
There's a Wall missing from the last row.\n\
The Map must be surrounded by walls!.", init_game);
		i++;
	}
}

void	ft_check_columns(t_game *init_game)
{
	int	i;

	i = 0;
	while (i < init_game->map.columns)
	{
		if (init_game->map.grid[0][i] != '1')
			ft_handle_error("Invalid Map. \
There's a Wall missing from the first column.\n\
The Map must be surrounded by walls!.", init_game);
		else if (init_game->map.grid[init_game->map.rows - 1][i] != '1')
			ft_handle_error("Invalid Map. \
There's a Wall missing from the last column.\n\
The Map must be surrounded by walls!.", init_game);
		i++;
	}
}

void	ft_count_map_parameters(t_game *init_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < init_game->map.rows)
	{
		x = 0;
		while (x < init_game->map.columns)
		{
			if (!ft_strchr("CEP01", init_game->map.grid[y][x]))
				ft_handle_error("Invalid Map. Not expected map parameter.", init_game);
			else if (init_game->map.grid[y][x] == 'P')
			{
				init_game->count.player++;
				init_game->player.x = x;
				init_game->player.y = y;
			}
			else if (init_game->map.grid[y][x] == 'C')
				init_game->count.collectibles++;
			else if (init_game->map.grid[y][x] == 'E')
				init_game->count.exit++;
			x++;
		}
		y++;
	}
}

void	ft_verify_map_parameters(t_game *init_game)
{
	if (init_game->count.collectibles == 0)
		ft_handle_error("Invalid Map. There are no Coins!", init_game);
	else if (init_game->count.exit == 0)
		ft_handle_error("Invalid Map. There is no Exit.", init_game);
	else if (init_game->count.player != 1)
		ft_handle_error("Invalid Map. Invalid Player quantity. \
It's a single player game.", init_game);
}