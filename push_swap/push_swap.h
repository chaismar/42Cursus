/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 05:15:46 by lmarchai          #+#    #+#             */
/*   Updated: 2023/02/11 19:50:10 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list_int
{
	int					content;
	int					index;
	struct s_list_int	*next;
}	t_list_int;

typedef struct s_calc_rota
{
	int			ra;
	int			rra;
	int			rb;
	int			rrb;
	t_list_int	node;
}	t_calc_rota;
//main
int				main(int argc, char **argv);
//commands
void			sa(t_list_int **a);
void			sb(t_list_int **b);
void			ss(t_list_int **a, t_list_int **b);
void			pa(t_list_int **a, t_list_int **b);
void			pb(t_list_int **a, t_list_int **b);
void			ra(t_list_int **a, int msg);
void			rb(t_list_int **b, int msg);
void			rr(t_list_int **a, t_list_int **b);
void			rra(t_list_int **a, int msg);
void			rrb(t_list_int **b, int msg);
void			rrr(t_list_int **a, t_list_int **b);
//parsing (atoi send an int if there is an issue or not)
int				ft_atoi_push_swap(const char *str);
void			check_double2(t_list_int **a, t_list_int to_check);
void			check_double(t_list_int **a);
int				check_sorted(t_list_int *l);
int				check_errors(char **l);
//setting up the list for sorting
void			define_index(t_list_int *l);
t_list_int		*get_unindex_val(t_list_int *l);
t_list_int		*get_arg(char **argv);
t_list_int		*ft_lstnew_int(int content);
t_list_int		*ft_lstlast_int(t_list_int *lst);
void			ft_lstadd_back_int(t_list_int **lst, t_list_int *new);
//selection of sorting
void			choose_sort(t_list_int **a, t_list_int **b);
//low sorting
void			sort_3(t_list_int **a);
void			sort_5(t_list_int **a, t_list_int **b, int total);
void			send_to_a(t_list_int **a, t_list_int **b,
					t_list_int node, int i);
void			send_to_b(t_list_int **a, t_list_int **b,
					t_list_int node, int i);
//sorting more than 5
//usefull function
int				ft_lstsize_int(t_list_int *lst);
t_list_int		get_second(t_list_int **a,
					t_list_int node, int median);
t_list_int		get_first(t_list_int **a, int median);
int				get_pos(t_list_int **a, t_list_int to_find);
void			get_first_at_top(t_list_int **a, int total);
t_list_int		find_closer(t_list_int **a, int index);
//first part
void			fast_sort(t_list_int **a, t_list_int **b, int total);
//second part
void			insert_sort(t_list_int **a, t_list_int **b, int total);
void			send_back(t_list_int **a, t_list_int **b, t_calc_rota to_send);
t_calc_rota		calc_all(t_list_int **a, t_list_int **b);
/*functions that calculate how much mooves it take
to use each commands for a define node*/
t_calc_rota		calc_all(t_list_int **a, t_list_int **b);
int				calc_closer_up(t_list_int **a, t_list_int node);
int				calc_lower_mooves(t_calc_rota to_calc);
int				calc_mooves(int ra, int rb, int rra, int rrb);
int				calc_rrr(int rra, int rrb);
int				calc_rr(int ra, int rb);
/*functions that use the commands in function of how much we calculated before*/
void			use_rrb(t_list_int **b, t_calc_rota to_send);
void			use_rb(t_list_int **b, t_calc_rota to_send);
void			use_rra(t_list_int **a, t_calc_rota to_send);
void			use_ra(t_list_int **a, t_calc_rota to_send);
void			send_rrr(t_list_int **a, t_list_int **b, t_calc_rota to_send);
void			send_rr(t_list_int **a, t_list_int **b, t_calc_rota to_send);
//properly clear the list
void			clean(t_list_int *a, int msg);
#endif