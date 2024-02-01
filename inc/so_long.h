# ifndef SO_LONG_H

#define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/get_next_line.h"


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_data_map
{
	char	**map_tab;
	char	*map_str;
	int		nb_pos;
	int		nb_exit;
	int		nb_collectible;
	int		nb_row;
	int		nb_colomn;
	int		wall;
}	t_data_map;

typedef struct	s_data_img
{
	void	*img_wall;      		/* pointer qui permet d'identifier l'image */
	char	*wall_str;  		/* string contenant tous les pixels de l'image */
	int		bits;      		/* nombre de bits par pixels */
	int		size_line; 		/*  taille de la img_str*/
	int		endian;    		/* permet de signifier la fin d'une image*/
}	t_data_img;

typedef struct s_data_win
{
	void		*mlx;
	void		*mlx_win;
	t_data_img	*img;
	int			width;
	int			height;
}	t_data_win;

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;*/

/*-----------------------check_map.c--------------------------*/
bool    check_file_extension(char *argv1);
void    print_error_and_exit(char *error_msg);
void    check_map(int argc, char **argv, t_data_map *map);

/*-----------------------print_map.c--------------------------*/
void    print_map(t_data_map *map, t_data_win *win);

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

# endif