/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_DFS.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:32:00 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/19 03:31:51 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_dfs(t_map map)
{
	if (map.map[map.start.y][map.start.x] == 'X' &&
		map.map[map.exit.y][map.exit.x] == 'X')
	{
		while (map.collectible != NULL)
		{
			if (map.map[map.collectible->pos.y][map.collectible->pos.x] != 'X')
				return (1);
			else
			map.collectible = map.collectible->next;
		}
		return (0);
	}
	return (1);
}
