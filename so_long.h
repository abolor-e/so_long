#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "./minilibx/mlx.h"
# include "libft/libft.h"


# define IMG_WIDTH	32
# define IMG_HEIGHT	32

# define KEY_D		2
# define KEY_S		1
# define KEY_A		0
# define KEY_W		13
# define KEY_ESC	65307

# define KEY_RELEASE		2
# define KEY_RELEASE_MASK	0
# define DESTROY_NOTIFY		17
# define NO_EVENT_MASK		0
# define EXPOSE				12
# define EXPOSURE_MASK		32768

# define FAILURE	-1
# define SUCCESS	0

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
	char	**grid;
}				t_map;

typedef struct	s_game_instance
{
	void		*mlx_ptr;
	void		*mlx_window;
	int			game_alloc;
	t_map		map;
	t_map_items	count;
	t_graphic	graphic;
	t_player	player;
}				t_game;

int	ft_check_map_validity(char **av);
void	ft_init_map(char *av, t_game *init_game);
char	*ft_add_gnlmap(char **line_tmp, char *next_line);
void	ft_check_newline(char *line_tmp, t_game *init_game);

//char	*ft_strappend(char **s1, const char *s2);
//void	ft_check_for_empty_line(char *map, t_game *game);
//void	ft_init_map(char *av, t_game *game);


void	ft_init_count(t_game *init_game);

void	ft_map_check(t_game *init_game);
void	ft_check_row_columns(t_game *init_game);
void	ft_check_items(t_game *init_game);
void	ft_item_number(t_game *init_game);

//void	ft_check_rows(t_game *init_game);
//void	ft_check_columns(t_game *init_game);
//void	ft_count_map_parameters(t_game *init_game);
//void	ft_verify_map_parameters(t_game *init_game);

void	ft_init_window(t_game *init_game);
void	ft_init_sprite(t_game *init_game);
void	ft_to_image(t_game *init_game, void **image, char *location);
int		ft_recognize_mapsprite(t_game *init_game);
void	ft_sprite(t_game *init_game, int y, int x);
void	ft_render(t_game *init_game, void *image, int x, int y);
int		ft_check_key(int key, t_game *init_game);
void	ft_player_movement(t_game *init_game, int y, int x);
int		ft_handle_error(char *str, t_game *init_game);
void	ft_grid_free(t_game *init_game);
int		ft_quit_game(t_game *init_game);
void	ft_free_allocated_memory(t_game *init_game);
void	ft_destroy_images(t_game *init_game);
int		ft_win(t_game *init_game);
#endif