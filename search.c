/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:10:35 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:53:14 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_search_execution(t_data *data, t_cost *cost, t_best *best,
		t_data *hide)
{
	int	i;
	int	current_candidate;
	int	current_receiver;
	int	current_lowest_cost;
	int	best_cost;

	best_cost = hide->len_a * 2;
	i = 0;
	while (i < data->len_b)
	{
		current_candidate = data->b[i];
		current_receiver = ft_find_receiver(current_candidate, data, hide);
		ft_get_cost_info(current_candidate, current_receiver, cost, data);
		current_lowest_cost = ft_get_current_cost(cost);
		if (current_lowest_cost < best_cost)
		{
			best->candidate = current_candidate;
			best->receiver = current_receiver;
			best_cost = current_lowest_cost;
		}
		i = i + 1;
	}
}

int	ft_find_receiver(int candidat, t_data *data, t_data *hide)
{
	int	candidat_index;
	int	stack_a_maximum;
	int	stack_a_minimum;

	candidat_index = ft_get_index(hide->a, hide->len_a, candidat);
	stack_a_maximum = ft_find_biggest(data->a, data->len_a);
	stack_a_minimum = ft_find_small(data->a, data->len_a);
	if (candidat > stack_a_maximum)
		return (stack_a_minimum);
	else
		return (ft_find_neighbor_top(candidat_index, data, hide, VALUE));//rajouter une comparation avec neighbor bot ???
}

int	ft_find_neighbor_top(int candidat_index, t_data *data,
		t_data *hide, int wanted_value)
{
	int	i;
	int	j;

	i = candidat_index + 1;
	while (i < hide->len_a)
	{
		j = 0;
		while (j < data->len_a)
		{
			if (data->a[j] == hide->a[i])
			{
				if (wanted_value == VALUE)
					return (data->a[j]);
				else
					return (i);
			}
			else
				j = j + 1;
		}
		i = i + 1;
	}
	return (data->error_code);
}

void	ft_get_execution_info(t_data *data, t_cost *cost, t_best *best)
{
	cost->quantity.a = ft_action(data->a, data->len_a,
			best->receiver, QUANTITY);
	cost->quantity.b = ft_action(data->b, data->len_b,
			best->candidate, QUANTITY);
	cost->type.a = ft_action(data->a, data->len_a,
			best->receiver, TYPE);
	cost->type.b = ft_action(data->b, data->len_b,
			best->candidate, TYPE);
}
