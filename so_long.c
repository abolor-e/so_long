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
		if (ft_check_map_argument(av) == 0)
		{
			ft_printf("Error: Map extension wrong <map.berg>!\n");
			return (1);
		}
		init_map(av[1], init_game);
		
		
	
	
}
