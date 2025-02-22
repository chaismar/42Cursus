/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:14:28 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/22 10:15:30 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_next_pos(t_data *data)
{
	t_enemies	*first;

	first = data->map.enemies;
	while (data->map.enemies->next != NULL)
	{
		data->map.enemies->next_pos = bfs(data, *data->map.enemies);
		data->map.enemies = data->map.enemies->next;
	}
	data->map.enemies->next_pos = bfs(data, *data->map.enemies);
	data->map.enemies = first;
}

int	check_other_enemies(t_enemies *list, t_enemies *enemies)
{
	t_enemies	*first;

	first = list;
	while (list->next != NULL)
	{
		if (enemies->next_pos.x == list->pos.x
			&& enemies->next_pos.y == list->pos.y)
			return (1);
			list = list->next;
	}
	if (enemies->next_pos.x == list->pos.x
		&& enemies->next_pos.y == list->pos.y)
		return (1);
	list = first;
	return (0);
}

void	print_background(t_data *data, t_pos pos)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->background_img, pos.x * 64, pos.y * 64);
}

t_data	*move_enemie(t_data *data)
{
	t_enemies	*first;

	first = data->map.enemies;
	while (data->map.enemies->next != NULL)
	{
		if (check_other_enemies(first, data->map.enemies) != 1)
		{
			print_background(data, (t_pos){data->map.enemies->pos.x,
				data->map.enemies->pos.y});
			data->map.enemies->pos = data->map.enemies->next_pos;
		}
		data->map.enemies = data->map.enemies->next;
	}
	if (check_other_enemies(first, data->map.enemies) != 1)
	{
		print_background(data, (t_pos){data->map.enemies->pos.x,
			data->map.enemies->pos.y});
		data->map.enemies->pos = data->map.enemies->next_pos;
	}
	data->map.enemies = first;
	print_enemie(data);
	return (data);
}

t_map	add_enemies(t_map map, int x, int y)
{
	t_enemies	*new;
	t_enemies	*list;

	new = malloc(sizeof(t_enemies));
	if (!new)
		alloc_error_free(map);
	new->pos.x = x;
	new->pos.y = y;
	new->next = NULL;
	new->next_pos.x = 0;
	new->next_pos.x = 0;
	if (map.enemies == NULL)
	{
		map.enemies = new;
		return (map);
	}
	list = map.enemies;
	while (list->next != NULL)
		list = list->next;
	list->next = new;
	return (map);
}
