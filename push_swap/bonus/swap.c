/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 05:59:36 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/08 04:15:39 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list_int **a)
{
	t_list_int	*temp;

	temp = *a;
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
}

void	sb(t_list_int **b)
{
	t_list_int	*temp;

	temp = *b;
	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
}

void	ss(t_list_int **a, t_list_int **b)
{
	sa(a);
	sb(b);
}
