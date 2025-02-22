/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_user2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:00:39 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/02 12:21:24 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_double2(t_list_int **a, t_list_int to_check)
{
	t_list_int	*list;

	list = *a;
	while (list->next != NULL)
	{
		if (to_check.content == list->content && to_check.index != list->index)
		{
			clean(*a, 1);
			exit(1);
		}
		else
			list = list->next;
	}
	if (to_check.content == list->content && to_check.index != list->index)
	{
		clean(*a, 1);
		exit(1);
	}
}

void	check_double(t_list_int **a)
{
	t_list_int	*list;

	list = *a;
	while (list->next != NULL)
	{
		check_double2(a, *list);
		list = list->next;
	}
	check_double2(a, *list);
}
