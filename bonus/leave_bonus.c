/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:25:23 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:54:26 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_leave_bonus(t_data *data, char *command, int error_message,
			int action)
{
	if (data->a)
		free(data->a);
	if (data->b)
		free(data->b);
	if (data)
		free(data);
	if (command)
		free(command);
	if (error_message == PRINT_ERROR_MESSAGE)
		write(2, "Error\n", 6);
	if (action == EXIT)
		exit(0);
	else
		return ;
}
