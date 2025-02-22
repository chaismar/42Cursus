/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debouncing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:14:46 by lmarchai          #+#    #+#             */
/*   Updated: 2023/01/23 14:37:26 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	incr_frame(t_data *data)
{
	if (data->frame++ == 2147483647)
		data->frame = 0;
	if (data->frame < data->last_key_up_timer)
	{
		data->frame = data->frame + data->last_key_up_timer;
		data->last_key_up_timer = 0;
	}
	if (data->frame < data->last_key_down_timer)
	{
		data->frame = data->frame + data->last_key_down_timer;
		data->last_key_down_timer = 0;
	}
	if (data->frame < data->last_key_right_timer)
	{
		data->frame = data->frame + data->last_key_right_timer;
		data->last_key_right_timer = 0;
	}
	if (data->frame < data->last_key_left_timer)
	{
		data->frame = data->frame + data->last_key_left_timer;
		data->last_key_left_timer = 0;
	}
}
