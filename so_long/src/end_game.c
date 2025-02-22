/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:12:45 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/23 11:25:06 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	free(data->mlx_ptr);
}
