/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 02:42:22 by lmarchai          #+#    #+#             */
/*   Updated: 2023/07/10 14:29:18 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_mooves(int ra, int rb, int rra, int rrb)
{
	int	total;

	total = 0;
	if (ra < rra)
	{
		if (rb < rrb)
			return (calc_rr(ra, rb));
		else
			total += ra;
	}
	else
	{
		if (rrb < rb)
			return (calc_rrr(rra, rrb));
		else
			total += rra;
	}
	if (rb < rrb)
		total += rb;
	else
		total += rrb;
	return (total);
}

int	calc_lower_mooves(t_calc_rota to_calc)
{
	t_calc_rota	temp;

	temp.ra = to_calc.ra;
	temp.rb = to_calc.rb;
	temp.rra = to_calc.rra;
	temp.rrb = to_calc.rrb;
	temp.node.content = 0;
	temp.node.index = 0;
	temp.node.next = NULL;
	return (calc_mooves(temp.ra, temp.rb, temp.rra, temp.rrb));
}

int	calc_closer_up(t_list_int **a, t_list_int node)
{
	t_list_int	next_up;

	next_up = find_closer(a, node.index);
	return (get_pos(a, next_up));
}

t_calc_rota	calc_this(t_list_int **a, t_list_int **b, int total,
	t_calc_rota to_calc)
{
	int	pos;
	int	total_a;

	total_a = ft_lstsize_int(*a);
	pos = get_pos(b, to_calc.node);
	to_calc.rb = pos;
	to_calc.rrb = total - pos;
	if (total_a != 1)
	{
		to_calc.ra = calc_closer_up(a, to_calc.node);
		to_calc.rra = total_a - calc_closer_up(a, to_calc.node);
	}
	else
	{
		to_calc.ra = 0;
		to_calc.rra = 0;
	}
	return (to_calc);
}

t_calc_rota	calc_all(t_list_int **a, t_list_int **b)
{
	t_calc_rota		temp;
	t_calc_rota		next_to_check;
	t_list_int		*list;
	int				total;

	list = *b;
	temp.node = **b;
	total = ft_lstsize_int(*b);
	temp = calc_this(a, b, total, temp);
	while (list->next != NULL)
	{
		total = ft_lstsize_int(*b);
		next_to_check.node = *list->next;
		next_to_check = calc_this(a, b, total, next_to_check);
		if (calc_lower_mooves(next_to_check) < calc_lower_mooves(temp))
			temp = next_to_check;
		list = list->next;
	}
	next_to_check.node = *list;
	next_to_check = calc_this(a, b, total, next_to_check);
	if (calc_lower_mooves(next_to_check) < calc_lower_mooves(temp))
		temp = next_to_check;
	return (temp);
}
