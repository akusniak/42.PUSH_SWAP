/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:04:16 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:54:47 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

static void	ft_do_rotate(int *stack, int len)
{
	int	last;
	int	i;

	i = 0;
	last = stack[0];
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i = i + 1;
	}
	stack[len - 1] = last;
}

static void	ft_do_r_rotate(int *stack, int len)
{
	int	i;
	int	j;
	int	last;

	i = len - 1;
	j = len - 2;
	last = stack[i];
	while (i > 0)
	{
		stack[i] = stack[j];
		i = i - 1;
		j = j - 1;
	}
	stack[0] = last;
}

void	ft_r_rotate_bonus(t_data *data, int instruction, int print)
{
	data->actions += 1;
	if (instruction == RRA)
	{
		ft_do_r_rotate(data->a, data->len_a);
		if (print == PRINT)
			ft_printf("rra\n");
	}
	else if (instruction == RRB)
	{
		ft_do_r_rotate(data->b, data->len_b);
		if (print == PRINT)
			ft_printf("rrb\n");
	}
	else if (instruction == RRR)
	{
		ft_do_r_rotate(data->a, data->len_a);
		ft_do_r_rotate(data->b, data->len_b);
		if (print == PRINT)
			ft_printf("rrr\n");
	}
}

void	ft_rotate_bonus(t_data *data, int instruction, int print)
{
	data->actions += 1;
	if (instruction == RA)
	{
		ft_do_rotate(data->a, data->len_a);
		if (print == PRINT)
			ft_printf("ra\n");
	}
	else if (instruction == RB)
	{
		ft_do_rotate(data->b, data->len_b);
		if (print == PRINT)
			ft_printf("rb\n");
	}
	else if (instruction == RR)
	{
		ft_do_rotate(data->a, data->len_a);
		ft_do_rotate(data->b, data->len_b);
		if (print == PRINT)
			ft_printf("rr\n");
	}
}
