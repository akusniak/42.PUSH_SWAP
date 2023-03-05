/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:11:02 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:53:12 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_is_sorted(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			i = i + 1;
		else
			return (NO);
	}
	return (YES);
}

int	ft_is_inversed(int *stack, int len)
{
	int	i;

	i = len - 1;
	while (i > 0)
	{
		if (stack[i] < stack[i - 1])
			i = i - 1;
		else
			return (NO);
	}
	return (YES);
}

int	ft_find_biggest(int *stack_a, int len)
{
	int	i;
	int	big;

	i = 1;
	big = stack_a[0];
	while (i < len)
	{
		if (stack_a[i] > big)
			big = stack_a[i];
		i = i + 1;
	}
	return (big);
}

int	ft_find_small(int *stack_a, int len)
{
	int	i;
	int	small;

	i = 1;
	small = stack_a[0];
	while (i < len)
	{
		if (stack_a[i] < small)
			small = stack_a[i];
		i = i + 1;
	}
	return (small);
}
