/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:07:58 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/02 16:21:48 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_sort_three(t_data *data)
{
	int	big;
	int	to_swap;

	big = ft_find_biggest(data->a, data->len_a);
	to_swap = 0;
	if (ft_is_last(data->a, big, data->len_a) == YES)
		ft_swap(data, SA, PRINT);
	else if (ft_is_first(data->a, big) == YES)
	{
		if (data->a[1] < data->a[2])
			ft_rotate(data, RA, PRINT);
		else
		{
			ft_rotate(data, RA, PRINT);
			ft_swap(data, SA, PRINT);
		}
	}
	else
	{
		if (data->a[0] < data->a[2])
			to_swap = 1;
		ft_r_rotate(data, RRA, PRINT);
		if (to_swap == 1)
			ft_swap(data, SA, PRINT);
	}
}

void	ft_brute_sort(t_data *hide)
{
	int	to_push;

	while (hide->len_a != 1)
	{
		to_push = ft_find_small(hide->a, hide->len_a);
		while (ft_is_first(hide->a, to_push) == NO)
		{
			if (ft_action(hide->a, hide->len_a, to_push, TYPE) == ROTATE)
				ft_rotate(hide, RA, NO_PRINT);
			else
				ft_r_rotate(hide, RRA, NO_PRINT);
		}
		ft_push(hide, PB, NO_PRINT);
	}
	while (hide->len_b != 0)
		ft_push(hide, PA, NO_PRINT);
	free(hide->b);
	hide->b = NULL;
}
