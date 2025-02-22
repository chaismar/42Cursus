/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 05:10:20 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/02 12:04:48 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list_int
{
	int					index;
	int					content;
	struct s_list_int	*next;
}	t_list_int;

void		sa(t_list_int **a);
void		sb(t_list_int **b);
void		ss(t_list_int **a, t_list_int **b);
void		pa(t_list_int **a, t_list_int **b);
void		pb(t_list_int **a, t_list_int **b);
void		ra(t_list_int **a);
void		rb(t_list_int **b);
void		rr(t_list_int **a, t_list_int **b);
void		rra(t_list_int **a);
void		rrb(t_list_int **b);
void		rrr(t_list_int **a, t_list_int **b);

int			first_check(char *str);
void		deep_check(t_list_int **a, t_list_int **b, char *str);
void		error_user(t_list_int **a, t_list_int **b, char *str);
void		read_standard_input(t_list_int **a, t_list_int **b);
void		check_sorting(t_list_int **a, t_list_int **b);
void		check_double(t_list_int **a);
void		check_double2(t_list_int **a, t_list_int to_check);
//functions that parse and call the right function for each line get
void		add_reverse_rotate(t_list_int **a, t_list_int **b,
				char *str, int i);
void		add_rotate(t_list_int **a, t_list_int **b,
				char *str, int i);
void		add_swap(t_list_int **a, t_list_int **b, char *str, int i);
void		add_push(t_list_int **a, t_list_int **b, char *str, int i);

void		set_up_list(t_list_int **a, t_list_int **b, char *str);
int			check_errors(char **l);
int			check_sorted(t_list_int *l);
void		check_double(t_list_int **a);
void		check_double2(t_list_int **a, t_list_int to_check);
void		define_index2(t_list_int *l, t_list_int *last_value,
				t_list_int *first, int index);
void		define_index(t_list_int *l);
int			ft_atoi_push_swap(const char *str);
int			ft_lstsize_int(t_list_int *lst);
t_list_int	*ft_lstnew_int(int content);
t_list_int	*ft_lstlast_int(t_list_int *lst);
void		ft_lstadd_back_int(t_list_int **lst, t_list_int *new);
t_list_int	*get_arg(char **argv);
t_list_int	*get_unindex_val(t_list_int *l);
void		clean(t_list_int *a, int msg);

#endif