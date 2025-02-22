/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:26:38 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/02 12:01:05 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	deep_check(t_list_int **a, t_list_int **b, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'r')
			add_rotate(a, b, str, i);
		else if (str[i] == 's')
			add_swap(a, b, str, i);
		else if (str[i] == 'p')
			add_push(a, b, str, i);
		else
			error_user(a, b, str);
		while (str[i] && str[i] != '\n')
			i++;
		i++;
	}
}

int	first_check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '\n' && str[i] != 'r' && str[i] != 'a'
			&& str[i] != 'b' && str[i] != 's' && str[i] != 'p')
			return (1);
	}
	return (0);
}

void	check_sorting(t_list_int **a, t_list_int **b)
{
	if (check_sorted(*a) == 0)
		write(1, "KO\n", 3);
	else if (ft_lstsize_int(*b) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
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
