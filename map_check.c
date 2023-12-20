#include "so_long.h"

void    ft_map_check(t_game *init_game)
{
    ft_check_row_column(init_game);
    if (init_game->map.rows == init_game->map.columns)
        //ft_error("");
    ft_check_items(init_game);
    ft_item_number(init_game);
}

// Checking if there are walls surrounding the first and last rows and columns!
void    ft_check_row_column(t_game *init_game)
{
    int i;

    i = 0;
    while (i < init_game->map.rows)
    {
        if (init_game->map.grid[i][0] != '1')
            //ft_error("Error: Map should be surrounded by walls");
        else if (init_game->map.grid[i][init_game->map.columns - 1] != '1')
            //ft_error("");
        i++;
    }
    i = 0;
    while (i < init_game->map.columns)
    {
        if (init_game->map.grid[0][i] != '1')
            //ft_error("");
        else if (init_game->map.grid[init_game->map.rows - 1] != '1')
            //ft_error("");
        i++;
    }
}

void    ft_check_items(t_game *init_game)
{
    int i;
    int a;

    i = 0;
    while (i++ < init_game->map.rows)
    {
        a = 0;
        while (a++ < init_game->map.columns)
        {
            if (init_game->map.grid[i][a] == 'C')
                init_game->count.collectibles++;
            else if (init_game->map.grid[i][a] == 'P')
            {
                init_game->count.player++;
                init_game->player.x = a;
                init_game->player.y = i;
            }
            else if (init_game->map.grid[i][a] == 'E')
                init_game->count.exit++;
            else if (init_game->map.grid[i][a] == '1')
                init_game->count.wall++;
            else if (init_game->map.grid[i][a] == '0')
                init_game->count.floor++;
            else
                //ft_error("Error: Unrecognized character!")
        }
    }
}

// Checks if there are correct numbers of items in the map!
void    ft_item_number(t_game *init_game)
{
    if (init_game->count.exit != 1)
        ft_error("");
    else if (init_game->count.player != 1)
        ft_error("");
    else if (init_game->count.collectibles < 1)
        ft_error("");
}