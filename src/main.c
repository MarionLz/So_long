#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_data_win *win;
	t_data_map *map;
	t_data_map *img;

	win = (t_data_win *)malloc(sizeof(t_data_win));
	map = (t_data_map *)malloc(sizeof(t_data_map));
	img = (t_data_map *)malloc(sizeof(t_data_map));
	check_map(argc, argv, map);
	print_map(map, win);
	mlx_loop(win->mlx);
	free(map);
	free(win);
}

/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img_ptr;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Background");
	img_ptr = mlx_xpm_file_to_image(mlx, "soil.xpm", &img_width, &img_height);
	if (img_ptr == NULL)
	{
		printf("error");
		exit(EXIT_FAILURE);
	}
	y = 0;
	while (y <= 1080 / img_height)
	{
		x = 0;
		while (x <= 1920 / img_width)
		{
			mlx_put_image_to_window(mlx, mlx_win, img_ptr, x * img_width, y * img_height);
			x++;
		}
		y++;
	}
	
	//mlx_put_image_to_window(mlx, mlx_win, img_ptr, 0, 0);
	//mlx_put_image_to_window(mlx, mlx_win, img_ptr, 0, img_height);
	mlx_loop(mlx);
	return (0);
}*/

//img.img = mlx_new_image(mlx, 1920, 1080);
//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//							&img.endian);
//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);*/