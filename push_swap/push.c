/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 06:00:14 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/03 01:05:39 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list_int **a, t_list_int **b)
{
	t_list_int	*temp;

	if (*b != NULL)
	{
		write(1, "pa\n", 3);
		temp = *b;
		if ((*b)->next != NULL)
			*b = (*b)->next;
		else
			*b = NULL;
		temp->next = *a;
		*a = temp;
	}
}

void	pb(t_list_int **a, t_list_int **b)
{
	t_list_int	*temp;

	if (*a != NULL)
	{
		write(1, "pb\n", 3);
		temp = *a;
		if ((*a)->next != NULL)
			*a = (*a)->next;
		else
			*a = NULL;
		temp->next = *b;
		*b = temp;
	}
}
