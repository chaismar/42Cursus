/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:36:18 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/07 07:33:29 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_first_at_top(t_list_int **a, int total)
{
	t_list_int	*list;

	list = *a;
	while (list->next != NULL)
	{
		if (list->index == 1)
			break ;
		list = list->next;
	}
	while ((*a)->index != list->index)
	{
		if (get_pos(a, *list) > total / 2)
			rra(a, 1);
		else
			ra(a, 1);
	}
}

void	send_back(t_list_int **a, t_list_int **b, t_calc_rota to_send)
{
	if (to_send.ra < to_send.rra)
	{
		if (to_send.rb < to_send.rrb)
			return (send_rr(a, b, to_send));
		else
			use_ra(a, to_send);
	}
	else
	{
		if (to_send.rrb < to_send.rb)
			return (send_rrr(a, b, to_send));
		else
			use_rra(a, to_send);
	}
	if (to_send.rb < to_send.rrb)
		use_rb(b, to_send);
	else
		use_rrb(b, to_send);
	pa(a, b);
}

void	insert_sort(t_list_int **a, t_list_int **b, int total)
{
	t_calc_rota	to_send;

	while (--total > 0)
	{
		to_send = calc_all(a, b);
		send_back(a, b, to_send);
	}
}

void	fast_sort(t_list_int **a, t_list_int **b, int total)
{
	int			middle;

	middle = total / 2;
	while ((*a)->next != NULL)
	{
		if ((*a)->index == total)
			ra(a, 1);
		else
		{			
			if ((*a)->index < middle)
			{
				pb(a, b);
				rb(b, 1);
			}
			else
				pb(a, b);
		}
	}
	insert_sort(a, b, total);
	get_first_at_top(a, total);
}
