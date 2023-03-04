/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:58:08 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/04 15:02:19 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_organize_stack(t_data *data, t_data *hide)
{
	int	pivot;
	int	stop;

	pivot = hide->a[hide->len_a / 2];
	stop = (hide->len_a / 2);
	ft_send_half(data, pivot, stop);
	pivot = hide->a[(int)(hide->len_a * 0.75)];
	stop = (int)(hide->len_a * 0.75);
	ft_send_half(data, pivot, stop);
	while (data->len_a > 3)
		ft_push(data, PB, PRINT);
}

int	ft_who_push(t_data *data, int pivot)
{
	int	i;
	int	j;
	int	candidat1;
	int	candidat2;

	i = 0;
	j = data->len_a - 1;
	while (i < data->len_a)
	{
		if (data->a[i] <= pivot)
			candidat1 = data->a[i];
		i++;
	}
	while (j != 0)
	{
		if (data->a[j] <= pivot)
			candidat2 = data->a[j];
		j--;
	}
	if (candidat1 == candidat2)
		return (candidat1);
	if (i > (data->len_a - j))
		return (candidat2);
	else
		return (candidat1);
}

void	ft_send_half(t_data *data, int pivot, int stop)
{
	int	to_push;

	to_push = 0;
	while (data->len_b < stop)
	{
		to_push = ft_who_push(data, pivot);
		while (ft_is_first(data->a, to_push) == NO)
		{
			if (ft_action(data->a, data->len_a, to_push, TYPE) == ROTATE)
				ft_rotate(data, RA, PRINT);
			else
				ft_r_rotate(data, RRA, PRINT);
		}
		ft_push(data, PB, PRINT);
	}
}
