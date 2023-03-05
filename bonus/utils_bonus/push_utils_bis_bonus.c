/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_bis_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:16:15 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:54:41 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_no_stack_no_refill_pa(t_data *data)
{
	int	*new_a;

	new_a = NULL;
	ft_ajust_len(INCREASE, &data->len_a, REDUCE, &data->len_b);
	new_a = malloc(sizeof(int) * 1);
	new_a[0] = data->b[0];
	free(data->a);
	free(data->b);
	data->b = NULL;
	data->a = ft_intdup(new_a, data->len_a);
}

void	ft_no_stack_ok_refill_pa(t_data *data)
{
	int	*new_a;
	int	*new_b;

	new_a = NULL;
	new_b = NULL;
	ft_ajust_len(INCREASE, &data->len_a, REDUCE, &data->len_b);
	new_a = malloc(sizeof(int) * 1);
	new_b = malloc(sizeof(int) * data->len_b);
	new_a[0] = data->b[0];
	ft_refill_looser(new_b, data->b, data->len_b + 1);
	free(data->a);
	free(data->b);
	data->a = ft_intdup(new_a, data->len_a);
	data->b = ft_intdup(new_b, data->len_b);
}

void	ft_no_stack_no_refill_pb(t_data *data)
{
	int	*new_b;

	new_b = NULL;
	ft_ajust_len(REDUCE, &data->len_a, INCREASE, &data->len_b);
	new_b = malloc(sizeof(int) * 1);
	new_b[0] = data->a[0];
	free(data->a);
	free(data->b);
	data->a = NULL;
	data->b = ft_intdup(new_b, data->len_a);
}

void	ft_no_stack_ok_refill_pb(t_data *data)
{
	int	*new_a;
	int	*new_b;

	new_a = NULL;
	new_b = NULL;
	ft_ajust_len(REDUCE, &data->len_a, INCREASE, &data->len_b);
	new_b = malloc(sizeof(int) * 1);
	new_a = malloc(sizeof(int) * data->len_a);
	new_b[0] = data->a[0];
	ft_refill_looser(new_a, data->a, data->len_a + 1);
	free(data->a);
	free(data->b);
	data->a = ft_intdup(new_a, data->len_a);
	data->b = ft_intdup(new_b, data->len_b);
}

void	ft_ok_stack(t_data *data, int action)
{
	int	refill;

	refill = YES;
	if (action == PA)
	{
		if (data->len_b == 1)
			refill = NO;
		if (refill == YES)
			ft_ok_stack_ok_refill_pa(data);
		else if (refill == NO)
			ft_ok_stack_no_refill_pa(data);
	}
	else if (action == PB)
	{
		if (data->len_a == 1)
			refill = NO;
		if (refill == YES)
			ft_ok_stack_ok_refill_pb(data);
		else if (refill == NO)
			ft_ok_stack_no_refill_pb(data);
	}
}
