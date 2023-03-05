/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:32:19 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 15:19:44 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_exec_swap(char *command, t_data *data)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
	{
		if (data->a == NULL || data->len_a == 1)
			return ;
		ft_swap_bonus(data, SA, NO_PRINT);
	}
	else if (ft_strncmp(command, "sb\n", 3) == 0)
	{
		if (data->b == NULL || data->len_b == 1)
			return ;
		ft_swap_bonus(data, SB, NO_PRINT);
	}
	else
	{
		if ((data->a == NULL || data->len_a == 1) && (data->b == NULL
				|| data->len_b == 1))
			return ;
		else if ((data->a == NULL || data->len_a == 1))
			ft_swap_bonus(data, SB, NO_PRINT);
		else if ((data->b == NULL || data->len_b == 1))
			ft_swap_bonus(data, SA, NO_PRINT);
		else
			ft_swap_bonus(data, SS, NO_PRINT);
	}
}

void	ft_exec_push(char *command, t_data *data)
{
	if (ft_strncmp(command, "pa\n", 3) == 0)
	{
		if (data->b == NULL)
			return ;
		else
			ft_push_bonus(data, PA, NO_PRINT);
	}
	else if (ft_strncmp(command, "pb\n", 3) == 0)
	{
		if (data->a == NULL)
			return ;
		ft_push_bonus(data, PB, NO_PRINT);
	}
	else
		return ;
}

void	ft_exec_rotate(char *command, t_data *data)
{
	if (ft_strncmp(command, "ra\n", 3) == 0)
	{
		if (data->a == NULL)
			return ;
		ft_rotate_bonus(data, RA, NO_PRINT);
	}
	else if (ft_strncmp(command, "rb\n", 3) == 0)
	{
		if (data->b == NULL)
			return ;
		ft_rotate_bonus(data, RB, NO_PRINT);
	}
	else if (ft_strncmp(command, "rr\n", 3) == 0)
	{
		if (data->a == NULL && data->b == NULL)
			return ;
		else if (data->a == NULL)
			ft_rotate_bonus(data, RB, NO_PRINT);
		else if (data->b == NULL)
			ft_rotate_bonus(data, RA, NO_PRINT);
		else
			ft_rotate_bonus(data, RR, NO_PRINT);
	}
	else
		return ;
}

void	ft_exec_rrr(t_data *data)
{
	if (data->a == NULL && data->b == NULL)
		return ;
	else if (data->a == NULL)
		ft_r_rotate_bonus(data, RRB, NO_PRINT);
	else if (data->b == NULL)
		ft_r_rotate_bonus(data, RRA, NO_PRINT);
	else
		ft_r_rotate_bonus(data, RRR, NO_PRINT);
}
