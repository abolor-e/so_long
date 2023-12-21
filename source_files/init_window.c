/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:58:57 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/21 16:36:54 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_to_image(t_game *init_game, void **image, char *location)
{
	int width;
	int	height;

	*image = mlx_xpm_file_to_image(init_game->mlx_ptr, location, &width, &height);
	if (!image)
		ft_handle_error("Error: Cannot create image of sprites!\n", init_game);
}

void	ft_init_sprite(t_game *init_game)
{
	ft_to_image(init_game, &init_game->graphic.wall, "game_images/wall.xpm");
	ft_to_image(init_game, &init_game->graphic.floor, "game_images/floor.xpm");
	ft_to_image(init_game, &init_game->graphic.collectibles, "game_images/collectibles.xpm");
	ft_to_image(init_game, &init_game->graphic.open_exit, "game_images/open_exit.xpm");
	ft_to_image(init_game, &init_game->graphic.closed_exit, "game_images/closed_exit.xpm");
	ft_to_image(init_game, &init_game->graphic.player_front, "game_images/thief.xpm");
}

void	ft_init_window(t_game *init_game)
{
	init_game->mlx_ptr = mlx_init();
	if (!init_game->mlx_ptr)
	{
		free(init_game->mlx_ptr);
		ft_handle_error("Error: Window cannot be initialized!\n", init_game);
	}
	ft_init_sprite(init_game);
	init_game->mlx_window = mlx_new_window(init_game->mlx_ptr, \
	init_game->map.columns * 64, init_game->map.rows * 64, "so_long");
	if (!init_game->mlx_window)
	{
		free(init_game->mlx_ptr);
		ft_handle_error("Error: Window cannot be initialized!\n", init_game);
	}
}