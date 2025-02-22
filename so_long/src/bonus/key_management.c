/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:16:24 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/23 14:41:18 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	static int	count = 15;

	if (count++ >= 13 && data->map.enemies != NULL)
	{
		game(data);
		get_next_pos(data);
		data = move_enemie(data);
		count = 0;
	}
	if (keysym == 65362 || keysym == 119)
		move_up(data);
	else if (keysym == 65364 || keysym == 115)
		move_down(data);
	else if (keysym == 65363 || keysym == 100)
		move_right(data);
	else if (keysym == 65361 || keysym == 97)
		move_left(data);
	else if (keysym == XK_Escape)
		exit_game(data);
	return (0);
}

t_data	*move_up(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map[data->player.y - 1][data->player.x] == '1'
		|| data->map.map[data->player.y - 1][data->player.x] == '2')
		return (data);
	if (data->frame - data->last_key_up_timer > 200)
	{
		data->last_key_up_timer = data->frame;
		movement_up(data);
		data->player.y --;
		data->moove_set.y = 0;
		check_collect(data);
		print_player(data);
		print_moove(data);
	}
	return (data);
}

t_data	*move_down(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map[data->player.y + 1][data->player.x] == '1'
		|| data->map.map[data->player.y + 1][data->player.x] == '2')
		return (data);
	if (data->frame - data->last_key_down_timer > 200)
	{
		data->last_key_down_timer = data->frame;
		movement_down(data);
		data->player.y ++;
		data->moove_set.y = 0;
		check_collect(data);
		print_player(data);
		print_moove(data);
	}
	return (data);
}

t_data	*move_right(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map[data->player.y][data->player.x + 1] == '1'
		|| data->map.map[data->player.y][data->player.x + 1] == '2')
		return (data);
	if (data->frame - data->last_key_right_timer > 200)
	{
		data->last_key_right_timer = data->frame;
		movement_right(data);
		data->player.x++;
		data->moove_set.x = 0;
		check_collect(data);
		print_player(data);
		print_moove(data);
	}
	return (data);
}

t_data	*move_left(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map[data->player.y][data->player.x - 1] == '1'
		|| data->map.map[data->player.y][data->player.x - 1] == '2')
		return (data);
	if (data->frame - data->last_key_left_timer > 200)
	{
		data->last_key_left_timer = data->frame;
		movement_left(data);
		data->player.x--;
		data->moove_set.x = 0;
		check_collect(data);
		print_player(data);
		print_moove(data);
	}
	return (data);
}
