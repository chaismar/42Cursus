/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:24:25 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/07 08:52:47 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	define_index2(t_list_int *l, t_list_int *last_value,
	t_list_int *first, int index)
{
	while (l->next != NULL)
	{
		if (last_value->content > l->content && l->index == 0)
		{
			last_value = l;
			l = first;
		}
		l = l->next;
	}
	if (last_value->content > l->content && l->index == 0)
	{
		last_value = l;
		l = first;
	}
	l = last_value;
	l->index = index;
	l = first;
}

void	define_index(t_list_int *l)
{
	t_list_int	*first;
	t_list_int	*last_value;
	int			nbr_nodes;
	int			index;

	index = 0;
	nbr_nodes = ft_lstsize_int(l);
	first = l;
	while (++index <= nbr_nodes)
	{
		last_value = get_unindex_val(l);
		define_index2(l, last_value, first, index);
	}
}
