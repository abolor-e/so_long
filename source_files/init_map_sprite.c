/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:04:40 by abolor-e          #+#    #+#             */
/*   Updated: 2024/01/09 20:13:05 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_render(t_game *init_game, void *image, int x, int y)
{
	mlx_put_image_to_window (init_game->mlx_ptr, init_game->mlx_window, 
		image, y * 64, x * 64);
}

void	ft_sprite(t_game *init_game, int y, int x)
{
	char	c;

	c = init_game->map.grid[y][x];
	ft_render(init_game, init_game->graphic.floor, y, x);
	if (c == '1')
		ft_render(init_game, init_game->graphic.wall, y, x);
	else if (c == 'P')
		ft_render(init_game, init_game->graphic.player_front, y, x);
	else if (c == 'E')
	{
		if (init_game->count.collectibles == 0)
			ft_render(init_game, init_game->graphic.open_exit, y, x);
		else
			ft_render(init_game, init_game->graphic.closed_exit, y, x);
	}
	else if (c == 'C')
		ft_render(init_game, init_game->graphic.collectibles, y, x);
}

int	ft_recognize_mapsprite(t_game *init_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < init_game->map.rows)
	{
		x = 0;
		while (x < init_game->map.columns)
		{
			ft_sprite(init_game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_player_movement(t_game *init_game, int y, int x)
{
	int	moved_y;
	int	moved_x;

	moved_y = init_game->player.y;
	moved_x = init_game->player.x;
	if (init_game->map.grid[y][x] == '0' || init_game->map.grid[y][x] == 'C')
	{
		init_game->map.grid[moved_y][moved_x] = '0';
		if (init_game->map.grid[y][x] == 'C')
			init_game->count.collectibles--;
		init_game->player.x = x;
		init_game->player.y = y;
		init_game->map.grid[y][x] = 'P';
		//Movements!
	}
	else if (init_game->map.grid[y][x] == 'E' && 
		init_game->count.collectibles == 0)
	{
		ft_win(init_game);
	}
	ft_recognize_mapsprite(init_game);
}

int	ft_check_key(int key, t_game *init_game)
{
	if (key == KEY_ESC)
		ft_handle_error("Key ESC pressed!\n", init_game);
	else if (key == KEY_A)
		ft_player_movement(init_game, init_game->player.y, 
			init_game->player.x - 1);
	else if (key == KEY_W)
		ft_player_movement(init_game, init_game->player.y - 1, 
			init_game->player.x);
	else if (key == KEY_S)
		ft_player_movement(init_game, init_game->player.y + 1, 
			init_game->player.x);
	else if (key == KEY_D)
		ft_player_movement(init_game, init_game->player.y, 
			init_game->player.x + 1);
	return (0);
}
