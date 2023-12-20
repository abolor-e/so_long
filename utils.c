#include "so_long.h"

void    ft_grid_free(t_game *init_game)
{
    int i;

    i = 0;
    while (i < init_game->map.rows)
    {
        free(init_game->map.grid[i]);
        i++;
    }
    free(init_game->map.grid);
}

int ft_error(char *str, t_game *init_game)
{
    if (init_game->game_alloc == 1)
        ft_grid_free(init_game);
    free(init_game);
    ft_printf("%s", str);
    exit (FAILURE);
}

void	ft_init_count(t_game *init_game)
{
	ft_memset(&init_game->count, 0, sizeof(t_map_items));
	init_game->map.columns = ft_strlen(init_game->map.grid[0]) - 1;
	// Do we need to start the player?
}

void    ft_free_allocated_memory(t_game *init_game)
{
    
}

int ft_quit_game(t_game *init_game)
{
    ft_free_allocated_memory(init_game);
    exit (FAILURE);
}
