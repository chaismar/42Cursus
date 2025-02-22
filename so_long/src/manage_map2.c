/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:46:05 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/22 08:40:43 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	add_exit(t_map map, int x, int y)
{
	if (map.exit.x != 0 || map.exit.y != 0)
	{
		map.is_valid = 0;
		return (map);
	}
	map.is_valid++;
	map.exit.x = x;
	map.exit.y = y;
	return (map);
}

t_map	add_start(t_map map, int x, int y)
{
	if (map.start.x != 0 || map.start.y != 0)
	{
		map.is_valid = 0;
		return (map);
	}
	map.is_valid++;
	map.start.x = x;
	map.start.y = y;
	return (map);
}

t_map	add_collectible(t_map map, int x, int y)
{
	t_collect	*to_collect;
	t_collect	*list;

	to_collect = malloc(sizeof(t_collect));
	if (!to_collect)
	{
		free_collectible(map);
		free_map(map);
		exit(1);
	}
	to_collect->pos.x = x;
	to_collect->pos.y = y;
	to_collect->next = NULL;
	to_collect->is_collected = 0;
	if (map.collectible == NULL)
	{
		map.collectible = to_collect;
		return (map);
	}
	list = map.collectible;
	while (list->next != NULL)
		list = list->next;
	list->next = to_collect;
	return (map);
}

int	map_width_len(char *file)
{
	int		fd;
	int		i;
	char	buffer[1];

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buffer, 1))
	{
		if (buffer[0] == '\n')
		{
			close(fd);
			return (i);
		}
		i++;
	}
	return (0);
}

int	map_height_len(char *file)
{
	int		fd;
	int		i;
	int		res;
	char	buffer[1];

	i = 0;
	res = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, buffer, 1))
	{
		if (buffer[0] == '\n')
			res++;
		i++;
	}
	close (fd);
	return (res + 1);
}
