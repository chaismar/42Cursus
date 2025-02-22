/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:09:28 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/02 12:18:01 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_user(t_list_int **a, t_list_int **b, char *str)
{
	clean(*a, 0);
	if (b)
		clean(*b, 1);
	if (str)
		free(str);
	exit(1);
}

void	clean(t_list_int *a, int msg)
{
	t_list_int	*next;

	if (msg == 1)
		write(2, "Error\n", 6);
	if (a)
	{
		while (a->next != NULL)
		{
			next = a->next;
			free(a);
			a = next;
		}
		free(a);
	}
}

void	set_up_list(t_list_int **a, t_list_int **b, char *str)
{
	if (first_check(str) == 1)
		error_user(a, b, str);
	else
		deep_check(a, b, str);
}

void	read_standard_input(t_list_int **a, t_list_int **b)
{
	char	*str;
	char	*buff;
	int		bool;

	bool = 0;
	str = get_next_line(0);
	if (!str)
		return ;
	while (bool != 1)
	{
		buff = get_next_line(0);
		if (!buff || buff[0] == '\n')
			bool = 1;
		else
			str = ft_strjoin(str, buff);
	}
	set_up_list(a, b, str);
	free(str);
}

int	main(int argc, char **argv)
{
	t_list_int	*a;
	t_list_int	*b;

	a = NULL;
	b = NULL;
	if (argc != 1 && check_errors(argv) == 0)
	{
		a = get_arg(argv);
		define_index(a);
		check_double(&a);
		read_standard_input(&a, &b);
		check_sorting(&a, &b);
		clean(a, 0);
	}
	else
		return (1);
	return (0);
}
