/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:21:57 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/19 03:31:10 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectible_error(t_map map)
{
	free_map(map);
	write(1, "Error : no collectible available", 33);
	return (0);
}

int	exit_or_collectible_not_available(t_map map)
{
	free_map(map);
	free_collectible(map);
	write(1, "Error : exit or collectible are not reachable", 46);
	return (0);
}

int	read_error(t_map map)
{
	free_collectible(map);
	free_map(map);
	write(1, "Error : read error check you argument", 38);
	return (0);
}

int	width_error(t_map map)
{
	free_map(map);
	write(1, "Error : map is not a square", 28);
	return (0);
}

int	wall_error(t_map map)
{
	free_collectible(map);
	free_map(map);
	write(1, "Error : walls are not correct", 30);
	return (0);
}
