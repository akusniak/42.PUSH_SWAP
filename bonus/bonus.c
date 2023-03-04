/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:23:39 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/04 11:29:35 by akusniak         ###   ########.fr       */
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
			ft_leave_bonus(data, NO_ERROR_MESSAGE, EXIT);
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
			ft_leave_bonus(data, NO_ERROR_MESSAGE, EXIT);
		}
		else if (ft_command_check(command) == GOOD_COMMAND)
		{
			ft_execute(command, data);
			free(command);
		}
		else
		{
			free(command);
			ft_leave_bonus(data, PRINT_ERROR_MESSAGE, EXIT);
		}
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
	// check si A est vide et que B est vide, bloquer l'instruction(enfin l'afficher mais ne pas la faire)
	if (ft_strncmp(command, "sa\n", 3) == 0)
		ft_swap_bonus(data, SA, NO_PRINT);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		ft_swap_bonus(data, SB, NO_PRINT);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		ft_swap_bonus(data, SS, NO_PRINT);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		ft_push_bonus(data, PA, NO_PRINT);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		ft_push_bonus(data, PB, NO_PRINT);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		ft_rotate_bonus(data, RA, NO_PRINT);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		ft_rotate_bonus(data, RB, NO_PRINT);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		ft_rotate_bonus(data, RR, NO_PRINT);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		ft_r_rotate_bonus(data, RRA, NO_PRINT);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		ft_r_rotate_bonus(data, RRB, NO_PRINT);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		ft_r_rotate_bonus(data, RRR, NO_PRINT);
	else
		return ;
}
