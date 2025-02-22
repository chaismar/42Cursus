/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frames.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:22:51 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/24 15:31:20 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_up_img(t_data *data)
{
	int				size;
	t_player_up_img	*list;
	t_player_up_img	*next;

	size = 64;
	list = malloc(sizeof(t_player_up_img));
	if (!list)
		exit_game(data);
	list->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/up_walk/1_floor.xpm", &size, &size);
	list->next = malloc(sizeof(t_player_up_img));
	if (!list->next)
		exit_game(data);
	list->next->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/up_walk/2_floor.xpm", &size, &size);
	list->next->next = malloc(sizeof(t_player_up_img));
	if (!list->next->next)
		exit_game(data);
	list->next->next->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/up_walk/3_floor.xpm", &size, &size);
	list->next->next->next = list;
	data->list_up = list;
}

void	init_down_img(t_data *data)
{
	int					size;
	t_player_down_img	*list;
	t_player_down_img	*next;

	size = 64;
	list = malloc(sizeof(t_player_down_img));
	if (!list)
		exit_game(data);
	list->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/down_walk/1_floor.xpm", &size, &size);
	list->next = malloc(sizeof(t_player_down_img));
	if (!list->next)
		exit_game(data);
	list->next->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/down_walk/2_floor.xpm", &size, &size);
	list->next->next = malloc(sizeof(t_player_down_img));
	if (!list->next->next)
		exit_game(data);
	list->next->next->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/down_walk/3_floor.xpm", &size, &size);
	list->next->next->next = list;
	data->list_down = list;
}

void	init_left_img(t_data *data)
{
	int					size;
	t_player_left_img	*list;
	t_player_left_img	*next;

	size = 64;
	list = malloc(sizeof(t_player_left_img));
	if (!list)
		exit_game(data);
	list->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/left_walk/1_floor.xpm", &size, &size);
	list->next = malloc(sizeof(t_player_left_img));
	if (!list->next)
		exit_game(data);
	list->next->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/left_walk/2_floor.xpm", &size, &size);
	list->next->next = malloc(sizeof(t_player_left_img));
	if (!list->next->next)
		exit_game(data);
	list->next->next->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/left_walk/3_floor.xpm", &size, &size);
	list->next->next->next = list;
	data->list_left = list;
}

void	init_right_img(t_data *data)
{
	int					size;
	t_player_right_img	*list;
	t_player_right_img	*next;

	size = 64;
	list = malloc(sizeof(t_player_right_img));
	if (!list)
		exit_game(data);
	list->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/right_walk/3_floor.xpm", &size, &size);
	list->next = malloc(sizeof(t_player_right_img));
	if (!list->next)
		exit_game(data);
	list->next->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/right_walk/2_floor.xpm", &size, &size);
	list->next->next = malloc(sizeof(t_player_right_img));
	if (!list->next->next)
		exit_game(data);
	list->next->next->img = mlx_xpm_file_to_image(data->mlx_ptr,
			"ressources/right_walk/1_floor.xpm", &size, &size);
	list->next->next->next = list;
	data->list_right = list;
}

void	init_img(t_data *data)
{
	init_up_img(data);
	init_down_img(data);
	init_left_img(data);
	init_right_img(data);
}
