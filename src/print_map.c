/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:27:59 by maax              #+#    #+#             */
/*   Updated: 2024/02/09 18:10:19 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_print_img(t_data *data)
{
    int     x;
    int     y;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->img.img_wall, x * IMG_WIDTH, y * IMG_HEIGHT);
            if (data->map[y][x] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->img.img_floor, x * IMG_WIDTH, y * IMG_HEIGHT);
            if (data->map[y][x] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->img.img_player_l, x * IMG_WIDTH, y * IMG_HEIGHT);
            if (data->map[y][x] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->img.img_collect, x * IMG_WIDTH, y * IMG_HEIGHT);
            if (data->map[y][x] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->img.img_exit_cl, x * IMG_WIDTH, y * IMG_HEIGHT);
            x++;
        }
        y++;
    }
}

void    ft_print_map(t_data *data)
{
    ft_init_window(data);
    ft_init_img(data);
    ft_print_img(data);
}