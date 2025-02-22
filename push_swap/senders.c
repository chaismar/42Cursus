/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   senders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:29:45 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/07 07:20:43 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_list_int **a, t_list_int **b, t_list_int node, int i)
{
	int	total;

	total = ft_lstsize_int(*a);
	if (i >= total / 2)
		while ((*a)->index != node.index)
			rra(a, 1);
	else
		while ((*a)->index != node.index)
			ra(a, 1);
	pb(a, b);
}

void	send_to_a(t_list_int **a, t_list_int **b, t_list_int node, int i)
{
	int	total;

	total = ft_lstsize_int(*b);
	if (i > total / 2)
		while ((*b)->index != node.index)
			rrb(b, 1);
	else
		while ((*b)->index != node.index)
			rb(b, 1);
	pa(a, b);
}
