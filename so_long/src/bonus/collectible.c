/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:13:54 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/11 19:32:32 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_this(t_data *data, t_pos pos)
{
	t_collect	*first;

	first = data->map.collectible;
	while (data->map.collectible != NULL)
	{
		if (data->map.collectible->pos.x == pos.x
			&& data->map.collectible->pos.y == pos.y)
		{
			data->map.collectible->is_collected = 1;
			data->map.collectible = first;
			return ;
		}
		data->map.collectible = data->map.collectible->next;
	}
	data->map.collectible = first;
	return ;
}

void	check_collect(t_data *data)
{
	t_collect	*first;

	first = data->map.collectible;
	while (data->map.collectible != NULL)
	{
		if (data->map.collectible->pos.x == data->player.x
			&& data->map.collectible->pos.y == data->player.y)
		{
			data->map.collectible->is_collected = 1;
			data->map.collectible = first;
			return ;
		}
		data->map.collectible = data->map.collectible->next;
	}
	data->map.collectible = first;
	return ;
}
