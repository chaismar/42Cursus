/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 02:43:30 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/07 04:55:52 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_rr(int ra, int rb)
{
	int	i;

	i = 0;
	while (ra-- > 0 && rb-- > 0)
		i++;
	if (ra > 0)
		i += ra;
	if (rb > 0)
		i += rb;
	return (i);
}

int	calc_rrr(int rra, int rrb)
{
	int	i;

	i = 0;
	while (rra-- > 0 && rrb > 0)
		i++;
	if (rra > 0)
		i += rra;
	if (rrb > 0)
		i += rrb;
	return (i);
}

t_list_int	check_last(t_list_int *list, t_list_int ret, int index)
{
	if (list->index > index)
	{
		if (ret.index != 0)
		{
			if (list->index - index < ret.index - index)
				ret = *list;
		}
		else
			ret = *list;
	}
	return (ret);
}

t_list_int	find_closer(t_list_int **a, int index)
{
	t_list_int	*list;
	t_list_int	ret;

	list = *a;
	ret = (t_list_int){0, 0, NULL};
	while (list->next != NULL)
	{
		if (list->index > index)
		{
			if (ret.index != 0)
			{
				if (list->index - index < ret.index - index)
					ret = *list;
			}
			else
				ret = *list;
		}
		list = list->next;
	}
	ret = check_last(list, ret, index);
	return (ret);
}
