/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:02:26 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:53:58 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_push_a(t_data *data)
{
	if (data->len_a == 0)
		ft_no_stack(data, PA);
	else
		ft_ok_stack(data, PA);
}

static void	ft_push_b(t_data *data)
{
	if (data->len_b == 0)
		ft_no_stack(data, PB);
	else
		ft_ok_stack(data, PB);
}

void	ft_push(t_data *data, int instruction, int print)
{
	data->actions += 1;
	if (instruction == PA)
	{
		ft_push_a(data);
		if (print == PRINT)
			ft_printf("pa\n");
	}
	else if (instruction == PB)
	{
		ft_push_b(data);
		if (print == PRINT)
			ft_printf("pb\n");
	}
}
