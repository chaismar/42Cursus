/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:25:18 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/19 03:33:26 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_bfs_end(t_queue *queue, t_pos goal)
{
	if (queue->pos.x == goal.x && queue->pos.y == goal.y)
		return (1);
	return (0);
}

int	check_already_checked(t_queue *queue, t_pos next_pos)
{
	t_queue	*first;

	first = queue;
	while (queue->previous != NULL)
		queue = queue->previous;
	while (queue->next != NULL)
	{
		if (queue->pos.x == next_pos.x && queue->pos.y == next_pos.y)
			return (1);
		queue = queue->next;
	}
	queue = first;
	return (0);
}
