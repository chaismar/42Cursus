/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:18:24 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/19 02:12:16 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_up(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->player_img);
	while (++i <= 3)
	{
		j = 0;
		data->player_img = data->list_up->img;
		data->moove_set.y -= 16;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->background_img, data->player.x * 64, data->player.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_img, data->player.x * 64 + data->moove_set.x,
			data->player.y * 64 + data->moove_set.y);
		mlx_do_sync(data->mlx_ptr);
		usleep(90000);
		data->list_up = data->list_up->next;
	}
	j = 64;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background_img,
		data->player.x * 64, data->player.y * 64);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/up_walk/4_floor.xpm", &j, &j);
}

void	movement_down(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->player_img);
	while (++i <= 3)
	{
		j = 0;
		data->player_img = data->list_down->img;
		data->moove_set.y += 16;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->background_img, data->player.x * 64, data->player.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_img, data->player.x * 64 + data->moove_set.x,
			data->player.y * 64 + data->moove_set.y);
		mlx_do_sync(data->mlx_ptr);
		usleep(90000);
		data->list_down = data->list_down->next;
	}
	j = 64;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background_img,
		data->player.x * 64, data->player.y * 64);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/down_walk/4_floor.xpm", &j, &j);
}

void	movement_right(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->player_img);
	while (++i <= 3)
	{
		j = 0;
		data->player_img = data->list_right->img;
		data->moove_set.x += 16;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->background_img, data->player.x * 64, data->player.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img,
			data->player.x * 64 + data->moove_set.x,
			data->player.y * 64 + data->moove_set.y);
		mlx_do_sync(data->mlx_ptr);
		usleep(90000);
		data->list_right = data->list_right->next;
	}
	j = 64;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background_img,
		data->player.x * 64, data->player.y * 64);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/right_walk/2_floor.xpm", &j, &j);
}

void	movement_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->player_img);
	while (++i <= 3)
	{
		j = 0;
		data->player_img = data->list_left->img;
		data->moove_set.x -= 16;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->background_img, data->player.x * 64, data->player.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_img, data->player.x * 64 + data->moove_set.x,
			data->player.y * 64 + data->moove_set.y);
		mlx_do_sync(data->mlx_ptr);
		usleep(90000);
		data->list_left = data->list_left->next;
	}
	j = 64;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background_img,
		data->player.x * 64, data->player.y * 64);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/left_walk/4_floor.xpm", &j, &j);
}
