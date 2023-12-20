/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:58:57 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/20 12:12:25 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_to_image(t_game *init_game, void **image, char *location)
{
	int width;
	int	height;

	*image = mlx_xpm_file_to_image(init_game->mlx_ptr, location, &width, &height);
	if (!image)
		ft_error("Error with sprites");
}

void	ft_init_sprite(t_game *init_game)
{
	ft_to_image(init_game, &init_game->graphic.wall, "resources/wall.xpm");
	ft_to_image(init_game, &init_game->graphic.floor, "resources/floor.xpm");
	ft_to_image(init_game, &init_game->graphic.collectibles, "resources/bank.xpm");
	//ft_to_image(init_game, &init_game->graphic.open_exit, ...);
	//ft_to_image(init_game, &init_game->graphic.closed_exit, ...);
	//ft_to_image(init_game, &init_game->graphic.player_right, ...);
	//ft_to_image(init_game, &init_game->graphic.player_left, ...);
	ft_to_image(init_game, &init_game->graphic.player_front, "resources/thief.xpm");
	//ft_to_image(init_game, &init_game->graphic.player_back, ...);
}

void	ft_init_window(t_game *init_game)
{
	init_game->mlx_ptr = mlx_init();
	if (!init_game->mlx_ptr)
	{
		free(init_game->mlx_ptr);
		ft_error("");
	}
	ft_init_sprite(init_game);
	init_game->mlx_window = mlx_new_window(init_game->mlx_ptr, \
	init_game->map.columns * IMG_WIDTH, init_game->map.rows * IMG_HEIGHT, "so_long");
	if (!init_game->mlx_window)
	{
		//mlx_destroy_display(init_game->mlx_ptr);
		free(init_game->mlx_ptr);
		ft_error("");
	}
}

void	ft_init_count(t_game *init_game)
{
	ft_memset(&init_game->count, 0, sizeof(t_map_items));
	init_game->map.columns = ft_strlen(init_game->map.grid[0]) - 1;
	// Do we need to start the player?
}