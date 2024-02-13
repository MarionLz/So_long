# ifndef SO_LONG_H

#define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/get_next_line.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

#define IMG_WIDTH 64
#define IMG_HEIGHT 64

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_player
{
	int		x;
	int		y;
	int		score;
	int		nb_moves;
	int		x_exit;
	int		y_exit;
	char	direction;
}	t_player;

typedef struct	s_img
{
	int		height;
	int		width;
	int		height_end;
	int		width_end;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_player_l;
	void	*img_player_lc;
	void	*img_player_r;
	void	*img_player_rc;
	void	*img_exit_op;
	void	*img_exit_cl;
	void	*img_end;
	char	*path_wall;
	char	*path_floor;
	char	*path_collect;
	char	*path_player;
	char	*path_player_coll;
	char	*path_exit_op;
	char	*path_exit_cl;
	char	*path_end;

}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		**map;
	int			nb_pos;
	int			nb_exit;
	int			nb_collect;
	int			nb_row;
	int			nb_colomn;
	t_img		img;
	t_player	player;
}	t_data;

/*--------------------------main.c----------------------------*/
bool    ft_check_file_extension(char *argv1);
int		ft_key_hook(int keycode, t_data *data);

/*-----------------------check_map.c--------------------------*/
void	ft_read_map(char **argv, t_data *data);
bool    ft_check_valid_char(char c);
void    ft_check_content(t_data *data);
void    ft_check_format(t_data *data);
void    ft_check_map(char **argv, t_data *data);

/*--------------------check_valid_path.c----------------------*/
char    **ft_copy_map_tab(t_data *data);
void    ft_flood_fill_coll(char **map_copy, t_pos p, char flag);
void    ft_check_map_copy(t_data *data, char **map_copy, char **map_other, char flag);
void    ft_check_valid_path(t_data *data);

/*-----------------------init_data.c--------------------------*/
void    ft_init_map_data(t_data *data);
void    ft_init_player(t_data *data);
void    ft_init_window(t_data *data);
void    ft_init_img(t_data *data);

/*-----------------------print_map.c--------------------------*/
void    ft_print_img(t_data *data);
void    ft_print_map(t_data *data);

/*----------------------animations.c-------------------------*/
void    ft_handle_exit(t_data *data, int x, int y);
void    ft_move_player(t_data *data, int x, int y);

/*----------------------error_and_exit.c-------------------------*/
void    ft_free_map(char **map_tab);
void    ft_error(char *error_msg);
void	ft_error_map(t_data *data, char *error_msg);
int		ft_close_win(t_data *data);

# endif