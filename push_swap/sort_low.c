/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:28:01 by lmarchai          #+#    #+#             */
/*   Updated: 2023/07/26 15:53:01 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list_int **a)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
	{
		if ((*a)->next->content < (*a)->next->next->content)
			ra(a, 1);
		else
		{
			sa(a);
			rra(a, 1);
		}
		return ;
	}
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
	{
		if ((*a)->next->content < (*a)->next->next->content)
			return ;
		sa(a);
		ra(a, 1);
		return ;
	}
	if ((*a)->next->content < (*a)->next->next->content)
		sa(a);
	else
		rra(a, 1);
}

void	insert_to_a(t_list_int **a, t_list_int **b, int total)
{
	t_list_int	closest;
	int			pos;

	closest = find_closer(a, (*b)->index);
	pos = get_pos(a, closest);
	if (pos >= total / 2)
		while ((*a)->index != closest.index)
			rra(a, 1);
	else
		while ((*a)->index != closest.index)
			ra(a, 1);
	pa(a, b);
}

void	sort_5(t_list_int **a, t_list_int **b, int total)
{
	if (total == 5)
	{
		if ((*a)->index == total)
			rra(a, 1);
		send_to_b(a, b, **a, get_pos(a, **a));
	}
	if ((*a)->index == total)
		rra(a, 1);
	send_to_b(a, b, **a, get_pos(a, **a));
	sort_3(a);
	if (total == 5)
		insert_to_a(a, b, total);
	insert_to_a(a, b, total);
	get_first_at_top(a, total);
}
