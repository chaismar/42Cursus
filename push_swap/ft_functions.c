/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:21:56 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/02 10:32:24 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_push_swap(const char *str)
{
	int			i;
	long		nbr;
	int			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	if (nbr * sign > 2147483647 || nbr * sign < -2147483648
		|| ft_strlen(str) > 11)
		return (1);
	return (0);
}

int	ft_lstsize_int(t_list_int *lst)
{
	int			i;
	t_list_int	*actual;

	i = 0;
	actual = lst;
	while (actual)
	{
		actual = actual->next;
		i++;
	}
	return (i);
}

t_list_int	*ft_lstnew_int(int content)
{
	t_list_int	*l;

	l = malloc(sizeof(t_list_int));
	if (!l)
		return (NULL);
	l->index = 0;
	l->content = content;
	l->next = NULL;
	return (l);
}

t_list_int	*ft_lstlast_int(t_list_int *lst)
{
	t_list_int	*actual;

	if (lst == 0)
		return (lst);
	actual = lst;
	while (actual->next)
		actual = actual->next;
	return (actual);
}

void	ft_lstadd_back_int(t_list_int **lst, t_list_int *new)
{
	t_list_int	*end;

	if (lst)
	{
		if (*lst)
		{
			end = ft_lstlast_int(*lst);
			end->next = new;
		}
		else
			*lst = new;
	}
}
