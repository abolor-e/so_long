#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>

// Usage of IMG width and height???
# define IMG_WIDTH	32
# define IMG_HEIGHT	32

typedef struct	s_graphic
{
	void	wall;
	void	floor;
	void	collectible;
	//void	open_exit;
	void	closed_exit;
	//void	player_left;
	//void	player_right;
	void	player_front;
	//void	player_back;
}				t_graphic;

typedef struct	s_map_items
{
	int	exit;
	int	player;
	int	collectibles;
	int	wall;
	int	floor;
	int	movements;
}				t_map_items;

typedef struct	s_map
{
	int		rows;
	int		columns;
	char	**filled;
	
}				t_map;

typedef struct	s_game_instance
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_map		map;
	t_map_items	count;
	t_graphic	graphic;
}				t_game;

#endif
