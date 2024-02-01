#include "../inc/so_long.h"

#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

void    check_arg(int argc, char **argv)
{
    if (argc == 1)
        print_error_and_exit("Error, please add a map as an argument.\n");
    if (argc > 2)
        print_error_and_exit("Error, too many arguments.\n");
    if (!check_file_extension(argv[1]))
        print_error_and_exit("Error, file extension is incorrect, try with .ber.\n");
}

bool    check_file_extension(char *argv1)
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

void    print_error_and_exit(char *error_msg)
{
    ft_printf("%s", error_msg);
    exit (EXIT_FAILURE);
}

void    read_map(char **argv, t_data_map *map)
{
    int     fd;
    char    *line;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        print_error_and_exit("Error, problem reading the file.");
    map->map_str = ft_strdup("");
    while (1)
	{
		line = get_next_line(fd);
        if (!line)
			break;
        map->map_str = ft_strjoin(map->map_str, line);
        free(line);
	}
   	close(fd);
}

/*void    free_tab(t_data_map *map)
{

}

void    read_map_cell(t_data_map *map, char c)
{
    if (c == 'P')
        map->nb_pos += 1;
    else if (c == 'E')
        map->nb_exit += 1;
    else if (c == 'C')
        map->nb_collectible += 1;
    else if (c != 0 && c != 1)
    {
        free_tab();
        print_error_and_exit("Error, wrong character in the map.");
    }
}

void    check_map_content(t_data_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map->map_tab[i])
    {
        while (map->map_tab[i][j])
        {
            read_map_cell(map, map->map_tab[i][j]);
        }
    }
}*/

void    split_map(t_data_map *map)
{
    int i;
    i = 0;
    map->map_tab = ft_split(map->map_str, '\n');
    while (i < 8)
	{
		ft_printf("%s\n", map->map_tab[i]);
		i++;
	}
    free(map->map_str);
}

void    check_map(int argc, char **argv, t_data_map *map)
{
    check_arg(argc, argv);
    read_map(argv, map);
    split_map(map);
    //check_map_content(map);
}
