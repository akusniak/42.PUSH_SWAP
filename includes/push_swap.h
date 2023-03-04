/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:05:27 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/04 15:09:36 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "libft.h"

# define YES 1
# define NO 0

# define OK 1
# define KO 0

# define EXIT 1
# define NO_EXIT 0

# define PRINT_ERROR_MESSAGE 3
# define NO_ERROR_MESSAGE 4

# define ROTATE 42
# define REVERSE_ROTATE 43

# define TYPE 0
# define QUANTITY 1

# define INDEX 0
# define VALUE 1

# define NO_EXIST 99

# define PRINT 0
# define NO_PRINT 1

# define SA 10
# define SB 11
# define SS 12

# define PA 13
# define PB 14

# define RA 15
# define RB 16
# define RR 17

# define RRA 18
# define RRB 19
# define RRR 20

# define REDUCE -1
# define INCREASE 1

typedef struct s_type
{
	int	a;
	int	b;
}				t_type;

typedef struct s_quantity
{
	int	a;
	int	b;
}				t_quantity;

typedef struct s_cost
{
	t_type		type;
	t_quantity	quantity;
}				t_cost;

typedef struct s_best
{
	int		candidate;
	int		receiver;
}				t_best;

typedef struct s_data
{
	int		*a;
	int		*b;
	int		len_a;
	int		len_b;
	int		actions;
	int		error_code;
}				t_data;

void	ft_sort_three(t_data *data);
void	ft_brute_sort(t_data *hide);
int		ft_is_sorted(int *stack, int len);
int		ft_is_inversed(int *stack, int len);
int		ft_find_biggest(int *stack_a, int len);
int		ft_find_small(int *stack_a, int len);
void	ft_search_execution(t_data *data, t_cost *cost, t_best *best,
			t_data *hide);
int		ft_find_receiver(int candidat, t_data *data, t_data *hide);
int		ft_find_neighbor_top(int candidat_index, t_data *data,
			t_data *hide, int wanted_value);
void	ft_get_execution_info(t_data *data, t_cost *cost, t_best *best);
int		ft_is_last(int *stack_a, int number, int last);
int		ft_is_first(int *stack_a, int number);
int		ft_get_index(int *stack, int len, int nbr);
void	ft_parsing(int argc, char **argv);
void	ft_is_valid_arguments(char *argv);
void	ft_print_error_and_exit(void);
void	ft_leave(t_data *data, int error_message, int action);
t_data	*ft_init_data(int argc);
int		ft_set_data(t_data *data, char **argv);
int		*ft_get_sorted_tab(t_data *data_cpy);
int		ft_action(int *stack, int len, int number, int return_wanted);
void	ft_duo_action(t_data *data, t_best *best, int action);
void	ft_execution(t_data *data, t_cost *cost, t_best *best);
void	ft_same_cost(t_data *data, t_cost *cost, t_best *best);
void	ft_put_little_at_start(t_data *data, t_data *hide);
void	ft_get_cost_info(int current_candidate,
			int current_receiver, t_cost *cost, t_data *data);
int		ft_get_current_cost(t_cost *cost);
void	ft_ajust_len(int action_a, int *len_a, int action_b, int *len_b);
void	ft_refill_winner(int *new, int *old, int len);
void	ft_refill_looser(int *new, int *old, int len);
int		*ft_intdup(int *new, int len);
void	ft_ok_stack_ok_refill_pa(t_data *data);
void	ft_ok_stack_no_refill_pa(t_data *data);
void	ft_ok_stack_ok_refill_pb(t_data *data);
void	ft_ok_stack_no_refill_pb(t_data *data);
void	ft_no_stack(t_data *data, int action);
void	ft_no_stack_no_refill_pa(t_data *data);
void	ft_no_stack_ok_refill_pa(t_data *data);
void	ft_no_stack_no_refill_pb(t_data *data);
void	ft_no_stack_ok_refill_pb(t_data *data);
void	ft_ok_stack(t_data *data, int action);
void	ft_more_a_moove(t_data *data, t_cost *cost, t_best *best);
void	ft_more_b_moove(t_data *data, t_cost *cost, t_best *best);
void	ft_push(t_data *data, int instruction, int print);
void	ft_r_rotate(t_data *data, int instruction, int print);
void	ft_rotate(t_data *data, int instruction, int print);
void	ft_swap(t_data *data, int instruction, int print);
void	ft_too_different(t_data *data, t_best *best, t_cost *cost);
void	ft_sort(t_data *data, t_data *hide);
void	ft_big_sort(t_data *data, t_data *hide);
void	ft_prepare_stack(t_data *data, t_data *hide);
void	ft_correct_moove(t_data *data, t_cost *cost, t_best *best,
			t_data *hide);
void	ft_organize_stack(t_data *data, t_data *hide);
int		ft_who_push(t_data *data, int pivot);
void	ft_send_half(t_data *data, int pivot, int stop);

#endif
