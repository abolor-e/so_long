/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:37:48 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/22 14:20:32 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_map_parse(t_game *init_game, int m_fd);

int	ft_check_map_validity(char **av)
{
	int	i;

	i = ft_strlen(av[1]);
	if (ft_strnstr(&av[1][i - 4], ".ber", 4) == NULL)
		return (0);
	else
		return (1);
}

void	ft_check_newline(char *line_tmp, t_game *init_game)
{
	int	i;

	i = 0;
	while (line_tmp[i])
	{
		if (line_tmp[i] == '\n' && line_tmp[i + 1] == '\n')
		{
			free(line_tmp);
			ft_handle_error("Error: Consecutive newlines in the map!\n", init_game);
		}
		i++;
	}
	if (line_tmp[0] == '\n')
	{
		free(line_tmp);
		ft_handle_error("Error: Newline in the beginning of the map!\n", init_game);
	}
	if (line_tmp[i] == '\n')
	{
		free(line_tmp);
		ft_handle_error("Error: Newline in the end of the map!\n", init_game);
	}
}


char	*ft_add_gnlmap(char **line_tmp, char *next_line)
{
	if (!*line_tmp || !next_line)
		return (NULL);
	char	*string;

	string = ft_calloc((ft_strlen(*line_tmp) + ft_strlen(next_line) + 1), sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, *line_tmp, ft_strlen(*line_tmp) + 1);
	ft_strlcat(string, next_line, ft_strlen(*line_tmp) + ft_strlen(next_line) + 1);
	free(*line_tmp);
	return (string);
}


static void	ft_map_parse(t_game *init_game, int m_fd)
{
	char	*next_line;
	char	*line_tmp;
	
	line_tmp = ft_strdup("");
	init_game->map.rows = 0;
	while (1)
	{
		next_line = get_next_line(m_fd);
		if (!next_line)
			break ;
		line_tmp = ft_add_gnlmap(&line_tmp, next_line);
		free(next_line);
		init_game->map.rows++;
	}
	ft_check_newline(line_tmp, init_game);
	init_game->map.grid = ft_split(line_tmp, '\n');
	free(line_tmp);
}

void	ft_init_map(char *av, t_game *init_game)
{
	int	m_fd;
	
	m_fd = open(av, O_RDONLY);
	if (m_fd < 0)
	{
		ft_handle_error("Error: Cannot open the map, check file descriptor!\n", init_game);
	}
	ft_map_parse(init_game, m_fd);
	close(m_fd);
	init_game->game_alloc = 1;
	ft_init_count(init_game);
}
