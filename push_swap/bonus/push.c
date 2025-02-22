/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 06:00:14 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/10 00:30:34 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_list_int **a, t_list_int **b)
{
	t_list_int	*temp;

	if (*b != NULL)
	{
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
		temp = *a;
		if ((*a)->next != NULL)
			*a = (*a)->next;
		else
			*a = NULL;
		temp->next = *b;
		*b = temp;
	}
}
