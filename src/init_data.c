/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:12:08 by maax              #+#    #+#             */
/*   Updated: 2024/02/13 13:24:54 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_init_map_data(t_data *data)
{
    data->nb_pos = 0;
    data->nb_exit = 0;
    data->nb_collect = 0;
    data->nb_row = 0;
    data->nb_colomn = 0;
}

void    ft_init_player(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == 'P')
            {
                data->player.x = x;
                data->player.y = y;
            }
            if (data->map[y][x] == 'E')
            {
                data->player.x_exit = x;
                data->player.y_exit = y;
            }
            x++;
        }
        y++;
    }
    data->player.nb_moves = 0;
    data->player.score = 0;
    data->player.direction = 'L';
}

void    ft_init_window(t_data *data)
{
    data->height = data->nb_row * IMG_HEIGHT;
    data->width = data->nb_colomn * IMG_WIDTH;
    data->mlx = mlx_init();
    if (!data->mlx)
        return ;
    data->win = mlx_new_window(data->mlx, data->width, data->height, "WELCOME TO HAZELRUN !");
    if (!data->win)
    {
        free(data->mlx);
        return ;
    }
}

void    ft_init_img(t_data *data)
{
    data->img.height = IMG_HEIGHT;
    data->img.width = IMG_WIDTH;
    data->img.img_wall = mlx_xpm_file_to_image(data->mlx, "./assets/img/wall.xpm", &(data->img.width), &(data->img.height));
    data->img.img_floor = mlx_xpm_file_to_image(data->mlx, "./assets/img/floor.xpm", &(data->img.width), &(data->img.height));
    data->img.img_collect = mlx_xpm_file_to_image(data->mlx, "./assets/img/collectible.xpm", &(data->img.width), &(data->img.height));
    data->img.img_player_l = mlx_xpm_file_to_image(data->mlx, "./assets/img/player_l.xpm", &(data->img.width), &(data->img.height));
    data->img.img_player_lc = mlx_xpm_file_to_image(data->mlx, "./assets/img/player_lc.xpm", &(data->img.width), &(data->img.height));
    data->img.img_player_r = mlx_xpm_file_to_image(data->mlx, "./assets/img/player_r.xpm", &(data->img.width), &(data->img.height));
    data->img.img_player_rc = mlx_xpm_file_to_image(data->mlx, "./assets/img/player_rc.xpm", &(data->img.width), &(data->img.height));
    data->img.img_exit_op = mlx_xpm_file_to_image(data->mlx, "./assets/img/exit_op.xpm", &(data->img.width), &(data->img.height));
    data->img.img_exit_cl = mlx_xpm_file_to_image(data->mlx, "./assets/img/exit_cl.xpm", &(data->img.width), &(data->img.height));    
    data->img.img_end = mlx_xpm_file_to_image(data->mlx, "./assets/img/end.xpm", &(data->img.width_end), &(data->img.height_end));
}
