/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:23:23 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/02 10:58:54 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
			error_user(&a, NULL, NULL);
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
