/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:24:00 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/24 15:31:53 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	set_inside_wall(t_map map)
{
	int	x;
	int	y;

	x = 1;
	while (x < map.height - 1)
	{
		y = 1;
		while (y < map.width - 1)
		{
			if (map.map[x][y] == '1')
				map.map[x][y] = '2';
			y++;
		}
		x++;
	}
	return (map);
}

t_map	set_starting_pos(t_map map)
{
	t_collect	*list;

	list = map.collectible;
	map.map[map.start.y][map.start.x] = 'P';
	map.map[map.exit.y][map.exit.x] = 'E';
	while (map.collectible->next != NULL)
	{
		map.map[map.collectible->pos.y][map.collectible->pos.x] = 'C';
		map.collectible = map.collectible->next;
	}
	map.map[map.collectible->pos.y][map.collectible->pos.x] = 'C';
	map.collectible = map.collectible->next;
	map.collectible = list;
	map = set_inside_wall(map);
	return (map);
}

void	init_data_img(t_data *data)
{
	int	size;

	size = 64;
	data->background_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/floor.xpm", &size, &size);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/down_walk/4_floor.xpm", &size, &size);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/machine.xpm", &size, &size);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/collectible.xpm", &size, &size);
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/wall.xpm", &size, &size);
	data->inside_wall_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/inside_wall4.xpm", &size, &size);
	data->enemie_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/cat/norminet.xpm", &size, &size);
	if (!data->background_img || !data->player_img || !data->exit_img
		|| !data->collectible_img || !data->wall_img || !data->inside_wall_img
		|| !data->enemie_img)
		exit_game(data);
}

void	init_imgs_null(t_data *data)
{
	data->background_img = NULL;
	data->player_img = NULL;
	data->collectible_img = NULL;
	data->wall_img = NULL;
	data->inside_wall_img = NULL;
	data->enemie_img = NULL;
	data->list_down = NULL;
	data->list_up = NULL;
	data->list_right = NULL;
	data->list_left = NULL;
	data->exit_img = NULL;
	data->img.mlx_img = NULL;
	data->img.addr = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img.addr = NULL;
	data->moove = 0;
}

void	init_data(t_data *data, t_map map)
{
	data->map = map;
	data->player.x = map.start.x;
	data->player.y = map.start.y;
	data->moove_set.x = 0;
	data->moove_set.y = 0;
	data->frame = 1;
	data->last_key_up_timer = 0;
	data->last_key_down_timer = 0;
	data->last_key_right_timer = 0;
	data->last_key_left_timer = 0;
	init_imgs_null(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		alloc_error_free(data->map);
	init_data_img(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, map.width * 64,
			map.height * 64, "my window");
	if (data->win_ptr == NULL)
		exit_game(data);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr,
			map.width * 64, map.height * 64);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!data->img.mlx_img || !data->img.addr)
		exit_game(data);
}
