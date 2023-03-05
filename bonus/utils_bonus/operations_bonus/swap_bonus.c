/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:07:24 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:54:49 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

static void	ft_do_swap(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void	ft_swap_bonus(t_data *data, int instruction, int print)
{
	data->actions += 1;
	if (instruction == SA)
	{
		ft_do_swap(&data->a[1], &data->a[0]);
		if (print == PRINT)
			ft_printf("sa\n");
	}
	else if (instruction == SB)
	{
		ft_do_swap(&data->b[1], &data->b[0]);
		if (print == PRINT)
			ft_printf("sb\n");
	}
	else if (instruction == SS)
	{
		ft_do_swap(&data->a[1], &data->a[0]);
		ft_do_swap(&data->b[1], &data->b[0]);
		if (print == PRINT)
			ft_printf("ss\n");
	}
}
