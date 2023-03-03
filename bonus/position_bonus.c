/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:10:11 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/02 15:12:20 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_last(int *stack_a, int number, int last)
{
	int	index;

	index = last - 1;
	if (number == stack_a[index])
		return (YES);
	else
		return (NO);
}

int	ft_is_first(int *stack_a, int number)
{
	if (number == stack_a[0])
		return (YES);
	else
		return (NO);
}

int	ft_get_index(int *stack, int len, int nbr)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (stack[i] == nbr)
			break ;
		i = i + 1;
	}
	return (i);
}
