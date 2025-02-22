/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:04:42 by lmarchai          #+#    #+#             */
/*   Updated: 2023/07/10 12:54:56 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list_int **a, int msg)
{
	t_list_int	*temp;
	t_list_int	*list;

	if (!a || !*a || !(*a)->next)
		return ;
	if (msg == 1)
		write(1, "rra\n", 4);
	list = *a;
	while (list->next->next != NULL)
		list = list->next;
	temp = list->next;
	temp->next = *a;
	list->next = NULL;
	*a = temp;
}

void	rrb(t_list_int **b, int msg)
{
	t_list_int	*temp;
	t_list_int	*list;

	if (!b || !*b || !(*b)->next)
		return ;
	if (msg == 1)
		write(1, "rrb\n", 4);
	list = *b;
	while (list->next->next != NULL)
		list = list->next;
	temp = list->next;
	temp->next = *b;
	list->next = NULL;
	*b = temp;
}

void	rrr(t_list_int **a, t_list_int **b)
{
	write(1, "rrr\n", 4);
	rra(a, 0);
	rrb(b, 0);
}
