/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:50:38 by lmarchai          #+#    #+#             */
/*   Updated: 2023/07/26 15:52:17 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	clean(t_list_int *a, int msg)
{
	t_list_int	*next;

	if (msg == 1)
		write(2, "Error\n", 6);
	while (a->next != NULL)
	{
		next = a->next;
		free(a);
		a = next;
	}
	free(a);
	exit(1);
}

void	choose_sort(t_list_int **a, t_list_int **b)
{
	int	total;

	total = ft_lstsize_int(*a);
	if (total == 2)
		ra(a, 1);
	if (total == 3)
		sort_3(a);
	if (total == 4 || total == 5)
		sort_5(a, b, total);
	if (total > 5)
		fast_sort(a, b, total);
}

int	main(int argc, char **argv)
{
	t_list_int	*a;
	t_list_int	*b;

	a = NULL;
	if (argc != 1 && check_errors(argv) == 0)
	{
		if (argc == 2)
		{
			if (ft_atoi_push_swap(argv[1]) == 1)
				return (write(2, "Error\n", 7), 1);
			return (0);
		}
		a = get_arg(argv);
		if (check_sorted(a) == 1)
			return (clean(a, 0), 1);
		b = NULL;
		define_index(a);
		check_double(&a);
		choose_sort(&a, &b);
		clean(a, 0);
	}
	else
		return (1);
	return (0);
}
