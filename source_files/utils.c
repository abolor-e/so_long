/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:58:14 by abolor-e          #+#    #+#             */
/*   Updated: 2024/01/09 18:01:12 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_count(t_game *init_game)
{
	ft_memset(&init_game->count, 0, sizeof(t_map_items));
	init_game->map.columns = ft_strlen(init_game->map.grid[0]);
}

int	ft_win(t_game *init_game)
{
	ft_free_allocated_memory(init_game);
	ft_printf("win");
	exit (EXIT_FAILURE);
}
