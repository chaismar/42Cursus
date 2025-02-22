/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 06:00:20 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/07 07:17:53 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list_int **a, int msg)
{
	t_list_int	*first;
	t_list_int	*list;

	if (msg == 1)
		write(1, "ra\n", 3);
	first = *a;
	list = (*a)->next;
	*a = (*a)->next;
	first->next = NULL;
	while (list->next != NULL)
		list = list->next;
	list->next = first;
}

void	rb(t_list_int **b, int msg)
{
	t_list_int	*first;
	t_list_int	*list;

	if (msg == 1)
		write(1, "rb\n", 3);
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
	write(1, "rr\n", 3);
	ra(a, 0);
	rb(b, 0);
}
