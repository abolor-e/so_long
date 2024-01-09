/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:59:02 by abolor-e          #+#    #+#             */
/*   Updated: 2024/01/09 18:05:09 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	*init_game;

	init_game = malloc(sizeof(t_game));
	if (!init_game)
		return (0);
	init_game->game_alloc = 0;
	if (ac < 2 || ac > 2)
		ft_handle_error("Error: Too low or high amount of parameters!\n", 
			init_game);
	else
	{
		if (ft_check_map_validity(av) == 0)
			ft_handle_error("Error: Map extension wrong <map.berg>!\n", 
				init_game);
		ft_init_map(av[1], init_game);
		ft_map_check(init_game);
		ft_init_window(init_game);
		ft_recognize_mapsprite(init_game);
		mlx_hook(init_game->mlx_window, KEY_RELEASE,
			KEY_RELEASE_MASK, ft_check_key, init_game);
		mlx_hook(init_game->mlx_window, DESTROY_NOTIFY, 
			NO_EVENT_MASK, ft_quit_game, init_game);
		mlx_hook(init_game->mlx_window, EXPOSE, 
			EXPOSURE_MASK, ft_recognize_mapsprite, init_game);
		mlx_loop(init_game->mlx_ptr);
		system("leaks so_long");
		ft_free_allocated_memory(init_game);
		return (0);
	}
}
