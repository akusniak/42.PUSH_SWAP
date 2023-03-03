/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:48:55 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/02 17:29:46 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_more_a_moove(t_data *data, t_cost *cost, t_best *best)
{
	while (ft_is_first(data->b, best->candidate) == NO)
	{
		if (cost->type.a == ROTATE)
			ft_rotate(data, RR, PRINT);
		else
			ft_r_rotate(data, RRR, PRINT);
	}
	while (ft_is_first(data->a, best->receiver) == NO)
	{
		if (cost->type.a == ROTATE)
			ft_rotate(data, RA, PRINT);
		else
			ft_r_rotate(data, RRA, PRINT);
	}
}

void	ft_more_b_moove(t_data *data, t_cost *cost, t_best *best)
{
	while (ft_is_first(data->a, best->receiver) == NO)
	{
		if (cost->type.a == ROTATE)
			ft_rotate(data, RR, PRINT);
		else
			ft_r_rotate(data, RRR, PRINT);
	}
	while (ft_is_first(data->b, best->candidate) == NO)
	{
		if (cost->type.b == ROTATE)
			ft_rotate(data, RB, PRINT);
		else
			ft_r_rotate(data, RRB, PRINT);
	}
}

void	ft_too_different(t_data *data, t_best *best, t_cost *cost)
{
	while (ft_is_first(data->a, best->receiver) == NO)
	{
		if (cost->type.a == ROTATE)
			ft_rotate(data, RA, PRINT);
		else
			ft_r_rotate(data, RRA, PRINT);
	}
	while (ft_is_first(data->b, best->candidate) == NO)
	{
		if (cost->type.b == ROTATE)
			ft_rotate(data, RB, PRINT);
		else
			ft_r_rotate(data, RRB, PRINT);
	}
}
