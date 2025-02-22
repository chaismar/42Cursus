/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:03:09 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/11 14:30:11 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_reverse_rotate(t_list_int **a, t_list_int **b, char *str, int i)
{
	if (str[i + 1] == 'r' && str[i + 2] == '\n')
		rrr(a, b);
	else if (str[i + 1] == 'a' && str[i + 2] == '\n')
		rra(a);
	else if (str[i + 1] == 'b' && str[i + 2] == '\n')
		rrb(b);
	else
		error_user(a, b, str);
}

void	add_rotate(t_list_int **a, t_list_int **b, char *str, int i)
{
	if (str[i + 1] == 0 || str[i + 2] == 0)
		error_user(a, b, str);
	else if (str[i + 1] == 'r')
	{
		if (str[i + 2] == '\n' || str[i + 2] == '\0')
			rr(a, b);
		else
			add_reverse_rotate(a, b, str, i + 1);
	}
	else if (str[i + 1] == 'a' && str[i + 2] == '\n')
		ra(a);
	else if (str[i + 1] == 'b' && str[i + 2] == '\n')
		rb(b);
	else
		error_user(a, b, str);
}

void	add_swap(t_list_int **a, t_list_int **b, char *str, int i)
{
	if (str[i + 1] == 's' && str[i + 2] == '\n')
		ss(a, b);
	else if (str[i + 1] == 'a' && str[i + 2] == '\n')
		sa(a);
	else if (str[i + 1] == 'a' && str[i + 2] == '\n')
		sb(b);
	else
		error_user(a, b, str);
}

void	add_push(t_list_int **a, t_list_int **b, char *str, int i)
{
	if (str[i + 1] == 'a' && str[i + 2] == '\n')
		pa(a, b);
	else if (str[i + 1] == 'b' && str[i + 2] == '\n')
		pb(a, b);
	else
		error_user(a, b, str);
}
