#include "../inc/so_long.h"

bool    ft_check_file_extension(char *argv1)
{
    int     i;
    int     j;
    char    *extension;

    i = 0;
    j = 0;
    extension = ".ber";
    while (argv1[i + 4] != '\0')
        i++;
    while (argv1[i] == extension[j])
    {
        i++;
        j++;
    }
    if (j != 5)
        return (0);
    return (1);
}

/*keycode :
113 = left A
100 = right D
122 = top W
115 = bottom S*/

int	ft_key_hook(int keycode, t_data *data)
{
    if (keycode == 113)
    {
        data->player.direction = 'L';
        ft_move_player(data, -1, 0);
    }
    if (keycode == 100)
    {
        data->player.direction = 'R';
        ft_move_player(data, 1, 0);
    }
    if (keycode == 122)
        ft_move_player(data, 0, -1);
    if (keycode == 115)
        ft_move_player(data, 0, 1);
    if (keycode == 65307)
        ft_close_win(data);
    return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 1)
        ft_error("Error, please add a map as an argument.\n");
    else if (argc > 2)
        ft_error("Error, too many arguments.\n");
    if (!ft_check_file_extension(argv[1]))
    {
        ft_error("Error, incorrect file extension, try with .ber.\n");
    }
    ft_check_map(argv, &data);
	ft_print_map(&data);
    mlx_key_hook(data.win, &ft_key_hook, &data);
	mlx_hook(data.win, 17, 0, &ft_close_win, &data);
	mlx_loop(data.mlx);
}
