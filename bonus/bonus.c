/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:23:39 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:56:28 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac > 1)
	{
		ft_parsing_bonus(ac, av);
		data = ft_init_data_bonus(ac);
		if (data == NULL)
			exit(0);
		ft_set_data_bonus(data, av);
		ft_read_instruction(data);
		return (1);
	}
	else
		return (0);
}

void	ft_read_instruction(t_data *data)
{
	char	*command;

	command = NULL;
	while (1)
	{
		command = ft_gnl(0);
		if (ft_strncmp(command, "\n", 1) == 0)
		{
			if (ft_is_sorted(data->a, data->len_a) == YES)
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
			ft_leave_bonus(data, command, NO_ERROR_MESSAGE, EXIT);
		}
		else if (ft_command_check(command) == GOOD_COMMAND)
		{
			ft_execute(command, data);
			free(command);
		}
		else
			ft_leave_bonus(data, command, PRINT_ERROR_MESSAGE, EXIT);
	}
}

int	ft_command_check(char *command)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		return (GOOD_COMMAND);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		return (GOOD_COMMAND);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		return (GOOD_COMMAND);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		return (GOOD_COMMAND);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		return (GOOD_COMMAND);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		return (GOOD_COMMAND);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		return (GOOD_COMMAND);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		return (GOOD_COMMAND);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		return (GOOD_COMMAND);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		return (GOOD_COMMAND);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		return (GOOD_COMMAND);
	return (WRONG_COMMAND);
}

void	ft_execute(char *command, t_data *data)
{
	if (ft_strncmp(command, "s", 1) == 0)
		ft_exec_swap(command, data);
	else if (ft_strncmp(command, "p", 1) == 0)
		ft_exec_push(command, data);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
	{
		if (data->a == NULL)
			return ;
		ft_r_rotate_bonus(data, RRA, NO_PRINT);
	}
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
	{
		if (data->b == NULL)
			return ;
		ft_r_rotate_bonus(data, RRB, NO_PRINT);
	}
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		ft_exec_rrr(command, data);
	else
		ft_exec_rotate(command, data);
}
