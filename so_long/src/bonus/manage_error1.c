/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 06:02:55 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/22 10:28:26 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map map)
{
	int	i;

	if (map.map != NULL)
	{
		i = 0;
		while (i < map.height)
		{
			free(map.map[i]);
			i++;
		}
		free(map.map);
	}
}

void	free_enemies(t_map map)
{
	t_enemies	*next_to_free;

	next_to_free = map.enemies;
	while (map.enemies != NULL)
	{
		next_to_free = map.enemies->next;
		free(map.enemies);
		map.enemies = next_to_free;
	}
	free(next_to_free);
}

void	free_collectible(t_map map)
{
	t_collect	*next_to_free;

	next_to_free = map.collectible;
	while (map.collectible != NULL)
	{
		next_to_free = map.collectible->next;
		free(map.collectible);
		map.collectible = next_to_free;
	}
	free(next_to_free);
}

int	start_or_exit_error(t_map map)
{
	free_collectible(map);
	free_map(map);
	write(1, "Error : start or exit error", 28);
	return (0);
}
