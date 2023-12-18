#include "so_long.h"

int	ft_check_map_argument(char **av)
{
	int	i;

	i = ft_strlen(av[1]);
	if (ft_strnstr(av[1][i - 4], ".ber", 4) == NULL)
		return (0);
}

void	init_map(char *av, t_game *init_game)
{
	int	m_fd;
	
	m_fd = open(av, O_RDONLY);
	if (m_fd < 0)
		ft_error("Error: Cannot open the map!", init_game);
	ft_parse_map(init_game, m_fd);
}

static void	ft_parse_map(t_game *init_game, int m_fd)
{
	char	*line_tmp;
	
	line_tmp = ft_strdup("");
	init_game->map.rows = 0;
	while (1)
	{
			
	}
}
