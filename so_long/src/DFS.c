/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:30:45 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/17 04:22:43 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_up(t_map map, t_pos pos)
{
	if (map.map[pos.y - 1][pos.x] == '1' || map.map[pos.y - 1][pos.x] == '1')
		return (1);
	return (0);
}

int	check_down(t_map map, t_pos pos)
{
	if (map.map[pos.y + 1][pos.x] == '1' || map.map[pos.y + 1][pos.x] == 'X')
		return (1);
	return (0);
}

int	check_left(t_map map, t_pos pos)
{
	if (map.map[pos.y][pos.x - 1] == '1' || map.map[pos.y][pos.x - 1] == 'X')
		return (1);
	return (0);
}

int	check_right(t_map map, t_pos pos)
{
	if (map.map[pos.y][pos.x + 1] == '1' || map.map[pos.y][pos.x + 1] == 'X')
		return (1);
	return (0);
}

t_map	depth_first_check(t_map map, t_pos pos)
{
	map.map[pos.y][pos.x] = 'X';
	if (check_left(map, pos) == 0)
		depth_first_check(map, (t_pos){pos.x - 1, pos.y});
	if (check_up(map, pos) == 0)
		depth_first_check(map, (t_pos){pos.x, pos.y - 1});
	if (check_right(map, pos) == 0)
		depth_first_check(map, (t_pos){pos.x + 1, pos.y});
	if (check_down(map, pos) == 0)
		depth_first_check(map, (t_pos){pos.x, pos.y + 1});
	return (map);
}
