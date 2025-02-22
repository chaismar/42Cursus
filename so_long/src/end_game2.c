/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 10:09:45 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/23 11:25:27 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img1(t_data *data)
{
	if (data->background_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->background_img);
	if (data->collectible_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->collectible_img);
	if (data->player_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->player_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx_ptr, data->exit_img);
	if (data->inside_wall_img)
		mlx_destroy_image(data->mlx_ptr, data->inside_wall_img);
	if (data->wall_img)
		mlx_destroy_image(data->mlx_ptr, data->wall_img);
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free_all_1(data);
}
