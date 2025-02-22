/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 06:00:20 by lmarchai          #+#    #+#             */
/*   Updated: 2023/07/26 15:56:13 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_list_int **a)
{
	t_list_int	*first;
	t_list_int	*list;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	list = (*a)->next;
	*a = (*a)->next;
	first->next = NULL;
	while (list->next != NULL)
		list = list->next;
	list->next = first;
}

void	rb(t_list_int **b)
{
	t_list_int	*first;
	t_list_int	*list;

	if (!b || !*b || !(*b)->next)
		return ;
	if ((*b)->next == NULL)
		return ;
	first = *b;
	list = (*b)->next;
	*b = (*b)->next;
	first->next = NULL;
	while (list->next != NULL)
		list = list->next;
	list->next = first;
}

void	rr(t_list_int **a, t_list_int **b)
{
	ra(a);
	rb(b);
}
