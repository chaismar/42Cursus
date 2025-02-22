/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:28:49 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/23 14:32:27 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check_width_line(char *file, int width)
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
			if (i != width)
				return (1);
			i = -1;
		}
		i++;
	}
	if (i != width)
		return (1);
	return (0);
}

t_map	init_map(t_map map, char *file)
{
	static int	i = -1;

	map.height = map_height_len(file);
	if (map.height == -1)
	{
		map.is_valid = 5;
		return (map);
	}
	map.width = map_width_len(file);
	map.collectible = NULL;
	map.start = (t_pos){0, 0};
	map.exit = (t_pos){0, 0};
	map.is_valid = 0;
	map.enemies = NULL;
	map.map = malloc(sizeof(char *) * map.height + 1);
	if (!map.map)
		alloc_error(map);
	while (++i < map.height)
	{
		map.map[i] = malloc(sizeof(char) * map.width + 2);
		if (!map.map[i])
			alloc_error(map);
		map.map[i][map.width] = 0;
	}
	return (map);
}

t_map	fill_map(t_map map, char *file)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file, O_RDONLY);
	while (i < map.height)
	{
		if (read(fd, map.map[i], map.width + 1) == 0)
		{
			map.is_valid = 5;
			return (map);
		}
		i++;
	}
	close (fd);
	return (map);
}

int	check_wall(t_map map)
{
	int	i;

	i = 0;
	while (i < map.width)
	{
		if (map.map[0][i] != '1' || map.map[map.height - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < map.height)
	{
		if (map.map[i][0] != '1' || map.map[i][map.width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

t_map	fill_game_object(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.map[i][j] == 'C')
				map = add_collectible(map, j, i);
			else if (map.map[i][j] == 'P')
				map = add_start(map, j, i);
			else if (map.map[i][j] == 'E')
				map = add_exit(map, j, i);
			else if (map.map[i][j] == 'N')
				map = add_enemies(map, j, i);
			else if (map.map[i][j] != '1' && map.map[i][j] != '0' &&
				map.map[i][j] != '\n' && map.map[i][j] != '\0')
				map_error(map);
			j++;
		}
		i++;
	}
	return (map);
}
