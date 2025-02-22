/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_specials.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 02:41:32 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/07 07:29:38 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_rr(t_list_int **a, t_list_int **b, t_calc_rota to_send)
{
	while (to_send.ra > 0 && to_send.rb > 0)
	{
		rr(a, b);
		to_send.ra--;
		to_send.rb--;
	}
	while (to_send.ra > 0)
	{
		ra(a, 1);
		to_send.ra--;
	}
	while (to_send.rb > 0)
	{
		rb(b, 1);
		to_send.rb--;
	}
	pa(a, b);
}

void	send_rrr(t_list_int **a, t_list_int **b, t_calc_rota to_send)
{
	while (to_send.rra > 0 && to_send.rrb > 0)
	{
		rrr(a, b);
		to_send.rra--;
		to_send.rrb--;
	}
	while (to_send.rra > 0)
	{
		rra(a, 1);
		to_send.rra--;
	}
	while (to_send.rrb > 0)
	{
		rrb(b, 1);
		to_send.rrb--;
	}
	pa(a, b);
}
