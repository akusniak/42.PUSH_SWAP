/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:05:24 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/04 13:59:00 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_correct_moove(t_data *data, t_cost *cost, t_best *best,
		t_data *hide)
{
	ft_search_execution(data, cost, best, hide);
	ft_get_execution_info(data, cost, best);
	ft_execution(data, cost, best);
}

void	ft_prepare_stack(t_data *data, t_data *hide)
{
	if (data->len_a < 200)
		while (data->len_a > 3)
			ft_push(data, PB, PRINT);
	else
	 	ft_organize_stack(data, hide);
	if (ft_is_sorted(data->a, data->len_a) == NO)
		ft_sort_three(data);
}

void	ft_big_sort(t_data *data, t_data *hide)
{
	t_cost	*cost;
	t_best	*best;

	cost = NULL;
	best = NULL;
	cost = malloc(sizeof(t_cost));
	if (cost == NULL)
		return ;
	best = malloc (sizeof(t_best));
	if (best == NULL)
	{
		free(cost);
		return ;
	}
	ft_brute_sort(hide);
	ft_prepare_stack(data, hide);
	while (data->len_b != 0)
		ft_correct_moove(data, cost, best, hide);
	ft_put_little_at_start(data, hide);
	free(cost);
	free(best);
}

void	ft_sort(t_data *data, t_data *hide)
{
	if (ft_is_sorted(data->a, data->len_a) == YES)
		return ;
	else if (data->len_a == 2)
		ft_swap(data, SA, PRINT);
	else if (data->len_a == 3)
		ft_sort_three(data);
	else
		ft_big_sort(data, hide);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_data	*hide;

	if (argc < 2)
		return (1);
	ft_parsing(argc, argv);
	data = ft_init_data(argc);
	if (data == NULL)
		ft_leave(data, NO_ERROR_MESSAGE, EXIT);
	hide = ft_init_data(argc);
	if (hide == NULL)
	{
		ft_leave(data, NO_ERROR_MESSAGE, NO_EXIT);
		ft_leave(hide, NO_ERROR_MESSAGE, EXIT);
	}
	ft_set_data(data, argv);
	if (ft_set_data(data, argv) == KO)
	{
		ft_leave(data, NO_ERROR_MESSAGE, NO_EXIT);
		ft_leave(hide, PRINT_ERROR_MESSAGE, EXIT);
	}
	ft_set_data(hide, argv);
	ft_sort(data, hide);
	ft_leave(data, NO_ERROR_MESSAGE, NO_EXIT);
	ft_leave(hide, NO_ERROR_MESSAGE, EXIT);
}
