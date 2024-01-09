/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:29:54 by abolor-e          #+#    #+#             */
/*   Updated: 2024/01/09 18:37:09 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../minilibx/mlx.h"

void	ft_grid_free(t_game *init_game)
{
	int	i;

	i = 0;
	while (i < init_game->map.rows)
	{
		free(init_game->map.grid[i]);
		i++;
	}
	free(init_game->map.grid);
}

int	ft_handle_error(char *str, t_game *init_game)
{
	if (init_game->game_alloc == 1)
		ft_grid_free(init_game);
	free(init_game);
	ft_printf("%s", str);
	exit (FAILURE);
}

void	ft_destroy_images(t_game *init_game)
{
	mlx_destroy_image(init_game->mlx_ptr, init_game->graphic.closed_exit);
	mlx_destroy_image(init_game->mlx_ptr, init_game->graphic.collectibles);
	mlx_destroy_image(init_game->mlx_ptr, init_game->graphic.player_front);
	mlx_destroy_image(init_game->mlx_ptr, init_game->graphic.wall);
	mlx_destroy_image(init_game->mlx_ptr, init_game->graphic.floor);
	mlx_destroy_image(init_game->mlx_ptr, init_game->graphic.open_exit);
}

void	ft_free_allocated_memory(t_game *init_game)
{
	ft_destroy_images(init_game);
	ft_grid_free(init_game);
	mlx_clear_window(init_game->mlx_ptr, init_game->mlx_window);
	mlx_destroy_window(init_game->mlx_ptr, init_game->mlx_window);
	free(init_game->mlx_ptr);
	free(init_game); 
}

int	ft_quit_game(t_game *init_game)
{
	ft_free_allocated_memory(init_game);
	exit (FAILURE);
}
