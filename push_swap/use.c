/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 02:41:00 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/07 07:21:01 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	use_ra(t_list_int **a, t_calc_rota to_send)
{
	int	temp;

	temp = to_send.ra;
	while (temp > 0)
	{
		ra(a, 1);
		temp--;
	}
}

void	use_rra(t_list_int **a, t_calc_rota to_send)
{
	int	temp;

	temp = to_send.rra;
	while (temp > 0)
	{
		rra(a, 1);
		temp--;
	}
}

void	use_rb(t_list_int **b, t_calc_rota to_send)
{
	int	temp;

	temp = to_send.rb;
	while (temp > 0)
	{
		rb(b, 1);
		temp--;
	}
}

void	use_rrb(t_list_int **b, t_calc_rota to_send)
{
	int	temp;

	temp = to_send.rrb;
	while (temp > 0)
	{
		rrb(b, 1);
		temp--;
	}
}
