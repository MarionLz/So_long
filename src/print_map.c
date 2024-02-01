#include "../inc/so_long.h"

void    init_window(t_data_win *win)
{
    win->height = 1080;
    win->width = 1920;
    win->mlx = mlx_init();
    win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, "So_long");
}

void    size_map_cell(t_data_map *map, t_data_win *win)
{
    int         img_width;
    int         img_height;
    int         x;
    int         y;
    void *img;
    int bpp;
    int size_line;
    int endian;

    map->nb_row = 8;
    map->nb_colomn = 15;
    img = mlx_xpm_file_to_image(win->mlx, "tree.xpm", &img_width, &img_height);
    if (img == NULL)
        print_error_and_exit("Error, image reading has failed.");
    img_height = win->height / map->nb_row;
    img_width = win->width / map->nb_colomn;
    
    void *resized_img_ptr = mlx_new_image(win->mlx, img_width, img_height);
    char *img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
    //win->img_ptr = mlx_new_image(win->mlx, img_width, img_height);
    mlx_put_image_to_window(win->mlx, win->mlx_win, resized_img_ptr, 0, 0);

    /*y = 0;
	while (y <= map->nb_row)
	{
		x = 0;
		while (x <= map->nb_colomn)
		{
			mlx_put_image_to_window(win->mlx, win->mlx_win, win->img_ptr, x * img_width, y * img_height);
			x++;
		}
		y++;
	}*/
}

void    print_map(t_data_map *map, t_data_win *win)
{
    init_window(win);
    size_map_cell(map, win);    
}