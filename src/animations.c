/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:45:26 by maax              #+#    #+#             */
/*   Updated: 2024/02/09 18:31:00 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_print_end(t_data *data)
{
    int x;
    int y;

    x = (data->width / 2) - (data->img.width_end / 2);
    y = (data->height / 2) - (data->img.height_end / 2);
    mlx_put_image_to_window(data->mlx, data->win, data->img.img_end, x, y);
}

void    ft_handle_exit(t_data *data, int x, int y)
{
    if (data->player.score == data->nb_collect)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->img.img_floor, data->player.x * IMG_WIDTH, data->player.y * IMG_HEIGHT);
        data->player.x += x;
        data->player.y += y;
        mlx_put_image_to_window(data->mlx, data->win, data->img.img_exit_cl, data->player.x * IMG_WIDTH, data->player.y * IMG_HEIGHT);
        ft_print_end(data);
        data->player.nb_moves += 1;
        ft_printf("Congratulations !\nYou finished Hazelrun in only %d moves.\n", data->player.nb_moves);
    }
    else
        ft_printf("Warning, missing hazelnuts !\n");
}

void    ft_move_player(t_data *data, int x, int y)
{
    if (data->map[data->player.y + y][data->player.x + x] == 'E')
        ft_handle_exit(data, x, y);
    else if (data->map[data->player.y + y][data->player.x + x] != '1' && data->map[data->player.y + y][data->player.x + x] != 'E' && data->map[data->player.y][data->player.x] != 'E')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->img.img_floor, data->player.x * IMG_WIDTH, data->player.y * IMG_HEIGHT);
        data->player.x += x;
        data->player.y += y;
        if (data->map[data->player.y][data->player.x] == 'C' || data->player.score != 0)
        {
            if (data->player.direction == 'L')
                mlx_put_image_to_window(data->mlx, data->win, data->img.img_player_lc, data->player.x * IMG_WIDTH, data->player.y * IMG_HEIGHT);
            else
                mlx_put_image_to_window(data->mlx, data->win, data->img.img_player_rc, data->player.x * IMG_WIDTH, data->player.y * IMG_HEIGHT);
            if (data->map[data->player.y][data->player.x] == 'C')
            {
                data->player.score += 1;
                data->map[data->player.y][data->player.x] = '0';
                if (data->player.score ==  data->nb_collect)
                    mlx_put_image_to_window(data->mlx, data->win, data->img.img_exit_op, data->player.x_exit * IMG_WIDTH, data->player.y_exit * IMG_HEIGHT);     
            }
        }
        else if (data->player.direction == 'L')
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_player_l, data->player.x * IMG_WIDTH, data->player.y * IMG_HEIGHT);
        else
            mlx_put_image_to_window(data->mlx, data->win, data->img.img_player_r, data->player.x * IMG_WIDTH, data->player.y * IMG_HEIGHT);
        data->player.nb_moves += 1;
        ft_printf("Moves = %d\n", data->player.nb_moves);
    }
}

