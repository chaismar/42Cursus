/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:55:12 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/24 15:30:02 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game(t_data *data)
{
	print_collectibles(data);
	if (data->player.y == data->map.exit.y
		&& data->player.x == data->map.exit.x)
		check_end(data);
	else if (data->win_ptr != NULL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit_img, data->map.exit.x * 64, data->map.exit.y * 64);
	return (0);
}

int	exit_game(t_data *data)
{
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	destroy_img1(data);
	free_collectible(data->map);
	free_map(data->map);
	exit(0);
}

int	start_game(t_map map)
{
	t_data	data;

	map = set_starting_pos(map);
	init_data(&data, map);
	print_map(&data);
	print_player(&data);
	mlx_loop_hook(data.mlx_ptr, &game, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, &handle_click_end, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;

	i = 0;
	if (argc == 2)
	{
		map = init_map(map, argv[1]);
		map = fill_map(map, argv[1]);
		if (map.is_valid == 5)
			return (read_error(map));
		map = fill_game_object(map);
		if (check_wall(map) == 1)
			return (wall_error(map));
		if (map.is_valid != 2)
			return (start_or_exit_error(map));
		if (map.collectible == NULL)
			return (collectible_error(map));
		map = depth_first_check(map, map.start);
		if (check_dfs(map) == 1)
			return (exit_or_collectible_not_available(map));
		start_game(map);
		return (free_collectible(map), free_map(map), 1);
	}
	return (0);
}
