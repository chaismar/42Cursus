/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:18:55 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/22 12:04:27 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_case(t_data *data, int i, int j)
{
	if (i == 0 && j == 0)
		return ;
	else if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall_img, j * 64, i * 64);
	else if (data->map.map[i][j] == '2')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->inside_wall_img, j * 64, i * 64);
	else if (data->map.map[i][j] == 'X' || data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->background_img, j * 64, i * 64);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->background_img, j * 64, i * 64);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit_img, j * 64, i * 64);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collectible_img, j * 64, i * 64);
}

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			print_case(data, i, j);
			j++;
		}
		i++;
	}
	return ;
}

int	print_collectibles(t_data *data)
{
	t_collect	*first;

	first = data->map.collectible;
	while (data->map.collectible->next != NULL)
	{
		if (data->map.collectible->is_collected == 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->collectible_img,
				data->map.collectible->pos.x * 64,
				data->map.collectible->pos.y * 64);
		data->map.collectible = data->map.collectible->next;
	}
	if (data->map.collectible->is_collected == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collectible_img,
			data->map.collectible->pos.x * 64,
			data->map.collectible->pos.y * 64);
	data->map.collectible = first;
	return (0);
}

int	print_enemie(t_data *data)
{
	t_enemies	*first;

	first = data->map.enemies;
	while (data->map.enemies->next != NULL)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->enemie_img,
			data->map.enemies->pos.x * 64, data->map.enemies->pos.y * 64);
		data->map.enemies = data->map.enemies->next;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->enemie_img,
		data->map.enemies->pos.x * 64, data->map.enemies->pos.y * 64);
	data->map.enemies = first;
	return (0);
}

int	print_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img,
		data->player.x * 64, data->player.y * 64);
	return (0);
}
