/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:15:53 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/23 12:20:50 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alloc_error_free(t_map map)
{
	free_collectible(map);
	free_enemies(map);
	free_map(map);
	exit(1);
}

void	map_error(t_map map)
{
	free_collectible(map);
	free_map(map);
	write(1, "Error : unknow character in map", 32);
	exit(1);
}

void	alloc_error(t_map map)
{
	free_map(map);
	write(1, "Error : allocation error for map", 33);
	exit(1);
}
