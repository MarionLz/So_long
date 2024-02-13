/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maax <maax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:32:47 by maax              #+#    #+#             */
/*   Updated: 2024/02/13 13:26:15 by maax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_free_map(char **map_tab)
{
    int i;

    i = 0;
    while (map_tab[i])
    {
        free(map_tab[i]);
        i++;
    }
    free(map_tab);
}

void    ft_error(char *error_msg)
{
    ft_printf("%s", error_msg);
    exit (EXIT_FAILURE);
}

void    ft_error_map(t_data *data, char *error_msg)
{
    ft_free_map(data->map);
    ft_printf("%s", error_msg);
    exit (EXIT_FAILURE);   
}

int    ft_close_win(t_data *data)
{
    ft_free_map(data->map);
    mlx_destroy_image(data->mlx, data->img.img_collect);
    mlx_destroy_image(data->mlx, data->img.img_end);
    mlx_destroy_image(data->mlx, data->img.img_exit_op);
    mlx_destroy_image(data->mlx, data->img.img_exit_cl);
    mlx_destroy_image(data->mlx, data->img.img_floor);
    mlx_destroy_image(data->mlx, data->img.img_player_l);
    mlx_destroy_image(data->mlx, data->img.img_player_lc);
    mlx_destroy_image(data->mlx, data->img.img_player_r);
    mlx_destroy_image(data->mlx, data->img.img_player_rc);
    mlx_destroy_image(data->mlx, data->img.img_wall);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit (EXIT_SUCCESS);
    return (0);
}