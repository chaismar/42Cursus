/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:04:42 by lmarchai          #+#    #+#             */
/*   Updated: 2023/07/10 12:41:36 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_list_int **a)
{
	t_list_int	*temp;
	t_list_int	*list;

	if (!a || !*a || !(*a)->next)
		return ;
	list = *a;
	while (list->next->next != NULL)
		list = list->next;
	temp = list->next;
	temp->next = *a;
	list->next = NULL;
	*a = temp;
}

void	rrb(t_list_int **b)
{
	t_list_int	*temp;
	t_list_int	*list;

	if (!b || !*b || !(*b)->next)
		return ;
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
	rra(a);
	rrb(b);
}
