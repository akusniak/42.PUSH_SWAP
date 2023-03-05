/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:31:06 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:53:40 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_action(int *stack, int len, int number, int return_wanted)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (stack[i] == number)
			break ;
		else
			i = i + 1;
	}
	if (i <= len / 2)
	{
		if (return_wanted == TYPE)
			return (ROTATE);
		else
			return (i);
	}
	else
	{
		if (return_wanted == TYPE)
			return (REVERSE_ROTATE);
		else
			return (len - i);
	}
}

void	ft_duo_action(t_data *data, t_best *best, int action)
{
	while (ft_is_first(data->b, best->candidate) == NO)
	{
		if (action == ROTATE)
			ft_rotate(data, RR, PRINT);
		else
			ft_r_rotate(data, RRR, PRINT);
	}
}

void	ft_execution(t_data *data, t_cost *cost, t_best *best)
{
	if (cost->quantity.a == cost->quantity.b && cost->type.a == cost->type.b)
		ft_duo_action(data, best, cost->type.a);
	else
	{
		if (cost->type.a == cost->type.b)
			ft_same_cost(data, cost, best);
		else
			ft_too_different(data, best, cost);
	}
	ft_push(data, PA, PRINT);
}

void	ft_same_cost(t_data *data, t_cost *cost, t_best *best)
{
	if (cost->quantity.a > cost->quantity.b)
		ft_more_a_moove(data, cost, best);
	else
		ft_more_b_moove(data, cost, best);
}

void	ft_put_little_at_start(t_data *data, t_data *hide)
{
	int	little;

	little = hide->a[0];
	while (ft_is_first(data->a, little) == NO)
	{
		if (ft_action(data->a, data->len_a, little, TYPE) == ROTATE)
			ft_rotate(data, RA, PRINT);
		else
			ft_r_rotate(data, RRA, PRINT);
	}
}
