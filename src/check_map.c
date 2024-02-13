/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:34:25 by maax              #+#    #+#             */
/*   Updated: 2024/02/13 11:29:55 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_read_map(char **argv, t_data *data)
{
    int     fd;
    char    *line;
    char    *map_str;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_error("Error, problem reading the file.");
    map_str = ft_strdup("");
    while (1)
	{
		line = get_next_line(fd);
        if (!line)
			break;
        map_str = ft_strjoin_and_free(map_str, line);
        free(line);
        data->nb_row ++;
	}
   	close(fd);
    data->map = ft_split(map_str, '\n');
    free(map_str);
}

bool    ft_check_valid_char(char c)
{
    if (c == 'P' || c == 'E' || c == 'C' || c == '0' || c == '1')
        return (1);
    return (0);
}

void    ft_check_content(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (!ft_check_valid_char(data->map[y][x]))
                ft_error_map(data, "Error, wrong character used in the map.\n");
            if ((x == 0 || x == data->nb_colomn - 1 || y == 0 || y == data->nb_row - 1) && data->map[y][x] != '1')
                ft_error_map(data, "Error, map should be surrounded by walls.\n");
            if (data->map[y][x] == 'P')
                data->nb_pos += 1;
            if (data->map[y][x] == 'E')
                data->nb_exit += 1;
            if (data->map[y][x] == 'C')
                data->nb_collect += 1;
            x++;
        }
        y++;
    }
    if (data->nb_pos != 1 || data->nb_exit != 1 || data->nb_collect == 0)
        ft_error_map(data, "Error, map need 1 P, 1 E and at least 1 C.\n");
}

void    ft_check_format(t_data *data)
{
    int     i;
    size_t  len_row;

    i = 0;
    len_row = ft_strlen(data->map[i]);
    while (data->map[i])
    {
        if (ft_strlen(data->map[i]) != len_row)
            ft_error_map(data, "Error, all rows must be the same lenght.\n");
        i++;
    }
    data->nb_colomn = len_row;
    if (data->nb_colomn == data->nb_row)
        ft_error_map(data, "Error, map should be rectangular.\n");
}

void    ft_check_map(char **argv, t_data *data)
{
    ft_init_map_data(data);
    ft_read_map(argv, data);
    ft_check_content(data);
    ft_check_format(data);
    ft_init_player(data);
    ft_check_valid_path(data);
}
