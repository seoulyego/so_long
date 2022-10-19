/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:41:37 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/19 11:20:25 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FILE_EXT ".ber"
# define P_NAME "so_long"

# define MAX_WINDOW_WIDTH 2560
# define MAX_WINDOW_HEIGHT 1344

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_WIN_EXIT 17

typedef struct s_exit		t_exit;
typedef struct s_img		t_img;
typedef struct s_component	t_component;
typedef struct s_map		t_map;
typedef struct s_vector		t_vector;
typedef struct s_player		t_player;
typedef struct s_baram		t_baram;

struct s_img
{
	void	*empty;
	void	*wall;
	void	*collect;
	void	*exit;
};

struct s_component
{
	int	collectible;
	int	exit;
	int	player;
};

struct s_map
{
	char		*path;
	char		**board;
	int			width;
	int			height;
	t_component	component;
};

struct s_vector
{
	int	vector_y;
	int	vector_x;
};

struct s_player
{
	int			x;
	int			y;
	t_vector	preset[5];
	int			movement;
	void		*img;
};

struct s_baram
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_img		img;
	t_player	player;
};

enum e_keys
{
	PRESS_W = 13,
	PRESS_A = 0,
	PRESS_S = 1,
	PRESS_D = 2,
	PRESS_ESC = 53,
	PRESS_UP = 126,
	PRESS_DOWN = 125,
	PRESS_LEFT = 123,
	PRESS_RIGHT = 124
};

enum e_component
{
	EMPTY = '0',
	WALL = '1',
	COLLECT = 'C',
	EXIT = 'E',
	PLAYER = 'P'
};

enum e_direction
{
	NONE = 0,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};

/*            terminate.c             */
void	exit_with_error_message(char *str);
void	exit_with_perror(char *str);
int		exit_success(t_baram *baram);

/*            movement.c              */
int		press_key(int key_code, t_baram *baram);
void	display_movement_count(t_baram *baram);

/*            init.c                  */
void	init_baram(t_baram *baram, char *map_path);
void	init_img_ptr(t_baram *baram);
void	init_window(t_baram *baram);

/*            ft_mlx.c                */
void	ft_mlx_init(void **mlx_ptr);
void	ft_new_window(void *mlx_ptr, void **window, int size_x, int size_y);
void	ft_xpm_to_image(void *mlx_ptr, void **img_ptr, char *img_path);

/*            parse_util.c            */
int		check_map_name(char *map_path);
int		get_width(int fd);
void	count_component(int map_y, int map_x, t_player *player, t_map *map);

/*            parse.c                 */
int		parse_map(t_baram *baram);

/*            render_component.c      */
void	render_map(t_baram *baram, int y, int x);
void	render_player(t_baram *baram);

/*            render.c                */
int		render_game(t_baram *baram);

#endif
