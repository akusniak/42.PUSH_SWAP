/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_terce.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:17:17 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:53:48 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ok_stack_ok_refill_pa(t_data *data)
{
	int	*new_a;
	int	*new_b;

	new_a = NULL;
	new_b = NULL;
	ft_ajust_len(INCREASE, &data->len_a, REDUCE, &data->len_b);
	new_a = malloc(sizeof(int) * data->len_a);
	if (new_a == NULL)
		return ;
	new_b = malloc(sizeof(int) * data->len_b);
	if (new_b == NULL)
		return (free(new_a));
	ft_refill_looser(new_b, data->b, data->len_b + 1);
	ft_refill_winner(new_a, data->a, data->len_a - 1);
	new_a[0] = data->b[0];
	free(data->b);
	free(data->a);
	data->a = ft_intdup(new_a, data->len_a);
	if (data->a == NULL)
		return (free(new_b));
	data->b = ft_intdup(new_b, data->len_b);
	if (data->b == NULL)
		free (new_a);
}

void	ft_ok_stack_no_refill_pa(t_data *data)
{
	int	*new_a;

	new_a = NULL;
	ft_ajust_len(INCREASE, &data->len_a, REDUCE, &data->len_b);
	new_a = malloc(sizeof(int) * data->len_a);
	if (new_a == NULL)
		return ;
	ft_refill_winner(new_a, data->a, data->len_a - 1);
	new_a[0] = data->b[0];
	free(data->b);
	free(data->a);
	data->b = NULL;
	data->a = ft_intdup(new_a, data->len_a);
}

void	ft_ok_stack_ok_refill_pb(t_data *data)
{
	int	*new_a;
	int	*new_b;

	new_a = NULL;
	new_b = NULL;
	ft_ajust_len(REDUCE, &data->len_a, INCREASE, &data->len_b);
	new_a = malloc(sizeof(int) * data->len_a);
	if (new_a == NULL)
		return ;
	new_b = malloc(sizeof(int) * data->len_b);
	if (new_b == NULL)
		return (free(new_a));
	ft_refill_looser(new_a, data->a, data->len_a + 1);
	ft_refill_winner(new_b, data->b, data->len_b - 1);
	new_b[0] = data->a[0];
	free(data->b);
	free(data->a);
	data->a = ft_intdup(new_a, data->len_a);
	if (data->a == NULL)
		return (free(new_b));
	data->b = ft_intdup(new_b, data->len_b);
	if (data->b == NULL)
		free (new_a);
}

void	ft_ok_stack_no_refill_pb(t_data *data)
{
	int	*new_b;

	new_b = NULL;
	ft_ajust_len(REDUCE, &data->len_a, INCREASE, &data->len_b);
	new_b = malloc(sizeof(int) * data->len_b);
	if (new_b == NULL)
		return ;
	ft_refill_winner(new_b, data->b, data->len_b - 1);
	new_b[0] = data->a[0];
	free(data->b);
	free(data->a);
	data->a = NULL;
	data->b = ft_intdup(new_b, data->len_b);
}

void	ft_no_stack(t_data *data, int action)
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
			ft_no_stack_no_refill_pa(data);
	}
	else if (action == PB)
	{
		if (data->len_a == 1)
			refill = NO;
		if (refill == YES)
			ft_ok_stack_ok_refill_pb(data);
		else if (refill == NO)
			ft_no_stack_no_refill_pb(data);
	}
}
