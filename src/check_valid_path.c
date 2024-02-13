/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:42:32 by maax              #+#    #+#             */
/*   Updated: 2024/02/13 14:07:43 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char    **ft_copy_map_tab(t_data *data)
{
    int     x;
    int     y;
    char    **map_copy;

    y = 0;
    map_copy = ft_calloc(data->nb_row + 1, sizeof(char *));
    if (!map_copy)
        return (NULL);
    while (data->map[y])
    {
        x = 0;
        map_copy[y] = ft_calloc(data->nb_colomn + 1, sizeof(char));
        if (!map_copy[y])
            return (NULL);
        while (data->map[y][x])
        {
            map_copy[y][x] = data->map[y][x];
            x++;
        }
        y++;
    }
    return (map_copy);
}

void    ft_flood_fill(char **map_copy, t_pos p, char flag)
{
    if (flag == 'C')
    {
        if (map_copy[p.y][p.x] == '1' || map_copy[p.y][p.x] == 'F' || map_copy[p.y][p.x] == 'E')
            return ;
    }
    else if (flag == 'E')
    {
        if (map_copy[p.y][p.x] == '1' || map_copy[p.y][p.x] == 'F')
            return ;
    }
    map_copy[p.y][p.x] = 'F';
    ft_flood_fill(map_copy, (t_pos){p.x + 1, p.y}, flag);
    ft_flood_fill(map_copy, (t_pos){p.x - 1, p.y}, flag);
    ft_flood_fill(map_copy, (t_pos){p.x, p.y + 1}, flag);
    ft_flood_fill(map_copy, (t_pos){p.x, p.y - 1}, flag);
}

void    ft_check_map_copy(t_data *data, char **map_copy, char **map_other, char flag)
{
    int x;
    int y;

    y = 0;
    while (map_copy[y])
    {
        x = 0;
        while (map_copy[y][x])
        {
            if ((flag == 'C' && map_copy[y][x] == 'C') || (flag == 'E' && map_copy[y][x] == 'E'))
            {
                ft_free_map(map_copy);
                ft_free_map(map_other);
                ft_error_map(data, "Error, invalid path in the map, exit and objects must be reachable.\n");
            }
            x++;
        }
        y++;
    }
}

void    ft_check_valid_path(t_data *data)
{
    t_pos   p1;
    t_pos   p2;
    char    **map_exit;
    char    **map_collect;

    p1.x = data->player.x;
    p1.y = data->player.y;
    p2.x = data->player.x;
    p2.y = data->player.y;
    map_exit = ft_copy_map_tab(data);
    map_collect = ft_copy_map_tab(data);
    ft_flood_fill(map_exit, p1, 'E');
    ft_flood_fill(map_collect, p2, 'C');
    ft_check_map_copy(data, map_exit, map_collect, 'E');
    ft_check_map_copy(data, map_collect, map_exit, 'C');
    ft_free_map(map_exit);
    ft_free_map(map_collect);
}
