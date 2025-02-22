/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:26:38 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/02 11:15:26 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double2(t_list_int **a, t_list_int to_check)
{
	t_list_int	*list;

	list = *a;
	while (list->next != NULL)
	{
		if (to_check.content == list->content && to_check.index != list->index)
			clean(*a, 1);
		else
			list = list->next;
	}
	if (to_check.content == list->content && to_check.index != list->index)
		clean(*a, 1);
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

int	check_sorted(t_list_int *l)
{
	t_list_int	*first;

	first = l;
	while (l->next != NULL)
	{
		if (l->content < l->next->content)
			l = l->next;
		else
		{
			l = first;
			return (0);
		}
	}
	l = first;
	return (1);
}

int	check_errors(char **l)
{
	int	i;
	int	j;

	i = 1;
	while (l[i])
	{
		if (ft_strncmp(l[i], "", 1) == 0)
			return (write(2, "Error\n", 7), 1);
		j = 0;
		while (l[i][j])
		{
			if (ft_isdigit(l[i][j]) == 0 && l[i][j] != '-' && l[i][j] != ' ')
				return (write(2, "Error\n", 7), 1);
			if (l[i][j] == '-' && ft_isdigit(l[i][j + 1]) == 0)
				return (write(2, "Error\n", 7), 1);
			j++;
		}
		i++;
	}
	return (0);
}
