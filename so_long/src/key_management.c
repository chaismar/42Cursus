/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:16:24 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/23 11:42:54 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->background_img, data->player.x * 64, data->player.y * 64);
	data->player.y --;
	data->moove_set.y = 0;
	data->moove++;
	print_nbr_moove(data->moove);
	check_collect(data);
	print_player(data);
	return (data);
}

t_data	*move_down(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map[data->player.y + 1][data->player.x] == '1'
		|| data->map.map[data->player.y + 1][data->player.x] == '2')
		return (data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->background_img, data->player.x * 64, data->player.y * 64);
	data->player.y ++;
	data->moove_set.y = 0;
	data->moove++;
	print_nbr_moove(data->moove);
	check_collect(data);
	print_player(data);
	return (data);
}

t_data	*move_right(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map[data->player.y][data->player.x + 1] == '1'
		|| data->map.map[data->player.y][data->player.x + 1] == '2')
		return (data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->background_img, data->player.x * 64, data->player.y * 64);
	data->player.x++;
	data->moove_set.x = 0;
	data->moove++;
	print_nbr_moove(data->moove);
	check_collect(data);
	print_player(data);
	return (data);
}

t_data	*move_left(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map[data->player.y][data->player.x - 1] == '1'
		|| data->map.map[data->player.y][data->player.x - 1] == '2')
		return (data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->background_img, data->player.x * 64, data->player.y * 64);
	data->player.x--;
	data->moove_set.x = 0;
	data->moove++;
	print_nbr_moove(data->moove);
	check_collect(data);
	print_player(data);
	return (data);
}
