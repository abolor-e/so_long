/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <abolor-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:59:02 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/20 16:23:07 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*init_game;

	init_game = malloc(sizeof(t_game));
	if (init_game == NULL)
		ft_printf("Error: Memory allocation for t_game failed!\n");
	if (ac < 2 || ac > 2)
	{
		ft_printf("Error: Check argument numbers <./so_long map.ber>\n");
		return (1);
	}
	else
	{
		if (ft_check_map_validity(av) == 0)
		{
			ft_printf("Error: Map extension wrong <map.berg>!\n");
			return (1);
		}
		ft_init_map(av[1], init_game);
		ft_map_check(init_game);
		ft_init_window(init_game);
		ft_recognize_mapsprite(init_game);
		mlx_hook(init_game->mlx_window, Keypress, KeyPressMask, ft_check_key, init_game);
		mlx_hook(init_game->mlx_window, DestroyNotify, ButtonPressMask, /*ft_...*/, init_game);
		mlx_hook(init_game->mlx_window, Expose, Exposuremask, ft_recognize_mapsprite, init_game);
		mlx_loop(init_game->mlx_ptr);
		/* free function*/
	}
}
