/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:12:45 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/22 10:27:37 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_enemi_end(t_data *data)
{
	t_enemies	*first;

	first = data->map.enemies;
	while (data->map.enemies->next != NULL)
	{
		if (data->player.x == data->map.enemies->pos.x
			&& data->player.y == data->map.enemies->pos.y)
		{
			data->map.enemies = first;
			return (1);
		}
		data->map.enemies = data->map.enemies->next;
	}
	if (data->player.x == data->map.enemies->pos.x
		&& data->player.y == data->map.enemies->pos.y)
	{
		data->map.enemies = first;
		return (1);
	}
	data->map.enemies = first;
	return (0);
}

void	check_end(t_data *data)
{
	t_collect	*first;

	if (data->player.y == data->map.exit.y
		&& data->player.x == data->map.exit.x)
	{
		print_player(data);
		first = data->map.collectible;
		while (data->map.collectible->next != NULL)
		{
			if (data->map.collectible->is_collected != 1)
			{
				data->map.collectible = first;
				return ;
			}
			data->map.collectible = data->map.collectible->next;
		}
		if (data->map.collectible->is_collected == 1)
		{
			data->map.collectible = first;
			exit_game(data);
		}
		data->map.collectible = first;
	}
	return ;
}

void	free_all_1(t_data *data)
{
	free(data->list_down->next->next);
	free(data->list_down->next);
	free(data->list_down);
	free(data->list_up->next->next);
	free(data->list_up->next);
	free(data->list_up);
	free_all_2(data);
}

void	free_all_2(t_data *data)
{
	free(data->list_right->next->next);
	free(data->list_right->next);
	free(data->list_right);
	free(data->list_left->next->next);
	free(data->list_left->next);
	free(data->list_left);
	free(data->mlx_ptr);
}
