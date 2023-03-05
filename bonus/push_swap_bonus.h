/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:09:54 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 15:19:53 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stddef.h>
# include "../includes/libft.h"

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

# define GOOD_COMMAND 1
# define WRONG_COMMAND -1

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
	int	candidate;
	int	receiver;
}				t_best;

typedef struct s_data
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
	int	actions;
	int	error_code;
}				t_data;

void	ft_push_bonus(t_data *data, int instruction, int print);
void	ft_r_rotate_bonus(t_data *data, int instruction, int print);
void	ft_rotate_bonus(t_data *data, int instruction, int print);
void	ft_swap_bonus(t_data *data, int instruction, int print);
void	ft_no_stack_no_refill_pa(t_data *data);
void	ft_no_stack_ok_refill_pa(t_data *data);
void	ft_no_stack_no_refill_pb(t_data *data);
void	ft_no_stack_ok_refill_pb(t_data *data);
void	ft_ok_stack(t_data *data, int action);
void	ft_ajust_len(int action_a, int *len_a, int action_b, int *len_b);
void	ft_refill_winner(int *new, int *old, int len);
void	ft_refill_looser(int *new, int *old, int len);
int		*ft_intdup(int *new, int len);
void	ft_ok_stack_ok_refill_pa(t_data *data);
void	ft_ok_stack_no_refill_pa(t_data *data);
void	ft_ok_stack_ok_refill_pb(t_data *data);
void	ft_ok_stack_no_refill_pb(t_data *data);
void	ft_no_stack(t_data *data, int action);
void	ft_read_instruction(t_data *data);
int		ft_command_check(char *command);
void	ft_execute(char *command, t_data *data);
t_data	*ft_init_data_bonus(int argc);
int		ft_set_data_bonus(t_data *data, char **argv);
void	ft_print_error_and_exit(void);
void	ft_leave_bonus(t_data *data, char *command, int error_message,
			int action);
int		ft_is_sorted(int *stack, int len);
int		ft_is_inversed(int *stack, int len);
int		ft_find_biggest(int *stack_a, int len);
int		ft_find_small(int *stack_a, int len);
void	ft_parsing_bonus(int argc, char **argv);
void	ft_exec_rrr(t_data *data);
void	ft_exec_swap(char *command, t_data *data);
void	ft_exec_push(char *command, t_data *data);
void	ft_exec_rotate(char *command, t_data *data);

#endif
