#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <mlx.h>

// Usage of IMG width and height???
# define IMG_WIDTH	32
# define IMG_HEIGHT	32

# define KEY_D		100
# define KEY_S		115
# define KEY_A		97
# define KEY_W		119
# define KEY_ESC	65307

typedef struct	s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct	s_graphic
{
	void	*wall;
	void	*floor;
	void	*collectibles;
	void	*closed_exit;
	void	*player_front;
	void	*open_exit;
	int		img_width;
	int		img_height;
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
	char	**grid
}				t_map;

typedef struct	s_game_instance
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_map		map;
	t_map_items	count;
	t_graphic	graphic;
	t_player	player
}				t_game;

#endif
