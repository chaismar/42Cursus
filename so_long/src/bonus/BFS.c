/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:24:29 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/19 10:47:44 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_queue	*add_next(t_queue *queue, t_pos next_pos)
{
	t_queue	*new;
	t_queue	*first;

	if (check_already_checked(queue, next_pos))
		return (queue);
	first = queue;
	new = malloc(sizeof(t_queue));
	if (!new)
		return (queue);
	new->next = NULL;
	new->pos.x = next_pos.x;
	new->pos.y = next_pos.y;
	new->previous = queue;
	while (queue->next != NULL)
		queue = queue->next;
	queue->next = new;
	queue = first;
	return (queue);
}

t_queue	*get_next_nodes(t_data *data, t_queue *queue)
{
	if (data->map.map[queue->pos.y + 1][queue->pos.x] != '1'
		&& data->map.map[queue->pos.y + 1][queue->pos.x] != '2')
		queue = add_next(queue, (t_pos){queue->pos.x, queue->pos.y + 1});
	if (data->map.map[queue->pos.y][queue->pos.x + 1] != '1'
		&& data->map.map[queue->pos.y][queue->pos.x + 1] != '2')
		queue = add_next(queue, (t_pos){queue->pos.x + 1, queue->pos.y});
	if (data->map.map[queue->pos.y - 1][queue->pos.x] != '1'
		&& data->map.map[queue->pos.y - 1][queue->pos.x] != '2')
		queue = add_next(queue, (t_pos){queue->pos.x, queue->pos.y - 1});
	if (data->map.map[queue->pos.y][queue->pos.x - 1] != '1'
		&& data->map.map[queue->pos.y][queue->pos.x - 1] != '2')
		queue = add_next(queue, (t_pos){queue->pos.x - 1, queue->pos.y});
	return (queue);
}

t_pos	get_first_pos(t_queue *queue)
{
	while (queue->previous->previous != NULL)
		queue = queue->previous;
	return (queue->pos);
}

void	free_queue(t_queue *queue)
{
	t_queue	*next_to_free;

	next_to_free = queue;
	while (queue != NULL)
	{
		next_to_free = queue->next;
		free(queue);
		queue = next_to_free;
	}
	free(next_to_free);
}

t_pos	bfs(t_data *data, t_enemies enemie)
{
	t_queue	*queue;
	t_queue	*first;
	t_pos	res;

	res = (t_pos){0, 0};
	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (enemie.pos);
	queue->previous = NULL;
	queue->next = NULL;
	queue->pos = enemie.pos;
	first = queue;
	while (check_bfs_end(queue, data->player) != 1)
	{
		queue = get_next_nodes(data, queue);
		queue = queue->next;
	}
	res = get_first_pos(queue);
	queue = first;
	free_queue(queue);
	return (res);
}
