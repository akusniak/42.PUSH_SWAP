/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:25:23 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/02 15:37:30 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_leave(t_data *data, int error_message, int action)
{
	if (data->a)
	{
		free(data->a);
		data->a = NULL;
	}
	if (data->b)
	{
		free(data->b);
		data->b = NULL;
	}
	if (data)
	{
		free(data);
		data = NULL;
	}
	if (error_message == PRINT_ERROR_MESSAGE)
		write(2, "Error\n", 6);
	if (action == EXIT)
		exit(0);
	else
		return ;
}
