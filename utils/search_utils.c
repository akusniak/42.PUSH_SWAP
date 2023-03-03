/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:54:15 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/02 16:29:31 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_cost_info(int current_candidate,
			int current_receiver, t_cost *cost, t_data *data)
{
	cost->quantity.a = ft_action(data->a, data->len_a,
			current_receiver, QUANTITY);
	cost->quantity.b = ft_action(data->b, data->len_b,
			current_candidate, QUANTITY);
	cost->type.a = ft_action(data->a, data->len_a,
			current_receiver, TYPE);
	cost->type.b = ft_action(data->b, data->len_b,
			current_candidate, TYPE);
}

int	ft_get_current_cost(t_cost *cost)
{
	int	current_lowest_cost;

	if (cost->type.a == cost->type.b)
	{
		if (cost->quantity.a == cost->quantity.b)
			current_lowest_cost = cost->quantity.a;
		else if (cost->quantity.a > cost->quantity.b)
			current_lowest_cost = cost->quantity.a;
		else
			current_lowest_cost = cost->quantity.b;
	}
	else
		current_lowest_cost = cost->quantity.a + cost->quantity.b;
	return (current_lowest_cost);
}
