#include "../so_long.h"

int	ft_check_map_validity(char **av)
{
	int	i;

	i = ft_strlen(av[1]);
	if (ft_strnstr(&av[1][i - 4], ".ber", 4) == NULL)
		return (0);
	else
		return (1);
}

void	ft_init_map(t_game *init_game, char *av)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(av, O_RDONLY);
	if (map_fd == -1)
		ft_handle_error("The Map couldn't be opened. Does the Map exist?", init_game);
	map_temp = ft_strdup("");
	init_game->map.rows = 0;
	while (1)
	{
		line_temp = get_next_line(map_fd);
		if (!line_temp)
			break ;
		map_temp = ft_strappend(&map_temp, line_temp);
		free(line_temp);
		init_game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(map_temp, init_game);
	init_game->map.grid = ft_split(map_temp, '\n');

    ft_printf("grid = %s\n", init_game->map.grid);
    
	init_game->game_alloc = 1;
	free(map_temp);
}

void	ft_check_for_empty_line(char *map, t_game *init_game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_handle_error("Invalid map.\
The map have an empty line right at the beginning.", init_game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free (map);
		ft_handle_error("Invalid map. \
The map have an empty line at the end.", init_game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_handle_error("Invalid map. \
The map have an empty line at the middle.", init_game);
		}
		i++;
	}
}

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}