/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:23:23 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/02 11:15:34 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_int	*get_arg(char **argv)
{
	int			i;
	t_list_int	*a;
	t_list_int	*new;

	i = 2;
	if (ft_atoi_push_swap(argv[1]) == 1)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	a = ft_lstnew_int(ft_atoi(argv[1]));
	while (argv[i])
	{
		if (ft_atoi_push_swap(argv[i]) == 1)
			clean(a, 1);
		new = ft_lstnew_int(ft_atoi(argv[i]));
		if (new == NULL)
			return (a);
		ft_lstadd_back_int(&a, new);
		i++;
	}
	return (a);
}

t_list_int	*get_unindex_val(t_list_int *l)
{
	while (l->next != NULL)
	{
		if (l->index == 0)
			return (l);
		l = l->next;
	}
	return (l);
}

t_list_int	get_second(t_list_int **a,
	t_list_int node, int median)
{
	t_list_int	*list;
	t_list_int	ret;

	if (!*a)
		return (**a);
	list = *a;
	ret.next = NULL;
	ret.content = 0;
	ret.index = 0;
	while (list->next != NULL)
	{
		if (list->index <= median && list->index != node.index)
			ret = *list;
		list = list->next;
	}
	if (list->index <= median && list->index != node.index)
		return (ret);
	return (ret);
}

t_list_int	get_first(t_list_int **a, int median)
{
	t_list_int	*list;
	t_list_int	ret;

	list = *a;
	while (list->next != NULL)
	{
		if (list->index <= median)
			return (*list);
		else
			list = list->next;
	}
	if (list->index <= median)
		return (*list);
	ret.next = NULL;
	ret.content = 0;
	ret.index = 0;
	return (ret);
}

int	get_pos(t_list_int **a, t_list_int to_find)
{
	int			i;
	t_list_int	*list;

	i = 0;
	list = *a;
	while (list->next != NULL)
	{
		if (list->index == to_find.index)
			return (i);
		list = list->next;
		i++;
	}
	return (i);
}
